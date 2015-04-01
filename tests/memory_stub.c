/* OPMOCK2 GENERATED CODE - DO NOT MODIFY */

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-prototypes"

#include "memory_stub.h"
#include <stdio.h>
#include <string.h>

typedef struct
{
    unsigned long length;
    OPMOCK_MATCHER match_length;
    void * to_return;
    char check_params;
} Malloc_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_Malloc_CALLBACK callback;
    Malloc_call calls[MAX_FUNC_CALL];
} Malloc_struct;

static Malloc_struct Malloc_struct_inst;

typedef struct
{
    void * ptr;
    unsigned long length;
    OPMOCK_MATCHER match_ptr;
    OPMOCK_MATCHER match_length;
    void * to_return;
    char check_params;
} Realloc_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_Realloc_CALLBACK callback;
    Realloc_call calls[MAX_FUNC_CALL];
} Realloc_struct;

static Realloc_struct Realloc_struct_inst;

typedef struct
{
    void * ptr;
    OPMOCK_MATCHER match_ptr;
    char * to_return;
    char check_params;
} StrDup_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_StrDup_CALLBACK callback;
    StrDup_call calls[MAX_FUNC_CALL];
} StrDup_struct;

static StrDup_struct StrDup_struct_inst;

typedef struct
{
    void * ptr;
    OPMOCK_MATCHER match_ptr;
    char check_params;
} Free_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_Free_CALLBACK callback;
    Free_call calls[MAX_FUNC_CALL];
} Free_struct;

static Free_struct Free_struct_inst;

static void opmock_reset_all_mocks_in_this_header()
{
    Malloc_MockReset();
    Realloc_MockReset();
    StrDup_MockReset();
    Free_MockReset();
}

static void opmock_verify_all_mocks_in_this_header()
{
    Malloc_VerifyMock();
    Realloc_VerifyMock();
    StrDup_VerifyMock();
    Free_VerifyMock();
}

