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
#include "serverstate.h"

#include <stdio.h>
#include <string.h>
#include <json-c/json.h>

static Hash *ConfigSections;

void
config_init()
{
    ConfigSections = hash_new("Configuration", DEFAULT_HASH_SIZE);
}

void
config_load()
{
    FILE *fptr = fopen(serverstate_get_config_path(), "r");
    char fileBuffer[8192];
    struct json_object *obj;
    struct json_tokener *tokener = json_tokener_new();

    if(fptr == NULL)
    {
        fprintf(stderr, "Error opening config %s\n", serverstate_get_config_path());
        return;
    }

    while(fgets(fileBuffer, sizeof(fileBuffer), fptr) != NULL)
    {
        obj = json_tokener_parse_ex(tokener, fileBuffer, strlen(fileBuffer));

        if(obj == NULL &&
           json_tokener_get_error(tokener) != json_tokener_continue)
        {
            fprintf(stderr, "Error parsing config\n");
            break;
        }

        if(obj == NULL)
        {
            continue;
        }

        if(json_object_get_type(obj) != json_type_object)
        {
            fprintf(stderr, "Invalid config, could not find root object\n");
            break;
        }

        json_object_object_foreach(obj, key, val)
        {
            ConfigSection *section;

            section = hash_find(ConfigSections, key);

            if(section == NULL)
            {
                fprintf(stderr, "Unknown config section: %s\n", key);
                break;
            }

            if(section->IsArray)
            {
                int index = 0;

                for(index = 0; index < json_object_array_length(val); index++)
                {
                    json_object *obj = json_object_array_get_idx(val, index);
                    void *element = section->NewElement();

                    if(json_object_get_type(obj) != json_type_object)
                    {
                        break;
                    }

                    json_object_object_foreach(obj, subKey, subVal)
                    {
                        ConfigField *field = hash_find(section->Fields, subKey);

                        if(field == NULL)
                        {
                            fprintf(stderr, "Unknown field %s\n", subKey);
                            break;
                        }

                        if(json_object_get_type(subVal) != field->Type)
                        {
                            fprintf(stderr, "Wrong field type in field %s\n",
                                    subKey);
                            break;
                        }

                        field->Handler(element, subVal);
                    }
                }
            }
        }
    }

    if(obj == NULL)
    {
        enum json_tokener_error err = json_tokener_get_error(tokener);
        printf("%p %s\n", obj, json_tokener_error_desc(err));
    }

    fclose(fptr);
}

ConfigSection *
config_register_section(const char *sectionName, bool isArray)
{
    ConfigSection *newSection = Malloc(sizeof(ConfigSection));

    newSection->Name = sectionName;
    newSection->Fields = hash_new("Config Section", DEFAULT_HASH_SIZE);
    newSection->IsArray = isArray;

    hash_add_string(ConfigSections, sectionName, newSection);

    return newSection;
}

void
config_register_field(ConfigSection *section, ConfigField *field)
{
    if(section == NULL || field == NULL)
    {
        return;
    }

    hash_add_string(section->Fields, field->Name, field);
}