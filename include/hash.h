/*
 * Copyright (c) 2014, Stuart Walsh
 * All rights reserved.
 * hash.h hashing subsystem
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, thi
 *    list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.

 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" A
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE F
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGE
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef __oftc_ircd__hash__
#define __oftc_ircd__hash__

#include <stddef.h>

#define DEFAULT_HASH_SIZE 65535
#define HASHSEED 0x6d4c2a10
#define MAX_KEY_LEN 128

typedef struct _Hash Hash;
typedef struct _HashItem HashItem;

struct _Hash
{
    const char *Name;
    size_t Length;
    HashItem **Buckets;
};

struct _HashItem
{
    HashItem *Next;
    void *Data;
    char Key[MAX_KEY_LEN + 1];
};

void hash_init();
Hash *hash_new(const char *name, size_t length);
void hash_add_string(Hash *this, const char *key, void *value);
void *hash_find(Hash *this, const char *key);
void hash_delete_string(Hash *this, const char *key);

#endif /* defined(__oftc_ircd__hash__) */
