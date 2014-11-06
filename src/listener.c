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

#include "listener.h"
#include "config.h"
#include "memory.h"

static void
listener_set_name(Listener *listener, json_object *obj)
{
    listener->Name = json_object_get_string(obj);

    printf("%s\n", listener->Name);
}

static Listener *
listener_new_listener()
{
    return Malloc(sizeof(Listener));
}

void
listener_init()
{
    ConfigSection *section = config_register_section("listeners", true);

    section->NewElement = (ConfigNewElementHandler)listener_new_listener;

    ConfigField *field = Malloc(sizeof(ConfigField));

    field->Name = "name";
    field->Type = json_type_string;
    field->Handler = (ConfigFieldHandler)listener_set_name;

    config_register_field(section, field);
}