/* OPMOCK2 GENERATED CODE - DO NOT MODIFY */
#include "vector_stub.h"
#include <stdio.h>
#include <string.h>

typedef struct
{
    unsigned long capacity;
    unsigned long elementSize;
    OPMOCK_MATCHER match_capacity;
    OPMOCK_MATCHER match_elementSize;
    struct _Vector * to_return;
    char check_params;
} vector_new_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_vector_new_CALLBACK callback;
    vector_new_call calls[MAX_FUNC_CALL];
} vector_new_struct;

static vector_new_struct vector_new_struct_inst;

typedef struct
{
    void * thisVector;
    void * data;
    OPMOCK_MATCHER match_thisVector;
    OPMOCK_MATCHER match_data;
    void * to_return;
    char check_params;
} vector_push_back_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_vector_push_back_CALLBACK callback;
    vector_push_back_call calls[MAX_FUNC_CALL];
} vector_push_back_struct;

static vector_push_back_struct vector_push_back_struct_inst;

typedef struct
{
    void * thisVector;
    unsigned long index;
    OPMOCK_MATCHER match_thisVector;
    OPMOCK_MATCHER match_index;
    void * to_return;
    char check_params;
} vector_get_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_vector_get_CALLBACK callback;
    vector_get_call calls[MAX_FUNC_CALL];
} vector_get_struct;

static vector_get_struct vector_get_struct_inst;

typedef struct
{
    void * thisVector;
    unsigned long index;
    OPMOCK_MATCHER match_thisVector;
    OPMOCK_MATCHER match_index;
    char check_params;
} vector_delete_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_vector_delete_CALLBACK callback;
    vector_delete_call calls[MAX_FUNC_CALL];
} vector_delete_struct;

static vector_delete_struct vector_delete_struct_inst;

typedef struct
{
    void * thisVector;
    OPMOCK_MATCHER match_thisVector;
    unsigned long to_return;
    char check_params;
} vector_length_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_vector_length_CALLBACK callback;
    vector_length_call calls[MAX_FUNC_CALL];
} vector_length_struct;

static vector_length_struct vector_length_struct_inst;

typedef struct
{
    void * thisVector;
    OPMOCK_MATCHER match_thisVector;
    char check_params;
} vector_free_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_vector_free_CALLBACK callback;
    vector_free_call calls[MAX_FUNC_CALL];
} vector_free_struct;

static vector_free_struct vector_free_struct_inst;

static void opmock_reset_all_mocks_in_this_header()
{
    vector_new_MockReset();
    vector_push_back_MockReset();
    vector_get_MockReset();
    vector_delete_MockReset();
    vector_length_MockReset();
    vector_free_MockReset();
}

static void opmock_verify_all_mocks_in_this_header()
{
    vector_new_VerifyMock();
    vector_push_back_VerifyMock();
    vector_get_VerifyMock();
    vector_delete_VerifyMock();
    vector_length_VerifyMock();
    vector_free_VerifyMock();
}

