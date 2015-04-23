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

static Vector *clientList;
static Hash *clientHash;
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
        network_ipstring_from_address(&dnsRequest->Client->Address,
                                      dnsRequest->Host, HOSTLEN);
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
client_allocate_buffer_callback(uv_handle_t *handle,
                                size_t suggestedSize,
                                uv_buf_t *buf)
{
    buf->base = Malloc(suggestedSize);
    buf->len = suggestedSize;
}

static void
client_on_read_callback(uv_stream_t *stream, ssize_t nRead, const uv_buf_t *buf)
{
    Client *client = stream->data;

    assert(client != NULL);

    if(nRead == UV_EOF)
    {
        // TODO: exit client due to connection closed, probably get consolidated
        // with below
    }
    else if(nRead < 0)
    {
        // TODO: exit client due to read error
    }

    buffer_add(client->ReadBuffer, buf->base, (size_t)nRead);

    client_process_read_buffer(client);

    Free(buf->base);
}

static bool
client_accept_socket(Client *client, uv_stream_t *handle)
{
    assert(client != NULL);

    client->handle = Malloc(sizeof(uv_tcp_t));
    uv_tcp_init(serverstate_get_event_loop(), client->handle);
    if(uv_accept(handle, (uv_stream_t *)client->handle) != 0)
    {
        return false;
    }

    client->handle->data = client;

    return true;
}

static void
client_dns_complete_callback(ClientDnsRequest *request, bool match)
{
    Client *client = request->Client;

    client_send(server_get_this_server(), client, "NOTICE * :%s",
                DnsNotices[match ? Found : NotFound]);

    if(uv_read_start((uv_stream_t *)client->handle, client_allocate_buffer_callback,
                     client_on_read_callback) < 0)
    {
        // TODO: Exit client
    }
}

static void
client_write_callback(uv_write_t *req, int status)
{
    Free(req);
}

static void
client_internal_send(Client *client, char *buffer)
{
    uv_write_t *req;
    uv_buf_t buf;
    size_t len;

    len = strlen(buffer);
    if(len > IRC_MAXLEN - 2)
    {
        len = IRC_MAXLEN - 2;
    }

    buffer[len++] = '\r';
    buffer[len++] = '\n';
    buffer[len] = '\0';

    buf.base = buffer;
    buf.len = len;

    req = Malloc(sizeof(uv_write_t));

    uv_write(req, (uv_stream_t *)client->handle, &buf, 1, client_write_callback);
}

static void
client_lookup_dns(Client *client)
{
    ClientDnsRequest *dnsRequest;
    uv_getnameinfo_t *req;

    if(client == NULL)
    {
        return;
    }

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

void
client_init()
{
    clientList = vector_new(0, sizeof(Client));
    clientHash = hash_new("Client Hash", 0);
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
        uv_close((uv_handle_t *)client->handle, NULL);
        Free(client->handle);
        client->handle = NULL;
    }

    Free(client);
}

bool
client_accept(Client *client, uv_stream_t *handle)
{
    if(client == NULL || handle == NULL)
    {
        return false;
    }

    if(!client_accept_socket(client, handle))
    {
        return false;
    }

    client->Address.AddressLength = sizeof(client->Address);
    if(uv_tcp_getsockname((uv_tcp_t *)client->handle,
                             (struct sockaddr *)&client->Address,
                             (int *)&client->Address.AddressLength) != 0)
    {
        return false;
    }

    client->Address.AddressFamily = client->Address.Address.Addr4.sin_family;

    client_send(server_get_this_server(), client, "NOTICE * :%s",
                DnsNotices[LookingUp]);
    
    client_lookup_dns(client);

    return true;
}

__attribute__((__format__ (__printf__, 3, 0)))
void
client_send(Client *source, Client *client, const char *format, ...)
{
    va_list args;
    char buffer[IRC_MAXLEN + 1];
    char actualBuffer[IRC_MAXLEN + 1];

    va_start(args, format);

    vsnprintf(buffer, sizeof(buffer), format, args);
    if(source != NULL)
    {
        snprintf(actualBuffer, sizeof(actualBuffer), ":%s %s", source->Name,
                 buffer);
    }
    else
    {
        snprintf(actualBuffer, sizeof(actualBuffer), "%s", buffer);
    }

    client_internal_send(client, actualBuffer);

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

bool
client_set_nickname(Client *client, const char *nickname)
{
    strncpy(client->Name, nickname, NICKLEN);

    return true;
}

bool 
client_set_username(Client *client, const char *username)
{
    strncpy(client->Username, username, USERLEN);

    return true;
}

bool
client_set_realname(Client *client, const char *realname)
{
    strncpy(client->Realname, realname, REALLEN);

    return true;
}
