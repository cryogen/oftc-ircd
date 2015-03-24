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

void
network_address_from_ipstring_when_null_ip_returns_false()
{
    bool ret;

    ret = network_address_from_ipstring(NULL, NULL);

    OP_ASSERT_FALSE(ret);
    OP_VERIFY();
}

void
network_address_from_ipstring_when_null_address_returns_false()
{
    bool ret;

    ret = network_address_from_ipstring("123.123.123.123", NULL);

    OP_ASSERT_FALSE(ret);
    OP_VERIFY();
}

void
network_address_from_ipstring_when_v4fails_returns_false()
{
    NetworkAddress address;
    bool ret;

    uv_ip4_addr_ExpectAndReturn(NULL, 0, NULL, -1, NULL, NULL, NULL);

    ret = network_address_from_ipstring("123.123.123.123", &address);

    OP_ASSERT_FALSE(ret);
    OP_VERIFY();
}

void
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

void
network_address_from_ipstring_when_v6fails_returns_false()
{
    NetworkAddress address;
    bool ret;

    uv_ip6_addr_ExpectAndReturn(NULL, 0, NULL, -1, NULL, NULL, NULL);

    ret = network_address_from_ipstring("::1", &address);

    OP_ASSERT_FALSE(ret);
    OP_VERIFY();
}

void
network_address_from_ipstring_when_invalid_address_returns_false()
{
    NetworkAddress address;
    bool ret;

    ret = network_address_from_ipstring("invalid", &address);

    OP_ASSERT_FALSE(ret);
}

void
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

int
main()
{
    opmock_test_suite_reset();

    opmock_register_test(network_address_from_ipstring_when_null_ip_returns_false,
                         "network_address_from_ipstring_when_null_ip_returns_false");
    opmock_register_test(network_address_from_ipstring_when_null_address_returns_false, "network_address_from_ipstring_when_null_address_returns_false");
    opmock_register_test(network_address_from_ipstring_when_v4fails_returns_false,
                         "network_address_from_ipstring_when_v4fails_returns_false");
    opmock_register_test(network_address_from_ipstring_when_dots_in_address_sets_v4, "network_address_from_ipstring_when_dots_in_address_sets_v4");
    opmock_register_test(network_address_from_ipstring_when_v6fails_returns_false, "network_address_from_ipstring_when_v6fails_returns_false");
    opmock_register_test(network_address_from_ipstring_when_invalid_address_returns_false, "network_address_from_ipstring_when_invalid_address_returns_false");
    opmock_register_test(network_address_from_ipstring_when_colons_in_address_sets_v6, "network_address_from_ipstring_when_colons_in_address_sets_v6");

    opmock_test_suite_run();

    return opmock_test_error > 0;
}