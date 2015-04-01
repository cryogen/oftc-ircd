/*
 * Copyright (c) 2015, Stuart Walsh
 * All rights reserved.
 * buffer_tests.c buffer tests
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
#include "memory_stub.h"
#include "buffer.h"

static Buffer buffer;
static char FirstChunk[BUFFER_CHUNK_SIZE];
static char SecondChunk[BUFFER_CHUNK_SIZE * 2];

static void
setup_buffer()
{
    memset(&buffer, 0, sizeof(buffer));
    memset(FirstChunk, 0, sizeof(FirstChunk));
    memset(SecondChunk, 0, sizeof(SecondChunk));

    Malloc_ExpectAndReturn(sizeof(Buffer), &buffer, cmp_int);
    Malloc_ExpectAndReturn(BUFFER_CHUNK_SIZE, FirstChunk, cmp_int);

    buffer_new();
}

static void
buffer_push_back_when_null_buffer_works_ok()
{
    buffer_push_back(NULL, NULL, 0);

    OP_VERIFY();
}

static void
buffer_push_back_when_null_data_works_ok()
{
    setup_buffer();

    buffer_push_back(&buffer, NULL, 2 * BUFFER_CHUNK_SIZE);

    OP_ASSERT_TRUE(buffer.buffer != NULL);
    OP_ASSERT_EQUAL_ULONG(0UL, buffer.Size);
    OP_VERIFY();
}

static void
buffer_push_back_when_called_stores_data()
{
    setup_buffer();

    buffer_push_back(&buffer, "Test", strlen("Test"));

    OP_ASSERT_EQUAL_CSTRING("Test", buffer.buffer);
    OP_ASSERT_EQUAL_ULONG(4UL, buffer.Size);
}

static void
buffer_push_back_when_called_exceeding_capacity_increases_capacity()
{
    char tmp[5000];

    memset(tmp, '0', sizeof(tmp));

    setup_buffer();

    Realloc_ExpectAndReturn(NULL, 0, &SecondChunk, NULL, NULL);

    buffer_push_back(&buffer, tmp, sizeof(tmp));

    OP_ASSERT_EQUAL_ULONG(sizeof(tmp), buffer.Size);
    OP_ASSERT_EQUAL_ULONG((size_t)2 * BUFFER_CHUNK_SIZE, buffer.Capacity);
}

static void
buffer_push_back_when_called_twice_adds_both()
{
    setup_buffer();

    buffer_push_back(&buffer, "Test", strlen("Test"));
    buffer_push_back(&buffer, "Second", strlen("Second"));

    OP_ASSERT_EQUAL_CSTRING("TestSecond", buffer.buffer);
    OP_ASSERT_EQUAL_ULONG(10UL, buffer.Size);
}

static void
buffer_pop_front_when_null_buffer_returns_null()
{
    const char *buf = buffer_pop_front(NULL, 0);

    OP_ASSERT_TRUE(buf == NULL);
}

static void
buffer_pop_front_when_zero_len_returns_null()
{
    const char *buf;

    setup_buffer();

    buffer_push_back(&buffer, "Test", strlen("Test"));

    buf = buffer_pop_front(&buffer, 0);

    OP_ASSERT_TRUE(buf == NULL);
}

static void
buffer_pop_front_when_called_returns_buffer()
{
    const char *buf;
    char tmp[16] = { 0 };

    setup_buffer();

    buffer_push_back(&buffer, "Test", strlen("Test"));

    buf = buffer_pop_front(&buffer, 2);
    strncpy(tmp, buf, 2);

    OP_ASSERT_EQUAL_CSTRING("Te", tmp);
    OP_ASSERT_EQUAL_ULONG(2UL, buffer.Size);
}

static void
buffer_pop_front_when_too_long_returns_null()
{
    const char *buf;

    setup_buffer();

    buffer_push_back(&buffer, "Test", strlen("Test"));

    buf = buffer_pop_front(&buffer, 9999);

    OP_ASSERT_TRUE(buf == NULL);
}

static void
buffer_pop_front_when_called_twice_moves_buffer()
{
    const char *buf;
    char tmp[16] = { 0 };

    setup_buffer();

    buffer_push_back(&buffer, "Test", strlen("Test"));

    buf = buffer_pop_front(&buffer, 2);
    buf = buffer_pop_front(&buffer, 2);

    strncpy(tmp, buf, 2);

    OP_ASSERT_EQUAL_CSTRING("st", tmp);
}

static void
buffer_pop_front_when_overflows_wraps()
{
    const char *buf;
    char tmp[16] = { 0 };
    char data[BUFFER_CHUNK_SIZE];

    memset(data, '0', sizeof(tmp));

    setup_buffer();

    buffer_push_back(&buffer, data, sizeof(data));

    buf = buffer_pop_front(&buffer, sizeof(data));

    buffer_push_back(&buffer, "Test", 4);
    buf = buffer_pop_front(&buffer, 2);

    strncpy(tmp, buf, 2);

    OP_ASSERT_EQUAL_CSTRING("Te", tmp);
}

int
main()
{
    opmock_test_suite_reset();

    opmock_register_test(buffer_push_back_when_null_buffer_works_ok,
                         "buffer_push_back_when_null_buffer_works_ok");
    opmock_register_test(buffer_push_back_when_null_data_works_ok,
                         "buffer_push_back_when_null_data_works_ok");
    opmock_register_test(buffer_push_back_when_called_stores_data,
                         "buffer_push_back_when_called_stores_data");
    opmock_register_test(buffer_push_back_when_called_exceeding_capacity_increases_capacity,
                         "buffer_push_back_when_called_exceeding_capacity_increases_capacity");
    opmock_register_test(buffer_push_back_when_called_twice_adds_both,
                         "buffer_push_back_when_called_twice_adds_both");
    opmock_register_test(buffer_pop_front_when_null_buffer_returns_null,
                         "buffer_pop_front_when_null_buffer_returns_null");
    opmock_register_test(buffer_pop_front_when_zero_len_returns_null,
                         "buffer_pop_front_when_zero_len_returns_null");
    opmock_register_test(buffer_pop_front_when_called_returns_buffer,
                         "buffer_pop_front_when_called_returns_buffer");
    opmock_register_test(buffer_pop_front_when_too_long_returns_null,
                         "buffer_pop_front_when_too_long_returns_null");
    opmock_register_test(buffer_pop_front_when_called_twice_moves_buffer,
                         "buffer_pop_front_when_called_twice_moves_buffer");
    opmock_register_test(buffer_pop_front_when_overflows_wraps,
                         "buffer_pop_front_when_overflows_wraps");

    opmock_test_suite_run();

    return opmock_test_error > 0;
}
