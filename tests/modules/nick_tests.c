/*
 * Copyright (c) 2015, Stuart Walsh
 * All rights reserved.
 * nick_test tests for the nick command module
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
#include "command_stub.h"
#include "vector_stub.h"
#include "client_stub.h"
#include "server_stub.h"

#include "module.h"
#include "command.h"
#include "numeric.h"

extern ModuleInfo ModuleInfoPtr;

CommandHandler handler;

static int
get_handler(void *left, void *right, const char *name, char *message)
{
    handler = *(CommandHandler *)right;

    return 0;
}

static void
nick_handler_when_blank_nick_sends_error()
{
    Client client = { 0 };

    vector_get_ExpectAndReturn(NULL, 0, "", NULL, cmp_int);
    server_get_this_server_ExpectAndReturn(NULL);
    client_send_ExpectAndReturn(NULL, &client, ERR_NONICKNAMEGIVEN, NULL,
                                NULL, cmp_ptr, cmp_cstr);

    handler(&client, NULL);

    OP_VERIFY();
}

static void
nick_handler_when_in_use_send_error()
{
    Client client = { 0 };

    vector_get_ExpectAndReturn(NULL, 0, "Test", NULL, cmp_int);
    client_find_ExpectAndReturn("Test", &client, cmp_cstr);
    server_get_this_server_ExpectAndReturn(NULL);
    client_send_ExpectAndReturn(NULL, &client, ERR_NICKNAMEINUSE, NULL,
                                NULL, cmp_ptr, cmp_cstr);

    handler(&client, NULL);

    OP_VERIFY();
}

static void
nick_handler_when_can_not_register_changes_nick()
{
    Client client = { 0 };

    vector_get_ExpectAndReturn(NULL, 0, "Test", NULL, cmp_int);
    client_find_ExpectAndReturn("Test", NULL, cmp_cstr);
    client_set_nickname_ExpectAndReturn(&client, "Test", true, cmp_ptr, cmp_cstr);
    client_can_register_ExpectAndReturn(&client, false, cmp_ptr);

    handler(&client, NULL);

    OP_VERIFY();
}

static void
nick_handler_when_can_register_registers()
{
    Client client = { 0 };

    vector_get_ExpectAndReturn(NULL, 0, "Test", NULL, cmp_int);
    client_find_ExpectAndReturn("Test", NULL, cmp_cstr);
    client_set_nickname_ExpectAndReturn(&client, "Test", true, cmp_ptr, cmp_cstr);
    client_can_register_ExpectAndReturn(&client, true, cmp_ptr);
    client_register_ExpectAndReturn(&client, cmp_ptr);

    handler(&client, NULL);

    OP_VERIFY();
}

int
main()
{
    opmock_test_suite_reset();

    command_register_ExpectAndReturn(NULL, 0, NULL, 0, NULL, NULL, get_handler,
                                     NULL);

    ModuleInfoPtr.Load();

    opmock_register_test(nick_handler_when_blank_nick_sends_error,
                         "nick_handler_when_blank_nick_sends_error");
    opmock_register_test(nick_handler_when_in_use_send_error,
                         "nick_handler_when_in_use_send_error");
    opmock_register_test(nick_handler_when_can_not_register_changes_nick,
                         "nick_handler_when_can_not_register_changes_nick");
    opmock_register_test(nick_handler_when_can_register_registers,
                         "nick_handler_when_can_register_registers");

    opmock_test_suite_run();
    
    return opmock_test_error > 0;
}