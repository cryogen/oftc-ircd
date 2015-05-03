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

#include "opmock.h"

#include "vector.h"
#include "memory_stub.h"

static void
vector_new_when_called_with_zero_element_size_returns_null()
{
    Vector *vector;

    vector = vector_new(0, 0);

    OP_ASSERT_TRUE(vector == NULL);
    OP_VERIFY();
}

static void
vector_new_when_called_with_zero_capacity_sets_default_capacity()
{
    Vector *vector;
    Vector retVector = { 0 };
    char data[4096];

    Malloc_ExpectAndReturn(0, &retVector, NULL);
    Malloc_ExpectAndReturn(0, data, NULL);

    vector = vector_new(0, 4);

    OP_ASSERT_TRUE(vector != NULL);
    OP_ASSERT_EQUAL_INT(DEFAULT_VECTOR_CAPACITY, (int)vector->Capacity);
    OP_VERIFY();
}

static void
vector_new_when_called_sets_capactity_and_element_size()
{
    Vector *vector;
    Vector retVector = { 0 };
    char data[4096];

    Malloc_ExpectAndReturn(0, &retVector, NULL);
    Malloc_ExpectAndReturn(0, data, NULL);

    vector = vector_new(100, 4);

    OP_ASSERT_TRUE(vector != NULL);
    OP_ASSERT_EQUAL_INT(100, (int)vector->Capacity);
    OP_ASSERT_EQUAL_INT(4, (int)vector->ElementSize);
    OP_VERIFY();
}

static void
vector_push_back_when_called_with_null_this_returns_null()
{
    void  *ret = vector_push_back(NULL, NULL);

    OP_ASSERT_TRUE(ret == NULL);
    OP_VERIFY();
}

static void
vector_push_back_when_called_with_null_value_returns_null()
{
    Vector *vector;
    void *ptr;
    Vector retVector = { 0 };
    char data[4096];

    Malloc_ExpectAndReturn(0, &retVector, NULL);
    Malloc_ExpectAndReturn(0, data, NULL);

    vector = vector_new(100, 4);

    ptr = vector_push_back(vector, NULL);

    OP_ASSERT_TRUE(ptr == NULL);
    OP_VERIFY();
}

static void
vector_push_back_when_called_sets_length()
{
    Vector *vector;
    Vector retVector = { 0 };
    char data[4096];

    Malloc_ExpectAndReturn(0, &retVector, NULL);
    Malloc_ExpectAndReturn(0, data, NULL);

    vector = vector_new(100, 4);

    vector_push_back(vector, "TEST");

    OP_ASSERT_EQUAL_INT(1, (int)vector->Length);
    OP_VERIFY();
}

static void
vector_push_back_when_called_does_not_increase_capacity()
{
    Vector *vector;
    Vector retVector = { 0 };
    char data[4096];

    Malloc_ExpectAndReturn(0, &retVector, NULL);
    Malloc_ExpectAndReturn(0, data, NULL);

    vector = vector_new(100, 4);

    vector_push_back(vector, "TEST");

    OP_ASSERT_EQUAL_INT(100, (int)vector->Capacity);
    OP_VERIFY();
}

static void
vector_push_back_when_called_puts_value_in_data()
{
    Vector *vector;
    void *ret;
    Vector retVector = { 0 };
    char data[4096] = { 0 };

    Malloc_ExpectAndReturn(0, &retVector, NULL);
    Malloc_ExpectAndReturn(0, data, NULL);

    vector = vector_new(100, 4);

    ret = vector_push_back(vector, "TEST");

    OP_ASSERT_EQUAL_CSTRING("TEST", vector->Data);
    OP_ASSERT_EQUAL_CSTRING("TEST", (char *)ret);
    OP_VERIFY();
}

static void 
vector_push_back_when_called_twice_puts_value_in_data_and_sets_length()
{
    Vector *vector;
    Vector retVector = { 0 };
    char data[4096] = { 0 };

    Malloc_ExpectAndReturn(0, &retVector, NULL);
    Malloc_ExpectAndReturn(0, data, NULL);

    vector = vector_new(100, 5);

    vector_push_back(vector, "TEST");
    vector_push_back(vector, "1TES");

    OP_ASSERT_EQUAL_CSTRING("TEST", vector->Data);
    OP_ASSERT_EQUAL_CSTRING("1TES", vector->Data + 5);
    OP_ASSERT_EQUAL_INT(2, (int)vector->Length);
    OP_ASSERT_EQUAL_INT(100, (int)vector->Capacity);
    OP_VERIFY();
}

