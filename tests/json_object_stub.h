/* OPMOCK2 GENERATED CODE - DO NOT MODIFY */
#ifndef _JSON_OBJECT_STUB_H
#define _JSON_OBJECT_STUB_H

#include <json_object.h>
#include <json_object_private.h>
#include <linkhash.h>
#include "opmock.h"

#ifdef __cplusplus
extern "C" {
#endif

void json_object_get_ExpectAndReturn(struct json_object * obj, struct json_object * to_return, OPMOCK_MATCHER match_obj);
void json_object_get_MockReset();
typedef struct json_object * (* OPMOCK_json_object_get_CALLBACK)(struct json_object * obj, int calls);
void json_object_get_MockWithCallback(OPMOCK_json_object_get_CALLBACK callback);
void json_object_get_VerifyMock();
void json_object_put_ExpectAndReturn(struct json_object * obj, int to_return, OPMOCK_MATCHER match_obj);
void json_object_put_MockReset();
typedef int (* OPMOCK_json_object_put_CALLBACK)(struct json_object * obj, int calls);
void json_object_put_MockWithCallback(OPMOCK_json_object_put_CALLBACK callback);
void json_object_put_VerifyMock();
void json_object_is_type_ExpectAndReturn(struct json_object * obj, enum json_type type, int to_return, OPMOCK_MATCHER match_obj, OPMOCK_MATCHER match_type);
void json_object_is_type_MockReset();
typedef int (* OPMOCK_json_object_is_type_CALLBACK)(struct json_object * obj, enum json_type type, int calls);
void json_object_is_type_MockWithCallback(OPMOCK_json_object_is_type_CALLBACK callback);
void json_object_is_type_VerifyMock();
void json_object_get_type_ExpectAndReturn(struct json_object * obj, enum json_type to_return, OPMOCK_MATCHER match_obj);
void json_object_get_type_MockReset();
typedef enum json_type (* OPMOCK_json_object_get_type_CALLBACK)(struct json_object * obj, int calls);
void json_object_get_type_MockWithCallback(OPMOCK_json_object_get_type_CALLBACK callback);
void json_object_get_type_VerifyMock();
void json_object_to_json_string_ExpectAndReturn(struct json_object * obj, const char * to_return, OPMOCK_MATCHER match_obj);
void json_object_to_json_string_MockReset();
typedef const char * (* OPMOCK_json_object_to_json_string_CALLBACK)(struct json_object * obj, int calls);
void json_object_to_json_string_MockWithCallback(OPMOCK_json_object_to_json_string_CALLBACK callback);
void json_object_to_json_string_VerifyMock();
void json_object_to_json_string_ext_ExpectAndReturn(struct json_object * obj, int flags, const char * to_return, OPMOCK_MATCHER match_obj, OPMOCK_MATCHER match_flags);
void json_object_to_json_string_ext_MockReset();
typedef const char * (* OPMOCK_json_object_to_json_string_ext_CALLBACK)(struct json_object * obj, int flags, int calls);
void json_object_to_json_string_ext_MockWithCallback(OPMOCK_json_object_to_json_string_ext_CALLBACK callback);
void json_object_to_json_string_ext_VerifyMock();
void json_object_set_serializer_ExpectAndReturn(json_object * jso, json_object_to_json_string_fn to_string_func, void * userdata, json_object_delete_fn * user_delete, OPMOCK_MATCHER match_jso, OPMOCK_MATCHER match_to_string_func, OPMOCK_MATCHER match_userdata, OPMOCK_MATCHER match_user_delete);
void json_object_set_serializer_MockReset();
typedef void (* OPMOCK_json_object_set_serializer_CALLBACK)(json_object * jso, json_object_to_json_string_fn to_string_func, void * userdata, json_object_delete_fn * user_delete, int calls);
void json_object_set_serializer_MockWithCallback(OPMOCK_json_object_set_serializer_CALLBACK callback);
void json_object_set_serializer_VerifyMock();
void json_object_free_userdata_ExpectAndReturn(struct json_object * arg1, void * arg2, OPMOCK_MATCHER match_arg1, OPMOCK_MATCHER match_arg2);
void json_object_free_userdata_MockReset();
typedef void (* OPMOCK_json_object_free_userdata_CALLBACK)(struct json_object * arg1, void * arg2, int calls);
void json_object_free_userdata_MockWithCallback(OPMOCK_json_object_free_userdata_CALLBACK callback);
void json_object_free_userdata_VerifyMock();
void json_object_userdata_to_json_string_ExpectAndReturn(struct json_object * arg1, struct printbuf * arg2, int arg3, int arg4, int to_return, OPMOCK_MATCHER match_arg1, OPMOCK_MATCHER match_arg2, OPMOCK_MATCHER match_arg3, OPMOCK_MATCHER match_arg4);
void json_object_userdata_to_json_string_MockReset();
typedef int (* OPMOCK_json_object_userdata_to_json_string_CALLBACK)(struct json_object * arg1, struct printbuf * arg2, int arg3, int arg4, int calls);
void json_object_userdata_to_json_string_MockWithCallback(OPMOCK_json_object_userdata_to_json_string_CALLBACK callback);
void json_object_userdata_to_json_string_VerifyMock();
void json_object_new_object_ExpectAndReturn(struct json_object * to_return);
void json_object_new_object_MockReset();
typedef struct json_object * (* OPMOCK_json_object_new_object_CALLBACK)(int calls);
void json_object_new_object_MockWithCallback(OPMOCK_json_object_new_object_CALLBACK callback);
void json_object_new_object_VerifyMock();
void json_object_get_object_ExpectAndReturn(struct json_object * obj, struct lh_table * to_return, OPMOCK_MATCHER match_obj);
void json_object_get_object_MockReset();
typedef struct lh_table * (* OPMOCK_json_object_get_object_CALLBACK)(struct json_object * obj, int calls);
void json_object_get_object_MockWithCallback(OPMOCK_json_object_get_object_CALLBACK callback);
void json_object_get_object_VerifyMock();
void json_object_object_length_ExpectAndReturn(struct json_object * obj, int to_return, OPMOCK_MATCHER match_obj);
void json_object_object_length_MockReset();
typedef int (* OPMOCK_json_object_object_length_CALLBACK)(struct json_object * obj, int calls);
void json_object_object_length_MockWithCallback(OPMOCK_json_object_object_length_CALLBACK callback);
void json_object_object_length_VerifyMock();
void json_object_object_add_ExpectAndReturn(struct json_object * obj, const char * key, struct json_object * val, OPMOCK_MATCHER match_obj, OPMOCK_MATCHER match_key, OPMOCK_MATCHER match_val);
void json_object_object_add_MockReset();
typedef void (* OPMOCK_json_object_object_add_CALLBACK)(struct json_object * obj, const char * key, struct json_object * val, int calls);
void json_object_object_add_MockWithCallback(OPMOCK_json_object_object_add_CALLBACK callback);
void json_object_object_add_VerifyMock();
void json_object_object_get_ExpectAndReturn(struct json_object * obj, const char * key, struct json_object * to_return, OPMOCK_MATCHER match_obj, OPMOCK_MATCHER match_key);
void json_object_object_get_MockReset();
typedef struct json_object * (* OPMOCK_json_object_object_get_CALLBACK)(struct json_object * obj, const char * key, int calls);
void json_object_object_get_MockWithCallback(OPMOCK_json_object_object_get_CALLBACK callback);
void json_object_object_get_VerifyMock();
void json_object_object_get_ex_ExpectAndReturn(struct json_object * obj, const char * key, struct json_object ** value, json_bool to_return, OPMOCK_MATCHER match_obj, OPMOCK_MATCHER match_key, OPMOCK_MATCHER match_value);
void json_object_object_get_ex_MockReset();
typedef json_bool (* OPMOCK_json_object_object_get_ex_CALLBACK)(struct json_object * obj, const char * key, struct json_object ** value, int calls);
void json_object_object_get_ex_MockWithCallback(OPMOCK_json_object_object_get_ex_CALLBACK callback);
void json_object_object_get_ex_VerifyMock();
void json_object_object_del_ExpectAndReturn(struct json_object * obj, const char * key, OPMOCK_MATCHER match_obj, OPMOCK_MATCHER match_key);
void json_object_object_del_MockReset();
typedef void (* OPMOCK_json_object_object_del_CALLBACK)(struct json_object * obj, const char * key, int calls);
void json_object_object_del_MockWithCallback(OPMOCK_json_object_object_del_CALLBACK callback);
void json_object_object_del_VerifyMock();
void json_object_new_array_ExpectAndReturn(struct json_object * to_return);
void json_object_new_array_MockReset();
typedef struct json_object * (* OPMOCK_json_object_new_array_CALLBACK)(int calls);
void json_object_new_array_MockWithCallback(OPMOCK_json_object_new_array_CALLBACK callback);
void json_object_new_array_VerifyMock();
void json_object_get_array_ExpectAndReturn(struct json_object * obj, struct array_list * to_return, OPMOCK_MATCHER match_obj);
void json_object_get_array_MockReset();
typedef struct array_list * (* OPMOCK_json_object_get_array_CALLBACK)(struct json_object * obj, int calls);
void json_object_get_array_MockWithCallback(OPMOCK_json_object_get_array_CALLBACK callback);
void json_object_get_array_VerifyMock();
void json_object_array_length_ExpectAndReturn(struct json_object * obj, int to_return, OPMOCK_MATCHER match_obj);
void json_object_array_length_MockReset();
typedef int (* OPMOCK_json_object_array_length_CALLBACK)(struct json_object * obj, int calls);
void json_object_array_length_MockWithCallback(OPMOCK_json_object_array_length_CALLBACK callback);
void json_object_array_length_VerifyMock();
void json_object_array_sort_ExpectAndReturn(struct json_object * jso, int (* sort_fn )(const void *, const void *), OPMOCK_MATCHER match_jso, OPMOCK_MATCHER match_sort_fn);
void json_object_array_sort_MockReset();
typedef void (* OPMOCK_json_object_array_sort_CALLBACK)(struct json_object * jso, int (* sort_fn )(const void *, const void *), int calls);
void json_object_array_sort_MockWithCallback(OPMOCK_json_object_array_sort_CALLBACK callback);
void json_object_array_sort_VerifyMock();
void json_object_array_add_ExpectAndReturn(struct json_object * obj, struct json_object * val, int to_return, OPMOCK_MATCHER match_obj, OPMOCK_MATCHER match_val);
void json_object_array_add_MockReset();
typedef int (* OPMOCK_json_object_array_add_CALLBACK)(struct json_object * obj, struct json_object * val, int calls);
void json_object_array_add_MockWithCallback(OPMOCK_json_object_array_add_CALLBACK callback);
void json_object_array_add_VerifyMock();
void json_object_array_put_idx_ExpectAndReturn(struct json_object * obj, int idx, struct json_object * val, int to_return, OPMOCK_MATCHER match_obj, OPMOCK_MATCHER match_idx, OPMOCK_MATCHER match_val);
void json_object_array_put_idx_MockReset();
typedef int (* OPMOCK_json_object_array_put_idx_CALLBACK)(struct json_object * obj, int idx, struct json_object * val, int calls);
void json_object_array_put_idx_MockWithCallback(OPMOCK_json_object_array_put_idx_CALLBACK callback);
void json_object_array_put_idx_VerifyMock();
void json_object_array_get_idx_ExpectAndReturn(struct json_object * obj, int idx, struct json_object * to_return, OPMOCK_MATCHER match_obj, OPMOCK_MATCHER match_idx);
void json_object_array_get_idx_MockReset();
typedef struct json_object * (* OPMOCK_json_object_array_get_idx_CALLBACK)(struct json_object * obj, int idx, int calls);
void json_object_array_get_idx_MockWithCallback(OPMOCK_json_object_array_get_idx_CALLBACK callback);
void json_object_array_get_idx_VerifyMock();
void json_object_new_boolean_ExpectAndReturn(json_bool b, struct json_object * to_return, OPMOCK_MATCHER match_b);
void json_object_new_boolean_MockReset();
typedef struct json_object * (* OPMOCK_json_object_new_boolean_CALLBACK)(json_bool b, int calls);
void json_object_new_boolean_MockWithCallback(OPMOCK_json_object_new_boolean_CALLBACK callback);
void json_object_new_boolean_VerifyMock();
void json_object_get_boolean_ExpectAndReturn(struct json_object * obj, json_bool to_return, OPMOCK_MATCHER match_obj);
void json_object_get_boolean_MockReset();
typedef json_bool (* OPMOCK_json_object_get_boolean_CALLBACK)(struct json_object * obj, int calls);
void json_object_get_boolean_MockWithCallback(OPMOCK_json_object_get_boolean_CALLBACK callback);
void json_object_get_boolean_VerifyMock();
void json_object_new_int_ExpectAndReturn(int32_t i, struct json_object * to_return, OPMOCK_MATCHER match_i);
void json_object_new_int_MockReset();
typedef struct json_object * (* OPMOCK_json_object_new_int_CALLBACK)(int32_t i, int calls);
void json_object_new_int_MockWithCallback(OPMOCK_json_object_new_int_CALLBACK callback);
void json_object_new_int_VerifyMock();
void json_object_new_int64_ExpectAndReturn(int64_t i, struct json_object * to_return, OPMOCK_MATCHER match_i);
void json_object_new_int64_MockReset();
typedef struct json_object * (* OPMOCK_json_object_new_int64_CALLBACK)(int64_t i, int calls);
void json_object_new_int64_MockWithCallback(OPMOCK_json_object_new_int64_CALLBACK callback);
void json_object_new_int64_VerifyMock();
void json_object_get_int_ExpectAndReturn(struct json_object * obj, int32_t to_return, OPMOCK_MATCHER match_obj);
void json_object_get_int_MockReset();
typedef int32_t (* OPMOCK_json_object_get_int_CALLBACK)(struct json_object * obj, int calls);
void json_object_get_int_MockWithCallback(OPMOCK_json_object_get_int_CALLBACK callback);
void json_object_get_int_VerifyMock();
void json_object_get_int64_ExpectAndReturn(struct json_object * obj, int64_t to_return, OPMOCK_MATCHER match_obj);
void json_object_get_int64_MockReset();
typedef int64_t (* OPMOCK_json_object_get_int64_CALLBACK)(struct json_object * obj, int calls);
void json_object_get_int64_MockWithCallback(OPMOCK_json_object_get_int64_CALLBACK callback);
void json_object_get_int64_VerifyMock();
void json_object_new_double_ExpectAndReturn(double d, struct json_object * to_return, OPMOCK_MATCHER match_d);
void json_object_new_double_MockReset();
typedef struct json_object * (* OPMOCK_json_object_new_double_CALLBACK)(double d, int calls);
void json_object_new_double_MockWithCallback(OPMOCK_json_object_new_double_CALLBACK callback);
void json_object_new_double_VerifyMock();
void json_object_new_double_s_ExpectAndReturn(double d, const char * ds, struct json_object * to_return, OPMOCK_MATCHER match_d, OPMOCK_MATCHER match_ds);
void json_object_new_double_s_MockReset();
typedef struct json_object * (* OPMOCK_json_object_new_double_s_CALLBACK)(double d, const char * ds, int calls);
void json_object_new_double_s_MockWithCallback(OPMOCK_json_object_new_double_s_CALLBACK callback);
void json_object_new_double_s_VerifyMock();
void json_object_get_double_ExpectAndReturn(struct json_object * obj, double to_return, OPMOCK_MATCHER match_obj);
void json_object_get_double_MockReset();
typedef double (* OPMOCK_json_object_get_double_CALLBACK)(struct json_object * obj, int calls);
void json_object_get_double_MockWithCallback(OPMOCK_json_object_get_double_CALLBACK callback);
void json_object_get_double_VerifyMock();
void json_object_new_string_ExpectAndReturn(const char * s, struct json_object * to_return, OPMOCK_MATCHER match_s);
void json_object_new_string_MockReset();
typedef struct json_object * (* OPMOCK_json_object_new_string_CALLBACK)(const char * s, int calls);
void json_object_new_string_MockWithCallback(OPMOCK_json_object_new_string_CALLBACK callback);
void json_object_new_string_VerifyMock();
void json_object_new_string_len_ExpectAndReturn(const char * s, int len, struct json_object * to_return, OPMOCK_MATCHER match_s, OPMOCK_MATCHER match_len);
void json_object_new_string_len_MockReset();
typedef struct json_object * (* OPMOCK_json_object_new_string_len_CALLBACK)(const char * s, int len, int calls);
void json_object_new_string_len_MockWithCallback(OPMOCK_json_object_new_string_len_CALLBACK callback);
void json_object_new_string_len_VerifyMock();
void json_object_get_string_ExpectAndReturn(struct json_object * obj, const char * to_return, OPMOCK_MATCHER match_obj);
void json_object_get_string_MockReset();
typedef const char * (* OPMOCK_json_object_get_string_CALLBACK)(struct json_object * obj, int calls);
void json_object_get_string_MockWithCallback(OPMOCK_json_object_get_string_CALLBACK callback);
void json_object_get_string_VerifyMock();
void json_object_get_string_len_ExpectAndReturn(struct json_object * obj, int to_return, OPMOCK_MATCHER match_obj);
void json_object_get_string_len_MockReset();
typedef int (* OPMOCK_json_object_get_string_len_CALLBACK)(struct json_object * obj, int calls);
void json_object_get_string_len_MockWithCallback(OPMOCK_json_object_get_string_len_CALLBACK callback);
void json_object_get_string_len_VerifyMock();

#ifdef __cplusplus
}
#endif
#endif
