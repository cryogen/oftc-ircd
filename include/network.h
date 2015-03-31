/*
 * Copyright (c) 2014, Stuart Walsh
 * All rights reserved.
 * network.h network utility functions
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

#ifndef __oftc_ircd__network__
#define __oftc_ircd__network__

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdbool.h>

typedef struct _NetworkAddress NetworkAddress;

struct _NetworkAddress
{
    union
    {
        struct sockaddr_in Addr4;
        struct sockaddr_in6 Addr6;
    } Address;

    int AddressFamily;
    size_t AddressLength;
};

bool network_address_from_ipstring(const char *ip, NetworkAddress *address);
bool network_address_from_ipstring_and_port(const char *ip, unsigned short port, NetworkAddress *address);
bool network_ipstring_from_address(NetworkAddress *address, char *ip, size_t ipLen);

#endif /* defined(__oftc_ircd__network__) */