static void
vector_push_back_when_above_capacity_extends_vector()
{
    Vector *vector;
    Vector retVector = { 0 };
    char data[4096] = { 0 };

    Malloc_ExpectAndReturn(0, &retVector, NULL);
    Malloc_ExpectAndReturn(0, data, NULL);
    Realloc_ExpectAndReturn(NULL, 0, &data, NULL, NULL);

    vector = vector_new(1, 5);

    vector_push_back(vector, "TEST");

    OP_ASSERT_EQUAL_INT(1, (int)vector->Capacity);

    vector_push_back(vector, "1TES");

    OP_ASSERT_EQUAL_CSTRING("TEST", vector->Data);
    OP_ASSERT_EQUAL_CSTRING("1TES", vector->Data + 5);
    OP_ASSERT_EQUAL_INT(2, (int)vector->Length);
    OP_ASSERT_EQUAL_INT(2, (int)vector->Capacity);
    OP_VERIFY();
}

static void
vector_length_when_called_with_null_this_returns_zero()
{
    OP_ASSERT_EQUAL_INT(0, (int)vector_length(NULL));
    OP_VERIFY();
}

static void
vector_length_when_called_returns_correct_length()
{
    Vector *vector;
    Vector retVector = { 0 };
    char data[4096] = { 0 };

    Malloc_ExpectAndReturn(0, &retVector, NULL);
    Malloc_ExpectAndReturn(0, data, NULL);

    vector = vector_new(0, 4);

    vector_push_back(vector, "TEST");

    OP_ASSERT_EQUAL_INT(1, (int)vector_length(vector));
    OP_ASSERT_EQUAL_INT((int)vector->Length, (int)vector_length(vector));

    vector_push_back(vector, "1TES");

    OP_ASSERT_EQUAL_INT(2, (int)vector_length(vector));
    OP_ASSERT_EQUAL_INT((int)vector->Length, (int)vector_length(vector));
    OP_VERIFY();
}

static void
vector_get_when_called_with_null_this_returns_null()
{
    OP_ASSERT_TRUE(vector_get(NULL, 0) == NULL);
    OP_VERIFY();
}

static void
vector_get_when_called_returns_correct_value()
{
    Vector *vector;
    Vector retVector = { 0 };
    char data[4096] = { 0 };

    Malloc_ExpectAndReturn(0, &retVector, NULL);
    Malloc_ExpectAndReturn(0, data, NULL);

    vector = vector_new(0, 5);

    vector_push_back(vector, "TEST");
    vector_push_back(vector, "1TES");

    OP_ASSERT_EQUAL_CSTRING("TEST", (char *)vector_get(vector, 0));
    OP_ASSERT_EQUAL_CSTRING("1TES", (char *)vector_get(vector, 1));
    OP_VERIFY();
}

static void
vector_get_when_called_with_out_of_range_index_returns_null()
{
    Vector *vector;
    Vector retVector = { 0 };
    char data[4096] = { 0 };

    Malloc_ExpectAndReturn(0, &retVector, NULL);
    Malloc_ExpectAndReturn(0, data, NULL);

    vector = vector_new(0, 5);

    vector_push_back(vector, "TEST");
    vector_push_back(vector, "1TES");

    OP_ASSERT_TRUE(vector_get(vector, 2) == NULL);
    OP_ASSERT_EQUAL_CSTRING("TEST", (char *)vector_get(vector, 0));
    OP_ASSERT_EQUAL_CSTRING("1TES", (char *)vector_get(vector, 1));
    OP_VERIFY();
}

static void
vector_delete_when_null_vector_returns()
{
    vector_delete(NULL, 0);

    OP_VERIFY();
}

static void
vector_delete_when_not_present_returns()
{
    Vector retVector = { 0 };
    Vector *vector;
    char data[4096];

    Malloc_ExpectAndReturn(0, &retVector, NULL);
    Malloc_ExpectAndReturn(0, data, NULL);

    vector = vector_new(0, 5);
    vector_push_back(vector, "TEST");
    vector_delete(vector, 1);

    OP_ASSERT_EQUAL_INT(1, (int)vector_length(vector));

    OP_VERIFY();
}

static void
vector_delete_when_present_deletes()
{
    Vector retVector = { 0 };
    Vector *vector;
    char data[4096];

    Malloc_ExpectAndReturn(0, &retVector, NULL);
    Malloc_ExpectAndReturn(0, data, NULL);

    vector = vector_new(0, 5);
    vector_push_back(vector, "TEST");
    vector_delete(vector, 0);

    OP_ASSERT_EQUAL_INT(0, (int)vector_length(vector));

    OP_VERIFY();
}

