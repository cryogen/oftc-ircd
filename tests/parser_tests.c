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
#include "buffer_stub.h"
#include "memory_stub.h"

#include "parser.h"

static Buffer TestBuffer;
static char TestData[1024];
static ListEntry TestEntry;
static ParserResult ParserRes;

static void
setup_buffer()
{
    memset(&TestBuffer, 0, sizeof(TestBuffer));
    memset(&TestData, 0, sizeof(TestData));
    memset(&TestEntry, 0, sizeof(TestEntry));

    TestEntry.Data = TestData;

    buffer_get_start_ExpectAndReturn(NULL, &TestEntry, NULL);
}

static void
setup_parser_result()
{
    memset(&ParserRes, 0, sizeof(ParserRes));

    Malloc_ExpectAndReturn(sizeof(ParserRes), &ParserRes, cmp_int);
}

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

    setup_buffer();

    ret = parser_get_line(&TestBuffer, NULL, 512);

    OP_ASSERT_FALSE(ret);
}

static void
parser_get_line_when_empty_buffer_returns_false()
{
    bool ret;
    char destBuffer[512 + 1];
    Buffer emptyBuffer = { 0 };

    ret = parser_get_line(&emptyBuffer, destBuffer, sizeof(destBuffer));

    OP_ASSERT_FALSE(ret);
}

static void
parser_get_line_when_line_in_buffer_returns_line()
{
    bool ret;
    char destBuffer[512 + 1] = { "12345" };

    setup_buffer();

    strcpy(TestData, "TEST\r\nFAIL");
    TestBuffer.Size = strlen(TestData);

    ret = parser_get_line(&TestBuffer, destBuffer, sizeof(destBuffer));

    OP_ASSERT_TRUE(ret);
    OP_ASSERT_EQUAL_CSTRING("TEST", destBuffer);

}

static void
parser_get_line_when_line_bigger_than_buffer_truncates()
{
    bool ret;
    char destBuffer[512 + 1] = { "12345" };

    setup_buffer();

    strcpy(TestData, "TEST\r\nFAIL");
    TestBuffer.Size = strlen(TestData);

    ret = parser_get_line(&TestBuffer, destBuffer, 4);

    OP_ASSERT_TRUE(ret);
    OP_ASSERT_EQUAL_CSTRING("TES", destBuffer);
}

static void
parser_get_line_when_spaces_at_front_trim_spaces()
{
    bool ret;
    char destBuffer[512 + 1] = { "12345" };

    setup_buffer();

    strcpy(TestData, "    TEST\r\nFAIL");
    TestBuffer.Size = strlen(TestData);

    ret = parser_get_line(&TestBuffer, destBuffer, sizeof(destBuffer));

    OP_ASSERT_TRUE(ret);
    OP_ASSERT_EQUAL_CSTRING("TEST", destBuffer);
}

static void
parser_get_line_when_no_eol_returns_false()
{
    bool ret;
    char destBuffer[512 + 1] = { "12345" };

    setup_buffer();

    strcpy(TestData, "TEST");
    TestBuffer.Size = strlen(TestData);

    ret = parser_get_line(&TestBuffer, destBuffer, sizeof(destBuffer));

    OP_ASSERT_FALSE(ret);
}

static void
parser_get_line_when_one_line_called_twice_returns_false()
{
    bool ret;
    char destBuffer[512 + 1] = { "12345" };

    setup_buffer();

    strcpy(TestData, "TEST\r\nFAIL");
    TestBuffer.Size = strlen(TestData);

    ret = parser_get_line(&TestBuffer, destBuffer, sizeof(destBuffer));

    OP_ASSERT_TRUE(ret);
    OP_ASSERT_EQUAL_CSTRING("TEST", destBuffer);

    strcpy(TestData, "FAIL");
    TestBuffer.Size = strlen(TestData);

    ret = parser_get_line(&TestBuffer, destBuffer, sizeof(destBuffer));
    OP_ASSERT_FALSE(ret);
}

static void
parser_get_line_when_called_twice_returns_both()
{
    bool ret;
    char destBuffer[512 + 1] = { "12345" };

    setup_buffer();

    strcpy(TestData, "TEST\r\nOTHER\r\nFAIL");
    TestBuffer.Size = strlen(TestData);

    ret = parser_get_line(&TestBuffer, destBuffer, sizeof(destBuffer));
    OP_ASSERT_TRUE(ret);
    OP_ASSERT_EQUAL_CSTRING("TEST", destBuffer);

    strcpy(TestData, "OTHER\r\nFAIL");
    TestBuffer.Size = strlen(TestData);

    ret = parser_get_line(&TestBuffer, destBuffer, sizeof(destBuffer));
    OP_ASSERT_TRUE(ret);
    OP_ASSERT_EQUAL_CSTRING("OTHER", destBuffer);
}

static void
parser_get_line_when_spans_two_blocks_returns_line()
{
    bool ret;
    char destBuffer[512 + 1] = { "12345" };
    char chunk1[4096];
    char chunk2[1000];
    char expected[512 + 1];
    ListEntry entry2 = { 0 };

    setup_buffer();

    memset(chunk1, 'A', sizeof(chunk1));
    memset(chunk2, 'A', 997);
    chunk2[998] = '\r';
    chunk2[999] = '\n';

    memset(expected, 'A', 512);
    expected[512] = '\0';

    TestEntry.Data = chunk1;
    TestEntry.Next = &entry2;
    entry2.Data = chunk2;

    TestBuffer.Size = 4096 + 1000;

    ret = parser_get_line(&TestBuffer, destBuffer, sizeof(destBuffer));
    OP_ASSERT_TRUE(ret);
    OP_ASSERT_EQUAL_CSTRING(expected, destBuffer);
}

static void
parser_process_line_when_buffer_null_returns_null()
{
    ParserResult *ret;

    ret = parser_process_line(NULL, 512);

    OP_ASSERT_TRUE(ret == NULL);
}

static void
parser_process_line_when_no_spaces_returns_command()
{
    ParserResult *ret;

    setup_parser_result();

    ret = parser_process_line("NOSPACES", 9);

    OP_ASSERT_TRUE(ret != NULL);
    OP_ASSERT_EQUAL_CSTRING("NOSPACES", ret->CommandText);

    OP_VERIFY();
}

/*static void
parser_process_line_when_spaces_returns_command()
{
    ParserResult *ret;

    ret = parser_process_line("NOSPACES", 9);

    OP_ASSERT_TRUE(ret != NULL);
    OP_ASSERT_EQUAL_CSTRING("NOSPACES", ret->CommandText);

    OP_VERIFY();
}*/

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
    opmock_register_test(parser_get_line_when_no_eol_returns_false,
                         "parser_get_line_when_no_eol_returns_false");
    opmock_register_test(parser_get_line_when_one_line_called_twice_returns_false,
                         "parser_get_line_when_one_line_called_twice_returns_false");
    opmock_register_test(parser_get_line_when_called_twice_returns_both,
                         "parser_get_line_when_called_twice_returns_both");
    opmock_register_test(parser_get_line_when_spans_two_blocks_returns_line,
                         "parser_get_line_when_spans_two_blocks_returns_line");
    opmock_register_test(parser_process_line_when_buffer_null_returns_null,
                         "parser_process_line_when_buffer_null_returns_null");
    opmock_register_test(parser_process_line_when_no_spaces_returns_command,
                         "parser_process_line_when_no_spaces_returns_command");

    opmock_test_suite_run();

    return opmock_test_error > 0;
}
