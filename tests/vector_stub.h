/* OPMOCK2 GENERATED CODE - DO NOT MODIFY */
#ifndef _VECTOR_STUB_H
#define _VECTOR_STUB_H

#include <vector.h>
#include "opmock.h"

#ifdef __cplusplus
extern "C" {
#endif

void vector_new_ExpectAndReturn(size_t capacity, size_t elementSize, Vector * to_return, OPMOCK_MATCHER match_capacity, OPMOCK_MATCHER match_elementSize);
void vector_new_MockReset();
typedef Vector * (* OPMOCK_vector_new_CALLBACK)(size_t capacity, size_t elementSize, int calls);
void vector_new_MockWithCallback(OPMOCK_vector_new_CALLBACK callback);
void vector_new_VerifyMock();
void vector_push_back_ExpectAndReturn(Vector * this, void * data, void * to_return, OPMOCK_MATCHER match_this, OPMOCK_MATCHER match_data);
void vector_push_back_MockReset();
typedef void * (* OPMOCK_vector_push_back_CALLBACK)(Vector * this, void * data, int calls);
void vector_push_back_MockWithCallback(OPMOCK_vector_push_back_CALLBACK callback);
void vector_push_back_VerifyMock();
void vector_get_ExpectAndReturn(Vector * this, size_t index, void * to_return, OPMOCK_MATCHER match_this, OPMOCK_MATCHER match_index);
void vector_get_MockReset();
typedef void * (* OPMOCK_vector_get_CALLBACK)(Vector * this, size_t index, int calls);
void vector_get_MockWithCallback(OPMOCK_vector_get_CALLBACK callback);
void vector_get_VerifyMock();
void vector_length_ExpectAndReturn(Vector * this, size_t to_return, OPMOCK_MATCHER match_this);
void vector_length_MockReset();
typedef size_t (* OPMOCK_vector_length_CALLBACK)(Vector * this, int calls);
void vector_length_MockWithCallback(OPMOCK_vector_length_CALLBACK callback);
void vector_length_VerifyMock();

#ifdef __cplusplus
}
#endif
#endif
