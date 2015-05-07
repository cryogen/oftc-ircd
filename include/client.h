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
#include <openssl/sha.h>

#include "network.h"
#include "buffer.h"

#define HOSTLEN 128
#define NICKLEN 16
#define USERLEN 16
#define REALLEN 128

typedef struct _Client Client;
typedef struct _ClientDnsRequest ClientDnsRequest;

typedef void (*DnsCallback)(ClientDnsRequest *request, bool matched);

typedef enum _DnsNotice
{
    LookingUp,
    Found,
    NotFound
} DnsNotice;

typedef enum _CommandAccess
{
    Unregistered,
    Standard,
    Oper
} CommandAccess;


struct _Client
{
    char Name[NICKLEN + 1];
    char Username[USERLEN + 1];
    char Realname[REALLEN + 1];
    char Host[HOSTLEN + 1];
    NetworkAddress Address;
    Buffer *ReadBuffer;
    CommandAccess AccessLevel;
    struct tls *TlsContext;
    char CertificateFp[SHA_DIGEST_LENGTH + 1];

    // private
    uv_tcp_t *handle;
};

struct _ClientDnsRequest
{
    Client *Client;
    char Host[HOSTLEN];
    DnsCallback Callback;
};

void client_init(void);
Client *client_new(void);
void client_free(Client *client);
void client_lookup_dns(Client *client);
void client_send(Client *, Client *, const char *, const char *, ...);
void client_process_read_buffer(Client *client);
bool client_set_username(Client *client, const char *username);
bool client_set_nickname(Client *client, const char *nickname);
bool client_set_realname(Client *client, const char *realname);
const char *client_get_nickname(Client *client);

#endif /* defined(__oftc_ircd__client__) */