Vector * vector_new(size_t capacity, size_t elementSize)
{
    Vector * default_res = (Vector *)vector_new_struct_inst.calls[0].to_return;
    int opmock_i;
    vector_new_struct_inst.actualCalls++;

    if (vector_new_struct_inst.callback != NULL)
    {
        return vector_new_struct_inst.callback (capacity, elementSize, vector_new_struct_inst.actualCalls);
    }
    if (vector_new_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'vector_new', returning random value.");
        return default_res;
    }

    if(strcmp(opmock_get_current_call(), "Vector * vector_new (size_t capacity, size_t elementSize)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'Vector * vector_new(size_t capacity, size_t elementSize)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (vector_new_struct_inst.calls[0].check_params == 1) {
        if(vector_new_struct_inst.calls[0].match_capacity) {
            void * val1 = (void *) &vector_new_struct_inst.calls[0].capacity;
            void * val2 = (void *) &capacity;
            int match_result = vector_new_struct_inst.calls[0].match_capacity(val1, val2, "capacity", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'vector_new', %s",vector_new_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
        if(vector_new_struct_inst.calls[0].match_elementSize) {
            void * val1 = (void *) &vector_new_struct_inst.calls[0].elementSize;
            void * val2 = (void *) &elementSize;
            int match_result = vector_new_struct_inst.calls[0].match_elementSize(val1, val2, "elementSize", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'vector_new', %s",vector_new_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < vector_new_struct_inst.expectedCalls; opmock_i++) {
        vector_new_struct_inst.calls[opmock_i - 1] = vector_new_struct_inst.calls[opmock_i];
    }

    vector_new_struct_inst.expectedCalls--;
    return default_res;
}

void vector_new_MockReset()
{
    vector_new_struct_inst.expectedCalls = 0;
    vector_new_struct_inst.actualCalls = 0;
    vector_new_struct_inst.callback = NULL;
}

void vector_new_MockWithCallback(OPMOCK_vector_new_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    vector_new_struct_inst.callback = callback;
    vector_new_struct_inst.expectedCalls = 0;
    vector_new_struct_inst.actualCalls = 0;
}

void vector_new_VerifyMock()
{
    if (vector_new_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'vector_new'",vector_new_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void vector_new_ExpectAndReturn (size_t capacity, size_t elementSize, Vector * to_return, OPMOCK_MATCHER match_capacity, OPMOCK_MATCHER match_elementSize)
{
    if(vector_new_struct_inst.callback != NULL)
    {
        vector_new_MockReset ();
    }

    if(vector_new_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting vector_new_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"Vector * vector_new (size_t capacity, size_t elementSize)");
    vector_new_struct_inst.calls[vector_new_struct_inst.expectedCalls].capacity = (unsigned long)capacity;
    vector_new_struct_inst.calls[vector_new_struct_inst.expectedCalls].elementSize = (unsigned long)elementSize;
    vector_new_struct_inst.calls[vector_new_struct_inst.expectedCalls].match_capacity = match_capacity;
    vector_new_struct_inst.calls[vector_new_struct_inst.expectedCalls].match_elementSize = match_elementSize;
    vector_new_struct_inst.calls[vector_new_struct_inst.expectedCalls].to_return = (struct _Vector *) to_return;
    vector_new_struct_inst.calls[vector_new_struct_inst.expectedCalls].check_params = 1;
    vector_new_struct_inst.expectedCalls++;
}

void * vector_push_back(Vector * thisVector, void * data)
{
    void * default_res = (void *)vector_push_back_struct_inst.calls[0].to_return;
    int opmock_i;
    vector_push_back_struct_inst.actualCalls++;

    if (vector_push_back_struct_inst.callback != NULL)
    {
        return vector_push_back_struct_inst.callback (thisVector, data, vector_push_back_struct_inst.actualCalls);
    }
    if (vector_push_back_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'vector_push_back', returning random value.");
        return default_res;
    }

    if(strcmp(opmock_get_current_call(), "void * vector_push_back (Vector * thisVector, void * data)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'void * vector_push_back(Vector * thisVector, void * data)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (vector_push_back_struct_inst.calls[0].check_params == 1) {
        if(vector_push_back_struct_inst.calls[0].match_thisVector) {
            void * val1 = (void *) &vector_push_back_struct_inst.calls[0].thisVector;
            void * val2 = (void *) &thisVector;
            int match_result = vector_push_back_struct_inst.calls[0].match_thisVector(val1, val2, "thisVector", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'vector_push_back', %s",vector_push_back_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
        if(vector_push_back_struct_inst.calls[0].match_data) {
            void * val1 = (void *) &vector_push_back_struct_inst.calls[0].data;
            void * val2 = (void *) &data;
            int match_result = vector_push_back_struct_inst.calls[0].match_data(val1, val2, "data", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'vector_push_back', %s",vector_push_back_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < vector_push_back_struct_inst.expectedCalls; opmock_i++) {
        vector_push_back_struct_inst.calls[opmock_i - 1] = vector_push_back_struct_inst.calls[opmock_i];
    }

    vector_push_back_struct_inst.expectedCalls--;
    return default_res;
}

void vector_push_back_MockReset()
{
    vector_push_back_struct_inst.expectedCalls = 0;
    vector_push_back_struct_inst.actualCalls = 0;
    vector_push_back_struct_inst.callback = NULL;
}

void vector_push_back_MockWithCallback(OPMOCK_vector_push_back_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    vector_push_back_struct_inst.callback = callback;
    vector_push_back_struct_inst.expectedCalls = 0;
    vector_push_back_struct_inst.actualCalls = 0;
}

void vector_push_back_VerifyMock()
{
    if (vector_push_back_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'vector_push_back'",vector_push_back_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void vector_push_back_ExpectAndReturn (Vector * thisVector, void * data, void * to_return, OPMOCK_MATCHER match_thisVector, OPMOCK_MATCHER match_data)
{
    if(vector_push_back_struct_inst.callback != NULL)
    {
        vector_push_back_MockReset ();
    }

    if(vector_push_back_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting vector_push_back_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"void * vector_push_back (Vector * thisVector, void * data)");
    vector_push_back_struct_inst.calls[vector_push_back_struct_inst.expectedCalls].thisVector = (void *)thisVector;
    vector_push_back_struct_inst.calls[vector_push_back_struct_inst.expectedCalls].data = (void *)data;
    vector_push_back_struct_inst.calls[vector_push_back_struct_inst.expectedCalls].match_thisVector = match_thisVector;
    vector_push_back_struct_inst.calls[vector_push_back_struct_inst.expectedCalls].match_data = match_data;
    vector_push_back_struct_inst.calls[vector_push_back_struct_inst.expectedCalls].to_return = (void *) to_return;
    vector_push_back_struct_inst.calls[vector_push_back_struct_inst.expectedCalls].check_params = 1;
    vector_push_back_struct_inst.expectedCalls++;
}

void * vector_get(Vector * thisVector, size_t index)
{
    void * default_res = (void *)vector_get_struct_inst.calls[0].to_return;
    int opmock_i;
    vector_get_struct_inst.actualCalls++;

    if (vector_get_struct_inst.callback != NULL)
    {
        return vector_get_struct_inst.callback (thisVector, index, vector_get_struct_inst.actualCalls);
    }
    if (vector_get_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'vector_get', returning random value.");
        return default_res;
    }

    if(strcmp(opmock_get_current_call(), "void * vector_get (Vector * thisVector, size_t index)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'void * vector_get(Vector * thisVector, size_t index)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (vector_get_struct_inst.calls[0].check_params == 1) {
        if(vector_get_struct_inst.calls[0].match_thisVector) {
            void * val1 = (void *) &vector_get_struct_inst.calls[0].thisVector;
            void * val2 = (void *) &thisVector;
            int match_result = vector_get_struct_inst.calls[0].match_thisVector(val1, val2, "thisVector", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'vector_get', %s",vector_get_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
        if(vector_get_struct_inst.calls[0].match_index) {
            void * val1 = (void *) &vector_get_struct_inst.calls[0].index;
            void * val2 = (void *) &index;
            int match_result = vector_get_struct_inst.calls[0].match_index(val1, val2, "index", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'vector_get', %s",vector_get_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < vector_get_struct_inst.expectedCalls; opmock_i++) {
        vector_get_struct_inst.calls[opmock_i - 1] = vector_get_struct_inst.calls[opmock_i];
    }

    vector_get_struct_inst.expectedCalls--;
    return default_res;
}

void vector_get_MockReset()
{
    vector_get_struct_inst.expectedCalls = 0;
    vector_get_struct_inst.actualCalls = 0;
    vector_get_struct_inst.callback = NULL;
}

void vector_get_MockWithCallback(OPMOCK_vector_get_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    vector_get_struct_inst.callback = callback;
    vector_get_struct_inst.expectedCalls = 0;
    vector_get_struct_inst.actualCalls = 0;
}

void vector_get_VerifyMock()
{
    if (vector_get_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'vector_get'",vector_get_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void vector_get_ExpectAndReturn (Vector * thisVector, size_t index, void * to_return, OPMOCK_MATCHER match_thisVector, OPMOCK_MATCHER match_index)
{
    if(vector_get_struct_inst.callback != NULL)
    {
        vector_get_MockReset ();
    }

    if(vector_get_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting vector_get_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"void * vector_get (Vector * thisVector, size_t index)");
    vector_get_struct_inst.calls[vector_get_struct_inst.expectedCalls].thisVector = (void *)thisVector;
    vector_get_struct_inst.calls[vector_get_struct_inst.expectedCalls].index = (unsigned long)index;
    vector_get_struct_inst.calls[vector_get_struct_inst.expectedCalls].match_thisVector = match_thisVector;
    vector_get_struct_inst.calls[vector_get_struct_inst.expectedCalls].match_index = match_index;
    vector_get_struct_inst.calls[vector_get_struct_inst.expectedCalls].to_return = (void *) to_return;
    vector_get_struct_inst.calls[vector_get_struct_inst.expectedCalls].check_params = 1;
    vector_get_struct_inst.expectedCalls++;
}

void vector_delete(Vector * thisVector, size_t index)
{
    int opmock_i;
    vector_delete_struct_inst.actualCalls++;

    if (vector_delete_struct_inst.callback != NULL)
    {
        vector_delete_struct_inst.callback (thisVector, index, vector_delete_struct_inst.actualCalls);
        return;
    }
    if (vector_delete_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'vector_delete', returning random value.");
        return;
    }

    if(strcmp(opmock_get_current_call(), "void vector_delete (Vector * thisVector, size_t index)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'void vector_delete(Vector * thisVector, size_t index)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (vector_delete_struct_inst.calls[0].check_params == 1) {
        if(vector_delete_struct_inst.calls[0].match_thisVector) {
            void * val1 = (void *) &vector_delete_struct_inst.calls[0].thisVector;
            void * val2 = (void *) &thisVector;
            int match_result = vector_delete_struct_inst.calls[0].match_thisVector(val1, val2, "thisVector", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'vector_delete', %s",vector_delete_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
        if(vector_delete_struct_inst.calls[0].match_index) {
            void * val1 = (void *) &vector_delete_struct_inst.calls[0].index;
            void * val2 = (void *) &index;
            int match_result = vector_delete_struct_inst.calls[0].match_index(val1, val2, "index", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'vector_delete', %s",vector_delete_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < vector_delete_struct_inst.expectedCalls; opmock_i++) {
        vector_delete_struct_inst.calls[opmock_i - 1] = vector_delete_struct_inst.calls[opmock_i];
    }

    vector_delete_struct_inst.expectedCalls--;
}

void vector_delete_MockReset()
{
    vector_delete_struct_inst.expectedCalls = 0;
    vector_delete_struct_inst.actualCalls = 0;
    vector_delete_struct_inst.callback = NULL;
}

void vector_delete_MockWithCallback(OPMOCK_vector_delete_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    vector_delete_struct_inst.callback = callback;
    vector_delete_struct_inst.expectedCalls = 0;
    vector_delete_struct_inst.actualCalls = 0;
}

void vector_delete_VerifyMock()
{
    if (vector_delete_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'vector_delete'",vector_delete_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void vector_delete_ExpectAndReturn (Vector * thisVector, size_t index, OPMOCK_MATCHER match_thisVector, OPMOCK_MATCHER match_index)
{
    if(vector_delete_struct_inst.callback != NULL)
    {
        vector_delete_MockReset ();
    }

    if(vector_delete_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting vector_delete_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"void vector_delete (Vector * thisVector, size_t index)");
    vector_delete_struct_inst.calls[vector_delete_struct_inst.expectedCalls].thisVector = (void *)thisVector;
    vector_delete_struct_inst.calls[vector_delete_struct_inst.expectedCalls].index = (unsigned long)index;
    vector_delete_struct_inst.calls[vector_delete_struct_inst.expectedCalls].match_thisVector = match_thisVector;
    vector_delete_struct_inst.calls[vector_delete_struct_inst.expectedCalls].match_index = match_index;
    vector_delete_struct_inst.calls[vector_delete_struct_inst.expectedCalls].check_params = 1;
    vector_delete_struct_inst.expectedCalls++;
}

size_t vector_length(Vector * thisVector)
{
    size_t default_res = (size_t)vector_length_struct_inst.calls[0].to_return;
    int opmock_i;
    vector_length_struct_inst.actualCalls++;

    if (vector_length_struct_inst.callback != NULL)
    {
        return vector_length_struct_inst.callback (thisVector, vector_length_struct_inst.actualCalls);
    }
    if (vector_length_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'vector_length', returning random value.");
        return default_res;
    }

    if(strcmp(opmock_get_current_call(), "size_t vector_length (Vector * thisVector)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'size_t vector_length(Vector * thisVector)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (vector_length_struct_inst.calls[0].check_params == 1) {
        if(vector_length_struct_inst.calls[0].match_thisVector) {
            void * val1 = (void *) &vector_length_struct_inst.calls[0].thisVector;
            void * val2 = (void *) &thisVector;
            int match_result = vector_length_struct_inst.calls[0].match_thisVector(val1, val2, "thisVector", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'vector_length', %s",vector_length_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < vector_length_struct_inst.expectedCalls; opmock_i++) {
        vector_length_struct_inst.calls[opmock_i - 1] = vector_length_struct_inst.calls[opmock_i];
    }

    vector_length_struct_inst.expectedCalls--;
    return default_res;
}

void vector_length_MockReset()
{
    vector_length_struct_inst.expectedCalls = 0;
    vector_length_struct_inst.actualCalls = 0;
    vector_length_struct_inst.callback = NULL;
}

void vector_length_MockWithCallback(OPMOCK_vector_length_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    vector_length_struct_inst.callback = callback;
    vector_length_struct_inst.expectedCalls = 0;
    vector_length_struct_inst.actualCalls = 0;
}

void vector_length_VerifyMock()
{
    if (vector_length_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'vector_length'",vector_length_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void vector_length_ExpectAndReturn (Vector * thisVector, size_t to_return, OPMOCK_MATCHER match_thisVector)
{
    if(vector_length_struct_inst.callback != NULL)
    {
        vector_length_MockReset ();
    }

    if(vector_length_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting vector_length_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"size_t vector_length (Vector * thisVector)");
    vector_length_struct_inst.calls[vector_length_struct_inst.expectedCalls].thisVector = (void *)thisVector;
    vector_length_struct_inst.calls[vector_length_struct_inst.expectedCalls].match_thisVector = match_thisVector;
    vector_length_struct_inst.calls[vector_length_struct_inst.expectedCalls].to_return = (unsigned long) to_return;
    vector_length_struct_inst.calls[vector_length_struct_inst.expectedCalls].check_params = 1;
    vector_length_struct_inst.expectedCalls++;
}

void vector_free(Vector * thisVector)
{
    int opmock_i;
    vector_free_struct_inst.actualCalls++;

    if (vector_free_struct_inst.callback != NULL)
    {
        vector_free_struct_inst.callback (thisVector, vector_free_struct_inst.actualCalls);
        return;
    }
    if (vector_free_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'vector_free', returning random value.");
        return;
    }

    if(strcmp(opmock_get_current_call(), "void vector_free (Vector * thisVector)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'void vector_free(Vector * thisVector)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (vector_free_struct_inst.calls[0].check_params == 1) {
        if(vector_free_struct_inst.calls[0].match_thisVector) {
            void * val1 = (void *) &vector_free_struct_inst.calls[0].thisVector;
            void * val2 = (void *) &thisVector;
            int match_result = vector_free_struct_inst.calls[0].match_thisVector(val1, val2, "thisVector", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'vector_free', %s",vector_free_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < vector_free_struct_inst.expectedCalls; opmock_i++) {
        vector_free_struct_inst.calls[opmock_i - 1] = vector_free_struct_inst.calls[opmock_i];
    }

    vector_free_struct_inst.expectedCalls--;
}

void vector_free_MockReset()
{
    vector_free_struct_inst.expectedCalls = 0;
    vector_free_struct_inst.actualCalls = 0;
    vector_free_struct_inst.callback = NULL;
}

void vector_free_MockWithCallback(OPMOCK_vector_free_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    vector_free_struct_inst.callback = callback;
    vector_free_struct_inst.expectedCalls = 0;
    vector_free_struct_inst.actualCalls = 0;
}

void vector_free_VerifyMock()
{
    if (vector_free_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'vector_free'",vector_free_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void vector_free_ExpectAndReturn (Vector * thisVector, OPMOCK_MATCHER match_thisVector)
{
    if(vector_free_struct_inst.callback != NULL)
    {
        vector_free_MockReset ();
    }

    if(vector_free_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting vector_free_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"void vector_free (Vector * thisVector)");
    vector_free_struct_inst.calls[vector_free_struct_inst.expectedCalls].thisVector = (void *)thisVector;
    vector_free_struct_inst.calls[vector_free_struct_inst.expectedCalls].match_thisVector = match_thisVector;
    vector_free_struct_inst.calls[vector_free_struct_inst.expectedCalls].check_params = 1;
    vector_free_struct_inst.expectedCalls++;
}

