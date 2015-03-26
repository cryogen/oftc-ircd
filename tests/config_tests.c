/*
 * Copyright (c) 2014, Stuart Walsh
 * All rights reserved.
 * config_tests.c config tests
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
#include "config.h"
#include "hash_stub.h"
#include "vector_stub.h"
#include "serverstate_stub.h"
#include "uv_stub.h"
#include "json_object_stub.h"
#include "json_tokener_stub.h"
#include "memory_stub.h"

static bool setDefaultsCalled = false;
static bool handlerCalled = false;
static bool verifyCalled = false;
static bool newElementCalled = false;
static bool elementDoneCalled = false;
static uv_buf_t buf;
static json_tokener tok;
static json_object obj;
static struct lh_table table;
static struct lh_entry head;

static void
set_defaults_callback()
{
    setDefaultsCalled = true;
}

static void
field_handler(void *element, json_object *obj)
{
    handlerCalled = true;
}

static bool
verify_section_callback()
{
    verifyCalled = true;

    return true;
}

static bool
verify_section_fail_callback()
{
    verifyCalled = true;

    return false;
}

static void *
new_element_callback()
{
    newElementCalled = true;

    return (void *)0x12345678;
}

static void
element_done_callback()
{
    elementDoneCalled = true;
}

static void
init_buf()
{
    memset(&buf, 0, sizeof(buf));
    memset(&tok, 0, sizeof(tok));
    memset(&obj, 0, sizeof(obj));

    vector_length_ExpectAndReturn(NULL, 0, NULL);
    serverstate_get_config_path_ExpectAndReturn("test.conf");
    uv_buf_init_ExpectAndReturn(NULL, 0, buf, NULL, NULL);
    serverstate_get_event_loop_ExpectAndReturn(NULL);
    uv_fs_open_ExpectAndReturn(NULL, NULL, NULL, 0, 0, NULL, 0, NULL, NULL,
                               NULL, NULL, NULL, NULL);
    json_tokener_new_ExpectAndReturn(&tok);
}

static void
init_read()
{
    memset(&head, 0, sizeof(head));
    memset(&table, 0, sizeof(table));

    obj.o_type = json_type_object;
    table.head = &head;

    uv_fs_read_ExpectAndReturn(NULL, NULL, 0, 0, 0, 0, NULL, 1, NULL, NULL,
                               NULL, NULL, NULL, NULL, NULL);
    json_tokener_parse_ex_ExpectAndReturn(&tok, NULL, 0, &obj, cmp_ptr,
                                          NULL, NULL);
    json_tokener_get_error_ExpectAndReturn(&tok, 0, cmp_ptr);
    json_object_get_type_ExpectAndReturn(&obj, json_type_object, cmp_ptr);
    json_object_get_object_ExpectAndReturn(&obj, &table, cmp_ptr);
}

void
config_init_when_called_sets_up_hash_and_vector()
{
    hash_new_ExpectAndReturn(NULL, 0, NULL, NULL, NULL);
    vector_new_ExpectAndReturn(0, 0, NULL, NULL, NULL);

    config_init();

    OP_VERIFY();
}

void
config_load_when_path_is_null_returns_false()
{
    vector_length_ExpectAndReturn(NULL, 0, NULL);
    serverstate_get_config_path_ExpectAndReturn(NULL);

    bool ret = config_load();

    OP_ASSERT_FALSE(ret);
    OP_VERIFY();
}

void
config_load_when_sections_registered_and_set_defaults_is_null_works_ok()
{
    ConfigSection section = { 0 };

    vector_length_ExpectAndReturn(NULL, 1, NULL);
    vector_get_ExpectAndReturn(NULL, 0, &section, NULL, NULL);
    serverstate_get_config_path_ExpectAndReturn(NULL);

    bool ret = config_load();

    OP_ASSERT_FALSE(ret);
    OP_VERIFY();
}

void
config_load_when_sections_registered_set_defaults_called()
{
    ConfigSection section = { 0 };

    section.SetDefaults = set_defaults_callback;

    vector_length_ExpectAndReturn(NULL, 1, NULL);
    vector_get_ExpectAndReturn(NULL, 0, &section, NULL, NULL);
    serverstate_get_config_path_ExpectAndReturn(NULL);

    bool ret = config_load();

    OP_ASSERT_FALSE(ret);
    OP_ASSERT_TRUE(setDefaultsCalled);
    OP_VERIFY();
}

void
config_load_when_fs_open_fails_returns_false()
{
    vector_length_ExpectAndReturn(NULL, 0, NULL);
    serverstate_get_config_path_ExpectAndReturn("test.conf");
    uv_buf_init_ExpectAndReturn(NULL, 0, buf, NULL, NULL);
    serverstate_get_event_loop_ExpectAndReturn(NULL);
    uv_fs_open_ExpectAndReturn(NULL, NULL, NULL, 0, 0, NULL, -1, NULL, NULL,
                               NULL, NULL, NULL, NULL);

    bool ret = config_load();

    OP_ASSERT_FALSE(ret);
    OP_VERIFY();
}

void
config_load_when_fs_read_fails_returns_false()
{
    init_buf();

    uv_fs_read_ExpectAndReturn(NULL, NULL, 0, 0, 0, 0, NULL, -1, NULL, NULL,
                               NULL, NULL, NULL, NULL, NULL);
    json_tokener_free_ExpectAndReturn(&tok, cmp_ptr);
    uv_fs_close_ExpectAndReturn(NULL, NULL, 0, NULL, 0, NULL, NULL, NULL, NULL);

    bool ret = config_load();

    OP_ASSERT_FALSE(ret);
    OP_VERIFY();
}

void
config_load_when_invalid_json_returns_false()
{
    init_buf();

    uv_fs_read_ExpectAndReturn(NULL, NULL, 0, 0, 0, 0, NULL, 1, NULL, NULL,
                               NULL, NULL, NULL, NULL, NULL);
    json_tokener_parse_ex_ExpectAndReturn(&tok, NULL, 0, NULL, cmp_ptr,
                                          NULL, NULL);
    json_tokener_get_error_ExpectAndReturn(&tok, json_tokener_error_parse_array,
                                           cmp_ptr);
    json_tokener_error_desc_ExpectAndReturn(0, "Test error", NULL);
    json_tokener_free_ExpectAndReturn(&tok, cmp_ptr);
    uv_fs_close_ExpectAndReturn(NULL, NULL, 0, NULL, 0, NULL, NULL, NULL, NULL);

    bool ret = config_load();

    OP_ASSERT_FALSE(ret);
    OP_VERIFY();
}

void
config_load_when_invalid_json_second_time_returns_false()
{
    init_buf();

    uv_fs_read_ExpectAndReturn(NULL, NULL, 0, 0, 0, 0, NULL, 1, NULL, NULL,
                               NULL, NULL, NULL, NULL, NULL);
    json_tokener_parse_ex_ExpectAndReturn(&tok, NULL, 0, NULL, cmp_ptr,
                                          NULL, NULL);
    json_tokener_get_error_ExpectAndReturn(&tok, json_tokener_continue,
                                           cmp_ptr);
    uv_fs_read_ExpectAndReturn(NULL, NULL, 0, 0, 0, 0, NULL, 1, NULL, NULL,
                               NULL, NULL, NULL, NULL, NULL);

    json_tokener_parse_ex_ExpectAndReturn(&tok, NULL, 0, NULL, cmp_ptr,
                                          NULL, NULL);
    json_tokener_get_error_ExpectAndReturn(&tok, json_tokener_error_parse_array,
                                           cmp_ptr);
    json_tokener_error_desc_ExpectAndReturn(0, "Test error", NULL);
    json_tokener_free_ExpectAndReturn(&tok, cmp_ptr);
    uv_fs_close_ExpectAndReturn(NULL, NULL, 0, NULL, 0, NULL, NULL, NULL, NULL);

    bool ret = config_load();

    OP_ASSERT_FALSE(ret);
    OP_VERIFY();
}

void
config_load_when_no_root_object_returns_false()
{
    init_buf();

    uv_fs_read_ExpectAndReturn(NULL, NULL, 0, 0, 0, 0, NULL, 1, NULL, NULL,
                               NULL, NULL, NULL, NULL, NULL);
    json_tokener_parse_ex_ExpectAndReturn(&tok, NULL, 0, &obj, cmp_ptr,
                                          NULL, NULL);
    json_tokener_get_error_ExpectAndReturn(&tok, 0, cmp_ptr);
    json_object_get_type_ExpectAndReturn(&obj, json_type_boolean, cmp_ptr);
    json_tokener_free_ExpectAndReturn(&tok, cmp_ptr);
    uv_fs_close_ExpectAndReturn(NULL, NULL, 0, NULL, 0, NULL, NULL, NULL, NULL);

    bool ret = config_load();

    OP_ASSERT_FALSE(ret);
    OP_VERIFY();
}

void
config_load_when_section_not_found_works_ok()
{
    init_buf();
    init_read();

    hash_find_ExpectAndReturn(NULL, NULL, NULL, NULL, NULL);
    uv_fs_read_ExpectAndReturn(NULL, NULL, 0, 0, 0, 0, NULL, 0, NULL, NULL,
                               NULL, NULL, NULL, NULL, NULL);
    json_tokener_free_ExpectAndReturn(&tok, cmp_ptr);
    uv_fs_close_ExpectAndReturn(NULL, NULL, 0, NULL, 0, NULL, NULL, NULL, NULL);
    vector_length_ExpectAndReturn(NULL, 0, NULL);

    bool ret = config_load();

    OP_ASSERT_TRUE(ret);
    OP_VERIFY();
}

void
config_load_when_section_found_and_wrong_type_works_ok()
{
    ConfigSection section = { 0 };

    init_buf();
    init_read();

    hash_find_ExpectAndReturn(NULL, NULL, &section, NULL, NULL);
    json_object_get_type_ExpectAndReturn(NULL, json_type_string, NULL);
    uv_fs_read_ExpectAndReturn(NULL, NULL, 0, 0, 0, 0, NULL, 0, NULL, NULL,
                               NULL, NULL, NULL, NULL, NULL);
    json_tokener_free_ExpectAndReturn(&tok, cmp_ptr);
    uv_fs_close_ExpectAndReturn(NULL, NULL, 0, NULL, 0, NULL, NULL, NULL, NULL);
    vector_length_ExpectAndReturn(NULL, 0, NULL);

    bool ret = config_load();

    OP_ASSERT_TRUE(ret);
    OP_VERIFY();
}

void
config_load_when_field_not_found_returns_ok()
{
    ConfigSection section = { 0 };

    init_buf();
    init_read();

    hash_find_ExpectAndReturn(NULL, NULL, &section, NULL, NULL);
    json_object_get_type_ExpectAndReturn(NULL, json_type_object, NULL);
    json_object_get_object_ExpectAndReturn(&obj, &table, NULL);
    hash_find_ExpectAndReturn(NULL, NULL, NULL, NULL, NULL);
    uv_fs_read_ExpectAndReturn(NULL, NULL, 0, 0, 0, 0, NULL, 0, NULL, NULL,
                               NULL, NULL, NULL, NULL, NULL);
    json_tokener_free_ExpectAndReturn(&tok, cmp_ptr);
    uv_fs_close_ExpectAndReturn(NULL, NULL, 0, NULL, 0, NULL, NULL, NULL, NULL);
    vector_length_ExpectAndReturn(NULL, 0, NULL);

    bool ret = config_load();

    OP_ASSERT_TRUE(ret);
    OP_VERIFY();
}

void
config_load_when_field_wrong_type_returns_ok()
{
    ConfigSection section = { 0 };
    ConfigField field = { 0 };

    field.Handler = field_handler;

    init_buf();
    init_read();

    hash_find_ExpectAndReturn(NULL, NULL, &section, NULL, NULL);
    json_object_get_type_ExpectAndReturn(NULL, json_type_object, NULL);
    json_object_get_object_ExpectAndReturn(&obj, &table, NULL);
    hash_find_ExpectAndReturn(NULL, NULL, &field, NULL, NULL);
    json_object_get_type_ExpectAndReturn(NULL, json_type_string, NULL);
    uv_fs_read_ExpectAndReturn(NULL, NULL, 0, 0, 0, 0, NULL, 0, NULL, NULL,
                               NULL, NULL, NULL, NULL, NULL);
    json_tokener_free_ExpectAndReturn(&tok, cmp_ptr);
    uv_fs_close_ExpectAndReturn(NULL, NULL, 0, NULL, 0, NULL, NULL, NULL, NULL);
    vector_length_ExpectAndReturn(NULL, 0, NULL);

    handlerCalled = false;

    bool ret = config_load();

    OP_ASSERT_TRUE(ret);
    OP_ASSERT_FALSE(handlerCalled);
    OP_VERIFY();
}

void
config_load_when_field_handler_null_returns_ok()
{
    ConfigSection section = { 0 };
    ConfigField field = { 0 };

    field.Handler = field_handler;

    init_buf();
    init_read();

    hash_find_ExpectAndReturn(NULL, NULL, &section, NULL, NULL);
    json_object_get_type_ExpectAndReturn(NULL, json_type_object, NULL);
    json_object_get_object_ExpectAndReturn(&obj, &table, NULL);
    hash_find_ExpectAndReturn(NULL, NULL, &field, NULL, NULL);
    json_object_get_type_ExpectAndReturn(NULL, json_type_string, NULL);
    uv_fs_read_ExpectAndReturn(NULL, NULL, 0, 0, 0, 0, NULL, 0, NULL, NULL,
                               NULL, NULL, NULL, NULL, NULL);
    json_tokener_free_ExpectAndReturn(&tok, cmp_ptr);
    uv_fs_close_ExpectAndReturn(NULL, NULL, 0, NULL, 0, NULL, NULL, NULL, NULL);
    vector_length_ExpectAndReturn(NULL, 0, NULL);

    handlerCalled = false;

    bool ret = config_load();

    OP_ASSERT_TRUE(ret);
    OP_ASSERT_FALSE(handlerCalled);
    OP_VERIFY();
}

void
config_load_when_field_handler_provided_calls_handler()
{
    ConfigSection section = { 0 };
    ConfigField field = { 0 };

    field.Handler = field_handler;
    field.Type = json_type_string;

    init_buf();
    init_read();

    hash_find_ExpectAndReturn(NULL, NULL, &section, NULL, NULL);
    json_object_get_type_ExpectAndReturn(NULL, json_type_object, NULL);
    json_object_get_object_ExpectAndReturn(&obj, &table, NULL);
    hash_find_ExpectAndReturn(NULL, NULL, &field, NULL, NULL);
    json_object_get_type_ExpectAndReturn(NULL, json_type_string, NULL);
    uv_fs_read_ExpectAndReturn(NULL, NULL, 0, 0, 0, 0, NULL, 0, NULL, NULL,
                               NULL, NULL, NULL, NULL, NULL);
    json_tokener_free_ExpectAndReturn(&tok, cmp_ptr);
    uv_fs_close_ExpectAndReturn(NULL, NULL, 0, NULL, 0, NULL, NULL, NULL, NULL);
    vector_length_ExpectAndReturn(NULL, 0, NULL);

    handlerCalled = false;

    bool ret = config_load();

    OP_ASSERT_TRUE(ret);
    OP_ASSERT_TRUE(handlerCalled);
    OP_VERIFY();
}

void
config_load_when_sections_registered_and_verify_null_works_ok()
{
    ConfigSection section = { 0 };

    init_buf();
    init_read();

    hash_find_ExpectAndReturn(NULL, NULL, NULL, NULL, NULL);
    uv_fs_read_ExpectAndReturn(NULL, NULL, 0, 0, 0, 0, NULL, 0, NULL, NULL,
                               NULL, NULL, NULL, NULL, NULL);
    json_tokener_free_ExpectAndReturn(&tok, cmp_ptr);
    uv_fs_close_ExpectAndReturn(NULL, NULL, 0, NULL, 0, NULL, NULL, NULL, NULL);
    vector_length_ExpectAndReturn(NULL, 1, NULL);
    vector_get_ExpectAndReturn(NULL, 0, &section, NULL, NULL);
    vector_length_ExpectAndReturn(NULL, 0, NULL);

    verifyCalled = false;

    bool ret = config_load();

    OP_ASSERT_TRUE(ret);
    OP_ASSERT_FALSE(verifyCalled);
    OP_VERIFY();
}

void
config_load_when_sections_registered_verify_called()
{
    ConfigSection section = { 0 };

    section.VerifySection = verify_section_callback;

    init_buf();
    init_read();

    hash_find_ExpectAndReturn(NULL, NULL, NULL, NULL, NULL);
    uv_fs_read_ExpectAndReturn(NULL, NULL, 0, 0, 0, 0, NULL, 0, NULL, NULL,
                               NULL, NULL, NULL, NULL, NULL);
    json_tokener_free_ExpectAndReturn(&tok, cmp_ptr);
    uv_fs_close_ExpectAndReturn(NULL, NULL, 0, NULL, 0, NULL, NULL, NULL, NULL);
    vector_length_ExpectAndReturn(NULL, 1, NULL);
    vector_get_ExpectAndReturn(NULL, 0, &section, NULL, NULL);
    vector_length_ExpectAndReturn(NULL, 0, NULL);

    verifyCalled = false;

    bool ret = config_load();

    OP_ASSERT_TRUE(ret);
    OP_ASSERT_TRUE(verifyCalled);
    OP_VERIFY();
}

void
config_load_when_sections_registered_verify_fail_returns_false()
{
    ConfigSection section = { 0 };

    section.VerifySection = verify_section_fail_callback;

    init_buf();
    init_read();

    hash_find_ExpectAndReturn(NULL, NULL, NULL, NULL, NULL);
    uv_fs_read_ExpectAndReturn(NULL, NULL, 0, 0, 0, 0, NULL, 0, NULL, NULL,
                               NULL, NULL, NULL, NULL, NULL);
    json_tokener_free_ExpectAndReturn(&tok, cmp_ptr);
    uv_fs_close_ExpectAndReturn(NULL, NULL, 0, NULL, 0, NULL, NULL, NULL, NULL);
    vector_length_ExpectAndReturn(NULL, 1, NULL);
    vector_get_ExpectAndReturn(NULL, 0, &section, NULL, NULL);

    verifyCalled = false;

    bool ret = config_load();

    OP_ASSERT_FALSE(ret);
    OP_ASSERT_TRUE(verifyCalled);
    OP_VERIFY();
}

void
config_load_when_array_and_new_element_null_returns_ok()
{
    ConfigSection section = { 0 };

    section.IsArray = true;

    init_buf();
    init_read();

    hash_find_ExpectAndReturn(NULL, NULL, &section, NULL, NULL);
    json_object_get_type_ExpectAndReturn(NULL, json_type_array, NULL);
    json_object_array_length_ExpectAndReturn(NULL, 1, NULL);
    json_object_array_get_idx_ExpectAndReturn(NULL, 0, NULL, NULL, NULL);
    json_object_get_type_ExpectAndReturn(NULL, json_type_array, NULL);
    uv_fs_read_ExpectAndReturn(NULL, NULL, 0, 0, 0, 0, NULL, 0, NULL, NULL,
                               NULL, NULL, NULL, NULL, NULL);
    json_tokener_free_ExpectAndReturn(&tok, cmp_ptr);
    uv_fs_close_ExpectAndReturn(NULL, NULL, 0, NULL, 0, NULL, NULL, NULL, NULL);
    vector_length_ExpectAndReturn(NULL, 0, NULL);

    bool ret = config_load();

    OP_ASSERT_TRUE(ret);
    OP_VERIFY();
}

void
config_load_when_array_calls_new_element()
{
    ConfigSection section = { 0 };

    section.IsArray = true;
    section.NewElement = new_element_callback;

    init_buf();
    init_read();

    hash_find_ExpectAndReturn(NULL, NULL, &section, NULL, NULL);
    json_object_get_type_ExpectAndReturn(NULL, json_type_array, NULL);
    json_object_array_length_ExpectAndReturn(NULL, 1, NULL);
    json_object_array_get_idx_ExpectAndReturn(NULL, 0, NULL, NULL, NULL);
    json_object_get_type_ExpectAndReturn(NULL, json_type_array, NULL);
    uv_fs_read_ExpectAndReturn(NULL, NULL, 0, 0, 0, 0, NULL, 0, NULL, NULL,
                               NULL, NULL, NULL, NULL, NULL);
    json_tokener_free_ExpectAndReturn(&tok, cmp_ptr);
    uv_fs_close_ExpectAndReturn(NULL, NULL, 0, NULL, 0, NULL, NULL, NULL, NULL);
    vector_length_ExpectAndReturn(NULL, 0, NULL);

    bool ret = config_load();

    OP_ASSERT_TRUE(ret);
    OP_VERIFY();
}

void
config_load_when_array_processes_object()
{
    struct lh_table table2 = { 0 };
    ConfigSection section = { 0 };

    section.IsArray = true;

    init_buf();
    init_read();

    hash_find_ExpectAndReturn(NULL, NULL, &section, NULL, NULL);
    json_object_get_type_ExpectAndReturn(NULL, json_type_array, NULL);
    json_object_array_length_ExpectAndReturn(NULL, 1, NULL);
    json_object_array_get_idx_ExpectAndReturn(NULL, 0, NULL, NULL, NULL);
    json_object_get_type_ExpectAndReturn(NULL, json_type_object, NULL);
    json_object_get_object_ExpectAndReturn(NULL, &table2, NULL);
    uv_fs_read_ExpectAndReturn(NULL, NULL, 0, 0, 0, 0, NULL, 0, NULL, NULL,
                               NULL, NULL, NULL, NULL, NULL);
    json_tokener_free_ExpectAndReturn(&tok, cmp_ptr);
    uv_fs_close_ExpectAndReturn(NULL, NULL, 0, NULL, 0, NULL, NULL, NULL, NULL);
    vector_length_ExpectAndReturn(NULL, 0, NULL);

    bool ret = config_load();

    OP_ASSERT_TRUE(ret);
    OP_VERIFY();
}

void
config_load_when_array_calls_element_done()
{
    struct lh_table table2 = { 0 };
    ConfigSection section = { 0 };

    section.IsArray = true;
    section.ElementDone = element_done_callback;

    init_buf();
    init_read();
    
    hash_find_ExpectAndReturn(NULL, NULL, &section, NULL, NULL);
    json_object_get_type_ExpectAndReturn(NULL, json_type_array, NULL);
    json_object_array_length_ExpectAndReturn(NULL, 1, NULL);
    json_object_array_get_idx_ExpectAndReturn(NULL, 0, NULL, NULL, NULL);
    json_object_get_type_ExpectAndReturn(NULL, json_type_object, NULL);
    json_object_get_object_ExpectAndReturn(NULL, &table2, NULL);
    uv_fs_read_ExpectAndReturn(NULL, NULL, 0, 0, 0, 0, NULL, 0, NULL, NULL,
                               NULL, NULL, NULL, NULL, NULL);
    json_tokener_free_ExpectAndReturn(&tok, cmp_ptr);
    uv_fs_close_ExpectAndReturn(NULL, NULL, 0, NULL, 0, NULL, NULL, NULL, NULL);
    vector_length_ExpectAndReturn(NULL, 0, NULL);

    bool ret = config_load();

    OP_ASSERT_TRUE(ret);
    OP_VERIFY();
}

void
config_register_section_when_called_with_null_name_returns_null()
{
    ConfigSection *section = config_register_section(NULL, false);

    OP_ASSERT_TRUE(section == NULL);
    OP_VERIFY();
}

void
config_register_section_when_called_registers_section()
{
    StrDup_ExpectAndReturn(NULL, NULL, NULL);
    hash_new_ExpectAndReturn(NULL, 0, NULL, NULL, NULL);
    vector_push_back_ExpectAndReturn(NULL, NULL, (void *)0x12345678, NULL, NULL);
    hash_add_string_ExpectAndReturn(NULL, NULL, NULL, NULL, NULL, NULL);

    ConfigSection *section = config_register_section("Test", false);

    OP_ASSERT_TRUE(section != NULL);
    OP_VERIFY();
}

void
config_register_field_when_section_null_returns_ok()
{
    config_register_field(NULL, NULL, json_type_string, NULL);

    OP_VERIFY();
}

void
config_register_field_when_name_null_returns_ok()
{
    ConfigSection section = { 0 };

    config_register_field(&section, NULL, json_type_string, NULL);

    OP_VERIFY();
}

void
config_register_field_registers_field()
{
    ConfigSection section = { 0 };
    void *ptr = malloc(sizeof(ConfigField));

    Malloc_ExpectAndReturn(sizeof(ConfigField), ptr, cmp_int);
    StrDup_ExpectAndReturn(NULL, NULL, NULL);
    hash_add_string_ExpectAndReturn(NULL, NULL, NULL, NULL, NULL, NULL);

    config_register_field(&section, "Test", json_type_string, NULL);

    OP_VERIFY();
}

int
main()
{
    opmock_test_suite_reset();

    opmock_register_test(config_init_when_called_sets_up_hash_and_vector,
                         "config_init_when_called_sets_up_hash_and_vector");
    opmock_register_test(config_load_when_path_is_null_returns_false,
                         "config_load_when_path_is_null_returns_false");
    opmock_register_test(config_load_when_sections_registered_and_set_defaults_is_null_works_ok,
                         "config_load_when_sections_registered_and_set_defaults_is_null_works_ok");
    opmock_register_test(config_load_when_sections_registered_set_defaults_called,
                         "config_load_when_sections_registered_set_defaults_called");
    opmock_register_test(config_load_when_fs_open_fails_returns_false,
                         "config_load_when_fs_open_fails_returns_false");
    opmock_register_test(config_load_when_fs_read_fails_returns_false,
                         "config_load_when_fs_read_fails_returns_false");
    opmock_register_test(config_load_when_invalid_json_returns_false,
                         "config_load_when_invalid_json_returns_false");
    opmock_register_test(config_load_when_invalid_json_second_time_returns_false,
                         "config_load_when_invalid_json_second_time_returns_false");
    opmock_register_test(config_load_when_no_root_object_returns_false,
                         "config_load_when_no_root_object_returns_false");
    opmock_register_test(config_load_when_section_not_found_works_ok,
                         "config_load_when_section_not_found_works_ok");
    opmock_register_test(config_load_when_section_found_and_wrong_type_works_ok,
                         "config_load_when_section_found_and_wrong_type_works_ok");
    opmock_register_test(config_load_when_field_not_found_returns_ok,
                         "config_load_when_field_not_found_returns_ok");
    opmock_register_test(config_load_when_field_wrong_type_returns_ok,
                         "config_load_when_field_wrong_type_returns_ok");
    opmock_register_test(config_load_when_field_handler_null_returns_ok,
                         "config_load_when_field_handler_null_returns_ok");
    opmock_register_test(config_load_when_field_handler_provided_calls_handler,
                         "config_load_when_field_handler_provided_calls_handler");
    opmock_register_test(config_load_when_sections_registered_and_verify_null_works_ok,
                         "config_load_when_sections_registered_and_verify_null_works_ok");
    opmock_register_test(config_load_when_sections_registered_verify_fail_returns_false,
                         "config_load_when_sections_registered_verify_fail_returns_false");
    opmock_register_test(config_load_when_sections_registered_verify_called,
                         "config_load_when_sections_registered_verify_called");
    opmock_register_test(config_load_when_array_and_new_element_null_returns_ok,
                         "config_load_when_array_and_new_element_null_returns_ok");
    opmock_register_test(config_load_when_array_calls_new_element,
                         "config_load_when_array_calls_new_element");
    opmock_register_test(config_load_when_array_processes_object,
                         "config_load_when_array_processes_object");
    opmock_register_test(config_load_when_array_calls_element_done,
                         "config_load_when_array_calls_element_done");
    opmock_register_test(config_register_section_when_called_with_null_name_returns_null,
                         "config_register_section_when_called_with_null_name_returns_null");
    opmock_register_test(config_register_section_when_called_registers_section,
                         "config_register_section_when_called_registers_section");
    opmock_register_test(config_register_field_when_section_null_returns_ok,
                         "config_register_field_when_section_null_returns_ok");
    opmock_register_test(config_register_field_when_name_null_returns_ok,
                         "config_register_field_when_name_null_returns_ok");
    opmock_register_test(config_register_field_registers_field,
                         "config_register_field_registers_field");

    opmock_test_suite_run();

    return opmock_test_error > 0;
}