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

static char HashDataPtr[65535 * sizeof(HashItem *)];
static Hash HashPtr;
static char HashKey[64];
static HashItem Item;
static HashItem Item2;
static HashItem *ItemPtr;
static uint32_t HashValue;

static int
hash_callback(void *left, void *right, const char *message, char *buffer)
{
    if(strcmp(HashKey, "TEST") == 0)
    {
        HashValue = 0x1234;
    }
    else if(strcmp(HashKey, "SAME") == 0)
    {
        HashValue = 0x1234;
    }
    else if(strcmp(HashKey, "FOO") == 0)
    {
        HashValue = 0x4321;
    }
    else
    {
        HashValue = 0x9999;
    }

    **(int **)right = HashValue;

    return 0;
}

static void
setup_hash()
{
    memset(HashDataPtr, 0, sizeof(HashDataPtr));
    memset(&HashPtr, 0, sizeof(HashPtr));
    memset(HashKey, 0, sizeof(HashKey));

    Malloc_ExpectAndReturn(0, &HashPtr, NULL);
    Malloc_ExpectAndReturn(0, &HashDataPtr, NULL);
}

static void
setup_item()
{
    memset(HashKey, 0, sizeof(HashKey));
    memset(ItemPtr, 0, sizeof(HashItem));

    StrDup_ExpectAndReturn(NULL, HashKey, NULL);

    MurmurHash3_x86_32_ExpectAndReturn(HashKey, 0, HASHSEED, NULL,
                                       cmp_cstr, NULL, cmp_int, hash_callback);

    Free_ExpectAndReturn(HashKey, cmp_ptr);

    Malloc_ExpectAndReturn(0, ItemPtr, NULL);
}

static void
setup_find()
{
    StrDup_ExpectAndReturn(NULL, HashKey, NULL);

    MurmurHash3_x86_32_ExpectAndReturn(HashKey, 0, HASHSEED, NULL,
                                       cmp_cstr, NULL, cmp_int, hash_callback);

    Free_ExpectAndReturn(NULL, NULL);
}

static void
hash_new_when_called_with_name_and_len_returns_hash()
{
    Hash *h;

    setup_hash();

    h = hash_new("Test hash", DEFAULT_HASH_SIZE);

    OP_ASSERT_TRUE(h != NULL);
    OP_ASSERT_TRUE(h->Name != NULL);
    OP_ASSERT_EQUAL_CSTRING("Test hash", h->Name);
    OP_ASSERT_TRUE(h->Buckets != NULL);
}

static void
hash_new_when_called_with_null_name_and_len_returns_hash()
{
    Hash *h;

    setup_hash();

    h = hash_new(NULL, 20);

    OP_ASSERT_TRUE(h != NULL);
    OP_ASSERT_EQUAL_LONG((size_t)20, h->Length);
}

static void
hash_new_when_called_with_zero_len_returns_hash_with_default_length()
{
    Hash *h;

    setup_hash();

    h = hash_new("Test", 0);

    OP_ASSERT_TRUE(h != NULL);
    OP_ASSERT_EQUAL_LONG((size_t)DEFAULT_HASH_SIZE, h->Length);
}

static void
hash_add_string_when_this_is_null_returns_ok()
{
    hash_add_string(NULL, "Test", &Item);

    OP_VERIFY();
}

static void
hash_add_string_when_called_puts_value_in_hash()
{
    Hash *h;

    setup_hash();

    ItemPtr = &Item;
    setup_item();

    h = hash_new("Test", DEFAULT_HASH_SIZE);

    hash_add_string(h, "Test", &Item);

    OP_ASSERT_TRUE(h->Buckets[HashValue % h->Length] != NULL);
    OP_ASSERT_TRUE(h->Buckets[HashValue % h->Length]->Data == &Item);
}

