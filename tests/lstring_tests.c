/*
 * Copyright (c) 2014, Stuart Walsh
 * All rights reserved.
 * lstring_tests Tests for lstring functions
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

#include "lstring.h"

START_TEST(string_is_null_or_empty_WhenCalledWithNullReturnsTrue)
{
    ck_assert(string_is_null_or_empty(NULL));
}
END_TEST

START_TEST(string_is_null_or_empty_WhenCalledWithEmptyReturnsTrue)
{
    ck_assert(string_is_null_or_empty(""));
}
END_TEST

START_TEST(string_is_null_or_empty_WhenCalledWithStringReturnsFalse)
{
    ck_assert(!string_is_null_or_empty("string"));
}
END_TEST

Suite *
lstring_suite()
{
    Suite *s;
    TCase *tcCore;

    s = suite_create("lstring");

    tcCore = tcase_create("Core");

    tcase_add_test(tcCore, string_is_null_or_empty_WhenCalledWithNullReturnsTrue);
    tcase_add_test(tcCore, string_is_null_or_empty_WhenCalledWithEmptyReturnsTrue);
    tcase_add_test(tcCore, string_is_null_or_empty_WhenCalledWithStringReturnsFalse);

    suite_add_tcase(s, tcCore);
    
    return s;
}