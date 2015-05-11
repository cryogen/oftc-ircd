/*
 * Copyright (c) 2015, Stuart Walsh
 * All rights reserved.
 * connection_tests.c connection tests
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
#include "client_stub.h"
#include "uv_stub.h"
#include "serverstate_stub.h"
#include "network_stub.h"
#include "config_stub.h"
#include "tls_stub.h"
#include "json_object_stub.h"
#include "buffer_stub.h"

#include "connection.h"
#include "listener.h"

static uv_tcp_t Handle;
static char *SendBuffer;
static Client TestClient;

static void
setup_handle()
{
    Malloc_ExpectAndReturn(sizeof(uv_tcp_t), &Handle, cmp_int);
    serverstate_get_event_loop_ExpectAndReturn(NULL);
    uv_tcp_init_ExpectAndReturn(NULL, &Handle, 0, NULL, cmp_ptr);
}

static int
write_callback(uv_write_t *w,
               uv_stream_t *stream,
               const uv_buf_t *buf,
               unsigned int numBuf,
               uv_write_cb callback,
               int calls)
{
    SendBuffer = strdup(buf[0].base);

    callback(w, 0);

    return 0;
}

static int
call_setter(void *left, void *right, const char *name, char *message)
{
    ConfigFieldHandler handler = *(ConfigFieldHandler *)right;

    handler(NULL, NULL);

    return 0;
}

static void
connection_init_when_called_sets_up_config()
{
    config_register_section_ExpectAndReturn("connection", false, NULL,
                                            cmp_cstr, cmp_byte);
    config_register_field_ExpectAndReturn(NULL, "privatekey", json_type_string,
                                          NULL, NULL, cmp_cstr, cmp_int,
                                          call_setter);

    json_object_get_string_ExpectAndReturn(NULL, "KEY", NULL);

    config_register_field_ExpectAndReturn(NULL, "certificatefile",
                                          json_type_string, NULL, NULL,
                                          cmp_cstr, cmp_int, call_setter);

    json_object_get_string_ExpectAndReturn(NULL, "CERT", NULL);

    connection_init();

    OP_VERIFY();
}

static void
connection_init_tls_when_server_configure_fails_logs_error()
{
    tls_init_ExpectAndReturn(0);
    tls_config_new_ExpectAndReturn(NULL);
    tls_server_ExpectAndReturn(NULL);
    tls_client_ExpectAndReturn(NULL);
    tls_config_set_key_file_ExpectAndReturn(NULL, NULL, 0, NULL, NULL);
    tls_config_set_cert_file_ExpectAndReturn(NULL, NULL, 0, NULL, NULL);
    tls_config_insecure_noverifycert_ExpectAndReturn(NULL, NULL);
    tls_configure_ExpectAndReturn(NULL, NULL, -1, NULL, NULL);
    tls_error_ExpectAndReturn(NULL, "Error", NULL);
    tls_configure_ExpectAndReturn(NULL, NULL, 0, NULL, NULL);
    connection_init_tls();

    OP_VERIFY();
}

static void
connection_init_tls_when_client_configure_fails_logs_error()
{
    tls_init_ExpectAndReturn(0);
    tls_config_new_ExpectAndReturn(NULL);
    tls_server_ExpectAndReturn(NULL);
    tls_client_ExpectAndReturn(NULL);
    tls_config_set_key_file_ExpectAndReturn(NULL, NULL, 0, NULL, NULL);
    tls_config_set_cert_file_ExpectAndReturn(NULL, NULL, 0, NULL, NULL);
    tls_config_insecure_noverifycert_ExpectAndReturn(NULL, NULL);
    tls_configure_ExpectAndReturn(NULL, NULL, 0, NULL, NULL);
    tls_configure_ExpectAndReturn(NULL, NULL, -1, NULL, NULL);
    tls_error_ExpectAndReturn(NULL, "Client Configure Error", NULL);

    connection_init_tls();

    OP_VERIFY();
}

static void
connection_init_tls_when_success_returns_ok()
{
    tls_init_ExpectAndReturn(0);
    tls_config_new_ExpectAndReturn(NULL);
    tls_server_ExpectAndReturn(NULL);
    tls_client_ExpectAndReturn(NULL);
    tls_config_set_key_file_ExpectAndReturn(NULL, NULL, 0, NULL, NULL);
    tls_config_set_cert_file_ExpectAndReturn(NULL, NULL, 0, NULL, NULL);
    tls_config_insecure_noverifycert_ExpectAndReturn(NULL, NULL);
    tls_configure_ExpectAndReturn(NULL, NULL, 0, NULL, NULL);
    tls_configure_ExpectAndReturn(NULL, NULL, 0, NULL, NULL);

    connection_init_tls();

    OP_VERIFY();
}

static void
connection_accept_when_called_with_null_handle_returns()
{
    connection_accept(NULL);

    OP_VERIFY();
}

static void
connection_accept_when_uv_accept_fails_returns()
{
    setup_handle();

    uv_accept_ExpectAndReturn(NULL, NULL, -1, NULL, NULL);
    Free_ExpectAndReturn(&Handle, cmp_ptr);

    connection_accept((uv_stream_t *)&Handle);

    OP_VERIFY();
}

static void
connection_accept_when_get_address_fails_returns()
{
    setup_handle();

    uv_accept_ExpectAndReturn(NULL, NULL, 0, NULL, NULL);
    network_address_from_stream_ExpectAndReturn(&Handle, NULL, false, cmp_ptr,
                                                NULL);
    uv_close_ExpectAndReturn((uv_handle_t *)&Handle, NULL, cmp_ptr, NULL);
    Free_ExpectAndReturn(&Handle, cmp_ptr);

    connection_accept((uv_stream_t *)&Handle);

    OP_VERIFY();
}

static void
connection_accept_when_success_starts_dns_lookup()
{
    Listener listener = { 0 };
    setup_handle();

    Handle.data = &listener;

    uv_accept_ExpectAndReturn(NULL, NULL, 0, NULL, NULL);
    network_address_from_stream_ExpectAndReturn(&Handle, NULL, true, cmp_ptr,
                                                NULL);

    client_new_ExpectAndReturn(&TestClient);

    client_lookup_dns_ExpectAndReturn(NULL, NULL);

    connection_accept((uv_stream_t *)&Handle);

    OP_VERIFY();
}

static void
connection_accept_when_tls_handshake_fails_return()
{
    Listener listener = { 0 };
    setup_handle();

    listener.IsTls = true;

    Handle.data = &listener;

    uv_accept_ExpectAndReturn(NULL, NULL, 0, NULL, NULL);
    network_address_from_stream_ExpectAndReturn(&Handle, NULL, true, cmp_ptr,
                                                NULL);

    client_new_ExpectAndReturn(&TestClient);
    uv_fileno_ExpectAndReturn(NULL, NULL, 0, NULL, NULL);
    tls_accept_socket_ExpectAndReturn(NULL, NULL, 0, -1, NULL, NULL, NULL);
    client_free_ExpectAndReturn(&TestClient, cmp_ptr);

    connection_accept((uv_stream_t *)&Handle);

    OP_VERIFY();
}

static void
connection_accept_when_uv_fileno_fails_returns()
{
    Listener listener = { 0 };
    setup_handle();

    listener.IsTls = true;

    Handle.data = &listener;

    uv_accept_ExpectAndReturn(NULL, NULL, 0, NULL, NULL);
    network_address_from_stream_ExpectAndReturn(&Handle, NULL, true, cmp_ptr,
                                                NULL);

    client_new_ExpectAndReturn(&TestClient);
    uv_fileno_ExpectAndReturn(NULL, NULL, -1, NULL, NULL);
    client_free_ExpectAndReturn(&TestClient, cmp_ptr);

    connection_accept((uv_stream_t *)&Handle);
    
    OP_VERIFY();
}

static void
connection_accept_when_tls_wants_read_calls_again()
{
    Listener listener = { 0 };
    setup_handle();

    listener.IsTls = true;

    Handle.data = &listener;

    uv_accept_ExpectAndReturn(NULL, NULL, 0, NULL, NULL);
    network_address_from_stream_ExpectAndReturn(&Handle, NULL, true, cmp_ptr,
                                                NULL);

    client_new_ExpectAndReturn(&TestClient);
    uv_fileno_ExpectAndReturn(NULL, NULL, 0, NULL, NULL);
    tls_accept_socket_ExpectAndReturn(NULL, NULL, 0, TLS_READ_AGAIN, NULL, NULL, NULL);
    tls_accept_socket_ExpectAndReturn(NULL, NULL, 0, -1, NULL, NULL, NULL);
    client_free_ExpectAndReturn(&TestClient, cmp_ptr);

    connection_accept((uv_stream_t *)&Handle);
    
    OP_VERIFY();
}

static void
connection_accept_when_tls_wants_write_calls_again()
{
    Listener listener = { 0 };
    setup_handle();

    listener.IsTls = true;

    Handle.data = &listener;

    uv_accept_ExpectAndReturn(NULL, NULL, 0, NULL, NULL);
    network_address_from_stream_ExpectAndReturn(&Handle, NULL, true, cmp_ptr,
                                                NULL);

    client_new_ExpectAndReturn(&TestClient);
    uv_fileno_ExpectAndReturn(NULL, NULL, 0, NULL, NULL);
    tls_accept_socket_ExpectAndReturn(NULL, NULL, 0, TLS_WRITE_AGAIN, NULL, NULL, NULL);
    tls_accept_socket_ExpectAndReturn(NULL, NULL, 0, -1, NULL, NULL, NULL);
    client_free_ExpectAndReturn(&TestClient, cmp_ptr);

    connection_accept((uv_stream_t *)&Handle);

    OP_VERIFY();
}

static void
connection_accept_when_tls_succeeds_looksup_dns()
{
    Listener listener = { 0 };
    setup_handle();

    listener.IsTls = true;

    Handle.data = &listener;

    uv_accept_ExpectAndReturn(NULL, NULL, 0, NULL, NULL);
    network_address_from_stream_ExpectAndReturn(&Handle, NULL, true, cmp_ptr,
                                                NULL);

    client_new_ExpectAndReturn(&TestClient);
    uv_fileno_ExpectAndReturn(NULL, NULL, 0, NULL, NULL);
    tls_accept_socket_ExpectAndReturn(NULL, NULL, 0, 0, NULL, NULL, NULL);
    tls_get_cert_fingerprint_ExpectAndReturn(NULL, NULL, 0, 0, NULL, NULL, NULL);
    client_lookup_dns_ExpectAndReturn(NULL, NULL);

    connection_accept((uv_stream_t *)&Handle);
    
    OP_VERIFY();
}

static void
connection_send_when_tls_sends_via_tls()
{
    char testBuffer[2048] = { 0 };

    memcpy(testBuffer, "TEST", 4);

    TestClient.TlsContext = malloc(100);

    tls_write_ExpectAndReturn(NULL, NULL, 0, NULL, 0, NULL, NULL, NULL, NULL);

    connection_send(&TestClient, testBuffer);

    free(TestClient.TlsContext);

    TestClient.TlsContext = NULL;

    OP_VERIFY();
}


static void
connection_send_when_too_long_is_truncated()
{
    char testBuffer[2048] = { 0 };
    char expected[2048] = { 0 };

    uv_write_MockWithCallback(write_callback);

    strcpy(testBuffer,
    "1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890"
    "1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890"
    "1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890"
    "1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890"
    "1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890"
    "123456789012bunnies");
    strcpy(expected,
    "1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890"
    "1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890"
    "1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890"
    "1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890"
    "1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890"
    "1234567890\r\n");

    connection_send(&TestClient, testBuffer);

    OP_ASSERT_EQUAL_CSTRING(expected, SendBuffer);

    free(SendBuffer);
}

static void
connection_send_when_511_long_is_truncated()
{
    char testBuffer[2048] = { 0 };

    uv_write_MockWithCallback(write_callback);

    strcpy(testBuffer,
    "1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890"
    "1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890"
    "1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890"
    "1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890"
    "1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890"
           "12345678901");

    connection_send(&TestClient, testBuffer);

    OP_ASSERT_EQUAL_CSTRING(
    "1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890"
    "1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890"
    "1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890"
    "1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890"
    "1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890"
    "1234567890\r\n", SendBuffer);
    
    free(SendBuffer);
}

static int
call_alloc_callback(void *left, void *right, const char *name, char *message)
{
    uv_buf_t buf = { 0 };
    size_t allocSize = 1024;

    uv_alloc_cb alloc = *(uv_alloc_cb *)right;

    alloc(NULL, allocSize, &buf);

    if(buf.len != allocSize)
    {
        snprintf(message, OP_MATCHER_MESSAGE_LENGTH,
                 "Expected buffer length to be %ld, actually was %ld",
                 allocSize, buf.len);
        return -1;
    }

    return 0;
}

static void
connection_allocate_buffer_callback_when_calls_allocs_buffer()
{
    uv_read_start_ExpectAndReturn(NULL, NULL, NULL, 0, NULL,
                                  call_alloc_callback, NULL);
    Malloc_ExpectAndReturn(1024, NULL, cmp_int);

    connection_start_read(&TestClient);

    OP_VERIFY();
}

static int nRead;
static uv_buf_t UvBuf;

static int
call_read_callback(void *left, void *right, const char *name, char *message)
{
    uv_read_cb read = *(uv_read_cb *)right;

    read((uv_stream_t *)TestClient.handle, nRead, &UvBuf);

    return 0;
}

static void
connection_on_read_callback_when_eof_closes_connection()
{
    nRead = UV_EOF;

    uv_read_start_ExpectAndReturn(NULL, NULL, NULL, 0, NULL, NULL,
                                  call_read_callback);
    client_free_ExpectAndReturn(&TestClient, cmp_ptr);

    connection_start_read(&TestClient);

    OP_VERIFY();
}

static void
connection_on_read_callback_when_error_closes_connection()
{
    nRead = -1;

    uv_read_start_ExpectAndReturn(NULL, NULL, NULL, 0, NULL, NULL,
                                  call_read_callback);
    client_free_ExpectAndReturn(&TestClient, cmp_ptr);

    connection_start_read(&TestClient);

    OP_VERIFY();
}

static void
connection_on_read_callback_when_succeeds_gets_data()
{
    nRead = 0;

    uv_read_start_ExpectAndReturn(NULL, NULL, NULL, 0, NULL, NULL,
                                  call_read_callback);
    buffer_add_ExpectAndReturn(NULL, NULL, 0, NULL, NULL, NULL);
    client_process_read_buffer_ExpectAndReturn(NULL, NULL);
    Free_ExpectAndReturn(NULL, NULL);

    connection_start_read(&TestClient);

    OP_VERIFY();
}

uv_poll_t PollHandle;
static int PollStatus;

static int
call_poll_callback(void *left, void *right, const char *name, char *message)
{
    uv_poll_cb poll = *(uv_poll_cb *)right;

    poll(&PollHandle, PollStatus, UV_READABLE);
    return 0;
}

static void
connection_poll_callback_when_bad_status_returns()
{
    TestClient.TlsContext = (struct tls*)0x12345678;

    PollStatus = -1;

    Malloc_ExpectAndReturn(sizeof(uv_poll_t), &PollHandle, cmp_int);
    uv_fileno_ExpectAndReturn(NULL, NULL, 1, NULL, NULL);
    serverstate_get_event_loop_ExpectAndReturn(NULL);
    uv_poll_init_ExpectAndReturn(NULL, NULL, 1, 0, NULL, NULL, NULL);
    uv_poll_start_ExpectAndReturn(&PollHandle, UV_READABLE, NULL, 0, cmp_ptr,
                                  cmp_int, call_poll_callback);

    client_free_ExpectAndReturn(&TestClient, cmp_ptr);

    connection_start_read(&TestClient);

    OP_VERIFY();
}

static void
connection_poll_callback_when_tls_needs_read_calls_again()
{
    TestClient.TlsContext = (struct tls*)0x12345678;

    PollStatus = 0;

    Malloc_ExpectAndReturn(sizeof(uv_poll_t), &PollHandle, cmp_int);
    uv_fileno_ExpectAndReturn(NULL, NULL, 1, NULL, NULL);
    serverstate_get_event_loop_ExpectAndReturn(NULL);
    uv_poll_init_ExpectAndReturn(NULL, NULL, 1, 0, NULL, NULL, NULL);
    uv_poll_start_ExpectAndReturn(&PollHandle, UV_READABLE, NULL, 0, cmp_ptr,
                                  cmp_int, call_poll_callback);
    Malloc_ExpectAndReturn(0, NULL, NULL);
    tls_read_ExpectAndReturn(NULL, NULL, 0, NULL, TLS_READ_AGAIN, NULL,
                             NULL, NULL, NULL);
    tls_read_ExpectAndReturn(NULL, NULL, 0, NULL, 0, NULL,
                             NULL, NULL, NULL);

    buffer_add_ExpectAndReturn(NULL, NULL, 0, NULL, NULL, NULL);
    client_process_read_buffer_ExpectAndReturn(NULL, NULL);
    Free_ExpectAndReturn(NULL, NULL);

    connection_start_read(&TestClient);

    OP_VERIFY();
}

static void
connection_poll_callback_when_tls_needs_write_calls_again()
{
    TestClient.TlsContext = (struct tls*)0x12345678;

    PollStatus = 0;

    Malloc_ExpectAndReturn(sizeof(uv_poll_t), &PollHandle, cmp_int);
    uv_fileno_ExpectAndReturn(NULL, NULL, 1, NULL, NULL);
    serverstate_get_event_loop_ExpectAndReturn(NULL);
    uv_poll_init_ExpectAndReturn(NULL, NULL, 1, 0, NULL, NULL, NULL);
    uv_poll_start_ExpectAndReturn(&PollHandle, UV_READABLE, NULL, 0, cmp_ptr,
                                  cmp_int, call_poll_callback);
    Malloc_ExpectAndReturn(0, NULL, NULL);
    tls_read_ExpectAndReturn(NULL, NULL, 0, NULL, TLS_WRITE_AGAIN, NULL,
                             NULL, NULL, NULL);
    tls_read_ExpectAndReturn(NULL, NULL, 0, NULL, 0, NULL,
                             NULL, NULL, NULL);

    buffer_add_ExpectAndReturn(NULL, NULL, 0, NULL, NULL, NULL);
    client_process_read_buffer_ExpectAndReturn(NULL, NULL);
    Free_ExpectAndReturn(NULL, NULL);

    connection_start_read(&TestClient);

    OP_VERIFY();
}

static void
connection_poll_callback_when_tls_fails_returns()
{
    TestClient.TlsContext = (struct tls*)0x12345678;

    PollStatus = 0;

    Malloc_ExpectAndReturn(sizeof(uv_poll_t), &PollHandle, cmp_int);
    uv_fileno_ExpectAndReturn(NULL, NULL, 1, NULL, NULL);
    serverstate_get_event_loop_ExpectAndReturn(NULL);
    uv_poll_init_ExpectAndReturn(NULL, NULL, 1, 0, NULL, NULL, NULL);
    uv_poll_start_ExpectAndReturn(&PollHandle, UV_READABLE, NULL, 0, cmp_ptr,
                                  cmp_int, call_poll_callback);
    Malloc_ExpectAndReturn(0, NULL, NULL);
    tls_read_ExpectAndReturn(NULL, NULL, 0, NULL, -1, NULL,
                             NULL, NULL, NULL);
    client_free_ExpectAndReturn(&TestClient, cmp_ptr);

    connection_start_read(&TestClient);

    OP_VERIFY();
}

static void
connection_start_read_when_null_client_returns()
{
    connection_start_read(NULL);

    OP_VERIFY();
}

static void
connection_start_when_read_fails_returns()
{
    TestClient.TlsContext = NULL;
    
    uv_read_start_ExpectAndReturn(NULL, NULL, NULL, -1, NULL, NULL, NULL);
    client_free_ExpectAndReturn(&TestClient, cmp_ptr);

    connection_start_read(&TestClient);

    OP_VERIFY();
}

static void
connection_start_when_poll_fails_returns()
{
    TestClient.TlsContext = (struct tls *)0x12345678;

    Malloc_ExpectAndReturn(0, &PollHandle, NULL);
    uv_fileno_ExpectAndReturn(NULL, NULL, 1, NULL, NULL);
    serverstate_get_event_loop_ExpectAndReturn(NULL);
    uv_poll_init_ExpectAndReturn(NULL, NULL, 0, 0, NULL, NULL, NULL);
    uv_poll_start_ExpectAndReturn(NULL, 0, NULL, -1, NULL, NULL, NULL);
    client_free_ExpectAndReturn(&TestClient, cmp_ptr);

    connection_start_read(&TestClient);

    OP_VERIFY();
}

int main()
{
    opmock_test_suite_reset();

    opmock_register_test(connection_init_when_called_sets_up_config,
                         "connection_init_when_called_sets_up_config");
    opmock_register_test(connection_accept_when_called_with_null_handle_returns,
                         "connection_accept_when_called_with_null_handle_returns");
    opmock_register_test(connection_init_tls_when_server_configure_fails_logs_error,
                         "connection_init_tls_when_server_configure_fails_logs_error");
    opmock_register_test(connection_init_tls_when_client_configure_fails_logs_error,
                         "connection_init_tls_when_client_configure_fails_logs_error");
    opmock_register_test(connection_init_tls_when_success_returns_ok,
                         "connection_init_tls_when_success_returns_ok");
    opmock_register_test(connection_accept_when_uv_accept_fails_returns,
                         "connection_accept_when_uv_accept_fails_returns");
    opmock_register_test(connection_accept_when_get_address_fails_returns,
                         "connection_accept_when_get_address_fails_returns");
    opmock_register_test(connection_accept_when_success_starts_dns_lookup,
                         "connection_accept_when_success_starts_dns_lookup");
    opmock_register_test(connection_accept_when_tls_handshake_fails_return,
                         "connection_accept_when_tls_handshake_fails_return");
    opmock_register_test(connection_accept_when_uv_fileno_fails_returns,
                         "connection_accept_when_uv_fileno_fails_returns");
    opmock_register_test(connection_accept_when_tls_wants_read_calls_again,
                         "connection_accept_when_tls_wants_read_calls_again");
    opmock_register_test(connection_accept_when_tls_wants_write_calls_again,
                         "connection_accept_when_tls_wants_write_calls_again");
    opmock_register_test(connection_accept_when_tls_succeeds_looksup_dns,
                         "connection_accept_when_tls_succeeds_looksup_dns");
    opmock_register_test(connection_send_when_tls_sends_via_tls,
                         "conneciton_send_when_tls_sends_via_tls");
    opmock_register_test(connection_send_when_too_long_is_truncated,
                         "connection_send_when_too_long_is_truncated");
    opmock_register_test(connection_send_when_511_long_is_truncated,
                         "connection_send_when_511_long_is_truncated");
    opmock_register_test(connection_allocate_buffer_callback_when_calls_allocs_buffer,
                         "connection_allocate_buffer_callback_when_calls_allocs_buffer");
    opmock_register_test(connection_on_read_callback_when_eof_closes_connection,
                         "connection_on_read_callback_when_eof_closes_connection");
    opmock_register_test(connection_on_read_callback_when_error_closes_connection,
                         "connection_on_read_callback_when_error_closes_connection");
    opmock_register_test(connection_on_read_callback_when_succeeds_gets_data,
                         "connection_on_read_callback_when_succeeds_gets_data");
    opmock_register_test(connection_poll_callback_when_bad_status_returns,
                         "connection_poll_callback_when_bad_status_returns");
    opmock_register_test(connection_poll_callback_when_tls_needs_read_calls_again,
                         "connection_poll_callback_when_tls_needs_read_calls_again");
    opmock_register_test(connection_poll_callback_when_tls_fails_returns,
                         "connection_poll_callback_when_tls_fails_returns");
    opmock_register_test(connection_poll_callback_when_tls_needs_write_calls_again,
                         "connection_poll_callback_when_tls_needs_write_calls_again");
    opmock_register_test(connection_start_read_when_null_client_returns,
                         "connection_start_read_when_null_client_returns");
    opmock_register_test(connection_start_when_read_fails_returns,
                         "connection_start_when_read_fails_returns");
    opmock_register_test(connection_start_when_poll_fails_returns,
                         "connection_start_when_poll_fails_returns");

    opmock_test_suite_run();

    return opmock_test_error > 0;
}
