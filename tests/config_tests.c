/*
 * Copyright (c) 2014, Stuart Walsh
 * All rights reserved.
 * config.c config subsystem
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

#include <check.h>

#include "config.h"
#include "serverstate.h"

static void
setup()
{
    hash_init();
    config_init();
}

static void
cleanup()
{
}

START_TEST(config_register_section_WhenCalledWithNameReturnsSection)
{
    ConfigSection *section = config_register_section("Test", false);

    ck_assert(section != NULL);
    ck_assert(section->Name != NULL);
    ck_assert_str_eq(section->Name, "Test");
}
END_TEST

START_TEST(config_register_field_WhenCalledWithSectionSucceeds)
{
    ConfigSection *section = config_register_section("Test", false);
    ConfigField field;

    field.Name = "Test";
    field.Type = json_type_string;

    ck_assert(section != NULL);

    config_register_field(section, &field);
}
END_TEST

START_TEST(config_register_field_WhenCalledWithNullSectionDoesNotCrash)
{
    ConfigSection *section = config_register_section("Test", false);
    ConfigField field;

    field.Name = "Test";
    field.Type = json_type_string;

    ck_assert(section != NULL);

    config_register_field(NULL, &field);
}
END_TEST

START_TEST(config_load_WhenPathIsNullReturnsFalse)
{
    bool ret = config_load();

    ck_assert(!ret);
}
END_TEST

START_TEST(config_load_WhenPathNotFoundReturnsFalse)
{
    bool ret;

    serverstate_set_config_path("not.found");

    ret = config_load();

    ck_assert(!ret);
}
END_TEST

START_TEST(config_load_WhenFileInvalidJsonReturnsFalse)
{
    bool ret;

    serverstate_set_config_path("test1.conf");

    ret = config_load();

    ck_assert(!ret);
}
END_TEST

START_TEST(config_load_WhenFileNoObjectRootReturnsFalse)
{
    bool ret;

    serverstate_set_config_path("test2.conf");

    ret = config_load();

    ck_assert(!ret);
}
END_TEST

START_TEST(config_load_WhenObjectValueWrongTypeReturnsOk)
{
    bool ret;

    serverstate_set_config_path("test3.conf");

    config_register_section("test", false);

    ret = config_load();

    ck_assert(ret);
}
END_TEST

START_TEST(config_load_WhenUnknownSectionReturnsOk)
{
    bool ret;

    serverstate_set_config_path("test4.conf");

    config_register_section("test", false);

    ret = config_load();

    ck_assert(ret);
}
END_TEST

static void foo_field_handler(void *unused, json_object *obj)
{
    ck_assert_str_eq(json_object_get_string(obj), "bar");
}

START_TEST(config_load_NonArraySectionSetsValue)
{
    bool ret;
    ConfigSection *section;
    ConfigField *field;

    serverstate_set_config_path("test5.conf");

    section = config_register_section("test", false);

    field = malloc(sizeof(ConfigField));
    field->Name = "foo";
    field->Type = json_type_string;
    field->Handler = foo_field_handler;

    config_register_field(section, field);

    ret = config_load();

    ck_assert(ret);
}
END_TEST

START_TEST(config_load_NonArrayNoHandlerDoesNotCrash)
{
    bool ret;
    ConfigSection *section;
    ConfigField *field;

    serverstate_set_config_path("test5.conf");

    section = config_register_section("test", false);

    field = malloc(sizeof(ConfigField));
    field->Name = "foo";
    field->Type = json_type_string;

    config_register_field(section, field);

    ret = config_load();

    ck_assert(ret);
}
END_TEST

Suite *
config_suite()
{
    Suite *s;
    TCase *tcCore;

    s = suite_create("config");

    tcCore = tcase_create("Core");

    tcase_add_unchecked_fixture(tcCore, setup, cleanup);

    tcase_add_test(tcCore, config_register_section_WhenCalledWithNameReturnsSection);
    tcase_add_test(tcCore, config_register_field_WhenCalledWithSectionSucceeds);
    tcase_add_test(tcCore, config_register_field_WhenCalledWithNullSectionDoesNotCrash);
    tcase_add_test(tcCore, config_load_WhenPathIsNullReturnsFalse);
    tcase_add_test(tcCore, config_load_WhenPathNotFoundReturnsFalse);
    tcase_add_test(tcCore, config_load_WhenFileInvalidJsonReturnsFalse);
    tcase_add_test(tcCore, config_load_WhenFileNoObjectRootReturnsFalse);
    tcase_add_test(tcCore, config_load_WhenObjectValueWrongTypeReturnsOk);
    tcase_add_test(tcCore, config_load_WhenUnknownSectionReturnsOk);
    tcase_add_test(tcCore, config_load_NonArraySectionSetsValue);
    tcase_add_test(tcCore, config_load_NonArrayNoHandlerDoesNotCrash);
    suite_add_tcase(s, tcCore);
    
    return s;
}