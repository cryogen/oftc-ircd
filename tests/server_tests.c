/*
 * Copyright (c) 2015, Stuart Walsh
 * All rights reserved.
 * server_tests.c server tests
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
#include "server.h"

#include "config_stub.h"
#include "client_stub.h"
#include "json_object_stub.h"

static void
server_init_when_called_sets_up_server()
{
    ConfigSection section;

    config_register_section_ExpectAndReturn(NULL, false, &section, NULL, NULL);
    config_register_field_ExpectAndReturn(NULL, NULL, 0, NULL, NULL, NULL,
                                          NULL, NULL);
    server_init();

    OP_VERIFY();
}

static void
set_defaults_once(ConfigSection *section,
                  const char *name,
                  json_type type,
                  ConfigFieldHandler handler,
                  int calls)
{
    section->SetDefaults();
}

static void
set_defaults_twice(ConfigSection *section,
                  const char *name,
                  json_type type,
                  ConfigFieldHandler handler,
                  int calls)
{
    section->SetDefaults();
    section->SetDefaults();
}

static void
server_set_defaults_when_called_allocates_client()
{
    ConfigSection section = { 0 };

    config_register_section_ExpectAndReturn(NULL, false, &section, NULL, NULL);
    config_register_field_MockWithCallback(set_defaults_once);
    client_new_ExpectAndReturn(NULL);

    server_init();

    OP_VERIFY();
}

static void
server_set_defaults_when_called_twice_frees_old_client()
{
    ConfigSection section = { 0 };
    Client client = { 0 };

    config_register_section_ExpectAndReturn(NULL, false, &section, NULL, NULL);
    config_register_field_MockWithCallback(set_defaults_twice);
    client_new_ExpectAndReturn(&client);
    client_free_ExpectAndReturn(NULL, NULL);
    client_new_ExpectAndReturn(&client);

    server_init();

    OP_VERIFY();
}

static void
set_name_callback(ConfigSection *section,
                  const char *name,
                  json_type type,
                  ConfigFieldHandler handler,
                  int calls)
{
    json_object obj = { 0 };

    section->SetDefaults();

    handler(NULL, &obj);
}

static void
server_set_name_when_called_sets_name()
{
    ConfigSection section = { 0 };
    Client client = { 0 };

    config_register_section_ExpectAndReturn(NULL, false, &section, NULL, NULL);
    config_register_field_MockWithCallback(set_name_callback);
    client_free_ExpectAndReturn(NULL, NULL);
    client_new_ExpectAndReturn(&client);
    json_object_get_string_ExpectAndReturn(NULL, "test.server", NULL);

    server_init();

    OP_VERIFY();
}

static void
server_get_this_server_when_called_returns_server()
{
    server_get_this_server();

    OP_VERIFY();
}

int
main()
{
    opmock_test_suite_reset();

    opmock_register_test(server_init_when_called_sets_up_server,
                         "server_init_when_called_sets_up_server");
    opmock_register_test(server_set_defaults_when_called_allocates_client,
                         "server_set_defaults_when_called_allocates_client");
    opmock_register_test(server_set_defaults_when_called_twice_frees_old_client,
                         "server_set_defaults_when_called_twice_frees_old_client");
    opmock_register_test(server_set_name_when_called_sets_name,
                         "server_set_name_when_called_sets_name");
    opmock_register_test(server_get_this_server_when_called_returns_server,
                         "server_get_this_server_when_called_returns_server");

    opmock_test_suite_run();

    return opmock_test_error > 0;
}
