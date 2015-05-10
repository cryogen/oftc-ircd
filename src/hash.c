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

#include <string.h>

#include "hash.h"
#include "memory.h"
#include "murmurhash3.h"
#include "lstring.h"

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
    char *upperKey;

    if(thisHash == NULL)
    {
        return;
    }

    upperKey = string_to_upper(key);

    hashVal = get_hash_value(thisHash, upperKey);
    newItem = Malloc(sizeof(HashItem));

    newItem->Next = thisHash->Buckets[hashVal];
    newItem->Data = value;
    strncpy(newItem->Key, upperKey, MAX_KEY_LEN);
    thisHash->Buckets[hashVal] = newItem;

    Free(upperKey);
}

void *
hash_find(Hash *thisHash, const char *key)
{
    uint32_t hashVal;
    HashItem *ptr;
    char *upperKey;

    if(thisHash == NULL)
    {
        return NULL;
    }

    upperKey = string_to_upper(key);

    hashVal = get_hash_value(thisHash, upperKey);

    ptr = thisHash->Buckets[hashVal];
    
    if(ptr == NULL)
    {
        Free(upperKey);
        return NULL;
    }

    while(ptr != NULL)
    {
        if(strncmp(ptr->Key, upperKey, MAX_KEY_LEN) == 0)
        {
            Free(upperKey);
            return ptr->Data;
        }

        ptr = ptr->Next;
    }

    Free(upperKey);
    return NULL;
}

void
hash_delete_string(Hash *thisHash, const char *key)
{
    uint32_t hashVal;
    char *upperKey;
    HashItem *ptr, *last;

    if(thisHash == NULL)
    {
        return;
    }

    upperKey = string_to_upper(key);
    hashVal = get_hash_value(thisHash, upperKey);

    last = ptr = thisHash->Buckets[hashVal];

    while(ptr != NULL)
    {
        if(strncmp(ptr->Key, upperKey, MAX_KEY_LEN) == 0)
        {
            last->Next = ptr->Next;
            if(thisHash->Buckets[hashVal] == ptr && ptr->Next == NULL)
            {
                thisHash->Buckets[hashVal] = NULL;
            }
            Free(ptr);
            break;
        }

        last = ptr;
        ptr = ptr->Next;
    }

    Free(upperKey);
}
