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
void vector_push_back_ExpectAndReturn(Vector * thisVector, void * data, void * to_return, OPMOCK_MATCHER match_thisVector, OPMOCK_MATCHER match_data);
void vector_push_back_MockReset();
typedef void * (* OPMOCK_vector_push_back_CALLBACK)(Vector * thisVector, void * data, int calls);
void vector_push_back_MockWithCallback(OPMOCK_vector_push_back_CALLBACK callback);
void vector_push_back_VerifyMock();
void vector_get_ExpectAndReturn(Vector * thisVector, size_t index, void * to_return, OPMOCK_MATCHER match_thisVector, OPMOCK_MATCHER match_index);
void vector_get_MockReset();
typedef void * (* OPMOCK_vector_get_CALLBACK)(Vector * thisVector, size_t index, int calls);
void vector_get_MockWithCallback(OPMOCK_vector_get_CALLBACK callback);
void vector_get_VerifyMock();
void vector_delete_ExpectAndReturn(Vector * thisVector, size_t index, OPMOCK_MATCHER match_thisVector, OPMOCK_MATCHER match_index);
void vector_delete_MockReset();
typedef void (* OPMOCK_vector_delete_CALLBACK)(Vector * thisVector, size_t index, int calls);
void vector_delete_MockWithCallback(OPMOCK_vector_delete_CALLBACK callback);
void vector_delete_VerifyMock();
void vector_length_ExpectAndReturn(Vector * thisVector, size_t to_return, OPMOCK_MATCHER match_thisVector);
void vector_length_MockReset();
typedef size_t (* OPMOCK_vector_length_CALLBACK)(Vector * thisVector, int calls);
void vector_length_MockWithCallback(OPMOCK_vector_length_CALLBACK callback);
void vector_length_VerifyMock();
void vector_free_ExpectAndReturn(Vector * thisVector, OPMOCK_MATCHER match_thisVector);
void vector_free_MockReset();
typedef void (* OPMOCK_vector_free_CALLBACK)(Vector * thisVector, int calls);
void vector_free_MockWithCallback(OPMOCK_vector_free_CALLBACK callback);
void vector_free_VerifyMock();

#ifdef __cplusplus
}
#endif
#endif
