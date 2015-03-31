/* OPMOCK2 GENERATED CODE - DO NOT MODIFY */
#include "client_stub.h"
#include <stdio.h>
#include <string.h>

typedef struct
{
    char check_params;
} client_init_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_client_init_CALLBACK callback;
    client_init_call calls[MAX_FUNC_CALL];
} client_init_struct;

static client_init_struct client_init_struct_inst;

typedef struct
{
    struct _Client * to_return;
    char check_params;
} client_new_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_client_new_CALLBACK callback;
    client_new_call calls[MAX_FUNC_CALL];
} client_new_struct;

static client_new_struct client_new_struct_inst;

typedef struct
{
    void * client;
    OPMOCK_MATCHER match_client;
    char check_params;
} client_free_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_client_free_CALLBACK callback;
    client_free_call calls[MAX_FUNC_CALL];
} client_free_struct;

static client_free_struct client_free_struct_inst;

typedef struct
{
    void * client;
    void * handle;
    OPMOCK_MATCHER match_client;
    OPMOCK_MATCHER match_handle;
    _Bool to_return;
    char check_params;
} client_accept_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_client_accept_CALLBACK callback;
    client_accept_call calls[MAX_FUNC_CALL];
} client_accept_struct;

static client_accept_struct client_accept_struct_inst;

static void opmock_reset_all_mocks_in_this_header()
{
    client_init_MockReset();
    client_new_MockReset();
    client_free_MockReset();
    client_accept_MockReset();
}

static void opmock_verify_all_mocks_in_this_header()
{
    client_init_VerifyMock();
    client_new_VerifyMock();
    client_free_VerifyMock();
    client_accept_VerifyMock();
}

