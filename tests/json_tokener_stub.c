/* OPMOCK2 GENERATED CODE - DO NOT MODIFY */
#include "json_tokener_stub.h"
#include <stdio.h>
#include <string.h>

typedef struct
{
    enum json_tokener_error jerr;
    OPMOCK_MATCHER match_jerr;
     char * to_return;
    char check_params;
} json_tokener_error_desc_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_json_tokener_error_desc_CALLBACK callback;
    json_tokener_error_desc_call calls[MAX_FUNC_CALL];
} json_tokener_error_desc_struct;

static json_tokener_error_desc_struct json_tokener_error_desc_struct_inst;

typedef struct
{
    void * tok;
    OPMOCK_MATCHER match_tok;
    enum json_tokener_error to_return;
    char check_params;
} json_tokener_get_error_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_json_tokener_get_error_CALLBACK callback;
    json_tokener_get_error_call calls[MAX_FUNC_CALL];
} json_tokener_get_error_struct;

static json_tokener_get_error_struct json_tokener_get_error_struct_inst;

typedef struct
{
    struct json_tokener * to_return;
    char check_params;
} json_tokener_new_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_json_tokener_new_CALLBACK callback;
    json_tokener_new_call calls[MAX_FUNC_CALL];
} json_tokener_new_struct;

static json_tokener_new_struct json_tokener_new_struct_inst;

typedef struct
{
    int depth;
    OPMOCK_MATCHER match_depth;
    struct json_tokener * to_return;
    char check_params;
} json_tokener_new_ex_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_json_tokener_new_ex_CALLBACK callback;
    json_tokener_new_ex_call calls[MAX_FUNC_CALL];
} json_tokener_new_ex_struct;

static json_tokener_new_ex_struct json_tokener_new_ex_struct_inst;

typedef struct
{
    void * tok;
    OPMOCK_MATCHER match_tok;
    char check_params;
} json_tokener_free_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_json_tokener_free_CALLBACK callback;
    json_tokener_free_call calls[MAX_FUNC_CALL];
} json_tokener_free_struct;

static json_tokener_free_struct json_tokener_free_struct_inst;

typedef struct
{
    void * tok;
    OPMOCK_MATCHER match_tok;
    char check_params;
} json_tokener_reset_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_json_tokener_reset_CALLBACK callback;
    json_tokener_reset_call calls[MAX_FUNC_CALL];
} json_tokener_reset_struct;

static json_tokener_reset_struct json_tokener_reset_struct_inst;

typedef struct
{
    void * str;
    OPMOCK_MATCHER match_str;
    struct json_object * to_return;
    char check_params;
} json_tokener_parse_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_json_tokener_parse_CALLBACK callback;
    json_tokener_parse_call calls[MAX_FUNC_CALL];
} json_tokener_parse_struct;

static json_tokener_parse_struct json_tokener_parse_struct_inst;

typedef struct
{
    void * str;
    void * error;
    OPMOCK_MATCHER match_str;
    OPMOCK_MATCHER match_error;
    struct json_object * to_return;
    char check_params;
} json_tokener_parse_verbose_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_json_tokener_parse_verbose_CALLBACK callback;
    json_tokener_parse_verbose_call calls[MAX_FUNC_CALL];
} json_tokener_parse_verbose_struct;

static json_tokener_parse_verbose_struct json_tokener_parse_verbose_struct_inst;

typedef struct
{
    void * tok;
    int flags;
    OPMOCK_MATCHER match_tok;
    OPMOCK_MATCHER match_flags;
    char check_params;
} json_tokener_set_flags_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_json_tokener_set_flags_CALLBACK callback;
    json_tokener_set_flags_call calls[MAX_FUNC_CALL];
} json_tokener_set_flags_struct;

static json_tokener_set_flags_struct json_tokener_set_flags_struct_inst;

typedef struct
{
    void * tok;
    void * str;
    int len;
    OPMOCK_MATCHER match_tok;
    OPMOCK_MATCHER match_str;
    OPMOCK_MATCHER match_len;
    struct json_object * to_return;
    char check_params;
} json_tokener_parse_ex_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_json_tokener_parse_ex_CALLBACK callback;
    json_tokener_parse_ex_call calls[MAX_FUNC_CALL];
} json_tokener_parse_ex_struct;

static json_tokener_parse_ex_struct json_tokener_parse_ex_struct_inst;

static void opmock_reset_all_mocks_in_this_header()
{
    json_tokener_error_desc_MockReset();
    json_tokener_get_error_MockReset();
    json_tokener_new_MockReset();
    json_tokener_new_ex_MockReset();
    json_tokener_free_MockReset();
    json_tokener_reset_MockReset();
    json_tokener_parse_MockReset();
    json_tokener_parse_verbose_MockReset();
    json_tokener_set_flags_MockReset();
    json_tokener_parse_ex_MockReset();
}

