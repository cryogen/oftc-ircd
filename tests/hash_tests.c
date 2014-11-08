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

#include <check.h>
#include <stdlib.h>

#include "hash.h"
#include "murmurhash3.h"

static uint32_t
get_hash_value(Hash *hash, const char *key)
{
    uint32_t hashVal;

    MurmurHash3_x86_32(key, strlen(key), HASHSEED, &hashVal);

    return hashVal % hash->Length;
}

static void
setup()
{
    hash_init();
}

static void
cleanup()
{
}

START_TEST(hash_new_WhenCalledWithNameAndLenReturnsHash)
{
    Hash *h = hash_new("Test hash", DEFAULT_HASH_SIZE);

    ck_assert(h != NULL);
    ck_assert(h->Name != NULL);
    ck_assert_str_eq(h->Name, "Test hash");
    ck_assert(h->Buckets != NULL);
}
END_TEST

START_TEST(hash_new_WhenCalledWithNullNameAndLenReturnsHash)
{
    Hash *h = hash_new(NULL, 20);

    ck_assert(h != NULL);
    ck_assert_int_eq(h->Length, 20);
}
END_TEST

START_TEST(hash_new_WhenCalledWithZeroLenReturnsHashWithDefaultLength)
{
    Hash *h = hash_new("Test", 0);

    ck_assert(h != NULL);
    ck_assert_int_eq(h->Length, DEFAULT_HASH_SIZE);
}
END_TEST

START_TEST(hash_add_string_WhenThisIsNullReturnsOk)
{
    HashItem *item = malloc(sizeof(HashItem));

    hash_add_string(NULL, "Test", item);
}
END_TEST

START_TEST(hash_add_string_WhenCalledPutsValueInHash)
{
    HashItem *item = malloc(sizeof(HashItem));
    Hash *h = hash_new("Test", DEFAULT_HASH_SIZE);
    uint32_t hashKey = get_hash_value(h, "Test");

    hash_add_string(h, "Test", item);

    ck_assert(h->Buckets[hashKey] != NULL);
    ck_assert(h->Buckets[hashKey]->Data == item);
}
END_TEST

START_TEST(hash_add_string_WhenCalledTwicePutsValueInHashBucket)
{
    HashItem *item = malloc(sizeof(HashItem));
    HashItem *item2 = malloc(sizeof(HashItem));
    Hash *h = hash_new("Test", DEFAULT_HASH_SIZE);
    uint32_t hashKey = get_hash_value(h, "Test");

    hash_add_string(h, "Test", item);
    hash_add_string(h, "Test", item2);

    ck_assert(h->Buckets[hashKey] != NULL);
    ck_assert(h->Buckets[hashKey]->Data == item2);
    ck_assert(h->Buckets[hashKey]->Next != NULL);
    ck_assert(h->Buckets[hashKey]->Next->Data == item);
}
END_TEST

START_TEST(hash_find_WhenCalledWithNullThisReturnsNull)
{
    HashItem *item = hash_find(NULL, "TEST");

    ck_assert(item == NULL);
}
END_TEST

START_TEST(hash_find_WhenCalledWithItemInHashReturnsItem)
{
    HashItem *item = malloc(sizeof(HashItem));
    HashItem *item2 = malloc(sizeof(HashItem));
    HashItem *ret;
    Hash *h = hash_new("Test", DEFAULT_HASH_SIZE);

    hash_add_string(h, "Test", item);
    hash_add_string(h, "Test2", item2);

    ret = hash_find(h, "Test");

    ck_assert(ret != NULL);
    ck_assert(ret == item);
}
END_TEST

START_TEST(hash_find_WhenCalledWithItemNotInHashReturnsNull)
{
    HashItem *item = malloc(sizeof(HashItem));
    HashItem *item2 = malloc(sizeof(HashItem));
    HashItem *ret;
    Hash *h = hash_new("Test", DEFAULT_HASH_SIZE);

    hash_add_string(h, "Test", item);
    hash_add_string(h, "Test2", item2);

    ret = hash_find(h, "foo");

    ck_assert(ret == NULL);
}
END_TEST

Suite *
hash_suite()
{
    Suite *s;
    TCase *tcCore;

    s = suite_create("Hash");

    tcCore = tcase_create("Core");

    tcase_add_unchecked_fixture(tcCore, setup, cleanup);

    tcase_add_test(tcCore, hash_new_WhenCalledWithNameAndLenReturnsHash);
    tcase_add_test(tcCore, hash_new_WhenCalledWithNullNameAndLenReturnsHash);
    tcase_add_test(tcCore, hash_new_WhenCalledWithZeroLenReturnsHashWithDefaultLength);
    tcase_add_test(tcCore, hash_add_string_WhenThisIsNullReturnsOk);
    tcase_add_test(tcCore, hash_add_string_WhenCalledPutsValueInHash);
    tcase_add_test(tcCore, hash_add_string_WhenCalledTwicePutsValueInHashBucket);
    tcase_add_test(tcCore, hash_find_WhenCalledWithNullThisReturnsNull);
    tcase_add_test(tcCore, hash_find_WhenCalledWithItemInHashReturnsItem);
    tcase_add_test(tcCore, hash_find_WhenCalledWithItemNotInHashReturnsNull);

    suite_add_tcase(s, tcCore);

    return s;
}