static void
hash_add_string_when_called_twice_puts_value_in_hash_bucket()
{
    Hash *h;

    setup_hash();

    ItemPtr = &Item;
    setup_item();

    ItemPtr = &Item2;
    setup_item();

    h = hash_new("Test", DEFAULT_HASH_SIZE);

    hash_add_string(h, "Test", &Item);
    hash_add_string(h, "Test", &Item2);

    OP_ASSERT_TRUE(h->Buckets[HashValue] != NULL);
    OP_ASSERT_TRUE(h->Buckets[HashValue]->Data == &Item2);
    OP_ASSERT_TRUE(h->Buckets[HashValue]->Next != NULL);
    OP_ASSERT_TRUE(h->Buckets[HashValue]->Next->Data == &Item);
}


static void
hash_find_when_called_with_null_this_returns_null()
{
    HashItem *item = hash_find(NULL, "TEST");

    OP_ASSERT_TRUE(item == NULL);
}

static void
hash_find_when_called_with_item_in_hash_returns_item()
{
    Hash *h;
    HashItem *ret;

    setup_hash();

    ItemPtr = &Item;
    setup_item();

    setup_find();

    h = hash_new("Test", DEFAULT_HASH_SIZE);

    hash_add_string(h, "Test", &Item);

    memset(HashKey, 0, sizeof(HashKey));

    ret = hash_find(h, "Test");

    OP_ASSERT_TRUE(ret != NULL);
    OP_ASSERT_TRUE(ret == &Item);
}

static void
hash_find_when_called_with_item_not_in_hash_returns_null()
{
    Hash *h;
    HashItem *ret;

    setup_hash();

    ItemPtr = &Item;
    setup_item();

    setup_find();

    h = hash_new("Test", DEFAULT_HASH_SIZE);

    hash_add_string(h, "Test", &Item);

    memset(HashKey, 0, sizeof(HashKey));

    ret = hash_find(h, "foo");

    OP_ASSERT_TRUE(ret == NULL);
}

static void
hash_find_when_different_case_returns_item()
{
    Hash *h;
    HashItem *ret;

    setup_hash();

    ItemPtr = &Item;
    setup_item();

    setup_find();

    h = hash_new("Test", DEFAULT_HASH_SIZE);

    hash_add_string(h, "Test", &Item);

    memset(HashKey, 0, sizeof(HashKey));

    ret = hash_find(h, "TeST");

    OP_ASSERT_TRUE(ret != NULL);
    OP_ASSERT_TRUE(ret == &Item);
}

static void
hash_find_when_in_bucket_returns_item()
{
    Hash *h;
    HashItem *ret;

    setup_hash();

    ItemPtr = &Item;
    setup_item();

    ItemPtr = &Item2;
    setup_item();

    setup_find();
    setup_find();

    h = hash_new("Test", DEFAULT_HASH_SIZE);

    hash_add_string(h, "Test", &Item);
    hash_add_string(h, "Same", &Item2);

    memset(HashKey, 0, sizeof(HashKey));

    ret = hash_find(h, "same");

    OP_ASSERT_TRUE(ret == &Item2);

    ret = hash_find(h, "test");
    OP_ASSERT_TRUE(ret == &Item);
}

static void
hash_Find_when_same_bucket_not_in_hash_returns_null()
{
    Hash *h;
    HashItem *ret;

    setup_hash();

    ItemPtr = &Item;
    setup_item();

    setup_find();
    setup_find();

    h = hash_new("Test", DEFAULT_HASH_SIZE);

    hash_add_string(h, "Test", &Item);

    memset(HashKey, 0, sizeof(HashKey));

    ret = hash_find(h, "same");
    OP_ASSERT_TRUE(ret == NULL);
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
    opmock_register_test(hash_find_when_different_case_returns_item,
                         "hash_find_when_different_case_returns_item");
    opmock_register_test(hash_find_when_in_bucket_returns_item,
                         "hash_find_when_in_bucket_returns_item");
    opmock_register_test(hash_Find_when_same_bucket_not_in_hash_returns_null,
                         "hash_Find_when_same_bucket_not_in_hash_returns_null");

    opmock_test_suite_run();

    return opmock_test_error > 0;
}
