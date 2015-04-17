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
void buffer_add_ExpectAndReturn(Buffer * buffer, char * data, size_t len, OPMOCK_MATCHER match_buffer, OPMOCK_MATCHER match_data, OPMOCK_MATCHER match_len);
void buffer_add_MockReset();
typedef void (* OPMOCK_buffer_add_CALLBACK)(Buffer * buffer, char * data, size_t len, int calls);
void buffer_add_MockWithCallback(OPMOCK_buffer_add_CALLBACK callback);
void buffer_add_VerifyMock();
void buffer_remove_ExpectAndReturn(Buffer * buffer, size_t len, OPMOCK_MATCHER match_buffer, OPMOCK_MATCHER match_len);
void buffer_remove_MockReset();
typedef void (* OPMOCK_buffer_remove_CALLBACK)(Buffer * buffer, size_t len, int calls);
void buffer_remove_MockWithCallback(OPMOCK_buffer_remove_CALLBACK callback);
void buffer_remove_VerifyMock();
void buffer_get_start_ExpectAndReturn(Buffer * buffer, ListEntry * to_return, OPMOCK_MATCHER match_buffer);
void buffer_get_start_MockReset();
typedef ListEntry * (* OPMOCK_buffer_get_start_CALLBACK)(Buffer * buffer, int calls);
void buffer_get_start_MockWithCallback(OPMOCK_buffer_get_start_CALLBACK callback);
void buffer_get_start_VerifyMock();

#ifdef __cplusplus
}
#endif
#endif
