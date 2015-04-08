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
static char SecondChunk[BUFFER_CHUNK_SIZE];
static char ThirdChunk[BUFFER_CHUNK_SIZE];
static List list;
static ListEntry ListEntry1;
static ListEntry ListEntry2;
static ListEntry ListEntry3;

static void
setup_buffer()
{
    memset(&buffer, 0, sizeof(buffer));
    memset(FirstChunk, 0, sizeof(FirstChunk));
    memset(SecondChunk, 0, sizeof(SecondChunk));
    memset(ThirdChunk, 0, sizeof(ThirdChunk));
    memset(&list, 0, sizeof(list));
    memset(&ListEntry1, 0, sizeof(ListEntry));
    memset(&ListEntry2, 0, sizeof(ListEntry));
    memset(&ListEntry3, 0, sizeof(ListEntry));

    Malloc_ExpectAndReturn(sizeof(Buffer), &buffer, cmp_int);
    Malloc_ExpectAndReturn(sizeof(List), &list, cmp_int);

    buffer_new();
}

static void
buffer_add_when_null_buffer_works_ok()
{
    buffer_add(NULL, NULL, 0);

    OP_VERIFY();
}

static void
buffer_add_when_null_data_works_ok()
{
    setup_buffer();

    buffer_add(&buffer, NULL, 2 * BUFFER_CHUNK_SIZE);

    OP_ASSERT_TRUE(buffer.Data != NULL);
    OP_ASSERT_EQUAL_ULONG(0UL, buffer.Size);
    OP_VERIFY();
}

static void
buffer_add_when_called_stores_data()
{
    setup_buffer();

    Malloc_ExpectAndReturn(BUFFER_CHUNK_SIZE, &FirstChunk, cmp_int);
    Malloc_ExpectAndReturn(sizeof(ListEntry), &ListEntry1, cmp_int);

    buffer_add(&buffer, "Test", strlen("Test"));

    OP_ASSERT_EQUAL_CSTRING("Test", (char *)buffer.Data->Head->Data);
    OP_ASSERT_EQUAL_ULONG(4UL, buffer.Size);
}

static void
buffer_add_when_called_exceeding_capacity_increases_capacity()
{
    char tmp[5000];

    memset(tmp, '0', sizeof(tmp));

    setup_buffer();

    Malloc_ExpectAndReturn(BUFFER_CHUNK_SIZE, &FirstChunk, cmp_int);
    Malloc_ExpectAndReturn(sizeof(ListEntry), &ListEntry1, cmp_int);
    Malloc_ExpectAndReturn(BUFFER_CHUNK_SIZE, &SecondChunk, cmp_int);
    Malloc_ExpectAndReturn(sizeof(ListEntry), &ListEntry1, cmp_int);

    buffer_add(&buffer, tmp, sizeof(tmp));

    OP_ASSERT_EQUAL_ULONG(sizeof(tmp), buffer.Size);
    OP_ASSERT_EQUAL_ULONG(2UL, buffer.Data->Length);
}

static void
buffer_add_when_called_twice_adds_both()
{
    setup_buffer();

    Malloc_ExpectAndReturn(BUFFER_CHUNK_SIZE, &FirstChunk, cmp_int);
    Malloc_ExpectAndReturn(sizeof(ListEntry), &ListEntry1, cmp_int);

    buffer_add(&buffer, "Test", strlen("Test"));
    buffer_add(&buffer, "Second", strlen("Second"));

    OP_ASSERT_EQUAL_CSTRING("TestSecond", (char *)buffer.Data->Head->Data);
    OP_ASSERT_EQUAL_ULONG(10UL, buffer.Size);
}

static void
buffer_remove_when_null_buffer_returns()
{
    buffer_remove(NULL, 0);

    OP_VERIFY();
}

static void
buffer_remove_when_zero_len_returns()
{
    setup_buffer();

    Malloc_ExpectAndReturn(BUFFER_CHUNK_SIZE, &FirstChunk, cmp_int);
    Malloc_ExpectAndReturn(sizeof(ListEntry), &ListEntry1, cmp_int);

    buffer_add(&buffer, "Test", strlen("Test"));

    buffer_remove(&buffer, 0);

    OP_VERIFY();
}

static void
buffer_remove_when_called_shrinks_buffer()
{
    char tmp[16] = { 0 };

    setup_buffer();

    Malloc_ExpectAndReturn(BUFFER_CHUNK_SIZE, &FirstChunk, cmp_int);
    Malloc_ExpectAndReturn(sizeof(ListEntry), &ListEntry1, cmp_int);

    buffer_add(&buffer, "Test", strlen("Test"));

    buffer_remove(&buffer, 2);

    strncpy(tmp, buffer.Data->Head->Data, 2);

    OP_ASSERT_EQUAL_CSTRING("st", tmp);
    OP_ASSERT_EQUAL_ULONG(2UL, buffer.Size);
}

