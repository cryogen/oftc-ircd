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
#include "vector.h"

#include <stdio.h>
#include <string.h>
#include <json-c/json.h>
#include <uv.h>

static Hash *ConfigSections;
static Vector *ConfigSectionList;

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
    ConfigSectionList = vector_new(0, sizeof(ConfigSection));
}

bool
config_load()
{
    uv_fs_t fileReq, readReq, closeReq;
    uv_buf_t buffer;
    char fileBuffer[4096];
    const char *configPath;
    struct json_object *obj = NULL;
    struct json_tokener *tokener;
    int ret, len;

    len = vector_length(ConfigSectionList);

    for(int i = 0; i < len; i++)
    {
        ConfigSection *section = vector_get(ConfigSectionList, i);

        if(section->SetDefaults != NULL)
        {
            section->SetDefaults();
        }
    }

    configPath = serverstate_get_config_path();
    if(configPath == NULL)
    {
        return false;
    }

    buffer = uv_buf_init(fileBuffer, sizeof(fileBuffer));

    ret = uv_fs_open(uv_default_loop(), &fileReq, configPath, O_RDONLY, 0, NULL);
    if(ret < 0)
    {
        fprintf(stderr, "Error opening config %s\n", configPath);
        return false;
    }

    tokener = json_tokener_new();

    while((ret = uv_fs_read(uv_default_loop(), &readReq, fileReq.result, &buffer,
                           1, -1, NULL)) > 0)
    {
        obj = json_tokener_parse_ex(tokener, fileBuffer, ret);
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
            uv_fs_close(uv_default_loop(), &closeReq, fileReq.result, NULL);
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
                int arrayLen = json_object_array_length(val);

                for(index = 0; index < arrayLen; index++)
                {
                    json_object *item = json_object_array_get_idx(val, index);
                    void *element = NULL;

                    if(section->NewElement != NULL)
                    {
                        element = section->NewElement();
                    }

                    if(json_object_get_type(item) != json_type_object)
                    {
                        break;
                    }

                    process_object(section, element, item);

                    if(section->ElementDone != NULL)
                    {
                        section->ElementDone(element);
                    }
                }
            }
            else if(type == json_type_object)
            {
                process_object(section, NULL, val);
            }
            else
            {
                fprintf(stderr, "Found array for non array section\n");
            }
        }
    }

    json_tokener_free(tokener);

    uv_fs_close(uv_default_loop(), &closeReq, fileReq.result, NULL);

    if(obj == NULL)
    {
        return false;
    }

    for(int i = 0; i < vector_length(ConfigSectionList); i++)
    {
        ConfigSection *section = vector_get(ConfigSectionList, i);

        if(section->VerifySection != NULL)
        {
            if(!section->VerifySection())
            {
                fprintf(stderr, "Section %s returned false from verify\n",
                        section->Name);
                return false;
            }
        }
    }

    return true;
}

ConfigSection *
config_register_section(const char *sectionName, bool isArray)
{
    ConfigSection *ret, newSection = { 0 };

    if(sectionName == NULL)
    {
        return NULL;
    }

    newSection.Name = StrDup(sectionName);
    newSection.Fields = hash_new("Config Section", DEFAULT_HASH_SIZE);
    newSection.IsArray = isArray;

    ret = vector_push_back(ConfigSectionList, &newSection);
    hash_add_string(ConfigSections, sectionName, ret);

    return ret;
}

void
config_register_field(ConfigSection *section, const char *name, json_type type,
                      ConfigFieldHandler handler)
{
    ConfigField *field;

    if(section == NULL || name == NULL)
    {
        return;
    }

    field = Malloc(sizeof(ConfigField));
    field->Name = StrDup(name);
    field->Type = type;
    field->Handler = handler;

    hash_add_string(section->Fields, field->Name, field);
}