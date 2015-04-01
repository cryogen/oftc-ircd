/* OPMOCK2 GENERATED CODE - DO NOT MODIFY */
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-prototypes"

#include "murmurhash3_stub.h"
#include <stdio.h>
#include <string.h>

typedef struct
{
    void * key;
    int len;
    unsigned int seed;
    void * out;
    OPMOCK_MATCHER match_key;
    OPMOCK_MATCHER match_len;
    OPMOCK_MATCHER match_seed;
    OPMOCK_MATCHER match_out;
    char check_params;
} MurmurHash3_x86_32_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_MurmurHash3_x86_32_CALLBACK callback;
    MurmurHash3_x86_32_call calls[MAX_FUNC_CALL];
} MurmurHash3_x86_32_struct;

static MurmurHash3_x86_32_struct MurmurHash3_x86_32_struct_inst;

typedef struct
{
    void * key;
    int len;
    unsigned int seed;
    void * out;
    OPMOCK_MATCHER match_key;
    OPMOCK_MATCHER match_len;
    OPMOCK_MATCHER match_seed;
    OPMOCK_MATCHER match_out;
    char check_params;
} MurmurHash3_x86_128_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_MurmurHash3_x86_128_CALLBACK callback;
    MurmurHash3_x86_128_call calls[MAX_FUNC_CALL];
} MurmurHash3_x86_128_struct;

static MurmurHash3_x86_128_struct MurmurHash3_x86_128_struct_inst;

typedef struct
{
    void * key;
    int len;
    unsigned int seed;
    void * out;
    OPMOCK_MATCHER match_key;
    OPMOCK_MATCHER match_len;
    OPMOCK_MATCHER match_seed;
    OPMOCK_MATCHER match_out;
    char check_params;
} MurmurHash3_x64_128_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_MurmurHash3_x64_128_CALLBACK callback;
    MurmurHash3_x64_128_call calls[MAX_FUNC_CALL];
} MurmurHash3_x64_128_struct;

static MurmurHash3_x64_128_struct MurmurHash3_x64_128_struct_inst;

static void opmock_reset_all_mocks_in_this_header()
{
    MurmurHash3_x86_32_MockReset();
    MurmurHash3_x86_128_MockReset();
    MurmurHash3_x64_128_MockReset();
}

static void opmock_verify_all_mocks_in_this_header()
{
    MurmurHash3_x86_32_VerifyMock();
    MurmurHash3_x86_128_VerifyMock();
    MurmurHash3_x64_128_VerifyMock();
}

