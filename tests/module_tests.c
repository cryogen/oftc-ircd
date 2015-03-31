/*
 * Copyright (c) 2015, Stuart Walsh
 * All rights reserved.
 * module_tests.c unit tests for module functions
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

#include "opmock.h"
#include "json_object_stub.h"
#include "vector_stub.h"
#include "config_stub.h"
#include "uv_stub.h"
#include "serverstate_stub.h"
#include "memory_stub.h"

#include "module.h"

static ModuleInfo Info;
static bool CallbackCalled;

static int
dlsym_callback(uv_lib_t *lib, const char *name, void **ptr, int calls)
{
    memset(&Info, 0, sizeof(Info));

    *ptr = &Info;

    return 0;
}

static bool
module_load_callback()
{
    CallbackCalled = true;

    return true;
}

static int
dlsym_load_callback(uv_lib_t *lib, const char *name, void **ptr, int calls)
{
    memset(&Info, 0, sizeof(Info));

    Info.Load = module_load_callback;
    *ptr = &Info;

    CallbackCalled = false;
    
    return 0;
}

static void
set_path_test_callback(ConfigSection *section,
                       const char *name,
                       json_type type,
                       ConfigFieldHandler handler,
                       int calls)
{
    handler(NULL, NULL);
}

static int
scandir_callback(uv_loop_t *loop,
                 uv_fs_t *req,
                 const char *path,
                 int flags,
                 uv_fs_cb callback,
                 int calls)
{
    callback(req);

    return 0;
}

static int
scandir_next_not_file_callback(uv_fs_t *req, uv_dirent_t *ent, int calls)
{
    ent->type = UV_DIRENT_DIR;

    if(calls > 1)
    {
        return UV_EOF;
    }

    return 0;
}

static int
scandir_next_file_callback(uv_fs_t *req, uv_dirent_t *ent, int calls)
{
    ent->type = UV_DIRENT_FILE;
    ent->name = "test.so";

    if(calls > 1)
    {
        return UV_EOF;
    }

    return 0;
}

static int
dlsym_null_callback(uv_lib_t *lib, const char *name, void **ptr, int calls)
{
    *ptr = NULL;

    return 0;
}

static void
module_init_when_called_sets_up_modules()
{
    vector_new_ExpectAndReturn(0, 0, NULL, NULL, NULL);
    vector_new_ExpectAndReturn(0, 0, NULL, NULL, NULL);

    config_register_section_ExpectAndReturn(NULL, false, NULL, NULL, NULL);
    config_register_field_ExpectAndReturn(NULL, NULL, 0, 0, NULL, NULL, NULL, NULL);

    module_init();

    OP_VERIFY();
}

static void
module_config_set_path_when_called_adds_path()
{
    const char *path = "test/path";

    vector_new_ExpectAndReturn(0, 0, NULL, NULL, NULL);
    vector_new_ExpectAndReturn(0, 0, NULL, NULL, NULL);

    config_register_section_ExpectAndReturn(NULL, false, NULL, NULL, NULL);
    config_register_field_MockWithCallback(set_path_test_callback);
    json_object_get_string_ExpectAndReturn(NULL, path, NULL);
    vector_push_back_ExpectAndReturn(NULL, NULL, NULL, NULL, NULL);

    module_init();

    OP_VERIFY();
}

static void
module_load_all_modules_when_calls_loads_module()
{
    vector_length_ExpectAndReturn(NULL, 1, NULL);
    vector_get_ExpectAndReturn(NULL, 0, "test", NULL, cmp_int);

    Malloc_ExpectAndReturn(0, NULL, NULL);
    serverstate_get_event_loop_ExpectAndReturn(NULL);
    uv_fs_scandir_ExpectAndReturn(NULL, NULL, NULL, 0, NULL, 0, NULL, NULL,
                                  NULL, NULL, NULL);

    module_load_all_modules();

    OP_VERIFY();
}

static void
module_scandir_when_eof_does_not_load_module()
{
    uv_fs_t req;

    vector_length_ExpectAndReturn(NULL, 1, NULL);
    vector_get_ExpectAndReturn(NULL, 0, "test", NULL, cmp_int);

    Malloc_ExpectAndReturn(sizeof(req), &req, cmp_int);
    serverstate_get_event_loop_ExpectAndReturn(NULL);
    uv_fs_scandir_MockWithCallback(scandir_callback);
    uv_cwd_ExpectAndReturn(NULL, NULL, 0, NULL, NULL);
    uv_chdir_ExpectAndReturn(NULL, 0, NULL);
    uv_fs_scandir_next_ExpectAndReturn(NULL, NULL, UV_EOF, NULL, NULL);
    uv_chdir_ExpectAndReturn(NULL, 0, NULL);

    module_load_all_modules();

    OP_VERIFY();
}

static void
module_scandir_when_not_file_does_not_load_module()
{
    uv_fs_t req;

    vector_length_ExpectAndReturn(NULL, 1, NULL);
    vector_get_ExpectAndReturn(NULL, 0, "test", NULL, cmp_int);

    Malloc_ExpectAndReturn(sizeof(req), &req, cmp_int);

    serverstate_get_event_loop_ExpectAndReturn(NULL);
    uv_fs_scandir_MockWithCallback(scandir_callback);
    uv_cwd_ExpectAndReturn(NULL, NULL, 0, NULL, NULL);
    uv_chdir_ExpectAndReturn(NULL, 0, NULL);
    uv_fs_scandir_next_MockWithCallback(scandir_next_not_file_callback);
    uv_chdir_ExpectAndReturn(NULL, 0, NULL);

    module_load_all_modules();

    OP_VERIFY();
}

static void
module_scandir_when_file_loads_module()
{
    uv_fs_t req;
    Module module = { 0 };

    vector_length_ExpectAndReturn(NULL, 1, NULL);
    vector_get_ExpectAndReturn(NULL, 0, "test", NULL, cmp_int);

    Malloc_ExpectAndReturn(sizeof(req), &req, cmp_int);

    serverstate_get_event_loop_ExpectAndReturn(NULL);
    uv_fs_scandir_MockWithCallback(scandir_callback);
    uv_cwd_ExpectAndReturn(NULL, NULL, 0, NULL, NULL);
    uv_chdir_ExpectAndReturn(NULL, 0, NULL);
    uv_fs_scandir_next_MockWithCallback(scandir_next_file_callback);
    Malloc_ExpectAndReturn(sizeof(Module), &module, cmp_int);
    StrDup_ExpectAndReturn(NULL, NULL, NULL);
    uv_dlopen_ExpectAndReturn(NULL, NULL, -1, NULL, NULL);
    Free_ExpectAndReturn(NULL, NULL);
    Free_ExpectAndReturn(NULL, NULL);
    uv_chdir_ExpectAndReturn(NULL, 0, NULL);

    module_load_all_modules();

    OP_VERIFY();
}

static void
module_load_when_load_fails_return_false()
{
    Module module = { 0 };

    Malloc_ExpectAndReturn(sizeof(Module), &module, cmp_ptr);
    StrDup_ExpectAndReturn(NULL, NULL, NULL);
    uv_dlopen_ExpectAndReturn(NULL, NULL, -1, NULL, NULL);
    Free_ExpectAndReturn(NULL, NULL);
    Free_ExpectAndReturn(&module, cmp_ptr);

    bool ret = module_load("test");

    OP_ASSERT_FALSE(ret);
    OP_VERIFY();
}

static void
module_load_when_symbol_error_returns_false()
{
    Module module = { 0 };

    Malloc_ExpectAndReturn(sizeof(Module), &module, cmp_ptr);
    uv_dlopen_ExpectAndReturn(NULL, NULL, 0, NULL, NULL);
    uv_dlsym_ExpectAndReturn(NULL, NULL, NULL, -1, NULL, NULL, NULL);

    bool ret = module_load("test");

    OP_ASSERT_FALSE(ret);
}

static void
module_load_when_symbol_null_returns_false()
{
    Module module = { 0 };

    Malloc_ExpectAndReturn(sizeof(Module), &module, cmp_ptr);
    uv_dlopen_ExpectAndReturn(NULL, NULL, 0, NULL, NULL);
    uv_dlsym_MockWithCallback(dlsym_null_callback);

    bool ret = module_load("test");

    OP_ASSERT_FALSE(ret);
}

static void
module_load_when_load_succeeds_returns_true()
{
    Module module = { 0 };

    Malloc_ExpectAndReturn(sizeof(Module), &module, cmp_ptr);
    uv_dlopen_ExpectAndReturn(NULL, NULL, 0, NULL, NULL);
    uv_dlsym_MockWithCallback(dlsym_callback);

    bool ret = module_load("test");

    OP_ASSERT_TRUE(ret);
}

static void
module_load_when_load_callback_calls_callback()
{
    Module module = { 0 };

    Malloc_ExpectAndReturn(sizeof(Module), &module, cmp_ptr);
    uv_dlopen_ExpectAndReturn(NULL, NULL, 0, NULL, NULL);
    uv_dlsym_MockWithCallback(dlsym_load_callback);

    bool ret = module_load("test");

    OP_ASSERT_TRUE(ret);
    OP_ASSERT_TRUE(CallbackCalled);
}

int
main()
{
    opmock_test_suite_reset();

    opmock_register_test(module_init_when_called_sets_up_modules,
                         "module_init_when_called_sets_up_modules");
    opmock_register_test(module_config_set_path_when_called_adds_path,
                         "module_config_set_path_when_called_adds_path");
    opmock_register_test(module_load_all_modules_when_calls_loads_module,
                         "module_load_all_modules_when_calls_loads_module");
    opmock_register_test(module_scandir_when_eof_does_not_load_module,
                         "module_scandir_when_eof_does_not_load_module");
    opmock_register_test(module_scandir_when_not_file_does_not_load_module,
                         "module_scandir_when_not_file_does_not_load_module");
    opmock_register_test(module_scandir_when_file_loads_module,
                         "module_scandir_when_file_loads_module");
    opmock_register_test(module_load_when_load_fails_return_false,
                         "module_load_when_load_fails_return_false");
    opmock_register_test(module_load_when_symbol_error_returns_false,
                         "module_load_when_symbol_error_returns_false");
    opmock_register_test(module_load_when_symbol_null_returns_false,
                         "module_load_when_symbol_null_returns_false");
    opmock_register_test(module_load_when_load_succeeds_returns_true,
                         "module_load_when_load_succeeds_returns_true");
    opmock_register_test(module_load_when_load_callback_calls_callback,
                         "module_load_when_load_callback_calls_callback");

    opmock_test_suite_run();

    return opmock_test_error > 0;
}
