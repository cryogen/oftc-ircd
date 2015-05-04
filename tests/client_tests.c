/*
 * Copyright (c) 2014, Stuart Walsh
 * All rights reserved.
 * client_tests.c client tests
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
#include "hash_stub.h"
#include "vector_stub.h"
#include "uv_stub.h"
#include "server_stub.h"
#include "buffer_stub.h"
#include "parser_stub.h"
#include "command_stub.h"
#include "network_stub.h"
#include "connection_stub.h"

#include "client.h"
#include "listener.h"
#include "network.h"

#include <stdlib.h>

static Client TestClient;
static Client Server;
static ClientDnsRequest DnsRequest;
static ParserResult Result;
static Command ResultCommand;
static uv_getnameinfo_t NameRequest;
static uv_getaddrinfo_t AddressRequest;

static void
setup_send()
{
    server_get_this_server_ExpectAndReturn(&Server);

    connection_send_ExpectAndReturn(NULL, NULL, NULL, NULL);
}

static void
setup_dns()
{
    struct sockaddr_in addr4 = { 0 };

    memset(&TestClient, 0, sizeof(TestClient));
    memset(&Server, 0, sizeof(Server));
    memset(&DnsRequest, 0, sizeof(DnsRequest));

    setup_send();

    Malloc_ExpectAndReturn(sizeof(DnsRequest), &DnsRequest, cmp_int);
    Malloc_ExpectAndReturn(sizeof(NameRequest), &NameRequest, cmp_int);

    TestClient.Address.AddressLength = sizeof(addr4);

    addr4.sin_addr.s_addr = inet_addr("123.123.123.123");

    memcpy(&TestClient.Address.Address.Addr4, &addr4, sizeof(addr4));

    TestClient.handle = malloc(sizeof(uv_tcp_t));
    TestClient.handle->data = &TestClient;
}

static void
setup_parser()
{
    memset(&Result, 0, sizeof(Result));

    parser_get_line_ExpectAndReturn(NULL, NULL, 0, true, NULL, NULL, NULL);
    parser_process_line_ExpectAndReturn(NULL, 0, &Result, NULL, NULL);
}

static void
setup_command()
{
    setup_parser();

    memset(&ResultCommand, 0, sizeof(Command));
    
    command_find_ExpectAndReturn(NULL, &ResultCommand, NULL);

    parser_result_free_ExpectAndReturn(&Result, cmp_ptr);
    parser_get_line_ExpectAndReturn(NULL, NULL, 0, NULL, NULL, NULL, NULL);
}

static int
getnameinfo_goodstatus(uv_loop_t* loop,
                       uv_getnameinfo_t *request,
                       uv_getnameinfo_cb getnameinfo_cb,
                       const struct sockaddr *addr,
                       int flags,
                       int calls)
{
    getnameinfo_cb(request, 0, "Test.Test", NULL);

    return 0;
}

static int
getnameinfo_badstatus(uv_loop_t* loop,
                      uv_getnameinfo_t *request,
                      uv_getnameinfo_cb getnameinfo_cb,
                      const struct sockaddr *addr,
                      int flags,
                      int calls)
{
    getnameinfo_cb(request, 1, NULL, NULL);

    return 0;
}

static int
set_null_callback(uv_loop_t *loop,
                  uv_getnameinfo_t *request,
                  uv_getnameinfo_cb getnameinfo_cb,
                  const struct sockaddr *addr,
                  int flags,
                  int calls)
{
    DnsRequest.Callback = NULL;

    getnameinfo_cb(request, 1, NULL, NULL);

    return 0;
}

static int
getaddrinfo_badstatus(uv_loop_t *loop,
                      uv_getaddrinfo_t *request,
                      uv_getaddrinfo_cb callback,
                      const char *node,
                      const char *service,
                      const struct addrinfo *hints,
                      int calls)
{
    callback(request, -1, NULL);

    return 0;
}

static int
getaddrinfo_nomatch(uv_loop_t *loop,
                    uv_getaddrinfo_t *request,
                    uv_getaddrinfo_cb callback,
                    const char *node,
                    const char *service,
                    const struct addrinfo *hints,
                    int calls)
{
    struct addrinfo addr = { 0 };
    struct sockaddr_in addr4 = { 0 };

    addr.ai_addrlen = sizeof(addr4);

    addr4.sin_addr.s_addr = inet_addr("111.111.111.111");

    addr.ai_addr = (struct sockaddr *)&addr4;

    callback(request, 0, &addr);
    
    return 0;
}

static int
getaddrinfo_match(uv_loop_t *loop,
                  uv_getaddrinfo_t *request,
                  uv_getaddrinfo_cb callback,
                  const char *node,
                  const char *service,
                  const struct addrinfo *hints,
                  int calls)
{
    struct addrinfo addr = { 0 };
    struct sockaddr_in addr4 = { 0 };

    addr.ai_addrlen = sizeof(addr4);

    addr4.sin_addr.s_addr = inet_addr("123.123.123.123");

    addr.ai_addr = (struct sockaddr *)&addr4;

    callback(request, 0, &addr);
    
    return 0;
}

static int
uv_ip4_name_callback(const struct sockaddr_in *src,
                     char *dst,
                     size_t size,
                     int calls)
{
    inet_ntop(AF_INET, &src->sin_addr, dst, (socklen_t)size);

    return 0;
}

static bool callback_called = false;

static void
handler_callback(Client *client, Vector *args)
{
    callback_called = true;
}

static void
client_init_when_called_init_sets_up_hash_and_vector()
{
    Vector test;
    Hash testHash;

    vector_new_ExpectAndReturn(0, sizeof(Client), &test, cmp_int, cmp_int);
    hash_new_ExpectAndReturn("Client Hash", 0, &testHash, cmp_cstr, cmp_int);

    client_init();

    OP_VERIFY();
}

static void
client_new_when_called_allocates_memory()
{
    Client *ptr;
    Buffer clientBuffer = { 0 };

    void *ret = malloc(sizeof(Client));

    Malloc_ExpectAndReturn(sizeof(Client), ret, cmp_int);
    buffer_new_ExpectAndReturn(&clientBuffer);
    ptr = client_new();

    OP_ASSERT_TRUE(ptr == ret);
    OP_VERIFY();

    free(ptr);
}

static void
client_free_when_called_with_null_returns()
{
    client_free(NULL);

    OP_VERIFY();
}

static void
client_free_when_called_with_null_handle_frees_client()
{
    Client *testClient = calloc(1, sizeof(Client));

    Free_ExpectAndReturn(testClient, cmp_ptr);

    client_free(testClient);

    OP_VERIFY();

    free(testClient);
}

static void
client_free_when_called_with_handle_close_handle()
{
    Client *testClient = calloc(1, sizeof(Client));

    testClient->handle = calloc(1, sizeof(uv_tcp_t));

    uv_close_ExpectAndReturn(NULL, NULL, NULL, NULL);
    Free_ExpectAndReturn(NULL, NULL);
    Free_ExpectAndReturn(testClient, cmp_ptr);

    client_free(testClient);

    OP_VERIFY();

    free(testClient->handle);
    free(testClient);
}

static void
client_lookup_dns_when_client_null_returns()
{
    client_lookup_dns(NULL);

    OP_VERIFY();
}

static void
client_lookup_dns_when_getnameinfo_fails_sets_ip_as_host()
{
    setup_dns();

    uv_getnameinfo_ExpectAndReturn(NULL, &NameRequest, NULL, NULL, 0, -1, NULL,
                                   cmp_ptr, NULL, NULL, NULL);

    Free_ExpectAndReturn(NULL, NULL);

    network_ipstring_from_address_ExpectAndReturn(&TestClient.Address, NULL,
                                                  0, true, cmp_ptr, NULL, NULL);

    setup_send();

    connection_start_read_ExpectAndReturn(NULL, NULL);
    Free_ExpectAndReturn(NULL, NULL);

    client_lookup_dns(&TestClient);

    OP_VERIFY();
}

static void
client_lookup_dns_when_null_callback_returns_ok()
{
    setup_dns();

    uv_getnameinfo_MockWithCallback(set_null_callback);
    Free_ExpectAndReturn(NULL, NULL);

    client_lookup_dns(&TestClient);

    OP_VERIFY();
}

static void
client_lookup_dns_when_getnameinfo_succeeds_returns_ok()
{
    setup_dns();

    uv_getnameinfo_ExpectAndReturn(NULL, &NameRequest, NULL, NULL, 0, 0, NULL,
                                   cmp_ptr, NULL, NULL, NULL);

    client_lookup_dns(&TestClient);

    OP_VERIFY();
}

static void
client_lookup_dns_when_namecallback_returns_bad_status_frees_request()
{
    setup_dns();

    uv_getnameinfo_MockWithCallback(&getnameinfo_badstatus);

    network_ipstring_from_address_ExpectAndReturn(&TestClient.Address, NULL,
                                                  0, true, cmp_ptr, NULL, NULL);

    setup_send();

    connection_start_read_ExpectAndReturn(NULL, NULL);
    Free_ExpectAndReturn(NULL, NULL);
    Free_ExpectAndReturn(&NameRequest, cmp_ptr);

    client_lookup_dns(&TestClient);

    OP_VERIFY();
}

static void
client_lookup_dns_when_namecallback_returns_good_status_getsaddress()
{
    setup_dns();

    uv_getnameinfo_MockWithCallback(&getnameinfo_goodstatus);

    Malloc_ExpectAndReturn(sizeof(uv_getaddrinfo_t), &AddressRequest, cmp_int);
    uv_getaddrinfo_ExpectAndReturn(NULL, &AddressRequest, NULL, NULL, NULL, NULL, 0,
                                   NULL, cmp_ptr, NULL, NULL, NULL, NULL);

    Free_ExpectAndReturn(&NameRequest, cmp_ptr);

    client_lookup_dns(&TestClient);

    OP_VERIFY();
}

static void
client_lookup_dns_when_addrcallback_returns_bad_status_frees_request()
{
    setup_dns();

    uv_getnameinfo_MockWithCallback(&getnameinfo_goodstatus);

    Malloc_ExpectAndReturn(sizeof(uv_getaddrinfo_t), &AddressRequest, cmp_int);
    uv_getaddrinfo_MockWithCallback(getaddrinfo_badstatus);

    network_ipstring_from_address_ExpectAndReturn(&TestClient.Address, NULL,
                                                  0, true, cmp_ptr, NULL, NULL);

    setup_send();

    connection_start_read_ExpectAndReturn(NULL, NULL);
    Free_ExpectAndReturn(NULL, NULL);
    Free_ExpectAndReturn(&AddressRequest, cmp_ptr);
    Free_ExpectAndReturn(&NameRequest, cmp_ptr);

    client_lookup_dns(&TestClient);

    OP_VERIFY();
}

static void
client_lookup_dns_when_addrcallback_and_no_host_match_sets_ip_as_host()
{
    setup_dns();

    uv_getnameinfo_MockWithCallback(&getnameinfo_goodstatus);

    Malloc_ExpectAndReturn(sizeof(uv_getaddrinfo_t), &AddressRequest, cmp_int);
    uv_getaddrinfo_MockWithCallback(getaddrinfo_nomatch);

    uv_ip4_name_MockWithCallback(uv_ip4_name_callback);

    network_ipstring_from_address_ExpectAndReturn(&TestClient.Address, NULL,
                                                  0, true, cmp_ptr, NULL, NULL);

    setup_send();

    connection_start_read_ExpectAndReturn(NULL, NULL);
    Free_ExpectAndReturn(NULL, NULL);

    Free_ExpectAndReturn(&AddressRequest, cmp_ptr);
    Free_ExpectAndReturn(&NameRequest, cmp_ptr);

    client_lookup_dns(&TestClient);

    OP_VERIFY();
}

static void
client_lookup_dns_when_addrcallback_and_host_match_sets_host()
{
    setup_dns();

    uv_getnameinfo_MockWithCallback(&getnameinfo_goodstatus);

    Malloc_ExpectAndReturn(sizeof(uv_getaddrinfo_t), &AddressRequest, cmp_int);
    uv_getaddrinfo_MockWithCallback(getaddrinfo_match);

    uv_ip4_name_MockWithCallback(uv_ip4_name_callback);

    setup_send();

    connection_start_read_ExpectAndReturn(NULL, NULL);
    Free_ExpectAndReturn(NULL, NULL);

    Free_ExpectAndReturn(&AddressRequest, cmp_ptr);
    Free_ExpectAndReturn(&NameRequest, cmp_ptr);


    client_lookup_dns(&TestClient);

    OP_VERIFY();
}

static void
client_send_when_no_source_sends_message()
{
    connection_send_ExpectAndReturn(&TestClient, "Test * :foo", cmp_ptr, cmp_cstr);

    client_send(NULL, &TestClient, "Test", "%s", ":foo");

    OP_VERIFY();
}

static void
client_send_when_source_sends_message_with_source()
{
    Client testServer = { 0 };

    strcpy(testServer.Name, "Test.Server");

    connection_send_ExpectAndReturn(&TestClient, ":Test.Server Test * foo",
                                    cmp_ptr, cmp_cstr);

    client_send(&testServer, &TestClient, "Test", "%s", "foo");

    OP_VERIFY();
}

static void
client_process_read_buffer_when_null_result_continues()
{
    Client client = { 0 };

    parser_get_line_ExpectAndReturn(NULL, NULL, 0, true, NULL, NULL, NULL);
    parser_process_line_ExpectAndReturn(NULL, 0, NULL, NULL, NULL);
    parser_get_line_ExpectAndReturn(NULL, NULL, 0, NULL, NULL, NULL, NULL);

    client_process_read_buffer(&client);
    
    OP_VERIFY();
}

static void
client_process_read_buffer_when_command_not_found_frees_result()
{
    Client client = { 0 };

    setup_parser();

    command_find_ExpectAndReturn(NULL, NULL, NULL);
    parser_result_free_ExpectAndReturn(&Result, cmp_ptr);
    parser_get_line_ExpectAndReturn(NULL, NULL, 0, NULL, NULL, NULL, NULL);

    client_process_read_buffer(&client);
    
    OP_VERIFY();
}

static void
client_process_read_buffer_when_handler_null_works_ok()
{
    Client client = { 0 };

    setup_parser();

    command_find_ExpectAndReturn(NULL, &ResultCommand, NULL);
    vector_length_ExpectAndReturn(NULL, 1, NULL);
    parser_result_free_ExpectAndReturn(&Result, cmp_ptr);
    parser_get_line_ExpectAndReturn(NULL, NULL, 0, NULL, NULL, NULL, NULL);

    ResultCommand.Handler = NULL;

    client_process_read_buffer(&client);
    
    OP_VERIFY();
}


static void
client_process_read_buffer_when_handler_calls_handler()
{
    Client client = { 0 };

    setup_command();

    ResultCommand.Handler = handler_callback;

    client_process_read_buffer(&client);

    OP_ASSERT_TRUE(callback_called);
}

static void
client_process_read_buffer_when_no_access_does_not_call_handler()
{
    Client client = { 0 };

    setup_command();

    callback_called = false;
    ResultCommand.Handler = handler_callback;
    ResultCommand.RequiredAccess = Standard;

    client_process_read_buffer(&client);

    OP_ASSERT_FALSE(callback_called);
}

static void
client_process_read_buffer_when_too_few_args_does_not_call_handler()
{
    Client client = { 0 };

    setup_parser();
    setup_command();

    vector_length_ExpectAndReturn(NULL, 0, NULL);
    parser_result_free_ExpectAndReturn(&Result, cmp_ptr);
    parser_get_line_ExpectAndReturn(NULL, NULL, 0, NULL, NULL, NULL, NULL);

    callback_called = false;
    ResultCommand.Handler = handler_callback;
    ResultCommand.MinParams = 1;

    client_process_read_buffer(&client);

    OP_ASSERT_FALSE(callback_called);
}

static void
client_set_nickname_when_null_client_returns_false()
{
    bool ret;

    ret = client_set_nickname(NULL, "foo");

    OP_ASSERT_FALSE(ret);
}

static void
client_set_nickname_when_null_nick_returns_false()
{
    bool ret;

    ret = client_set_nickname(&TestClient, NULL);

    OP_ASSERT_FALSE(ret);
}

static void
client_set_nickname_when_called_sets_nickname()
{
    bool ret;

    ret = client_set_nickname(&TestClient, "Test");

    OP_ASSERT_TRUE(ret);
    OP_ASSERT_EQUAL_CSTRING("Test", TestClient.Name);
}

static void
client_set_nickname_when_too_long_truncates()
{
    bool ret;
    char longNick[NICKLEN + 10] = { 0 };
    char expected[NICKLEN + 1] = { 0 };

    memset(longNick, '1', sizeof(longNick) - 1);
    memset(expected, '1', sizeof(expected) - 1);

    ret = client_set_nickname(&TestClient, longNick);

    OP_ASSERT_TRUE(ret);
    OP_ASSERT_EQUAL_CSTRING(expected, TestClient.Name);
}

static void
client_set_username_when_null_client_returns_false()
{
    bool ret;

    ret = client_set_username(NULL, "foo");

    OP_ASSERT_FALSE(ret);
}

static void
client_set_username_when_null_username_returns_false()
{
    bool ret;

    ret = client_set_username(&TestClient, NULL);

    OP_ASSERT_FALSE(ret);
}

static void
client_set_username_when_called_sets_username()
{
    bool ret;

    ret = client_set_username(&TestClient, "Test");

    OP_ASSERT_TRUE(ret);
    OP_ASSERT_EQUAL_CSTRING("Test", TestClient.Username);
}

static void
client_set_username_when_too_long_truncates()
{
    bool ret;
    char longUser[USERLEN + 10] = { 0 };
    char expected[USERLEN + 1] = { 0 };

    memset(longUser, '1', sizeof(longUser) - 1);
    memset(expected, '1', sizeof(expected) - 1);

    ret = client_set_username(&TestClient, longUser);

    OP_ASSERT_TRUE(ret);
    OP_ASSERT_EQUAL_CSTRING(expected, TestClient.Username);
}

static void
client_set_realname_when_null_client_returns_false()
{
    bool ret;

    ret = client_set_realname(NULL, "foo");

    OP_ASSERT_FALSE(ret);
}

static void
client_set_realname_when_null_realname_returns_false()
{
    bool ret;

    ret = client_set_realname(&TestClient, NULL);

    OP_ASSERT_FALSE(ret);
}

static void
client_set_realname_when_called_sets_realname()
{
    bool ret;

    ret = client_set_realname(&TestClient, "Test");

    OP_ASSERT_TRUE(ret);
    OP_ASSERT_EQUAL_CSTRING("Test", TestClient.Realname);
}

static void
client_set_realname_when_too_long_truncates()
{
    bool ret;
    char longReal[REALLEN + 10] = { 0 };
    char expected[REALLEN + 1] = { 0 };

    memset(longReal, '1', sizeof(longReal) - 1);
    memset(expected, '1', sizeof(expected) - 1);

    ret = client_set_realname(&TestClient, longReal);

    OP_ASSERT_TRUE(ret);
    OP_ASSERT_EQUAL_CSTRING(expected, TestClient.Realname);
}

static void
client_get_nickname_when_null_nick_returns_null()
{
    const char *ret;

    ret = client_get_nickname(NULL);

    OP_ASSERT_TRUE(ret == NULL);
}

static void
client_get_nickname_when_empty_name_returns_star()
{
    const char *ret;

    memset(TestClient.Name, 0, sizeof(TestClient.Name));

    ret = client_get_nickname(&TestClient);

    OP_ASSERT_EQUAL_CSTRING("*", ret);
}

static void
client_get_nickname_when_name_returns_name()
{
    const char *ret;

    strcpy(TestClient.Name, "Test");

    ret = client_get_nickname(&TestClient);

    OP_ASSERT_EQUAL_CSTRING("Test", ret);
}

int main()
{
    opmock_test_suite_reset();

    opmock_register_test(client_new_when_called_allocates_memory,
                         "client_new_when_called_allocates_memory");
    opmock_register_test(client_init_when_called_init_sets_up_hash_and_vector,
                         "client_init_when_called_init_sets_up_hash_and_vector");
    opmock_register_test(client_free_when_called_with_null_returns,
                         "client_free_when_called_with_null_returns");
    opmock_register_test(client_free_when_called_with_null_handle_frees_client,
                         "client_free_when_called_with_null_handle_frees_client");
    opmock_register_test(client_free_when_called_with_handle_close_handle,
                         "client_free_when_called_with_handle_close_handle");
    opmock_register_test(client_lookup_dns_when_client_null_returns,
                         "client_lookup_dns_when_client_null_returns");
    opmock_register_test(client_lookup_dns_when_getnameinfo_fails_sets_ip_as_host,
                         "client_lookup_dns_when_getnameinfo_fails_sets_ip_as_host");
    opmock_register_test(client_lookup_dns_when_null_callback_returns_ok,
                         "client_lookup_dns_when_null_callback_returns_ok");
    opmock_register_test(client_lookup_dns_when_getnameinfo_succeeds_returns_ok,
                         "client_lookup_dns_when_getnameinfo_succeeds_returns_ok");
    opmock_register_test(client_lookup_dns_when_namecallback_returns_bad_status_frees_request,
                         "client_lookup_dns_when_namecallback_returns_bad_status_frees_request");
    opmock_register_test(client_lookup_dns_when_namecallback_returns_good_status_getsaddress,
                         "client_lookup_dns_when_namecallback_returns_good_status_getsaddress");
    opmock_register_test(client_lookup_dns_when_addrcallback_returns_bad_status_frees_request,
                         "client_lookup_dns_when_addrcallback_returns_bad_status_frees_request");
    opmock_register_test(client_lookup_dns_when_addrcallback_and_no_host_match_sets_ip_as_host,
                         "client_lookup_dns_when_addrcallback_and_no_host_match_sets_ip_as_host");
    opmock_register_test(client_lookup_dns_when_addrcallback_and_host_match_sets_host,
                         "client_lookup_dns_when_addrcallback_and_host_match_sets_host");
    opmock_register_test(client_send_when_no_source_sends_message,
                         "client_send_when_no_source_sends_message");
    opmock_register_test(client_send_when_source_sends_message_with_source,
                         "client_send_when_source_sends_message_with_source");
    opmock_register_test(client_process_read_buffer_when_null_result_continues,
                         "client_process_read_buffer_when_null_result_continues");
    opmock_register_test(client_process_read_buffer_when_command_not_found_frees_result,
                         "client_process_read_buffer_when_command_not_found_frees_result");
    opmock_register_test(client_process_read_buffer_when_handler_null_works_ok,
                         "client_process_read_buffer_when_handler_null_works_ok");
    opmock_register_test(client_process_read_buffer_when_handler_calls_handler,
                         "client_process_read_buffer_when_handler_calls_handler");
    opmock_register_test(client_process_read_buffer_when_no_access_does_not_call_handler,
                         "client_process_read_buffer_when_no_access_does_not_call_handler");
    opmock_register_test(client_process_read_buffer_when_too_few_args_does_not_call_handler,
                         "client_process_read_buffer_when_too_few_args_does_not_call_handler");
    opmock_register_test(client_set_nickname_when_null_client_returns_false,
                         "client_set_nickname_when_null_client_returns_false");
    opmock_register_test(client_set_nickname_when_null_nick_returns_false,
                         "client_set_nickname_when_null_nick_returns_false");
    opmock_register_test(client_set_nickname_when_called_sets_nickname,
                         "client_set_nickname_when_called_sets_nickname");
    opmock_register_test(client_set_nickname_when_too_long_truncates,
                         "client_set_nickname_when_too_long_truncates");
    opmock_register_test(client_set_username_when_null_client_returns_false,
                         "client_set_username_when_null_client_returns_false");
    opmock_register_test(client_set_username_when_null_username_returns_false,
                         "client_set_username_when_null_username_returns_false");
    opmock_register_test(client_set_username_when_called_sets_username,
                         "client_set_username_when_called_sets_username");
    opmock_register_test(client_set_username_when_too_long_truncates,
                         "client_set_username_when_too_long_truncates");
    opmock_register_test(client_set_realname_when_null_client_returns_false,
                         "client_set_realname_when_null_client_returns_false");
    opmock_register_test(client_set_realname_when_null_realname_returns_false,
                         "client_set_realname_when_null_realname_returns_false");
    opmock_register_test(client_set_realname_when_called_sets_realname,
                         "client_set_realname_when_called_sets_realname");
    opmock_register_test(client_set_realname_when_too_long_truncates,
                         "client_set_realname_when_too_long_truncates");
    opmock_register_test(client_get_nickname_when_null_nick_returns_null,
                         "client_get_nickname_when_null_nick_returns_null");
    opmock_register_test(client_get_nickname_when_empty_name_returns_star,
                         "client_get_nickname_when_empty_name_returns_star");
    opmock_register_test(client_get_nickname_when_name_returns_name,
                         "client_get_nickname_when_name_returns_name");

    opmock_test_suite_run();

    return opmock_test_error > 0;
}
