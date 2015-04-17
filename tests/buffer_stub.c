/* OPMOCK2 GENERATED CODE - DO NOT MODIFY */
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
} buffer_add_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_buffer_add_CALLBACK callback;
    buffer_add_call calls[MAX_FUNC_CALL];
} buffer_add_struct;

static buffer_add_struct buffer_add_struct_inst;

typedef struct
{
    void * buffer;
    unsigned long len;
    OPMOCK_MATCHER match_buffer;
    OPMOCK_MATCHER match_len;
    char check_params;
} buffer_remove_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_buffer_remove_CALLBACK callback;
    buffer_remove_call calls[MAX_FUNC_CALL];
} buffer_remove_struct;

static buffer_remove_struct buffer_remove_struct_inst;

typedef struct
{
    void * buffer;
    OPMOCK_MATCHER match_buffer;
    struct _ListEntry * to_return;
    char check_params;
} buffer_get_start_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_buffer_get_start_CALLBACK callback;
    buffer_get_start_call calls[MAX_FUNC_CALL];
} buffer_get_start_struct;

static buffer_get_start_struct buffer_get_start_struct_inst;

static void opmock_reset_all_mocks_in_this_header()
{
    buffer_new_MockReset();
    buffer_add_MockReset();
    buffer_remove_MockReset();
    buffer_get_start_MockReset();
}

