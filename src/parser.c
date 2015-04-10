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

#include "parser.h"

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
    
    currentChunk = srcBuffer->Data->Head;
    if(currentChunk == NULL)
    {
        return false;
    }

    bufferPtr = currentChunk->Data;
    destPtr = destBuffer;
    toRead = srcBuffer->Size;
    waitingEol = false;
    found = false;
    toDelete = written = 0;

    while(toRead > 0) 
    {
        toRead--;

        switch(*bufferPtr)
        {
            case ' ':
                bufferPtr++;
                toDelete++;
                
                break;
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

        *destPtr = '\0';
    }

    if(found)
    {
        toDelete += written + 2;
    }

    buffer_remove(srcBuffer, toDelete);

    return found;
}
