/*
 * Copyright (c) 2015, Stuart Walsh
 * All rights reserved.
 * parser_tests.c unit tests for the parser
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, thi
 *    list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.

 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" A
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE F
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGE
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "opmock.h"

#include "parser.h"

static void
parser_get_line_when_null_source_returns_false()
{
    bool ret;
    char ircBuf[512 + 1];

    ret = parser_get_line(NULL, ircBuf, sizeof(ircBuf));

    OP_ASSERT_FALSE(ret);
}

static void
parser_get_line_when_null_dest_returns_false()
{
    bool ret;
    Buffer *buffer;

    buffer = buffer_new();
    ret = parser_get_line(buffer, NULL, 512);

    OP_ASSERT_FALSE(ret);
}

static void
parser_get_line_when_empty_buffer_returns_false()
{
    bool ret;
    Buffer *buffer;
    char destBuffer[512 + 1];

    buffer = buffer_new();
    ret = parser_get_line(buffer, destBuffer, sizeof(destBuffer));

    OP_ASSERT_FALSE(ret);
}

static void
parser_get_line_when_line_in_buffer_returns_line()
{
    bool ret;
    Buffer *buffer;
    char destBuffer[512 + 1] = { "12345" };
    char *data = "TEST\r\nFAIL";

    buffer = buffer_new();
    buffer_add(buffer, data, strlen(data));

    ret = parser_get_line(buffer, destBuffer, sizeof(destBuffer));

    OP_ASSERT_TRUE(ret);
    OP_ASSERT_EQUAL_CSTRING("TEST", destBuffer);
}

static void
parser_get_line_when_line_bigger_than_buffer_truncates()
{
    bool ret;
    Buffer *buffer;
    char destBuffer[512 + 1] = { "12345" };
    char *data = "TEST\r\nFAIL";

    buffer = buffer_new();
    buffer_add(buffer, data, strlen(data));

    ret = parser_get_line(buffer, destBuffer, 4);

    OP_ASSERT_TRUE(ret);
    OP_ASSERT_EQUAL_CSTRING("TES", destBuffer);
}

static void
parser_get_line_when_spaces_at_front_trim_spaces()
{
    bool ret;
    Buffer *buffer;
    char destBuffer[512 + 1] = { "12345" };
    char *data = "   TEST\r\nFAIL";

    buffer = buffer_new();
    buffer_add(buffer, data, strlen(data));

    ret = parser_get_line(buffer, destBuffer, sizeof(destBuffer));

    OP_ASSERT_TRUE(ret);
    OP_ASSERT_EQUAL_CSTRING("TEST", destBuffer);
}

static void
parser_get_line_when_spans_two_entries_returns_line()
{
    bool ret;
    Buffer *buffer;
    char destBuffer[512 + 1] = { "12345" };
    char *data1 = "TEST";
    char *data2 = "\r\nFAIL";

    buffer = buffer_new();
    buffer_add(buffer, data1, strlen(data1));
    buffer_add(buffer, data2, strlen(data2));

    ret = parser_get_line(buffer, destBuffer, sizeof(destBuffer));

    OP_ASSERT_TRUE(ret);
    OP_ASSERT_EQUAL_CSTRING("TEST", destBuffer);
}

static void
parser_get_line_when_no_eol_returns_false()
{
    bool ret;
    Buffer *buffer;
    char destBuffer[512 + 1] = { "12345" };
    char *data = "TEST";

    buffer = buffer_new();
    buffer_add(buffer, data, strlen(data));

    ret = parser_get_line(buffer, destBuffer, sizeof(destBuffer));

    OP_ASSERT_FALSE(ret);
}

static void
parser_get_line_when_one_line_called_twice_returns_false()
{
    bool ret;
    Buffer *buffer;
    char destBuffer[512 + 1] = { "12345" };
    char *data = "TEST\r\nFAIL";

    buffer = buffer_new();
    buffer_add(buffer, data, strlen(data));

    ret = parser_get_line(buffer, destBuffer, sizeof(destBuffer));
    OP_ASSERT_TRUE(ret);
    OP_ASSERT_EQUAL_CSTRING("TEST", destBuffer);

    ret = parser_get_line(buffer, destBuffer, sizeof(destBuffer));
    OP_ASSERT_FALSE(ret);
}

static void
parser_get_line_when_called_twice_returns_both()
{
    bool ret;
    Buffer *buffer;
    char destBuffer[512 + 1] = { "12345" };
    char *data = "TEST\r\nOTHER\r\nFAIL";

    buffer = buffer_new();
    buffer_add(buffer, data, strlen(data));

    ret = parser_get_line(buffer, destBuffer, sizeof(destBuffer));
    OP_ASSERT_TRUE(ret);
    OP_ASSERT_EQUAL_CSTRING("TEST", destBuffer);

    ret = parser_get_line(buffer, destBuffer, sizeof(destBuffer));
    OP_ASSERT_TRUE(ret);
    OP_ASSERT_EQUAL_CSTRING("OTHER", destBuffer);
}

static void
parser_get_line_when_spans_two_blocks_returns_line()
{
    bool ret;
    Buffer *buffer;
    char destBuffer[512 + 1] = { "12345" };
    char data[5000];
    char expected[512 + 1];

    memset(data, 'A', 4997);
    data[4998] = '\r';
    data[4999] = '\n';

    memset(expected, 'A', 512);
    expected[512] = '\0';

    buffer = buffer_new();
    buffer_add(buffer, data, sizeof(data));

    ret = parser_get_line(buffer, destBuffer, sizeof(destBuffer));
    OP_ASSERT_TRUE(ret);
    OP_ASSERT_EQUAL_CSTRING(expected, destBuffer);
}

int
main()
{
    opmock_test_suite_reset();

    opmock_register_test(parser_get_line_when_null_source_returns_false,
                         "parser_get_line_when_null_source_returns_false");
    opmock_register_test(parser_get_line_when_null_dest_returns_false,
                         "parser_get_line_when_null_dest_returns_false");
    opmock_register_test(parser_get_line_when_empty_buffer_returns_false,
                         "parser_get_line_when_empty_buffer_returns_false");
    opmock_register_test(parser_get_line_when_line_in_buffer_returns_line,
                         "parser_get_line_when_line_in_buffer_returns_line");
    opmock_register_test(parser_get_line_when_line_bigger_than_buffer_truncates,
                         "parser_get_line_when_line_bigger_than_buffer_truncates");
    opmock_register_test(parser_get_line_when_spaces_at_front_trim_spaces,
                         "parser_get_line_when_spaces_at_front_trim_spaces");
    opmock_register_test(parser_get_line_when_spans_two_entries_returns_line,
                         "parser_get_line_when_spans_two_entries_returns_line");
    opmock_register_test(parser_get_line_when_no_eol_returns_false,
                         "parser_get_line_when_no_eol_returns_false");
    opmock_register_test(parser_get_line_when_one_line_called_twice_returns_false,
                         "parser_get_line_when_one_line_called_twice_returns_false");
    opmock_register_test(parser_get_line_when_called_twice_returns_both,
                         "parser_get_line_when_called_twice_returns_both");
    opmock_register_test(parser_get_line_when_spans_two_blocks_returns_line,
                         "parser_get_line_when_spans_two_blocks_returns_line");

    opmock_test_suite_run();

    return opmock_test_error > 0;
}
