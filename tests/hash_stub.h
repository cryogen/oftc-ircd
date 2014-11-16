/* OPMOCK2 GENERATED CODE - DO NOT MODIFY */
#ifndef _HASH_STUB_H
#define _HASH_STUB_H

#include <hash.h>
#include "opmock.h"

#ifdef __cplusplus
extern "C" {
#endif

void hash_init_ExpectAndReturn();
void hash_init_MockReset();
typedef void (* OPMOCK_hash_init_CALLBACK)(int calls);
void hash_init_MockWithCallback(OPMOCK_hash_init_CALLBACK callback);
void hash_init_VerifyMock();
void hash_new_ExpectAndReturn(const char * name, size_t length, Hash * to_return, OPMOCK_MATCHER match_name, OPMOCK_MATCHER match_length);
void hash_new_MockReset();
typedef Hash * (* OPMOCK_hash_new_CALLBACK)(const char * name, size_t length, int calls);
void hash_new_MockWithCallback(OPMOCK_hash_new_CALLBACK callback);
void hash_new_VerifyMock();
void hash_add_string_ExpectAndReturn(Hash * this, const char * key, void * value, OPMOCK_MATCHER match_this, OPMOCK_MATCHER match_key, OPMOCK_MATCHER match_value);
void hash_add_string_MockReset();
typedef void (* OPMOCK_hash_add_string_CALLBACK)(Hash * this, const char * key, void * value, int calls);
void hash_add_string_MockWithCallback(OPMOCK_hash_add_string_CALLBACK callback);
void hash_add_string_VerifyMock();
void hash_find_ExpectAndReturn(Hash * this, const char * key, void * to_return, OPMOCK_MATCHER match_this, OPMOCK_MATCHER match_key);
void hash_find_MockReset();
typedef void * (* OPMOCK_hash_find_CALLBACK)(Hash * this, const char * key, int calls);
void hash_find_MockWithCallback(OPMOCK_hash_find_CALLBACK callback);
void hash_find_VerifyMock();

#ifdef __cplusplus
}
#endif
#endif
