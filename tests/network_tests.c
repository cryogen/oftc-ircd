/*
 * Copyright (c) 2015, Stuart Walsh
 * All rights reserved.
 * network_tests.c unit tests for network functions
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

#include "network.h"
#include "uv_stub.h"

static void
network_address_from_ipstring_when_null_ip_returns_false()
{
    bool ret;

    ret = network_address_from_ipstring(NULL, NULL);

    OP_ASSERT_FALSE(ret);
    OP_VERIFY();
}

static void
network_address_from_ipstring_when_null_address_returns_false()
{
    bool ret;

    ret = network_address_from_ipstring("123.123.123.123", NULL);

    OP_ASSERT_FALSE(ret);
    OP_VERIFY();
}

static void
network_address_from_ipstring_when_v4fails_returns_false()
{
    NetworkAddress address;
    bool ret;

    uv_ip4_addr_ExpectAndReturn(NULL, 0, NULL, -1, NULL, NULL, NULL);

    ret = network_address_from_ipstring("123.123.123.123", &address);

    OP_ASSERT_FALSE(ret);
    OP_VERIFY();
}

static void
network_address_from_ipstring_when_dots_in_address_sets_v4()
{
    NetworkAddress address;
    bool ret;

    uv_ip4_addr_ExpectAndReturn(NULL, 0, NULL, 0, NULL, NULL, NULL);

    ret = network_address_from_ipstring("123.123.123.123", &address);

    OP_ASSERT_TRUE(ret);
    OP_ASSERT_EQUAL_INT(AF_INET, address.AddressFamily);
    OP_VERIFY();
}

static void
network_address_from_ipstring_when_v6fails_returns_false()
{
    NetworkAddress address;
    bool ret;

    uv_ip6_addr_ExpectAndReturn(NULL, 0, NULL, -1, NULL, NULL, NULL);

    ret = network_address_from_ipstring("::1", &address);

    OP_ASSERT_FALSE(ret);
    OP_VERIFY();
}

static void
network_address_from_ipstring_when_invalid_address_returns_false()
{
    NetworkAddress address;
    bool ret;

    ret = network_address_from_ipstring("invalid", &address);

    OP_ASSERT_FALSE(ret);
}

static void
network_address_from_ipstring_when_colons_in_address_sets_v6()
{
    NetworkAddress address;
    bool ret;

    uv_ip6_addr_ExpectAndReturn(NULL, 0, NULL, 0, NULL, NULL, NULL);

    ret = network_address_from_ipstring("::1", &address);

    OP_ASSERT_TRUE(ret);
    OP_ASSERT_EQUAL_INT(AF_INET6, address.AddressFamily);
    OP_VERIFY();
}

static void
network_ipstring_from_address_when_address_null_return_false()
{
    char host[256];
    bool ret;

    ret = network_ipstring_from_address(NULL, host, 256);

    OP_ASSERT_FALSE(ret);
    OP_VERIFY();
}

static void
network_ipstring_from_address_when_ipstr_null_return_false()
{
    NetworkAddress address;
    bool ret;

    ret = network_ipstring_from_address(&address, NULL, 256);

    OP_ASSERT_FALSE(ret);
    OP_VERIFY();
}

static void
network_ipstring_from_address_when_v4_and_fails_returns_false()
{
    NetworkAddress address;
    char host[256];
    bool ret;

    address.AddressFamily = AF_INET;

    uv_ip4_name_ExpectAndReturn(NULL, NULL, 0, -1, NULL, NULL, NULL);

    ret = network_ipstring_from_address(&address, host, 256);

    OP_ASSERT_FALSE(ret);
    OP_VERIFY();
}

static void
network_ipstring_from_address_when_v6_and_fails_returns_false()
{
    NetworkAddress address;
    char host[256];
    bool ret;

    address.AddressFamily = AF_INET6;

    uv_ip6_name_ExpectAndReturn(NULL, NULL, 0, -1, NULL, NULL, NULL);

    ret = network_ipstring_from_address(&address, host, 256);

    OP_ASSERT_FALSE(ret);
    OP_VERIFY();
}

static void
network_ipstring_from_address_when_unknown_family_returns_false()
{
    NetworkAddress address = { 0 };
    char host[256];
    bool ret;

    ret = network_ipstring_from_address(&address, host, 256);

    OP_ASSERT_FALSE(ret);
    OP_VERIFY();
}

static void
network_ipstring_from_address_when_v4ok_returns_true()
{
    NetworkAddress address;
    char host[256];
    bool ret;

    address.AddressFamily = AF_INET;

    uv_ip4_name_ExpectAndReturn(NULL, NULL, 0, 0, NULL, NULL, NULL);

    ret = network_ipstring_from_address(&address, host, 256);

    OP_ASSERT_TRUE(ret);
    OP_VERIFY();
}

static void
network_ipstring_from_address_when_v6ok_returns_true()
{
    NetworkAddress address;
    char host[256];
    bool ret;

    address.AddressFamily = AF_INET6;

    uv_ip6_name_ExpectAndReturn(NULL, NULL, 0, 0, NULL, NULL, NULL);

    ret = network_ipstring_from_address(&address, host, 256);

    OP_ASSERT_TRUE(ret);
    OP_VERIFY();
}

static void
network_address_from_ip_string_and_port_when_port_uses_port()
{
    NetworkAddress address;
    bool ret;

    uv_ip4_addr_ExpectAndReturn(NULL, 1234, NULL, 0, NULL, cmp_int, NULL);

    ret = network_address_from_ipstring_and_port("123.123.123.123", 1234,
                                                 &address);

    OP_ASSERT_TRUE(ret);
    OP_VERIFY();
}

static void
network_address_from_ip_string_and_port_when_v6port_uses_port()
{
    NetworkAddress address;
    bool ret;

    uv_ip6_addr_ExpectAndReturn(NULL, 1234, NULL, 0, NULL, cmp_int, NULL);

    ret = network_address_from_ipstring_and_port("::", 1234, &address);

    OP_ASSERT_TRUE(ret);
    OP_VERIFY();
}

static void
network_address_from_stream_when_stream_null_returns_false()
{
    bool ret;
    NetworkAddress address = { 0 };

    ret = network_address_from_stream(NULL, &address);

    OP_ASSERT_FALSE(ret);
}

static void
network_address_from_stream_when_address_null_returns_false()
{
    uv_tcp_t stream = { 0 };
    bool ret;

    ret = network_address_from_stream(&stream, NULL);

    OP_ASSERT_FALSE(ret);
}

static void
network_address_from_stream_when_sockname_fails_returns_false()
{
    uv_tcp_t stream = { 0 };
    NetworkAddress address = { 0 };
    bool ret;

    uv_tcp_getsockname_ExpectAndReturn(&stream, NULL, NULL, -1, cmp_ptr,
                                       NULL, NULL);

    ret = network_address_from_stream(&stream, &address);

    OP_ASSERT_FALSE(ret);
}

static int
setup_address(void *left, void *right, const char *name, char *message)
{
    struct sockaddr_in *addr = *(struct sockaddr_in **)right;

    addr->sin_addr.s_addr = inet_addr("127.0.0.1");
    addr->sin_len = sizeof(struct sockaddr_in);
    addr->sin_family = AF_INET;

    return 0;
}

static void
network_address_from_stream_when_succeeds_returns_true()
{
    uv_tcp_t stream = { 0 };
    NetworkAddress address = { 0 };
    bool ret;

    printf("%p\n", &address);

    uv_tcp_getsockname_ExpectAndReturn(&stream, NULL, NULL, 0, cmp_ptr,
                                       setup_address, NULL);

    ret = network_address_from_stream(&stream, &address);

    OP_ASSERT_TRUE(ret);
    OP_ASSERT_EQUAL_INT(AF_INET, address.AddressFamily);
    OP_ASSERT_EQUAL_CSTRING("127.0.0.1",
                            inet_ntoa(address.Address.Addr4.sin_addr));

    OP_VERIFY();
}

int
main()
{
    opmock_test_suite_reset();

    opmock_register_test(network_address_from_ipstring_when_null_ip_returns_false,
                         "network_address_from_ipstring_when_null_ip_returns_false");
    opmock_register_test(network_address_from_ipstring_when_null_address_returns_false,
                         "network_address_from_ipstring_when_null_address_returns_false");
    opmock_register_test(network_address_from_ipstring_when_v4fails_returns_false,
                         "network_address_from_ipstring_when_v4fails_returns_false");
    opmock_register_test(network_address_from_ipstring_when_dots_in_address_sets_v4,
                         "network_address_from_ipstring_when_dots_in_address_sets_v4");
    opmock_register_test(network_address_from_ipstring_when_v6fails_returns_false,
                         "network_address_from_ipstring_when_v6fails_returns_false");
    opmock_register_test(network_address_from_ipstring_when_invalid_address_returns_false,
                         "network_address_from_ipstring_when_invalid_address_returns_false");
    opmock_register_test(network_address_from_ipstring_when_colons_in_address_sets_v6,
                         "network_address_from_ipstring_when_colons_in_address_sets_v6");
    opmock_register_test(network_ipstring_from_address_when_address_null_return_false,
                         "network_ipstring_from_address_when_address_null_return_false");
    opmock_register_test(network_ipstring_from_address_when_ipstr_null_return_false,
                         "network_ipstring_from_address_when_ipstr_null_return_false");
    opmock_register_test(network_ipstring_from_address_when_v4_and_fails_returns_false,
                         "network_ipstring_from_address_when_v4_and_fails_returns_false");
    opmock_register_test(network_ipstring_from_address_when_v6_and_fails_returns_false,
                         "network_ipstring_from_address_when_v6_and_fails_returns_false");
    opmock_register_test(network_ipstring_from_address_when_unknown_family_returns_false,
                         "network_ipstring_from_address_when_unknown_family_returns_false");
    opmock_register_test(network_ipstring_from_address_when_v4ok_returns_true,
                         "network_ipstring_from_address_when_v4ok_returns_true");
    opmock_register_test(network_ipstring_from_address_when_v6ok_returns_true,
                         "network_ipstring_from_address_when_v6ok_returns_true");
    opmock_register_test(network_address_from_ip_string_and_port_when_port_uses_port,
                         "network_address_from_ip_string_and_port_when_port_uses_port");
    opmock_register_test(network_address_from_ip_string_and_port_when_v6port_uses_port,
                         "network_address_from_ip_string_and_port_when_v6port_uses_port");
    opmock_register_test(network_address_from_stream_when_stream_null_returns_false,
                         "network_address_from_stream_when_stream_null_returns_false");
    opmock_register_test(network_address_from_stream_when_address_null_returns_false,
                         "network_address_from_stream_when_address_null_returns_false");
    opmock_register_test(network_address_from_stream_when_sockname_fails_returns_false,
                         "network_address_from_stream_when_sockname_fails_returns_false");
    opmock_register_test(network_address_from_stream_when_succeeds_returns_true,
                         "network_address_from_stream_when_succeeds_returns_true");

    opmock_test_suite_run();

    return opmock_test_error > 0;
}
