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

#include "opmock.h"

#include "lstring.h"

static void
string_is_null_or_empty_when_called_with_null_returns_true()
{
    OP_ASSERT_TRUE(string_is_null_or_empty(NULL));
}

static void string_is_null_or_empty_when_called_with_empty_returns_true()
{
    OP_ASSERT_TRUE(string_is_null_or_empty(""));
}

static void string_is_null_or_empty_when_called_with_string_returns_false()
{
    OP_ASSERT_FALSE(string_is_null_or_empty("string"));
}

int
main()
{
    opmock_test_suite_reset();

    opmock_register_test(string_is_null_or_empty_when_called_with_null_returns_true,
                         "string_is_null_or_empty_when_called_with_null_returns_true");
    opmock_register_test(string_is_null_or_empty_when_called_with_empty_returns_true,
                         "string_is_null_or_empty_when_called_with_empty_returns_true");
    opmock_register_test(string_is_null_or_empty_when_called_with_string_returns_false,
                         "string_is_null_or_empty_when_called_with_string_returns_false");

    opmock_test_suite_run();

    return opmock_test_error > 0;
}