static void opmock_verify_all_mocks_in_this_header()
{
    json_tokener_error_desc_VerifyMock();
    json_tokener_get_error_VerifyMock();
    json_tokener_new_VerifyMock();
    json_tokener_new_ex_VerifyMock();
    json_tokener_free_VerifyMock();
    json_tokener_reset_VerifyMock();
    json_tokener_parse_VerifyMock();
    json_tokener_parse_verbose_VerifyMock();
    json_tokener_set_flags_VerifyMock();
    json_tokener_parse_ex_VerifyMock();
}

const char * json_tokener_error_desc(enum json_tokener_error jerr)
{
    const char * default_res = (const char *)json_tokener_error_desc_struct_inst.calls[0].to_return;
    int opmock_i;
    json_tokener_error_desc_struct_inst.actualCalls++;

    if (json_tokener_error_desc_struct_inst.callback != NULL)
    {
        return json_tokener_error_desc_struct_inst.callback (jerr, json_tokener_error_desc_struct_inst.actualCalls);
    }
    if (json_tokener_error_desc_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'json_tokener_error_desc', returning random value.");
        return default_res;
    }

    if(strcmp(opmock_get_current_call(), "const char * json_tokener_error_desc (enum json_tokener_error jerr)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'const char * json_tokener_error_desc(enum json_tokener_error jerr)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (json_tokener_error_desc_struct_inst.calls[0].check_params == 1) {
        if(json_tokener_error_desc_struct_inst.calls[0].match_jerr) {
            void * val1 = (void *) &json_tokener_error_desc_struct_inst.calls[0].jerr;
            void * val2 = (void *) &jerr;
            int match_result = json_tokener_error_desc_struct_inst.calls[0].match_jerr(val1, val2, "jerr", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'json_tokener_error_desc', %s",json_tokener_error_desc_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < json_tokener_error_desc_struct_inst.expectedCalls; opmock_i++) {
        json_tokener_error_desc_struct_inst.calls[opmock_i - 1] = json_tokener_error_desc_struct_inst.calls[opmock_i];
    }

    json_tokener_error_desc_struct_inst.expectedCalls--;
    return default_res;
}

void json_tokener_error_desc_MockReset()
{
    json_tokener_error_desc_struct_inst.expectedCalls = 0;
    json_tokener_error_desc_struct_inst.actualCalls = 0;
    json_tokener_error_desc_struct_inst.callback = NULL;
}

void json_tokener_error_desc_MockWithCallback(OPMOCK_json_tokener_error_desc_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    json_tokener_error_desc_struct_inst.callback = callback;
    json_tokener_error_desc_struct_inst.expectedCalls = 0;
    json_tokener_error_desc_struct_inst.actualCalls = 0;
}

void json_tokener_error_desc_VerifyMock()
{
    if (json_tokener_error_desc_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'json_tokener_error_desc'",json_tokener_error_desc_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void json_tokener_error_desc_ExpectAndReturn (enum json_tokener_error jerr, const char * to_return, OPMOCK_MATCHER match_jerr)
{
    if(json_tokener_error_desc_struct_inst.callback != NULL)
    {
        json_tokener_error_desc_MockReset ();
    }

    if(json_tokener_error_desc_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting json_tokener_error_desc_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"const char * json_tokener_error_desc (enum json_tokener_error jerr)");
    json_tokener_error_desc_struct_inst.calls[json_tokener_error_desc_struct_inst.expectedCalls].jerr = (enum json_tokener_error)jerr;
    json_tokener_error_desc_struct_inst.calls[json_tokener_error_desc_struct_inst.expectedCalls].match_jerr = match_jerr;
    json_tokener_error_desc_struct_inst.calls[json_tokener_error_desc_struct_inst.expectedCalls].to_return = ( char *) to_return;
    json_tokener_error_desc_struct_inst.calls[json_tokener_error_desc_struct_inst.expectedCalls].check_params = 1;
    json_tokener_error_desc_struct_inst.expectedCalls++;
}

enum json_tokener_error json_tokener_get_error(struct json_tokener * tok)
{
    enum json_tokener_error default_res = (enum json_tokener_error)json_tokener_get_error_struct_inst.calls[0].to_return;
    int opmock_i;
    json_tokener_get_error_struct_inst.actualCalls++;

    if (json_tokener_get_error_struct_inst.callback != NULL)
    {
        return json_tokener_get_error_struct_inst.callback (tok, json_tokener_get_error_struct_inst.actualCalls);
    }
    if (json_tokener_get_error_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'json_tokener_get_error', returning random value.");
        return default_res;
    }

    if(strcmp(opmock_get_current_call(), "enum json_tokener_error json_tokener_get_error (struct json_tokener * tok)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'enum json_tokener_error json_tokener_get_error(struct json_tokener * tok)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (json_tokener_get_error_struct_inst.calls[0].check_params == 1) {
        if(json_tokener_get_error_struct_inst.calls[0].match_tok) {
            void * val1 = (void *) &json_tokener_get_error_struct_inst.calls[0].tok;
            void * val2 = (void *) &tok;
            int match_result = json_tokener_get_error_struct_inst.calls[0].match_tok(val1, val2, "tok", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'json_tokener_get_error', %s",json_tokener_get_error_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < json_tokener_get_error_struct_inst.expectedCalls; opmock_i++) {
        json_tokener_get_error_struct_inst.calls[opmock_i - 1] = json_tokener_get_error_struct_inst.calls[opmock_i];
    }

    json_tokener_get_error_struct_inst.expectedCalls--;
    return default_res;
}

void json_tokener_get_error_MockReset()
{
    json_tokener_get_error_struct_inst.expectedCalls = 0;
    json_tokener_get_error_struct_inst.actualCalls = 0;
    json_tokener_get_error_struct_inst.callback = NULL;
}

void json_tokener_get_error_MockWithCallback(OPMOCK_json_tokener_get_error_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    json_tokener_get_error_struct_inst.callback = callback;
    json_tokener_get_error_struct_inst.expectedCalls = 0;
    json_tokener_get_error_struct_inst.actualCalls = 0;
}

void json_tokener_get_error_VerifyMock()
{
    if (json_tokener_get_error_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'json_tokener_get_error'",json_tokener_get_error_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void json_tokener_get_error_ExpectAndReturn (struct json_tokener * tok, enum json_tokener_error to_return, OPMOCK_MATCHER match_tok)
{
    if(json_tokener_get_error_struct_inst.callback != NULL)
    {
        json_tokener_get_error_MockReset ();
    }

    if(json_tokener_get_error_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting json_tokener_get_error_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"enum json_tokener_error json_tokener_get_error (struct json_tokener * tok)");
    json_tokener_get_error_struct_inst.calls[json_tokener_get_error_struct_inst.expectedCalls].tok = (void *)tok;
    json_tokener_get_error_struct_inst.calls[json_tokener_get_error_struct_inst.expectedCalls].match_tok = match_tok;
    json_tokener_get_error_struct_inst.calls[json_tokener_get_error_struct_inst.expectedCalls].to_return = (enum json_tokener_error) to_return;
    json_tokener_get_error_struct_inst.calls[json_tokener_get_error_struct_inst.expectedCalls].check_params = 1;
    json_tokener_get_error_struct_inst.expectedCalls++;
}

struct json_tokener * json_tokener_new()
{
    struct json_tokener * default_res = (struct json_tokener *)json_tokener_new_struct_inst.calls[0].to_return;
    int opmock_i;
    json_tokener_new_struct_inst.actualCalls++;

    if (json_tokener_new_struct_inst.callback != NULL)
    {
        return json_tokener_new_struct_inst.callback (json_tokener_new_struct_inst.actualCalls);
    }
    if (json_tokener_new_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'json_tokener_new', returning random value.");
        return default_res;
    }

    if(strcmp(opmock_get_current_call(), "struct json_tokener * json_tokener_new ()") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'struct json_tokener * json_tokener_new()',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (json_tokener_new_struct_inst.calls[0].check_params == 1) {
    }

    for(opmock_i = 1; opmock_i < json_tokener_new_struct_inst.expectedCalls; opmock_i++) {
        json_tokener_new_struct_inst.calls[opmock_i - 1] = json_tokener_new_struct_inst.calls[opmock_i];
    }

    json_tokener_new_struct_inst.expectedCalls--;
    return default_res;
}

void json_tokener_new_MockReset()
{
    json_tokener_new_struct_inst.expectedCalls = 0;
    json_tokener_new_struct_inst.actualCalls = 0;
    json_tokener_new_struct_inst.callback = NULL;
}

void json_tokener_new_MockWithCallback(OPMOCK_json_tokener_new_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    json_tokener_new_struct_inst.callback = callback;
    json_tokener_new_struct_inst.expectedCalls = 0;
    json_tokener_new_struct_inst.actualCalls = 0;
}

void json_tokener_new_VerifyMock()
{
    if (json_tokener_new_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'json_tokener_new'",json_tokener_new_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void json_tokener_new_ExpectAndReturn (struct json_tokener * to_return)
{
    if(json_tokener_new_struct_inst.callback != NULL)
    {
        json_tokener_new_MockReset ();
    }

    if(json_tokener_new_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting json_tokener_new_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"struct json_tokener * json_tokener_new ()");
    json_tokener_new_struct_inst.calls[json_tokener_new_struct_inst.expectedCalls].to_return = (struct json_tokener *) to_return;
    json_tokener_new_struct_inst.calls[json_tokener_new_struct_inst.expectedCalls].check_params = 1;
    json_tokener_new_struct_inst.expectedCalls++;
}

struct json_tokener * json_tokener_new_ex(int depth)
{
    struct json_tokener * default_res = (struct json_tokener *)json_tokener_new_ex_struct_inst.calls[0].to_return;
    int opmock_i;
    json_tokener_new_ex_struct_inst.actualCalls++;

    if (json_tokener_new_ex_struct_inst.callback != NULL)
    {
        return json_tokener_new_ex_struct_inst.callback (depth, json_tokener_new_ex_struct_inst.actualCalls);
    }
    if (json_tokener_new_ex_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'json_tokener_new_ex', returning random value.");
        return default_res;
    }

    if(strcmp(opmock_get_current_call(), "struct json_tokener * json_tokener_new_ex (int depth)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'struct json_tokener * json_tokener_new_ex(int depth)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (json_tokener_new_ex_struct_inst.calls[0].check_params == 1) {
        if(json_tokener_new_ex_struct_inst.calls[0].match_depth) {
            void * val1 = (void *) &json_tokener_new_ex_struct_inst.calls[0].depth;
            void * val2 = (void *) &depth;
            int match_result = json_tokener_new_ex_struct_inst.calls[0].match_depth(val1, val2, "depth", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'json_tokener_new_ex', %s",json_tokener_new_ex_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < json_tokener_new_ex_struct_inst.expectedCalls; opmock_i++) {
        json_tokener_new_ex_struct_inst.calls[opmock_i - 1] = json_tokener_new_ex_struct_inst.calls[opmock_i];
    }

    json_tokener_new_ex_struct_inst.expectedCalls--;
    return default_res;
}

void json_tokener_new_ex_MockReset()
{
    json_tokener_new_ex_struct_inst.expectedCalls = 0;
    json_tokener_new_ex_struct_inst.actualCalls = 0;
    json_tokener_new_ex_struct_inst.callback = NULL;
}

void json_tokener_new_ex_MockWithCallback(OPMOCK_json_tokener_new_ex_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    json_tokener_new_ex_struct_inst.callback = callback;
    json_tokener_new_ex_struct_inst.expectedCalls = 0;
    json_tokener_new_ex_struct_inst.actualCalls = 0;
}

void json_tokener_new_ex_VerifyMock()
{
    if (json_tokener_new_ex_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'json_tokener_new_ex'",json_tokener_new_ex_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void json_tokener_new_ex_ExpectAndReturn (int depth, struct json_tokener * to_return, OPMOCK_MATCHER match_depth)
{
    if(json_tokener_new_ex_struct_inst.callback != NULL)
    {
        json_tokener_new_ex_MockReset ();
    }

    if(json_tokener_new_ex_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting json_tokener_new_ex_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"struct json_tokener * json_tokener_new_ex (int depth)");
    json_tokener_new_ex_struct_inst.calls[json_tokener_new_ex_struct_inst.expectedCalls].depth = (int)depth;
    json_tokener_new_ex_struct_inst.calls[json_tokener_new_ex_struct_inst.expectedCalls].match_depth = match_depth;
    json_tokener_new_ex_struct_inst.calls[json_tokener_new_ex_struct_inst.expectedCalls].to_return = (struct json_tokener *) to_return;
    json_tokener_new_ex_struct_inst.calls[json_tokener_new_ex_struct_inst.expectedCalls].check_params = 1;
    json_tokener_new_ex_struct_inst.expectedCalls++;
}

void json_tokener_free(struct json_tokener * tok)
{
    int opmock_i;
    json_tokener_free_struct_inst.actualCalls++;

    if (json_tokener_free_struct_inst.callback != NULL)
    {
        json_tokener_free_struct_inst.callback (tok, json_tokener_free_struct_inst.actualCalls);
        return;
    }
    if (json_tokener_free_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'json_tokener_free', returning random value.");
        return;
    }

    if(strcmp(opmock_get_current_call(), "void json_tokener_free (struct json_tokener * tok)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'void json_tokener_free(struct json_tokener * tok)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (json_tokener_free_struct_inst.calls[0].check_params == 1) {
        if(json_tokener_free_struct_inst.calls[0].match_tok) {
            void * val1 = (void *) &json_tokener_free_struct_inst.calls[0].tok;
            void * val2 = (void *) &tok;
            int match_result = json_tokener_free_struct_inst.calls[0].match_tok(val1, val2, "tok", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'json_tokener_free', %s",json_tokener_free_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < json_tokener_free_struct_inst.expectedCalls; opmock_i++) {
        json_tokener_free_struct_inst.calls[opmock_i - 1] = json_tokener_free_struct_inst.calls[opmock_i];
    }

    json_tokener_free_struct_inst.expectedCalls--;
}

void json_tokener_free_MockReset()
{
    json_tokener_free_struct_inst.expectedCalls = 0;
    json_tokener_free_struct_inst.actualCalls = 0;
    json_tokener_free_struct_inst.callback = NULL;
}

void json_tokener_free_MockWithCallback(OPMOCK_json_tokener_free_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    json_tokener_free_struct_inst.callback = callback;
    json_tokener_free_struct_inst.expectedCalls = 0;
    json_tokener_free_struct_inst.actualCalls = 0;
}

void json_tokener_free_VerifyMock()
{
    if (json_tokener_free_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'json_tokener_free'",json_tokener_free_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void json_tokener_free_ExpectAndReturn (struct json_tokener * tok, OPMOCK_MATCHER match_tok)
{
    if(json_tokener_free_struct_inst.callback != NULL)
    {
        json_tokener_free_MockReset ();
    }

    if(json_tokener_free_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting json_tokener_free_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"void json_tokener_free (struct json_tokener * tok)");
    json_tokener_free_struct_inst.calls[json_tokener_free_struct_inst.expectedCalls].tok = (void *)tok;
    json_tokener_free_struct_inst.calls[json_tokener_free_struct_inst.expectedCalls].match_tok = match_tok;
    json_tokener_free_struct_inst.calls[json_tokener_free_struct_inst.expectedCalls].check_params = 1;
    json_tokener_free_struct_inst.expectedCalls++;
}

void json_tokener_reset(struct json_tokener * tok)
{
    int opmock_i;
    json_tokener_reset_struct_inst.actualCalls++;

    if (json_tokener_reset_struct_inst.callback != NULL)
    {
        json_tokener_reset_struct_inst.callback (tok, json_tokener_reset_struct_inst.actualCalls);
        return;
    }
    if (json_tokener_reset_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'json_tokener_reset', returning random value.");
        return;
    }

    if(strcmp(opmock_get_current_call(), "void json_tokener_reset (struct json_tokener * tok)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'void json_tokener_reset(struct json_tokener * tok)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (json_tokener_reset_struct_inst.calls[0].check_params == 1) {
        if(json_tokener_reset_struct_inst.calls[0].match_tok) {
            void * val1 = (void *) &json_tokener_reset_struct_inst.calls[0].tok;
            void * val2 = (void *) &tok;
            int match_result = json_tokener_reset_struct_inst.calls[0].match_tok(val1, val2, "tok", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'json_tokener_reset', %s",json_tokener_reset_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < json_tokener_reset_struct_inst.expectedCalls; opmock_i++) {
        json_tokener_reset_struct_inst.calls[opmock_i - 1] = json_tokener_reset_struct_inst.calls[opmock_i];
    }

    json_tokener_reset_struct_inst.expectedCalls--;
}

void json_tokener_reset_MockReset()
{
    json_tokener_reset_struct_inst.expectedCalls = 0;
    json_tokener_reset_struct_inst.actualCalls = 0;
    json_tokener_reset_struct_inst.callback = NULL;
}

void json_tokener_reset_MockWithCallback(OPMOCK_json_tokener_reset_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    json_tokener_reset_struct_inst.callback = callback;
    json_tokener_reset_struct_inst.expectedCalls = 0;
    json_tokener_reset_struct_inst.actualCalls = 0;
}

void json_tokener_reset_VerifyMock()
{
    if (json_tokener_reset_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'json_tokener_reset'",json_tokener_reset_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void json_tokener_reset_ExpectAndReturn (struct json_tokener * tok, OPMOCK_MATCHER match_tok)
{
    if(json_tokener_reset_struct_inst.callback != NULL)
    {
        json_tokener_reset_MockReset ();
    }

    if(json_tokener_reset_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting json_tokener_reset_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"void json_tokener_reset (struct json_tokener * tok)");
    json_tokener_reset_struct_inst.calls[json_tokener_reset_struct_inst.expectedCalls].tok = (void *)tok;
    json_tokener_reset_struct_inst.calls[json_tokener_reset_struct_inst.expectedCalls].match_tok = match_tok;
    json_tokener_reset_struct_inst.calls[json_tokener_reset_struct_inst.expectedCalls].check_params = 1;
    json_tokener_reset_struct_inst.expectedCalls++;
}

struct json_object * json_tokener_parse(const char * str)
{
    struct json_object * default_res = (struct json_object *)json_tokener_parse_struct_inst.calls[0].to_return;
    int opmock_i;
    json_tokener_parse_struct_inst.actualCalls++;

    if (json_tokener_parse_struct_inst.callback != NULL)
    {
        return json_tokener_parse_struct_inst.callback (str, json_tokener_parse_struct_inst.actualCalls);
    }
    if (json_tokener_parse_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'json_tokener_parse', returning random value.");
        return default_res;
    }

    if(strcmp(opmock_get_current_call(), "struct json_object * json_tokener_parse (const char * str)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'struct json_object * json_tokener_parse(const char * str)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (json_tokener_parse_struct_inst.calls[0].check_params == 1) {
        if(json_tokener_parse_struct_inst.calls[0].match_str) {
            void * val1 = (void *) &json_tokener_parse_struct_inst.calls[0].str;
            void * val2 = (void *) &str;
            int match_result = json_tokener_parse_struct_inst.calls[0].match_str(val1, val2, "str", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'json_tokener_parse', %s",json_tokener_parse_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < json_tokener_parse_struct_inst.expectedCalls; opmock_i++) {
        json_tokener_parse_struct_inst.calls[opmock_i - 1] = json_tokener_parse_struct_inst.calls[opmock_i];
    }

    json_tokener_parse_struct_inst.expectedCalls--;
    return default_res;
}

void json_tokener_parse_MockReset()
{
    json_tokener_parse_struct_inst.expectedCalls = 0;
    json_tokener_parse_struct_inst.actualCalls = 0;
    json_tokener_parse_struct_inst.callback = NULL;
}

void json_tokener_parse_MockWithCallback(OPMOCK_json_tokener_parse_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    json_tokener_parse_struct_inst.callback = callback;
    json_tokener_parse_struct_inst.expectedCalls = 0;
    json_tokener_parse_struct_inst.actualCalls = 0;
}

void json_tokener_parse_VerifyMock()
{
    if (json_tokener_parse_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'json_tokener_parse'",json_tokener_parse_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void json_tokener_parse_ExpectAndReturn (const char * str, struct json_object * to_return, OPMOCK_MATCHER match_str)
{
    if(json_tokener_parse_struct_inst.callback != NULL)
    {
        json_tokener_parse_MockReset ();
    }

    if(json_tokener_parse_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting json_tokener_parse_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"struct json_object * json_tokener_parse (const char * str)");
    json_tokener_parse_struct_inst.calls[json_tokener_parse_struct_inst.expectedCalls].str = (void *)str;
    json_tokener_parse_struct_inst.calls[json_tokener_parse_struct_inst.expectedCalls].match_str = match_str;
    json_tokener_parse_struct_inst.calls[json_tokener_parse_struct_inst.expectedCalls].to_return = (struct json_object *) to_return;
    json_tokener_parse_struct_inst.calls[json_tokener_parse_struct_inst.expectedCalls].check_params = 1;
    json_tokener_parse_struct_inst.expectedCalls++;
}

struct json_object * json_tokener_parse_verbose(const char * str, enum json_tokener_error * error)
{
    struct json_object * default_res = (struct json_object *)json_tokener_parse_verbose_struct_inst.calls[0].to_return;
    int opmock_i;
    json_tokener_parse_verbose_struct_inst.actualCalls++;

    if (json_tokener_parse_verbose_struct_inst.callback != NULL)
    {
        return json_tokener_parse_verbose_struct_inst.callback (str, error, json_tokener_parse_verbose_struct_inst.actualCalls);
    }
    if (json_tokener_parse_verbose_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'json_tokener_parse_verbose', returning random value.");
        return default_res;
    }

    if(strcmp(opmock_get_current_call(), "struct json_object * json_tokener_parse_verbose (const char * str, enum json_tokener_error * error)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'struct json_object * json_tokener_parse_verbose(const char * str, enum json_tokener_error * error)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (json_tokener_parse_verbose_struct_inst.calls[0].check_params == 1) {
        if(json_tokener_parse_verbose_struct_inst.calls[0].match_str) {
            void * val1 = (void *) &json_tokener_parse_verbose_struct_inst.calls[0].str;
            void * val2 = (void *) &str;
            int match_result = json_tokener_parse_verbose_struct_inst.calls[0].match_str(val1, val2, "str", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'json_tokener_parse_verbose', %s",json_tokener_parse_verbose_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
        if(json_tokener_parse_verbose_struct_inst.calls[0].match_error) {
            void * val1 = (void *) &json_tokener_parse_verbose_struct_inst.calls[0].error;
            void * val2 = (void *) &error;
            int match_result = json_tokener_parse_verbose_struct_inst.calls[0].match_error(val1, val2, "error", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'json_tokener_parse_verbose', %s",json_tokener_parse_verbose_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < json_tokener_parse_verbose_struct_inst.expectedCalls; opmock_i++) {
        json_tokener_parse_verbose_struct_inst.calls[opmock_i - 1] = json_tokener_parse_verbose_struct_inst.calls[opmock_i];
    }

    json_tokener_parse_verbose_struct_inst.expectedCalls--;
    return default_res;
}

void json_tokener_parse_verbose_MockReset()
{
    json_tokener_parse_verbose_struct_inst.expectedCalls = 0;
    json_tokener_parse_verbose_struct_inst.actualCalls = 0;
    json_tokener_parse_verbose_struct_inst.callback = NULL;
}

void json_tokener_parse_verbose_MockWithCallback(OPMOCK_json_tokener_parse_verbose_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    json_tokener_parse_verbose_struct_inst.callback = callback;
    json_tokener_parse_verbose_struct_inst.expectedCalls = 0;
    json_tokener_parse_verbose_struct_inst.actualCalls = 0;
}

void json_tokener_parse_verbose_VerifyMock()
{
    if (json_tokener_parse_verbose_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'json_tokener_parse_verbose'",json_tokener_parse_verbose_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void json_tokener_parse_verbose_ExpectAndReturn (const char * str, enum json_tokener_error * error, struct json_object * to_return, OPMOCK_MATCHER match_str, OPMOCK_MATCHER match_error)
{
    if(json_tokener_parse_verbose_struct_inst.callback != NULL)
    {
        json_tokener_parse_verbose_MockReset ();
    }

    if(json_tokener_parse_verbose_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting json_tokener_parse_verbose_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"struct json_object * json_tokener_parse_verbose (const char * str, enum json_tokener_error * error)");
    json_tokener_parse_verbose_struct_inst.calls[json_tokener_parse_verbose_struct_inst.expectedCalls].str = (void *)str;
    json_tokener_parse_verbose_struct_inst.calls[json_tokener_parse_verbose_struct_inst.expectedCalls].error = (void *)error;
    json_tokener_parse_verbose_struct_inst.calls[json_tokener_parse_verbose_struct_inst.expectedCalls].match_str = match_str;
    json_tokener_parse_verbose_struct_inst.calls[json_tokener_parse_verbose_struct_inst.expectedCalls].match_error = match_error;
    json_tokener_parse_verbose_struct_inst.calls[json_tokener_parse_verbose_struct_inst.expectedCalls].to_return = (struct json_object *) to_return;
    json_tokener_parse_verbose_struct_inst.calls[json_tokener_parse_verbose_struct_inst.expectedCalls].check_params = 1;
    json_tokener_parse_verbose_struct_inst.expectedCalls++;
}

void json_tokener_set_flags(struct json_tokener * tok, int flags)
{
    int opmock_i;
    json_tokener_set_flags_struct_inst.actualCalls++;

    if (json_tokener_set_flags_struct_inst.callback != NULL)
    {
        json_tokener_set_flags_struct_inst.callback (tok, flags, json_tokener_set_flags_struct_inst.actualCalls);
        return;
    }
    if (json_tokener_set_flags_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'json_tokener_set_flags', returning random value.");
        return;
    }

    if(strcmp(opmock_get_current_call(), "void json_tokener_set_flags (struct json_tokener * tok, int flags)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'void json_tokener_set_flags(struct json_tokener * tok, int flags)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (json_tokener_set_flags_struct_inst.calls[0].check_params == 1) {
        if(json_tokener_set_flags_struct_inst.calls[0].match_tok) {
            void * val1 = (void *) &json_tokener_set_flags_struct_inst.calls[0].tok;
            void * val2 = (void *) &tok;
            int match_result = json_tokener_set_flags_struct_inst.calls[0].match_tok(val1, val2, "tok", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'json_tokener_set_flags', %s",json_tokener_set_flags_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
        if(json_tokener_set_flags_struct_inst.calls[0].match_flags) {
            void * val1 = (void *) &json_tokener_set_flags_struct_inst.calls[0].flags;
            void * val2 = (void *) &flags;
            int match_result = json_tokener_set_flags_struct_inst.calls[0].match_flags(val1, val2, "flags", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'json_tokener_set_flags', %s",json_tokener_set_flags_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < json_tokener_set_flags_struct_inst.expectedCalls; opmock_i++) {
        json_tokener_set_flags_struct_inst.calls[opmock_i - 1] = json_tokener_set_flags_struct_inst.calls[opmock_i];
    }

    json_tokener_set_flags_struct_inst.expectedCalls--;
}

void json_tokener_set_flags_MockReset()
{
    json_tokener_set_flags_struct_inst.expectedCalls = 0;
    json_tokener_set_flags_struct_inst.actualCalls = 0;
    json_tokener_set_flags_struct_inst.callback = NULL;
}

void json_tokener_set_flags_MockWithCallback(OPMOCK_json_tokener_set_flags_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    json_tokener_set_flags_struct_inst.callback = callback;
    json_tokener_set_flags_struct_inst.expectedCalls = 0;
    json_tokener_set_flags_struct_inst.actualCalls = 0;
}

void json_tokener_set_flags_VerifyMock()
{
    if (json_tokener_set_flags_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'json_tokener_set_flags'",json_tokener_set_flags_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void json_tokener_set_flags_ExpectAndReturn (struct json_tokener * tok, int flags, OPMOCK_MATCHER match_tok, OPMOCK_MATCHER match_flags)
{
    if(json_tokener_set_flags_struct_inst.callback != NULL)
    {
        json_tokener_set_flags_MockReset ();
    }

    if(json_tokener_set_flags_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting json_tokener_set_flags_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"void json_tokener_set_flags (struct json_tokener * tok, int flags)");
    json_tokener_set_flags_struct_inst.calls[json_tokener_set_flags_struct_inst.expectedCalls].tok = (void *)tok;
    json_tokener_set_flags_struct_inst.calls[json_tokener_set_flags_struct_inst.expectedCalls].flags = (int)flags;
    json_tokener_set_flags_struct_inst.calls[json_tokener_set_flags_struct_inst.expectedCalls].match_tok = match_tok;
    json_tokener_set_flags_struct_inst.calls[json_tokener_set_flags_struct_inst.expectedCalls].match_flags = match_flags;
    json_tokener_set_flags_struct_inst.calls[json_tokener_set_flags_struct_inst.expectedCalls].check_params = 1;
    json_tokener_set_flags_struct_inst.expectedCalls++;
}

struct json_object * json_tokener_parse_ex(struct json_tokener * tok, const char * str, int len)
{
    struct json_object * default_res = (struct json_object *)json_tokener_parse_ex_struct_inst.calls[0].to_return;
    int opmock_i;
    json_tokener_parse_ex_struct_inst.actualCalls++;

    if (json_tokener_parse_ex_struct_inst.callback != NULL)
    {
        return json_tokener_parse_ex_struct_inst.callback (tok, str, len, json_tokener_parse_ex_struct_inst.actualCalls);
    }
    if (json_tokener_parse_ex_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'json_tokener_parse_ex', returning random value.");
        return default_res;
    }

    if(strcmp(opmock_get_current_call(), "struct json_object * json_tokener_parse_ex (struct json_tokener * tok, const char * str, int len)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'struct json_object * json_tokener_parse_ex(struct json_tokener * tok, const char * str, int len)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (json_tokener_parse_ex_struct_inst.calls[0].check_params == 1) {
        if(json_tokener_parse_ex_struct_inst.calls[0].match_tok) {
            void * val1 = (void *) &json_tokener_parse_ex_struct_inst.calls[0].tok;
            void * val2 = (void *) &tok;
            int match_result = json_tokener_parse_ex_struct_inst.calls[0].match_tok(val1, val2, "tok", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'json_tokener_parse_ex', %s",json_tokener_parse_ex_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
        if(json_tokener_parse_ex_struct_inst.calls[0].match_str) {
            void * val1 = (void *) &json_tokener_parse_ex_struct_inst.calls[0].str;
            void * val2 = (void *) &str;
            int match_result = json_tokener_parse_ex_struct_inst.calls[0].match_str(val1, val2, "str", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'json_tokener_parse_ex', %s",json_tokener_parse_ex_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
        if(json_tokener_parse_ex_struct_inst.calls[0].match_len) {
            void * val1 = (void *) &json_tokener_parse_ex_struct_inst.calls[0].len;
            void * val2 = (void *) &len;
            int match_result = json_tokener_parse_ex_struct_inst.calls[0].match_len(val1, val2, "len", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'json_tokener_parse_ex', %s",json_tokener_parse_ex_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < json_tokener_parse_ex_struct_inst.expectedCalls; opmock_i++) {
        json_tokener_parse_ex_struct_inst.calls[opmock_i - 1] = json_tokener_parse_ex_struct_inst.calls[opmock_i];
    }

    json_tokener_parse_ex_struct_inst.expectedCalls--;
    return default_res;
}

void json_tokener_parse_ex_MockReset()
{
    json_tokener_parse_ex_struct_inst.expectedCalls = 0;
    json_tokener_parse_ex_struct_inst.actualCalls = 0;
    json_tokener_parse_ex_struct_inst.callback = NULL;
}

void json_tokener_parse_ex_MockWithCallback(OPMOCK_json_tokener_parse_ex_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    json_tokener_parse_ex_struct_inst.callback = callback;
    json_tokener_parse_ex_struct_inst.expectedCalls = 0;
    json_tokener_parse_ex_struct_inst.actualCalls = 0;
}

void json_tokener_parse_ex_VerifyMock()
{
    if (json_tokener_parse_ex_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'json_tokener_parse_ex'",json_tokener_parse_ex_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void json_tokener_parse_ex_ExpectAndReturn (struct json_tokener * tok, const char * str, int len, struct json_object * to_return, OPMOCK_MATCHER match_tok, OPMOCK_MATCHER match_str, OPMOCK_MATCHER match_len)
{
    if(json_tokener_parse_ex_struct_inst.callback != NULL)
    {
        json_tokener_parse_ex_MockReset ();
    }

    if(json_tokener_parse_ex_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting json_tokener_parse_ex_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"struct json_object * json_tokener_parse_ex (struct json_tokener * tok, const char * str, int len)");
    json_tokener_parse_ex_struct_inst.calls[json_tokener_parse_ex_struct_inst.expectedCalls].tok = (void *)tok;
    json_tokener_parse_ex_struct_inst.calls[json_tokener_parse_ex_struct_inst.expectedCalls].str = (void *)str;
    json_tokener_parse_ex_struct_inst.calls[json_tokener_parse_ex_struct_inst.expectedCalls].len = (int)len;
    json_tokener_parse_ex_struct_inst.calls[json_tokener_parse_ex_struct_inst.expectedCalls].match_tok = match_tok;
    json_tokener_parse_ex_struct_inst.calls[json_tokener_parse_ex_struct_inst.expectedCalls].match_str = match_str;
    json_tokener_parse_ex_struct_inst.calls[json_tokener_parse_ex_struct_inst.expectedCalls].match_len = match_len;
    json_tokener_parse_ex_struct_inst.calls[json_tokener_parse_ex_struct_inst.expectedCalls].to_return = (struct json_object *) to_return;
    json_tokener_parse_ex_struct_inst.calls[json_tokener_parse_ex_struct_inst.expectedCalls].check_params = 1;
    json_tokener_parse_ex_struct_inst.expectedCalls++;
}

