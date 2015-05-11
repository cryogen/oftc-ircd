/*
 * Copyright (c) 2015, Stuart Walsh
 * All rights reserved.
 * nick.c NICK command module
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

#include "module.h"
#include "command.h"
#include "lstring.h"
#include "server.h"
#include "numeric.h"

static void
nick_handler(Client *client, Vector *params)
{
    const char *nick = vector_get(params, 0);
    Client *target;

    if(string_is_null_or_empty(nick))
    {
        client_send(server_get_this_server(), client, ERR_NONICKNAMEGIVEN);
        return;
    }

    target = client_find(nick);
    if(target != NULL)
    {
        client_send(server_get_this_server(), client, ERR_NICKNAMEINUSE, nick);
        return;
    }

    client_set_nickname(client, nick);

    if(client_can_register(client))
    {
        client_register(client);
    }
}

static bool
nick_load()
{
    command_register("NICK", Unregistered, nick_handler, 1);

    return true;
}

static bool
nick_unload()
{
    return true;
}

ModuleInfo ModuleInfoPtr =
{
    nick_load,
    nick_unload
};
