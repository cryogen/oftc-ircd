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

#include "client.h"
#include "listener.h"
#include "network.h"

#include <stdlib.h>

static Client client;
static Client server;
static uv_stream_t handle;
static uv_tcp_t clienthandle;
static ClientDnsRequest dnsRequest;
static Listener listener = { 0 };
static uv_getnameinfo_t req;
static uv_getaddrinfo_t addrReq;
static bool callbackCalled;
static uv_write_t writeReq;
static char *buffer;
uv_buf_t uvBuf = { 0 };

static void
no_match_callback(ClientDnsRequest *request, bool match)
{
    callbackCalled = true;

    OP_ASSERT_FALSE(match);
    OP_ASSERT_EQUAL_CSTRING("123.123.123.123", request->Host);
}

static void
match_callback(ClientDnsRequest *request, bool match)
{
    callbackCalled = true;

    OP_ASSERT_TRUE(match);
    OP_ASSERT_EQUAL_CSTRING("Test.Test", request->Host);
}

static int
getsockname_mock(const uv_tcp_t *tcp,
                 struct sockaddr *addr,
                 int *addrLen,
                 int calls)
{
    NetworkAddress address;

    network_address_from_ipstring("123.123.123.123", &address);

    memcpy(addr, &address.Address, address.AddressLength);
    *addrLen = (int)address.AddressLength;

    return 0;
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
    struct sockaddr_in addr4;

    ClientDnsRequest *dns = request->data;

    dns->Callback = no_match_callback;

    addr.ai_addrlen = sizeof(addr4);

    addr4.sin_addr.s_addr = inet_addr("123.123.123.123");

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
    NetworkAddress address;

    ClientDnsRequest *dns = request->data;

    dns->Callback = match_callback;

    network_address_from_ipstring("123.123.123.123", &address);

    addr.ai_addr = (struct sockaddr *)&address.Address;

    callback(request, 0, &addr);

    return 0;
}

static int
uv_ip4_addr_callback(const char *ip,
                     int port,
                     struct sockaddr_in *addr,
                     int calls)
{
    memset(addr, 0, sizeof(struct sockaddr_in));

    addr->sin_family = AF_INET;
    inet_pton(AF_INET, ip, &addr->sin_addr);

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
    allocCallback((uv_handle_t *)stream, 1024, &uvBuf);

    readCallback(stream, -1, &uvBuf);

    return 0;
}

static int
uv_read_start_read_closed_callback(uv_stream_t *stream,
                                   uv_alloc_cb allocCallback,
                                   uv_read_cb readCallback,
                                   int calls)
{
    readCallback(stream, UV_EOF, &uvBuf);

    return 0;
}

static int
write_callback(uv_write_t *w,
               uv_stream_t *stream,
               const uv_buf_t *buf,
               unsigned int numBuf,
               uv_write_cb callback,
               int calls)
{
    buffer = strdup(buf[0].base);

    callback(w, 0);

    return 0;
}

static void
setup_stream(int acceptRet)
{
    memset(&client, 0, sizeof(client));
    memset(&handle, 0, sizeof(handle));
    memset(&clienthandle, 0, sizeof(clienthandle));
    memset(&listener, 0, sizeof(listener));

    Malloc_ExpectAndReturn(sizeof(uv_tcp_t), &clienthandle, cmp_int);
    uv_tcp_init_ExpectAndReturn(NULL, &clienthandle, 0, NULL, cmp_ptr);
    uv_accept_ExpectAndReturn(&handle, (uv_stream_t *)&clienthandle, acceptRet,
                              cmp_ptr, cmp_ptr);

    handle.data = &listener;
}

