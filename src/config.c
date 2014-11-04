/*
 * Copyright (c) 2014, Stuart Walsh
 * All rights reserved.
 * config.c config subsystem
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

#include "hash.h"
#include "memory.h"
#include "config.h"

static Hash *ConfigHash;

void
config_init()
{
    ConfigHash = hash_new("Configuration", DEFAULT_HASH_SIZE);
}

ConfigSection *
config_register_section(const char *sectionName)
{
    ConfigSection *newSection = Malloc(sizeof(ConfigSection));

    newSection->Name = sectionName;
    newSection->Fields = hash_new("Config Section", DEFAULT_HASH_SIZE);

    hash_add_string(ConfigHash, sectionName, (HashItem *)newSection);

    return newSection;
}

void
config_register_field(ConfigSection *section, const char *fieldName,
                           json_type fieldType)
{
    ConfigField *field = Malloc(sizeof(ConfigField));
    field->Name = fieldName;
    field->Type = fieldType;

    hash_add_string(section->Fields, fieldName, (HashItem *)field);
}