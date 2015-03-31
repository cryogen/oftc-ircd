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

static uint32_t
get_hash_value(Hash *hash, const char *key)
{
    uint32_t hashVal;

    MurmurHash3_x86_32(key, (int)strlen(key), HASHSEED, &hashVal);

    return hashVal % hash->Length;
}

Hash *
hash_new(const char *name, size_t length)
{
    Hash *newHash;
    size_t hashSize;

    if(length == 0)
    {
        hashSize = DEFAULT_HASH_SIZE;
    }
    else
    {
      hashSize = length;
    }

    newHash = Malloc(sizeof(Hash));

    newHash->Name = name;
    newHash->Length = hashSize;
    newHash->Buckets = Malloc(hashSize * sizeof(HashItem *));

    return newHash;
}

void
hash_add_string(Hash *thisHash, const char *key, void *value)
{
    uint32_t hashVal;
    HashItem *newItem;

    if(thisHash == NULL)
    {
        return;
    }

    hashVal = get_hash_value(thisHash, key);
    newItem = Malloc(sizeof(HashItem));

    newItem->Next = thisHash->Buckets[hashVal];
    newItem->Data = value;
    thisHash->Buckets[hashVal] = newItem;
}

void *
hash_find(Hash *thisHash, const char *key)
{
    uint32_t hashVal;

    if(thisHash == NULL)
    {
        return NULL;
    }

    hashVal = get_hash_value(thisHash, key);

    if(thisHash->Buckets[hashVal] == NULL)
    {
        return NULL;
    }

    return thisHash->Buckets[hashVal]->Data;
}
