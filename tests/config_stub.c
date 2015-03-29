/* OPMOCK2 GENERATED CODE - DO NOT MODIFY */
#include "config_stub.h"
#include <stdio.h>
#include <string.h>

typedef struct
{
    char check_params;
} config_init_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_config_init_CALLBACK callback;
    config_init_call calls[MAX_FUNC_CALL];
} config_init_struct;

static config_init_struct config_init_struct_inst;

typedef struct
{
    _Bool to_return;
    char check_params;
} config_load_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_config_load_CALLBACK callback;
    config_load_call calls[MAX_FUNC_CALL];
} config_load_struct;

static config_load_struct config_load_struct_inst;

typedef struct
{
    void * sectionName;
    bool isArray;
    OPMOCK_MATCHER match_sectionName;
    OPMOCK_MATCHER match_isArray;
    struct _ConfigSection * to_return;
    char check_params;
} config_register_section_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_config_register_section_CALLBACK callback;
    config_register_section_call calls[MAX_FUNC_CALL];
} config_register_section_struct;

static config_register_section_struct config_register_section_struct_inst;

typedef struct
{
    void * arg1;
    void * arg2;
    enum json_type arg3;
    void * arg4;
    OPMOCK_MATCHER match_arg1;
    OPMOCK_MATCHER match_arg2;
    OPMOCK_MATCHER match_arg3;
    OPMOCK_MATCHER match_arg4;
    char check_params;
} config_register_field_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_config_register_field_CALLBACK callback;
    config_register_field_call calls[MAX_FUNC_CALL];
} config_register_field_struct;

static config_register_field_struct config_register_field_struct_inst;

static void opmock_reset_all_mocks_in_this_header()
{
    config_init_MockReset();
    config_load_MockReset();
    config_register_section_MockReset();
    config_register_field_MockReset();
}

static void opmock_verify_all_mocks_in_this_header()
{
    config_init_VerifyMock();
    config_load_VerifyMock();
    config_register_section_VerifyMock();
    config_register_field_VerifyMock();
}

