/*
 * Copyright (c) 2015, Stuart Walsh
 * All rights reserved.
 * list_tests.c list tests
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

#include "list.h"

static List TestList;
static size_t TestItem1 = 11111111;
static size_t TestItem2 = 22222222;
static size_t TestItem3 = 33333333;
static ListEntry Item1;
static ListEntry Item2;
static ListEntry Item3;

static List *
setup_list()
{
    memset(&TestList, 0, sizeof(List));
    memset(&Item1, 0, sizeof(Item1));
    memset(&Item2, 0, sizeof(Item2));
    memset(&Item3, 0, sizeof(Item3));

    Malloc_ExpectAndReturn(sizeof(List), &TestList, cmp_int);

    return list_new();
}

static void
list_new_when_called_returns_list()
{
    List *list;

    list = setup_list();

    OP_ASSERT_TRUE(list != NULL);
}

static void
list_add_when_called_with_null_list_returns()
{
    list_add(NULL, (void *)TestItem1);

    OP_VERIFY();
}

static void
list_add_when_called_with_null_item_returns()
{
    List *list = setup_list();
    ListEntry *entry;

    entry = list_add(list, NULL);

    OP_ASSERT_TRUE(entry == NULL);
    OP_ASSERT_EQUAL_ULONG(0UL, list->Length);
}

static void
list_add_when_called_with_item_adds_item()
{
    List *list = setup_list();
    ListEntry *entry;

    Malloc_ExpectAndReturn(sizeof(ListEntry), &Item1, cmp_int);

    entry = list_add(list, (void *)TestItem1);

    OP_ASSERT_TRUE(entry != NULL);
    OP_ASSERT_EQUAL_ULONG(TestItem1, (size_t)list->Head->Data);
    OP_ASSERT_EQUAL_ULONG(TestItem1, (size_t)list->Tail->Data);
    OP_ASSERT_EQUAL_ULONG(1UL, list->Length);
}

static void
list_add_when_called_twice_adds_both()
{
    List *list = setup_list();

    Malloc_ExpectAndReturn(sizeof(ListEntry), &Item1, cmp_int);
    Malloc_ExpectAndReturn(sizeof(ListEntry), &Item2, cmp_int);

    list_add(list, (void *)TestItem1);
    list_add(list, (void *)TestItem2);

    OP_ASSERT_EQUAL_ULONG(TestItem2, (size_t)list->Head->Data);
    OP_ASSERT_EQUAL_ULONG(TestItem1, (size_t)list->Head->Next->Data);
    OP_ASSERT_EQUAL_ULONG(2UL, list->Length);
}

static void
list_add_tail_when_called_with_null_list_returns()
{
    list_add_tail(NULL, (void *)TestItem1);

    OP_VERIFY();
}

static void
list_add_tail_when_called_with_null_item_returns()
{
    List *list = setup_list();
    ListEntry *entry;

    entry = list_add_tail(list, NULL);

    OP_ASSERT_TRUE(entry == NULL);
    OP_ASSERT_EQUAL_ULONG(0UL, list->Length);
}

static void
list_add_tail_when_called_with_item_adds_item()
{
    List *list = setup_list();
    ListEntry *entry;

    Malloc_ExpectAndReturn(sizeof(ListEntry), &Item1, cmp_int);

    entry = list_add_tail(list, (void *)TestItem1);

    OP_ASSERT_TRUE(entry != NULL);
    OP_ASSERT_EQUAL_ULONG(TestItem1, (size_t)list->Head->Data);
    OP_ASSERT_EQUAL_ULONG(TestItem1, (size_t)list->Tail->Data);
    OP_ASSERT_EQUAL_ULONG(1UL, list->Length);
}

static void
list_add_tail_when_called_twice_adds_both()
{
    List *list = setup_list();

    Malloc_ExpectAndReturn(sizeof(ListEntry), &Item1, cmp_int);
    Malloc_ExpectAndReturn(sizeof(ListEntry), &Item2, cmp_int);

    list_add_tail(list, (void *)TestItem1);
    list_add_tail(list, (void *)TestItem2);

    OP_ASSERT_EQUAL_ULONG(TestItem1, (size_t)list->Head->Data);
    OP_ASSERT_EQUAL_ULONG(TestItem2, (size_t)list->Head->Next->Data);
    OP_ASSERT_EQUAL_ULONG(TestItem2, (size_t)list->Tail->Data);
    OP_ASSERT_EQUAL_ULONG(TestItem1, (size_t)list->Tail->Prev->Data);
    OP_ASSERT_EQUAL_ULONG(2UL, list->Length);
}


static void
list_delete_when_null_list_returns()
{
    list_delete(NULL, &Item1);

    OP_VERIFY();
}

static void
list_delete_when_null_entry_returns()
{
    List *list = setup_list();

    Malloc_ExpectAndReturn(sizeof(ListEntry), &Item1, cmp_int);

    list_add(list, (void *)TestItem1);
    list_delete(list, NULL);

    OP_ASSERT_EQUAL_ULONG(1UL, list->Length);
}

static void
list_delete_when_called_removes_item()
{
    List *list = setup_list();
    ListEntry *entry;

    Malloc_ExpectAndReturn(sizeof(ListEntry), &Item1, cmp_int);

    entry = list_add(list, (void *)TestItem1);
    list_delete(list, entry);

    OP_ASSERT_EQUAL_ULONG(0UL, list->Length);
    OP_ASSERT_TRUE(list->Head == NULL);
}

static void
list_delete_when_called_on_middle_node_keeps_list()
{
    List *list = setup_list();
    ListEntry *entry;

    Malloc_ExpectAndReturn(sizeof(ListEntry), &Item1, cmp_int);
    Malloc_ExpectAndReturn(sizeof(ListEntry), &Item2, cmp_int);
    Malloc_ExpectAndReturn(sizeof(ListEntry), &Item3, cmp_int);

    list_add(list, (void *)TestItem1);
    entry = list_add(list, (void *)TestItem2);
    list_add(list, (void *)TestItem3);

    list_delete(list, entry);

    OP_ASSERT_EQUAL_ULONG(2UL, list->Length);
    OP_ASSERT_EQUAL_ULONG(TestItem3, (size_t)list->Head->Data);
    OP_ASSERT_EQUAL_ULONG(TestItem1, (size_t)list->Head->Next->Data);
}

int
main()
{
    opmock_test_suite_reset();

    opmock_register_test(list_new_when_called_returns_list,
                         "list_new_when_called_returns_list");
    opmock_register_test(list_add_when_called_with_null_list_returns,
                         "list_add_when_called_with_null_list_returns");
    opmock_register_test(list_add_when_called_with_null_item_returns,
                         "list_add_when_called_with_null_item_returns");
    opmock_register_test(list_add_when_called_with_item_adds_item,
                         "list_add_when_called_with_item_adds_item");
    opmock_register_test(list_add_when_called_twice_adds_both,
                         "list_add_when_called_twice_adds_both");
    opmock_register_test(list_add_tail_when_called_with_null_list_returns,
                         "list_add_tail_when_called_with_null_list_returns");
    opmock_register_test(list_add_tail_when_called_with_null_item_returns,
                         "list_add_tail_when_called_with_null_item_returns");
    opmock_register_test(list_add_tail_when_called_with_item_adds_item,
                         "list_add_tail_when_called_with_item_adds_item");
    opmock_register_test(list_add_tail_when_called_twice_adds_both,
                         "list_add_tail_when_called_twice_adds_both");
    opmock_register_test(list_delete_when_null_list_returns,
                         "list_delete_when_null_list_returns");
    opmock_register_test(list_delete_when_null_entry_returns,
                         "list_delete_when_null_entry_returns");
    opmock_register_test(list_delete_when_called_removes_item,
                         "list_delete_when_called_removes_item");
    opmock_register_test(list_delete_when_called_on_middle_node_keeps_list,
                         "list_delete_when_called_on_middle_node_keeps_list");

    opmock_test_suite_run();

    return opmock_test_error > 0;
}
