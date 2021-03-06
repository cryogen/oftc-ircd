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
#include <tls.h>
#include <stdio.h>
#include <json-c/json.h>
#include <assert.h>

#include "connection.h"
#include "client.h"
#include "serverstate.h"
#include "memory.h"
#include "irc.h"
#include "listener.h"
#include "config.h"

static ConnectionState CurrentConnectionState = { 0 };

static void
connection_write_callback(uv_write_t *req, int status)
{
    Free(req);
}

static void
connection_set_private_key(void *element, json_object *obj)
{
    CurrentConnectionState.PrivateKey = json_object_get_string(obj);
}

static void
connection_set_certificate_file(void *element, json_object *obj)
{
    CurrentConnectionState.CertificateFile = json_object_get_string(obj);
}

static bool
connection_tls_handshake(Client *client)
{
    uv_os_fd_t fd;
    struct tls *context = NULL;
    int ret = TLS_READ_AGAIN;

    if(uv_fileno((uv_handle_t *)client->handle, &fd) != 0)
    {
        return false;
    }

    while((ret = tls_accept_socket(CurrentConnectionState.ServerContext,
                                  &context, fd)) != 0)
    {
        if(ret == -1)
        {
            return false;
        }
    }

    client->TlsContext = context;
    tls_get_cert_fingerprint(client->TlsContext, client->CertificateFp,
                             sizeof(client->CertificateFp));

    return true;
}

static void
connection_allocate_buffer_callback(uv_handle_t *handle,
                                    size_t suggestedSize,
                                    uv_buf_t *buf)
{
    buf->base = Malloc(suggestedSize);
    buf->len = suggestedSize;
}

static void
connection_on_read_callback(uv_stream_t *stream, ssize_t nRead, const uv_buf_t *buf)
{
    Client *client = stream->data;

    assert(client != NULL);

    if(nRead == UV_EOF)
    {
        // TODO: exit client due to connection closed, probably get consolidated
        // with below
        client_free(client);
        return;
    }
    else if(nRead < 0)
    {
        // TODO: exit client due to read error
        client_free(client);
        return;
    }

    buffer_add(client->ReadBuffer, buf->base, (size_t)nRead);

    client_process_read_buffer(client);

    Free(buf->base);
}

static void
connection_poll_callback(uv_poll_t *handle, int status, int events)
{
    Client *client = handle->data;
    uv_buf_t buffer = { 0 };
    size_t len;
    int ret;

    if(status != 0)
    {
        client_free(client);
        return;
    }

    connection_allocate_buffer_callback((uv_handle_t *)handle,
                                        DEFAULT_READ_SIZE, &buffer);

    while((ret = tls_read(client->TlsContext, buffer.base, buffer.len, &len)) != 0)
    {
        if(ret == -1)
        {
            client_free(client);
            return;
        }
    }

    connection_on_read_callback((uv_stream_t *)handle, len, &buffer);
}

void
connection_init()
{
    ConfigSection *connectionSection;

    connectionSection = config_register_section("connection", false);

    config_register_field(connectionSection, "privatekey", json_type_string,
                          connection_set_private_key);
    config_register_field(connectionSection, "certificatefile", json_type_string,
                          connection_set_certificate_file);
}

void
connection_init_tls()
{
    tls_init();

    CurrentConnectionState.TlsConfiguration = tls_config_new();
    CurrentConnectionState.ServerContext = tls_server();
    CurrentConnectionState.ClientContext = tls_client();

    tls_config_set_key_file(CurrentConnectionState.TlsConfiguration,
                            CurrentConnectionState.PrivateKey);

    tls_config_set_cert_file(CurrentConnectionState.TlsConfiguration,
                             CurrentConnectionState.CertificateFile);

    tls_config_insecure_noverifycert(CurrentConnectionState.TlsConfiguration);

    if(tls_configure(CurrentConnectionState.ServerContext,
                     CurrentConnectionState.TlsConfiguration) != 0)
    {
        printf("%s\n", tls_error(CurrentConnectionState.ServerContext));
    }

    if(tls_configure(CurrentConnectionState.ClientContext,
                     CurrentConnectionState.TlsConfiguration) != 0)
    {
        printf("%s\n", tls_error(CurrentConnectionState.ClientContext));
    }
}


void
connection_accept(uv_stream_t *handle)
{
    Client *newClient;
    uv_tcp_t *newHandle;
    NetworkAddress address = { 0 };
    Listener *listener;

    if(handle == NULL)
    {
        return;
    }

    listener = handle->data;

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
    newHandle->data = newClient;
    newClient->handle = newHandle;

    memcpy(&newClient->Address, &address, sizeof(NetworkAddress));

    if(listener->IsTls)
    {
        if(!connection_tls_handshake(newClient))
        {
            client_free(newClient);
            return;
        }
    }
    
    client_lookup_dns(newClient);
}

void
connection_start_read(Client *client)
{
    if(client == NULL)
    {
        return;
    }

    if(client->TlsContext != NULL)
    {
        uv_os_fd_t fd;
        uv_poll_t *handle = Malloc(sizeof(uv_poll_t));

        handle->data = client;

        uv_fileno((uv_handle_t *)client->handle, &fd);

        uv_poll_init(serverstate_get_event_loop(), handle, fd);
        if(uv_poll_start(handle, UV_READABLE, connection_poll_callback) < 0)
        {
            client_free(client);
        }
    }
    else
    {
        if(uv_read_start((uv_stream_t *)client->handle,
                         connection_allocate_buffer_callback,
                         connection_on_read_callback) < 0)
        {
            client_free(client);
        }
    }
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

    if(client->TlsContext != NULL)
    {
        tls_write(client->TlsContext, buffer, len, &len);
    }
    else
    {
        req = Malloc(sizeof(uv_write_t));

        uv_write(req, (uv_stream_t *)client->handle, &buf, 1,
                 connection_write_callback);
    }
}
