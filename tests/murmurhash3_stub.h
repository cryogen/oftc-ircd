/* OPMOCK2 GENERATED CODE - DO NOT MODIFY */
#ifndef _MURMURHASH3_STUB_H
#define _MURMURHASH3_STUB_H

#include <murmurhash3.h>
#include "opmock.h"

#ifdef __cplusplus
extern "C" {
#endif

void MurmurHash3_x86_32_ExpectAndReturn(const void * key, int len, uint32_t seed, void * out, OPMOCK_MATCHER match_key, OPMOCK_MATCHER match_len, OPMOCK_MATCHER match_seed, OPMOCK_MATCHER match_out);
void MurmurHash3_x86_32_MockReset();
typedef void (* OPMOCK_MurmurHash3_x86_32_CALLBACK)(const void * key, int len, uint32_t seed, void * out, int calls);
void MurmurHash3_x86_32_MockWithCallback(OPMOCK_MurmurHash3_x86_32_CALLBACK callback);
void MurmurHash3_x86_32_VerifyMock();
void MurmurHash3_x86_128_ExpectAndReturn(const void * key, int len, uint32_t seed, void * out, OPMOCK_MATCHER match_key, OPMOCK_MATCHER match_len, OPMOCK_MATCHER match_seed, OPMOCK_MATCHER match_out);
void MurmurHash3_x86_128_MockReset();
typedef void (* OPMOCK_MurmurHash3_x86_128_CALLBACK)(const void * key, int len, uint32_t seed, void * out, int calls);
void MurmurHash3_x86_128_MockWithCallback(OPMOCK_MurmurHash3_x86_128_CALLBACK callback);
void MurmurHash3_x86_128_VerifyMock();
void MurmurHash3_x64_128_ExpectAndReturn(const void * key, int len, uint32_t seed, void * out, OPMOCK_MATCHER match_key, OPMOCK_MATCHER match_len, OPMOCK_MATCHER match_seed, OPMOCK_MATCHER match_out);
void MurmurHash3_x64_128_MockReset();
typedef void (* OPMOCK_MurmurHash3_x64_128_CALLBACK)(const void * key, int len, uint32_t seed, void * out, int calls);
void MurmurHash3_x64_128_MockWithCallback(OPMOCK_MurmurHash3_x64_128_CALLBACK callback);
void MurmurHash3_x64_128_VerifyMock();

#ifdef __cplusplus
}
#endif
#endif
