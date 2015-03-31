/*
 * Copyright (c) 2015, Stuart Walsh
 * All rights reserved.
 * command_tests.c command tests
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

#include "opmock.h"
#include "command.h"

#include "hash_stub.h"
#include "memory_stub.h"

static void
command_init_when_called_sets_up_commands()
{
    hash_new_ExpectAndReturn(NULL, 0, NULL, NULL, NULL);

    command_init();

    OP_VERIFY();
}

static void
command_free_when_called_with_null_does_nothing()
{
    command_free(NULL);

    OP_VERIFY();
}

static void
command_free_when_called_with_command_frees()
{
    Command command;

    Free_ExpectAndReturn(&command, cmp_ptr);

    command_free(&command);

    OP_VERIFY();
}

static void
command_register_when_called_registers_command()
{
    Command command;

    Malloc_ExpectAndReturn(sizeof(Command), &command, cmp_int);
    hash_add_string_ExpectAndReturn(NULL, NULL, NULL, NULL, NULL, NULL);

    command_register("TEST", Standard, NULL, 0);

    OP_VERIFY();
}

int
main()
{
    opmock_test_suite_reset();

    opmock_register_test(command_init_when_called_sets_up_commands,
                         "command_init_when_called_sets_up_commands");
    opmock_register_test(command_register_when_called_registers_command,
                         "command_register_when_called_registers_command");
    opmock_register_test(command_free_when_called_with_null_does_nothing,
                         "command_free_when_called_with_null_does_nothing");
    opmock_register_test(command_free_when_called_with_command_frees,
                         "command_free_when_called_with_command_frees");

    opmock_test_suite_run();

    return opmock_test_error > 0;
}
