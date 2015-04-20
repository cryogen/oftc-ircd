/*
 * Copyright (c) 2015, Stuart Walsh
 * All rights reserved.
 * parser.h parser definitions
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

#ifndef __oftc_ircd__parser__
#define __oftc_ircd__parser__

#include <stdbool.h>

#include "buffer.h"
#include "command.h"
#include "client.h"
#include "vector.h"
#include "irc.h"

typedef enum _ParserState
{
    InitialState,
    CommandState,
    ArgState
} ParserState;

typedef struct _ParserResult ParserResult;

struct _ParserResult
{
    char CommandText[IRC_MAXLEN + 1];
    char Source[IRC_MAXLEN + 1];
    Vector *Params;
};

bool parser_get_line(Buffer *srcBuffer, char *destBuffer, size_t length);
ParserResult *parser_process_line(const char *, size_t);

ParserResult *parser_result_new();
void parser_result_free(ParserResult *result);

#endif /* defined(__oftc_ircd__parser__) */
