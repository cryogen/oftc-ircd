/*
 * Copyright (c) 2014, Stuart Walsh
 * All rights reserved.
 * vector_tests.c unit tests for vectors
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

#include "vector.h"

static void
setup()
{
}

static void
cleanup()
{
}

START_TEST(vector_new_WhenCalledWithZeroElementSizeReturnsNull)
{
    Vector *vector;

    vector = vector_new(0, 0);

    ck_assert(vector == NULL);
}
END_TEST

START_TEST(vector_new_WhenCalledWithZeroCapacitySetsDefaultCapacity)
{
    Vector *vector;

    vector = vector_new(0, 4);

    ck_assert(vector != NULL);
    ck_assert_int_eq(vector->Capacity, DEFAULT_VECTOR_CAPACITY);
}
END_TEST

START_TEST(vector_new_WhenCalledSetsCapactityAndElementSize)
{
    Vector *vector;

    vector = vector_new(100, 4);

    ck_assert(vector != NULL);
    ck_assert_int_eq(vector->Capacity, 100);
    ck_assert_int_eq(vector->ElementSize, 4);
}
END_TEST

START_TEST(vector_push_back_WhenCalledWithNullThisReturnsOk)
{
    vector_push_back(NULL, NULL);
}
END_TEST

START_TEST(vector_push_back_WhenCalledWithNullValueReturnsOk)
{
    Vector *vector;

    vector = vector_new(100, 4);

    vector_push_back(vector, NULL);
}
END_TEST

START_TEST(vector_push_back_WhenCalledSetsLength)
{
    Vector *vector;

    vector = vector_new(100, 4);

    vector_push_back(vector, "TEST");

    ck_assert_int_eq(vector->Length, 1);
}
END_TEST

START_TEST(vector_push_back_WhenCalledDoesNotIncreaseCapacity)
{
    Vector *vector;

    vector = vector_new(100, 4);

    vector_push_back(vector, "TEST");

    ck_assert_int_eq(vector->Capacity, 100);
}
END_TEST

START_TEST(vector_push_back_WhenCalledPutsValueInData)
{
    Vector *vector;

    vector = vector_new(100, 4);

    vector_push_back(vector, "TEST");

    ck_assert_str_eq(vector->Data, "TEST");
}
END_TEST

START_TEST(vector_push_back_WhenCalledTwicePutsValueInDataAndSetsLength)
{
    Vector *vector;

    vector = vector_new(100, 4);

    vector_push_back(vector, "TEST");
    vector_push_back(vector, "1TES");

    ck_assert(memcmp(vector->Data, "TEST", 4) == 0);
    ck_assert(memcmp(vector->Data + 4, "1TES", 4) == 0);
    ck_assert_int_eq(vector->Length, 2);
    ck_assert_int_eq(vector->Capacity, 100);
}
END_TEST

START_TEST(vector_push_back_WhenAboveCapacityExtendsVector)
{
    Vector *vector;

    vector = vector_new(1, 4);

    vector_push_back(vector, "TEST");

    ck_assert_int_eq(vector->Capacity, 1);

    vector_push_back(vector, "1TES");

    ck_assert(memcmp(vector->Data, "TEST", 4) == 0);
    ck_assert(memcmp(vector->Data + 4, "1TES", 4) == 0);
    ck_assert_int_eq(vector->Length, 2);
    ck_assert_int_eq(vector->Capacity, 2);
}
END_TEST

START_TEST(vector_length_WhenCalledWithNullThisReturnsZero)
{
    ck_assert_int_eq(vector_length(NULL), 0);
}
END_TEST

START_TEST(vector_length_WhenCalledReturnsCorrectLength)
{
    Vector *vector;

    vector = vector_new(0, 4);

    vector_push_back(vector, "TEST");

    ck_assert_int_eq(vector_length(vector), 1);
    ck_assert_int_eq(vector_length(vector), vector->Length);

    vector_push_back(vector, "1TES");

    ck_assert_int_eq(vector_length(vector), 2);
    ck_assert_int_eq(vector_length(vector), vector->Length);
}
END_TEST

START_TEST(vector_get_WhenCalledWithNullThisReturnsNull)
{
    ck_assert(vector_get(NULL, 0) == NULL);
}
END_TEST

START_TEST(vector_get_WhenCalledReturnsCorrectValue)
{
    Vector *vector;

    vector = vector_new(0, 4);

    vector_push_back(vector, "TEST");
    vector_push_back(vector, "1TES");

    ck_assert(memcmp(vector_get(vector, 0), "TEST", 4) == 0);
    ck_assert_str_eq(vector_get(vector, 1), "1TES");
}
END_TEST

START_TEST(vector_get_WhenCalledWithOutOfRangeIndexReturnsNull)
{
    Vector *vector;

    vector = vector_new(0, 4);

    vector_push_back(vector, "TEST");
    vector_push_back(vector, "1TES");

    ck_assert(vector_get(vector, 2) == NULL);
    ck_assert_str_eq(vector_get(vector, 1), "1TES");
}
END_TEST

Suite *
vector_suite()
{
    Suite *s;
    TCase *tcCore;

    s = suite_create("vector");

    tcCore = tcase_create("Core");

    tcase_add_unchecked_fixture(tcCore, setup, cleanup);

    tcase_add_test(tcCore, vector_new_WhenCalledWithZeroElementSizeReturnsNull);
    tcase_add_test(tcCore, vector_new_WhenCalledWithZeroCapacitySetsDefaultCapacity);
    tcase_add_test(tcCore, vector_new_WhenCalledSetsCapactityAndElementSize);
    tcase_add_test(tcCore, vector_push_back_WhenCalledWithNullThisReturnsOk);
    tcase_add_test(tcCore, vector_push_back_WhenCalledWithNullValueReturnsOk);
    tcase_add_test(tcCore, vector_push_back_WhenCalledSetsLength);
    tcase_add_test(tcCore, vector_push_back_WhenCalledDoesNotIncreaseCapacity);
    tcase_add_test(tcCore, vector_push_back_WhenCalledPutsValueInData);
    tcase_add_test(tcCore, vector_push_back_WhenCalledTwicePutsValueInDataAndSetsLength);
    tcase_add_test(tcCore, vector_push_back_WhenAboveCapacityExtendsVector);
    tcase_add_test(tcCore, vector_length_WhenCalledWithNullThisReturnsZero);
    tcase_add_test(tcCore, vector_length_WhenCalledReturnsCorrectLength);
    tcase_add_test(tcCore, vector_get_WhenCalledWithNullThisReturnsNull);
    tcase_add_test(tcCore, vector_get_WhenCalledReturnsCorrectValue);
    tcase_add_test(tcCore, vector_get_WhenCalledWithOutOfRangeIndexReturnsNull);

    suite_add_tcase(s, tcCore);
    
    return s;
}