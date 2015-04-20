/* OPMOCK2 GENERATED CODE - DO NOT MODIFY */
#include "parser_stub.h"
#include <stdio.h>
#include <string.h>

typedef struct
{
    void * srcBuffer;
    void * destBuffer;
    unsigned long length;
    OPMOCK_MATCHER match_srcBuffer;
    OPMOCK_MATCHER match_destBuffer;
    OPMOCK_MATCHER match_length;
    _Bool to_return;
    char check_params;
} parser_get_line_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_parser_get_line_CALLBACK callback;
    parser_get_line_call calls[MAX_FUNC_CALL];
} parser_get_line_struct;

static parser_get_line_struct parser_get_line_struct_inst;

typedef struct
{
    void * arg1;
    unsigned long arg2;
    OPMOCK_MATCHER match_arg1;
    OPMOCK_MATCHER match_arg2;
    struct _ParserResult * to_return;
    char check_params;
} parser_process_line_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_parser_process_line_CALLBACK callback;
    parser_process_line_call calls[MAX_FUNC_CALL];
} parser_process_line_struct;

static parser_process_line_struct parser_process_line_struct_inst;

typedef struct
{
    struct _ParserResult * to_return;
    char check_params;
} parser_result_new_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_parser_result_new_CALLBACK callback;
    parser_result_new_call calls[MAX_FUNC_CALL];
} parser_result_new_struct;

static parser_result_new_struct parser_result_new_struct_inst;

typedef struct
{
    void * result;
    OPMOCK_MATCHER match_result;
    char check_params;
} parser_result_free_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_parser_result_free_CALLBACK callback;
    parser_result_free_call calls[MAX_FUNC_CALL];
} parser_result_free_struct;

static parser_result_free_struct parser_result_free_struct_inst;

static void opmock_reset_all_mocks_in_this_header()
{
    parser_get_line_MockReset();
    parser_process_line_MockReset();
    parser_result_new_MockReset();
    parser_result_free_MockReset();
}

static void opmock_verify_all_mocks_in_this_header()
{
    parser_get_line_VerifyMock();
    parser_process_line_VerifyMock();
    parser_result_new_VerifyMock();
    parser_result_free_VerifyMock();
}

