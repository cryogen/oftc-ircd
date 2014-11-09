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
#include "vector.h"

static Vector *listeners;

static void
listener_set_name(Listener *listener, json_object *obj)
{
    listener->Name = json_object_get_string(obj);
}

static Listener *
listener_new_listener()
{
    return Malloc(sizeof(Listener));
}

static void
listener_add(Listener *listener)
{
    vector_push_back(listeners, listener);
    
    Free(listener);
}

void
listener_init()
{
    ConfigSection *section = config_register_section("listeners", true);

    section->NewElement = (ConfigNewElementHandler)listener_new_listener;
    section->ElementDone = (ConfigElementDoneHandler)listener_add;

    config_register_field(section, "name", json_type_string,
                          (ConfigFieldHandler)listener_set_name);

    listeners = vector_new(0, sizeof(Listener));
}