/*
 * Copyright (c) 2014, Stuart Walsh
 * All rights reserved.
 * network.c network utility functions
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

#include "network.h"

#include <uv.h>
#include <stdio.h>
#include <string.h>

bool
network_address_from_ipstring(const char *ip, NetworkAddress *address)
{
    return network_address_from_ipstring_and_port(ip, 0, address);
}

bool
network_address_from_ipstring_and_port(const char *ip,
                                       unsigned short port,
                                       NetworkAddress *address)
{
    if(ip == NULL || address == NULL)
    {
        return false;
    }

    if(strstr(ip, ".") != NULL)
    {
        if(uv_ip4_addr(ip, port, &address->Address.Addr4) != 0)
        {
            return false;
        }

        address->AddressFamily = AF_INET;
        address->AddressLength = sizeof(struct sockaddr_in);
    }
    else if(strstr(ip, ":") != NULL)
    {
        if(uv_ip6_addr(ip, port, &address->Address.Addr6) != 0)
        {
            return false;
        }

        address->AddressFamily = AF_INET6;
        address->AddressLength = sizeof(struct sockaddr_in6);
    }
    else
    {
        return false;
    }

    return true;
}

bool
network_ipstring_from_address(NetworkAddress *address,
                              char *ip,
                              size_t ipLen)
{
    if(address == NULL || ip == NULL)
    {
        return false;
    }

    if(address->AddressFamily == AF_INET)
    {
        if(uv_ip4_name(&address->Address.Addr4, ip, ipLen) != 0)
        {
            return false;
        }
    }
    else if(address->AddressFamily == AF_INET6)
    {
        if(uv_ip6_name(&address->Address.Addr6, ip, ipLen) != 0)
        {
            return false;
        }
    }
    else
    {
        return false;
    }

    return true;
}
