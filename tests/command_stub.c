/* OPMOCK2 GENERATED CODE - DO NOT MODIFY */
#include "command_stub.h"
#include <stdio.h>
#include <string.h>

typedef struct
{
    char check_params;
} command_init_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_command_init_CALLBACK callback;
    command_init_call calls[MAX_FUNC_CALL];
} command_init_struct;

static command_init_struct command_init_struct_inst;

typedef struct
{
    struct _Command * to_return;
    char check_params;
} command_new_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_command_new_CALLBACK callback;
    command_new_call calls[MAX_FUNC_CALL];
} command_new_struct;

static command_new_struct command_new_struct_inst;

typedef struct
{
    void * arg1;
    OPMOCK_MATCHER match_arg1;
    char check_params;
} command_free_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_command_free_CALLBACK callback;
    command_free_call calls[MAX_FUNC_CALL];
} command_free_struct;

static command_free_struct command_free_struct_inst;

typedef struct
{
    void * arg1;
    enum _CommandAccess arg2;
    void * arg3;
    int arg4;
    OPMOCK_MATCHER match_arg1;
    OPMOCK_MATCHER match_arg2;
    OPMOCK_MATCHER match_arg3;
    OPMOCK_MATCHER match_arg4;
    char check_params;
} command_register_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_command_register_CALLBACK callback;
    command_register_call calls[MAX_FUNC_CALL];
} command_register_struct;

static command_register_struct command_register_struct_inst;

typedef struct
{
    void * arg1;
    OPMOCK_MATCHER match_arg1;
    struct _Command * to_return;
    char check_params;
} command_find_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_command_find_CALLBACK callback;
    command_find_call calls[MAX_FUNC_CALL];
} command_find_struct;

static command_find_struct command_find_struct_inst;

static void opmock_reset_all_mocks_in_this_header()
{
    command_init_MockReset();
    command_new_MockReset();
    command_free_MockReset();
    command_register_MockReset();
    command_find_MockReset();
}

static void opmock_verify_all_mocks_in_this_header()
{
    command_init_VerifyMock();
    command_new_VerifyMock();
    command_free_VerifyMock();
    command_register_VerifyMock();
    command_find_VerifyMock();
}