void * Malloc(size_t length)
{
    void * default_res = (void *)Malloc_struct_inst.calls[0].to_return;
    int opmock_i;
    Malloc_struct_inst.actualCalls++;

    if (Malloc_struct_inst.callback != NULL)
    {
        return Malloc_struct_inst.callback (length, Malloc_struct_inst.actualCalls);
    }
    if (Malloc_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'Malloc', returning random value.");
        return default_res;
    }

    if(strcmp(opmock_get_current_call(), "void * Malloc (size_t length)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'void * Malloc(size_t length)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (Malloc_struct_inst.calls[0].check_params == 1) {
        if(Malloc_struct_inst.calls[0].match_length) {
            void * val1 = (void *) &Malloc_struct_inst.calls[0].length;
            void * val2 = (void *) &length;
            int match_result = Malloc_struct_inst.calls[0].match_length(val1, val2, "length", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'Malloc', %s",Malloc_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < Malloc_struct_inst.expectedCalls; opmock_i++) {
        Malloc_struct_inst.calls[opmock_i - 1] = Malloc_struct_inst.calls[opmock_i];
    }

    Malloc_struct_inst.expectedCalls--;
    return default_res;
}

void Malloc_MockReset()
{
    Malloc_struct_inst.expectedCalls = 0;
    Malloc_struct_inst.actualCalls = 0;
    Malloc_struct_inst.callback = NULL;
}

void Malloc_MockWithCallback(OPMOCK_Malloc_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    Malloc_struct_inst.callback = callback;
    Malloc_struct_inst.expectedCalls = 0;
    Malloc_struct_inst.actualCalls = 0;
}

void Malloc_VerifyMock()
{
    if (Malloc_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'Malloc'",Malloc_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void Malloc_ExpectAndReturn (size_t length, void * to_return, OPMOCK_MATCHER match_length)
{
    if(Malloc_struct_inst.callback != NULL)
    {
        Malloc_MockReset ();
    }

    if(Malloc_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting Malloc_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"void * Malloc (size_t length)");
    Malloc_struct_inst.calls[Malloc_struct_inst.expectedCalls].length = (unsigned long)length;
    Malloc_struct_inst.calls[Malloc_struct_inst.expectedCalls].match_length = match_length;
    Malloc_struct_inst.calls[Malloc_struct_inst.expectedCalls].to_return = (void *) to_return;
    Malloc_struct_inst.calls[Malloc_struct_inst.expectedCalls].check_params = 1;
    Malloc_struct_inst.expectedCalls++;
}

void * Realloc(void * ptr, size_t length)
{
    void * default_res = (void *)Realloc_struct_inst.calls[0].to_return;
    int opmock_i;
    Realloc_struct_inst.actualCalls++;

    if (Realloc_struct_inst.callback != NULL)
    {
        return Realloc_struct_inst.callback (ptr, length, Realloc_struct_inst.actualCalls);
    }
    if (Realloc_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'Realloc', returning random value.");
        return default_res;
    }

    if(strcmp(opmock_get_current_call(), "void * Realloc (void * ptr, size_t length)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'void * Realloc(void * ptr, size_t length)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (Realloc_struct_inst.calls[0].check_params == 1) {
        if(Realloc_struct_inst.calls[0].match_ptr) {
            void * val1 = (void *) &Realloc_struct_inst.calls[0].ptr;
            void * val2 = (void *) &ptr;
            int match_result = Realloc_struct_inst.calls[0].match_ptr(val1, val2, "ptr", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'Realloc', %s",Realloc_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
        if(Realloc_struct_inst.calls[0].match_length) {
            void * val1 = (void *) &Realloc_struct_inst.calls[0].length;
            void * val2 = (void *) &length;
            int match_result = Realloc_struct_inst.calls[0].match_length(val1, val2, "length", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'Realloc', %s",Realloc_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < Realloc_struct_inst.expectedCalls; opmock_i++) {
        Realloc_struct_inst.calls[opmock_i - 1] = Realloc_struct_inst.calls[opmock_i];
    }

    Realloc_struct_inst.expectedCalls--;
    return default_res;
}

void Realloc_MockReset()
{
    Realloc_struct_inst.expectedCalls = 0;
    Realloc_struct_inst.actualCalls = 0;
    Realloc_struct_inst.callback = NULL;
}

void Realloc_MockWithCallback(OPMOCK_Realloc_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    Realloc_struct_inst.callback = callback;
    Realloc_struct_inst.expectedCalls = 0;
    Realloc_struct_inst.actualCalls = 0;
}

void Realloc_VerifyMock()
{
    if (Realloc_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'Realloc'",Realloc_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void Realloc_ExpectAndReturn (void * ptr, size_t length, void * to_return, OPMOCK_MATCHER match_ptr, OPMOCK_MATCHER match_length)
{
    if(Realloc_struct_inst.callback != NULL)
    {
        Realloc_MockReset ();
    }

    if(Realloc_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting Realloc_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"void * Realloc (void * ptr, size_t length)");
    Realloc_struct_inst.calls[Realloc_struct_inst.expectedCalls].ptr = (void *)ptr;
    Realloc_struct_inst.calls[Realloc_struct_inst.expectedCalls].length = (unsigned long)length;
    Realloc_struct_inst.calls[Realloc_struct_inst.expectedCalls].match_ptr = match_ptr;
    Realloc_struct_inst.calls[Realloc_struct_inst.expectedCalls].match_length = match_length;
    Realloc_struct_inst.calls[Realloc_struct_inst.expectedCalls].to_return = (void *) to_return;
    Realloc_struct_inst.calls[Realloc_struct_inst.expectedCalls].check_params = 1;
    Realloc_struct_inst.expectedCalls++;
}

char * StrDup(const char * ptr)
{
    char * default_res = (char *)StrDup_struct_inst.calls[0].to_return;
    int opmock_i;
    StrDup_struct_inst.actualCalls++;

    if (StrDup_struct_inst.callback != NULL)
    {
        return StrDup_struct_inst.callback (ptr, StrDup_struct_inst.actualCalls);
    }
    if (StrDup_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'StrDup', returning random value.");
        return default_res;
    }

    if(strcmp(opmock_get_current_call(), "char * StrDup (const char * ptr)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'char * StrDup(const char * ptr)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (StrDup_struct_inst.calls[0].check_params == 1) {
        if(StrDup_struct_inst.calls[0].match_ptr) {
            void * val1 = (void *) &StrDup_struct_inst.calls[0].ptr;
            void * val2 = (void *) &ptr;
            int match_result = StrDup_struct_inst.calls[0].match_ptr(val1, val2, "ptr", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'StrDup', %s",StrDup_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < StrDup_struct_inst.expectedCalls; opmock_i++) {
        StrDup_struct_inst.calls[opmock_i - 1] = StrDup_struct_inst.calls[opmock_i];
    }

    StrDup_struct_inst.expectedCalls--;
    return default_res;
}

void StrDup_MockReset()
{
    StrDup_struct_inst.expectedCalls = 0;
    StrDup_struct_inst.actualCalls = 0;
    StrDup_struct_inst.callback = NULL;
}

void StrDup_MockWithCallback(OPMOCK_StrDup_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    StrDup_struct_inst.callback = callback;
    StrDup_struct_inst.expectedCalls = 0;
    StrDup_struct_inst.actualCalls = 0;
}

void StrDup_VerifyMock()
{
    if (StrDup_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'StrDup'",StrDup_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void StrDup_ExpectAndReturn (const char * ptr, char * to_return, OPMOCK_MATCHER match_ptr)
{
    if(StrDup_struct_inst.callback != NULL)
    {
        StrDup_MockReset ();
    }

    if(StrDup_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting StrDup_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"char * StrDup (const char * ptr)");
    StrDup_struct_inst.calls[StrDup_struct_inst.expectedCalls].ptr = (void *)ptr;
    StrDup_struct_inst.calls[StrDup_struct_inst.expectedCalls].match_ptr = match_ptr;
    StrDup_struct_inst.calls[StrDup_struct_inst.expectedCalls].to_return = (char *) to_return;
    StrDup_struct_inst.calls[StrDup_struct_inst.expectedCalls].check_params = 1;
    StrDup_struct_inst.expectedCalls++;
}

void Free(void * ptr)
{
    int opmock_i;
    Free_struct_inst.actualCalls++;

    if (Free_struct_inst.callback != NULL)
    {
        Free_struct_inst.callback (ptr, Free_struct_inst.actualCalls);
        return;
    }
    if (Free_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'Free', returning random value.");
        return;
    }

    if(strcmp(opmock_get_current_call(), "void Free (void * ptr)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'void Free(void * ptr)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (Free_struct_inst.calls[0].check_params == 1) {
        if(Free_struct_inst.calls[0].match_ptr) {
            void * val1 = (void *) &Free_struct_inst.calls[0].ptr;
            void * val2 = (void *) &ptr;
            int match_result = Free_struct_inst.calls[0].match_ptr(val1, val2, "ptr", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'Free', %s",Free_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < Free_struct_inst.expectedCalls; opmock_i++) {
        Free_struct_inst.calls[opmock_i - 1] = Free_struct_inst.calls[opmock_i];
    }

    Free_struct_inst.expectedCalls--;
}

void Free_MockReset()
{
    Free_struct_inst.expectedCalls = 0;
    Free_struct_inst.actualCalls = 0;
    Free_struct_inst.callback = NULL;
}

void Free_MockWithCallback(OPMOCK_Free_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    Free_struct_inst.callback = callback;
    Free_struct_inst.expectedCalls = 0;
    Free_struct_inst.actualCalls = 0;
}

void Free_VerifyMock()
{
    if (Free_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'Free'",Free_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void Free_ExpectAndReturn (void * ptr, OPMOCK_MATCHER match_ptr)
{
    if(Free_struct_inst.callback != NULL)
    {
        Free_MockReset ();
    }

    if(Free_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting Free_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"void Free (void * ptr)");
    Free_struct_inst.calls[Free_struct_inst.expectedCalls].ptr = (void *)ptr;
    Free_struct_inst.calls[Free_struct_inst.expectedCalls].match_ptr = match_ptr;
    Free_struct_inst.calls[Free_struct_inst.expectedCalls].check_params = 1;
    Free_struct_inst.expectedCalls++;
}

#pragma GCC diagnostic pop

