/* OPMOCK2 GENERATED CODE - DO NOT MODIFY */
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-prototypes"
#pragma GCC diagnostic ignored "-Wshadow"

#include "buffer_stub.h"
#include <stdio.h>
#include <string.h>

typedef struct
{
    struct _Buffer * to_return;
    char check_params;
} buffer_new_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_buffer_new_CALLBACK callback;
    buffer_new_call calls[MAX_FUNC_CALL];
} buffer_new_struct;

static buffer_new_struct buffer_new_struct_inst;

typedef struct
{
    void * buffer;
    void * data;
    unsigned long len;
    OPMOCK_MATCHER match_buffer;
    OPMOCK_MATCHER match_data;
    OPMOCK_MATCHER match_len;
    char check_params;
} buffer_push_back_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_buffer_push_back_CALLBACK callback;
    buffer_push_back_call calls[MAX_FUNC_CALL];
} buffer_push_back_struct;

static buffer_push_back_struct buffer_push_back_struct_inst;

typedef struct
{
    void * buffer;
    unsigned long len;
    OPMOCK_MATCHER match_buffer;
    OPMOCK_MATCHER match_len;
     char * to_return;
    char check_params;
} buffer_pop_front_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_buffer_pop_front_CALLBACK callback;
    buffer_pop_front_call calls[MAX_FUNC_CALL];
} buffer_pop_front_struct;

static buffer_pop_front_struct buffer_pop_front_struct_inst;

static void opmock_reset_all_mocks_in_this_header()
{
    buffer_new_MockReset();
    buffer_push_back_MockReset();
    buffer_pop_front_MockReset();
}

static void opmock_verify_all_mocks_in_this_header()
{
    buffer_new_VerifyMock();
    buffer_push_back_VerifyMock();
    buffer_pop_front_VerifyMock();
}

