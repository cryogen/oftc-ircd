/*
 * Copyright (c) 2015, Stuart Walsh
 * All rights reserved.
 * parser.c parser implementation
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

#include "parser.h"
#include "memory.h"

bool
parser_get_line(Buffer *srcBuffer, char *destBuffer, size_t length)
{
    ListEntry *currentChunk;
    const char *bufferPtr;
    char *destPtr;
    size_t toRead;
    size_t toDelete;
    size_t written;
    bool waitingEol;
    bool found;

    if(srcBuffer == NULL || destBuffer == NULL)
    {
        return false;
    }
    
    currentChunk = buffer_get_start(srcBuffer);
    if(currentChunk == NULL)
    {
        return false;
    }

    bufferPtr = currentChunk->Data;
    destPtr = destBuffer;
    toRead = srcBuffer->Size > BUFFER_CHUNK_SIZE ? 
        BUFFER_CHUNK_SIZE : srcBuffer->Size;
    waitingEol = false;
    found = false;
    toDelete = written = 0;

    while(toRead > 0 && *bufferPtr == ' ')
    {
        toRead--;
        toDelete++;
        bufferPtr++;
    }

    while(toRead > 0)
    {
        toRead--;

        switch(*bufferPtr)
        {
            case '\r':
                bufferPtr++;
                waitingEol = true;

                break;
            case '\n':
                if(waitingEol)
                {
                    toRead = 0;
                    found = true;
                }

                break;
            default:
                if(length > 1)
                {
                    *destPtr = *bufferPtr;
                    destPtr++;
                    length--;
                }
                bufferPtr++;
                waitingEol = false;
                written++;

                break;
        }
        
        if(!found && toRead == 0)
        {
            size_t left = srcBuffer->Size - (bufferPtr - (char *)currentChunk->Data);
            currentChunk = currentChunk->Next;
            if(currentChunk != NULL)
            {
                bufferPtr = currentChunk->Data;
                toRead = left > BUFFER_CHUNK_SIZE ? BUFFER_CHUNK_SIZE : left;
            }
        }
    }

    if(found)
    {
        *destPtr = '\0';
        toDelete += written + 2;
    }

    buffer_remove(srcBuffer, toDelete);

    return found;
}

ParserResult *
parser_process_line(const char *buffer, size_t length)
{
    ParserResult *result;
    ParserState state = InitialState;
    char *destPtr;
    const char *end;
    char arg[IRC_MAXLEN + 1];
    bool lastArg = false;

    if(buffer == NULL)
    {
        return NULL;
    }

    result = parser_result_new();

    end = buffer + length;

    for(; (*buffer == ' ' || *buffer == '\t') && buffer < end; buffer++)
    {
    }

    destPtr = result->CommandText;
    state = CommandState;

    if(*buffer == ':')
    {
        destPtr = result->Source;
        state = InitialState;
        buffer++;
    }

    while(buffer < end)
    {
        char c = *buffer++;
        if(c == ' ')
        {
            switch (state)
            {
                case InitialState:
                    state = CommandState;
                    destPtr = result->CommandText;
                    continue;
                case CommandState:
                    state = ArgState;
                    memset(arg, 0, sizeof(arg));
                    destPtr = arg;
                    continue;
                default:
                    if(!lastArg)
                    {
                        vector_push_back(result->Params, arg);
                        memset(arg, 0, sizeof(arg));
                        destPtr = arg;
                        continue;
                    }
            }
        }
        else if(c == ':' && !lastArg)
        {
            lastArg = true;
            continue;
        }

        *destPtr++ = c;
    }

    if(state == ArgState)
    {
        vector_push_back(result->Params, arg);
    }

    return result;
}

ParserResult *
parser_result_new()
{
    ParserResult *result = Malloc(sizeof(ParserResult));

    result->Params = vector_new(0, IRC_MAXLEN + 1);

    return result;
}

void
parser_result_free(ParserResult *result)
{
    if(result == NULL)
    {
        return;
    }

    vector_free(result->Params);
    Free(result);
}