_Bool parser_get_line(Buffer * srcBuffer, char * destBuffer, size_t length)
{
    _Bool default_res = (_Bool)parser_get_line_struct_inst.calls[0].to_return;
    int opmock_i;
    parser_get_line_struct_inst.actualCalls++;

    if (parser_get_line_struct_inst.callback != NULL)
    {
        return parser_get_line_struct_inst.callback (srcBuffer, destBuffer, length, parser_get_line_struct_inst.actualCalls);
    }
    if (parser_get_line_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'parser_get_line', returning random value.");
        return default_res;
    }

    if(strcmp(opmock_get_current_call(), "_Bool parser_get_line (Buffer * srcBuffer, char * destBuffer, size_t length)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to '_Bool parser_get_line(Buffer * srcBuffer, char * destBuffer, size_t length)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (parser_get_line_struct_inst.calls[0].check_params == 1) {
        if(parser_get_line_struct_inst.calls[0].match_srcBuffer) {
            void * val1 = (void *) &parser_get_line_struct_inst.calls[0].srcBuffer;
            void * val2 = (void *) &srcBuffer;
            int match_result = parser_get_line_struct_inst.calls[0].match_srcBuffer(val1, val2, "srcBuffer", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'parser_get_line', %s",parser_get_line_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
        if(parser_get_line_struct_inst.calls[0].match_destBuffer) {
            void * val1 = (void *) &parser_get_line_struct_inst.calls[0].destBuffer;
            void * val2 = (void *) &destBuffer;
            int match_result = parser_get_line_struct_inst.calls[0].match_destBuffer(val1, val2, "destBuffer", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'parser_get_line', %s",parser_get_line_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
        if(parser_get_line_struct_inst.calls[0].match_length) {
            void * val1 = (void *) &parser_get_line_struct_inst.calls[0].length;
            void * val2 = (void *) &length;
            int match_result = parser_get_line_struct_inst.calls[0].match_length(val1, val2, "length", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'parser_get_line', %s",parser_get_line_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < parser_get_line_struct_inst.expectedCalls; opmock_i++) {
        parser_get_line_struct_inst.calls[opmock_i - 1] = parser_get_line_struct_inst.calls[opmock_i];
    }

    parser_get_line_struct_inst.expectedCalls--;
    return default_res;
}

void parser_get_line_MockReset()
{
    parser_get_line_struct_inst.expectedCalls = 0;
    parser_get_line_struct_inst.actualCalls = 0;
    parser_get_line_struct_inst.callback = NULL;
}

void parser_get_line_MockWithCallback(OPMOCK_parser_get_line_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    parser_get_line_struct_inst.callback = callback;
    parser_get_line_struct_inst.expectedCalls = 0;
    parser_get_line_struct_inst.actualCalls = 0;
}

void parser_get_line_VerifyMock()
{
    if (parser_get_line_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'parser_get_line'",parser_get_line_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void parser_get_line_ExpectAndReturn (Buffer * srcBuffer, char * destBuffer, size_t length, _Bool to_return, OPMOCK_MATCHER match_srcBuffer, OPMOCK_MATCHER match_destBuffer, OPMOCK_MATCHER match_length)
{
    if(parser_get_line_struct_inst.callback != NULL)
    {
        parser_get_line_MockReset ();
    }

    if(parser_get_line_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting parser_get_line_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"_Bool parser_get_line (Buffer * srcBuffer, char * destBuffer, size_t length)");
    parser_get_line_struct_inst.calls[parser_get_line_struct_inst.expectedCalls].srcBuffer = (void *)srcBuffer;
    parser_get_line_struct_inst.calls[parser_get_line_struct_inst.expectedCalls].destBuffer = (void *)destBuffer;
    parser_get_line_struct_inst.calls[parser_get_line_struct_inst.expectedCalls].length = (unsigned long)length;
    parser_get_line_struct_inst.calls[parser_get_line_struct_inst.expectedCalls].match_srcBuffer = match_srcBuffer;
    parser_get_line_struct_inst.calls[parser_get_line_struct_inst.expectedCalls].match_destBuffer = match_destBuffer;
    parser_get_line_struct_inst.calls[parser_get_line_struct_inst.expectedCalls].match_length = match_length;
    parser_get_line_struct_inst.calls[parser_get_line_struct_inst.expectedCalls].to_return = (_Bool) to_return;
    parser_get_line_struct_inst.calls[parser_get_line_struct_inst.expectedCalls].check_params = 1;
    parser_get_line_struct_inst.expectedCalls++;
}

ParserResult * parser_process_line(const char * arg1, size_t arg2)
{
    ParserResult * default_res = (ParserResult *)parser_process_line_struct_inst.calls[0].to_return;
    int opmock_i;
    parser_process_line_struct_inst.actualCalls++;

    if (parser_process_line_struct_inst.callback != NULL)
    {
        return parser_process_line_struct_inst.callback (arg1, arg2, parser_process_line_struct_inst.actualCalls);
    }
    if (parser_process_line_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'parser_process_line', returning random value.");
        return default_res;
    }

    if(strcmp(opmock_get_current_call(), "ParserResult * parser_process_line (const char * arg1, size_t arg2)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'ParserResult * parser_process_line(const char * arg1, size_t arg2)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (parser_process_line_struct_inst.calls[0].check_params == 1) {
        if(parser_process_line_struct_inst.calls[0].match_arg1) {
            void * val1 = (void *) &parser_process_line_struct_inst.calls[0].arg1;
            void * val2 = (void *) &arg1;
            int match_result = parser_process_line_struct_inst.calls[0].match_arg1(val1, val2, "arg1", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'parser_process_line', %s",parser_process_line_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
        if(parser_process_line_struct_inst.calls[0].match_arg2) {
            void * val1 = (void *) &parser_process_line_struct_inst.calls[0].arg2;
            void * val2 = (void *) &arg2;
            int match_result = parser_process_line_struct_inst.calls[0].match_arg2(val1, val2, "arg2", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'parser_process_line', %s",parser_process_line_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < parser_process_line_struct_inst.expectedCalls; opmock_i++) {
        parser_process_line_struct_inst.calls[opmock_i - 1] = parser_process_line_struct_inst.calls[opmock_i];
    }

    parser_process_line_struct_inst.expectedCalls--;
    return default_res;
}

void parser_process_line_MockReset()
{
    parser_process_line_struct_inst.expectedCalls = 0;
    parser_process_line_struct_inst.actualCalls = 0;
    parser_process_line_struct_inst.callback = NULL;
}

void parser_process_line_MockWithCallback(OPMOCK_parser_process_line_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    parser_process_line_struct_inst.callback = callback;
    parser_process_line_struct_inst.expectedCalls = 0;
    parser_process_line_struct_inst.actualCalls = 0;
}

void parser_process_line_VerifyMock()
{
    if (parser_process_line_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'parser_process_line'",parser_process_line_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void parser_process_line_ExpectAndReturn (const char * arg1, size_t arg2, ParserResult * to_return, OPMOCK_MATCHER match_arg1, OPMOCK_MATCHER match_arg2)
{
    if(parser_process_line_struct_inst.callback != NULL)
    {
        parser_process_line_MockReset ();
    }

    if(parser_process_line_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting parser_process_line_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"ParserResult * parser_process_line (const char * arg1, size_t arg2)");
    parser_process_line_struct_inst.calls[parser_process_line_struct_inst.expectedCalls].arg1 = (void *)arg1;
    parser_process_line_struct_inst.calls[parser_process_line_struct_inst.expectedCalls].arg2 = (unsigned long)arg2;
    parser_process_line_struct_inst.calls[parser_process_line_struct_inst.expectedCalls].match_arg1 = match_arg1;
    parser_process_line_struct_inst.calls[parser_process_line_struct_inst.expectedCalls].match_arg2 = match_arg2;
    parser_process_line_struct_inst.calls[parser_process_line_struct_inst.expectedCalls].to_return = (struct _ParserResult *) to_return;
    parser_process_line_struct_inst.calls[parser_process_line_struct_inst.expectedCalls].check_params = 1;
    parser_process_line_struct_inst.expectedCalls++;
}

ParserResult * parser_result_new()
{
    ParserResult * default_res = (ParserResult *)parser_result_new_struct_inst.calls[0].to_return;
    int opmock_i;
    parser_result_new_struct_inst.actualCalls++;

    if (parser_result_new_struct_inst.callback != NULL)
    {
        return parser_result_new_struct_inst.callback (parser_result_new_struct_inst.actualCalls);
    }
    if (parser_result_new_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'parser_result_new', returning random value.");
        return default_res;
    }

    if(strcmp(opmock_get_current_call(), "ParserResult * parser_result_new ()") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'ParserResult * parser_result_new()',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (parser_result_new_struct_inst.calls[0].check_params == 1) {
    }

    for(opmock_i = 1; opmock_i < parser_result_new_struct_inst.expectedCalls; opmock_i++) {
        parser_result_new_struct_inst.calls[opmock_i - 1] = parser_result_new_struct_inst.calls[opmock_i];
    }

    parser_result_new_struct_inst.expectedCalls--;
    return default_res;
}

void parser_result_new_MockReset()
{
    parser_result_new_struct_inst.expectedCalls = 0;
    parser_result_new_struct_inst.actualCalls = 0;
    parser_result_new_struct_inst.callback = NULL;
}

void parser_result_new_MockWithCallback(OPMOCK_parser_result_new_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    parser_result_new_struct_inst.callback = callback;
    parser_result_new_struct_inst.expectedCalls = 0;
    parser_result_new_struct_inst.actualCalls = 0;
}

void parser_result_new_VerifyMock()
{
    if (parser_result_new_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'parser_result_new'",parser_result_new_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void parser_result_new_ExpectAndReturn (ParserResult * to_return)
{
    if(parser_result_new_struct_inst.callback != NULL)
    {
        parser_result_new_MockReset ();
    }

    if(parser_result_new_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting parser_result_new_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"ParserResult * parser_result_new ()");
    parser_result_new_struct_inst.calls[parser_result_new_struct_inst.expectedCalls].to_return = (struct _ParserResult *) to_return;
    parser_result_new_struct_inst.calls[parser_result_new_struct_inst.expectedCalls].check_params = 1;
    parser_result_new_struct_inst.expectedCalls++;
}

void parser_result_free(ParserResult * result)
{
    int opmock_i;
    parser_result_free_struct_inst.actualCalls++;

    if (parser_result_free_struct_inst.callback != NULL)
    {
        parser_result_free_struct_inst.callback (result, parser_result_free_struct_inst.actualCalls);
        return;
    }
    if (parser_result_free_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'parser_result_free', returning random value.");
        return;
    }

    if(strcmp(opmock_get_current_call(), "void parser_result_free (ParserResult * result)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'void parser_result_free(ParserResult * result)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (parser_result_free_struct_inst.calls[0].check_params == 1) {
        if(parser_result_free_struct_inst.calls[0].match_result) {
            void * val1 = (void *) &parser_result_free_struct_inst.calls[0].result;
            void * val2 = (void *) &result;
            int match_result = parser_result_free_struct_inst.calls[0].match_result(val1, val2, "result", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'parser_result_free', %s",parser_result_free_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < parser_result_free_struct_inst.expectedCalls; opmock_i++) {
        parser_result_free_struct_inst.calls[opmock_i - 1] = parser_result_free_struct_inst.calls[opmock_i];
    }

    parser_result_free_struct_inst.expectedCalls--;
}

void parser_result_free_MockReset()
{
    parser_result_free_struct_inst.expectedCalls = 0;
    parser_result_free_struct_inst.actualCalls = 0;
    parser_result_free_struct_inst.callback = NULL;
}

void parser_result_free_MockWithCallback(OPMOCK_parser_result_free_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    parser_result_free_struct_inst.callback = callback;
    parser_result_free_struct_inst.expectedCalls = 0;
    parser_result_free_struct_inst.actualCalls = 0;
}

void parser_result_free_VerifyMock()
{
    if (parser_result_free_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'parser_result_free'",parser_result_free_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void parser_result_free_ExpectAndReturn (ParserResult * result, OPMOCK_MATCHER match_result)
{
    if(parser_result_free_struct_inst.callback != NULL)
    {
        parser_result_free_MockReset ();
    }

    if(parser_result_free_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting parser_result_free_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"void parser_result_free (ParserResult * result)");
    parser_result_free_struct_inst.calls[parser_result_free_struct_inst.expectedCalls].result = (void *)result;
    parser_result_free_struct_inst.calls[parser_result_free_struct_inst.expectedCalls].match_result = match_result;
    parser_result_free_struct_inst.calls[parser_result_free_struct_inst.expectedCalls].check_params = 1;
    parser_result_free_struct_inst.expectedCalls++;
}

