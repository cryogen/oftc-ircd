/*
 * Copyright (c) 2014, Stuart Walsh
 * All rights reserved.
 * config.h config subsystem
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

#ifndef __oftc_ircd__config__
#define __oftc_ircd__config__

#include <stdbool.h>

#include "hash.h"

typedef struct _ConfigSection ConfigSection;
typedef struct _ConfigField ConfigField;

typedef void (*ConfigFieldHandler)(void *, json_object *);
typedef void *(*ConfigNewElementHandler)();
typedef void (*ConfigElementDoneHandler)(void *);
typedef void (*ConfigSetDefaultsHandler)();
typedef bool (*ConfigVerifySectionHandler)();

struct _ConfigSection
{
    const char *Name;
    Hash *Fields;
    bool IsArray;
    ConfigSetDefaultsHandler SetDefaults;
    ConfigNewElementHandler NewElement;
    ConfigElementDoneHandler ElementDone;
    ConfigVerifySectionHandler VerifySection;
};

struct _ConfigField
{
    const char *Name;
    json_type Type;
    ConfigFieldHandler Handler;
};

void config_init(void);
bool config_load(void);
ConfigSection *config_register_section(const char *sectionName, bool isArray);
void config_register_field(ConfigSection *, const char *, json_type, ConfigFieldHandler);

#endif /* defined(__oftc_ircd__config__) */
