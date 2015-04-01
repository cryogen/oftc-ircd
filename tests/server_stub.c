/* OPMOCK2 GENERATED CODE - DO NOT MODIFY */
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-prototypes"

#include "server_stub.h"
#include <stdio.h>
#include <string.h>

typedef struct
{
    char check_params;
} server_init_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_server_init_CALLBACK callback;
    server_init_call calls[MAX_FUNC_CALL];
} server_init_struct;

static server_init_struct server_init_struct_inst;

typedef struct
{
    struct _Client * to_return;
    char check_params;
} server_get_this_server_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_server_get_this_server_CALLBACK callback;
    server_get_this_server_call calls[MAX_FUNC_CALL];
} server_get_this_server_struct;

static server_get_this_server_struct server_get_this_server_struct_inst;

static void opmock_reset_all_mocks_in_this_header()
{
    server_init_MockReset();
    server_get_this_server_MockReset();
}

static void opmock_verify_all_mocks_in_this_header()
{
    server_init_VerifyMock();
    server_get_this_server_VerifyMock();
}

void server_init()
{
    int opmock_i;
    server_init_struct_inst.actualCalls++;

    if (server_init_struct_inst.callback != NULL)
    {
        server_init_struct_inst.callback (server_init_struct_inst.actualCalls);
        return;
    }
    if (server_init_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'server_init', returning random value.");
        return;
    }

    if(strcmp(opmock_get_current_call(), "void server_init ()") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'void server_init()',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (server_init_struct_inst.calls[0].check_params == 1) {
    }

    for(opmock_i = 1; opmock_i < server_init_struct_inst.expectedCalls; opmock_i++) {
        server_init_struct_inst.calls[opmock_i - 1] = server_init_struct_inst.calls[opmock_i];
    }

    server_init_struct_inst.expectedCalls--;
}

void server_init_MockReset()
{
    server_init_struct_inst.expectedCalls = 0;
    server_init_struct_inst.actualCalls = 0;
    server_init_struct_inst.callback = NULL;
}

void server_init_MockWithCallback(OPMOCK_server_init_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    server_init_struct_inst.callback = callback;
    server_init_struct_inst.expectedCalls = 0;
    server_init_struct_inst.actualCalls = 0;
}

void server_init_VerifyMock()
{
    if (server_init_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'server_init'",server_init_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void server_init_ExpectAndReturn ()
{
    if(server_init_struct_inst.callback != NULL)
    {
        server_init_MockReset ();
    }

    if(server_init_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting server_init_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"void server_init ()");
    server_init_struct_inst.calls[server_init_struct_inst.expectedCalls].check_params = 1;
    server_init_struct_inst.expectedCalls++;
}

Client * server_get_this_server()
{
    Client * default_res = (Client *)server_get_this_server_struct_inst.calls[0].to_return;
    int opmock_i;
    server_get_this_server_struct_inst.actualCalls++;

    if (server_get_this_server_struct_inst.callback != NULL)
    {
        return server_get_this_server_struct_inst.callback (server_get_this_server_struct_inst.actualCalls);
    }
    if (server_get_this_server_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'server_get_this_server', returning random value.");
        return default_res;
    }

    if(strcmp(opmock_get_current_call(), "Client * server_get_this_server ()") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'Client * server_get_this_server()',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (server_get_this_server_struct_inst.calls[0].check_params == 1) {
    }

    for(opmock_i = 1; opmock_i < server_get_this_server_struct_inst.expectedCalls; opmock_i++) {
        server_get_this_server_struct_inst.calls[opmock_i - 1] = server_get_this_server_struct_inst.calls[opmock_i];
    }

    server_get_this_server_struct_inst.expectedCalls--;
    return default_res;
}

void server_get_this_server_MockReset()
{
    server_get_this_server_struct_inst.expectedCalls = 0;
    server_get_this_server_struct_inst.actualCalls = 0;
    server_get_this_server_struct_inst.callback = NULL;
}

void server_get_this_server_MockWithCallback(OPMOCK_server_get_this_server_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    server_get_this_server_struct_inst.callback = callback;
    server_get_this_server_struct_inst.expectedCalls = 0;
    server_get_this_server_struct_inst.actualCalls = 0;
}

void server_get_this_server_VerifyMock()
{
    if (server_get_this_server_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'server_get_this_server'",server_get_this_server_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void server_get_this_server_ExpectAndReturn (Client * to_return)
{
    if(server_get_this_server_struct_inst.callback != NULL)
    {
        server_get_this_server_MockReset ();
    }

    if(server_get_this_server_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting server_get_this_server_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"Client * server_get_this_server ()");
    server_get_this_server_struct_inst.calls[server_get_this_server_struct_inst.expectedCalls].to_return = (struct _Client *) to_return;
    server_get_this_server_struct_inst.calls[server_get_this_server_struct_inst.expectedCalls].check_params = 1;
    server_get_this_server_struct_inst.expectedCalls++;
}

#pragma GCC diagnostic pop

