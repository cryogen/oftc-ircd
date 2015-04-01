/*
 * Copyright (c) 2015, Stuart Walsh
 * All rights reserved.
 * buffer.c network buffer implementation
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

#include "buffer.h"
#include "memory.h"

Buffer *
buffer_new()
{
    Buffer *newBuffer;

    newBuffer = Malloc(sizeof(Buffer));
    
    newBuffer->Size = 0;
    newBuffer->Capacity = BUFFER_CHUNK_SIZE;
    newBuffer->buffer = Malloc(BUFFER_CHUNK_SIZE);
    newBuffer->head = newBuffer->buffer;
    newBuffer->tail = newBuffer->head;

    return newBuffer;
}

void
buffer_push_back(Buffer *buffer, char *data, size_t length)
{
    if(buffer == NULL || data == NULL)
    {
        return;
    }

    if(buffer->Capacity < buffer->Size + length)
    {
        size_t newLen = ((buffer->Size + length / BUFFER_CHUNK_SIZE) + 1) *
                        BUFFER_CHUNK_SIZE;
        buffer->buffer = Realloc(buffer->buffer, newLen);
        buffer->Capacity = newLen;
    }

    memcpy(buffer->tail, data, length);

    buffer->tail += length;
    buffer->Size = (size_t)(buffer->tail - buffer->head);
}

const char *
buffer_pop_front(Buffer *buffer, size_t len)
{
    const char *ret;

    if(buffer == NULL || len == 0)
    {
        return NULL;
    }

    if(len > buffer->Size)
    {
        return NULL;
    }

    ret = buffer->head;
    buffer->head += len;

    if(buffer->head >= buffer->tail)
    {
        if(((size_t)(buffer->tail - buffer->buffer)) + len > buffer->Capacity)
        {
            memmove(buffer->buffer, buffer->head, buffer->Size - len);
            buffer->head = buffer->buffer;
            buffer->tail = buffer->head + buffer->Size - len;
            ret = buffer->head;
        }
        else
        {
            buffer->tail += len;
        }
    }

    buffer->Size = (size_t)(buffer->tail - buffer->head);

    return ret;
}