static void opmock_verify_all_mocks_in_this_header()
{
    buffer_new_VerifyMock();
    buffer_add_VerifyMock();
    buffer_remove_VerifyMock();
    buffer_get_start_VerifyMock();
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

void buffer_add(Buffer * buffer, char * data, size_t len)
{
    int opmock_i;
    buffer_add_struct_inst.actualCalls++;

    if (buffer_add_struct_inst.callback != NULL)
    {
        buffer_add_struct_inst.callback (buffer, data, len, buffer_add_struct_inst.actualCalls);
        return;
    }
    if (buffer_add_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'buffer_add', returning random value.");
        return;
    }

    if(strcmp(opmock_get_current_call(), "void buffer_add (Buffer * buffer, char * data, size_t len)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'void buffer_add(Buffer * buffer, char * data, size_t len)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (buffer_add_struct_inst.calls[0].check_params == 1) {
        if(buffer_add_struct_inst.calls[0].match_buffer) {
            void * val1 = (void *) &buffer_add_struct_inst.calls[0].buffer;
            void * val2 = (void *) &buffer;
            int match_result = buffer_add_struct_inst.calls[0].match_buffer(val1, val2, "buffer", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'buffer_add', %s",buffer_add_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
        if(buffer_add_struct_inst.calls[0].match_data) {
            void * val1 = (void *) &buffer_add_struct_inst.calls[0].data;
            void * val2 = (void *) &data;
            int match_result = buffer_add_struct_inst.calls[0].match_data(val1, val2, "data", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'buffer_add', %s",buffer_add_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
        if(buffer_add_struct_inst.calls[0].match_len) {
            void * val1 = (void *) &buffer_add_struct_inst.calls[0].len;
            void * val2 = (void *) &len;
            int match_result = buffer_add_struct_inst.calls[0].match_len(val1, val2, "len", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'buffer_add', %s",buffer_add_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < buffer_add_struct_inst.expectedCalls; opmock_i++) {
        buffer_add_struct_inst.calls[opmock_i - 1] = buffer_add_struct_inst.calls[opmock_i];
    }

    buffer_add_struct_inst.expectedCalls--;
}

void buffer_add_MockReset()
{
    buffer_add_struct_inst.expectedCalls = 0;
    buffer_add_struct_inst.actualCalls = 0;
    buffer_add_struct_inst.callback = NULL;
}

void buffer_add_MockWithCallback(OPMOCK_buffer_add_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    buffer_add_struct_inst.callback = callback;
    buffer_add_struct_inst.expectedCalls = 0;
    buffer_add_struct_inst.actualCalls = 0;
}

void buffer_add_VerifyMock()
{
    if (buffer_add_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'buffer_add'",buffer_add_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void buffer_add_ExpectAndReturn (Buffer * buffer, char * data, size_t len, OPMOCK_MATCHER match_buffer, OPMOCK_MATCHER match_data, OPMOCK_MATCHER match_len)
{
    if(buffer_add_struct_inst.callback != NULL)
    {
        buffer_add_MockReset ();
    }

    if(buffer_add_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting buffer_add_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"void buffer_add (Buffer * buffer, char * data, size_t len)");
    buffer_add_struct_inst.calls[buffer_add_struct_inst.expectedCalls].buffer = (void *)buffer;
    buffer_add_struct_inst.calls[buffer_add_struct_inst.expectedCalls].data = (void *)data;
    buffer_add_struct_inst.calls[buffer_add_struct_inst.expectedCalls].len = (unsigned long)len;
    buffer_add_struct_inst.calls[buffer_add_struct_inst.expectedCalls].match_buffer = match_buffer;
    buffer_add_struct_inst.calls[buffer_add_struct_inst.expectedCalls].match_data = match_data;
    buffer_add_struct_inst.calls[buffer_add_struct_inst.expectedCalls].match_len = match_len;
    buffer_add_struct_inst.calls[buffer_add_struct_inst.expectedCalls].check_params = 1;
    buffer_add_struct_inst.expectedCalls++;
}

void buffer_remove(Buffer * buffer, size_t len)
{
    int opmock_i;
    buffer_remove_struct_inst.actualCalls++;

    if (buffer_remove_struct_inst.callback != NULL)
    {
        buffer_remove_struct_inst.callback (buffer, len, buffer_remove_struct_inst.actualCalls);
        return;
    }
    if (buffer_remove_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'buffer_remove', returning random value.");
        return;
    }

    if(strcmp(opmock_get_current_call(), "void buffer_remove (Buffer * buffer, size_t len)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'void buffer_remove(Buffer * buffer, size_t len)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (buffer_remove_struct_inst.calls[0].check_params == 1) {
        if(buffer_remove_struct_inst.calls[0].match_buffer) {
            void * val1 = (void *) &buffer_remove_struct_inst.calls[0].buffer;
            void * val2 = (void *) &buffer;
            int match_result = buffer_remove_struct_inst.calls[0].match_buffer(val1, val2, "buffer", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'buffer_remove', %s",buffer_remove_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
        if(buffer_remove_struct_inst.calls[0].match_len) {
            void * val1 = (void *) &buffer_remove_struct_inst.calls[0].len;
            void * val2 = (void *) &len;
            int match_result = buffer_remove_struct_inst.calls[0].match_len(val1, val2, "len", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'buffer_remove', %s",buffer_remove_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < buffer_remove_struct_inst.expectedCalls; opmock_i++) {
        buffer_remove_struct_inst.calls[opmock_i - 1] = buffer_remove_struct_inst.calls[opmock_i];
    }

    buffer_remove_struct_inst.expectedCalls--;
}

void buffer_remove_MockReset()
{
    buffer_remove_struct_inst.expectedCalls = 0;
    buffer_remove_struct_inst.actualCalls = 0;
    buffer_remove_struct_inst.callback = NULL;
}

void buffer_remove_MockWithCallback(OPMOCK_buffer_remove_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    buffer_remove_struct_inst.callback = callback;
    buffer_remove_struct_inst.expectedCalls = 0;
    buffer_remove_struct_inst.actualCalls = 0;
}

void buffer_remove_VerifyMock()
{
    if (buffer_remove_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'buffer_remove'",buffer_remove_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void buffer_remove_ExpectAndReturn (Buffer * buffer, size_t len, OPMOCK_MATCHER match_buffer, OPMOCK_MATCHER match_len)
{
    if(buffer_remove_struct_inst.callback != NULL)
    {
        buffer_remove_MockReset ();
    }

    if(buffer_remove_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting buffer_remove_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"void buffer_remove (Buffer * buffer, size_t len)");
    buffer_remove_struct_inst.calls[buffer_remove_struct_inst.expectedCalls].buffer = (void *)buffer;
    buffer_remove_struct_inst.calls[buffer_remove_struct_inst.expectedCalls].len = (unsigned long)len;
    buffer_remove_struct_inst.calls[buffer_remove_struct_inst.expectedCalls].match_buffer = match_buffer;
    buffer_remove_struct_inst.calls[buffer_remove_struct_inst.expectedCalls].match_len = match_len;
    buffer_remove_struct_inst.calls[buffer_remove_struct_inst.expectedCalls].check_params = 1;
    buffer_remove_struct_inst.expectedCalls++;
}

ListEntry * buffer_get_start(Buffer * buffer)
{
    ListEntry * default_res = (ListEntry *)buffer_get_start_struct_inst.calls[0].to_return;
    int opmock_i;
    buffer_get_start_struct_inst.actualCalls++;

    if (buffer_get_start_struct_inst.callback != NULL)
    {
        return buffer_get_start_struct_inst.callback (buffer, buffer_get_start_struct_inst.actualCalls);
    }
    if (buffer_get_start_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'buffer_get_start', returning random value.");
        return default_res;
    }

    if(strcmp(opmock_get_current_call(), "ListEntry * buffer_get_start (Buffer * buffer)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'ListEntry * buffer_get_start(Buffer * buffer)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (buffer_get_start_struct_inst.calls[0].check_params == 1) {
        if(buffer_get_start_struct_inst.calls[0].match_buffer) {
            void * val1 = (void *) &buffer_get_start_struct_inst.calls[0].buffer;
            void * val2 = (void *) &buffer;
            int match_result = buffer_get_start_struct_inst.calls[0].match_buffer(val1, val2, "buffer", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'buffer_get_start', %s",buffer_get_start_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < buffer_get_start_struct_inst.expectedCalls; opmock_i++) {
        buffer_get_start_struct_inst.calls[opmock_i - 1] = buffer_get_start_struct_inst.calls[opmock_i];
    }

    buffer_get_start_struct_inst.expectedCalls--;
    return default_res;
}

void buffer_get_start_MockReset()
{
    buffer_get_start_struct_inst.expectedCalls = 0;
    buffer_get_start_struct_inst.actualCalls = 0;
    buffer_get_start_struct_inst.callback = NULL;
}

void buffer_get_start_MockWithCallback(OPMOCK_buffer_get_start_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    buffer_get_start_struct_inst.callback = callback;
    buffer_get_start_struct_inst.expectedCalls = 0;
    buffer_get_start_struct_inst.actualCalls = 0;
}

void buffer_get_start_VerifyMock()
{
    if (buffer_get_start_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'buffer_get_start'",buffer_get_start_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void buffer_get_start_ExpectAndReturn (Buffer * buffer, ListEntry * to_return, OPMOCK_MATCHER match_buffer)
{
    if(buffer_get_start_struct_inst.callback != NULL)
    {
        buffer_get_start_MockReset ();
    }

    if(buffer_get_start_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting buffer_get_start_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"ListEntry * buffer_get_start (Buffer * buffer)");
    buffer_get_start_struct_inst.calls[buffer_get_start_struct_inst.expectedCalls].buffer = (void *)buffer;
    buffer_get_start_struct_inst.calls[buffer_get_start_struct_inst.expectedCalls].match_buffer = match_buffer;
    buffer_get_start_struct_inst.calls[buffer_get_start_struct_inst.expectedCalls].to_return = (struct _ListEntry *) to_return;
    buffer_get_start_struct_inst.calls[buffer_get_start_struct_inst.expectedCalls].check_params = 1;
    buffer_get_start_struct_inst.expectedCalls++;
}