void MurmurHash3_x86_32(const void * key, int len, uint32_t seed, void * out)
{
    int opmock_i;
    MurmurHash3_x86_32_struct_inst.actualCalls++;

    if (MurmurHash3_x86_32_struct_inst.callback != NULL)
    {
        MurmurHash3_x86_32_struct_inst.callback (key, len, seed, out, MurmurHash3_x86_32_struct_inst.actualCalls);
        return;
    }
    if (MurmurHash3_x86_32_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'MurmurHash3_x86_32', returning random value.");
        return;
    }

    if(strcmp(opmock_get_current_call(), "void MurmurHash3_x86_32 (const void * key, int len, uint32_t seed, void * out)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'void MurmurHash3_x86_32(const void * key, int len, uint32_t seed, void * out)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (MurmurHash3_x86_32_struct_inst.calls[0].check_params == 1) {
        if(MurmurHash3_x86_32_struct_inst.calls[0].match_key) {
            void * val1 = (void *) &MurmurHash3_x86_32_struct_inst.calls[0].key;
            void * val2 = (void *) &key;
            int match_result = MurmurHash3_x86_32_struct_inst.calls[0].match_key(val1, val2, "key", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'MurmurHash3_x86_32', %s",MurmurHash3_x86_32_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
        if(MurmurHash3_x86_32_struct_inst.calls[0].match_len) {
            void * val1 = (void *) &MurmurHash3_x86_32_struct_inst.calls[0].len;
            void * val2 = (void *) &len;
            int match_result = MurmurHash3_x86_32_struct_inst.calls[0].match_len(val1, val2, "len", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'MurmurHash3_x86_32', %s",MurmurHash3_x86_32_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
        if(MurmurHash3_x86_32_struct_inst.calls[0].match_seed) {
            void * val1 = (void *) &MurmurHash3_x86_32_struct_inst.calls[0].seed;
            void * val2 = (void *) &seed;
            int match_result = MurmurHash3_x86_32_struct_inst.calls[0].match_seed(val1, val2, "seed", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'MurmurHash3_x86_32', %s",MurmurHash3_x86_32_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
        if(MurmurHash3_x86_32_struct_inst.calls[0].match_out) {
            void * val1 = (void *) &MurmurHash3_x86_32_struct_inst.calls[0].out;
            void * val2 = (void *) &out;
            int match_result = MurmurHash3_x86_32_struct_inst.calls[0].match_out(val1, val2, "out", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'MurmurHash3_x86_32', %s",MurmurHash3_x86_32_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < MurmurHash3_x86_32_struct_inst.expectedCalls; opmock_i++) {
        MurmurHash3_x86_32_struct_inst.calls[opmock_i - 1] = MurmurHash3_x86_32_struct_inst.calls[opmock_i];
    }

    MurmurHash3_x86_32_struct_inst.expectedCalls--;
}

void MurmurHash3_x86_32_MockReset()
{
    MurmurHash3_x86_32_struct_inst.expectedCalls = 0;
    MurmurHash3_x86_32_struct_inst.actualCalls = 0;
    MurmurHash3_x86_32_struct_inst.callback = NULL;
}

void MurmurHash3_x86_32_MockWithCallback(OPMOCK_MurmurHash3_x86_32_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    MurmurHash3_x86_32_struct_inst.callback = callback;
    MurmurHash3_x86_32_struct_inst.expectedCalls = 0;
    MurmurHash3_x86_32_struct_inst.actualCalls = 0;
}

void MurmurHash3_x86_32_VerifyMock()
{
    if (MurmurHash3_x86_32_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'MurmurHash3_x86_32'",MurmurHash3_x86_32_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void MurmurHash3_x86_32_ExpectAndReturn (const void * key, int len, uint32_t seed, void * out, OPMOCK_MATCHER match_key, OPMOCK_MATCHER match_len, OPMOCK_MATCHER match_seed, OPMOCK_MATCHER match_out)
{
    if(MurmurHash3_x86_32_struct_inst.callback != NULL)
    {
        MurmurHash3_x86_32_MockReset ();
    }

    if(MurmurHash3_x86_32_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting MurmurHash3_x86_32_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"void MurmurHash3_x86_32 (const void * key, int len, uint32_t seed, void * out)");
    MurmurHash3_x86_32_struct_inst.calls[MurmurHash3_x86_32_struct_inst.expectedCalls].key = (void *)key;
    MurmurHash3_x86_32_struct_inst.calls[MurmurHash3_x86_32_struct_inst.expectedCalls].len = (int)len;
    MurmurHash3_x86_32_struct_inst.calls[MurmurHash3_x86_32_struct_inst.expectedCalls].seed = (unsigned int)seed;
    MurmurHash3_x86_32_struct_inst.calls[MurmurHash3_x86_32_struct_inst.expectedCalls].out = (void *)out;
    MurmurHash3_x86_32_struct_inst.calls[MurmurHash3_x86_32_struct_inst.expectedCalls].match_key = match_key;
    MurmurHash3_x86_32_struct_inst.calls[MurmurHash3_x86_32_struct_inst.expectedCalls].match_len = match_len;
    MurmurHash3_x86_32_struct_inst.calls[MurmurHash3_x86_32_struct_inst.expectedCalls].match_seed = match_seed;
    MurmurHash3_x86_32_struct_inst.calls[MurmurHash3_x86_32_struct_inst.expectedCalls].match_out = match_out;
    MurmurHash3_x86_32_struct_inst.calls[MurmurHash3_x86_32_struct_inst.expectedCalls].check_params = 1;
    MurmurHash3_x86_32_struct_inst.expectedCalls++;
}

void MurmurHash3_x86_128(const void * key, int len, uint32_t seed, void * out)
{
    int opmock_i;
    MurmurHash3_x86_128_struct_inst.actualCalls++;

    if (MurmurHash3_x86_128_struct_inst.callback != NULL)
    {
        MurmurHash3_x86_128_struct_inst.callback (key, len, seed, out, MurmurHash3_x86_128_struct_inst.actualCalls);
        return;
    }
    if (MurmurHash3_x86_128_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'MurmurHash3_x86_128', returning random value.");
        return;
    }

    if(strcmp(opmock_get_current_call(), "void MurmurHash3_x86_128 (const void * key, int len, uint32_t seed, void * out)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'void MurmurHash3_x86_128(const void * key, int len, uint32_t seed, void * out)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (MurmurHash3_x86_128_struct_inst.calls[0].check_params == 1) {
        if(MurmurHash3_x86_128_struct_inst.calls[0].match_key) {
            void * val1 = (void *) &MurmurHash3_x86_128_struct_inst.calls[0].key;
            void * val2 = (void *) &key;
            int match_result = MurmurHash3_x86_128_struct_inst.calls[0].match_key(val1, val2, "key", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'MurmurHash3_x86_128', %s",MurmurHash3_x86_128_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
        if(MurmurHash3_x86_128_struct_inst.calls[0].match_len) {
            void * val1 = (void *) &MurmurHash3_x86_128_struct_inst.calls[0].len;
            void * val2 = (void *) &len;
            int match_result = MurmurHash3_x86_128_struct_inst.calls[0].match_len(val1, val2, "len", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'MurmurHash3_x86_128', %s",MurmurHash3_x86_128_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
        if(MurmurHash3_x86_128_struct_inst.calls[0].match_seed) {
            void * val1 = (void *) &MurmurHash3_x86_128_struct_inst.calls[0].seed;
            void * val2 = (void *) &seed;
            int match_result = MurmurHash3_x86_128_struct_inst.calls[0].match_seed(val1, val2, "seed", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'MurmurHash3_x86_128', %s",MurmurHash3_x86_128_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
        if(MurmurHash3_x86_128_struct_inst.calls[0].match_out) {
            void * val1 = (void *) &MurmurHash3_x86_128_struct_inst.calls[0].out;
            void * val2 = (void *) &out;
            int match_result = MurmurHash3_x86_128_struct_inst.calls[0].match_out(val1, val2, "out", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'MurmurHash3_x86_128', %s",MurmurHash3_x86_128_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < MurmurHash3_x86_128_struct_inst.expectedCalls; opmock_i++) {
        MurmurHash3_x86_128_struct_inst.calls[opmock_i - 1] = MurmurHash3_x86_128_struct_inst.calls[opmock_i];
    }

    MurmurHash3_x86_128_struct_inst.expectedCalls--;
}

void MurmurHash3_x86_128_MockReset()
{
    MurmurHash3_x86_128_struct_inst.expectedCalls = 0;
    MurmurHash3_x86_128_struct_inst.actualCalls = 0;
    MurmurHash3_x86_128_struct_inst.callback = NULL;
}

void MurmurHash3_x86_128_MockWithCallback(OPMOCK_MurmurHash3_x86_128_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    MurmurHash3_x86_128_struct_inst.callback = callback;
    MurmurHash3_x86_128_struct_inst.expectedCalls = 0;
    MurmurHash3_x86_128_struct_inst.actualCalls = 0;
}

void MurmurHash3_x86_128_VerifyMock()
{
    if (MurmurHash3_x86_128_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'MurmurHash3_x86_128'",MurmurHash3_x86_128_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void MurmurHash3_x86_128_ExpectAndReturn (const void * key, int len, uint32_t seed, void * out, OPMOCK_MATCHER match_key, OPMOCK_MATCHER match_len, OPMOCK_MATCHER match_seed, OPMOCK_MATCHER match_out)
{
    if(MurmurHash3_x86_128_struct_inst.callback != NULL)
    {
        MurmurHash3_x86_128_MockReset ();
    }

    if(MurmurHash3_x86_128_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting MurmurHash3_x86_128_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"void MurmurHash3_x86_128 (const void * key, int len, uint32_t seed, void * out)");
    MurmurHash3_x86_128_struct_inst.calls[MurmurHash3_x86_128_struct_inst.expectedCalls].key = (void *)key;
    MurmurHash3_x86_128_struct_inst.calls[MurmurHash3_x86_128_struct_inst.expectedCalls].len = (int)len;
    MurmurHash3_x86_128_struct_inst.calls[MurmurHash3_x86_128_struct_inst.expectedCalls].seed = (unsigned int)seed;
    MurmurHash3_x86_128_struct_inst.calls[MurmurHash3_x86_128_struct_inst.expectedCalls].out = (void *)out;
    MurmurHash3_x86_128_struct_inst.calls[MurmurHash3_x86_128_struct_inst.expectedCalls].match_key = match_key;
    MurmurHash3_x86_128_struct_inst.calls[MurmurHash3_x86_128_struct_inst.expectedCalls].match_len = match_len;
    MurmurHash3_x86_128_struct_inst.calls[MurmurHash3_x86_128_struct_inst.expectedCalls].match_seed = match_seed;
    MurmurHash3_x86_128_struct_inst.calls[MurmurHash3_x86_128_struct_inst.expectedCalls].match_out = match_out;
    MurmurHash3_x86_128_struct_inst.calls[MurmurHash3_x86_128_struct_inst.expectedCalls].check_params = 1;
    MurmurHash3_x86_128_struct_inst.expectedCalls++;
}

void MurmurHash3_x64_128(const void * key, int len, uint32_t seed, void * out)
{
    int opmock_i;
    MurmurHash3_x64_128_struct_inst.actualCalls++;

    if (MurmurHash3_x64_128_struct_inst.callback != NULL)
    {
        MurmurHash3_x64_128_struct_inst.callback (key, len, seed, out, MurmurHash3_x64_128_struct_inst.actualCalls);
        return;
    }
    if (MurmurHash3_x64_128_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'MurmurHash3_x64_128', returning random value.");
        return;
    }

    if(strcmp(opmock_get_current_call(), "void MurmurHash3_x64_128 (const void * key, int len, uint32_t seed, void * out)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'void MurmurHash3_x64_128(const void * key, int len, uint32_t seed, void * out)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (MurmurHash3_x64_128_struct_inst.calls[0].check_params == 1) {
        if(MurmurHash3_x64_128_struct_inst.calls[0].match_key) {
            void * val1 = (void *) &MurmurHash3_x64_128_struct_inst.calls[0].key;
            void * val2 = (void *) &key;
            int match_result = MurmurHash3_x64_128_struct_inst.calls[0].match_key(val1, val2, "key", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'MurmurHash3_x64_128', %s",MurmurHash3_x64_128_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
        if(MurmurHash3_x64_128_struct_inst.calls[0].match_len) {
            void * val1 = (void *) &MurmurHash3_x64_128_struct_inst.calls[0].len;
            void * val2 = (void *) &len;
            int match_result = MurmurHash3_x64_128_struct_inst.calls[0].match_len(val1, val2, "len", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'MurmurHash3_x64_128', %s",MurmurHash3_x64_128_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
        if(MurmurHash3_x64_128_struct_inst.calls[0].match_seed) {
            void * val1 = (void *) &MurmurHash3_x64_128_struct_inst.calls[0].seed;
            void * val2 = (void *) &seed;
            int match_result = MurmurHash3_x64_128_struct_inst.calls[0].match_seed(val1, val2, "seed", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'MurmurHash3_x64_128', %s",MurmurHash3_x64_128_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
        if(MurmurHash3_x64_128_struct_inst.calls[0].match_out) {
            void * val1 = (void *) &MurmurHash3_x64_128_struct_inst.calls[0].out;
            void * val2 = (void *) &out;
            int match_result = MurmurHash3_x64_128_struct_inst.calls[0].match_out(val1, val2, "out", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'MurmurHash3_x64_128', %s",MurmurHash3_x64_128_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < MurmurHash3_x64_128_struct_inst.expectedCalls; opmock_i++) {
        MurmurHash3_x64_128_struct_inst.calls[opmock_i - 1] = MurmurHash3_x64_128_struct_inst.calls[opmock_i];
    }

    MurmurHash3_x64_128_struct_inst.expectedCalls--;
}

void MurmurHash3_x64_128_MockReset()
{
    MurmurHash3_x64_128_struct_inst.expectedCalls = 0;
    MurmurHash3_x64_128_struct_inst.actualCalls = 0;
    MurmurHash3_x64_128_struct_inst.callback = NULL;
}

void MurmurHash3_x64_128_MockWithCallback(OPMOCK_MurmurHash3_x64_128_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    MurmurHash3_x64_128_struct_inst.callback = callback;
    MurmurHash3_x64_128_struct_inst.expectedCalls = 0;
    MurmurHash3_x64_128_struct_inst.actualCalls = 0;
}

void MurmurHash3_x64_128_VerifyMock()
{
    if (MurmurHash3_x64_128_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'MurmurHash3_x64_128'",MurmurHash3_x64_128_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void MurmurHash3_x64_128_ExpectAndReturn (const void * key, int len, uint32_t seed, void * out, OPMOCK_MATCHER match_key, OPMOCK_MATCHER match_len, OPMOCK_MATCHER match_seed, OPMOCK_MATCHER match_out)
{
    if(MurmurHash3_x64_128_struct_inst.callback != NULL)
    {
        MurmurHash3_x64_128_MockReset ();
    }

    if(MurmurHash3_x64_128_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting MurmurHash3_x64_128_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"void MurmurHash3_x64_128 (const void * key, int len, uint32_t seed, void * out)");
    MurmurHash3_x64_128_struct_inst.calls[MurmurHash3_x64_128_struct_inst.expectedCalls].key = (void *)key;
    MurmurHash3_x64_128_struct_inst.calls[MurmurHash3_x64_128_struct_inst.expectedCalls].len = (int)len;
    MurmurHash3_x64_128_struct_inst.calls[MurmurHash3_x64_128_struct_inst.expectedCalls].seed = (unsigned int)seed;
    MurmurHash3_x64_128_struct_inst.calls[MurmurHash3_x64_128_struct_inst.expectedCalls].out = (void *)out;
    MurmurHash3_x64_128_struct_inst.calls[MurmurHash3_x64_128_struct_inst.expectedCalls].match_key = match_key;
    MurmurHash3_x64_128_struct_inst.calls[MurmurHash3_x64_128_struct_inst.expectedCalls].match_len = match_len;
    MurmurHash3_x64_128_struct_inst.calls[MurmurHash3_x64_128_struct_inst.expectedCalls].match_seed = match_seed;
    MurmurHash3_x64_128_struct_inst.calls[MurmurHash3_x64_128_struct_inst.expectedCalls].match_out = match_out;
    MurmurHash3_x64_128_struct_inst.calls[MurmurHash3_x64_128_struct_inst.expectedCalls].check_params = 1;
    MurmurHash3_x64_128_struct_inst.expectedCalls++;
}

#pragma GCC diagnostic pop