void config_init()
{
    int opmock_i;
    config_init_struct_inst.actualCalls++;

    if (config_init_struct_inst.callback != NULL)
    {
        config_init_struct_inst.callback (config_init_struct_inst.actualCalls);
        return;
    }
    if (config_init_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'config_init', returning random value.");
        return;
    }

    if(strcmp(opmock_get_current_call(), "void config_init ()") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'void config_init()',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (config_init_struct_inst.calls[0].check_params == 1) {
    }

    for(opmock_i = 1; opmock_i < config_init_struct_inst.expectedCalls; opmock_i++) {
        config_init_struct_inst.calls[opmock_i - 1] = config_init_struct_inst.calls[opmock_i];
    }

    config_init_struct_inst.expectedCalls--;
}

void config_init_MockReset()
{
    config_init_struct_inst.expectedCalls = 0;
    config_init_struct_inst.actualCalls = 0;
    config_init_struct_inst.callback = NULL;
}

void config_init_MockWithCallback(OPMOCK_config_init_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    config_init_struct_inst.callback = callback;
    config_init_struct_inst.expectedCalls = 0;
    config_init_struct_inst.actualCalls = 0;
}

void config_init_VerifyMock()
{
    if (config_init_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'config_init'",config_init_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void config_init_ExpectAndReturn ()
{
    if(config_init_struct_inst.callback != NULL)
    {
        config_init_MockReset ();
    }

    if(config_init_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting config_init_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"void config_init ()");
    config_init_struct_inst.calls[config_init_struct_inst.expectedCalls].check_params = 1;
    config_init_struct_inst.expectedCalls++;
}

_Bool config_load()
{
    _Bool default_res = (_Bool)config_load_struct_inst.calls[0].to_return;
    int opmock_i;
    config_load_struct_inst.actualCalls++;

    if (config_load_struct_inst.callback != NULL)
    {
        return config_load_struct_inst.callback (config_load_struct_inst.actualCalls);
    }
    if (config_load_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'config_load', returning random value.");
        return default_res;
    }

    if(strcmp(opmock_get_current_call(), "_Bool config_load ()") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to '_Bool config_load()',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (config_load_struct_inst.calls[0].check_params == 1) {
    }

    for(opmock_i = 1; opmock_i < config_load_struct_inst.expectedCalls; opmock_i++) {
        config_load_struct_inst.calls[opmock_i - 1] = config_load_struct_inst.calls[opmock_i];
    }

    config_load_struct_inst.expectedCalls--;
    return default_res;
}

void config_load_MockReset()
{
    config_load_struct_inst.expectedCalls = 0;
    config_load_struct_inst.actualCalls = 0;
    config_load_struct_inst.callback = NULL;
}

void config_load_MockWithCallback(OPMOCK_config_load_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    config_load_struct_inst.callback = callback;
    config_load_struct_inst.expectedCalls = 0;
    config_load_struct_inst.actualCalls = 0;
}

void config_load_VerifyMock()
{
    if (config_load_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'config_load'",config_load_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void config_load_ExpectAndReturn (_Bool to_return)
{
    if(config_load_struct_inst.callback != NULL)
    {
        config_load_MockReset ();
    }

    if(config_load_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting config_load_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"_Bool config_load ()");
    config_load_struct_inst.calls[config_load_struct_inst.expectedCalls].to_return = (_Bool) to_return;
    config_load_struct_inst.calls[config_load_struct_inst.expectedCalls].check_params = 1;
    config_load_struct_inst.expectedCalls++;
}

ConfigSection * config_register_section(const char * sectionName, bool isArray)
{
    ConfigSection * default_res = (ConfigSection *)config_register_section_struct_inst.calls[0].to_return;
    int opmock_i;
    config_register_section_struct_inst.actualCalls++;

    if (config_register_section_struct_inst.callback != NULL)
    {
        return config_register_section_struct_inst.callback (sectionName, isArray, config_register_section_struct_inst.actualCalls);
    }
    if (config_register_section_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'config_register_section', returning random value.");
        return default_res;
    }

    if(strcmp(opmock_get_current_call(), "ConfigSection * config_register_section (const char * sectionName, bool isArray)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'ConfigSection * config_register_section(const char * sectionName, bool isArray)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (config_register_section_struct_inst.calls[0].check_params == 1) {
        if(config_register_section_struct_inst.calls[0].match_sectionName) {
            void * val1 = (void *) &config_register_section_struct_inst.calls[0].sectionName;
            void * val2 = (void *) &sectionName;
            int match_result = config_register_section_struct_inst.calls[0].match_sectionName(val1, val2, "sectionName", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'config_register_section', %s",config_register_section_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
        if(config_register_section_struct_inst.calls[0].match_isArray) {
            void * val1 = (void *) &config_register_section_struct_inst.calls[0].isArray;
            void * val2 = (void *) &isArray;
            int match_result = config_register_section_struct_inst.calls[0].match_isArray(val1, val2, "isArray", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'config_register_section', %s",config_register_section_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < config_register_section_struct_inst.expectedCalls; opmock_i++) {
        config_register_section_struct_inst.calls[opmock_i - 1] = config_register_section_struct_inst.calls[opmock_i];
    }

    config_register_section_struct_inst.expectedCalls--;
    return default_res;
}

void config_register_section_MockReset()
{
    config_register_section_struct_inst.expectedCalls = 0;
    config_register_section_struct_inst.actualCalls = 0;
    config_register_section_struct_inst.callback = NULL;
}

void config_register_section_MockWithCallback(OPMOCK_config_register_section_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    config_register_section_struct_inst.callback = callback;
    config_register_section_struct_inst.expectedCalls = 0;
    config_register_section_struct_inst.actualCalls = 0;
}

void config_register_section_VerifyMock()
{
    if (config_register_section_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'config_register_section'",config_register_section_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void config_register_section_ExpectAndReturn (const char * sectionName, bool isArray, ConfigSection * to_return, OPMOCK_MATCHER match_sectionName, OPMOCK_MATCHER match_isArray)
{
    if(config_register_section_struct_inst.callback != NULL)
    {
        config_register_section_MockReset ();
    }

    if(config_register_section_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting config_register_section_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"ConfigSection * config_register_section (const char * sectionName, bool isArray)");
    config_register_section_struct_inst.calls[config_register_section_struct_inst.expectedCalls].sectionName = (void *)sectionName;
    config_register_section_struct_inst.calls[config_register_section_struct_inst.expectedCalls].isArray = (bool)isArray;
    config_register_section_struct_inst.calls[config_register_section_struct_inst.expectedCalls].match_sectionName = match_sectionName;
    config_register_section_struct_inst.calls[config_register_section_struct_inst.expectedCalls].match_isArray = match_isArray;
    config_register_section_struct_inst.calls[config_register_section_struct_inst.expectedCalls].to_return = (struct _ConfigSection *) to_return;
    config_register_section_struct_inst.calls[config_register_section_struct_inst.expectedCalls].check_params = 1;
    config_register_section_struct_inst.expectedCalls++;
}

void config_register_field(ConfigSection * arg1, const char * arg2, json_type arg3, ConfigFieldHandler arg4)
{
    int opmock_i;
    config_register_field_struct_inst.actualCalls++;

    if (config_register_field_struct_inst.callback != NULL)
    {
        config_register_field_struct_inst.callback (arg1, arg2, arg3, arg4, config_register_field_struct_inst.actualCalls);
        return;
    }
    if (config_register_field_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'config_register_field', returning random value.");
        return;
    }

    if(strcmp(opmock_get_current_call(), "void config_register_field (ConfigSection * arg1, const char * arg2, json_type arg3, ConfigFieldHandler arg4)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'void config_register_field(ConfigSection * arg1, const char * arg2, json_type arg3, ConfigFieldHandler arg4)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (config_register_field_struct_inst.calls[0].check_params == 1) {
        if(config_register_field_struct_inst.calls[0].match_arg1) {
            void * val1 = (void *) &config_register_field_struct_inst.calls[0].arg1;
            void * val2 = (void *) &arg1;
            int match_result = config_register_field_struct_inst.calls[0].match_arg1(val1, val2, "arg1", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'config_register_field', %s",config_register_field_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
        if(config_register_field_struct_inst.calls[0].match_arg2) {
            void * val1 = (void *) &config_register_field_struct_inst.calls[0].arg2;
            void * val2 = (void *) &arg2;
            int match_result = config_register_field_struct_inst.calls[0].match_arg2(val1, val2, "arg2", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'config_register_field', %s",config_register_field_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
        if(config_register_field_struct_inst.calls[0].match_arg3) {
            void * val1 = (void *) &config_register_field_struct_inst.calls[0].arg3;
            void * val2 = (void *) &arg3;
            int match_result = config_register_field_struct_inst.calls[0].match_arg3(val1, val2, "arg3", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'config_register_field', %s",config_register_field_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
        if(config_register_field_struct_inst.calls[0].match_arg4) {
            void * val1 = (void *) &config_register_field_struct_inst.calls[0].arg4;
            void * val2 = (void *) &arg4;
            int match_result = config_register_field_struct_inst.calls[0].match_arg4(val1, val2, "arg4", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'config_register_field', %s",config_register_field_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < config_register_field_struct_inst.expectedCalls; opmock_i++) {
        config_register_field_struct_inst.calls[opmock_i - 1] = config_register_field_struct_inst.calls[opmock_i];
    }

    config_register_field_struct_inst.expectedCalls--;
}

void config_register_field_MockReset()
{
    config_register_field_struct_inst.expectedCalls = 0;
    config_register_field_struct_inst.actualCalls = 0;
    config_register_field_struct_inst.callback = NULL;
}

void config_register_field_MockWithCallback(OPMOCK_config_register_field_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    config_register_field_struct_inst.callback = callback;
    config_register_field_struct_inst.expectedCalls = 0;
    config_register_field_struct_inst.actualCalls = 0;
}

void config_register_field_VerifyMock()
{
    if (config_register_field_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'config_register_field'",config_register_field_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void config_register_field_ExpectAndReturn (ConfigSection * arg1, const char * arg2, json_type arg3, ConfigFieldHandler arg4, OPMOCK_MATCHER match_arg1, OPMOCK_MATCHER match_arg2, OPMOCK_MATCHER match_arg3, OPMOCK_MATCHER match_arg4)
{
    if(config_register_field_struct_inst.callback != NULL)
    {
        config_register_field_MockReset ();
    }

    if(config_register_field_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting config_register_field_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"void config_register_field (ConfigSection * arg1, const char * arg2, json_type arg3, ConfigFieldHandler arg4)");
    config_register_field_struct_inst.calls[config_register_field_struct_inst.expectedCalls].arg1 = (void *)arg1;
    config_register_field_struct_inst.calls[config_register_field_struct_inst.expectedCalls].arg2 = (void *)arg2;
    config_register_field_struct_inst.calls[config_register_field_struct_inst.expectedCalls].arg3 = (enum json_type)arg3;
    config_register_field_struct_inst.calls[config_register_field_struct_inst.expectedCalls].arg4 = (void *)arg4;
    config_register_field_struct_inst.calls[config_register_field_struct_inst.expectedCalls].match_arg1 = match_arg1;
    config_register_field_struct_inst.calls[config_register_field_struct_inst.expectedCalls].match_arg2 = match_arg2;
    config_register_field_struct_inst.calls[config_register_field_struct_inst.expectedCalls].match_arg3 = match_arg3;
    config_register_field_struct_inst.calls[config_register_field_struct_inst.expectedCalls].match_arg4 = match_arg4;
    config_register_field_struct_inst.calls[config_register_field_struct_inst.expectedCalls].check_params = 1;
    config_register_field_struct_inst.expectedCalls++;
}