static void
vector_delete_when_multiple_deletes_first()
{
    Vector retVector = { 0 };
    Vector *vector;
    char data[4096];

    Malloc_ExpectAndReturn(0, &retVector, NULL);
    Malloc_ExpectAndReturn(0, data, NULL);

    vector = vector_new(0, 5);
    vector_push_back(vector, "TEST");
    vector_push_back(vector, "1234");
    vector_delete(vector, 0);

    OP_ASSERT_EQUAL_INT(1, (int)vector_length(vector));
    OP_ASSERT_EQUAL_CSTRING("1234", (char *)vector_get(vector, 0));

    OP_VERIFY();
}

static void
vector_delete_when_multiple_deletes_middle()
{
    Vector retVector = { 0 };
    Vector *vector;
    char data[4096];

    Malloc_ExpectAndReturn(0, &retVector, NULL);
    Malloc_ExpectAndReturn(0, data, NULL);

    vector = vector_new(0, 5);
    vector_push_back(vector, "1111");
    vector_push_back(vector, "2222");
    vector_push_back(vector, "3333");
    vector_delete(vector, 1);

    OP_ASSERT_EQUAL_INT(2, (int)vector_length(vector));
    OP_ASSERT_EQUAL_CSTRING("1111", (char *)vector_get(vector, 0));
    OP_ASSERT_EQUAL_CSTRING("3333", (char *)vector_get(vector, 1));

    OP_VERIFY();
}

static void
vector_free_when_null_returns()
{
    vector_free(NULL);

    OP_VERIFY();
}

static void
vector_free_when_called_frees_vector()
{
    Vector test = { 0 };

    Free_ExpectAndReturn(test.Data, cmp_ptr);
    Free_ExpectAndReturn(&test, cmp_ptr);

    vector_free(&test);

    OP_VERIFY();
}

int
main()
{
    opmock_test_suite_reset();

    opmock_register_test(vector_new_when_called_with_zero_element_size_returns_null,
                         "vector_new_when_called_with_zero_element_size_returns_null");
    opmock_register_test(vector_new_when_called_with_zero_capacity_sets_default_capacity,
                         "vector_new_when_called_with_zero_capacity_sets_default_capacity");
    opmock_register_test(vector_new_when_called_sets_capactity_and_element_size,
                         "vector_new_when_called_sets_capactity_and_element_size");
    opmock_register_test(vector_push_back_when_called_with_null_this_returns_null,
                         "vector_push_back_when_called_with_null_this_returns_null");
    opmock_register_test(vector_push_back_when_called_with_null_value_returns_null,
                         "vector_push_back_when_called_with_null_value_returns_null");
    opmock_register_test(vector_push_back_when_called_sets_length,
                         "vector_push_back_when_called_sets_length");
    opmock_register_test(vector_push_back_when_called_does_not_increase_capacity,
                         "vector_push_back_when_called_does_not_increase_capacity");
    opmock_register_test(vector_push_back_when_called_puts_value_in_data,
                         "vector_push_back_when_called_puts_value_in_data");
    opmock_register_test(vector_push_back_when_called_twice_puts_value_in_data_and_sets_length,
                         "vector_push_back_when_called_twice_puts_value_in_data_and_sets_length");
    opmock_register_test(vector_push_back_when_above_capacity_extends_vector,
                         "vector_push_back_when_above_capacity_extends_vector");
    opmock_register_test(vector_length_when_called_with_null_this_returns_zero,
                         "vector_length_when_called_with_null_this_returns_zero");
    opmock_register_test(vector_length_when_called_returns_correct_length,
                         "vector_length_when_called_returns_correct_length");
    opmock_register_test(vector_get_when_called_with_null_this_returns_null,
                         "vector_get_when_called_with_null_this_returns_null");
    opmock_register_test(vector_get_when_called_returns_correct_value,
                         "vector_get_when_called_returns_correct_value");
    opmock_register_test(vector_get_when_called_with_out_of_range_index_returns_null,
                         "vector_get_when_called_with_out_of_range_index_returns_null");
    opmock_register_test(vector_delete_when_null_vector_returns,
                         "vector_delete_when_null_vector_returns");
    opmock_register_test(vector_delete_when_not_present_returns,
                         "vector_delete_when_not_present_returns");
    opmock_register_test(vector_delete_when_present_deletes,
                         "vector_delete_when_present_deletes");
    opmock_register_test(vector_delete_when_multiple_deletes_first,
                         "vector_delete_when_multiple_deletes_first");
    opmock_register_test(vector_delete_when_multiple_deletes_middle,
                         "vector_delete_when_multiple_deletes_middle");
    opmock_register_test(vector_free_when_null_returns,
                         "vector_free_when_null_returns");
    opmock_register_test(vector_free_when_called_frees_vector,
                         "vector_free_when_called_frees_vector");

    opmock_test_suite_run();

    return opmock_test_error > 0;
}