static void
setup_sockname()
{
    memset(&req, 0, sizeof(req));
    memset(&dnsRequest, 0, sizeof(dnsRequest));
    memset(&server, 0, sizeof(server));

    strncpy(server.Name, "test.server", sizeof(server.Name) - 1);

    server_get_this_server_ExpectAndReturn(&server);
    Malloc_ExpectAndReturn(sizeof(uv_write_t), &writeReq, cmp_int);
    uv_write_ExpectAndReturn(NULL, NULL, 0, 0, NULL, 0, NULL, NULL, NULL, NULL, NULL);

    Malloc_ExpectAndReturn(sizeof(ClientDnsRequest), &dnsRequest, cmp_int);
    uv_tcp_getsockname_MockWithCallback(getsockname_mock);
    uv_ip4_addr_MockWithCallback(uv_ip4_addr_callback);
    Malloc_ExpectAndReturn(sizeof(uv_getnameinfo_t), &req, cmp_int);
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
client_accept_when_called_with_null_client_returns_false()
{
    bool ret = client_accept(NULL, NULL);

    OP_ASSERT_FALSE(ret);

    OP_VERIFY();
}

static void
client_accept_when_called_with_null_handle_returns_false()
{
    bool ret = client_accept(&client, NULL);

    OP_ASSERT_FALSE(ret);

    OP_VERIFY();
}

static void
client_accept_when_uv_accept_fails_returns_false()
{
    setup_stream(-1);

    bool ret = client_accept(&client, &handle);

    OP_ASSERT_FALSE(ret);
    OP_VERIFY();
}

static void
client_accept_when_getsockname_fails_returns_false()
{
    setup_stream(0);

    uv_tcp_getsockname_ExpectAndReturn(&clienthandle, NULL, NULL, -1, cmp_ptr,
                                       NULL, NULL);

    bool ret = client_accept(&client, &handle);

    OP_ASSERT_FALSE(ret);
    OP_VERIFY();
}

static void
client_accept_when_getnameinfo_fails_returns_true()
{
    setup_stream(0);
    setup_sockname();

    uv_getnameinfo_ExpectAndReturn(NULL, &req, NULL, NULL, 0, -1, NULL, cmp_ptr,
                                   NULL, NULL, NULL);

    Free_ExpectAndReturn(&req, cmp_ptr);
    uv_read_start_ExpectAndReturn(NULL, NULL, NULL, -1, NULL, NULL, NULL);

    bool ret = client_accept(&client, &handle);

    OP_ASSERT_TRUE(ret);
}

static void
client_accept_when_getnameinfo_suceeds_returns_true()
{
    setup_stream(0);
    setup_sockname();

    uv_getnameinfo_ExpectAndReturn(NULL, &req, NULL, NULL, 0, 0, NULL, cmp_ptr,
                                   NULL, NULL, NULL);

    bool ret = client_accept(&client, &handle);

    OP_ASSERT_TRUE(ret);
}

static void
client_accept_when_namecallback_returns_bad_status_frees_request()
{
    setup_stream(0);
    setup_sockname();

    uv_getnameinfo_MockWithCallback(&getnameinfo_badstatus);

    server_get_this_server_ExpectAndReturn(&server);
    Malloc_ExpectAndReturn(sizeof(uv_write_t), &writeReq, cmp_int);
    uv_write_ExpectAndReturn(NULL, NULL, 0, 0, NULL, 0, NULL, NULL, NULL, NULL, NULL);

    uv_read_start_ExpectAndReturn(NULL, NULL, NULL, -1, NULL, NULL, NULL);
    Free_ExpectAndReturn(&req, cmp_ptr);

    bool ret = client_accept(&client, &handle);

    OP_ASSERT_TRUE(ret);
    OP_VERIFY();
}

static void
client_accept_when_namecallback_returns_good_status_getsaddress()
{
    setup_stream(0);
    setup_sockname();

    uv_getnameinfo_MockWithCallback(&getnameinfo_goodstatus);

    Malloc_ExpectAndReturn(sizeof(uv_getaddrinfo_t), &addrReq, cmp_int);
    uv_getaddrinfo_ExpectAndReturn(NULL, &addrReq, NULL, NULL, NULL, NULL, 0,
                                   NULL, cmp_ptr, NULL, NULL, NULL, NULL);

    Free_ExpectAndReturn(&req, cmp_ptr);

    bool ret = client_accept(&client, &handle);

    OP_ASSERT_TRUE(ret);
    OP_VERIFY();
}

static void
client_accept_when_addrcallback_returns_bad_status_frees_request()
{
    setup_stream(0);
    setup_sockname();

    uv_getnameinfo_MockWithCallback(&getnameinfo_goodstatus);

    Malloc_ExpectAndReturn(sizeof(uv_getaddrinfo_t), &addrReq, cmp_int);
    uv_getaddrinfo_MockWithCallback(getaddrinfo_badstatus);

    server_get_this_server_ExpectAndReturn(&server);
    Malloc_ExpectAndReturn(sizeof(uv_write_t), &writeReq, cmp_int);
    uv_write_ExpectAndReturn(NULL, NULL, 0, 0, NULL, 0, NULL, NULL, NULL, NULL, NULL);

    uv_read_start_ExpectAndReturn(NULL, NULL, NULL, -1, NULL, NULL, NULL);
    Free_ExpectAndReturn(&addrReq, cmp_ptr);
    Free_ExpectAndReturn(&req, cmp_ptr);

    bool ret = client_accept(&client, &handle);

    OP_ASSERT_TRUE(ret);
    OP_VERIFY();
}

static void
client_accept_when_addrcallback_and_no_host_match_sets_ip_as_host()
{
    setup_stream(0);
    setup_sockname();

    uv_getnameinfo_MockWithCallback(&getnameinfo_goodstatus);

    Malloc_ExpectAndReturn(sizeof(uv_getaddrinfo_t), &addrReq, cmp_int);
    uv_getaddrinfo_MockWithCallback(getaddrinfo_nomatch);

    uv_ip4_name_MockWithCallback(uv_ip4_name_callback);

    Free_ExpectAndReturn(&addrReq, cmp_ptr);
    Free_ExpectAndReturn(&req, cmp_ptr);

    callbackCalled = false;

    bool ret = client_accept(&client, &handle);

    OP_ASSERT_TRUE(ret);
    OP_ASSERT_TRUE(callbackCalled);
    OP_VERIFY();
}

static void
client_accept_when_addrcallback_and_host_match_sets_host()
{
    setup_stream(0);
    setup_sockname();

    uv_getnameinfo_MockWithCallback(&getnameinfo_goodstatus);

    Malloc_ExpectAndReturn(sizeof(uv_getaddrinfo_t), &addrReq, cmp_int);
    uv_getaddrinfo_MockWithCallback(getaddrinfo_match);

    uv_ip4_name_MockWithCallback(uv_ip4_name_callback);

    Free_ExpectAndReturn(&addrReq, cmp_ptr);
    Free_ExpectAndReturn(&req, cmp_ptr);


    bool ret = client_accept(&client, &handle);

    OP_ASSERT_TRUE(ret);
    OP_ASSERT_TRUE(callbackCalled);
    OP_VERIFY();
}

static void
client_on_buffer_alloc_cb_allocates_buffer()
{
    setup_stream(0);
    setup_sockname();

    uv_getnameinfo_MockWithCallback(&getnameinfo_badstatus);

    uv_read_start_MockWithCallback(uv_read_start_alloc_callback);
    Free_ExpectAndReturn(&req, cmp_ptr);

    client_accept(&client, &handle);
}

static void
client_on_read_when_error_closes_connection()
{
    setup_stream(0);
    setup_sockname();

    uv_getnameinfo_MockWithCallback(&getnameinfo_badstatus);

    uv_read_start_MockWithCallback(uv_read_start_read_fail_callback);
    Free_ExpectAndReturn(&req, cmp_ptr);

    client_accept(&client, &handle);
}

static void
client_on_read_when_connection_closed_closes_connection()
{
    setup_stream(0);
    setup_sockname();

    uv_getnameinfo_MockWithCallback(&getnameinfo_badstatus);

    uv_read_start_MockWithCallback(uv_read_start_read_closed_callback);
    Free_ExpectAndReturn(&req, cmp_ptr);

    client_accept(&client, &handle);
}

static void
client_send_when_no_source_sends_message()
{
    uv_write_MockWithCallback(write_callback);

    client_send(NULL, &client, "%s", "Test");

    OP_ASSERT_EQUAL_CSTRING("Test\r\n", buffer);

    free(buffer);
}

static void
client_send_when_source_sends_message_with_source()
{
    Client testServer = { 0 };

    strcpy(testServer.Name, "Test.Server");

    uv_write_MockWithCallback(write_callback);

    client_send(&testServer, &client, "%s", "Test");

    OP_ASSERT_EQUAL_CSTRING(":Test.Server Test\r\n", buffer);

    free(buffer);
}

static void
client_send_when_too_long_is_truncated()
{
    uv_write_MockWithCallback(write_callback);

    client_send(NULL, &client, "%s",
"1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890"
"1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890"
"1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890"
"1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890"
"1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890"
"123456789012bunnies");

    OP_ASSERT_EQUAL_CSTRING(
"1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890"
"1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890"
"1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890"
"1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890"
"1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890"
"1234567890\r\n", buffer);

    free(buffer);
}

static void
client_send_when_511_long_is_truncated()
{
    uv_write_MockWithCallback(write_callback);

    client_send(NULL, &client, "%s",
    "1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890"
    "1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890"
    "1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890"
    "1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890"
    "1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890"
    "12345678901");

    OP_ASSERT_EQUAL_CSTRING(
    "1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890"
    "1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890"
    "1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890"
    "1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890"
    "1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890"
    "1234567890\r\n", buffer);
    
    free(buffer);
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
    opmock_register_test(client_accept_when_called_with_null_client_returns_false,
                         "client_accept_when_called_with_null_client_returns_false");
    opmock_register_test(client_accept_when_called_with_null_handle_returns_false,
                         "client_accept_when_called_with_null_handle_returns_false");
    opmock_register_test(client_accept_when_uv_accept_fails_returns_false,
                         "client_accept_when_uv_accept_fails_returns_false");
    opmock_register_test(client_accept_when_getsockname_fails_returns_false,
                         "client_accept_when_getsockname_fails_returns_false");
    opmock_register_test(client_accept_when_getnameinfo_fails_returns_true,
                         "client_accept_when_getnameinfo_fails_returns_true");
    opmock_register_test(client_accept_when_getnameinfo_suceeds_returns_true,
                         "client_accept_when_getnameinfo_suceeds_returns_true");
    opmock_register_test(client_accept_when_namecallback_returns_bad_status_frees_request,
                         "client_accept_when_namecallback_returns_bad_status_frees_request");
    opmock_register_test(client_accept_when_namecallback_returns_good_status_getsaddress,
                         "client_accept_when_namecallback_returns_good_status_getsaddress");
    opmock_register_test(client_accept_when_addrcallback_returns_bad_status_frees_request,
                         "client_accept_when_addrcallback_returns_bad_status_frees_request");
    opmock_register_test(client_accept_when_addrcallback_and_no_host_match_sets_ip_as_host,
                         "client_accept_when_addrcallback_and_no_host_match_sets_ip_as_host");
    opmock_register_test(client_accept_when_addrcallback_and_host_match_sets_host,
                         "client_accept_when_addrcallback_and_host_match_sets_host");
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
    opmock_register_test(client_send_when_too_long_is_truncated,
                         "client_send_when_too_long_is_truncated");
    opmock_register_test(client_send_when_511_long_is_truncated,
                         "client_send_when_511_long_is_truncated");

    opmock_test_suite_run();

    return opmock_test_error > 0;
}
