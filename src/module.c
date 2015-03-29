/*
 * Copyright (c) 2015, Stuart Walsh
 * All rights reserved.
 * module.h Module loading
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

#include <json-c/json.h>
#include <string.h>
#include <limits.h>
#include <uv.h>

#include "vector.h"
#include "config.h"
#include "module.h"
#include "serverstate.h"
#include "memory.h"

static Vector *ModuleList;
static Vector *ModulePaths;
static ConfigSection *ModuleSection;

static void
module_config_set_path(void *element, json_object *obj)
{
    vector_push_back(ModulePaths, (char *)json_object_get_string(obj));
}

static void
module_on_scandir(uv_fs_t *req)
{
    uv_dirent_t dirEntry;

    while(uv_fs_scandir_next(req, &dirEntry) != UV_EOF)
    {
        if(dirEntry.type != UV_DIRENT_FILE)
        {
            continue;
        }

        module_load(dirEntry.name);
    }
}

void
module_init()
{
    ModuleList = vector_new(0, sizeof(Module));
    ModulePaths = vector_new(0, sizeof(char *));
    ModuleSection = config_register_section("module", false);

    config_register_field(ModuleSection, "path", json_type_string,
                          module_config_set_path);
}

Module *
module_new()
{
    Module *module;

    module = Malloc(sizeof(Module));

    return module;
}

void
module_free(Module *module)
{
    Free(module->Path);
    Free(module);
}

void
module_load_all_modules()
{
    int len;
    uv_fs_t *req;

    len = vector_length(ModulePaths);

    for(int i = 0; i < len; i++)
    {
        const char *path = vector_get(ModulePaths, i);

        req = Malloc(sizeof(uv_fs_t));

        uv_fs_scandir(serverstate_get_event_loop(), req, path, 0,
                      module_on_scandir);
    }
}

bool
module_load(const char *path)
{
    Module *module;
    ModuleInfo *moduleInfo;

    module = module_new();

    module->Path = StrDup(path);

    if(uv_dlopen(path, &module->handle) < 0)
    {
        module_free(module);
        return false;
    }

    if(uv_dlsym(&module->handle, "ModuleInfo", (void **)&moduleInfo) < 0)
    {
        module_free(module);
        return false;
    }

    if(moduleInfo == NULL)
    {
        module_free(module);
        return false;
    }

    if(moduleInfo->Load != NULL)
    {
        moduleInfo->Load();
    }

    vector_push_back(ModuleList, module);

    return true;
}