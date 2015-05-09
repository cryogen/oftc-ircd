/* OPMOCK2 GENERATED CODE - DO NOT MODIFY */
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-prototypes"

#include "hash_stub.h"
#include <stdio.h>
#include <string.h>

typedef struct
{
    char check_params;
} hash_init_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_hash_init_CALLBACK callback;
    hash_init_call calls[MAX_FUNC_CALL];
} hash_init_struct;

static hash_init_struct hash_init_struct_inst;

typedef struct
{
    void * name;
    unsigned long length;
    OPMOCK_MATCHER match_name;
    OPMOCK_MATCHER match_length;
    struct _Hash * to_return;
    char check_params;
} hash_new_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_hash_new_CALLBACK callback;
    hash_new_call calls[MAX_FUNC_CALL];
} hash_new_struct;

static hash_new_struct hash_new_struct_inst;

typedef struct
{
    void * this;
    void * key;
    void * value;
    OPMOCK_MATCHER match_this;
    OPMOCK_MATCHER match_key;
    OPMOCK_MATCHER match_value;
    char check_params;
} hash_add_string_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_hash_add_string_CALLBACK callback;
    hash_add_string_call calls[MAX_FUNC_CALL];
} hash_add_string_struct;

static hash_add_string_struct hash_add_string_struct_inst;

typedef struct
{
    void * this;
    void * key;
    OPMOCK_MATCHER match_this;
    OPMOCK_MATCHER match_key;
    void * to_return;
    char check_params;
} hash_find_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_hash_find_CALLBACK callback;
    hash_find_call calls[MAX_FUNC_CALL];
} hash_find_struct;

static hash_find_struct hash_find_struct_inst;

typedef struct
{
    void * this;
    void * key;
    OPMOCK_MATCHER match_this;
    OPMOCK_MATCHER match_key;
    char check_params;
} hash_delete_string_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_hash_delete_string_CALLBACK callback;
    hash_delete_string_call calls[MAX_FUNC_CALL];
} hash_delete_string_struct;

static hash_delete_string_struct hash_delete_string_struct_inst;

static void opmock_reset_all_mocks_in_this_header()
{
    hash_init_MockReset();
    hash_new_MockReset();
    hash_add_string_MockReset();
    hash_find_MockReset();
    hash_delete_string_MockReset();
}

static void opmock_verify_all_mocks_in_this_header()
{
    hash_init_VerifyMock();
    hash_new_VerifyMock();
    hash_add_string_VerifyMock();
    hash_find_VerifyMock();
    hash_delete_string_VerifyMock();
}

