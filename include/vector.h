/*
 * Copyright (c) 2014, Stuart Walsh
 * All rights reserved.
 * vector.c vector implementation
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

#ifndef __oftc_ircd__vector__
#define __oftc_ircd__vector__

#include <stddef.h>

#define DEFAULT_VECTOR_CAPACITY 4096

typedef struct _Vector Vector;

struct _Vector
{
    size_t Length;
    size_t Capacity;
    size_t ElementSize;
    char *Data;
};

Vector *vector_new(size_t capacity, size_t elementSize);
void *vector_push_back(Vector *thisVector, void *data);
void *vector_get(Vector *thisVector, size_t index);
void vector_delete(Vector *thisVector, size_t index);
size_t vector_length(Vector *thisVector);
void vector_free(Vector *thisVector);

#endif /* defined(__oftc_ircd__vector__) */
