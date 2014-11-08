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

static void
process_object(ConfigSection *section, void *element, json_object *obj)
{
    json_object_object_foreach(obj, subKey, subVal)
    {
        ConfigField *field = hash_find(section->Fields, subKey);

        if(field == NULL)
        {
            fprintf(stderr, "Unknown field %s\n", subKey);
            return;
        }

        if(json_object_get_type(subVal) != field->Type)
        {
            fprintf(stderr, "Wrong field type in field %s\n", subKey);
            return;
        }

        if(field->Handler != NULL)
        {
            field->Handler(element, subVal);
        }
    }
}


void
config_init()
{
    ConfigSections = hash_new("Configuration", DEFAULT_HASH_SIZE);
}

bool
config_load()
{
    FILE *fptr;
    char fileBuffer[8192];
    const char *configPath;
    struct json_object *obj = NULL;
    struct json_tokener *tokener;

    configPath = serverstate_get_config_path();

    if(configPath == NULL)
    {
        return false;
    }

    fptr = fopen(configPath, "r");
    if(fptr == NULL)
    {
        fprintf(stderr, "Error opening config %s\n", serverstate_get_config_path());
        return false;
    }

    tokener = json_tokener_new();

    while(fgets(fileBuffer, sizeof(fileBuffer), fptr) != NULL)
    {
        obj = json_tokener_parse_ex(tokener, fileBuffer, strlen(fileBuffer));
        enum json_tokener_error err = json_tokener_get_error(tokener);

        if(obj == NULL && err != json_tokener_continue)
        {
            fprintf(stderr, "Error parsing config %s\n", json_tokener_error_desc(err));
            break;
        }

        if(obj == NULL)
        {
            continue;
        }

        if(json_object_get_type(obj) != json_type_object)
        {
            fprintf(stderr, "Invalid config, could not find root object\n");
            json_tokener_free(tokener);
            return false;
        }

        json_object_object_foreach(obj, key, val)
        {
            ConfigSection *section;
            json_type type;

            section = hash_find(ConfigSections, key);

            if(section == NULL)
            {
                fprintf(stderr, "Unknown config section: %s\n", key);
                break;
            }

            type = json_object_get_type(val);
            if(type != json_type_object && type != json_type_array)
            {
                fprintf(stderr, "Wrong type for config section value\n");
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

                    process_object(section, element, obj);

                    section->SectionDone(element);
                }
            }
            else
            {
                process_object(section, NULL, val);
            }
        }
    }

    json_tokener_free(tokener);

    if(obj == NULL)
    {
        return false;
    }

    fclose(fptr);

    return true;
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