void hash_init()
{
    int opmock_i;
    hash_init_struct_inst.actualCalls++;

    if (hash_init_struct_inst.callback != NULL)
    {
        hash_init_struct_inst.callback (hash_init_struct_inst.actualCalls);
        return;
    }
    if (hash_init_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'hash_init', returning random value.");
        return;
    }

    if(strcmp(opmock_get_current_call(), "void hash_init ()") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'void hash_init()',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (hash_init_struct_inst.calls[0].check_params == 1) {
    }

    for(opmock_i = 1; opmock_i < hash_init_struct_inst.expectedCalls; opmock_i++) {
        hash_init_struct_inst.calls[opmock_i - 1] = hash_init_struct_inst.calls[opmock_i];
    }

    hash_init_struct_inst.expectedCalls--;
}

void hash_init_MockReset()
{
    hash_init_struct_inst.expectedCalls = 0;
    hash_init_struct_inst.actualCalls = 0;
    hash_init_struct_inst.callback = NULL;
}

void hash_init_MockWithCallback(OPMOCK_hash_init_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    hash_init_struct_inst.callback = callback;
    hash_init_struct_inst.expectedCalls = 0;
    hash_init_struct_inst.actualCalls = 0;
}

void hash_init_VerifyMock()
{
    if (hash_init_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'hash_init'",hash_init_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void hash_init_ExpectAndReturn ()
{
    if(hash_init_struct_inst.callback != NULL)
    {
        hash_init_MockReset ();
    }

    if(hash_init_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting hash_init_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"void hash_init ()");
    hash_init_struct_inst.calls[hash_init_struct_inst.expectedCalls].check_params = 1;
    hash_init_struct_inst.expectedCalls++;
}

Hash * hash_new(const char * name, size_t length)
{
    Hash * default_res = (Hash *)hash_new_struct_inst.calls[0].to_return;
    int opmock_i;
    hash_new_struct_inst.actualCalls++;

    if (hash_new_struct_inst.callback != NULL)
    {
        return hash_new_struct_inst.callback (name, length, hash_new_struct_inst.actualCalls);
    }
    if (hash_new_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'hash_new', returning random value.");
        return default_res;
    }

    if(strcmp(opmock_get_current_call(), "Hash * hash_new (const char * name, size_t length)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'Hash * hash_new(const char * name, size_t length)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (hash_new_struct_inst.calls[0].check_params == 1) {
        if(hash_new_struct_inst.calls[0].match_name) {
            void * val1 = (void *) &hash_new_struct_inst.calls[0].name;
            void * val2 = (void *) &name;
            int match_result = hash_new_struct_inst.calls[0].match_name(val1, val2, "name", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'hash_new', %s",hash_new_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
        if(hash_new_struct_inst.calls[0].match_length) {
            void * val1 = (void *) &hash_new_struct_inst.calls[0].length;
            void * val2 = (void *) &length;
            int match_result = hash_new_struct_inst.calls[0].match_length(val1, val2, "length", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'hash_new', %s",hash_new_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < hash_new_struct_inst.expectedCalls; opmock_i++) {
        hash_new_struct_inst.calls[opmock_i - 1] = hash_new_struct_inst.calls[opmock_i];
    }

    hash_new_struct_inst.expectedCalls--;
    return default_res;
}

void hash_new_MockReset()
{
    hash_new_struct_inst.expectedCalls = 0;
    hash_new_struct_inst.actualCalls = 0;
    hash_new_struct_inst.callback = NULL;
}

void hash_new_MockWithCallback(OPMOCK_hash_new_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    hash_new_struct_inst.callback = callback;
    hash_new_struct_inst.expectedCalls = 0;
    hash_new_struct_inst.actualCalls = 0;
}

void hash_new_VerifyMock()
{
    if (hash_new_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'hash_new'",hash_new_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void hash_new_ExpectAndReturn (const char * name, size_t length, Hash * to_return, OPMOCK_MATCHER match_name, OPMOCK_MATCHER match_length)
{
    if(hash_new_struct_inst.callback != NULL)
    {
        hash_new_MockReset ();
    }

    if(hash_new_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting hash_new_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"Hash * hash_new (const char * name, size_t length)");
    hash_new_struct_inst.calls[hash_new_struct_inst.expectedCalls].name = (void *)name;
    hash_new_struct_inst.calls[hash_new_struct_inst.expectedCalls].length = (unsigned long)length;
    hash_new_struct_inst.calls[hash_new_struct_inst.expectedCalls].match_name = match_name;
    hash_new_struct_inst.calls[hash_new_struct_inst.expectedCalls].match_length = match_length;
    hash_new_struct_inst.calls[hash_new_struct_inst.expectedCalls].to_return = (struct _Hash *) to_return;
    hash_new_struct_inst.calls[hash_new_struct_inst.expectedCalls].check_params = 1;
    hash_new_struct_inst.expectedCalls++;
}

void hash_add_string(Hash * this, const char * key, void * value)
{
    int opmock_i;
    hash_add_string_struct_inst.actualCalls++;

    if (hash_add_string_struct_inst.callback != NULL)
    {
        hash_add_string_struct_inst.callback (this, key, value, hash_add_string_struct_inst.actualCalls);
        return;
    }
    if (hash_add_string_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'hash_add_string', returning random value.");
        return;
    }

    if(strcmp(opmock_get_current_call(), "void hash_add_string (Hash * this, const char * key, void * value)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'void hash_add_string(Hash * this, const char * key, void * value)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (hash_add_string_struct_inst.calls[0].check_params == 1) {
        if(hash_add_string_struct_inst.calls[0].match_this) {
            void * val1 = (void *) &hash_add_string_struct_inst.calls[0].this;
            void * val2 = (void *) &this;
            int match_result = hash_add_string_struct_inst.calls[0].match_this(val1, val2, "this", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'hash_add_string', %s",hash_add_string_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
        if(hash_add_string_struct_inst.calls[0].match_key) {
            void * val1 = (void *) &hash_add_string_struct_inst.calls[0].key;
            void * val2 = (void *) &key;
            int match_result = hash_add_string_struct_inst.calls[0].match_key(val1, val2, "key", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'hash_add_string', %s",hash_add_string_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
        if(hash_add_string_struct_inst.calls[0].match_value) {
            void * val1 = (void *) &hash_add_string_struct_inst.calls[0].value;
            void * val2 = (void *) &value;
            int match_result = hash_add_string_struct_inst.calls[0].match_value(val1, val2, "value", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'hash_add_string', %s",hash_add_string_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < hash_add_string_struct_inst.expectedCalls; opmock_i++) {
        hash_add_string_struct_inst.calls[opmock_i - 1] = hash_add_string_struct_inst.calls[opmock_i];
    }

    hash_add_string_struct_inst.expectedCalls--;
}

void hash_add_string_MockReset()
{
    hash_add_string_struct_inst.expectedCalls = 0;
    hash_add_string_struct_inst.actualCalls = 0;
    hash_add_string_struct_inst.callback = NULL;
}

void hash_add_string_MockWithCallback(OPMOCK_hash_add_string_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    hash_add_string_struct_inst.callback = callback;
    hash_add_string_struct_inst.expectedCalls = 0;
    hash_add_string_struct_inst.actualCalls = 0;
}

void hash_add_string_VerifyMock()
{
    if (hash_add_string_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'hash_add_string'",hash_add_string_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void hash_add_string_ExpectAndReturn (Hash * this, const char * key, void * value, OPMOCK_MATCHER match_this, OPMOCK_MATCHER match_key, OPMOCK_MATCHER match_value)
{
    if(hash_add_string_struct_inst.callback != NULL)
    {
        hash_add_string_MockReset ();
    }

    if(hash_add_string_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting hash_add_string_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"void hash_add_string (Hash * this, const char * key, void * value)");
    hash_add_string_struct_inst.calls[hash_add_string_struct_inst.expectedCalls].this = (void *)this;
    hash_add_string_struct_inst.calls[hash_add_string_struct_inst.expectedCalls].key = (void *)key;
    hash_add_string_struct_inst.calls[hash_add_string_struct_inst.expectedCalls].value = (void *)value;
    hash_add_string_struct_inst.calls[hash_add_string_struct_inst.expectedCalls].match_this = match_this;
    hash_add_string_struct_inst.calls[hash_add_string_struct_inst.expectedCalls].match_key = match_key;
    hash_add_string_struct_inst.calls[hash_add_string_struct_inst.expectedCalls].match_value = match_value;
    hash_add_string_struct_inst.calls[hash_add_string_struct_inst.expectedCalls].check_params = 1;
    hash_add_string_struct_inst.expectedCalls++;
}

void * hash_find(Hash * this, const char * key)
{
    void * default_res = (void *)hash_find_struct_inst.calls[0].to_return;
    int opmock_i;
    hash_find_struct_inst.actualCalls++;

    if (hash_find_struct_inst.callback != NULL)
    {
        return hash_find_struct_inst.callback (this, key, hash_find_struct_inst.actualCalls);
    }
    if (hash_find_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'hash_find', returning random value.");
        return default_res;
    }

    if(strcmp(opmock_get_current_call(), "void * hash_find (Hash * this, const char * key)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'void * hash_find(Hash * this, const char * key)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (hash_find_struct_inst.calls[0].check_params == 1) {
        if(hash_find_struct_inst.calls[0].match_this) {
            void * val1 = (void *) &hash_find_struct_inst.calls[0].this;
            void * val2 = (void *) &this;
            int match_result = hash_find_struct_inst.calls[0].match_this(val1, val2, "this", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'hash_find', %s",hash_find_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
        if(hash_find_struct_inst.calls[0].match_key) {
            void * val1 = (void *) &hash_find_struct_inst.calls[0].key;
            void * val2 = (void *) &key;
            int match_result = hash_find_struct_inst.calls[0].match_key(val1, val2, "key", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'hash_find', %s",hash_find_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < hash_find_struct_inst.expectedCalls; opmock_i++) {
        hash_find_struct_inst.calls[opmock_i - 1] = hash_find_struct_inst.calls[opmock_i];
    }

    hash_find_struct_inst.expectedCalls--;
    return default_res;
}

void hash_find_MockReset()
{
    hash_find_struct_inst.expectedCalls = 0;
    hash_find_struct_inst.actualCalls = 0;
    hash_find_struct_inst.callback = NULL;
}

void hash_find_MockWithCallback(OPMOCK_hash_find_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    hash_find_struct_inst.callback = callback;
    hash_find_struct_inst.expectedCalls = 0;
    hash_find_struct_inst.actualCalls = 0;
}

void hash_find_VerifyMock()
{
    if (hash_find_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'hash_find'",hash_find_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void hash_find_ExpectAndReturn (Hash * this, const char * key, void * to_return, OPMOCK_MATCHER match_this, OPMOCK_MATCHER match_key)
{
    if(hash_find_struct_inst.callback != NULL)
    {
        hash_find_MockReset ();
    }

    if(hash_find_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting hash_find_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"void * hash_find (Hash * this, const char * key)");
    hash_find_struct_inst.calls[hash_find_struct_inst.expectedCalls].this = (void *)this;
    hash_find_struct_inst.calls[hash_find_struct_inst.expectedCalls].key = (void *)key;
    hash_find_struct_inst.calls[hash_find_struct_inst.expectedCalls].match_this = match_this;
    hash_find_struct_inst.calls[hash_find_struct_inst.expectedCalls].match_key = match_key;
    hash_find_struct_inst.calls[hash_find_struct_inst.expectedCalls].to_return = (void *) to_return;
    hash_find_struct_inst.calls[hash_find_struct_inst.expectedCalls].check_params = 1;
    hash_find_struct_inst.expectedCalls++;
}

void hash_delete_string(Hash * this, const char * key)
{
    int opmock_i;
    hash_delete_string_struct_inst.actualCalls++;

    if (hash_delete_string_struct_inst.callback != NULL)
    {
        hash_delete_string_struct_inst.callback (this, key, hash_delete_string_struct_inst.actualCalls);
        return;
    }
    if (hash_delete_string_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'hash_delete_string', returning random value.");
        return;
    }

    if(strcmp(opmock_get_current_call(), "void hash_delete_string (Hash * this, const char * key)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'void hash_delete_string(Hash * this, const char * key)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (hash_delete_string_struct_inst.calls[0].check_params == 1) {
        if(hash_delete_string_struct_inst.calls[0].match_this) {
            void * val1 = (void *) &hash_delete_string_struct_inst.calls[0].this;
            void * val2 = (void *) &this;
            int match_result = hash_delete_string_struct_inst.calls[0].match_this(val1, val2, "this", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'hash_delete_string', %s",hash_delete_string_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
        if(hash_delete_string_struct_inst.calls[0].match_key) {
            void * val1 = (void *) &hash_delete_string_struct_inst.calls[0].key;
            void * val2 = (void *) &key;
            int match_result = hash_delete_string_struct_inst.calls[0].match_key(val1, val2, "key", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'hash_delete_string', %s",hash_delete_string_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < hash_delete_string_struct_inst.expectedCalls; opmock_i++) {
        hash_delete_string_struct_inst.calls[opmock_i - 1] = hash_delete_string_struct_inst.calls[opmock_i];
    }

    hash_delete_string_struct_inst.expectedCalls--;
}

void hash_delete_string_MockReset()
{
    hash_delete_string_struct_inst.expectedCalls = 0;
    hash_delete_string_struct_inst.actualCalls = 0;
    hash_delete_string_struct_inst.callback = NULL;
}

void hash_delete_string_MockWithCallback(OPMOCK_hash_delete_string_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    hash_delete_string_struct_inst.callback = callback;
    hash_delete_string_struct_inst.expectedCalls = 0;
    hash_delete_string_struct_inst.actualCalls = 0;
}

void hash_delete_string_VerifyMock()
{
    if (hash_delete_string_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'hash_delete_string'",hash_delete_string_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void hash_delete_string_ExpectAndReturn (Hash * this, const char * key, OPMOCK_MATCHER match_this, OPMOCK_MATCHER match_key)
{
    if(hash_delete_string_struct_inst.callback != NULL)
    {
        hash_delete_string_MockReset ();
    }

    if(hash_delete_string_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting hash_delete_string_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"void hash_delete_string (Hash * this, const char * key)");
    hash_delete_string_struct_inst.calls[hash_delete_string_struct_inst.expectedCalls].this = (void *)this;
    hash_delete_string_struct_inst.calls[hash_delete_string_struct_inst.expectedCalls].key = (void *)key;
    hash_delete_string_struct_inst.calls[hash_delete_string_struct_inst.expectedCalls].match_this = match_this;
    hash_delete_string_struct_inst.calls[hash_delete_string_struct_inst.expectedCalls].match_key = match_key;
    hash_delete_string_struct_inst.calls[hash_delete_string_struct_inst.expectedCalls].check_params = 1;
    hash_delete_string_struct_inst.expectedCalls++;
}