void client_init()
{
    int opmock_i;
    client_init_struct_inst.actualCalls++;

    if (client_init_struct_inst.callback != NULL)
    {
        client_init_struct_inst.callback (client_init_struct_inst.actualCalls);
        return;
    }
    if (client_init_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'client_init', returning random value.");
        return;
    }

    if(strcmp(opmock_get_current_call(), "void client_init ()") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'void client_init()',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (client_init_struct_inst.calls[0].check_params == 1) {
    }

    for(opmock_i = 1; opmock_i < client_init_struct_inst.expectedCalls; opmock_i++) {
        client_init_struct_inst.calls[opmock_i - 1] = client_init_struct_inst.calls[opmock_i];
    }

    client_init_struct_inst.expectedCalls--;
}

void client_init_MockReset()
{
    client_init_struct_inst.expectedCalls = 0;
    client_init_struct_inst.actualCalls = 0;
    client_init_struct_inst.callback = NULL;
}

void client_init_MockWithCallback(OPMOCK_client_init_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    client_init_struct_inst.callback = callback;
    client_init_struct_inst.expectedCalls = 0;
    client_init_struct_inst.actualCalls = 0;
}

void client_init_VerifyMock()
{
    if (client_init_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'client_init'",client_init_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void client_init_ExpectAndReturn ()
{
    if(client_init_struct_inst.callback != NULL)
    {
        client_init_MockReset ();
    }

    if(client_init_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting client_init_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"void client_init ()");
    client_init_struct_inst.calls[client_init_struct_inst.expectedCalls].check_params = 1;
    client_init_struct_inst.expectedCalls++;
}

Client * client_new()
{
    Client * default_res = (Client *)client_new_struct_inst.calls[0].to_return;
    int opmock_i;
    client_new_struct_inst.actualCalls++;

    if (client_new_struct_inst.callback != NULL)
    {
        return client_new_struct_inst.callback (client_new_struct_inst.actualCalls);
    }
    if (client_new_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'client_new', returning random value.");
        return default_res;
    }

    if(strcmp(opmock_get_current_call(), "Client * client_new ()") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'Client * client_new()',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (client_new_struct_inst.calls[0].check_params == 1) {
    }

    for(opmock_i = 1; opmock_i < client_new_struct_inst.expectedCalls; opmock_i++) {
        client_new_struct_inst.calls[opmock_i - 1] = client_new_struct_inst.calls[opmock_i];
    }

    client_new_struct_inst.expectedCalls--;
    return default_res;
}

void client_new_MockReset()
{
    client_new_struct_inst.expectedCalls = 0;
    client_new_struct_inst.actualCalls = 0;
    client_new_struct_inst.callback = NULL;
}

void client_new_MockWithCallback(OPMOCK_client_new_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    client_new_struct_inst.callback = callback;
    client_new_struct_inst.expectedCalls = 0;
    client_new_struct_inst.actualCalls = 0;
}

void client_new_VerifyMock()
{
    if (client_new_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'client_new'",client_new_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void client_new_ExpectAndReturn (Client * to_return)
{
    if(client_new_struct_inst.callback != NULL)
    {
        client_new_MockReset ();
    }

    if(client_new_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting client_new_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"Client * client_new ()");
    client_new_struct_inst.calls[client_new_struct_inst.expectedCalls].to_return = (struct _Client *) to_return;
    client_new_struct_inst.calls[client_new_struct_inst.expectedCalls].check_params = 1;
    client_new_struct_inst.expectedCalls++;
}

void client_free(Client * client)
{
    int opmock_i;
    client_free_struct_inst.actualCalls++;

    if (client_free_struct_inst.callback != NULL)
    {
        client_free_struct_inst.callback (client, client_free_struct_inst.actualCalls);
        return;
    }
    if (client_free_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'client_free', returning random value.");
        return;
    }

    if(strcmp(opmock_get_current_call(), "void client_free (Client * client)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'void client_free(Client * client)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (client_free_struct_inst.calls[0].check_params == 1) {
        if(client_free_struct_inst.calls[0].match_client) {
            void * val1 = (void *) &client_free_struct_inst.calls[0].client;
            void * val2 = (void *) &client;
            int match_result = client_free_struct_inst.calls[0].match_client(val1, val2, "client", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'client_free', %s",client_free_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < client_free_struct_inst.expectedCalls; opmock_i++) {
        client_free_struct_inst.calls[opmock_i - 1] = client_free_struct_inst.calls[opmock_i];
    }

    client_free_struct_inst.expectedCalls--;
}

void client_free_MockReset()
{
    client_free_struct_inst.expectedCalls = 0;
    client_free_struct_inst.actualCalls = 0;
    client_free_struct_inst.callback = NULL;
}

void client_free_MockWithCallback(OPMOCK_client_free_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    client_free_struct_inst.callback = callback;
    client_free_struct_inst.expectedCalls = 0;
    client_free_struct_inst.actualCalls = 0;
}

void client_free_VerifyMock()
{
    if (client_free_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'client_free'",client_free_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void client_free_ExpectAndReturn (Client * client, OPMOCK_MATCHER match_client)
{
    if(client_free_struct_inst.callback != NULL)
    {
        client_free_MockReset ();
    }

    if(client_free_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting client_free_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"void client_free (Client * client)");
    client_free_struct_inst.calls[client_free_struct_inst.expectedCalls].client = (void *)client;
    client_free_struct_inst.calls[client_free_struct_inst.expectedCalls].match_client = match_client;
    client_free_struct_inst.calls[client_free_struct_inst.expectedCalls].check_params = 1;
    client_free_struct_inst.expectedCalls++;
}

_Bool client_accept(Client * client, uv_stream_t * handle)
{
    _Bool default_res = (_Bool)client_accept_struct_inst.calls[0].to_return;
    int opmock_i;
    client_accept_struct_inst.actualCalls++;

    if (client_accept_struct_inst.callback != NULL)
    {
        return client_accept_struct_inst.callback (client, handle, client_accept_struct_inst.actualCalls);
    }
    if (client_accept_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'client_accept', returning random value.");
        return default_res;
    }

    if(strcmp(opmock_get_current_call(), "_Bool client_accept (Client * client, uv_stream_t * handle)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to '_Bool client_accept(Client * client, uv_stream_t * handle)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (client_accept_struct_inst.calls[0].check_params == 1) {
        if(client_accept_struct_inst.calls[0].match_client) {
            void * val1 = (void *) &client_accept_struct_inst.calls[0].client;
            void * val2 = (void *) &client;
            int match_result = client_accept_struct_inst.calls[0].match_client(val1, val2, "client", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'client_accept', %s",client_accept_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
        if(client_accept_struct_inst.calls[0].match_handle) {
            void * val1 = (void *) &client_accept_struct_inst.calls[0].handle;
            void * val2 = (void *) &handle;
            int match_result = client_accept_struct_inst.calls[0].match_handle(val1, val2, "handle", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'client_accept', %s",client_accept_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < client_accept_struct_inst.expectedCalls; opmock_i++) {
        client_accept_struct_inst.calls[opmock_i - 1] = client_accept_struct_inst.calls[opmock_i];
    }

    client_accept_struct_inst.expectedCalls--;
    return default_res;
}

void client_accept_MockReset()
{
    client_accept_struct_inst.expectedCalls = 0;
    client_accept_struct_inst.actualCalls = 0;
    client_accept_struct_inst.callback = NULL;
}

void client_accept_MockWithCallback(OPMOCK_client_accept_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    client_accept_struct_inst.callback = callback;
    client_accept_struct_inst.expectedCalls = 0;
    client_accept_struct_inst.actualCalls = 0;
}

void client_accept_VerifyMock()
{
    if (client_accept_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'client_accept'",client_accept_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void client_accept_ExpectAndReturn (Client * client, uv_stream_t * handle, _Bool to_return, OPMOCK_MATCHER match_client, OPMOCK_MATCHER match_handle)
{
    if(client_accept_struct_inst.callback != NULL)
    {
        client_accept_MockReset ();
    }

    if(client_accept_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting client_accept_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"_Bool client_accept (Client * client, uv_stream_t * handle)");
    client_accept_struct_inst.calls[client_accept_struct_inst.expectedCalls].client = (void *)client;
    client_accept_struct_inst.calls[client_accept_struct_inst.expectedCalls].handle = (void *)handle;
    client_accept_struct_inst.calls[client_accept_struct_inst.expectedCalls].match_client = match_client;
    client_accept_struct_inst.calls[client_accept_struct_inst.expectedCalls].match_handle = match_handle;
    client_accept_struct_inst.calls[client_accept_struct_inst.expectedCalls].to_return = (_Bool) to_return;
    client_accept_struct_inst.calls[client_accept_struct_inst.expectedCalls].check_params = 1;
    client_accept_struct_inst.expectedCalls++;
}

