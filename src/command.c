/*
 * Copyright (c) 2015, Stuart Walsh
 * All rights reserved.
 * command.h command handling functions
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

#include "command.h"
#include "hash.h"
#include "memory.h"
#include "lstring.h"

static Hash *CommandHash;

void
command_init()
{
    CommandHash = hash_new("Command Hash", 0);
}

Command *
command_new()
{
    return Malloc(sizeof(Command));
}

void
command_free(Command *command)
{
    if(command != NULL)
    {
        Free(command);
    }
}

void
command_register(const char *name,
                 CommandAccess access,
                 CommandHandler handler,
                 int minParams)
{
    Command *command;

    command = command_new();

    command->Name = name;
    command->RequiredAccess = access;
    command->Handler = handler;
    command->MinParams = minParams;

    hash_add_string(CommandHash, name, command);
}

Command *
command_find(const char *name)
{
    Command *ret;

    if(string_is_null_or_empty(name))
    {
        return NULL;
    }

    ret = hash_find(CommandHash, name);

    if(ret == NULL)
    {
        return NULL;
    }

    return ret;
}
