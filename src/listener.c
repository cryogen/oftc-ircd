/*
 * Copyright (c) 2014, Stuart Walsh
 * All rights reserved.
 * listener.c socket listeners
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

#include <stdio.h>
#include <uv.h>

#include "listener.h"
#include "config.h"
#include "memory.h"
#include "vector.h"
#include "lstring.h"
#include "network.h"

static Vector *listeners;

static void
listener_set_name(Listener *listener, json_object *obj)
{
    listener->Name = json_object_get_string(obj);
}

static void
listener_set_host(Listener *listener, json_object *obj)
{
    listener->Host = json_object_get_string(obj);
}

static void
listener_set_port(Listener *listener, json_object *obj)
{
    listener->Port = json_object_get_int(obj);
}

static Listener *
listener_new_listener()
{
    return Malloc(sizeof(Listener));
}

static void
listener_add(Listener *listener)
{
    if(string_is_null_or_empty(listener->Host))
    {
        Listener *v4Listener = listener_new_listener();
        v4Listener->Port = listener->Port;
        v4Listener->Host = StrDup("0.0.0.0");

        listener_add(v4Listener);

        listener->Host = StrDup("::");
    }

    vector_push_back(listeners, listener);
    
    Free(listener);
}

static void
listener_on_connection(uv_stream_t *handle, int status)
{
    printf("connection!\n");
}

void
listener_init()
{
    ConfigSection *section = config_register_section("listeners", true);

    section->NewElement = (ConfigNewElementHandler)listener_new_listener;
    section->ElementDone = (ConfigElementDoneHandler)listener_add;

    config_register_field(section, "name", json_type_string,
                          (ConfigFieldHandler)listener_set_name);
    config_register_field(section, "host", json_type_string,
                          (ConfigFieldHandler)listener_set_host);
    config_register_field(section, "port", json_type_int,
                          (ConfigFieldHandler)listener_set_port);

    listeners = vector_new(0, sizeof(Listener));
}

void
listener_start_listeners()
{
    for(int i = 0; i < vector_length(listeners); i++)
    {
        Listener *listener = vector_get(listeners, i);
        struct addrinfo *addr;
        unsigned int flags = 0;
        int ret;

        uv_tcp_init(uv_default_loop(), &listener->handle);

        addr = get_addr_from_ip(listener->Host, listener->Port);
        if(addr->ai_family == AF_INET6)
        {
            flags = UV_TCP_IPV6ONLY;
        }

        ret = uv_tcp_bind(&listener->handle, addr->ai_addr, flags);
        if(ret < 0)
        {
            freeaddrinfo(addr);
            fprintf(stderr, "Error binding to listener socket (%s)",
                    uv_strerror(ret));
            continue;
        }

        ret = uv_listen((uv_stream_t *) &listener->handle,
                        LISTENER_DEFAULT_BACKLOG, listener_on_connection);
        if(ret < 0)
        {
            freeaddrinfo(addr);
            fprintf(stderr, "Error starting listener (%s)",
                    uv_strerror(ret));
            continue;
        }
        freeaddrinfo(addr);
    }
}