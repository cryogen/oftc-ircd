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

#include "client.h"
#include "vector.h"
#include "hash.h"
#include "memory.h"
#include "listener.h"

static Vector *clientList;
static Hash *clientHash;

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

    if(status == 0)
    {
        do
        {
            if(memcmp(res->ai_addr, &dnsRequest->Address.Address,
                      dnsRequest->Address.AddressLength) == 0)
            {
                break;
            }

            res = res->ai_next;
        } while (res != NULL);

        if(res == NULL)
        {
            network_ipstring_from_address(&dnsRequest->Address,
                                          dnsRequest->Host, HOSTLEN);
            call_dns_callback(dnsRequest, false);
        }
        else
        {
            call_dns_callback(dnsRequest, true);
        }
    }

    Free(req);
}

static void
client_on_name_callback(uv_getnameinfo_t* req, int status, const char *hostname,
                        const char *service)
{
    if(status == 0)
    {
        ClientDnsRequest *dnsRequest = req->data;
        uv_getaddrinfo_t *addrReq = Malloc(sizeof(uv_getaddrinfo_t));

        strncpy(dnsRequest->Host, hostname, sizeof(dnsRequest->Host) - 1);
        addrReq->data = dnsRequest;

        uv_getaddrinfo(uv_default_loop(), addrReq, client_on_addr_callback,
                       dnsRequest->Host, service, NULL);
    }
    
    Free(req);
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
    return Malloc(sizeof(Client));
}

void
client_free(Client *client)
{
    if(client == NULL)
    {
        return;
    }

    if(client->Handle != NULL)
    {
        uv_close((uv_handle_t *)client->Handle, NULL);
        Free(client->Handle);
        client->Handle = NULL;
    }

    Free(client);
}

bool
client_accept(Client *client, uv_stream_t *handle)
{
    ClientDnsRequest *dnsRequest;
    Listener *listener;
    uv_getnameinfo_t *req;
    int ret;

    if(client == NULL || handle == NULL)
    {
        return false;
    }

    listener = handle->data;

    client->Handle = Malloc(sizeof(uv_tcp_t));

    uv_tcp_init(uv_default_loop(), client->Handle);
    ret = uv_accept(handle, (uv_stream_t *)client->Handle);

    if(ret < 0)
    {
        return false;
    }

    client->Handle->data = client;

    dnsRequest = Malloc(sizeof(ClientDnsRequest));
    dnsRequest->Client = client;

    ret = uv_tcp_getsockname((uv_tcp_t *)client->Handle,
                             (struct sockaddr *)&dnsRequest->Address,
                             &dnsRequest->Address.AddressLength);
    dnsRequest->Address.AddressFamily = dnsRequest->Address.Address.Addr4.sin_family;

    if(ret != 0)
    {
        Free(dnsRequest);
        return false;
    }

    req = Malloc(sizeof(uv_getnameinfo_t));
    req->data = dnsRequest;

    ret = uv_getnameinfo(uv_default_loop(), req, client_on_name_callback,
                         (struct sockaddr *)&dnsRequest->Address, 0);

    if(ret != 0)
    {
        Free(req);
        // TODO: Do DNS failed stuff
        return true;
    }

    return true;
}