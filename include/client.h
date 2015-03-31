/*
 * Copyright (c) 2014, Stuart Walsh
 * All rights reserved.
 * client.h client definitions
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

#ifndef __oftc_ircd__client__
#define __oftc_ircd__client__

#include <uv.h>
#include <stdbool.h>

#include "network.h"

#define HOSTLEN 128

typedef struct _Client Client;
typedef struct _ClientDnsRequest ClientDnsRequest;

typedef void (*DnsCallback)(ClientDnsRequest *request, bool matched);

struct _Client
{
    uv_tcp_t *Handle;
    char Name[HOSTLEN];
    char Host[HOSTLEN];
    NetworkAddress Address;
};

struct _ClientDnsRequest
{
    Client *Client;
    char Host[HOSTLEN];
    DnsCallback Callback;
};

void client_init();
Client *client_new();
void client_free(Client *client);
bool client_accept(Client *client, uv_stream_t *handle);
void client_send(Client *client, const char *pattern, ...);

#endif /* defined(__oftc_ircd__client__) */