void command_init()
{
    int opmock_i;
    command_init_struct_inst.actualCalls++;

    if (command_init_struct_inst.callback != NULL)
    {
        command_init_struct_inst.callback (command_init_struct_inst.actualCalls);
        return;
    }
    if (command_init_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'command_init', returning random value.");
        return;
    }

    if(strcmp(opmock_get_current_call(), "void command_init ()") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'void command_init()',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (command_init_struct_inst.calls[0].check_params == 1) {
    }

    for(opmock_i = 1; opmock_i < command_init_struct_inst.expectedCalls; opmock_i++) {
        command_init_struct_inst.calls[opmock_i - 1] = command_init_struct_inst.calls[opmock_i];
    }

    command_init_struct_inst.expectedCalls--;
}

void command_init_MockReset()
{
    command_init_struct_inst.expectedCalls = 0;
    command_init_struct_inst.actualCalls = 0;
    command_init_struct_inst.callback = NULL;
}

void command_init_MockWithCallback(OPMOCK_command_init_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    command_init_struct_inst.callback = callback;
    command_init_struct_inst.expectedCalls = 0;
    command_init_struct_inst.actualCalls = 0;
}

void command_init_VerifyMock()
{
    if (command_init_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'command_init'",command_init_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void command_init_ExpectAndReturn ()
{
    if(command_init_struct_inst.callback != NULL)
    {
        command_init_MockReset ();
    }

    if(command_init_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting command_init_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"void command_init ()");
    command_init_struct_inst.calls[command_init_struct_inst.expectedCalls].check_params = 1;
    command_init_struct_inst.expectedCalls++;
}

Command * command_new()
{
    Command * default_res = (Command *)command_new_struct_inst.calls[0].to_return;
    int opmock_i;
    command_new_struct_inst.actualCalls++;

    if (command_new_struct_inst.callback != NULL)
    {
        return command_new_struct_inst.callback (command_new_struct_inst.actualCalls);
    }
    if (command_new_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'command_new', returning random value.");
        return default_res;
    }

    if(strcmp(opmock_get_current_call(), "Command * command_new ()") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'Command * command_new()',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (command_new_struct_inst.calls[0].check_params == 1) {
    }

    for(opmock_i = 1; opmock_i < command_new_struct_inst.expectedCalls; opmock_i++) {
        command_new_struct_inst.calls[opmock_i - 1] = command_new_struct_inst.calls[opmock_i];
    }

    command_new_struct_inst.expectedCalls--;
    return default_res;
}

void command_new_MockReset()
{
    command_new_struct_inst.expectedCalls = 0;
    command_new_struct_inst.actualCalls = 0;
    command_new_struct_inst.callback = NULL;
}

void command_new_MockWithCallback(OPMOCK_command_new_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    command_new_struct_inst.callback = callback;
    command_new_struct_inst.expectedCalls = 0;
    command_new_struct_inst.actualCalls = 0;
}

void command_new_VerifyMock()
{
    if (command_new_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'command_new'",command_new_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void command_new_ExpectAndReturn (Command * to_return)
{
    if(command_new_struct_inst.callback != NULL)
    {
        command_new_MockReset ();
    }

    if(command_new_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting command_new_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"Command * command_new ()");
    command_new_struct_inst.calls[command_new_struct_inst.expectedCalls].to_return = (struct _Command *) to_return;
    command_new_struct_inst.calls[command_new_struct_inst.expectedCalls].check_params = 1;
    command_new_struct_inst.expectedCalls++;
}

void command_free(Command * arg1)
{
    int opmock_i;
    command_free_struct_inst.actualCalls++;

    if (command_free_struct_inst.callback != NULL)
    {
        command_free_struct_inst.callback (arg1, command_free_struct_inst.actualCalls);
        return;
    }
    if (command_free_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'command_free', returning random value.");
        return;
    }

    if(strcmp(opmock_get_current_call(), "void command_free (Command * arg1)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'void command_free(Command * arg1)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (command_free_struct_inst.calls[0].check_params == 1) {
        if(command_free_struct_inst.calls[0].match_arg1) {
            void * val1 = (void *) &command_free_struct_inst.calls[0].arg1;
            void * val2 = (void *) &arg1;
            int match_result = command_free_struct_inst.calls[0].match_arg1(val1, val2, "arg1", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'command_free', %s",command_free_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < command_free_struct_inst.expectedCalls; opmock_i++) {
        command_free_struct_inst.calls[opmock_i - 1] = command_free_struct_inst.calls[opmock_i];
    }

    command_free_struct_inst.expectedCalls--;
}

void command_free_MockReset()
{
    command_free_struct_inst.expectedCalls = 0;
    command_free_struct_inst.actualCalls = 0;
    command_free_struct_inst.callback = NULL;
}

void command_free_MockWithCallback(OPMOCK_command_free_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    command_free_struct_inst.callback = callback;
    command_free_struct_inst.expectedCalls = 0;
    command_free_struct_inst.actualCalls = 0;
}

void command_free_VerifyMock()
{
    if (command_free_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'command_free'",command_free_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void command_free_ExpectAndReturn (Command * arg1, OPMOCK_MATCHER match_arg1)
{
    if(command_free_struct_inst.callback != NULL)
    {
        command_free_MockReset ();
    }

    if(command_free_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting command_free_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"void command_free (Command * arg1)");
    command_free_struct_inst.calls[command_free_struct_inst.expectedCalls].arg1 = (void *)arg1;
    command_free_struct_inst.calls[command_free_struct_inst.expectedCalls].match_arg1 = match_arg1;
    command_free_struct_inst.calls[command_free_struct_inst.expectedCalls].check_params = 1;
    command_free_struct_inst.expectedCalls++;
}

void command_register(const char * arg1, CommandAccess arg2, CommandHandler arg3, int arg4)
{
    int opmock_i;
    command_register_struct_inst.actualCalls++;

    if (command_register_struct_inst.callback != NULL)
    {
        command_register_struct_inst.callback (arg1, arg2, arg3, arg4, command_register_struct_inst.actualCalls);
        return;
    }
    if (command_register_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'command_register', returning random value.");
        return;
    }

    if(strcmp(opmock_get_current_call(), "void command_register (const char * arg1, CommandAccess arg2, CommandHandler arg3, int arg4)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'void command_register(const char * arg1, CommandAccess arg2, CommandHandler arg3, int arg4)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (command_register_struct_inst.calls[0].check_params == 1) {
        if(command_register_struct_inst.calls[0].match_arg1) {
            void * val1 = (void *) &command_register_struct_inst.calls[0].arg1;
            void * val2 = (void *) &arg1;
            int match_result = command_register_struct_inst.calls[0].match_arg1(val1, val2, "arg1", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'command_register', %s",command_register_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
        if(command_register_struct_inst.calls[0].match_arg2) {
            void * val1 = (void *) &command_register_struct_inst.calls[0].arg2;
            void * val2 = (void *) &arg2;
            int match_result = command_register_struct_inst.calls[0].match_arg2(val1, val2, "arg2", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'command_register', %s",command_register_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
        if(command_register_struct_inst.calls[0].match_arg3) {
            void * val1 = (void *) &command_register_struct_inst.calls[0].arg3;
            void * val2 = (void *) &arg3;
            int match_result = command_register_struct_inst.calls[0].match_arg3(val1, val2, "arg3", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'command_register', %s",command_register_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
        if(command_register_struct_inst.calls[0].match_arg4) {
            void * val1 = (void *) &command_register_struct_inst.calls[0].arg4;
            void * val2 = (void *) &arg4;
            int match_result = command_register_struct_inst.calls[0].match_arg4(val1, val2, "arg4", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'command_register', %s",command_register_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < command_register_struct_inst.expectedCalls; opmock_i++) {
        command_register_struct_inst.calls[opmock_i - 1] = command_register_struct_inst.calls[opmock_i];
    }

    command_register_struct_inst.expectedCalls--;
}

void command_register_MockReset()
{
    command_register_struct_inst.expectedCalls = 0;
    command_register_struct_inst.actualCalls = 0;
    command_register_struct_inst.callback = NULL;
}

void command_register_MockWithCallback(OPMOCK_command_register_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    command_register_struct_inst.callback = callback;
    command_register_struct_inst.expectedCalls = 0;
    command_register_struct_inst.actualCalls = 0;
}

void command_register_VerifyMock()
{
    if (command_register_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'command_register'",command_register_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void command_register_ExpectAndReturn (const char * arg1, CommandAccess arg2, CommandHandler arg3, int arg4, OPMOCK_MATCHER match_arg1, OPMOCK_MATCHER match_arg2, OPMOCK_MATCHER match_arg3, OPMOCK_MATCHER match_arg4)
{
    if(command_register_struct_inst.callback != NULL)
    {
        command_register_MockReset ();
    }

    if(command_register_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting command_register_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"void command_register (const char * arg1, CommandAccess arg2, CommandHandler arg3, int arg4)");
    command_register_struct_inst.calls[command_register_struct_inst.expectedCalls].arg1 = (void *)arg1;
    command_register_struct_inst.calls[command_register_struct_inst.expectedCalls].arg2 = (enum _CommandAccess)arg2;
    command_register_struct_inst.calls[command_register_struct_inst.expectedCalls].arg3 = (void *)arg3;
    command_register_struct_inst.calls[command_register_struct_inst.expectedCalls].arg4 = (int)arg4;
    command_register_struct_inst.calls[command_register_struct_inst.expectedCalls].match_arg1 = match_arg1;
    command_register_struct_inst.calls[command_register_struct_inst.expectedCalls].match_arg2 = match_arg2;
    command_register_struct_inst.calls[command_register_struct_inst.expectedCalls].match_arg3 = match_arg3;
    command_register_struct_inst.calls[command_register_struct_inst.expectedCalls].match_arg4 = match_arg4;
    command_register_struct_inst.calls[command_register_struct_inst.expectedCalls].check_params = 1;
    command_register_struct_inst.expectedCalls++;
}

Command * command_find(const char * arg1)
{
    Command * default_res = (Command *)command_find_struct_inst.calls[0].to_return;
    int opmock_i;
    command_find_struct_inst.actualCalls++;

    if (command_find_struct_inst.callback != NULL)
    {
        return command_find_struct_inst.callback (arg1, command_find_struct_inst.actualCalls);
    }
    if (command_find_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'command_find', returning random value.");
        return default_res;
    }

    if(strcmp(opmock_get_current_call(), "Command * command_find (const char * arg1)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'Command * command_find(const char * arg1)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (command_find_struct_inst.calls[0].check_params == 1) {
        if(command_find_struct_inst.calls[0].match_arg1) {
            void * val1 = (void *) &command_find_struct_inst.calls[0].arg1;
            void * val2 = (void *) &arg1;
            int match_result = command_find_struct_inst.calls[0].match_arg1(val1, val2, "arg1", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'command_find', %s",command_find_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < command_find_struct_inst.expectedCalls; opmock_i++) {
        command_find_struct_inst.calls[opmock_i - 1] = command_find_struct_inst.calls[opmock_i];
    }

    command_find_struct_inst.expectedCalls--;
    return default_res;
}

void command_find_MockReset()
{
    command_find_struct_inst.expectedCalls = 0;
    command_find_struct_inst.actualCalls = 0;
    command_find_struct_inst.callback = NULL;
}

void command_find_MockWithCallback(OPMOCK_command_find_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    command_find_struct_inst.callback = callback;
    command_find_struct_inst.expectedCalls = 0;
    command_find_struct_inst.actualCalls = 0;
}

void command_find_VerifyMock()
{
    if (command_find_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'command_find'",command_find_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void command_find_ExpectAndReturn (const char * arg1, Command * to_return, OPMOCK_MATCHER match_arg1)
{
    if(command_find_struct_inst.callback != NULL)
    {
        command_find_MockReset ();
    }

    if(command_find_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting command_find_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"Command * command_find (const char * arg1)");
    command_find_struct_inst.calls[command_find_struct_inst.expectedCalls].arg1 = (void *)arg1;
    command_find_struct_inst.calls[command_find_struct_inst.expectedCalls].match_arg1 = match_arg1;
    command_find_struct_inst.calls[command_find_struct_inst.expectedCalls].to_return = (struct _Command *) to_return;
    command_find_struct_inst.calls[command_find_struct_inst.expectedCalls].check_params = 1;
    command_find_struct_inst.expectedCalls++;
}

