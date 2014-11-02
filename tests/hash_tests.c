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

#include "hash.h"
#include "murmurhash3.h"

static unsigned int
get_hash_value(const char *key)
{
    unsigned int hashVal;

    MurmurHash3_x86_32(key, strlen(key), HASHSEED, &hashVal);

    return hashVal;
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
    Hash *h = hash_new("Test hash", HASHLEN);

    ck_assert(h != NULL);
    ck_assert(h->Name != NULL);
    ck_assert_str_eq(h->Name, "Test hash");
}
END_TEST

START_TEST(hash_new_WhenCalledWithNullNameAndLenReturnsHash)
{
    Hash *h = hash_new(NULL, HASHLEN);

    ck_assert(h != NULL);
}
END_TEST

START_TEST(hash_new_WhenCalledWithZeroLenReturnsNull)
{
    Hash *h = hash_new("Fail", 0);

    ck_assert(h == NULL);
}
END_TEST

START_TEST(hash_add_string_WhenCalledPutsValueInHash)
{
    HashItem *item = malloc(sizeof(HashItem));
    Hash *h = hash_new("Test", HASHLEN);
    unsigned int hashKey = get_hash_value("Test");

    hash_add_string(h, "Test", item);

    ck_assert(h->Buckets[hashKey] != NULL);
    ck_assert(h->Buckets[hashKey] == item);
}
END_TEST

START_TEST(hash_add_string_WhenCalledTwicePutsValueInHashBucket)
{
    HashItem *item = malloc(sizeof(HashItem));
    HashItem *item2 = malloc(sizeof(HashItem));
    Hash *h = hash_new("Test", HASHLEN);
    unsigned int hashKey = get_hash_value("Test");

    hash_add_string(h, "Test", item);
    hash_add_string(h, "Test", item2);

    ck_assert(h->Buckets[hashKey] != NULL);
    ck_assert(h->Buckets[hashKey] == item2);
    ck_assert(h->Buckets[hashKey]->Next != NULL);
    ck_assert(h->Buckets[hashKey]->Next == item);
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
    tcase_add_test(tcCore, hash_new_WhenCalledWithZeroLenReturnsNull);
    tcase_add_test(tcCore, hash_add_string_WhenCalledPutsValueInHash);
    tcase_add_test(tcCore, hash_add_string_WhenCalledTwicePutsValueInHashBucket);

    suite_add_tcase(s, tcCore);

    return s;
}