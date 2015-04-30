/* OPMOCK2 GENERATED CODE - DO NOT MODIFY */
#include "connection_stub.h"
#include <stdio.h>
#include <string.h>

typedef struct
{
    void * handle;
    OPMOCK_MATCHER match_handle;
    char check_params;
} connection_accept_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_connection_accept_CALLBACK callback;
    connection_accept_call calls[MAX_FUNC_CALL];
} connection_accept_struct;

static connection_accept_struct connection_accept_struct_inst;

typedef struct
{
    void * client;
    void * buffer;
    OPMOCK_MATCHER match_client;
    OPMOCK_MATCHER match_buffer;
    char check_params;
} connection_send_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_connection_send_CALLBACK callback;
    connection_send_call calls[MAX_FUNC_CALL];
} connection_send_struct;

static connection_send_struct connection_send_struct_inst;

static void opmock_reset_all_mocks_in_this_header()
{
    connection_accept_MockReset();
    connection_send_MockReset();
}

static void opmock_verify_all_mocks_in_this_header()
{
    connection_accept_VerifyMock();
    connection_send_VerifyMock();
}

void connection_accept(uv_stream_t * handle)
{
    int opmock_i;
    connection_accept_struct_inst.actualCalls++;

    if (connection_accept_struct_inst.callback != NULL)
    {
        connection_accept_struct_inst.callback (handle, connection_accept_struct_inst.actualCalls);
        return;
    }
    if (connection_accept_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'connection_accept', returning random value.");
        return;
    }

    if(strcmp(opmock_get_current_call(), "void connection_accept (uv_stream_t * handle)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'void connection_accept(uv_stream_t * handle)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (connection_accept_struct_inst.calls[0].check_params == 1) {
        if(connection_accept_struct_inst.calls[0].match_handle) {
            void * val1 = (void *) &connection_accept_struct_inst.calls[0].handle;
            void * val2 = (void *) &handle;
            int match_result = connection_accept_struct_inst.calls[0].match_handle(val1, val2, "handle", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'connection_accept', %s",connection_accept_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < connection_accept_struct_inst.expectedCalls; opmock_i++) {
        connection_accept_struct_inst.calls[opmock_i - 1] = connection_accept_struct_inst.calls[opmock_i];
    }

    connection_accept_struct_inst.expectedCalls--;
}

void connection_accept_MockReset()
{
    connection_accept_struct_inst.expectedCalls = 0;
    connection_accept_struct_inst.actualCalls = 0;
    connection_accept_struct_inst.callback = NULL;
}

void connection_accept_MockWithCallback(OPMOCK_connection_accept_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    connection_accept_struct_inst.callback = callback;
    connection_accept_struct_inst.expectedCalls = 0;
    connection_accept_struct_inst.actualCalls = 0;
}

void connection_accept_VerifyMock()
{
    if (connection_accept_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'connection_accept'",connection_accept_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void connection_accept_ExpectAndReturn (uv_stream_t * handle, OPMOCK_MATCHER match_handle)
{
    if(connection_accept_struct_inst.callback != NULL)
    {
        connection_accept_MockReset ();
    }

    if(connection_accept_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting connection_accept_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"void connection_accept (uv_stream_t * handle)");
    connection_accept_struct_inst.calls[connection_accept_struct_inst.expectedCalls].handle = (void *)handle;
    connection_accept_struct_inst.calls[connection_accept_struct_inst.expectedCalls].match_handle = match_handle;
    connection_accept_struct_inst.calls[connection_accept_struct_inst.expectedCalls].check_params = 1;
    connection_accept_struct_inst.expectedCalls++;
}

void connection_send(Client * client, char * buffer)
{
    int opmock_i;
    connection_send_struct_inst.actualCalls++;

    if (connection_send_struct_inst.callback != NULL)
    {
        connection_send_struct_inst.callback (client, buffer, connection_send_struct_inst.actualCalls);
        return;
    }
    if (connection_send_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'connection_send', returning random value.");
        return;
    }

    if(strcmp(opmock_get_current_call(), "void connection_send (Client * client, char * buffer)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'void connection_send(Client * client, char * buffer)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (connection_send_struct_inst.calls[0].check_params == 1) {
        if(connection_send_struct_inst.calls[0].match_client) {
            void * val1 = (void *) &connection_send_struct_inst.calls[0].client;
            void * val2 = (void *) &client;
            int match_result = connection_send_struct_inst.calls[0].match_client(val1, val2, "client", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'connection_send', %s",connection_send_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
        if(connection_send_struct_inst.calls[0].match_buffer) {
            void * val1 = (void *) &connection_send_struct_inst.calls[0].buffer;
            void * val2 = (void *) &buffer;
            int match_result = connection_send_struct_inst.calls[0].match_buffer(val1, val2, "buffer", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'connection_send', %s",connection_send_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < connection_send_struct_inst.expectedCalls; opmock_i++) {
        connection_send_struct_inst.calls[opmock_i - 1] = connection_send_struct_inst.calls[opmock_i];
    }

    connection_send_struct_inst.expectedCalls--;
}

void connection_send_MockReset()
{
    connection_send_struct_inst.expectedCalls = 0;
    connection_send_struct_inst.actualCalls = 0;
    connection_send_struct_inst.callback = NULL;
}

void connection_send_MockWithCallback(OPMOCK_connection_send_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    connection_send_struct_inst.callback = callback;
    connection_send_struct_inst.expectedCalls = 0;
    connection_send_struct_inst.actualCalls = 0;
}

void connection_send_VerifyMock()
{
    if (connection_send_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'connection_send'",connection_send_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void connection_send_ExpectAndReturn (Client * client, char * buffer, OPMOCK_MATCHER match_client, OPMOCK_MATCHER match_buffer)
{
    if(connection_send_struct_inst.callback != NULL)
    {
        connection_send_MockReset ();
    }

    if(connection_send_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting connection_send_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"void connection_send (Client * client, char * buffer)");
    connection_send_struct_inst.calls[connection_send_struct_inst.expectedCalls].client = (void *)client;
    connection_send_struct_inst.calls[connection_send_struct_inst.expectedCalls].buffer = (void *)buffer;
    connection_send_struct_inst.calls[connection_send_struct_inst.expectedCalls].match_client = match_client;
    connection_send_struct_inst.calls[connection_send_struct_inst.expectedCalls].match_buffer = match_buffer;
    connection_send_struct_inst.calls[connection_send_struct_inst.expectedCalls].check_params = 1;
    connection_send_struct_inst.expectedCalls++;
}