Buffer * buffer_new()
{
    Buffer * default_res = (Buffer *)buffer_new_struct_inst.calls[0].to_return;
    int opmock_i;
    buffer_new_struct_inst.actualCalls++;

    if (buffer_new_struct_inst.callback != NULL)
    {
        return buffer_new_struct_inst.callback (buffer_new_struct_inst.actualCalls);
    }
    if (buffer_new_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'buffer_new', returning random value.");
        return default_res;
    }

    if(strcmp(opmock_get_current_call(), "Buffer * buffer_new ()") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'Buffer * buffer_new()',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (buffer_new_struct_inst.calls[0].check_params == 1) {
    }

    for(opmock_i = 1; opmock_i < buffer_new_struct_inst.expectedCalls; opmock_i++) {
        buffer_new_struct_inst.calls[opmock_i - 1] = buffer_new_struct_inst.calls[opmock_i];
    }

    buffer_new_struct_inst.expectedCalls--;
    return default_res;
}

void buffer_new_MockReset()
{
    buffer_new_struct_inst.expectedCalls = 0;
    buffer_new_struct_inst.actualCalls = 0;
    buffer_new_struct_inst.callback = NULL;
}

void buffer_new_MockWithCallback(OPMOCK_buffer_new_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    buffer_new_struct_inst.callback = callback;
    buffer_new_struct_inst.expectedCalls = 0;
    buffer_new_struct_inst.actualCalls = 0;
}

void buffer_new_VerifyMock()
{
    if (buffer_new_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'buffer_new'",buffer_new_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void buffer_new_ExpectAndReturn (Buffer * to_return)
{
    if(buffer_new_struct_inst.callback != NULL)
    {
        buffer_new_MockReset ();
    }

    if(buffer_new_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting buffer_new_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"Buffer * buffer_new ()");
    buffer_new_struct_inst.calls[buffer_new_struct_inst.expectedCalls].to_return = (struct _Buffer *) to_return;
    buffer_new_struct_inst.calls[buffer_new_struct_inst.expectedCalls].check_params = 1;
    buffer_new_struct_inst.expectedCalls++;
}

void buffer_push_back(Buffer * buffer, char * data, size_t len)
{
    int opmock_i;
    buffer_push_back_struct_inst.actualCalls++;

    if (buffer_push_back_struct_inst.callback != NULL)
    {
        buffer_push_back_struct_inst.callback (buffer, data, len, buffer_push_back_struct_inst.actualCalls);
        return;
    }
    if (buffer_push_back_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'buffer_push_back', returning random value.");
        return;
    }

    if(strcmp(opmock_get_current_call(), "void buffer_push_back (Buffer * buffer, char * data, size_t len)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'void buffer_push_back(Buffer * buffer, char * data, size_t len)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (buffer_push_back_struct_inst.calls[0].check_params == 1) {
        if(buffer_push_back_struct_inst.calls[0].match_buffer) {
            void * val1 = (void *) &buffer_push_back_struct_inst.calls[0].buffer;
            void * val2 = (void *) &buffer;
            int match_result = buffer_push_back_struct_inst.calls[0].match_buffer(val1, val2, "buffer", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'buffer_push_back', %s",buffer_push_back_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
        if(buffer_push_back_struct_inst.calls[0].match_data) {
            void * val1 = (void *) &buffer_push_back_struct_inst.calls[0].data;
            void * val2 = (void *) &data;
            int match_result = buffer_push_back_struct_inst.calls[0].match_data(val1, val2, "data", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'buffer_push_back', %s",buffer_push_back_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
        if(buffer_push_back_struct_inst.calls[0].match_len) {
            void * val1 = (void *) &buffer_push_back_struct_inst.calls[0].len;
            void * val2 = (void *) &len;
            int match_result = buffer_push_back_struct_inst.calls[0].match_len(val1, val2, "len", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'buffer_push_back', %s",buffer_push_back_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < buffer_push_back_struct_inst.expectedCalls; opmock_i++) {
        buffer_push_back_struct_inst.calls[opmock_i - 1] = buffer_push_back_struct_inst.calls[opmock_i];
    }

    buffer_push_back_struct_inst.expectedCalls--;
}

void buffer_push_back_MockReset()
{
    buffer_push_back_struct_inst.expectedCalls = 0;
    buffer_push_back_struct_inst.actualCalls = 0;
    buffer_push_back_struct_inst.callback = NULL;
}

void buffer_push_back_MockWithCallback(OPMOCK_buffer_push_back_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    buffer_push_back_struct_inst.callback = callback;
    buffer_push_back_struct_inst.expectedCalls = 0;
    buffer_push_back_struct_inst.actualCalls = 0;
}

void buffer_push_back_VerifyMock()
{
    if (buffer_push_back_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'buffer_push_back'",buffer_push_back_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void buffer_push_back_ExpectAndReturn (Buffer * buffer, char * data, size_t len, OPMOCK_MATCHER match_buffer, OPMOCK_MATCHER match_data, OPMOCK_MATCHER match_len)
{
    if(buffer_push_back_struct_inst.callback != NULL)
    {
        buffer_push_back_MockReset ();
    }

    if(buffer_push_back_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting buffer_push_back_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"void buffer_push_back (Buffer * buffer, char * data, size_t len)");
    buffer_push_back_struct_inst.calls[buffer_push_back_struct_inst.expectedCalls].buffer = (void *)buffer;
    buffer_push_back_struct_inst.calls[buffer_push_back_struct_inst.expectedCalls].data = (void *)data;
    buffer_push_back_struct_inst.calls[buffer_push_back_struct_inst.expectedCalls].len = (unsigned long)len;
    buffer_push_back_struct_inst.calls[buffer_push_back_struct_inst.expectedCalls].match_buffer = match_buffer;
    buffer_push_back_struct_inst.calls[buffer_push_back_struct_inst.expectedCalls].match_data = match_data;
    buffer_push_back_struct_inst.calls[buffer_push_back_struct_inst.expectedCalls].match_len = match_len;
    buffer_push_back_struct_inst.calls[buffer_push_back_struct_inst.expectedCalls].check_params = 1;
    buffer_push_back_struct_inst.expectedCalls++;
}

const char * buffer_pop_front(Buffer * buffer, size_t len)
{
    const char * default_res = (const char *)buffer_pop_front_struct_inst.calls[0].to_return;
    int opmock_i;
    buffer_pop_front_struct_inst.actualCalls++;

    if (buffer_pop_front_struct_inst.callback != NULL)
    {
        return buffer_pop_front_struct_inst.callback (buffer, len, buffer_pop_front_struct_inst.actualCalls);
    }
    if (buffer_pop_front_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'buffer_pop_front', returning random value.");
        return default_res;
    }

    if(strcmp(opmock_get_current_call(), "const char * buffer_pop_front (Buffer * buffer, size_t len)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'const char * buffer_pop_front(Buffer * buffer, size_t len)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (buffer_pop_front_struct_inst.calls[0].check_params == 1) {
        if(buffer_pop_front_struct_inst.calls[0].match_buffer) {
            void * val1 = (void *) &buffer_pop_front_struct_inst.calls[0].buffer;
            void * val2 = (void *) &buffer;
            int match_result = buffer_pop_front_struct_inst.calls[0].match_buffer(val1, val2, "buffer", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'buffer_pop_front', %s",buffer_pop_front_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
        if(buffer_pop_front_struct_inst.calls[0].match_len) {
            void * val1 = (void *) &buffer_pop_front_struct_inst.calls[0].len;
            void * val2 = (void *) &len;
            int match_result = buffer_pop_front_struct_inst.calls[0].match_len(val1, val2, "len", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'buffer_pop_front', %s",buffer_pop_front_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < buffer_pop_front_struct_inst.expectedCalls; opmock_i++) {
        buffer_pop_front_struct_inst.calls[opmock_i - 1] = buffer_pop_front_struct_inst.calls[opmock_i];
    }

    buffer_pop_front_struct_inst.expectedCalls--;
    return default_res;
}

void buffer_pop_front_MockReset()
{
    buffer_pop_front_struct_inst.expectedCalls = 0;
    buffer_pop_front_struct_inst.actualCalls = 0;
    buffer_pop_front_struct_inst.callback = NULL;
}

void buffer_pop_front_MockWithCallback(OPMOCK_buffer_pop_front_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    buffer_pop_front_struct_inst.callback = callback;
    buffer_pop_front_struct_inst.expectedCalls = 0;
    buffer_pop_front_struct_inst.actualCalls = 0;
}

void buffer_pop_front_VerifyMock()
{
    if (buffer_pop_front_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'buffer_pop_front'",buffer_pop_front_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void buffer_pop_front_ExpectAndReturn (Buffer * buffer, size_t len, const char * to_return, OPMOCK_MATCHER match_buffer, OPMOCK_MATCHER match_len)
{
    if(buffer_pop_front_struct_inst.callback != NULL)
    {
        buffer_pop_front_MockReset ();
    }

    if(buffer_pop_front_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting buffer_pop_front_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"const char * buffer_pop_front (Buffer * buffer, size_t len)");
    buffer_pop_front_struct_inst.calls[buffer_pop_front_struct_inst.expectedCalls].buffer = (void *)buffer;
    buffer_pop_front_struct_inst.calls[buffer_pop_front_struct_inst.expectedCalls].len = (unsigned long)len;
    buffer_pop_front_struct_inst.calls[buffer_pop_front_struct_inst.expectedCalls].match_buffer = match_buffer;
    buffer_pop_front_struct_inst.calls[buffer_pop_front_struct_inst.expectedCalls].match_len = match_len;
    buffer_pop_front_struct_inst.calls[buffer_pop_front_struct_inst.expectedCalls].to_return = ( char *) to_return;
    buffer_pop_front_struct_inst.calls[buffer_pop_front_struct_inst.expectedCalls].check_params = 1;
    buffer_pop_front_struct_inst.expectedCalls++;
}

#pragma GCC diagnostic push

