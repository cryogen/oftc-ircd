/* OPMOCK2 GENERATED CODE - DO NOT MODIFY */
#ifndef _MEMORY_STUB_H
#define _MEMORY_STUB_H

#include <memory.h>
#include "opmock.h"

#ifdef __cplusplus
extern "C" {
#endif

void Malloc_ExpectAndReturn(size_t length, void * to_return, OPMOCK_MATCHER match_length);
void Malloc_MockReset();
typedef void * (* OPMOCK_Malloc_CALLBACK)(size_t length, int calls);
void Malloc_MockWithCallback(OPMOCK_Malloc_CALLBACK callback);
void Malloc_VerifyMock();
void Realloc_ExpectAndReturn(void * ptr, size_t length, void * to_return, OPMOCK_MATCHER match_ptr, OPMOCK_MATCHER match_length);
void Realloc_MockReset();
typedef void * (* OPMOCK_Realloc_CALLBACK)(void * ptr, size_t length, int calls);
void Realloc_MockWithCallback(OPMOCK_Realloc_CALLBACK callback);
void Realloc_VerifyMock();
void StrDup_ExpectAndReturn(const char * ptr, char * to_return, OPMOCK_MATCHER match_ptr);
void StrDup_MockReset();
typedef char * (* OPMOCK_StrDup_CALLBACK)(const char * ptr, int calls);
void StrDup_MockWithCallback(OPMOCK_StrDup_CALLBACK callback);
void StrDup_VerifyMock();
void Free_ExpectAndReturn(void * ptr, OPMOCK_MATCHER match_ptr);
void Free_MockReset();
typedef void (* OPMOCK_Free_CALLBACK)(void * ptr, int calls);
void Free_MockWithCallback(OPMOCK_Free_CALLBACK callback);
void Free_VerifyMock();

#ifdef __cplusplus
}
#endif
#endif
