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

    newBuffer->Data = list_new();

    return newBuffer;
}

void
buffer_add(Buffer *buffer, char *data, size_t length)
{
    size_t written = 0;
    size_t partial;
    ListEntry *currentChunk;

    if(buffer == NULL || data == NULL)
    {
        return;
    }

    partial = buffer->Size % BUFFER_CHUNK_SIZE;
    currentChunk = buffer->currentChunk;

    while(written < length)
    {
        const char *ptr;
        size_t toWrite;

        if(length - written + partial > BUFFER_CHUNK_SIZE)
        {
            toWrite = BUFFER_CHUNK_SIZE - partial;
        }
        else
        {
            toWrite = length - written;
        }

        if(currentChunk == NULL)
        {
            ptr = Malloc(BUFFER_CHUNK_SIZE);
            currentChunk = list_add_tail(buffer->Data, (void *)ptr);
            buffer->currentChunk = currentChunk;
        }
        else
        {
            ptr = currentChunk->Data;
        }

        memcpy((void *)(ptr + partial), data + written, toWrite);

        written += toWrite;

        if(written < length || toWrite == BUFFER_CHUNK_SIZE)
        {
            buffer->currentChunk = NULL;
            currentChunk = NULL;
        }
    }

    buffer->Size += written;
}

void
buffer_remove(Buffer *buffer, size_t len)
{
    size_t toDelete;

    if(buffer == NULL || len == 0)
    {
        return;
    }

    if(len > buffer->Size)
    {
        return;
    }

    toDelete = len;

    while(toDelete >= BUFFER_CHUNK_SIZE)
    {
        list_delete(buffer->Data, buffer->Data->Head);

        toDelete -= BUFFER_CHUNK_SIZE;
    }

    if(toDelete > 0)
    {
        memmove(buffer->Data->Head->Data,
                ((char *)buffer->Data->Head->Data) + toDelete,
                BUFFER_CHUNK_SIZE - toDelete);

        buffer->currentChunk = buffer->Data->Head;
    }
    else
    {
        buffer->currentChunk = NULL;
    }

    buffer->Size -= len;
}
