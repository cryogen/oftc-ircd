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
static uv_buf_t UvBuf = { 0 };

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

    TestClient.handle = malloc(sizeof(TestClient.handle));
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
                       uv_getnameinfo_t* request,
                       uv_getnameinfo_cb getnameinfo_cb,
                       const struct sockaddr* addr,
                       int flags,
                       int calls)
{
    getnameinfo_cb(request, 0, "Test.Test", NULL);

    return 0;
}

static int
getnameinfo_badstatus(uv_loop_t* loop,
                      uv_getnameinfo_t* request,
                      uv_getnameinfo_cb getnameinfo_cb,
                      const struct sockaddr* addr,
                      int flags,
                      int calls)
{
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

static void
verify_alloc_test(uv_buf_t *buf)
{
    OP_ASSERT_EQUAL_INT(1024, (int)buf->len);
    OP_ASSERT_TRUE(buf->base != NULL);
}

static int
uv_read_start_alloc_callback(uv_stream_t *stream,
                             uv_alloc_cb allocCallback,
                             uv_read_cb readCallback,
                             int calls)
{
    uv_buf_t buf = { 0 };

    allocCallback((uv_handle_t *)stream, 1024, &buf);

    verify_alloc_test(&buf);

    return 0;
}

static int
uv_read_start_read_fail_callback(uv_stream_t *stream,
                                 uv_alloc_cb allocCallback,
                                 uv_read_cb readCallback,
                                 int calls)
{
    allocCallback((uv_handle_t *)stream, 1024, &UvBuf);

    readCallback(stream, -1, &UvBuf);

    return 0;
}

static int
uv_read_start_read_closed_callback(uv_stream_t *stream,
                                   uv_alloc_cb allocCallback,
                                   uv_read_cb readCallback,
                                   int calls)
{
    readCallback(stream, UV_EOF, &UvBuf);

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

    testClient->handle = calloc(1, sizeof(uv_handle_t));

    uv_close_ExpectAndReturn(NULL, NULL, NULL, NULL);
    Free_ExpectAndReturn(NULL, NULL);
    Free_ExpectAndReturn(testClient, cmp_ptr);

    client_free(testClient);

    OP_VERIFY();

    free(testClient->handle);
    free(testClient);
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

    uv_read_start_ExpectAndReturn(NULL, NULL, NULL, 0, NULL, NULL, NULL);
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

    uv_read_start_ExpectAndReturn(NULL, NULL, NULL, -1, NULL, NULL, NULL);
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

    uv_read_start_ExpectAndReturn(NULL, NULL, NULL, 0, NULL, NULL, NULL);
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

    uv_read_start_ExpectAndReturn(NULL, NULL, NULL, 0, NULL, NULL, NULL);
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

    uv_read_start_ExpectAndReturn(NULL, NULL, NULL, 0, NULL, NULL, NULL);
    Free_ExpectAndReturn(NULL, NULL);

    Free_ExpectAndReturn(&AddressRequest, cmp_ptr);
    Free_ExpectAndReturn(&NameRequest, cmp_ptr);


    client_lookup_dns(&TestClient);

    OP_VERIFY();
}

static void
client_on_buffer_alloc_cb_allocates_buffer()
{
    setup_dns();

    uv_getnameinfo_MockWithCallback(&getnameinfo_badstatus);

    uv_read_start_MockWithCallback(uv_read_start_alloc_callback);
    Free_ExpectAndReturn(&NameRequest, cmp_ptr);

    client_lookup_dns(&TestClient);
}

static void
client_on_read_when_error_closes_connection()
{
    setup_dns();

    uv_getnameinfo_MockWithCallback(&getnameinfo_badstatus);

    uv_read_start_MockWithCallback(uv_read_start_read_fail_callback);
    Free_ExpectAndReturn(&NameRequest, cmp_ptr);

    client_lookup_dns(&TestClient);
}

static void
client_on_read_when_connection_closed_closes_connection()
{
    setup_dns();

    uv_getnameinfo_MockWithCallback(&getnameinfo_badstatus);

    uv_read_start_MockWithCallback(uv_read_start_read_closed_callback);
    Free_ExpectAndReturn(&NameRequest, cmp_ptr);

    client_lookup_dns(&TestClient);
}

static void
client_send_when_no_source_sends_message()
{
    connection_send_ExpectAndReturn(&TestClient, "Test", cmp_ptr, cmp_cstr);

    client_send(NULL, &TestClient, "%s", "Test");

    OP_VERIFY();
}

static void
client_send_when_source_sends_message_with_source()
{
    Client testServer = { 0 };

    strcpy(testServer.Name, "Test.Server");

    connection_send_ExpectAndReturn(&TestClient, ":Test.Server Test",
                                    cmp_ptr, cmp_cstr);

    client_send(&testServer, &TestClient, "%s", "Test");

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

    vector_length_ExpectAndReturn(NULL, 0, NULL);
    parser_result_free_ExpectAndReturn(&Result, cmp_ptr);
    parser_get_line_ExpectAndReturn(NULL, NULL, 0, NULL, NULL, NULL, NULL);

    callback_called = false;
    ResultCommand.Handler = handler_callback;
    ResultCommand.MinParams = 1;

    client_process_read_buffer(&client);

    OP_ASSERT_FALSE(callback_called);
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
    opmock_register_test(client_lookup_dns_when_getnameinfo_fails_sets_ip_as_host,
                         "client_lookup_dns_when_getnameinfo_fails_sets_ip_as_host");
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
    opmock_register_test(client_on_buffer_alloc_cb_allocates_buffer,
                         "client_on_buffer_alloc_cb_allocates_buffer");
    opmock_register_test(client_on_read_when_error_closes_connection,
                         "client_on_read_when_error_closes_connection");
    opmock_register_test(client_on_read_when_connection_closed_closes_connection,
                         "client_on_read_when_connection_closed_closes_connection");
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

    opmock_test_suite_run();

    return opmock_test_error > 0;
}
