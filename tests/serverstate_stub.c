/* OPMOCK2 GENERATED CODE - DO NOT MODIFY */
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-prototypes"

#include "serverstate_stub.h"
#include <stdio.h>
#include <string.h>

typedef struct
{
     char * to_return;
    char check_params;
} serverstate_get_config_path_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_serverstate_get_config_path_CALLBACK callback;
    serverstate_get_config_path_call calls[MAX_FUNC_CALL];
} serverstate_get_config_path_struct;

static serverstate_get_config_path_struct serverstate_get_config_path_struct_inst;

typedef struct
{
    struct uv_loop_s * to_return;
    char check_params;
} serverstate_get_event_loop_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_serverstate_get_event_loop_CALLBACK callback;
    serverstate_get_event_loop_call calls[MAX_FUNC_CALL];
} serverstate_get_event_loop_struct;

static serverstate_get_event_loop_struct serverstate_get_event_loop_struct_inst;

typedef struct
{
    void * arg1;
    OPMOCK_MATCHER match_arg1;
    char check_params;
} serverstate_set_config_path_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_serverstate_set_config_path_CALLBACK callback;
    serverstate_set_config_path_call calls[MAX_FUNC_CALL];
} serverstate_set_config_path_struct;

static serverstate_set_config_path_struct serverstate_set_config_path_struct_inst;

typedef struct
{
    void * arg1;
    OPMOCK_MATCHER match_arg1;
    char check_params;
} serverstate_set_event_loop_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_serverstate_set_event_loop_CALLBACK callback;
    serverstate_set_event_loop_call calls[MAX_FUNC_CALL];
} serverstate_set_event_loop_struct;

static serverstate_set_event_loop_struct serverstate_set_event_loop_struct_inst;

static void opmock_reset_all_mocks_in_this_header()
{
    serverstate_get_config_path_MockReset();
    serverstate_get_event_loop_MockReset();
    serverstate_set_config_path_MockReset();
    serverstate_set_event_loop_MockReset();
}

static void opmock_verify_all_mocks_in_this_header()
{
    serverstate_get_config_path_VerifyMock();
    serverstate_get_event_loop_VerifyMock();
    serverstate_set_config_path_VerifyMock();
    serverstate_set_event_loop_VerifyMock();
}

