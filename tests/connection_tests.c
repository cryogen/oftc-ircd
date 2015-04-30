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

#include "connection.h"

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

int main()
{
    opmock_test_suite_reset();

    opmock_register_test(connection_accept_when_called_with_null_handle_returns,
                         "connection_accept_when_called_with_null_handle_returns");
    opmock_register_test(connection_accept_when_uv_accept_fails_returns,
                         "connection_accept_when_uv_accept_fails_returns");
    opmock_register_test(connection_accept_when_get_address_fails_returns,
                         "connection_accept_when_get_address_fails_returns");
    opmock_register_test(connection_send_when_too_long_is_truncated,
                         "connection_send_when_too_long_is_truncated");
    opmock_register_test(connection_send_when_511_long_is_truncated,
                         "connection_send_when_511_long_is_truncated");

    opmock_test_suite_run();

    return opmock_test_error > 0;
}
