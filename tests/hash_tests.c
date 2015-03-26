/*
 * Copyright (c) 2014, Stuart Walsh
 * All rights reserved.
 * hash_tests.c unit tests for hashing
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
#include "hash.h"
#include "murmurhash3_stub.h"
#include "memory_stub.h"

void
hash_new_when_called_with_name_and_len_returns_hash()
{
    Hash hash = { 0 };
    Hash *h;
    char ptr[512];

    hash_init();

    Malloc_ExpectAndReturn(0, &hash, NULL);
    Malloc_ExpectAndReturn(0, &ptr, NULL);

    h = hash_new("Test hash", DEFAULT_HASH_SIZE);

    OP_ASSERT_TRUE(h != NULL);
    OP_ASSERT_TRUE(h->Name != NULL);
    OP_ASSERT_EQUAL_CSTRING("Test hash", h->Name);
    OP_ASSERT_TRUE(h->Buckets != NULL);

    OP_VERIFY();
}

void
hash_new_when_called_with_null_name_and_len_returns_hash()
{
    Hash hash = { 0 };
    Hash *h;
    char ptr[512];

    Malloc_ExpectAndReturn(0, &hash, NULL);
    Malloc_ExpectAndReturn(0, &ptr, NULL);

    h = hash_new(NULL, 20);

    OP_ASSERT_TRUE(h != NULL);
    OP_ASSERT_EQUAL_LONG((size_t)20, h->Length);

    OP_VERIFY();
}


void
hash_new_when_called_with_zero_len_returns_hash_with_default_length()
{
    Hash hash = { 0 };
    Hash *h;
    char ptr[512];

    Malloc_ExpectAndReturn(0, &hash, NULL);
    Malloc_ExpectAndReturn(0, &ptr, NULL);

    h = hash_new("Test", 0);

    OP_ASSERT_TRUE(h != NULL);
    OP_ASSERT_EQUAL_LONG((size_t)DEFAULT_HASH_SIZE, h->Length);

    OP_VERIFY();
}

void
hash_add_string_when_this_is_null_returns_ok()
{
    HashItem item;

    hash_add_string(NULL, "Test", &item);

    OP_VERIFY();
}

void hash_callback(const void *key, int len, uint32_t seed, void *out, int calls)
{
    if(strcmp(key, "foo") == 0)
    {
        *((int*)out) = 1234;
    }
    else
    {
        *((int*)out) = 123;
    }
}

void
hash_add_string_when_called_puts_value_in_hash()
{
    Hash hash = { 0 };
    Hash *h;
    HashItem item = { 0 };
    char ptr[512] = { 0 };
    uint32_t hashVal = 123;

    Malloc_ExpectAndReturn(0, &hash, NULL);
    Malloc_ExpectAndReturn(0, &ptr, NULL);
    MurmurHash3_x86_32_MockWithCallback(hash_callback);
    Malloc_ExpectAndReturn(0, &item, NULL);

    h = hash_new("Test", DEFAULT_HASH_SIZE);

    hash_add_string(h, "Test", &item);

    OP_ASSERT_TRUE(h->Buckets[hashVal % h->Length] != NULL);
    OP_ASSERT_TRUE(h->Buckets[hashVal % h->Length]->Data == &item);

    OP_VERIFY();
}

void
hash_add_string_when_called_twice_puts_value_in_hash_bucket()
{
    Hash hash = { 0 };
    Hash *h;
    HashItem item = { 0 };
    HashItem item2 = { 0 };
    char ptr[512] = { 0 };
    uint32_t hashVal = 123;

    Malloc_ExpectAndReturn(0, &hash, NULL);
    Malloc_ExpectAndReturn(0, &ptr, NULL);
    MurmurHash3_x86_32_MockWithCallback(hash_callback);
    Malloc_ExpectAndReturn(0, &item, NULL);
    MurmurHash3_x86_32_MockWithCallback(hash_callback);
    Malloc_ExpectAndReturn(0, &item2, NULL);

    h = hash_new("Test", DEFAULT_HASH_SIZE);

    hash_add_string(h, "Test", &item);
    hash_add_string(h, "Test", &item2);

    OP_ASSERT_TRUE(h->Buckets[hashVal] != NULL);
    OP_ASSERT_TRUE(h->Buckets[hashVal]->Data == &item2);
    OP_ASSERT_TRUE(h->Buckets[hashVal]->Next != NULL);
    OP_ASSERT_TRUE(h->Buckets[hashVal]->Next->Data == &item);

    OP_VERIFY();
}


void
hash_find_when_called_with_null_this_returns_null()
{
    HashItem *item = hash_find(NULL, "TEST");

    OP_ASSERT_TRUE(item == NULL);

    OP_VERIFY();
}

void
hash_find_when_called_with_item_in_hash_returns_item()
{
    Hash hash = { 0 };
    Hash *h;
    HashItem item = { 0 };
    HashItem *ret;
    char ptr[512] = { 0 };
    uint32_t hashVal = 123;

    Malloc_ExpectAndReturn(0, &hash, NULL);
    Malloc_ExpectAndReturn(0, &ptr, NULL);
    MurmurHash3_x86_32_MockWithCallback(hash_callback);
    Malloc_ExpectAndReturn(0, &item, NULL);

    h = hash_new("Test", DEFAULT_HASH_SIZE);

    hash_add_string(h, "Test", &item);

    ret = hash_find(h, "Test");

    OP_ASSERT_TRUE(ret != NULL);
    OP_ASSERT_TRUE(ret == &item);

    OP_VERIFY();
}

void
hash_find_when_called_with_item_not_in_hash_returns_null()
{
    Hash hash = { 0 };
    Hash *h;
    HashItem item = { 0 };
    HashItem *ret;
    char ptr[524280] = { 0 }; // 65535 * sizeof(HashItem *)
    uint32_t hashVal = 123;

    Malloc_ExpectAndReturn(0, &hash, NULL);
    Malloc_ExpectAndReturn(0, &ptr, NULL);
    MurmurHash3_x86_32_MockWithCallback(hash_callback);
    Malloc_ExpectAndReturn(0, &item, NULL);

    h = hash_new("Test", DEFAULT_HASH_SIZE);

    hash_add_string(h, "Test", &item);

    ret = hash_find(h, "foo");

    OP_ASSERT_TRUE(ret == NULL);
    OP_VERIFY();
}

int
main()
{
    opmock_test_suite_reset();

    opmock_register_test(hash_new_when_called_with_name_and_len_returns_hash,
                         "hash_new_when_called_with_name_and_len_returns_hash");
    opmock_register_test(hash_new_when_called_with_null_name_and_len_returns_hash,
                         "hash_new_when_called_with_null_name_and_len_returns_hash");
    opmock_register_test(hash_new_when_called_with_zero_len_returns_hash_with_default_length,
                         "hash_new_when_called_with_zero_len_returns_hash_with_default_length");
    opmock_register_test(hash_add_string_when_this_is_null_returns_ok,
                         "hash_add_string_when_this_is_null_returns_ok");
    opmock_register_test(hash_add_string_when_called_puts_value_in_hash,
                         "hash_add_string_when_called_puts_value_in_hash");
    opmock_register_test(hash_add_string_when_called_twice_puts_value_in_hash_bucket,
                         "hash_add_string_when_called_twice_puts_value_in_hash_bucket");
    opmock_register_test(hash_find_when_called_with_null_this_returns_null,
                         "hash_find_when_called_with_null_this_returns_null");
    opmock_register_test(hash_find_when_called_with_item_in_hash_returns_item,
                         "hash_find_when_called_with_item_in_hash_returns_item");
    opmock_register_test(hash_find_when_called_with_item_not_in_hash_returns_null,
                         "hash_find_when_called_with_item_not_in_hash_returns_null");

    opmock_test_suite_run();

    return opmock_test_error > 0;
}
