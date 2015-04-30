/*
 * Copyright (c) 2015, Stuart Walsh
 * All rights reserved.
 * connection.c underlying network connection
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

#include <uv.h>
#include <string.h>

#include "connection.h"
#include "client.h"
#include "serverstate.h"
#include "memory.h"
#include "irc.h"

static void
connection_write_callback(uv_write_t *req, int status)
{
    Free(req);
}

void
connection_accept(uv_stream_t *handle)
{
    Client *newClient;
    uv_tcp_t *newHandle;
    NetworkAddress address = { 0 };

    if(handle == NULL)
    {
        return;
    }

    newHandle = Malloc(sizeof(uv_tcp_t));
    uv_tcp_init(serverstate_get_event_loop(), newHandle);
    if(uv_accept(handle, (uv_stream_t *)newHandle) != 0)
    {
        Free(handle);
        return;
    }

    if(!network_address_from_stream(newHandle, &address))
    {
        uv_close((uv_handle_t *)handle, NULL);
        Free(handle);
        return;
    }

    newClient = client_new();
    newClient->handle = newHandle;

    memcpy(&newClient->Address, &address, sizeof(NetworkAddress));

    client_lookup_dns(newClient);
}

void
connection_send(Client *client, char *buffer)
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

    uv_write(req, (uv_stream_t *)client->handle, &buf, 1,
             connection_write_callback);
}

