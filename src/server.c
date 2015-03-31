/*
 * Copyright (c) 2015, Stuart Walsh
 * All rights reserved.
 * server.c server related functions
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

#include <json-c/json.h>

#include "client.h"
#include "server.h"
#include "config.h"

static Client *ThisServer = NULL;

static void
server_set_name(void *element, json_object *object)
{
    strncpy(ThisServer->Name, json_object_get_string(object), HOSTLEN - 1);
}

static void
server_set_defaults()
{
    if(ThisServer != NULL)
    {
        client_free(ThisServer);
    }

    ThisServer = client_new();
}

void
server_init()
{
    ConfigSection *serverSection;

    serverSection = config_register_section("server", false);
    serverSection->SetDefaults = server_set_defaults;

    config_register_field(serverSection, "name", json_type_string,
                          server_set_name);
}

inline Client *
server_get_this_server()
{
    return ThisServer;
}
