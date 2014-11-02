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

static void
setup()
{
    config_init();
}

static void
cleanup()
{
}


START_TEST(config_register_section_WhenCalledWithNameReturnsSection)
{
    ConfigSection *section = config_register_section("Test");

    ck_assert(section != NULL);
    ck_assert(section->Name != NULL);
    ck_assert_str_eq(section->Name, "Test");
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

    suite_add_tcase(s, tcCore);
    
    return s;
}