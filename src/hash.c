/*
 * Copyright (c) 2014, Stuart Walsh
 * All rights reserved.
 * hash.c hashing subsystem
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

#include "hash.h"
#include "memory.h"
#include "murmurhash3.h"

#include <string.h>

static unsigned int
get_hash_value(const char *key)
{
    unsigned int hashVal;

    MurmurHash3_x86_32(key, strlen(key), HASHSEED, &hashVal);

    return hashVal;
}

void
hash_init()
{
}

Hash *
hash_new(const char *name, unsigned int length)
{
    Hash *newHash;

    if(length == 0)
    {
        return NULL;
    }

    newHash = Malloc(sizeof(Hash));

    newHash->Name = name;
    newHash->Length = length;
    newHash->Buckets = Malloc(length * sizeof(uint32_t));

    return newHash;
}

void
hash_add_string(Hash *hash, const char *key, HashItem *value)
{
    unsigned int hashVal = get_hash_value(key);

    value->Next = hash->Buckets[hashVal];
    hash->Buckets[hashVal] = value;
}