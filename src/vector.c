/*
 * Copyright (c) 2014, Stuart Walsh
 * All rights reserved.
 * vector.c vector implementation
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

#include <string.h>

#include "vector.h"
#include "memory.h"

static void
vector_check_size(Vector *thisVector)
{
    if(thisVector->Length < thisVector->Capacity)
    {
        return;
    }

    thisVector->Capacity *= 2;
    thisVector->Data = Realloc(thisVector->Data, thisVector->Capacity * thisVector->ElementSize);
}

Vector *
vector_new(size_t capacity, size_t elementSize)
{
    Vector *newVector;

    if(elementSize == 0)
    {
        return NULL;
    }

    if(capacity == 0)
    {
        capacity = DEFAULT_VECTOR_CAPACITY;
    }

    newVector = Malloc(sizeof(Vector));

    newVector->Data = Malloc(elementSize * capacity);
    newVector->Capacity = capacity;
    newVector->ElementSize = elementSize;

    return newVector;
}

void *
vector_push_back(Vector *thisVector, void *element)
{
    void *ptr;

    if(thisVector == NULL || element == NULL)
    {
        return NULL;
    }
    
    vector_check_size(thisVector);
    ptr = thisVector->Data + (thisVector->Length * thisVector->ElementSize);

    memcpy(ptr, element, thisVector->ElementSize);

    ++thisVector->Length;

    return ptr;
}

inline size_t
vector_length(Vector *thisVector)
{
    if(thisVector == NULL)
    {
        return 0;
    }
    
    return thisVector->Length;
}

inline void *
vector_get(Vector *thisVector, size_t index)
{
    if(thisVector == NULL)
    {
        return NULL;
    }

    if(index >= thisVector->Length)
    {
        return NULL;
    }

    return thisVector->Data + (index * thisVector->ElementSize);
}
