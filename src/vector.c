/*
 * Copyright (c) 2014, Stuart Walsh
 * All rights reserved.
 * main.c main startup functions
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
vector_resize(Vector *this, size_t newSize)
{
    if(newSize <= this->Capacity)
    {
        return;
    }

    this->Capacity *= 2;
    this->Data = Realloc(this->Data, this->Capacity * this->ElementSize);
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

    newVector->Data = Malloc(sizeof(elementSize * capacity));
    newVector->Capacity = capacity;
    newVector->ElementSize = elementSize;

    return newVector;
}

void
vector_push_back(Vector *this, void *element)
{
    if(this == NULL || element == NULL)
    {
        return;
    }
    
    vector_resize(this, this->Length + 1);

    memcpy(this->Data + (this->Length * this->ElementSize), element,
           this->ElementSize);

    ++this->Length;
}

inline size_t
vector_length(Vector *this)
{
    if(this == NULL)
    {
        return 0;
    }
    
    return this->Length;
}

inline void *
vector_get(Vector *this, size_t index)
{
    if(this == NULL)
    {
        return 0;
    }

    return this->Data + (index * this->ElementSize);
}