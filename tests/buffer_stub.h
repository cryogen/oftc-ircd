/* OPMOCK2 GENERATED CODE - DO NOT MODIFY */
#ifndef _BUFFER_STUB_H
#define _BUFFER_STUB_H

#include <buffer.h>
#include "opmock.h"

#ifdef __cplusplus
extern "C" {
#endif

void buffer_new_ExpectAndReturn(Buffer * to_return);
void buffer_new_MockReset();
typedef Buffer * (* OPMOCK_buffer_new_CALLBACK)(int calls);
void buffer_new_MockWithCallback(OPMOCK_buffer_new_CALLBACK callback);
void buffer_new_VerifyMock();
void buffer_push_back_ExpectAndReturn(Buffer * buffer, char * data, size_t len, OPMOCK_MATCHER match_buffer, OPMOCK_MATCHER match_data, OPMOCK_MATCHER match_len);
void buffer_push_back_MockReset();
typedef void (* OPMOCK_buffer_push_back_CALLBACK)(Buffer * buffer, char * data, size_t len, int calls);
void buffer_push_back_MockWithCallback(OPMOCK_buffer_push_back_CALLBACK callback);
void buffer_push_back_VerifyMock();
void buffer_pop_front_ExpectAndReturn(Buffer * buffer, size_t len, const char * to_return, OPMOCK_MATCHER match_buffer, OPMOCK_MATCHER match_len);
void buffer_pop_front_MockReset();
typedef const char * (* OPMOCK_buffer_pop_front_CALLBACK)(Buffer * buffer, size_t len, int calls);
void buffer_pop_front_MockWithCallback(OPMOCK_buffer_pop_front_CALLBACK callback);
void buffer_pop_front_VerifyMock();

#ifdef __cplusplus
}
#endif
#endif
