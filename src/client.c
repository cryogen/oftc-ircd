/*
 * Copyright (c) 2014, Stuart Walsh
 * All rights reserved.
 * client.c client related functions
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.

 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <assert.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

#include "client.h"
#include "vector.h"
#include "hash.h"
#include "memory.h"
#include "listener.h"
#include "serverstate.h"
#include "irc.h"
#include "server.h"
#include "parser.h"
#include "connection.h"
#include "lstring.h"
#include "numeric.h"

static Vector *clientList;
static Hash *ClientHash;

static char *DnsNotices[] =
{
    "Looking up your hostname",
    "Found your hostname",
    "Could not resolve or match your hostname"
};

static void
call_dns_callback(ClientDnsRequest *req, bool success)
{
    if(req == NULL || req->Callback == NULL)
    {
        return;
    }

    req->Callback(req, success);
}

static void
client_on_addr_callback(uv_getaddrinfo_t *req, int status, struct addrinfo *res)
{
    ClientDnsRequest *dnsRequest = req->data;

    if(status != 0)
    {
        call_dns_callback(dnsRequest, false);
        Free(req);

        return;
    }

    do
    {
        if(memcmp(res->ai_addr, &dnsRequest->Client->Address.Address,
                  dnsRequest->Client->Address.AddressLength) == 0)
        {
            break;
        }

        res = res->ai_next;
    } while (res != NULL);

    if(res == NULL)
    {
        call_dns_callback(dnsRequest, false);
    }
    else
    {
        call_dns_callback(dnsRequest, true);
    }

    Free(req);
}

static void
client_on_name_callback(uv_getnameinfo_t* req, int status, const char *hostname,
                        const char *service)
{
    ClientDnsRequest *dnsRequest = req->data;

    if(status == 0)
    {
        uv_getaddrinfo_t *addrReq = Malloc(sizeof(uv_getaddrinfo_t));

        strncpy(dnsRequest->Host, hostname, sizeof(dnsRequest->Host) - 1);
        addrReq->data = dnsRequest;

        uv_getaddrinfo(serverstate_get_event_loop(), addrReq,
                       client_on_addr_callback, dnsRequest->Host, service, NULL);
    }
    else
    {
        call_dns_callback(dnsRequest, false);
    }
    
    Free(req);
}

static void
client_dns_complete_callback(ClientDnsRequest *request, bool match)
{
    Client *client = request->Client;

    if(match)
    {
    }
    else
    {
        network_ipstring_from_address(&request->Client->Address, request->Host,
                                      HOSTLEN);
    }

    client_send(server_get_this_server(), client, "NOTICE", ":%s",
                DnsNotices[match ? Found : NotFound]);

    connection_start_read(client);

    Free(request);
}

static void
client_close_callback(uv_handle_t *handle)
{
    Free(handle);
}

void
client_init()
{
    clientList = vector_new(0, sizeof(Client));
    ClientHash = hash_new("Client Hash", 0);
}

Client *
client_new()
{
    Client *client;

    client = Malloc(sizeof(Client));

    client->ReadBuffer = buffer_new();

    return client;
}

void
client_free(Client *client)
{
    if(client == NULL)
    {
        return;
    }

    if(client->handle != NULL)
    {
        uv_close((uv_handle_t *)client->handle, client_close_callback);
        client->handle = NULL;
    }

    hash_delete_string(ClientHash, client->Name);

    Free(client);
}

void
client_lookup_dns(Client *client)
{
    ClientDnsRequest *dnsRequest;
    uv_getnameinfo_t *req;

    if(client == NULL)
    {
        return;
    }

    client_send(server_get_this_server(), client, "NOTICE", ":%s",
                DnsNotices[LookingUp]);

    dnsRequest = Malloc(sizeof(ClientDnsRequest));
    dnsRequest->Client = client;
    dnsRequest->Callback = client_dns_complete_callback;

    req = Malloc(sizeof(uv_getnameinfo_t));
    req->data = dnsRequest;

    if(uv_getnameinfo(serverstate_get_event_loop(), req, client_on_name_callback,
                      (struct sockaddr *)&client->Address, 0) != 0)
    {
        Free(req);
        call_dns_callback(dnsRequest, false);
    }
}

__attribute__((__format__ (__printf__, 3, 0)))
void
client_send(Client *source,
            Client *target,
            const char *command,
            const char *format,
            ...)
{
    va_list args;
    char buffer[IRC_MAXLEN + 1];
    char actualBuffer[IRC_MAXLEN + 1];

    va_start(args, format);

    vsnprintf(buffer, sizeof(buffer), format, args);
    if(source != NULL)
    {
        snprintf(actualBuffer, sizeof(actualBuffer), ":%s %s %s %s",
                 client_get_nickname(source), command,
                 client_get_nickname(target), buffer);
    }
    else
    {
        snprintf(actualBuffer, sizeof(actualBuffer), "%s %s %s",
                 command, client_get_nickname(target), buffer);
    }

    connection_send(target, actualBuffer);

    va_end(args);
}

void
client_process_read_buffer(Client *client)
{
    char buffer[IRC_MAXLEN + 1];

    while(parser_get_line(client->ReadBuffer, buffer, sizeof(buffer)))
    {
        ParserResult *result = parser_process_line(buffer, strlen(buffer));
        Command *command;

        if(result == NULL)
        {
            continue;
        }

        command = command_find(result->CommandText);
        if(command == NULL)
        {
            parser_result_free(result);
            continue;
        }

        if(client->AccessLevel < command->RequiredAccess)
        {
            parser_result_free(result);
            continue;
        }

        if(vector_length(result->Params) < command->MinParams)
        {
            client_send(server_get_this_server(), client, ERR_NEEDMOREPARAMS, command->Name);
            parser_result_free(result);
            continue;
        }

        if(command->Handler != NULL)
        {
            command->Handler(client, result->Params);
        }

        parser_result_free(result);
    }
}

Client *
client_find(const char *name)
{
    return hash_find(ClientHash, name);
}

void
client_register(Client *client)
{
    client_send(server_get_this_server(), client, RPL_WELCOME, client->Name);
    client_send(server_get_this_server(), client, RPL_YOURHOST,
                server_get_this_server()->Name, "0.0.0");
    client_send(server_get_this_server(), client, RPL_CREATED, "sometime");
    client_send(server_get_this_server(), client, RPL_MYINFO,
                server_get_this_server()->Name, "0.0.0", "", "");

    client->AccessLevel = Standard;
}

bool
client_can_register(Client *client)
{
    if(string_is_null_or_empty(client->Name) ||
       string_is_null_or_empty(client->Username))
    {
        return false;
    }

    if(client->AccessLevel != Unregistered)
    {
        return false;
    }

    return true;
}

bool
client_set_nickname(Client *client, const char *nickname)
{
    if(client == NULL || nickname == NULL)
    {
        return false;
    }

    hash_delete_string(ClientHash, client->Name);

    strncpy(client->Name, nickname, NICKLEN);

    hash_add_string(ClientHash, nickname, client);

    return true;
}

bool 
client_set_username(Client *client, const char *username)
{
    if(client == NULL || username == NULL)
    {
        return false;
    }

    strncpy(client->Username, username, USERLEN);

    return true;
}

bool
client_set_realname(Client *client, const char *realname)
{
    if(client == NULL || realname == NULL)
    {
        return false;
    }
    
    strncpy(client->Realname, realname, REALLEN);

    return true;
}

const char *
client_get_nickname(Client *client)
{
    if(client == NULL)
    {
        return NULL;
    }

    if(string_is_null_or_empty(client->Name))
    {
        return "*";
    }

    return client->Name;
}