const char * serverstate_get_config_path()
{
    const char * default_res = (const char *)serverstate_get_config_path_struct_inst.calls[0].to_return;
    int opmock_i;
    serverstate_get_config_path_struct_inst.actualCalls++;

    if (serverstate_get_config_path_struct_inst.callback != NULL)
    {
        return serverstate_get_config_path_struct_inst.callback (serverstate_get_config_path_struct_inst.actualCalls);
    }
    if (serverstate_get_config_path_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'serverstate_get_config_path', returning random value.");
        return default_res;
    }

    if(strcmp(opmock_get_current_call(), "const char * serverstate_get_config_path ()") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'const char * serverstate_get_config_path()',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (serverstate_get_config_path_struct_inst.calls[0].check_params == 1) {
    }

    for(opmock_i = 1; opmock_i < serverstate_get_config_path_struct_inst.expectedCalls; opmock_i++) {
        serverstate_get_config_path_struct_inst.calls[opmock_i - 1] = serverstate_get_config_path_struct_inst.calls[opmock_i];
    }

    serverstate_get_config_path_struct_inst.expectedCalls--;
    return default_res;
}

void serverstate_get_config_path_MockReset()
{
    serverstate_get_config_path_struct_inst.expectedCalls = 0;
    serverstate_get_config_path_struct_inst.actualCalls = 0;
    serverstate_get_config_path_struct_inst.callback = NULL;
}

void serverstate_get_config_path_MockWithCallback(OPMOCK_serverstate_get_config_path_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    serverstate_get_config_path_struct_inst.callback = callback;
    serverstate_get_config_path_struct_inst.expectedCalls = 0;
    serverstate_get_config_path_struct_inst.actualCalls = 0;
}

void serverstate_get_config_path_VerifyMock()
{
    if (serverstate_get_config_path_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'serverstate_get_config_path'",serverstate_get_config_path_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void serverstate_get_config_path_ExpectAndReturn (const char * to_return)
{
    if(serverstate_get_config_path_struct_inst.callback != NULL)
    {
        serverstate_get_config_path_MockReset ();
    }

    if(serverstate_get_config_path_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting serverstate_get_config_path_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"const char * serverstate_get_config_path ()");
    serverstate_get_config_path_struct_inst.calls[serverstate_get_config_path_struct_inst.expectedCalls].to_return = ( char *) to_return;
    serverstate_get_config_path_struct_inst.calls[serverstate_get_config_path_struct_inst.expectedCalls].check_params = 1;
    serverstate_get_config_path_struct_inst.expectedCalls++;
}

uv_loop_t * serverstate_get_event_loop()
{
    uv_loop_t * default_res = (uv_loop_t *)serverstate_get_event_loop_struct_inst.calls[0].to_return;
    int opmock_i;
    serverstate_get_event_loop_struct_inst.actualCalls++;

    if (serverstate_get_event_loop_struct_inst.callback != NULL)
    {
        return serverstate_get_event_loop_struct_inst.callback (serverstate_get_event_loop_struct_inst.actualCalls);
    }
    if (serverstate_get_event_loop_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'serverstate_get_event_loop', returning random value.");
        return default_res;
    }

    if(strcmp(opmock_get_current_call(), "uv_loop_t * serverstate_get_event_loop ()") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'uv_loop_t * serverstate_get_event_loop()',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (serverstate_get_event_loop_struct_inst.calls[0].check_params == 1) {
    }

    for(opmock_i = 1; opmock_i < serverstate_get_event_loop_struct_inst.expectedCalls; opmock_i++) {
        serverstate_get_event_loop_struct_inst.calls[opmock_i - 1] = serverstate_get_event_loop_struct_inst.calls[opmock_i];
    }

    serverstate_get_event_loop_struct_inst.expectedCalls--;
    return default_res;
}

void serverstate_get_event_loop_MockReset()
{
    serverstate_get_event_loop_struct_inst.expectedCalls = 0;
    serverstate_get_event_loop_struct_inst.actualCalls = 0;
    serverstate_get_event_loop_struct_inst.callback = NULL;
}

void serverstate_get_event_loop_MockWithCallback(OPMOCK_serverstate_get_event_loop_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    serverstate_get_event_loop_struct_inst.callback = callback;
    serverstate_get_event_loop_struct_inst.expectedCalls = 0;
    serverstate_get_event_loop_struct_inst.actualCalls = 0;
}

void serverstate_get_event_loop_VerifyMock()
{
    if (serverstate_get_event_loop_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'serverstate_get_event_loop'",serverstate_get_event_loop_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void serverstate_get_event_loop_ExpectAndReturn (uv_loop_t * to_return)
{
    if(serverstate_get_event_loop_struct_inst.callback != NULL)
    {
        serverstate_get_event_loop_MockReset ();
    }

    if(serverstate_get_event_loop_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting serverstate_get_event_loop_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"uv_loop_t * serverstate_get_event_loop ()");
    serverstate_get_event_loop_struct_inst.calls[serverstate_get_event_loop_struct_inst.expectedCalls].to_return = (struct uv_loop_s *) to_return;
    serverstate_get_event_loop_struct_inst.calls[serverstate_get_event_loop_struct_inst.expectedCalls].check_params = 1;
    serverstate_get_event_loop_struct_inst.expectedCalls++;
}

void serverstate_set_config_path(const char * arg1)
{
    int opmock_i;
    serverstate_set_config_path_struct_inst.actualCalls++;

    if (serverstate_set_config_path_struct_inst.callback != NULL)
    {
        serverstate_set_config_path_struct_inst.callback (arg1, serverstate_set_config_path_struct_inst.actualCalls);
        return;
    }
    if (serverstate_set_config_path_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'serverstate_set_config_path', returning random value.");
        return;
    }

    if(strcmp(opmock_get_current_call(), "void serverstate_set_config_path (const char * arg1)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'void serverstate_set_config_path(const char * arg1)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (serverstate_set_config_path_struct_inst.calls[0].check_params == 1) {
        if(serverstate_set_config_path_struct_inst.calls[0].match_arg1) {
            void * val1 = (void *) &serverstate_set_config_path_struct_inst.calls[0].arg1;
            void * val2 = (void *) &arg1;
            int match_result = serverstate_set_config_path_struct_inst.calls[0].match_arg1(val1, val2, "arg1", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'serverstate_set_config_path', %s",serverstate_set_config_path_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < serverstate_set_config_path_struct_inst.expectedCalls; opmock_i++) {
        serverstate_set_config_path_struct_inst.calls[opmock_i - 1] = serverstate_set_config_path_struct_inst.calls[opmock_i];
    }

    serverstate_set_config_path_struct_inst.expectedCalls--;
}

void serverstate_set_config_path_MockReset()
{
    serverstate_set_config_path_struct_inst.expectedCalls = 0;
    serverstate_set_config_path_struct_inst.actualCalls = 0;
    serverstate_set_config_path_struct_inst.callback = NULL;
}

void serverstate_set_config_path_MockWithCallback(OPMOCK_serverstate_set_config_path_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    serverstate_set_config_path_struct_inst.callback = callback;
    serverstate_set_config_path_struct_inst.expectedCalls = 0;
    serverstate_set_config_path_struct_inst.actualCalls = 0;
}

void serverstate_set_config_path_VerifyMock()
{
    if (serverstate_set_config_path_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'serverstate_set_config_path'",serverstate_set_config_path_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void serverstate_set_config_path_ExpectAndReturn (const char * arg1, OPMOCK_MATCHER match_arg1)
{
    if(serverstate_set_config_path_struct_inst.callback != NULL)
    {
        serverstate_set_config_path_MockReset ();
    }

    if(serverstate_set_config_path_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting serverstate_set_config_path_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"void serverstate_set_config_path (const char * arg1)");
    serverstate_set_config_path_struct_inst.calls[serverstate_set_config_path_struct_inst.expectedCalls].arg1 = (void *)arg1;
    serverstate_set_config_path_struct_inst.calls[serverstate_set_config_path_struct_inst.expectedCalls].match_arg1 = match_arg1;
    serverstate_set_config_path_struct_inst.calls[serverstate_set_config_path_struct_inst.expectedCalls].check_params = 1;
    serverstate_set_config_path_struct_inst.expectedCalls++;
}

void serverstate_set_event_loop(uv_loop_t * arg1)
{
    int opmock_i;
    serverstate_set_event_loop_struct_inst.actualCalls++;

    if (serverstate_set_event_loop_struct_inst.callback != NULL)
    {
        serverstate_set_event_loop_struct_inst.callback (arg1, serverstate_set_event_loop_struct_inst.actualCalls);
        return;
    }
    if (serverstate_set_event_loop_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'serverstate_set_event_loop', returning random value.");
        return;
    }

    if(strcmp(opmock_get_current_call(), "void serverstate_set_event_loop (uv_loop_t * arg1)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'void serverstate_set_event_loop(uv_loop_t * arg1)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (serverstate_set_event_loop_struct_inst.calls[0].check_params == 1) {
        if(serverstate_set_event_loop_struct_inst.calls[0].match_arg1) {
            void * val1 = (void *) &serverstate_set_event_loop_struct_inst.calls[0].arg1;
            void * val2 = (void *) &arg1;
            int match_result = serverstate_set_event_loop_struct_inst.calls[0].match_arg1(val1, val2, "arg1", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'serverstate_set_event_loop', %s",serverstate_set_event_loop_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < serverstate_set_event_loop_struct_inst.expectedCalls; opmock_i++) {
        serverstate_set_event_loop_struct_inst.calls[opmock_i - 1] = serverstate_set_event_loop_struct_inst.calls[opmock_i];
    }

    serverstate_set_event_loop_struct_inst.expectedCalls--;
}

void serverstate_set_event_loop_MockReset()
{
    serverstate_set_event_loop_struct_inst.expectedCalls = 0;
    serverstate_set_event_loop_struct_inst.actualCalls = 0;
    serverstate_set_event_loop_struct_inst.callback = NULL;
}

void serverstate_set_event_loop_MockWithCallback(OPMOCK_serverstate_set_event_loop_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    serverstate_set_event_loop_struct_inst.callback = callback;
    serverstate_set_event_loop_struct_inst.expectedCalls = 0;
    serverstate_set_event_loop_struct_inst.actualCalls = 0;
}

void serverstate_set_event_loop_VerifyMock()
{
    if (serverstate_set_event_loop_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'serverstate_set_event_loop'",serverstate_set_event_loop_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void serverstate_set_event_loop_ExpectAndReturn (uv_loop_t * arg1, OPMOCK_MATCHER match_arg1)
{
    if(serverstate_set_event_loop_struct_inst.callback != NULL)
    {
        serverstate_set_event_loop_MockReset ();
    }

    if(serverstate_set_event_loop_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting serverstate_set_event_loop_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"void serverstate_set_event_loop (uv_loop_t * arg1)");
    serverstate_set_event_loop_struct_inst.calls[serverstate_set_event_loop_struct_inst.expectedCalls].arg1 = (void *)arg1;
    serverstate_set_event_loop_struct_inst.calls[serverstate_set_event_loop_struct_inst.expectedCalls].match_arg1 = match_arg1;
    serverstate_set_event_loop_struct_inst.calls[serverstate_set_event_loop_struct_inst.expectedCalls].check_params = 1;
    serverstate_set_event_loop_struct_inst.expectedCalls++;
}

#pragma GCC diagnostic pop

