/*
 * Copyright (c) 2014, Stuart Walsh
 * All rights reserved.
 * main.c main startup functions
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

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <json-c/json.h>

#include "serverstate.h"
#include "hash.h"
#include "config.h"
#include "config.h"
#include "listener.h"
#include "client.h"
#include "module.h"
#include "server.h"

static void
process_commandline(char *const *args, int argCount)
{
    int opt;

    while((opt = getopt(argCount, args, "c:")) != -1)
    {
        switch(opt)
        {
            case 'c':
                serverstate_set_config_path(optarg);
                break;

            default:
                fprintf(stderr, "Usage: some stuff");
                exit(EXIT_FAILURE);
        }
    }

    if(serverstate_get_config_path() == NULL)
    {
        serverstate_set_config_path("ircd.conf");
    }
}

int
main(int argc, char *argv[])
{
    serverstate_set_event_loop(uv_default_loop());

    config_init();
    listener_init();
    client_init();
    module_init();
    server_init();
    
    process_commandline(argv, argc);

    config_load();
    listener_start_listeners();
    module_load_all_modules();

    uv_run(serverstate_get_event_loop(), UV_RUN_DEFAULT);
    
    return 0;
}