static void
buffer_remove_when_too_long_returns()
{
    setup_buffer();

    Malloc_ExpectAndReturn(BUFFER_CHUNK_SIZE, &FirstChunk, cmp_int);
    Malloc_ExpectAndReturn(sizeof(ListEntry), &ListEntry1, cmp_int);

    buffer_add(&buffer, "Test", strlen("Test"));

    buffer_remove(&buffer, 9999);

    OP_VERIFY();
}

static void
buffer_remove_when_called_twice_moves_buffer()
{
    char tmp[16] = { 0 };

    setup_buffer();

    Malloc_ExpectAndReturn(BUFFER_CHUNK_SIZE, &FirstChunk, cmp_int);
    Malloc_ExpectAndReturn(sizeof(ListEntry), &ListEntry1, cmp_int);

    buffer_add(&buffer, "Testing", strlen("Testing"));

    buffer_remove(&buffer, 2);
    buffer_remove(&buffer, 2);

    strncpy(tmp, buffer.Data->Head->Data, 2);

    OP_ASSERT_EQUAL_CSTRING("in", tmp);
}

static void
buffer_remove_when_overflows_saves_buffer()
{
    char tmp[16] = { 0 };
    char data[BUFFER_CHUNK_SIZE];

    memset(data, '0', sizeof(tmp));

    setup_buffer();

    Malloc_ExpectAndReturn(BUFFER_CHUNK_SIZE, &FirstChunk, cmp_int);
    Malloc_ExpectAndReturn(sizeof(ListEntry), &ListEntry1, cmp_int);
    Malloc_ExpectAndReturn(BUFFER_CHUNK_SIZE, &SecondChunk, cmp_int);
    Malloc_ExpectAndReturn(sizeof(ListEntry), &ListEntry2, cmp_int);

    buffer_add(&buffer, data, sizeof(data));

    buffer_remove(&buffer, sizeof(data));

    buffer_add(&buffer, "Test", 4);
    buffer_remove(&buffer, 2);

    strncpy(tmp, buffer.Data->Head->Data, 2);

    OP_ASSERT_EQUAL_CSTRING("st", tmp);
}

static void
buffer_remove_when_more_than_chunk_size_moves_chunk()
{
    char tmp[16] = { 0 };
    char data[BUFFER_CHUNK_SIZE];
    char data2[BUFFER_CHUNK_SIZE];

    memset(data, '0', sizeof(data));
    memset(data2, '1', sizeof(data2));

    setup_buffer();

    Malloc_ExpectAndReturn(BUFFER_CHUNK_SIZE, &FirstChunk, cmp_int);
    Malloc_ExpectAndReturn(sizeof(ListEntry), &ListEntry1, cmp_int);
    Malloc_ExpectAndReturn(BUFFER_CHUNK_SIZE, &SecondChunk, cmp_int);
    Malloc_ExpectAndReturn(sizeof(ListEntry), &ListEntry2, cmp_int);
    Malloc_ExpectAndReturn(BUFFER_CHUNK_SIZE, &ThirdChunk, cmp_int);
    Malloc_ExpectAndReturn(sizeof(ListEntry), &ListEntry3, cmp_int);

    buffer_add(&buffer, data, sizeof(data));
    buffer_add(&buffer, data2, sizeof(data2));

    buffer_remove(&buffer, sizeof(data));

    buffer_add(&buffer, "Test", 4);
    buffer_remove(&buffer, 2);

    strncpy(tmp, buffer.Data->Head->Data, 2);

    OP_ASSERT_EQUAL_CSTRING("11", tmp);
}

int
main()
{
    opmock_test_suite_reset();

    opmock_register_test(buffer_add_when_null_buffer_works_ok,
                         "buffer_add_when_null_buffer_works_ok");
    opmock_register_test(buffer_add_when_null_data_works_ok,
                         "buffer_add_when_null_data_works_ok");
    opmock_register_test(buffer_add_when_called_stores_data,
                         "buffer_add_when_called_stores_data");
    opmock_register_test(buffer_add_when_called_exceeding_capacity_increases_capacity,
                         "buffer_add_when_called_exceeding_capacity_increases_capacity");
    opmock_register_test(buffer_add_when_called_twice_adds_both,
                         "buffer_add_when_called_twice_adds_both");
    opmock_register_test(buffer_remove_when_null_buffer_returns,
                         "buffer_remove_when_null_buffer_returns");
    opmock_register_test(buffer_remove_when_zero_len_returns,
                         "buffer_remove_when_zero_len_returns");
    opmock_register_test(buffer_remove_when_called_shrinks_buffer,
                         "buffer_remove_when_called_shrinks_buffer");
    opmock_register_test(buffer_remove_when_too_long_returns,
                         "buffer_remove_when_too_long_returns");
    opmock_register_test(buffer_remove_when_called_twice_moves_buffer,
                         "buffer_remove_when_called_twice_moves_buffer");
    opmock_register_test(buffer_remove_when_overflows_saves_buffer,
                         "buffer_remove_when_overflows_wraps");
    opmock_register_test(buffer_remove_when_more_than_chunk_size_moves_chunk,
                         "buffer_remove_when_more_than_chunk_size_moves_chunk");

    opmock_test_suite_run();

    return opmock_test_error > 0;
}
