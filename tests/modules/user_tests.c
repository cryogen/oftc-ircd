/*
 * Copyright (c) 2015, Stuart Walsh
 * All rights reserved.
 * user_test tests for the user command module
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
#include "module.h"
#include "client.h"
#include "numeric.h"

#include "command_stub.h"
#include "client_stub.h"
#include "vector_stub.h"
#include "server_stub.h"

extern ModuleInfo ModuleInfoPtr;

CommandHandler handler;

static int
get_handler(void *left, void *right, const char *name, char *message)
{
    handler = *(CommandHandler *)right;

    return 0;
}

static void
user_handler_when_registered_returns()
{
    Client TestClient = { 0 };

    TestClient.AccessLevel = Standard;

    server_get_this_server_ExpectAndReturn(NULL);
    client_send_ExpectAndReturn(NULL, &TestClient, ERR_ALREADYREGISTERED, NULL,
                                NULL, cmp_ptr, cmp_cstr);

    handler(&TestClient, NULL);

    OP_VERIFY();
}

static void
user_handler_when_called_sets_username_and_realname()
{
    Client TestClient = { 0 };

    vector_get_ExpectAndReturn(NULL, 0, "User", NULL, cmp_int);
    client_set_username_ExpectAndReturn(&TestClient, "User", true, cmp_ptr, cmp_cstr);
    vector_get_ExpectAndReturn(NULL, 3, "Realname", NULL, cmp_int);
    client_set_realname_ExpectAndReturn(&TestClient, "Realname", true, cmp_ptr,
                                        cmp_cstr);
    client_can_register_ExpectAndReturn(&TestClient, false, cmp_ptr);

    handler(&TestClient, NULL);

    OP_VERIFY();
}

static void
user_handler_when_called_twice_updates_username()
{
    Client TestClient = { 0 };

    vector_get_ExpectAndReturn(NULL, 0, "User", NULL, cmp_int);
    client_set_username_ExpectAndReturn(&TestClient, "User", true, cmp_ptr, cmp_cstr);
    vector_get_ExpectAndReturn(NULL, 3, "Realname", NULL, cmp_int);
    client_set_realname_ExpectAndReturn(&TestClient, "Realname", true, cmp_ptr,
                                        cmp_cstr);

    client_can_register_ExpectAndReturn(&TestClient, false, cmp_ptr);

    vector_get_ExpectAndReturn(NULL, 0, "User", NULL, cmp_int);
    client_set_username_ExpectAndReturn(&TestClient, "User", true, cmp_ptr, cmp_cstr);
    vector_get_ExpectAndReturn(NULL, 3, "Realname", NULL, cmp_int);
    client_set_realname_ExpectAndReturn(&TestClient, "Realname", true, cmp_ptr,
                                        cmp_cstr);

    client_can_register_ExpectAndReturn(&TestClient, false, cmp_ptr);

    handler(&TestClient, NULL);
    handler(&TestClient, NULL);

    OP_VERIFY();
}

static void
user_handler_when_can_register_registers()
{
    Client TestClient = { 0 };

    vector_get_ExpectAndReturn(NULL, 0, "User", NULL, cmp_int);
    client_set_username_ExpectAndReturn(&TestClient, "User", true, cmp_ptr, cmp_cstr);
    vector_get_ExpectAndReturn(NULL, 3, "Realname", NULL, cmp_int);
    client_set_realname_ExpectAndReturn(&TestClient, "Realname", true, cmp_ptr,
                                        cmp_cstr);
    client_can_register_ExpectAndReturn(&TestClient, true, cmp_ptr);
    client_register_ExpectAndReturn(&TestClient, cmp_ptr);

    handler(&TestClient, NULL);

    OP_VERIFY();
}

int
main()
{
    opmock_test_suite_reset();

    command_register_ExpectAndReturn(NULL, 0, NULL, 0, NULL, NULL, get_handler,
                                     NULL);

    ModuleInfoPtr.Load();

    opmock_register_test(user_handler_when_registered_returns,
                         "user_handler_when_registered_returns");
    opmock_register_test(user_handler_when_called_sets_username_and_realname,
                         "user_handler_when_called_sets_username_and_realname");
    opmock_register_test(user_handler_when_called_twice_updates_username,
                         "user_handler_when_called_twice_updates_username");
    opmock_register_test(user_handler_when_can_register_registers,
                         "user_handler_when_can_register_registers");

    opmock_test_suite_run();

    return opmock_test_error > 0;
}