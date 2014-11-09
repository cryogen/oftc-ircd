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

    ck_assert(section != NULL);

    config_register_field(section, "Test", json_type_string, NULL);
}
END_TEST

START_TEST(config_register_field_WhenCalledWithNullSectionDoesNotCrash)
{
    ConfigSection *section = config_register_section("Test", false);

    ck_assert(section != NULL);

    config_register_field(NULL, "Test", json_type_string, NULL);
}
END_TEST

START_TEST(config_load_WhenPathIsNullReturnsFalse)
{
    bool ret = config_load();

    ck_assert(!ret);
}
END_TEST

static bool setDefaultsCalled = false;

static void
set_defaults_callback()
{
    setDefaultsCalled = true;
}

START_TEST(config_load_CallsSetDefaultsForSections)
{
    bool ret;

    serverstate_set_config_path("test5.conf");

    ConfigSection *section = config_register_section("Test", false);
    section->SetDefaults = set_defaults_callback;

    setDefaultsCalled = false;
    ret = config_load();

    ck_assert(setDefaultsCalled);
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

static bool callbackCalled = false;

static void foo_field_handler(void *unused, json_object *obj)
{
    callbackCalled = true;
    ck_assert_str_eq(json_object_get_string(obj), "bar");
}

START_TEST(config_load_NonArrayNoHandlerDoesNotCrash)
{
    bool ret;
    ConfigSection *section;

    serverstate_set_config_path("test5.conf");

    section = config_register_section("test", false);

    callbackCalled = false;

    config_register_field(section, "foo", json_type_string, NULL);

    ret = config_load();

    ck_assert(ret);
    ck_assert(!callbackCalled);
}
END_TEST

START_TEST(config_load_NotArrayAndConfigHasArrayDoesNotCrash)
{
    bool ret;
    ConfigSection *section;

    serverstate_set_config_path("test6.conf");

    section = config_register_section("test", false);

    config_register_field(section, "foo", json_type_string, NULL);

    callbackCalled = false;

    ret = config_load();

    ck_assert(ret);
    ck_assert(!callbackCalled);
}
END_TEST

START_TEST(config_load_ArrayNoNewElementHandlerDoesNotCrash)
{
    bool ret;
    ConfigSection *section;

    serverstate_set_config_path("test6.conf");

    section = config_register_section("test", true);

    callbackCalled = false;
    ret = config_load();

    ck_assert(ret);
    ck_assert(!callbackCalled);
}
END_TEST

START_TEST(config_load_ArrayNoHandlerDoesNotCrash)
{
    bool ret;
    ConfigSection *section;

    serverstate_set_config_path("test6.conf");

    section = config_register_section("test", true);

    config_register_field(section, "foo", json_type_string, NULL);

    callbackCalled = false;

    ret = config_load();

    ck_assert(ret);
    ck_assert(!callbackCalled);
}
END_TEST

START_TEST(config_load_NonArraySectionSetsValue)
{
    bool ret;
    ConfigSection *section;

    serverstate_set_config_path("test5.conf");

    section = config_register_section("test", false);

    config_register_field(section, "foo", json_type_string, foo_field_handler);

    callbackCalled = false;
    ret = config_load();

    ck_assert(ret);
    ck_assert(callbackCalled);
}
END_TEST

START_TEST(config_load_ArraySectionWrongTypeDoesNotCrash)
{
    bool ret;
    ConfigSection *section;

    serverstate_set_config_path("test6.conf");

    section = config_register_section("test", true);

    ret = config_load();

    ck_assert(ret);
}
END_TEST

START_TEST(config_load_ArraySectionSetsValue)
{
    bool ret;
    ConfigSection *section;

    serverstate_set_config_path("test6.conf");

    section = config_register_section("test", true);

    config_register_field(section, "foo", json_type_string, foo_field_handler);

    callbackCalled = false;
    ret = config_load();

    ck_assert(ret);
    ck_assert(callbackCalled);
}
END_TEST

START_TEST(config_load_WhenFieldHasWrongTypeDoesNotCrash)
{
    bool ret;
    ConfigSection *section;

    serverstate_set_config_path("test7.conf");

    section = config_register_section("test", true);

    config_register_field(section, "foo", json_type_string, foo_field_handler);

    ret = config_load();

    ck_assert(ret);
}
END_TEST

static int newElementCounter = 0;

static void *
new_element_callback()
{
    newElementCounter++;

    return NULL;
}

static int doneElementCounter = 0;

static void
section_done_callback(void *unused)
{
    doneElementCounter++;
}

START_TEST(config_load_WhenNewElementSpecifiedIsCalledPerItem)
{
    bool ret;
    ConfigSection *section;

    serverstate_set_config_path("test8.conf");

    section = config_register_section("test", true);
    section->NewElement = new_element_callback;
    section->ElementDone = section_done_callback;

    config_register_field(section, "foo", json_type_string, NULL);

    newElementCounter = 0;
    doneElementCounter = 0;
    ret = config_load();

    ck_assert(ret);
    ck_assert_int_eq(newElementCounter, 2);
    ck_assert_int_eq(doneElementCounter, 2);
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
    tcase_add_test(tcCore, config_load_CallsSetDefaultsForSections);
    tcase_add_test(tcCore, config_load_WhenPathNotFoundReturnsFalse);
    tcase_add_test(tcCore, config_load_WhenFileInvalidJsonReturnsFalse);
    tcase_add_test(tcCore, config_load_WhenFileNoObjectRootReturnsFalse);
    tcase_add_test(tcCore, config_load_WhenObjectValueWrongTypeReturnsOk);
    tcase_add_test(tcCore, config_load_WhenUnknownSectionReturnsOk);
    tcase_add_test(tcCore, config_load_NonArraySectionSetsValue);
    tcase_add_test(tcCore, config_load_NonArrayNoHandlerDoesNotCrash);
    tcase_add_test(tcCore, config_load_ArrayNoNewElementHandlerDoesNotCrash);
    tcase_add_test(tcCore, config_load_ArrayNoHandlerDoesNotCrash);
    tcase_add_test(tcCore, config_load_NotArrayAndConfigHasArrayDoesNotCrash);
    tcase_add_test(tcCore, config_load_WhenFieldHasWrongTypeDoesNotCrash);
    tcase_add_test(tcCore, config_load_ArraySectionSetsValue);
    tcase_add_test(tcCore, config_load_WhenFieldHasWrongTypeDoesNotCrash);
    tcase_add_test(tcCore, config_load_WhenNewElementSpecifiedIsCalledPerItem);
    suite_add_tcase(s, tcCore);
    
    return s;
}