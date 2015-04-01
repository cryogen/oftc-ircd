/* OPMOCK2 GENERATED CODE - DO NOT MODIFY */
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-prototypes"

#include "json_object_stub.h"
#include <stdio.h>
#include <string.h>

typedef struct
{
    void * obj;
    OPMOCK_MATCHER match_obj;
    struct json_object * to_return;
    char check_params;
} json_object_get_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_json_object_get_CALLBACK callback;
    json_object_get_call calls[MAX_FUNC_CALL];
} json_object_get_struct;

static json_object_get_struct json_object_get_struct_inst;

typedef struct
{
    void * obj;
    OPMOCK_MATCHER match_obj;
    int to_return;
    char check_params;
} json_object_put_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_json_object_put_CALLBACK callback;
    json_object_put_call calls[MAX_FUNC_CALL];
} json_object_put_struct;

static json_object_put_struct json_object_put_struct_inst;

typedef struct
{
    void * obj;
    enum json_type type;
    OPMOCK_MATCHER match_obj;
    OPMOCK_MATCHER match_type;
    int to_return;
    char check_params;
} json_object_is_type_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_json_object_is_type_CALLBACK callback;
    json_object_is_type_call calls[MAX_FUNC_CALL];
} json_object_is_type_struct;

static json_object_is_type_struct json_object_is_type_struct_inst;

typedef struct
{
    void * obj;
    OPMOCK_MATCHER match_obj;
    enum json_type to_return;
    char check_params;
} json_object_get_type_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_json_object_get_type_CALLBACK callback;
    json_object_get_type_call calls[MAX_FUNC_CALL];
} json_object_get_type_struct;

static json_object_get_type_struct json_object_get_type_struct_inst;

typedef struct
{
    void * obj;
    OPMOCK_MATCHER match_obj;
     char * to_return;
    char check_params;
} json_object_to_json_string_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_json_object_to_json_string_CALLBACK callback;
    json_object_to_json_string_call calls[MAX_FUNC_CALL];
} json_object_to_json_string_struct;

static json_object_to_json_string_struct json_object_to_json_string_struct_inst;

typedef struct
{
    void * obj;
    int flags;
    OPMOCK_MATCHER match_obj;
    OPMOCK_MATCHER match_flags;
     char * to_return;
    char check_params;
} json_object_to_json_string_ext_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_json_object_to_json_string_ext_CALLBACK callback;
    json_object_to_json_string_ext_call calls[MAX_FUNC_CALL];
} json_object_to_json_string_ext_struct;

static json_object_to_json_string_ext_struct json_object_to_json_string_ext_struct_inst;


typedef int (*json_to_string_func)(struct json_object *, struct printbuf *, int, int);

typedef struct
{
    void * jso;
    json_to_string_func to_string_func;
    void * userdata;
    void * user_delete;
    OPMOCK_MATCHER match_jso;
    OPMOCK_MATCHER match_to_string_func;
    OPMOCK_MATCHER match_userdata;
    OPMOCK_MATCHER match_user_delete;
    char check_params;
} json_object_set_serializer_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_json_object_set_serializer_CALLBACK callback;
    json_object_set_serializer_call calls[MAX_FUNC_CALL];
} json_object_set_serializer_struct;

static json_object_set_serializer_struct json_object_set_serializer_struct_inst;

typedef struct
{
    void * arg1;
    void * arg2;
    OPMOCK_MATCHER match_arg1;
    OPMOCK_MATCHER match_arg2;
    char check_params;
} json_object_free_userdata_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_json_object_free_userdata_CALLBACK callback;
    json_object_free_userdata_call calls[MAX_FUNC_CALL];
} json_object_free_userdata_struct;

static json_object_free_userdata_struct json_object_free_userdata_struct_inst;

typedef struct
{
    void * arg1;
    void * arg2;
    int arg3;
    int arg4;
    OPMOCK_MATCHER match_arg1;
    OPMOCK_MATCHER match_arg2;
    OPMOCK_MATCHER match_arg3;
    OPMOCK_MATCHER match_arg4;
    int to_return;
    char check_params;
} json_object_userdata_to_json_string_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_json_object_userdata_to_json_string_CALLBACK callback;
    json_object_userdata_to_json_string_call calls[MAX_FUNC_CALL];
} json_object_userdata_to_json_string_struct;

static json_object_userdata_to_json_string_struct json_object_userdata_to_json_string_struct_inst;

typedef struct
{
    struct json_object * to_return;
    char check_params;
} json_object_new_object_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_json_object_new_object_CALLBACK callback;
    json_object_new_object_call calls[MAX_FUNC_CALL];
} json_object_new_object_struct;

static json_object_new_object_struct json_object_new_object_struct_inst;

typedef struct
{
    void * obj;
    OPMOCK_MATCHER match_obj;
    struct lh_table * to_return;
    char check_params;
} json_object_get_object_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_json_object_get_object_CALLBACK callback;
    json_object_get_object_call calls[MAX_FUNC_CALL];
} json_object_get_object_struct;

static json_object_get_object_struct json_object_get_object_struct_inst;

typedef struct
{
    void * obj;
    OPMOCK_MATCHER match_obj;
    int to_return;
    char check_params;
} json_object_object_length_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_json_object_object_length_CALLBACK callback;
    json_object_object_length_call calls[MAX_FUNC_CALL];
} json_object_object_length_struct;

static json_object_object_length_struct json_object_object_length_struct_inst;

typedef struct
{
    void * obj;
    void * key;
    void * val;
    OPMOCK_MATCHER match_obj;
    OPMOCK_MATCHER match_key;
    OPMOCK_MATCHER match_val;
    char check_params;
} json_object_object_add_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_json_object_object_add_CALLBACK callback;
    json_object_object_add_call calls[MAX_FUNC_CALL];
} json_object_object_add_struct;

static json_object_object_add_struct json_object_object_add_struct_inst;

typedef struct
{
    void * obj;
    void * key;
    OPMOCK_MATCHER match_obj;
    OPMOCK_MATCHER match_key;
    struct json_object * to_return;
    char check_params;
} json_object_object_get_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_json_object_object_get_CALLBACK callback;
    json_object_object_get_call calls[MAX_FUNC_CALL];
} json_object_object_get_struct;

static json_object_object_get_struct json_object_object_get_struct_inst;

typedef struct
{
    void * obj;
    void * key;
    void * value;
    OPMOCK_MATCHER match_obj;
    OPMOCK_MATCHER match_key;
    OPMOCK_MATCHER match_value;
    int to_return;
    char check_params;
} json_object_object_get_ex_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_json_object_object_get_ex_CALLBACK callback;
    json_object_object_get_ex_call calls[MAX_FUNC_CALL];
} json_object_object_get_ex_struct;

static json_object_object_get_ex_struct json_object_object_get_ex_struct_inst;

typedef struct
{
    void * obj;
    void * key;
    OPMOCK_MATCHER match_obj;
    OPMOCK_MATCHER match_key;
    char check_params;
} json_object_object_del_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_json_object_object_del_CALLBACK callback;
    json_object_object_del_call calls[MAX_FUNC_CALL];
} json_object_object_del_struct;

static json_object_object_del_struct json_object_object_del_struct_inst;

typedef struct
{
    struct json_object * to_return;
    char check_params;
} json_object_new_array_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_json_object_new_array_CALLBACK callback;
    json_object_new_array_call calls[MAX_FUNC_CALL];
} json_object_new_array_struct;

static json_object_new_array_struct json_object_new_array_struct_inst;

typedef struct
{
    void * obj;
    OPMOCK_MATCHER match_obj;
    struct array_list * to_return;
    char check_params;
} json_object_get_array_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_json_object_get_array_CALLBACK callback;
    json_object_get_array_call calls[MAX_FUNC_CALL];
} json_object_get_array_struct;

static json_object_get_array_struct json_object_get_array_struct_inst;

typedef struct
{
    void * obj;
    OPMOCK_MATCHER match_obj;
    int to_return;
    char check_params;
} json_object_array_length_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_json_object_array_length_CALLBACK callback;
    json_object_array_length_call calls[MAX_FUNC_CALL];
} json_object_array_length_struct;

static json_object_array_length_struct json_object_array_length_struct_inst;

typedef struct
{
    void * jso;
    void * sort_fn;
    OPMOCK_MATCHER match_jso;
    OPMOCK_MATCHER match_sort_fn;
    char check_params;
} json_object_array_sort_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_json_object_array_sort_CALLBACK callback;
    json_object_array_sort_call calls[MAX_FUNC_CALL];
} json_object_array_sort_struct;

static json_object_array_sort_struct json_object_array_sort_struct_inst;

typedef struct
{
    void * obj;
    void * val;
    OPMOCK_MATCHER match_obj;
    OPMOCK_MATCHER match_val;
    int to_return;
    char check_params;
} json_object_array_add_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_json_object_array_add_CALLBACK callback;
    json_object_array_add_call calls[MAX_FUNC_CALL];
} json_object_array_add_struct;

static json_object_array_add_struct json_object_array_add_struct_inst;

typedef struct
{
    void * obj;
    int idx;
    void * val;
    OPMOCK_MATCHER match_obj;
    OPMOCK_MATCHER match_idx;
    OPMOCK_MATCHER match_val;
    int to_return;
    char check_params;
} json_object_array_put_idx_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_json_object_array_put_idx_CALLBACK callback;
    json_object_array_put_idx_call calls[MAX_FUNC_CALL];
} json_object_array_put_idx_struct;

static json_object_array_put_idx_struct json_object_array_put_idx_struct_inst;

typedef struct
{
    void * obj;
    int idx;
    OPMOCK_MATCHER match_obj;
    OPMOCK_MATCHER match_idx;
    struct json_object * to_return;
    char check_params;
} json_object_array_get_idx_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_json_object_array_get_idx_CALLBACK callback;
    json_object_array_get_idx_call calls[MAX_FUNC_CALL];
} json_object_array_get_idx_struct;

static json_object_array_get_idx_struct json_object_array_get_idx_struct_inst;

typedef struct
{
    int b;
    OPMOCK_MATCHER match_b;
    struct json_object * to_return;
    char check_params;
} json_object_new_boolean_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_json_object_new_boolean_CALLBACK callback;
    json_object_new_boolean_call calls[MAX_FUNC_CALL];
} json_object_new_boolean_struct;

static json_object_new_boolean_struct json_object_new_boolean_struct_inst;

typedef struct
{
    void * obj;
    OPMOCK_MATCHER match_obj;
    int to_return;
    char check_params;
} json_object_get_boolean_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_json_object_get_boolean_CALLBACK callback;
    json_object_get_boolean_call calls[MAX_FUNC_CALL];
} json_object_get_boolean_struct;

static json_object_get_boolean_struct json_object_get_boolean_struct_inst;

typedef struct
{
    int i;
    OPMOCK_MATCHER match_i;
    struct json_object * to_return;
    char check_params;
} json_object_new_int_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_json_object_new_int_CALLBACK callback;
    json_object_new_int_call calls[MAX_FUNC_CALL];
} json_object_new_int_struct;

static json_object_new_int_struct json_object_new_int_struct_inst;

typedef struct
{
    long long i;
    OPMOCK_MATCHER match_i;
    struct json_object * to_return;
    char check_params;
} json_object_new_int64_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_json_object_new_int64_CALLBACK callback;
    json_object_new_int64_call calls[MAX_FUNC_CALL];
} json_object_new_int64_struct;

static json_object_new_int64_struct json_object_new_int64_struct_inst;

typedef struct
{
    void * obj;
    OPMOCK_MATCHER match_obj;
    int to_return;
    char check_params;
} json_object_get_int_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_json_object_get_int_CALLBACK callback;
    json_object_get_int_call calls[MAX_FUNC_CALL];
} json_object_get_int_struct;

static json_object_get_int_struct json_object_get_int_struct_inst;

typedef struct
{
    void * obj;
    OPMOCK_MATCHER match_obj;
    long long to_return;
    char check_params;
} json_object_get_int64_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_json_object_get_int64_CALLBACK callback;
    json_object_get_int64_call calls[MAX_FUNC_CALL];
} json_object_get_int64_struct;

static json_object_get_int64_struct json_object_get_int64_struct_inst;

typedef struct
{
    double d;
    OPMOCK_MATCHER match_d;
    struct json_object * to_return;
    char check_params;
} json_object_new_double_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_json_object_new_double_CALLBACK callback;
    json_object_new_double_call calls[MAX_FUNC_CALL];
} json_object_new_double_struct;

static json_object_new_double_struct json_object_new_double_struct_inst;

typedef struct
{
    double d;
    void * ds;
    OPMOCK_MATCHER match_d;
    OPMOCK_MATCHER match_ds;
    struct json_object * to_return;
    char check_params;
} json_object_new_double_s_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_json_object_new_double_s_CALLBACK callback;
    json_object_new_double_s_call calls[MAX_FUNC_CALL];
} json_object_new_double_s_struct;

static json_object_new_double_s_struct json_object_new_double_s_struct_inst;

typedef struct
{
    void * obj;
    OPMOCK_MATCHER match_obj;
    double to_return;
    char check_params;
} json_object_get_double_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_json_object_get_double_CALLBACK callback;
    json_object_get_double_call calls[MAX_FUNC_CALL];
} json_object_get_double_struct;

static json_object_get_double_struct json_object_get_double_struct_inst;

typedef struct
{
    void * s;
    OPMOCK_MATCHER match_s;
    struct json_object * to_return;
    char check_params;
} json_object_new_string_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_json_object_new_string_CALLBACK callback;
    json_object_new_string_call calls[MAX_FUNC_CALL];
} json_object_new_string_struct;

static json_object_new_string_struct json_object_new_string_struct_inst;

typedef struct
{
    void * s;
    int len;
    OPMOCK_MATCHER match_s;
    OPMOCK_MATCHER match_len;
    struct json_object * to_return;
    char check_params;
} json_object_new_string_len_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_json_object_new_string_len_CALLBACK callback;
    json_object_new_string_len_call calls[MAX_FUNC_CALL];
} json_object_new_string_len_struct;

static json_object_new_string_len_struct json_object_new_string_len_struct_inst;

typedef struct
{
    void * obj;
    OPMOCK_MATCHER match_obj;
     char * to_return;
    char check_params;
} json_object_get_string_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_json_object_get_string_CALLBACK callback;
    json_object_get_string_call calls[MAX_FUNC_CALL];
} json_object_get_string_struct;

static json_object_get_string_struct json_object_get_string_struct_inst;

typedef struct
{
    void * obj;
    OPMOCK_MATCHER match_obj;
    int to_return;
    char check_params;
} json_object_get_string_len_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_json_object_get_string_len_CALLBACK callback;
    json_object_get_string_len_call calls[MAX_FUNC_CALL];
} json_object_get_string_len_struct;

static json_object_get_string_len_struct json_object_get_string_len_struct_inst;

static void opmock_reset_all_mocks_in_this_header()
{
    json_object_get_MockReset();
    json_object_put_MockReset();
    json_object_is_type_MockReset();
    json_object_get_type_MockReset();
    json_object_to_json_string_MockReset();
    json_object_to_json_string_ext_MockReset();
    json_object_set_serializer_MockReset();
    json_object_free_userdata_MockReset();
    json_object_userdata_to_json_string_MockReset();
    json_object_new_object_MockReset();
    json_object_get_object_MockReset();
    json_object_object_length_MockReset();
    json_object_object_add_MockReset();
    json_object_object_get_MockReset();
    json_object_object_get_ex_MockReset();
    json_object_object_del_MockReset();
    json_object_new_array_MockReset();
    json_object_get_array_MockReset();
    json_object_array_length_MockReset();
    json_object_array_sort_MockReset();
    json_object_array_add_MockReset();
    json_object_array_put_idx_MockReset();
    json_object_array_get_idx_MockReset();
    json_object_new_boolean_MockReset();
    json_object_get_boolean_MockReset();
    json_object_new_int_MockReset();
    json_object_new_int64_MockReset();
    json_object_get_int_MockReset();
    json_object_get_int64_MockReset();
    json_object_new_double_MockReset();
    json_object_new_double_s_MockReset();
    json_object_get_double_MockReset();
    json_object_new_string_MockReset();
    json_object_new_string_len_MockReset();
    json_object_get_string_MockReset();
    json_object_get_string_len_MockReset();
}

static void opmock_verify_all_mocks_in_this_header()
{
    json_object_get_VerifyMock();
    json_object_put_VerifyMock();
    json_object_is_type_VerifyMock();
    json_object_get_type_VerifyMock();
    json_object_to_json_string_VerifyMock();
    json_object_to_json_string_ext_VerifyMock();
    json_object_set_serializer_VerifyMock();
    json_object_free_userdata_VerifyMock();
    json_object_userdata_to_json_string_VerifyMock();
    json_object_new_object_VerifyMock();
    json_object_get_object_VerifyMock();
    json_object_object_length_VerifyMock();
    json_object_object_add_VerifyMock();
    json_object_object_get_VerifyMock();
    json_object_object_get_ex_VerifyMock();
    json_object_object_del_VerifyMock();
    json_object_new_array_VerifyMock();
    json_object_get_array_VerifyMock();
    json_object_array_length_VerifyMock();
    json_object_array_sort_VerifyMock();
    json_object_array_add_VerifyMock();
    json_object_array_put_idx_VerifyMock();
    json_object_array_get_idx_VerifyMock();
    json_object_new_boolean_VerifyMock();
    json_object_get_boolean_VerifyMock();
    json_object_new_int_VerifyMock();
    json_object_new_int64_VerifyMock();
    json_object_get_int_VerifyMock();
    json_object_get_int64_VerifyMock();
    json_object_new_double_VerifyMock();
    json_object_new_double_s_VerifyMock();
    json_object_get_double_VerifyMock();
    json_object_new_string_VerifyMock();
    json_object_new_string_len_VerifyMock();
    json_object_get_string_VerifyMock();
    json_object_get_string_len_VerifyMock();
}

struct json_object * json_object_get(struct json_object * obj)
{
    struct json_object * default_res = (struct json_object *)json_object_get_struct_inst.calls[0].to_return;
    int opmock_i;
    json_object_get_struct_inst.actualCalls++;

    if (json_object_get_struct_inst.callback != NULL)
    {
        return json_object_get_struct_inst.callback (obj, json_object_get_struct_inst.actualCalls);
    }
    if (json_object_get_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'json_object_get', returning random value.");
        return default_res;
    }

    if(strcmp(opmock_get_current_call(), "struct json_object * json_object_get (struct json_object * obj)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'struct json_object * json_object_get(struct json_object * obj)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (json_object_get_struct_inst.calls[0].check_params == 1) {
        if(json_object_get_struct_inst.calls[0].match_obj) {
            void * val1 = (void *) &json_object_get_struct_inst.calls[0].obj;
            void * val2 = (void *) &obj;
            int match_result = json_object_get_struct_inst.calls[0].match_obj(val1, val2, "obj", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'json_object_get', %s",json_object_get_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < json_object_get_struct_inst.expectedCalls; opmock_i++) {
        json_object_get_struct_inst.calls[opmock_i - 1] = json_object_get_struct_inst.calls[opmock_i];
    }

    json_object_get_struct_inst.expectedCalls--;
    return default_res;
}

void json_object_get_MockReset()
{
    json_object_get_struct_inst.expectedCalls = 0;
    json_object_get_struct_inst.actualCalls = 0;
    json_object_get_struct_inst.callback = NULL;
}

void json_object_get_MockWithCallback(OPMOCK_json_object_get_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    json_object_get_struct_inst.callback = callback;
    json_object_get_struct_inst.expectedCalls = 0;
    json_object_get_struct_inst.actualCalls = 0;
}

void json_object_get_VerifyMock()
{
    if (json_object_get_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'json_object_get'",json_object_get_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void json_object_get_ExpectAndReturn (struct json_object * obj, struct json_object * to_return, OPMOCK_MATCHER match_obj)
{
    if(json_object_get_struct_inst.callback != NULL)
    {
        json_object_get_MockReset ();
    }

    if(json_object_get_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting json_object_get_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"struct json_object * json_object_get (struct json_object * obj)");
    json_object_get_struct_inst.calls[json_object_get_struct_inst.expectedCalls].obj = (void *)obj;
    json_object_get_struct_inst.calls[json_object_get_struct_inst.expectedCalls].match_obj = match_obj;
    json_object_get_struct_inst.calls[json_object_get_struct_inst.expectedCalls].to_return = (struct json_object *) to_return;
    json_object_get_struct_inst.calls[json_object_get_struct_inst.expectedCalls].check_params = 1;
    json_object_get_struct_inst.expectedCalls++;
}

int json_object_put(struct json_object * obj)
{
    int default_res = (int)json_object_put_struct_inst.calls[0].to_return;
    int opmock_i;
    json_object_put_struct_inst.actualCalls++;

    if (json_object_put_struct_inst.callback != NULL)
    {
        return json_object_put_struct_inst.callback (obj, json_object_put_struct_inst.actualCalls);
    }
    if (json_object_put_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'json_object_put', returning random value.");
        return default_res;
    }

    if(strcmp(opmock_get_current_call(), "int json_object_put (struct json_object * obj)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'int json_object_put(struct json_object * obj)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (json_object_put_struct_inst.calls[0].check_params == 1) {
        if(json_object_put_struct_inst.calls[0].match_obj) {
            void * val1 = (void *) &json_object_put_struct_inst.calls[0].obj;
            void * val2 = (void *) &obj;
            int match_result = json_object_put_struct_inst.calls[0].match_obj(val1, val2, "obj", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'json_object_put', %s",json_object_put_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < json_object_put_struct_inst.expectedCalls; opmock_i++) {
        json_object_put_struct_inst.calls[opmock_i - 1] = json_object_put_struct_inst.calls[opmock_i];
    }

    json_object_put_struct_inst.expectedCalls--;
    return default_res;
}

void json_object_put_MockReset()
{
    json_object_put_struct_inst.expectedCalls = 0;
    json_object_put_struct_inst.actualCalls = 0;
    json_object_put_struct_inst.callback = NULL;
}

void json_object_put_MockWithCallback(OPMOCK_json_object_put_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    json_object_put_struct_inst.callback = callback;
    json_object_put_struct_inst.expectedCalls = 0;
    json_object_put_struct_inst.actualCalls = 0;
}

void json_object_put_VerifyMock()
{
    if (json_object_put_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'json_object_put'",json_object_put_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void json_object_put_ExpectAndReturn (struct json_object * obj, int to_return, OPMOCK_MATCHER match_obj)
{
    if(json_object_put_struct_inst.callback != NULL)
    {
        json_object_put_MockReset ();
    }

    if(json_object_put_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting json_object_put_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"int json_object_put (struct json_object * obj)");
    json_object_put_struct_inst.calls[json_object_put_struct_inst.expectedCalls].obj = (void *)obj;
    json_object_put_struct_inst.calls[json_object_put_struct_inst.expectedCalls].match_obj = match_obj;
    json_object_put_struct_inst.calls[json_object_put_struct_inst.expectedCalls].to_return = (int) to_return;
    json_object_put_struct_inst.calls[json_object_put_struct_inst.expectedCalls].check_params = 1;
    json_object_put_struct_inst.expectedCalls++;
}

int json_object_is_type(struct json_object * obj, enum json_type type)
{
    int default_res = (int)json_object_is_type_struct_inst.calls[0].to_return;
    int opmock_i;
    json_object_is_type_struct_inst.actualCalls++;

    if (json_object_is_type_struct_inst.callback != NULL)
    {
        return json_object_is_type_struct_inst.callback (obj, type, json_object_is_type_struct_inst.actualCalls);
    }
    if (json_object_is_type_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'json_object_is_type', returning random value.");
        return default_res;
    }

    if(strcmp(opmock_get_current_call(), "int json_object_is_type (struct json_object * obj, enum json_type type)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'int json_object_is_type(struct json_object * obj, enum json_type type)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (json_object_is_type_struct_inst.calls[0].check_params == 1) {
        if(json_object_is_type_struct_inst.calls[0].match_obj) {
            void * val1 = (void *) &json_object_is_type_struct_inst.calls[0].obj;
            void * val2 = (void *) &obj;
            int match_result = json_object_is_type_struct_inst.calls[0].match_obj(val1, val2, "obj", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'json_object_is_type', %s",json_object_is_type_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
        if(json_object_is_type_struct_inst.calls[0].match_type) {
            void * val1 = (void *) &json_object_is_type_struct_inst.calls[0].type;
            void * val2 = (void *) &type;
            int match_result = json_object_is_type_struct_inst.calls[0].match_type(val1, val2, "type", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'json_object_is_type', %s",json_object_is_type_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < json_object_is_type_struct_inst.expectedCalls; opmock_i++) {
        json_object_is_type_struct_inst.calls[opmock_i - 1] = json_object_is_type_struct_inst.calls[opmock_i];
    }

    json_object_is_type_struct_inst.expectedCalls--;
    return default_res;
}

void json_object_is_type_MockReset()
{
    json_object_is_type_struct_inst.expectedCalls = 0;
    json_object_is_type_struct_inst.actualCalls = 0;
    json_object_is_type_struct_inst.callback = NULL;
}

void json_object_is_type_MockWithCallback(OPMOCK_json_object_is_type_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    json_object_is_type_struct_inst.callback = callback;
    json_object_is_type_struct_inst.expectedCalls = 0;
    json_object_is_type_struct_inst.actualCalls = 0;
}

void json_object_is_type_VerifyMock()
{
    if (json_object_is_type_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'json_object_is_type'",json_object_is_type_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void json_object_is_type_ExpectAndReturn (struct json_object * obj, enum json_type type, int to_return, OPMOCK_MATCHER match_obj, OPMOCK_MATCHER match_type)
{
    if(json_object_is_type_struct_inst.callback != NULL)
    {
        json_object_is_type_MockReset ();
    }

    if(json_object_is_type_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting json_object_is_type_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"int json_object_is_type (struct json_object * obj, enum json_type type)");
    json_object_is_type_struct_inst.calls[json_object_is_type_struct_inst.expectedCalls].obj = (void *)obj;
    json_object_is_type_struct_inst.calls[json_object_is_type_struct_inst.expectedCalls].type = (enum json_type)type;
    json_object_is_type_struct_inst.calls[json_object_is_type_struct_inst.expectedCalls].match_obj = match_obj;
    json_object_is_type_struct_inst.calls[json_object_is_type_struct_inst.expectedCalls].match_type = match_type;
    json_object_is_type_struct_inst.calls[json_object_is_type_struct_inst.expectedCalls].to_return = (int) to_return;
    json_object_is_type_struct_inst.calls[json_object_is_type_struct_inst.expectedCalls].check_params = 1;
    json_object_is_type_struct_inst.expectedCalls++;
}

enum json_type json_object_get_type(struct json_object * obj)
{
    enum json_type default_res = (enum json_type)json_object_get_type_struct_inst.calls[0].to_return;
    int opmock_i;
    json_object_get_type_struct_inst.actualCalls++;

    if (json_object_get_type_struct_inst.callback != NULL)
    {
        return json_object_get_type_struct_inst.callback (obj, json_object_get_type_struct_inst.actualCalls);
    }
    if (json_object_get_type_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'json_object_get_type', returning random value.");
        return default_res;
    }

    if(strcmp(opmock_get_current_call(), "enum json_type json_object_get_type (struct json_object * obj)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'enum json_type json_object_get_type(struct json_object * obj)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (json_object_get_type_struct_inst.calls[0].check_params == 1) {
        if(json_object_get_type_struct_inst.calls[0].match_obj) {
            void * val1 = (void *) &json_object_get_type_struct_inst.calls[0].obj;
            void * val2 = (void *) &obj;
            int match_result = json_object_get_type_struct_inst.calls[0].match_obj(val1, val2, "obj", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'json_object_get_type', %s",json_object_get_type_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < json_object_get_type_struct_inst.expectedCalls; opmock_i++) {
        json_object_get_type_struct_inst.calls[opmock_i - 1] = json_object_get_type_struct_inst.calls[opmock_i];
    }

    json_object_get_type_struct_inst.expectedCalls--;
    return default_res;
}

void json_object_get_type_MockReset()
{
    json_object_get_type_struct_inst.expectedCalls = 0;
    json_object_get_type_struct_inst.actualCalls = 0;
    json_object_get_type_struct_inst.callback = NULL;
}

void json_object_get_type_MockWithCallback(OPMOCK_json_object_get_type_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    json_object_get_type_struct_inst.callback = callback;
    json_object_get_type_struct_inst.expectedCalls = 0;
    json_object_get_type_struct_inst.actualCalls = 0;
}

void json_object_get_type_VerifyMock()
{
    if (json_object_get_type_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'json_object_get_type'",json_object_get_type_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void json_object_get_type_ExpectAndReturn (struct json_object * obj, enum json_type to_return, OPMOCK_MATCHER match_obj)
{
    if(json_object_get_type_struct_inst.callback != NULL)
    {
        json_object_get_type_MockReset ();
    }

    if(json_object_get_type_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting json_object_get_type_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"enum json_type json_object_get_type (struct json_object * obj)");
    json_object_get_type_struct_inst.calls[json_object_get_type_struct_inst.expectedCalls].obj = (void *)obj;
    json_object_get_type_struct_inst.calls[json_object_get_type_struct_inst.expectedCalls].match_obj = match_obj;
    json_object_get_type_struct_inst.calls[json_object_get_type_struct_inst.expectedCalls].to_return = (enum json_type) to_return;
    json_object_get_type_struct_inst.calls[json_object_get_type_struct_inst.expectedCalls].check_params = 1;
    json_object_get_type_struct_inst.expectedCalls++;
}

const char * json_object_to_json_string(struct json_object * obj)
{
    const char * default_res = (const char *)json_object_to_json_string_struct_inst.calls[0].to_return;
    int opmock_i;
    json_object_to_json_string_struct_inst.actualCalls++;

    if (json_object_to_json_string_struct_inst.callback != NULL)
    {
        return json_object_to_json_string_struct_inst.callback (obj, json_object_to_json_string_struct_inst.actualCalls);
    }
    if (json_object_to_json_string_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'json_object_to_json_string', returning random value.");
        return default_res;
    }

    if(strcmp(opmock_get_current_call(), "const char * json_object_to_json_string (struct json_object * obj)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'const char * json_object_to_json_string(struct json_object * obj)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (json_object_to_json_string_struct_inst.calls[0].check_params == 1) {
        if(json_object_to_json_string_struct_inst.calls[0].match_obj) {
            void * val1 = (void *) &json_object_to_json_string_struct_inst.calls[0].obj;
            void * val2 = (void *) &obj;
            int match_result = json_object_to_json_string_struct_inst.calls[0].match_obj(val1, val2, "obj", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'json_object_to_json_string', %s",json_object_to_json_string_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < json_object_to_json_string_struct_inst.expectedCalls; opmock_i++) {
        json_object_to_json_string_struct_inst.calls[opmock_i - 1] = json_object_to_json_string_struct_inst.calls[opmock_i];
    }

    json_object_to_json_string_struct_inst.expectedCalls--;
    return default_res;
}

void json_object_to_json_string_MockReset()
{
    json_object_to_json_string_struct_inst.expectedCalls = 0;
    json_object_to_json_string_struct_inst.actualCalls = 0;
    json_object_to_json_string_struct_inst.callback = NULL;
}

void json_object_to_json_string_MockWithCallback(OPMOCK_json_object_to_json_string_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    json_object_to_json_string_struct_inst.callback = callback;
    json_object_to_json_string_struct_inst.expectedCalls = 0;
    json_object_to_json_string_struct_inst.actualCalls = 0;
}

void json_object_to_json_string_VerifyMock()
{
    if (json_object_to_json_string_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'json_object_to_json_string'",json_object_to_json_string_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void json_object_to_json_string_ExpectAndReturn (struct json_object * obj, const char * to_return, OPMOCK_MATCHER match_obj)
{
    if(json_object_to_json_string_struct_inst.callback != NULL)
    {
        json_object_to_json_string_MockReset ();
    }

    if(json_object_to_json_string_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting json_object_to_json_string_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"const char * json_object_to_json_string (struct json_object * obj)");
    json_object_to_json_string_struct_inst.calls[json_object_to_json_string_struct_inst.expectedCalls].obj = (void *)obj;
    json_object_to_json_string_struct_inst.calls[json_object_to_json_string_struct_inst.expectedCalls].match_obj = match_obj;
    json_object_to_json_string_struct_inst.calls[json_object_to_json_string_struct_inst.expectedCalls].to_return = ( char *) to_return;
    json_object_to_json_string_struct_inst.calls[json_object_to_json_string_struct_inst.expectedCalls].check_params = 1;
    json_object_to_json_string_struct_inst.expectedCalls++;
}

const char * json_object_to_json_string_ext(struct json_object * obj, int flags)
{
    const char * default_res = (const char *)json_object_to_json_string_ext_struct_inst.calls[0].to_return;
    int opmock_i;
    json_object_to_json_string_ext_struct_inst.actualCalls++;

    if (json_object_to_json_string_ext_struct_inst.callback != NULL)
    {
        return json_object_to_json_string_ext_struct_inst.callback (obj, flags, json_object_to_json_string_ext_struct_inst.actualCalls);
    }
    if (json_object_to_json_string_ext_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'json_object_to_json_string_ext', returning random value.");
        return default_res;
    }

    if(strcmp(opmock_get_current_call(), "const char * json_object_to_json_string_ext (struct json_object * obj, int flags)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'const char * json_object_to_json_string_ext(struct json_object * obj, int flags)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (json_object_to_json_string_ext_struct_inst.calls[0].check_params == 1) {
        if(json_object_to_json_string_ext_struct_inst.calls[0].match_obj) {
            void * val1 = (void *) &json_object_to_json_string_ext_struct_inst.calls[0].obj;
            void * val2 = (void *) &obj;
            int match_result = json_object_to_json_string_ext_struct_inst.calls[0].match_obj(val1, val2, "obj", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'json_object_to_json_string_ext', %s",json_object_to_json_string_ext_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
        if(json_object_to_json_string_ext_struct_inst.calls[0].match_flags) {
            void * val1 = (void *) &json_object_to_json_string_ext_struct_inst.calls[0].flags;
            void * val2 = (void *) &flags;
            int match_result = json_object_to_json_string_ext_struct_inst.calls[0].match_flags(val1, val2, "flags", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'json_object_to_json_string_ext', %s",json_object_to_json_string_ext_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < json_object_to_json_string_ext_struct_inst.expectedCalls; opmock_i++) {
        json_object_to_json_string_ext_struct_inst.calls[opmock_i - 1] = json_object_to_json_string_ext_struct_inst.calls[opmock_i];
    }

    json_object_to_json_string_ext_struct_inst.expectedCalls--;
    return default_res;
}

void json_object_to_json_string_ext_MockReset()
{
    json_object_to_json_string_ext_struct_inst.expectedCalls = 0;
    json_object_to_json_string_ext_struct_inst.actualCalls = 0;
    json_object_to_json_string_ext_struct_inst.callback = NULL;
}

void json_object_to_json_string_ext_MockWithCallback(OPMOCK_json_object_to_json_string_ext_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    json_object_to_json_string_ext_struct_inst.callback = callback;
    json_object_to_json_string_ext_struct_inst.expectedCalls = 0;
    json_object_to_json_string_ext_struct_inst.actualCalls = 0;
}

void json_object_to_json_string_ext_VerifyMock()
{
    if (json_object_to_json_string_ext_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'json_object_to_json_string_ext'",json_object_to_json_string_ext_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void json_object_to_json_string_ext_ExpectAndReturn (struct json_object * obj, int flags, const char * to_return, OPMOCK_MATCHER match_obj, OPMOCK_MATCHER match_flags)
{
    if(json_object_to_json_string_ext_struct_inst.callback != NULL)
    {
        json_object_to_json_string_ext_MockReset ();
    }

    if(json_object_to_json_string_ext_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting json_object_to_json_string_ext_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"const char * json_object_to_json_string_ext (struct json_object * obj, int flags)");
    json_object_to_json_string_ext_struct_inst.calls[json_object_to_json_string_ext_struct_inst.expectedCalls].obj = (void *)obj;
    json_object_to_json_string_ext_struct_inst.calls[json_object_to_json_string_ext_struct_inst.expectedCalls].flags = (int)flags;
    json_object_to_json_string_ext_struct_inst.calls[json_object_to_json_string_ext_struct_inst.expectedCalls].match_obj = match_obj;
    json_object_to_json_string_ext_struct_inst.calls[json_object_to_json_string_ext_struct_inst.expectedCalls].match_flags = match_flags;
    json_object_to_json_string_ext_struct_inst.calls[json_object_to_json_string_ext_struct_inst.expectedCalls].to_return = ( char *) to_return;
    json_object_to_json_string_ext_struct_inst.calls[json_object_to_json_string_ext_struct_inst.expectedCalls].check_params = 1;
    json_object_to_json_string_ext_struct_inst.expectedCalls++;
}

void json_object_set_serializer(json_object * jso, json_object_to_json_string_fn to_string_func, void * userdata, json_object_delete_fn * user_delete)
{
    int opmock_i;
    json_object_set_serializer_struct_inst.actualCalls++;

    if (json_object_set_serializer_struct_inst.callback != NULL)
    {
        json_object_set_serializer_struct_inst.callback (jso, to_string_func, userdata, user_delete, json_object_set_serializer_struct_inst.actualCalls);
        return;
    }
    if (json_object_set_serializer_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'json_object_set_serializer', returning random value.");
        return;
    }

    if(strcmp(opmock_get_current_call(), "void json_object_set_serializer (json_object * jso, json_object_to_json_string_fn to_string_func, void * userdata, json_object_delete_fn * user_delete)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'void json_object_set_serializer(json_object * jso, json_object_to_json_string_fn to_string_func, void * userdata, json_object_delete_fn * user_delete)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (json_object_set_serializer_struct_inst.calls[0].check_params == 1) {
        if(json_object_set_serializer_struct_inst.calls[0].match_jso) {
            void * val1 = (void *) &json_object_set_serializer_struct_inst.calls[0].jso;
            void * val2 = (void *) &jso;
            int match_result = json_object_set_serializer_struct_inst.calls[0].match_jso(val1, val2, "jso", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'json_object_set_serializer', %s",json_object_set_serializer_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
        if(json_object_set_serializer_struct_inst.calls[0].match_to_string_func) {
            void * val1 = (void *) &json_object_set_serializer_struct_inst.calls[0].to_string_func;
            void * val2 = (void *) &to_string_func;
            int match_result = json_object_set_serializer_struct_inst.calls[0].match_to_string_func(val1, val2, "to_string_func", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'json_object_set_serializer', %s",json_object_set_serializer_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
        if(json_object_set_serializer_struct_inst.calls[0].match_userdata) {
            void * val1 = (void *) &json_object_set_serializer_struct_inst.calls[0].userdata;
            void * val2 = (void *) &userdata;
            int match_result = json_object_set_serializer_struct_inst.calls[0].match_userdata(val1, val2, "userdata", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'json_object_set_serializer', %s",json_object_set_serializer_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
        if(json_object_set_serializer_struct_inst.calls[0].match_user_delete) {
            void * val1 = (void *) &json_object_set_serializer_struct_inst.calls[0].user_delete;
            void * val2 = (void *) &user_delete;
            int match_result = json_object_set_serializer_struct_inst.calls[0].match_user_delete(val1, val2, "user_delete", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'json_object_set_serializer', %s",json_object_set_serializer_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < json_object_set_serializer_struct_inst.expectedCalls; opmock_i++) {
        json_object_set_serializer_struct_inst.calls[opmock_i - 1] = json_object_set_serializer_struct_inst.calls[opmock_i];
    }

    json_object_set_serializer_struct_inst.expectedCalls--;
}

void json_object_set_serializer_MockReset()
{
    json_object_set_serializer_struct_inst.expectedCalls = 0;
    json_object_set_serializer_struct_inst.actualCalls = 0;
    json_object_set_serializer_struct_inst.callback = NULL;
}

void json_object_set_serializer_MockWithCallback(OPMOCK_json_object_set_serializer_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    json_object_set_serializer_struct_inst.callback = callback;
    json_object_set_serializer_struct_inst.expectedCalls = 0;
    json_object_set_serializer_struct_inst.actualCalls = 0;
}

void json_object_set_serializer_VerifyMock()
{
    if (json_object_set_serializer_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'json_object_set_serializer'",json_object_set_serializer_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void json_object_set_serializer_ExpectAndReturn (json_object * jso, json_object_to_json_string_fn to_string_func, void * userdata, json_object_delete_fn * user_delete, OPMOCK_MATCHER match_jso, OPMOCK_MATCHER match_to_string_func, OPMOCK_MATCHER match_userdata, OPMOCK_MATCHER match_user_delete)
{
    if(json_object_set_serializer_struct_inst.callback != NULL)
    {
        json_object_set_serializer_MockReset ();
    }

    if(json_object_set_serializer_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting json_object_set_serializer_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"void json_object_set_serializer (json_object * jso, json_object_to_json_string_fn to_string_func, void * userdata, json_object_delete_fn * user_delete)");
    json_object_set_serializer_struct_inst.calls[json_object_set_serializer_struct_inst.expectedCalls].jso = (void *)jso;
    json_object_set_serializer_struct_inst.calls[json_object_set_serializer_struct_inst.expectedCalls].to_string_func = (json_to_string_func)to_string_func;
    json_object_set_serializer_struct_inst.calls[json_object_set_serializer_struct_inst.expectedCalls].userdata = (void *)userdata;
    json_object_set_serializer_struct_inst.calls[json_object_set_serializer_struct_inst.expectedCalls].user_delete = (void *)user_delete;
    json_object_set_serializer_struct_inst.calls[json_object_set_serializer_struct_inst.expectedCalls].match_jso = match_jso;
    json_object_set_serializer_struct_inst.calls[json_object_set_serializer_struct_inst.expectedCalls].match_to_string_func = match_to_string_func;
    json_object_set_serializer_struct_inst.calls[json_object_set_serializer_struct_inst.expectedCalls].match_userdata = match_userdata;
    json_object_set_serializer_struct_inst.calls[json_object_set_serializer_struct_inst.expectedCalls].match_user_delete = match_user_delete;
    json_object_set_serializer_struct_inst.calls[json_object_set_serializer_struct_inst.expectedCalls].check_params = 1;
    json_object_set_serializer_struct_inst.expectedCalls++;
}

void json_object_free_userdata(struct json_object * arg1, void * arg2)
{
    int opmock_i;
    json_object_free_userdata_struct_inst.actualCalls++;

    if (json_object_free_userdata_struct_inst.callback != NULL)
    {
        json_object_free_userdata_struct_inst.callback (arg1, arg2, json_object_free_userdata_struct_inst.actualCalls);
        return;
    }
    if (json_object_free_userdata_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'json_object_free_userdata', returning random value.");
        return;
    }

    if(strcmp(opmock_get_current_call(), "void json_object_free_userdata (struct json_object * arg1, void * arg2)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'void json_object_free_userdata(struct json_object * arg1, void * arg2)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (json_object_free_userdata_struct_inst.calls[0].check_params == 1) {
        if(json_object_free_userdata_struct_inst.calls[0].match_arg1) {
            void * val1 = (void *) &json_object_free_userdata_struct_inst.calls[0].arg1;
            void * val2 = (void *) &arg1;
            int match_result = json_object_free_userdata_struct_inst.calls[0].match_arg1(val1, val2, "arg1", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'json_object_free_userdata', %s",json_object_free_userdata_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
        if(json_object_free_userdata_struct_inst.calls[0].match_arg2) {
            void * val1 = (void *) &json_object_free_userdata_struct_inst.calls[0].arg2;
            void * val2 = (void *) &arg2;
            int match_result = json_object_free_userdata_struct_inst.calls[0].match_arg2(val1, val2, "arg2", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'json_object_free_userdata', %s",json_object_free_userdata_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < json_object_free_userdata_struct_inst.expectedCalls; opmock_i++) {
        json_object_free_userdata_struct_inst.calls[opmock_i - 1] = json_object_free_userdata_struct_inst.calls[opmock_i];
    }

    json_object_free_userdata_struct_inst.expectedCalls--;
}

void json_object_free_userdata_MockReset()
{
    json_object_free_userdata_struct_inst.expectedCalls = 0;
    json_object_free_userdata_struct_inst.actualCalls = 0;
    json_object_free_userdata_struct_inst.callback = NULL;
}

void json_object_free_userdata_MockWithCallback(OPMOCK_json_object_free_userdata_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    json_object_free_userdata_struct_inst.callback = callback;
    json_object_free_userdata_struct_inst.expectedCalls = 0;
    json_object_free_userdata_struct_inst.actualCalls = 0;
}

void json_object_free_userdata_VerifyMock()
{
    if (json_object_free_userdata_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'json_object_free_userdata'",json_object_free_userdata_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void json_object_free_userdata_ExpectAndReturn (struct json_object * arg1, void * arg2, OPMOCK_MATCHER match_arg1, OPMOCK_MATCHER match_arg2)
{
    if(json_object_free_userdata_struct_inst.callback != NULL)
    {
        json_object_free_userdata_MockReset ();
    }

    if(json_object_free_userdata_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting json_object_free_userdata_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"void json_object_free_userdata (struct json_object * arg1, void * arg2)");
    json_object_free_userdata_struct_inst.calls[json_object_free_userdata_struct_inst.expectedCalls].arg1 = (void *)arg1;
    json_object_free_userdata_struct_inst.calls[json_object_free_userdata_struct_inst.expectedCalls].arg2 = (void *)arg2;
    json_object_free_userdata_struct_inst.calls[json_object_free_userdata_struct_inst.expectedCalls].match_arg1 = match_arg1;
    json_object_free_userdata_struct_inst.calls[json_object_free_userdata_struct_inst.expectedCalls].match_arg2 = match_arg2;
    json_object_free_userdata_struct_inst.calls[json_object_free_userdata_struct_inst.expectedCalls].check_params = 1;
    json_object_free_userdata_struct_inst.expectedCalls++;
}

int json_object_userdata_to_json_string(struct json_object * arg1, struct printbuf * arg2, int arg3, int arg4)
{
    int default_res = (int)json_object_userdata_to_json_string_struct_inst.calls[0].to_return;
    int opmock_i;
    json_object_userdata_to_json_string_struct_inst.actualCalls++;

    if (json_object_userdata_to_json_string_struct_inst.callback != NULL)
    {
        return json_object_userdata_to_json_string_struct_inst.callback (arg1, arg2, arg3, arg4, json_object_userdata_to_json_string_struct_inst.actualCalls);
    }
    if (json_object_userdata_to_json_string_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'json_object_userdata_to_json_string', returning random value.");
        return default_res;
    }

    if(strcmp(opmock_get_current_call(), "int json_object_userdata_to_json_string (struct json_object * arg1, struct printbuf * arg2, int arg3, int arg4)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'int json_object_userdata_to_json_string(struct json_object * arg1, struct printbuf * arg2, int arg3, int arg4)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (json_object_userdata_to_json_string_struct_inst.calls[0].check_params == 1) {
        if(json_object_userdata_to_json_string_struct_inst.calls[0].match_arg1) {
            void * val1 = (void *) &json_object_userdata_to_json_string_struct_inst.calls[0].arg1;
            void * val2 = (void *) &arg1;
            int match_result = json_object_userdata_to_json_string_struct_inst.calls[0].match_arg1(val1, val2, "arg1", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'json_object_userdata_to_json_string', %s",json_object_userdata_to_json_string_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
        if(json_object_userdata_to_json_string_struct_inst.calls[0].match_arg2) {
            void * val1 = (void *) &json_object_userdata_to_json_string_struct_inst.calls[0].arg2;
            void * val2 = (void *) &arg2;
            int match_result = json_object_userdata_to_json_string_struct_inst.calls[0].match_arg2(val1, val2, "arg2", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'json_object_userdata_to_json_string', %s",json_object_userdata_to_json_string_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
        if(json_object_userdata_to_json_string_struct_inst.calls[0].match_arg3) {
            void * val1 = (void *) &json_object_userdata_to_json_string_struct_inst.calls[0].arg3;
            void * val2 = (void *) &arg3;
            int match_result = json_object_userdata_to_json_string_struct_inst.calls[0].match_arg3(val1, val2, "arg3", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'json_object_userdata_to_json_string', %s",json_object_userdata_to_json_string_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
        if(json_object_userdata_to_json_string_struct_inst.calls[0].match_arg4) {
            void * val1 = (void *) &json_object_userdata_to_json_string_struct_inst.calls[0].arg4;
            void * val2 = (void *) &arg4;
            int match_result = json_object_userdata_to_json_string_struct_inst.calls[0].match_arg4(val1, val2, "arg4", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'json_object_userdata_to_json_string', %s",json_object_userdata_to_json_string_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < json_object_userdata_to_json_string_struct_inst.expectedCalls; opmock_i++) {
        json_object_userdata_to_json_string_struct_inst.calls[opmock_i - 1] = json_object_userdata_to_json_string_struct_inst.calls[opmock_i];
    }

    json_object_userdata_to_json_string_struct_inst.expectedCalls--;
    return default_res;
}

void json_object_userdata_to_json_string_MockReset()
{
    json_object_userdata_to_json_string_struct_inst.expectedCalls = 0;
    json_object_userdata_to_json_string_struct_inst.actualCalls = 0;
    json_object_userdata_to_json_string_struct_inst.callback = NULL;
}

void json_object_userdata_to_json_string_MockWithCallback(OPMOCK_json_object_userdata_to_json_string_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    json_object_userdata_to_json_string_struct_inst.callback = callback;
    json_object_userdata_to_json_string_struct_inst.expectedCalls = 0;
    json_object_userdata_to_json_string_struct_inst.actualCalls = 0;
}

void json_object_userdata_to_json_string_VerifyMock()
{
    if (json_object_userdata_to_json_string_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'json_object_userdata_to_json_string'",json_object_userdata_to_json_string_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void json_object_userdata_to_json_string_ExpectAndReturn (struct json_object * arg1, struct printbuf * arg2, int arg3, int arg4, int to_return, OPMOCK_MATCHER match_arg1, OPMOCK_MATCHER match_arg2, OPMOCK_MATCHER match_arg3, OPMOCK_MATCHER match_arg4)
{
    if(json_object_userdata_to_json_string_struct_inst.callback != NULL)
    {
        json_object_userdata_to_json_string_MockReset ();
    }

    if(json_object_userdata_to_json_string_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting json_object_userdata_to_json_string_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"int json_object_userdata_to_json_string (struct json_object * arg1, struct printbuf * arg2, int arg3, int arg4)");
    json_object_userdata_to_json_string_struct_inst.calls[json_object_userdata_to_json_string_struct_inst.expectedCalls].arg1 = (void *)arg1;
    json_object_userdata_to_json_string_struct_inst.calls[json_object_userdata_to_json_string_struct_inst.expectedCalls].arg2 = (void *)arg2;
    json_object_userdata_to_json_string_struct_inst.calls[json_object_userdata_to_json_string_struct_inst.expectedCalls].arg3 = (int)arg3;
    json_object_userdata_to_json_string_struct_inst.calls[json_object_userdata_to_json_string_struct_inst.expectedCalls].arg4 = (int)arg4;
    json_object_userdata_to_json_string_struct_inst.calls[json_object_userdata_to_json_string_struct_inst.expectedCalls].match_arg1 = match_arg1;
    json_object_userdata_to_json_string_struct_inst.calls[json_object_userdata_to_json_string_struct_inst.expectedCalls].match_arg2 = match_arg2;
    json_object_userdata_to_json_string_struct_inst.calls[json_object_userdata_to_json_string_struct_inst.expectedCalls].match_arg3 = match_arg3;
    json_object_userdata_to_json_string_struct_inst.calls[json_object_userdata_to_json_string_struct_inst.expectedCalls].match_arg4 = match_arg4;
    json_object_userdata_to_json_string_struct_inst.calls[json_object_userdata_to_json_string_struct_inst.expectedCalls].to_return = (int) to_return;
    json_object_userdata_to_json_string_struct_inst.calls[json_object_userdata_to_json_string_struct_inst.expectedCalls].check_params = 1;
    json_object_userdata_to_json_string_struct_inst.expectedCalls++;
}

struct json_object * json_object_new_object()
{
    struct json_object * default_res = (struct json_object *)json_object_new_object_struct_inst.calls[0].to_return;
    int opmock_i;
    json_object_new_object_struct_inst.actualCalls++;

    if (json_object_new_object_struct_inst.callback != NULL)
    {
        return json_object_new_object_struct_inst.callback (json_object_new_object_struct_inst.actualCalls);
    }
    if (json_object_new_object_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'json_object_new_object', returning random value.");
        return default_res;
    }

    if(strcmp(opmock_get_current_call(), "struct json_object * json_object_new_object ()") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'struct json_object * json_object_new_object()',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (json_object_new_object_struct_inst.calls[0].check_params == 1) {
    }

    for(opmock_i = 1; opmock_i < json_object_new_object_struct_inst.expectedCalls; opmock_i++) {
        json_object_new_object_struct_inst.calls[opmock_i - 1] = json_object_new_object_struct_inst.calls[opmock_i];
    }

    json_object_new_object_struct_inst.expectedCalls--;
    return default_res;
}

void json_object_new_object_MockReset()
{
    json_object_new_object_struct_inst.expectedCalls = 0;
    json_object_new_object_struct_inst.actualCalls = 0;
    json_object_new_object_struct_inst.callback = NULL;
}

void json_object_new_object_MockWithCallback(OPMOCK_json_object_new_object_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    json_object_new_object_struct_inst.callback = callback;
    json_object_new_object_struct_inst.expectedCalls = 0;
    json_object_new_object_struct_inst.actualCalls = 0;
}

void json_object_new_object_VerifyMock()
{
    if (json_object_new_object_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'json_object_new_object'",json_object_new_object_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void json_object_new_object_ExpectAndReturn (struct json_object * to_return)
{
    if(json_object_new_object_struct_inst.callback != NULL)
    {
        json_object_new_object_MockReset ();
    }

    if(json_object_new_object_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting json_object_new_object_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"struct json_object * json_object_new_object ()");
    json_object_new_object_struct_inst.calls[json_object_new_object_struct_inst.expectedCalls].to_return = (struct json_object *) to_return;
    json_object_new_object_struct_inst.calls[json_object_new_object_struct_inst.expectedCalls].check_params = 1;
    json_object_new_object_struct_inst.expectedCalls++;
}

struct lh_table * json_object_get_object(struct json_object * obj)
{
    struct lh_table * default_res = (struct lh_table *)json_object_get_object_struct_inst.calls[0].to_return;
    int opmock_i;
    json_object_get_object_struct_inst.actualCalls++;

    if (json_object_get_object_struct_inst.callback != NULL)
    {
        return json_object_get_object_struct_inst.callback (obj, json_object_get_object_struct_inst.actualCalls);
    }
    if (json_object_get_object_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'json_object_get_object', returning random value.");
        return default_res;
    }

    if(strcmp(opmock_get_current_call(), "struct lh_table * json_object_get_object (struct json_object * obj)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'struct lh_table * json_object_get_object(struct json_object * obj)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (json_object_get_object_struct_inst.calls[0].check_params == 1) {
        if(json_object_get_object_struct_inst.calls[0].match_obj) {
            void * val1 = (void *) &json_object_get_object_struct_inst.calls[0].obj;
            void * val2 = (void *) &obj;
            int match_result = json_object_get_object_struct_inst.calls[0].match_obj(val1, val2, "obj", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'json_object_get_object', %s",json_object_get_object_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < json_object_get_object_struct_inst.expectedCalls; opmock_i++) {
        json_object_get_object_struct_inst.calls[opmock_i - 1] = json_object_get_object_struct_inst.calls[opmock_i];
    }

    json_object_get_object_struct_inst.expectedCalls--;
    return default_res;
}

void json_object_get_object_MockReset()
{
    json_object_get_object_struct_inst.expectedCalls = 0;
    json_object_get_object_struct_inst.actualCalls = 0;
    json_object_get_object_struct_inst.callback = NULL;
}

void json_object_get_object_MockWithCallback(OPMOCK_json_object_get_object_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    json_object_get_object_struct_inst.callback = callback;
    json_object_get_object_struct_inst.expectedCalls = 0;
    json_object_get_object_struct_inst.actualCalls = 0;
}

void json_object_get_object_VerifyMock()
{
    if (json_object_get_object_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'json_object_get_object'",json_object_get_object_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void json_object_get_object_ExpectAndReturn (struct json_object * obj, struct lh_table * to_return, OPMOCK_MATCHER match_obj)
{
    if(json_object_get_object_struct_inst.callback != NULL)
    {
        json_object_get_object_MockReset ();
    }

    if(json_object_get_object_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting json_object_get_object_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"struct lh_table * json_object_get_object (struct json_object * obj)");
    json_object_get_object_struct_inst.calls[json_object_get_object_struct_inst.expectedCalls].obj = (void *)obj;
    json_object_get_object_struct_inst.calls[json_object_get_object_struct_inst.expectedCalls].match_obj = match_obj;
    json_object_get_object_struct_inst.calls[json_object_get_object_struct_inst.expectedCalls].to_return = (struct lh_table *) to_return;
    json_object_get_object_struct_inst.calls[json_object_get_object_struct_inst.expectedCalls].check_params = 1;
    json_object_get_object_struct_inst.expectedCalls++;
}

int json_object_object_length(struct json_object * obj)
{
    int default_res = (int)json_object_object_length_struct_inst.calls[0].to_return;
    int opmock_i;
    json_object_object_length_struct_inst.actualCalls++;

    if (json_object_object_length_struct_inst.callback != NULL)
    {
        return json_object_object_length_struct_inst.callback (obj, json_object_object_length_struct_inst.actualCalls);
    }
    if (json_object_object_length_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'json_object_object_length', returning random value.");
        return default_res;
    }

    if(strcmp(opmock_get_current_call(), "int json_object_object_length (struct json_object * obj)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'int json_object_object_length(struct json_object * obj)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (json_object_object_length_struct_inst.calls[0].check_params == 1) {
        if(json_object_object_length_struct_inst.calls[0].match_obj) {
            void * val1 = (void *) &json_object_object_length_struct_inst.calls[0].obj;
            void * val2 = (void *) &obj;
            int match_result = json_object_object_length_struct_inst.calls[0].match_obj(val1, val2, "obj", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'json_object_object_length', %s",json_object_object_length_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < json_object_object_length_struct_inst.expectedCalls; opmock_i++) {
        json_object_object_length_struct_inst.calls[opmock_i - 1] = json_object_object_length_struct_inst.calls[opmock_i];
    }

    json_object_object_length_struct_inst.expectedCalls--;
    return default_res;
}

void json_object_object_length_MockReset()
{
    json_object_object_length_struct_inst.expectedCalls = 0;
    json_object_object_length_struct_inst.actualCalls = 0;
    json_object_object_length_struct_inst.callback = NULL;
}

void json_object_object_length_MockWithCallback(OPMOCK_json_object_object_length_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    json_object_object_length_struct_inst.callback = callback;
    json_object_object_length_struct_inst.expectedCalls = 0;
    json_object_object_length_struct_inst.actualCalls = 0;
}

void json_object_object_length_VerifyMock()
{
    if (json_object_object_length_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'json_object_object_length'",json_object_object_length_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void json_object_object_length_ExpectAndReturn (struct json_object * obj, int to_return, OPMOCK_MATCHER match_obj)
{
    if(json_object_object_length_struct_inst.callback != NULL)
    {
        json_object_object_length_MockReset ();
    }

    if(json_object_object_length_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting json_object_object_length_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"int json_object_object_length (struct json_object * obj)");
    json_object_object_length_struct_inst.calls[json_object_object_length_struct_inst.expectedCalls].obj = (void *)obj;
    json_object_object_length_struct_inst.calls[json_object_object_length_struct_inst.expectedCalls].match_obj = match_obj;
    json_object_object_length_struct_inst.calls[json_object_object_length_struct_inst.expectedCalls].to_return = (int) to_return;
    json_object_object_length_struct_inst.calls[json_object_object_length_struct_inst.expectedCalls].check_params = 1;
    json_object_object_length_struct_inst.expectedCalls++;
}

void json_object_object_add(struct json_object * obj, const char * key, struct json_object * val)
{
    int opmock_i;
    json_object_object_add_struct_inst.actualCalls++;

    if (json_object_object_add_struct_inst.callback != NULL)
    {
        json_object_object_add_struct_inst.callback (obj, key, val, json_object_object_add_struct_inst.actualCalls);
        return;
    }
    if (json_object_object_add_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'json_object_object_add', returning random value.");
        return;
    }

    if(strcmp(opmock_get_current_call(), "void json_object_object_add (struct json_object * obj, const char * key, struct json_object * val)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'void json_object_object_add(struct json_object * obj, const char * key, struct json_object * val)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (json_object_object_add_struct_inst.calls[0].check_params == 1) {
        if(json_object_object_add_struct_inst.calls[0].match_obj) {
            void * val1 = (void *) &json_object_object_add_struct_inst.calls[0].obj;
            void * val2 = (void *) &obj;
            int match_result = json_object_object_add_struct_inst.calls[0].match_obj(val1, val2, "obj", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'json_object_object_add', %s",json_object_object_add_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
        if(json_object_object_add_struct_inst.calls[0].match_key) {
            void * val1 = (void *) &json_object_object_add_struct_inst.calls[0].key;
            void * val2 = (void *) &key;
            int match_result = json_object_object_add_struct_inst.calls[0].match_key(val1, val2, "key", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'json_object_object_add', %s",json_object_object_add_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
        if(json_object_object_add_struct_inst.calls[0].match_val) {
            void * val1 = (void *) &json_object_object_add_struct_inst.calls[0].val;
            void * val2 = (void *) &val;
            int match_result = json_object_object_add_struct_inst.calls[0].match_val(val1, val2, "val", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'json_object_object_add', %s",json_object_object_add_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < json_object_object_add_struct_inst.expectedCalls; opmock_i++) {
        json_object_object_add_struct_inst.calls[opmock_i - 1] = json_object_object_add_struct_inst.calls[opmock_i];
    }

    json_object_object_add_struct_inst.expectedCalls--;
}

void json_object_object_add_MockReset()
{
    json_object_object_add_struct_inst.expectedCalls = 0;
    json_object_object_add_struct_inst.actualCalls = 0;
    json_object_object_add_struct_inst.callback = NULL;
}

void json_object_object_add_MockWithCallback(OPMOCK_json_object_object_add_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    json_object_object_add_struct_inst.callback = callback;
    json_object_object_add_struct_inst.expectedCalls = 0;
    json_object_object_add_struct_inst.actualCalls = 0;
}

void json_object_object_add_VerifyMock()
{
    if (json_object_object_add_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'json_object_object_add'",json_object_object_add_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void json_object_object_add_ExpectAndReturn (struct json_object * obj, const char * key, struct json_object * val, OPMOCK_MATCHER match_obj, OPMOCK_MATCHER match_key, OPMOCK_MATCHER match_val)
{
    if(json_object_object_add_struct_inst.callback != NULL)
    {
        json_object_object_add_MockReset ();
    }

    if(json_object_object_add_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting json_object_object_add_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"void json_object_object_add (struct json_object * obj, const char * key, struct json_object * val)");
    json_object_object_add_struct_inst.calls[json_object_object_add_struct_inst.expectedCalls].obj = (void *)obj;
    json_object_object_add_struct_inst.calls[json_object_object_add_struct_inst.expectedCalls].key = (void *)key;
    json_object_object_add_struct_inst.calls[json_object_object_add_struct_inst.expectedCalls].val = (void *)val;
    json_object_object_add_struct_inst.calls[json_object_object_add_struct_inst.expectedCalls].match_obj = match_obj;
    json_object_object_add_struct_inst.calls[json_object_object_add_struct_inst.expectedCalls].match_key = match_key;
    json_object_object_add_struct_inst.calls[json_object_object_add_struct_inst.expectedCalls].match_val = match_val;
    json_object_object_add_struct_inst.calls[json_object_object_add_struct_inst.expectedCalls].check_params = 1;
    json_object_object_add_struct_inst.expectedCalls++;
}

struct json_object * json_object_object_get(struct json_object * obj, const char * key)
{
    struct json_object * default_res = (struct json_object *)json_object_object_get_struct_inst.calls[0].to_return;
    int opmock_i;
    json_object_object_get_struct_inst.actualCalls++;

    if (json_object_object_get_struct_inst.callback != NULL)
    {
        return json_object_object_get_struct_inst.callback (obj, key, json_object_object_get_struct_inst.actualCalls);
    }
    if (json_object_object_get_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'json_object_object_get', returning random value.");
        return default_res;
    }

    if(strcmp(opmock_get_current_call(), "struct json_object * json_object_object_get (struct json_object * obj, const char * key)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'struct json_object * json_object_object_get(struct json_object * obj, const char * key)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (json_object_object_get_struct_inst.calls[0].check_params == 1) {
        if(json_object_object_get_struct_inst.calls[0].match_obj) {
            void * val1 = (void *) &json_object_object_get_struct_inst.calls[0].obj;
            void * val2 = (void *) &obj;
            int match_result = json_object_object_get_struct_inst.calls[0].match_obj(val1, val2, "obj", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'json_object_object_get', %s",json_object_object_get_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
        if(json_object_object_get_struct_inst.calls[0].match_key) {
            void * val1 = (void *) &json_object_object_get_struct_inst.calls[0].key;
            void * val2 = (void *) &key;
            int match_result = json_object_object_get_struct_inst.calls[0].match_key(val1, val2, "key", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'json_object_object_get', %s",json_object_object_get_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < json_object_object_get_struct_inst.expectedCalls; opmock_i++) {
        json_object_object_get_struct_inst.calls[opmock_i - 1] = json_object_object_get_struct_inst.calls[opmock_i];
    }

    json_object_object_get_struct_inst.expectedCalls--;
    return default_res;
}

void json_object_object_get_MockReset()
{
    json_object_object_get_struct_inst.expectedCalls = 0;
    json_object_object_get_struct_inst.actualCalls = 0;
    json_object_object_get_struct_inst.callback = NULL;
}

void json_object_object_get_MockWithCallback(OPMOCK_json_object_object_get_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    json_object_object_get_struct_inst.callback = callback;
    json_object_object_get_struct_inst.expectedCalls = 0;
    json_object_object_get_struct_inst.actualCalls = 0;
}

void json_object_object_get_VerifyMock()
{
    if (json_object_object_get_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'json_object_object_get'",json_object_object_get_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void json_object_object_get_ExpectAndReturn (struct json_object * obj, const char * key, struct json_object * to_return, OPMOCK_MATCHER match_obj, OPMOCK_MATCHER match_key)
{
    if(json_object_object_get_struct_inst.callback != NULL)
    {
        json_object_object_get_MockReset ();
    }

    if(json_object_object_get_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting json_object_object_get_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"struct json_object * json_object_object_get (struct json_object * obj, const char * key)");
    json_object_object_get_struct_inst.calls[json_object_object_get_struct_inst.expectedCalls].obj = (void *)obj;
    json_object_object_get_struct_inst.calls[json_object_object_get_struct_inst.expectedCalls].key = (void *)key;
    json_object_object_get_struct_inst.calls[json_object_object_get_struct_inst.expectedCalls].match_obj = match_obj;
    json_object_object_get_struct_inst.calls[json_object_object_get_struct_inst.expectedCalls].match_key = match_key;
    json_object_object_get_struct_inst.calls[json_object_object_get_struct_inst.expectedCalls].to_return = (struct json_object *) to_return;
    json_object_object_get_struct_inst.calls[json_object_object_get_struct_inst.expectedCalls].check_params = 1;
    json_object_object_get_struct_inst.expectedCalls++;
}

json_bool json_object_object_get_ex(struct json_object * obj, const char * key, struct json_object ** value)
{
    json_bool default_res = (json_bool)json_object_object_get_ex_struct_inst.calls[0].to_return;
    int opmock_i;
    json_object_object_get_ex_struct_inst.actualCalls++;

    if (json_object_object_get_ex_struct_inst.callback != NULL)
    {
        return json_object_object_get_ex_struct_inst.callback (obj, key, value, json_object_object_get_ex_struct_inst.actualCalls);
    }
    if (json_object_object_get_ex_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'json_object_object_get_ex', returning random value.");
        return default_res;
    }

    if(strcmp(opmock_get_current_call(), "json_bool json_object_object_get_ex (struct json_object * obj, const char * key, struct json_object ** value)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'json_bool json_object_object_get_ex(struct json_object * obj, const char * key, struct json_object ** value)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (json_object_object_get_ex_struct_inst.calls[0].check_params == 1) {
        if(json_object_object_get_ex_struct_inst.calls[0].match_obj) {
            void * val1 = (void *) &json_object_object_get_ex_struct_inst.calls[0].obj;
            void * val2 = (void *) &obj;
            int match_result = json_object_object_get_ex_struct_inst.calls[0].match_obj(val1, val2, "obj", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'json_object_object_get_ex', %s",json_object_object_get_ex_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
        if(json_object_object_get_ex_struct_inst.calls[0].match_key) {
            void * val1 = (void *) &json_object_object_get_ex_struct_inst.calls[0].key;
            void * val2 = (void *) &key;
            int match_result = json_object_object_get_ex_struct_inst.calls[0].match_key(val1, val2, "key", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'json_object_object_get_ex', %s",json_object_object_get_ex_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
        if(json_object_object_get_ex_struct_inst.calls[0].match_value) {
            void * val1 = (void *) &json_object_object_get_ex_struct_inst.calls[0].value;
            void * val2 = (void *) &value;
            int match_result = json_object_object_get_ex_struct_inst.calls[0].match_value(val1, val2, "value", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'json_object_object_get_ex', %s",json_object_object_get_ex_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < json_object_object_get_ex_struct_inst.expectedCalls; opmock_i++) {
        json_object_object_get_ex_struct_inst.calls[opmock_i - 1] = json_object_object_get_ex_struct_inst.calls[opmock_i];
    }

    json_object_object_get_ex_struct_inst.expectedCalls--;
    return default_res;
}

void json_object_object_get_ex_MockReset()
{
    json_object_object_get_ex_struct_inst.expectedCalls = 0;
    json_object_object_get_ex_struct_inst.actualCalls = 0;
    json_object_object_get_ex_struct_inst.callback = NULL;
}

void json_object_object_get_ex_MockWithCallback(OPMOCK_json_object_object_get_ex_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    json_object_object_get_ex_struct_inst.callback = callback;
    json_object_object_get_ex_struct_inst.expectedCalls = 0;
    json_object_object_get_ex_struct_inst.actualCalls = 0;
}

void json_object_object_get_ex_VerifyMock()
{
    if (json_object_object_get_ex_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'json_object_object_get_ex'",json_object_object_get_ex_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void json_object_object_get_ex_ExpectAndReturn (struct json_object * obj, const char * key, struct json_object ** value, json_bool to_return, OPMOCK_MATCHER match_obj, OPMOCK_MATCHER match_key, OPMOCK_MATCHER match_value)
{
    if(json_object_object_get_ex_struct_inst.callback != NULL)
    {
        json_object_object_get_ex_MockReset ();
    }

    if(json_object_object_get_ex_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting json_object_object_get_ex_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"json_bool json_object_object_get_ex (struct json_object * obj, const char * key, struct json_object ** value)");
    json_object_object_get_ex_struct_inst.calls[json_object_object_get_ex_struct_inst.expectedCalls].obj = (void *)obj;
    json_object_object_get_ex_struct_inst.calls[json_object_object_get_ex_struct_inst.expectedCalls].key = (void *)key;
    json_object_object_get_ex_struct_inst.calls[json_object_object_get_ex_struct_inst.expectedCalls].value = (void *)value;
    json_object_object_get_ex_struct_inst.calls[json_object_object_get_ex_struct_inst.expectedCalls].match_obj = match_obj;
    json_object_object_get_ex_struct_inst.calls[json_object_object_get_ex_struct_inst.expectedCalls].match_key = match_key;
    json_object_object_get_ex_struct_inst.calls[json_object_object_get_ex_struct_inst.expectedCalls].match_value = match_value;
    json_object_object_get_ex_struct_inst.calls[json_object_object_get_ex_struct_inst.expectedCalls].to_return = (int) to_return;
    json_object_object_get_ex_struct_inst.calls[json_object_object_get_ex_struct_inst.expectedCalls].check_params = 1;
    json_object_object_get_ex_struct_inst.expectedCalls++;
}

void json_object_object_del(struct json_object * obj, const char * key)
{
    int opmock_i;
    json_object_object_del_struct_inst.actualCalls++;

    if (json_object_object_del_struct_inst.callback != NULL)
    {
        json_object_object_del_struct_inst.callback (obj, key, json_object_object_del_struct_inst.actualCalls);
        return;
    }
    if (json_object_object_del_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'json_object_object_del', returning random value.");
        return;
    }

    if(strcmp(opmock_get_current_call(), "void json_object_object_del (struct json_object * obj, const char * key)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'void json_object_object_del(struct json_object * obj, const char * key)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (json_object_object_del_struct_inst.calls[0].check_params == 1) {
        if(json_object_object_del_struct_inst.calls[0].match_obj) {
            void * val1 = (void *) &json_object_object_del_struct_inst.calls[0].obj;
            void * val2 = (void *) &obj;
            int match_result = json_object_object_del_struct_inst.calls[0].match_obj(val1, val2, "obj", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'json_object_object_del', %s",json_object_object_del_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
        if(json_object_object_del_struct_inst.calls[0].match_key) {
            void * val1 = (void *) &json_object_object_del_struct_inst.calls[0].key;
            void * val2 = (void *) &key;
            int match_result = json_object_object_del_struct_inst.calls[0].match_key(val1, val2, "key", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'json_object_object_del', %s",json_object_object_del_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < json_object_object_del_struct_inst.expectedCalls; opmock_i++) {
        json_object_object_del_struct_inst.calls[opmock_i - 1] = json_object_object_del_struct_inst.calls[opmock_i];
    }

    json_object_object_del_struct_inst.expectedCalls--;
}

void json_object_object_del_MockReset()
{
    json_object_object_del_struct_inst.expectedCalls = 0;
    json_object_object_del_struct_inst.actualCalls = 0;
    json_object_object_del_struct_inst.callback = NULL;
}

void json_object_object_del_MockWithCallback(OPMOCK_json_object_object_del_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    json_object_object_del_struct_inst.callback = callback;
    json_object_object_del_struct_inst.expectedCalls = 0;
    json_object_object_del_struct_inst.actualCalls = 0;
}

void json_object_object_del_VerifyMock()
{
    if (json_object_object_del_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'json_object_object_del'",json_object_object_del_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void json_object_object_del_ExpectAndReturn (struct json_object * obj, const char * key, OPMOCK_MATCHER match_obj, OPMOCK_MATCHER match_key)
{
    if(json_object_object_del_struct_inst.callback != NULL)
    {
        json_object_object_del_MockReset ();
    }

    if(json_object_object_del_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting json_object_object_del_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"void json_object_object_del (struct json_object * obj, const char * key)");
    json_object_object_del_struct_inst.calls[json_object_object_del_struct_inst.expectedCalls].obj = (void *)obj;
    json_object_object_del_struct_inst.calls[json_object_object_del_struct_inst.expectedCalls].key = (void *)key;
    json_object_object_del_struct_inst.calls[json_object_object_del_struct_inst.expectedCalls].match_obj = match_obj;
    json_object_object_del_struct_inst.calls[json_object_object_del_struct_inst.expectedCalls].match_key = match_key;
    json_object_object_del_struct_inst.calls[json_object_object_del_struct_inst.expectedCalls].check_params = 1;
    json_object_object_del_struct_inst.expectedCalls++;
}

struct json_object * json_object_new_array()
{
    struct json_object * default_res = (struct json_object *)json_object_new_array_struct_inst.calls[0].to_return;
    int opmock_i;
    json_object_new_array_struct_inst.actualCalls++;

    if (json_object_new_array_struct_inst.callback != NULL)
    {
        return json_object_new_array_struct_inst.callback (json_object_new_array_struct_inst.actualCalls);
    }
    if (json_object_new_array_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'json_object_new_array', returning random value.");
        return default_res;
    }

    if(strcmp(opmock_get_current_call(), "struct json_object * json_object_new_array ()") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'struct json_object * json_object_new_array()',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (json_object_new_array_struct_inst.calls[0].check_params == 1) {
    }

    for(opmock_i = 1; opmock_i < json_object_new_array_struct_inst.expectedCalls; opmock_i++) {
        json_object_new_array_struct_inst.calls[opmock_i - 1] = json_object_new_array_struct_inst.calls[opmock_i];
    }

    json_object_new_array_struct_inst.expectedCalls--;
    return default_res;
}

void json_object_new_array_MockReset()
{
    json_object_new_array_struct_inst.expectedCalls = 0;
    json_object_new_array_struct_inst.actualCalls = 0;
    json_object_new_array_struct_inst.callback = NULL;
}

void json_object_new_array_MockWithCallback(OPMOCK_json_object_new_array_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    json_object_new_array_struct_inst.callback = callback;
    json_object_new_array_struct_inst.expectedCalls = 0;
    json_object_new_array_struct_inst.actualCalls = 0;
}

void json_object_new_array_VerifyMock()
{
    if (json_object_new_array_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'json_object_new_array'",json_object_new_array_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void json_object_new_array_ExpectAndReturn (struct json_object * to_return)
{
    if(json_object_new_array_struct_inst.callback != NULL)
    {
        json_object_new_array_MockReset ();
    }

    if(json_object_new_array_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting json_object_new_array_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"struct json_object * json_object_new_array ()");
    json_object_new_array_struct_inst.calls[json_object_new_array_struct_inst.expectedCalls].to_return = (struct json_object *) to_return;
    json_object_new_array_struct_inst.calls[json_object_new_array_struct_inst.expectedCalls].check_params = 1;
    json_object_new_array_struct_inst.expectedCalls++;
}

struct array_list * json_object_get_array(struct json_object * obj)
{
    struct array_list * default_res = (struct array_list *)json_object_get_array_struct_inst.calls[0].to_return;
    int opmock_i;
    json_object_get_array_struct_inst.actualCalls++;

    if (json_object_get_array_struct_inst.callback != NULL)
    {
        return json_object_get_array_struct_inst.callback (obj, json_object_get_array_struct_inst.actualCalls);
    }
    if (json_object_get_array_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'json_object_get_array', returning random value.");
        return default_res;
    }

    if(strcmp(opmock_get_current_call(), "struct array_list * json_object_get_array (struct json_object * obj)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'struct array_list * json_object_get_array(struct json_object * obj)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (json_object_get_array_struct_inst.calls[0].check_params == 1) {
        if(json_object_get_array_struct_inst.calls[0].match_obj) {
            void * val1 = (void *) &json_object_get_array_struct_inst.calls[0].obj;
            void * val2 = (void *) &obj;
            int match_result = json_object_get_array_struct_inst.calls[0].match_obj(val1, val2, "obj", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'json_object_get_array', %s",json_object_get_array_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < json_object_get_array_struct_inst.expectedCalls; opmock_i++) {
        json_object_get_array_struct_inst.calls[opmock_i - 1] = json_object_get_array_struct_inst.calls[opmock_i];
    }

    json_object_get_array_struct_inst.expectedCalls--;
    return default_res;
}

void json_object_get_array_MockReset()
{
    json_object_get_array_struct_inst.expectedCalls = 0;
    json_object_get_array_struct_inst.actualCalls = 0;
    json_object_get_array_struct_inst.callback = NULL;
}

void json_object_get_array_MockWithCallback(OPMOCK_json_object_get_array_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    json_object_get_array_struct_inst.callback = callback;
    json_object_get_array_struct_inst.expectedCalls = 0;
    json_object_get_array_struct_inst.actualCalls = 0;
}

void json_object_get_array_VerifyMock()
{
    if (json_object_get_array_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'json_object_get_array'",json_object_get_array_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void json_object_get_array_ExpectAndReturn (struct json_object * obj, struct array_list * to_return, OPMOCK_MATCHER match_obj)
{
    if(json_object_get_array_struct_inst.callback != NULL)
    {
        json_object_get_array_MockReset ();
    }

    if(json_object_get_array_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting json_object_get_array_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"struct array_list * json_object_get_array (struct json_object * obj)");
    json_object_get_array_struct_inst.calls[json_object_get_array_struct_inst.expectedCalls].obj = (void *)obj;
    json_object_get_array_struct_inst.calls[json_object_get_array_struct_inst.expectedCalls].match_obj = match_obj;
    json_object_get_array_struct_inst.calls[json_object_get_array_struct_inst.expectedCalls].to_return = (struct array_list *) to_return;
    json_object_get_array_struct_inst.calls[json_object_get_array_struct_inst.expectedCalls].check_params = 1;
    json_object_get_array_struct_inst.expectedCalls++;
}

int json_object_array_length(struct json_object * obj)
{
    int default_res = (int)json_object_array_length_struct_inst.calls[0].to_return;
    int opmock_i;
    json_object_array_length_struct_inst.actualCalls++;

    if (json_object_array_length_struct_inst.callback != NULL)
    {
        return json_object_array_length_struct_inst.callback (obj, json_object_array_length_struct_inst.actualCalls);
    }
    if (json_object_array_length_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'json_object_array_length', returning random value.");
        return default_res;
    }

    if(strcmp(opmock_get_current_call(), "int json_object_array_length (struct json_object * obj)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'int json_object_array_length(struct json_object * obj)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (json_object_array_length_struct_inst.calls[0].check_params == 1) {
        if(json_object_array_length_struct_inst.calls[0].match_obj) {
            void * val1 = (void *) &json_object_array_length_struct_inst.calls[0].obj;
            void * val2 = (void *) &obj;
            int match_result = json_object_array_length_struct_inst.calls[0].match_obj(val1, val2, "obj", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'json_object_array_length', %s",json_object_array_length_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < json_object_array_length_struct_inst.expectedCalls; opmock_i++) {
        json_object_array_length_struct_inst.calls[opmock_i - 1] = json_object_array_length_struct_inst.calls[opmock_i];
    }

    json_object_array_length_struct_inst.expectedCalls--;
    return default_res;
}

void json_object_array_length_MockReset()
{
    json_object_array_length_struct_inst.expectedCalls = 0;
    json_object_array_length_struct_inst.actualCalls = 0;
    json_object_array_length_struct_inst.callback = NULL;
}

void json_object_array_length_MockWithCallback(OPMOCK_json_object_array_length_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    json_object_array_length_struct_inst.callback = callback;
    json_object_array_length_struct_inst.expectedCalls = 0;
    json_object_array_length_struct_inst.actualCalls = 0;
}

void json_object_array_length_VerifyMock()
{
    if (json_object_array_length_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'json_object_array_length'",json_object_array_length_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void json_object_array_length_ExpectAndReturn (struct json_object * obj, int to_return, OPMOCK_MATCHER match_obj)
{
    if(json_object_array_length_struct_inst.callback != NULL)
    {
        json_object_array_length_MockReset ();
    }

    if(json_object_array_length_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting json_object_array_length_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"int json_object_array_length (struct json_object * obj)");
    json_object_array_length_struct_inst.calls[json_object_array_length_struct_inst.expectedCalls].obj = (void *)obj;
    json_object_array_length_struct_inst.calls[json_object_array_length_struct_inst.expectedCalls].match_obj = match_obj;
    json_object_array_length_struct_inst.calls[json_object_array_length_struct_inst.expectedCalls].to_return = (int) to_return;
    json_object_array_length_struct_inst.calls[json_object_array_length_struct_inst.expectedCalls].check_params = 1;
    json_object_array_length_struct_inst.expectedCalls++;
}

void json_object_array_sort(struct json_object * jso, int (* sort_fn )(const void *, const void *))
{
    int opmock_i;
    json_object_array_sort_struct_inst.actualCalls++;

    if (json_object_array_sort_struct_inst.callback != NULL)
    {
        json_object_array_sort_struct_inst.callback (jso, sort_fn, json_object_array_sort_struct_inst.actualCalls);
        return;
    }
    if (json_object_array_sort_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'json_object_array_sort', returning random value.");
        return;
    }

    if(strcmp(opmock_get_current_call(), "void json_object_array_sort (struct json_object * jso, int (* sort_fn )(const void *, const void *))") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'void json_object_array_sort(struct json_object * jso, int (* sort_fn )(const void *, const void *))',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (json_object_array_sort_struct_inst.calls[0].check_params == 1) {
        if(json_object_array_sort_struct_inst.calls[0].match_jso) {
            void * val1 = (void *) &json_object_array_sort_struct_inst.calls[0].jso;
            void * val2 = (void *) &jso;
            int match_result = json_object_array_sort_struct_inst.calls[0].match_jso(val1, val2, "jso", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'json_object_array_sort', %s",json_object_array_sort_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
        if(json_object_array_sort_struct_inst.calls[0].match_sort_fn) {
            void * val1 = (void *) &json_object_array_sort_struct_inst.calls[0].sort_fn;
            void * val2 = (void *) &sort_fn;
            int match_result = json_object_array_sort_struct_inst.calls[0].match_sort_fn(val1, val2, "sort_fn", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'json_object_array_sort', %s",json_object_array_sort_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < json_object_array_sort_struct_inst.expectedCalls; opmock_i++) {
        json_object_array_sort_struct_inst.calls[opmock_i - 1] = json_object_array_sort_struct_inst.calls[opmock_i];
    }

    json_object_array_sort_struct_inst.expectedCalls--;
}

void json_object_array_sort_MockReset()
{
    json_object_array_sort_struct_inst.expectedCalls = 0;
    json_object_array_sort_struct_inst.actualCalls = 0;
    json_object_array_sort_struct_inst.callback = NULL;
}

void json_object_array_sort_MockWithCallback(OPMOCK_json_object_array_sort_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    json_object_array_sort_struct_inst.callback = callback;
    json_object_array_sort_struct_inst.expectedCalls = 0;
    json_object_array_sort_struct_inst.actualCalls = 0;
}

void json_object_array_sort_VerifyMock()
{
    if (json_object_array_sort_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'json_object_array_sort'",json_object_array_sort_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void json_object_array_sort_ExpectAndReturn (struct json_object * jso, int (* sort_fn )(const void *, const void *), OPMOCK_MATCHER match_jso, OPMOCK_MATCHER match_sort_fn)
{
    if(json_object_array_sort_struct_inst.callback != NULL)
    {
        json_object_array_sort_MockReset ();
    }

    if(json_object_array_sort_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting json_object_array_sort_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"void json_object_array_sort (struct json_object * jso, int (* sort_fn )(const void *, const void *))");
    json_object_array_sort_struct_inst.calls[json_object_array_sort_struct_inst.expectedCalls].jso = (void *)jso;
    json_object_array_sort_struct_inst.calls[json_object_array_sort_struct_inst.expectedCalls].sort_fn = (void *)sort_fn;
    json_object_array_sort_struct_inst.calls[json_object_array_sort_struct_inst.expectedCalls].match_jso = match_jso;
    json_object_array_sort_struct_inst.calls[json_object_array_sort_struct_inst.expectedCalls].match_sort_fn = match_sort_fn;
    json_object_array_sort_struct_inst.calls[json_object_array_sort_struct_inst.expectedCalls].check_params = 1;
    json_object_array_sort_struct_inst.expectedCalls++;
}

int json_object_array_add(struct json_object * obj, struct json_object * val)
{
    int default_res = (int)json_object_array_add_struct_inst.calls[0].to_return;
    int opmock_i;
    json_object_array_add_struct_inst.actualCalls++;

    if (json_object_array_add_struct_inst.callback != NULL)
    {
        return json_object_array_add_struct_inst.callback (obj, val, json_object_array_add_struct_inst.actualCalls);
    }
    if (json_object_array_add_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'json_object_array_add', returning random value.");
        return default_res;
    }

    if(strcmp(opmock_get_current_call(), "int json_object_array_add (struct json_object * obj, struct json_object * val)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'int json_object_array_add(struct json_object * obj, struct json_object * val)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (json_object_array_add_struct_inst.calls[0].check_params == 1) {
        if(json_object_array_add_struct_inst.calls[0].match_obj) {
            void * val1 = (void *) &json_object_array_add_struct_inst.calls[0].obj;
            void * val2 = (void *) &obj;
            int match_result = json_object_array_add_struct_inst.calls[0].match_obj(val1, val2, "obj", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'json_object_array_add', %s",json_object_array_add_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
        if(json_object_array_add_struct_inst.calls[0].match_val) {
            void * val1 = (void *) &json_object_array_add_struct_inst.calls[0].val;
            void * val2 = (void *) &val;
            int match_result = json_object_array_add_struct_inst.calls[0].match_val(val1, val2, "val", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'json_object_array_add', %s",json_object_array_add_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < json_object_array_add_struct_inst.expectedCalls; opmock_i++) {
        json_object_array_add_struct_inst.calls[opmock_i - 1] = json_object_array_add_struct_inst.calls[opmock_i];
    }

    json_object_array_add_struct_inst.expectedCalls--;
    return default_res;
}

void json_object_array_add_MockReset()
{
    json_object_array_add_struct_inst.expectedCalls = 0;
    json_object_array_add_struct_inst.actualCalls = 0;
    json_object_array_add_struct_inst.callback = NULL;
}

void json_object_array_add_MockWithCallback(OPMOCK_json_object_array_add_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    json_object_array_add_struct_inst.callback = callback;
    json_object_array_add_struct_inst.expectedCalls = 0;
    json_object_array_add_struct_inst.actualCalls = 0;
}

void json_object_array_add_VerifyMock()
{
    if (json_object_array_add_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'json_object_array_add'",json_object_array_add_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void json_object_array_add_ExpectAndReturn (struct json_object * obj, struct json_object * val, int to_return, OPMOCK_MATCHER match_obj, OPMOCK_MATCHER match_val)
{
    if(json_object_array_add_struct_inst.callback != NULL)
    {
        json_object_array_add_MockReset ();
    }

    if(json_object_array_add_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting json_object_array_add_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"int json_object_array_add (struct json_object * obj, struct json_object * val)");
    json_object_array_add_struct_inst.calls[json_object_array_add_struct_inst.expectedCalls].obj = (void *)obj;
    json_object_array_add_struct_inst.calls[json_object_array_add_struct_inst.expectedCalls].val = (void *)val;
    json_object_array_add_struct_inst.calls[json_object_array_add_struct_inst.expectedCalls].match_obj = match_obj;
    json_object_array_add_struct_inst.calls[json_object_array_add_struct_inst.expectedCalls].match_val = match_val;
    json_object_array_add_struct_inst.calls[json_object_array_add_struct_inst.expectedCalls].to_return = (int) to_return;
    json_object_array_add_struct_inst.calls[json_object_array_add_struct_inst.expectedCalls].check_params = 1;
    json_object_array_add_struct_inst.expectedCalls++;
}

int json_object_array_put_idx(struct json_object * obj, int idx, struct json_object * val)
{
    int default_res = (int)json_object_array_put_idx_struct_inst.calls[0].to_return;
    int opmock_i;
    json_object_array_put_idx_struct_inst.actualCalls++;

    if (json_object_array_put_idx_struct_inst.callback != NULL)
    {
        return json_object_array_put_idx_struct_inst.callback (obj, idx, val, json_object_array_put_idx_struct_inst.actualCalls);
    }
    if (json_object_array_put_idx_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'json_object_array_put_idx', returning random value.");
        return default_res;
    }

    if(strcmp(opmock_get_current_call(), "int json_object_array_put_idx (struct json_object * obj, int idx, struct json_object * val)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'int json_object_array_put_idx(struct json_object * obj, int idx, struct json_object * val)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (json_object_array_put_idx_struct_inst.calls[0].check_params == 1) {
        if(json_object_array_put_idx_struct_inst.calls[0].match_obj) {
            void * val1 = (void *) &json_object_array_put_idx_struct_inst.calls[0].obj;
            void * val2 = (void *) &obj;
            int match_result = json_object_array_put_idx_struct_inst.calls[0].match_obj(val1, val2, "obj", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'json_object_array_put_idx', %s",json_object_array_put_idx_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
        if(json_object_array_put_idx_struct_inst.calls[0].match_idx) {
            void * val1 = (void *) &json_object_array_put_idx_struct_inst.calls[0].idx;
            void * val2 = (void *) &idx;
            int match_result = json_object_array_put_idx_struct_inst.calls[0].match_idx(val1, val2, "idx", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'json_object_array_put_idx', %s",json_object_array_put_idx_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
        if(json_object_array_put_idx_struct_inst.calls[0].match_val) {
            void * val1 = (void *) &json_object_array_put_idx_struct_inst.calls[0].val;
            void * val2 = (void *) &val;
            int match_result = json_object_array_put_idx_struct_inst.calls[0].match_val(val1, val2, "val", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'json_object_array_put_idx', %s",json_object_array_put_idx_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < json_object_array_put_idx_struct_inst.expectedCalls; opmock_i++) {
        json_object_array_put_idx_struct_inst.calls[opmock_i - 1] = json_object_array_put_idx_struct_inst.calls[opmock_i];
    }

    json_object_array_put_idx_struct_inst.expectedCalls--;
    return default_res;
}

void json_object_array_put_idx_MockReset()
{
    json_object_array_put_idx_struct_inst.expectedCalls = 0;
    json_object_array_put_idx_struct_inst.actualCalls = 0;
    json_object_array_put_idx_struct_inst.callback = NULL;
}

void json_object_array_put_idx_MockWithCallback(OPMOCK_json_object_array_put_idx_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    json_object_array_put_idx_struct_inst.callback = callback;
    json_object_array_put_idx_struct_inst.expectedCalls = 0;
    json_object_array_put_idx_struct_inst.actualCalls = 0;
}

void json_object_array_put_idx_VerifyMock()
{
    if (json_object_array_put_idx_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'json_object_array_put_idx'",json_object_array_put_idx_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void json_object_array_put_idx_ExpectAndReturn (struct json_object * obj, int idx, struct json_object * val, int to_return, OPMOCK_MATCHER match_obj, OPMOCK_MATCHER match_idx, OPMOCK_MATCHER match_val)
{
    if(json_object_array_put_idx_struct_inst.callback != NULL)
    {
        json_object_array_put_idx_MockReset ();
    }

    if(json_object_array_put_idx_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting json_object_array_put_idx_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"int json_object_array_put_idx (struct json_object * obj, int idx, struct json_object * val)");
    json_object_array_put_idx_struct_inst.calls[json_object_array_put_idx_struct_inst.expectedCalls].obj = (void *)obj;
    json_object_array_put_idx_struct_inst.calls[json_object_array_put_idx_struct_inst.expectedCalls].idx = (int)idx;
    json_object_array_put_idx_struct_inst.calls[json_object_array_put_idx_struct_inst.expectedCalls].val = (void *)val;
    json_object_array_put_idx_struct_inst.calls[json_object_array_put_idx_struct_inst.expectedCalls].match_obj = match_obj;
    json_object_array_put_idx_struct_inst.calls[json_object_array_put_idx_struct_inst.expectedCalls].match_idx = match_idx;
    json_object_array_put_idx_struct_inst.calls[json_object_array_put_idx_struct_inst.expectedCalls].match_val = match_val;
    json_object_array_put_idx_struct_inst.calls[json_object_array_put_idx_struct_inst.expectedCalls].to_return = (int) to_return;
    json_object_array_put_idx_struct_inst.calls[json_object_array_put_idx_struct_inst.expectedCalls].check_params = 1;
    json_object_array_put_idx_struct_inst.expectedCalls++;
}

struct json_object * json_object_array_get_idx(struct json_object * obj, int idx)
{
    struct json_object * default_res = (struct json_object *)json_object_array_get_idx_struct_inst.calls[0].to_return;
    int opmock_i;
    json_object_array_get_idx_struct_inst.actualCalls++;

    if (json_object_array_get_idx_struct_inst.callback != NULL)
    {
        return json_object_array_get_idx_struct_inst.callback (obj, idx, json_object_array_get_idx_struct_inst.actualCalls);
    }
    if (json_object_array_get_idx_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'json_object_array_get_idx', returning random value.");
        return default_res;
    }

    if(strcmp(opmock_get_current_call(), "struct json_object * json_object_array_get_idx (struct json_object * obj, int idx)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'struct json_object * json_object_array_get_idx(struct json_object * obj, int idx)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (json_object_array_get_idx_struct_inst.calls[0].check_params == 1) {
        if(json_object_array_get_idx_struct_inst.calls[0].match_obj) {
            void * val1 = (void *) &json_object_array_get_idx_struct_inst.calls[0].obj;
            void * val2 = (void *) &obj;
            int match_result = json_object_array_get_idx_struct_inst.calls[0].match_obj(val1, val2, "obj", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'json_object_array_get_idx', %s",json_object_array_get_idx_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
        if(json_object_array_get_idx_struct_inst.calls[0].match_idx) {
            void * val1 = (void *) &json_object_array_get_idx_struct_inst.calls[0].idx;
            void * val2 = (void *) &idx;
            int match_result = json_object_array_get_idx_struct_inst.calls[0].match_idx(val1, val2, "idx", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'json_object_array_get_idx', %s",json_object_array_get_idx_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < json_object_array_get_idx_struct_inst.expectedCalls; opmock_i++) {
        json_object_array_get_idx_struct_inst.calls[opmock_i - 1] = json_object_array_get_idx_struct_inst.calls[opmock_i];
    }

    json_object_array_get_idx_struct_inst.expectedCalls--;
    return default_res;
}

void json_object_array_get_idx_MockReset()
{
    json_object_array_get_idx_struct_inst.expectedCalls = 0;
    json_object_array_get_idx_struct_inst.actualCalls = 0;
    json_object_array_get_idx_struct_inst.callback = NULL;
}

void json_object_array_get_idx_MockWithCallback(OPMOCK_json_object_array_get_idx_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    json_object_array_get_idx_struct_inst.callback = callback;
    json_object_array_get_idx_struct_inst.expectedCalls = 0;
    json_object_array_get_idx_struct_inst.actualCalls = 0;
}

void json_object_array_get_idx_VerifyMock()
{
    if (json_object_array_get_idx_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'json_object_array_get_idx'",json_object_array_get_idx_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void json_object_array_get_idx_ExpectAndReturn (struct json_object * obj, int idx, struct json_object * to_return, OPMOCK_MATCHER match_obj, OPMOCK_MATCHER match_idx)
{
    if(json_object_array_get_idx_struct_inst.callback != NULL)
    {
        json_object_array_get_idx_MockReset ();
    }

    if(json_object_array_get_idx_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting json_object_array_get_idx_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"struct json_object * json_object_array_get_idx (struct json_object * obj, int idx)");
    json_object_array_get_idx_struct_inst.calls[json_object_array_get_idx_struct_inst.expectedCalls].obj = (void *)obj;
    json_object_array_get_idx_struct_inst.calls[json_object_array_get_idx_struct_inst.expectedCalls].idx = (int)idx;
    json_object_array_get_idx_struct_inst.calls[json_object_array_get_idx_struct_inst.expectedCalls].match_obj = match_obj;
    json_object_array_get_idx_struct_inst.calls[json_object_array_get_idx_struct_inst.expectedCalls].match_idx = match_idx;
    json_object_array_get_idx_struct_inst.calls[json_object_array_get_idx_struct_inst.expectedCalls].to_return = (struct json_object *) to_return;
    json_object_array_get_idx_struct_inst.calls[json_object_array_get_idx_struct_inst.expectedCalls].check_params = 1;
    json_object_array_get_idx_struct_inst.expectedCalls++;
}

struct json_object * json_object_new_boolean(json_bool b)
{
    struct json_object * default_res = (struct json_object *)json_object_new_boolean_struct_inst.calls[0].to_return;
    int opmock_i;
    json_object_new_boolean_struct_inst.actualCalls++;

    if (json_object_new_boolean_struct_inst.callback != NULL)
    {
        return json_object_new_boolean_struct_inst.callback (b, json_object_new_boolean_struct_inst.actualCalls);
    }
    if (json_object_new_boolean_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'json_object_new_boolean', returning random value.");
        return default_res;
    }

    if(strcmp(opmock_get_current_call(), "struct json_object * json_object_new_boolean (json_bool b)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'struct json_object * json_object_new_boolean(json_bool b)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (json_object_new_boolean_struct_inst.calls[0].check_params == 1) {
        if(json_object_new_boolean_struct_inst.calls[0].match_b) {
            void * val1 = (void *) &json_object_new_boolean_struct_inst.calls[0].b;
            void * val2 = (void *) &b;
            int match_result = json_object_new_boolean_struct_inst.calls[0].match_b(val1, val2, "b", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'json_object_new_boolean', %s",json_object_new_boolean_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < json_object_new_boolean_struct_inst.expectedCalls; opmock_i++) {
        json_object_new_boolean_struct_inst.calls[opmock_i - 1] = json_object_new_boolean_struct_inst.calls[opmock_i];
    }

    json_object_new_boolean_struct_inst.expectedCalls--;
    return default_res;
}

void json_object_new_boolean_MockReset()
{
    json_object_new_boolean_struct_inst.expectedCalls = 0;
    json_object_new_boolean_struct_inst.actualCalls = 0;
    json_object_new_boolean_struct_inst.callback = NULL;
}

void json_object_new_boolean_MockWithCallback(OPMOCK_json_object_new_boolean_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    json_object_new_boolean_struct_inst.callback = callback;
    json_object_new_boolean_struct_inst.expectedCalls = 0;
    json_object_new_boolean_struct_inst.actualCalls = 0;
}

void json_object_new_boolean_VerifyMock()
{
    if (json_object_new_boolean_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'json_object_new_boolean'",json_object_new_boolean_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void json_object_new_boolean_ExpectAndReturn (json_bool b, struct json_object * to_return, OPMOCK_MATCHER match_b)
{
    if(json_object_new_boolean_struct_inst.callback != NULL)
    {
        json_object_new_boolean_MockReset ();
    }

    if(json_object_new_boolean_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting json_object_new_boolean_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"struct json_object * json_object_new_boolean (json_bool b)");
    json_object_new_boolean_struct_inst.calls[json_object_new_boolean_struct_inst.expectedCalls].b = (int)b;
    json_object_new_boolean_struct_inst.calls[json_object_new_boolean_struct_inst.expectedCalls].match_b = match_b;
    json_object_new_boolean_struct_inst.calls[json_object_new_boolean_struct_inst.expectedCalls].to_return = (struct json_object *) to_return;
    json_object_new_boolean_struct_inst.calls[json_object_new_boolean_struct_inst.expectedCalls].check_params = 1;
    json_object_new_boolean_struct_inst.expectedCalls++;
}

json_bool json_object_get_boolean(struct json_object * obj)
{
    json_bool default_res = (json_bool)json_object_get_boolean_struct_inst.calls[0].to_return;
    int opmock_i;
    json_object_get_boolean_struct_inst.actualCalls++;

    if (json_object_get_boolean_struct_inst.callback != NULL)
    {
        return json_object_get_boolean_struct_inst.callback (obj, json_object_get_boolean_struct_inst.actualCalls);
    }
    if (json_object_get_boolean_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'json_object_get_boolean', returning random value.");
        return default_res;
    }

    if(strcmp(opmock_get_current_call(), "json_bool json_object_get_boolean (struct json_object * obj)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'json_bool json_object_get_boolean(struct json_object * obj)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (json_object_get_boolean_struct_inst.calls[0].check_params == 1) {
        if(json_object_get_boolean_struct_inst.calls[0].match_obj) {
            void * val1 = (void *) &json_object_get_boolean_struct_inst.calls[0].obj;
            void * val2 = (void *) &obj;
            int match_result = json_object_get_boolean_struct_inst.calls[0].match_obj(val1, val2, "obj", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'json_object_get_boolean', %s",json_object_get_boolean_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < json_object_get_boolean_struct_inst.expectedCalls; opmock_i++) {
        json_object_get_boolean_struct_inst.calls[opmock_i - 1] = json_object_get_boolean_struct_inst.calls[opmock_i];
    }

    json_object_get_boolean_struct_inst.expectedCalls--;
    return default_res;
}

void json_object_get_boolean_MockReset()
{
    json_object_get_boolean_struct_inst.expectedCalls = 0;
    json_object_get_boolean_struct_inst.actualCalls = 0;
    json_object_get_boolean_struct_inst.callback = NULL;
}

void json_object_get_boolean_MockWithCallback(OPMOCK_json_object_get_boolean_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    json_object_get_boolean_struct_inst.callback = callback;
    json_object_get_boolean_struct_inst.expectedCalls = 0;
    json_object_get_boolean_struct_inst.actualCalls = 0;
}

void json_object_get_boolean_VerifyMock()
{
    if (json_object_get_boolean_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'json_object_get_boolean'",json_object_get_boolean_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void json_object_get_boolean_ExpectAndReturn (struct json_object * obj, json_bool to_return, OPMOCK_MATCHER match_obj)
{
    if(json_object_get_boolean_struct_inst.callback != NULL)
    {
        json_object_get_boolean_MockReset ();
    }

    if(json_object_get_boolean_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting json_object_get_boolean_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"json_bool json_object_get_boolean (struct json_object * obj)");
    json_object_get_boolean_struct_inst.calls[json_object_get_boolean_struct_inst.expectedCalls].obj = (void *)obj;
    json_object_get_boolean_struct_inst.calls[json_object_get_boolean_struct_inst.expectedCalls].match_obj = match_obj;
    json_object_get_boolean_struct_inst.calls[json_object_get_boolean_struct_inst.expectedCalls].to_return = (int) to_return;
    json_object_get_boolean_struct_inst.calls[json_object_get_boolean_struct_inst.expectedCalls].check_params = 1;
    json_object_get_boolean_struct_inst.expectedCalls++;
}

struct json_object * json_object_new_int(int32_t i)
{
    struct json_object * default_res = (struct json_object *)json_object_new_int_struct_inst.calls[0].to_return;
    int opmock_i;
    json_object_new_int_struct_inst.actualCalls++;

    if (json_object_new_int_struct_inst.callback != NULL)
    {
        return json_object_new_int_struct_inst.callback (i, json_object_new_int_struct_inst.actualCalls);
    }
    if (json_object_new_int_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'json_object_new_int', returning random value.");
        return default_res;
    }

    if(strcmp(opmock_get_current_call(), "struct json_object * json_object_new_int (int32_t i)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'struct json_object * json_object_new_int(int32_t i)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (json_object_new_int_struct_inst.calls[0].check_params == 1) {
        if(json_object_new_int_struct_inst.calls[0].match_i) {
            void * val1 = (void *) &json_object_new_int_struct_inst.calls[0].i;
            void * val2 = (void *) &i;
            int match_result = json_object_new_int_struct_inst.calls[0].match_i(val1, val2, "i", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'json_object_new_int', %s",json_object_new_int_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < json_object_new_int_struct_inst.expectedCalls; opmock_i++) {
        json_object_new_int_struct_inst.calls[opmock_i - 1] = json_object_new_int_struct_inst.calls[opmock_i];
    }

    json_object_new_int_struct_inst.expectedCalls--;
    return default_res;
}

void json_object_new_int_MockReset()
{
    json_object_new_int_struct_inst.expectedCalls = 0;
    json_object_new_int_struct_inst.actualCalls = 0;
    json_object_new_int_struct_inst.callback = NULL;
}

void json_object_new_int_MockWithCallback(OPMOCK_json_object_new_int_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    json_object_new_int_struct_inst.callback = callback;
    json_object_new_int_struct_inst.expectedCalls = 0;
    json_object_new_int_struct_inst.actualCalls = 0;
}

void json_object_new_int_VerifyMock()
{
    if (json_object_new_int_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'json_object_new_int'",json_object_new_int_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void json_object_new_int_ExpectAndReturn (int32_t i, struct json_object * to_return, OPMOCK_MATCHER match_i)
{
    if(json_object_new_int_struct_inst.callback != NULL)
    {
        json_object_new_int_MockReset ();
    }

    if(json_object_new_int_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting json_object_new_int_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"struct json_object * json_object_new_int (int32_t i)");
    json_object_new_int_struct_inst.calls[json_object_new_int_struct_inst.expectedCalls].i = (int)i;
    json_object_new_int_struct_inst.calls[json_object_new_int_struct_inst.expectedCalls].match_i = match_i;
    json_object_new_int_struct_inst.calls[json_object_new_int_struct_inst.expectedCalls].to_return = (struct json_object *) to_return;
    json_object_new_int_struct_inst.calls[json_object_new_int_struct_inst.expectedCalls].check_params = 1;
    json_object_new_int_struct_inst.expectedCalls++;
}

struct json_object * json_object_new_int64(int64_t i)
{
    struct json_object * default_res = (struct json_object *)json_object_new_int64_struct_inst.calls[0].to_return;
    int opmock_i;
    json_object_new_int64_struct_inst.actualCalls++;

    if (json_object_new_int64_struct_inst.callback != NULL)
    {
        return json_object_new_int64_struct_inst.callback (i, json_object_new_int64_struct_inst.actualCalls);
    }
    if (json_object_new_int64_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'json_object_new_int64', returning random value.");
        return default_res;
    }

    if(strcmp(opmock_get_current_call(), "struct json_object * json_object_new_int64 (int64_t i)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'struct json_object * json_object_new_int64(int64_t i)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (json_object_new_int64_struct_inst.calls[0].check_params == 1) {
        if(json_object_new_int64_struct_inst.calls[0].match_i) {
            void * val1 = (void *) &json_object_new_int64_struct_inst.calls[0].i;
            void * val2 = (void *) &i;
            int match_result = json_object_new_int64_struct_inst.calls[0].match_i(val1, val2, "i", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'json_object_new_int64', %s",json_object_new_int64_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < json_object_new_int64_struct_inst.expectedCalls; opmock_i++) {
        json_object_new_int64_struct_inst.calls[opmock_i - 1] = json_object_new_int64_struct_inst.calls[opmock_i];
    }

    json_object_new_int64_struct_inst.expectedCalls--;
    return default_res;
}

void json_object_new_int64_MockReset()
{
    json_object_new_int64_struct_inst.expectedCalls = 0;
    json_object_new_int64_struct_inst.actualCalls = 0;
    json_object_new_int64_struct_inst.callback = NULL;
}

void json_object_new_int64_MockWithCallback(OPMOCK_json_object_new_int64_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    json_object_new_int64_struct_inst.callback = callback;
    json_object_new_int64_struct_inst.expectedCalls = 0;
    json_object_new_int64_struct_inst.actualCalls = 0;
}

void json_object_new_int64_VerifyMock()
{
    if (json_object_new_int64_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'json_object_new_int64'",json_object_new_int64_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void json_object_new_int64_ExpectAndReturn (int64_t i, struct json_object * to_return, OPMOCK_MATCHER match_i)
{
    if(json_object_new_int64_struct_inst.callback != NULL)
    {
        json_object_new_int64_MockReset ();
    }

    if(json_object_new_int64_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting json_object_new_int64_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"struct json_object * json_object_new_int64 (int64_t i)");
    json_object_new_int64_struct_inst.calls[json_object_new_int64_struct_inst.expectedCalls].i = (long long)i;
    json_object_new_int64_struct_inst.calls[json_object_new_int64_struct_inst.expectedCalls].match_i = match_i;
    json_object_new_int64_struct_inst.calls[json_object_new_int64_struct_inst.expectedCalls].to_return = (struct json_object *) to_return;
    json_object_new_int64_struct_inst.calls[json_object_new_int64_struct_inst.expectedCalls].check_params = 1;
    json_object_new_int64_struct_inst.expectedCalls++;
}

int32_t json_object_get_int(struct json_object * obj)
{
    int32_t default_res = (int32_t)json_object_get_int_struct_inst.calls[0].to_return;
    int opmock_i;
    json_object_get_int_struct_inst.actualCalls++;

    if (json_object_get_int_struct_inst.callback != NULL)
    {
        return json_object_get_int_struct_inst.callback (obj, json_object_get_int_struct_inst.actualCalls);
    }
    if (json_object_get_int_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'json_object_get_int', returning random value.");
        return default_res;
    }

    if(strcmp(opmock_get_current_call(), "int32_t json_object_get_int (struct json_object * obj)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'int32_t json_object_get_int(struct json_object * obj)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (json_object_get_int_struct_inst.calls[0].check_params == 1) {
        if(json_object_get_int_struct_inst.calls[0].match_obj) {
            void * val1 = (void *) &json_object_get_int_struct_inst.calls[0].obj;
            void * val2 = (void *) &obj;
            int match_result = json_object_get_int_struct_inst.calls[0].match_obj(val1, val2, "obj", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'json_object_get_int', %s",json_object_get_int_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < json_object_get_int_struct_inst.expectedCalls; opmock_i++) {
        json_object_get_int_struct_inst.calls[opmock_i - 1] = json_object_get_int_struct_inst.calls[opmock_i];
    }

    json_object_get_int_struct_inst.expectedCalls--;
    return default_res;
}

void json_object_get_int_MockReset()
{
    json_object_get_int_struct_inst.expectedCalls = 0;
    json_object_get_int_struct_inst.actualCalls = 0;
    json_object_get_int_struct_inst.callback = NULL;
}

void json_object_get_int_MockWithCallback(OPMOCK_json_object_get_int_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    json_object_get_int_struct_inst.callback = callback;
    json_object_get_int_struct_inst.expectedCalls = 0;
    json_object_get_int_struct_inst.actualCalls = 0;
}

void json_object_get_int_VerifyMock()
{
    if (json_object_get_int_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'json_object_get_int'",json_object_get_int_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void json_object_get_int_ExpectAndReturn (struct json_object * obj, int32_t to_return, OPMOCK_MATCHER match_obj)
{
    if(json_object_get_int_struct_inst.callback != NULL)
    {
        json_object_get_int_MockReset ();
    }

    if(json_object_get_int_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting json_object_get_int_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"int32_t json_object_get_int (struct json_object * obj)");
    json_object_get_int_struct_inst.calls[json_object_get_int_struct_inst.expectedCalls].obj = (void *)obj;
    json_object_get_int_struct_inst.calls[json_object_get_int_struct_inst.expectedCalls].match_obj = match_obj;
    json_object_get_int_struct_inst.calls[json_object_get_int_struct_inst.expectedCalls].to_return = (int) to_return;
    json_object_get_int_struct_inst.calls[json_object_get_int_struct_inst.expectedCalls].check_params = 1;
    json_object_get_int_struct_inst.expectedCalls++;
}

int64_t json_object_get_int64(struct json_object * obj)
{
    int64_t default_res = (int64_t)json_object_get_int64_struct_inst.calls[0].to_return;
    int opmock_i;
    json_object_get_int64_struct_inst.actualCalls++;

    if (json_object_get_int64_struct_inst.callback != NULL)
    {
        return json_object_get_int64_struct_inst.callback (obj, json_object_get_int64_struct_inst.actualCalls);
    }
    if (json_object_get_int64_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'json_object_get_int64', returning random value.");
        return default_res;
    }

    if(strcmp(opmock_get_current_call(), "int64_t json_object_get_int64 (struct json_object * obj)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'int64_t json_object_get_int64(struct json_object * obj)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (json_object_get_int64_struct_inst.calls[0].check_params == 1) {
        if(json_object_get_int64_struct_inst.calls[0].match_obj) {
            void * val1 = (void *) &json_object_get_int64_struct_inst.calls[0].obj;
            void * val2 = (void *) &obj;
            int match_result = json_object_get_int64_struct_inst.calls[0].match_obj(val1, val2, "obj", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'json_object_get_int64', %s",json_object_get_int64_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < json_object_get_int64_struct_inst.expectedCalls; opmock_i++) {
        json_object_get_int64_struct_inst.calls[opmock_i - 1] = json_object_get_int64_struct_inst.calls[opmock_i];
    }

    json_object_get_int64_struct_inst.expectedCalls--;
    return default_res;
}

void json_object_get_int64_MockReset()
{
    json_object_get_int64_struct_inst.expectedCalls = 0;
    json_object_get_int64_struct_inst.actualCalls = 0;
    json_object_get_int64_struct_inst.callback = NULL;
}

void json_object_get_int64_MockWithCallback(OPMOCK_json_object_get_int64_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    json_object_get_int64_struct_inst.callback = callback;
    json_object_get_int64_struct_inst.expectedCalls = 0;
    json_object_get_int64_struct_inst.actualCalls = 0;
}

void json_object_get_int64_VerifyMock()
{
    if (json_object_get_int64_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'json_object_get_int64'",json_object_get_int64_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void json_object_get_int64_ExpectAndReturn (struct json_object * obj, int64_t to_return, OPMOCK_MATCHER match_obj)
{
    if(json_object_get_int64_struct_inst.callback != NULL)
    {
        json_object_get_int64_MockReset ();
    }

    if(json_object_get_int64_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting json_object_get_int64_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"int64_t json_object_get_int64 (struct json_object * obj)");
    json_object_get_int64_struct_inst.calls[json_object_get_int64_struct_inst.expectedCalls].obj = (void *)obj;
    json_object_get_int64_struct_inst.calls[json_object_get_int64_struct_inst.expectedCalls].match_obj = match_obj;
    json_object_get_int64_struct_inst.calls[json_object_get_int64_struct_inst.expectedCalls].to_return = (long long) to_return;
    json_object_get_int64_struct_inst.calls[json_object_get_int64_struct_inst.expectedCalls].check_params = 1;
    json_object_get_int64_struct_inst.expectedCalls++;
}

struct json_object * json_object_new_double(double d)
{
    struct json_object * default_res = (struct json_object *)json_object_new_double_struct_inst.calls[0].to_return;
    int opmock_i;
    json_object_new_double_struct_inst.actualCalls++;

    if (json_object_new_double_struct_inst.callback != NULL)
    {
        return json_object_new_double_struct_inst.callback (d, json_object_new_double_struct_inst.actualCalls);
    }
    if (json_object_new_double_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'json_object_new_double', returning random value.");
        return default_res;
    }

    if(strcmp(opmock_get_current_call(), "struct json_object * json_object_new_double (double d)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'struct json_object * json_object_new_double(double d)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (json_object_new_double_struct_inst.calls[0].check_params == 1) {
        if(json_object_new_double_struct_inst.calls[0].match_d) {
            void * val1 = (void *) &json_object_new_double_struct_inst.calls[0].d;
            void * val2 = (void *) &d;
            int match_result = json_object_new_double_struct_inst.calls[0].match_d(val1, val2, "d", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'json_object_new_double', %s",json_object_new_double_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < json_object_new_double_struct_inst.expectedCalls; opmock_i++) {
        json_object_new_double_struct_inst.calls[opmock_i - 1] = json_object_new_double_struct_inst.calls[opmock_i];
    }

    json_object_new_double_struct_inst.expectedCalls--;
    return default_res;
}

void json_object_new_double_MockReset()
{
    json_object_new_double_struct_inst.expectedCalls = 0;
    json_object_new_double_struct_inst.actualCalls = 0;
    json_object_new_double_struct_inst.callback = NULL;
}

void json_object_new_double_MockWithCallback(OPMOCK_json_object_new_double_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    json_object_new_double_struct_inst.callback = callback;
    json_object_new_double_struct_inst.expectedCalls = 0;
    json_object_new_double_struct_inst.actualCalls = 0;
}

void json_object_new_double_VerifyMock()
{
    if (json_object_new_double_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'json_object_new_double'",json_object_new_double_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void json_object_new_double_ExpectAndReturn (double d, struct json_object * to_return, OPMOCK_MATCHER match_d)
{
    if(json_object_new_double_struct_inst.callback != NULL)
    {
        json_object_new_double_MockReset ();
    }

    if(json_object_new_double_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting json_object_new_double_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"struct json_object * json_object_new_double (double d)");
    json_object_new_double_struct_inst.calls[json_object_new_double_struct_inst.expectedCalls].d = (double)d;
    json_object_new_double_struct_inst.calls[json_object_new_double_struct_inst.expectedCalls].match_d = match_d;
    json_object_new_double_struct_inst.calls[json_object_new_double_struct_inst.expectedCalls].to_return = (struct json_object *) to_return;
    json_object_new_double_struct_inst.calls[json_object_new_double_struct_inst.expectedCalls].check_params = 1;
    json_object_new_double_struct_inst.expectedCalls++;
}

struct json_object * json_object_new_double_s(double d, const char * ds)
{
    struct json_object * default_res = (struct json_object *)json_object_new_double_s_struct_inst.calls[0].to_return;
    int opmock_i;
    json_object_new_double_s_struct_inst.actualCalls++;

    if (json_object_new_double_s_struct_inst.callback != NULL)
    {
        return json_object_new_double_s_struct_inst.callback (d, ds, json_object_new_double_s_struct_inst.actualCalls);
    }
    if (json_object_new_double_s_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'json_object_new_double_s', returning random value.");
        return default_res;
    }

    if(strcmp(opmock_get_current_call(), "struct json_object * json_object_new_double_s (double d, const char * ds)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'struct json_object * json_object_new_double_s(double d, const char * ds)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (json_object_new_double_s_struct_inst.calls[0].check_params == 1) {
        if(json_object_new_double_s_struct_inst.calls[0].match_d) {
            void * val1 = (void *) &json_object_new_double_s_struct_inst.calls[0].d;
            void * val2 = (void *) &d;
            int match_result = json_object_new_double_s_struct_inst.calls[0].match_d(val1, val2, "d", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'json_object_new_double_s', %s",json_object_new_double_s_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
        if(json_object_new_double_s_struct_inst.calls[0].match_ds) {
            void * val1 = (void *) &json_object_new_double_s_struct_inst.calls[0].ds;
            void * val2 = (void *) &ds;
            int match_result = json_object_new_double_s_struct_inst.calls[0].match_ds(val1, val2, "ds", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'json_object_new_double_s', %s",json_object_new_double_s_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < json_object_new_double_s_struct_inst.expectedCalls; opmock_i++) {
        json_object_new_double_s_struct_inst.calls[opmock_i - 1] = json_object_new_double_s_struct_inst.calls[opmock_i];
    }

    json_object_new_double_s_struct_inst.expectedCalls--;
    return default_res;
}

void json_object_new_double_s_MockReset()
{
    json_object_new_double_s_struct_inst.expectedCalls = 0;
    json_object_new_double_s_struct_inst.actualCalls = 0;
    json_object_new_double_s_struct_inst.callback = NULL;
}

void json_object_new_double_s_MockWithCallback(OPMOCK_json_object_new_double_s_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    json_object_new_double_s_struct_inst.callback = callback;
    json_object_new_double_s_struct_inst.expectedCalls = 0;
    json_object_new_double_s_struct_inst.actualCalls = 0;
}

void json_object_new_double_s_VerifyMock()
{
    if (json_object_new_double_s_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'json_object_new_double_s'",json_object_new_double_s_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void json_object_new_double_s_ExpectAndReturn (double d, const char * ds, struct json_object * to_return, OPMOCK_MATCHER match_d, OPMOCK_MATCHER match_ds)
{
    if(json_object_new_double_s_struct_inst.callback != NULL)
    {
        json_object_new_double_s_MockReset ();
    }

    if(json_object_new_double_s_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting json_object_new_double_s_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"struct json_object * json_object_new_double_s (double d, const char * ds)");
    json_object_new_double_s_struct_inst.calls[json_object_new_double_s_struct_inst.expectedCalls].d = (double)d;
    json_object_new_double_s_struct_inst.calls[json_object_new_double_s_struct_inst.expectedCalls].ds = (void *)ds;
    json_object_new_double_s_struct_inst.calls[json_object_new_double_s_struct_inst.expectedCalls].match_d = match_d;
    json_object_new_double_s_struct_inst.calls[json_object_new_double_s_struct_inst.expectedCalls].match_ds = match_ds;
    json_object_new_double_s_struct_inst.calls[json_object_new_double_s_struct_inst.expectedCalls].to_return = (struct json_object *) to_return;
    json_object_new_double_s_struct_inst.calls[json_object_new_double_s_struct_inst.expectedCalls].check_params = 1;
    json_object_new_double_s_struct_inst.expectedCalls++;
}

double json_object_get_double(struct json_object * obj)
{
    double default_res = (double)json_object_get_double_struct_inst.calls[0].to_return;
    int opmock_i;
    json_object_get_double_struct_inst.actualCalls++;

    if (json_object_get_double_struct_inst.callback != NULL)
    {
        return json_object_get_double_struct_inst.callback (obj, json_object_get_double_struct_inst.actualCalls);
    }
    if (json_object_get_double_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'json_object_get_double', returning random value.");
        return default_res;
    }

    if(strcmp(opmock_get_current_call(), "double json_object_get_double (struct json_object * obj)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'double json_object_get_double(struct json_object * obj)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (json_object_get_double_struct_inst.calls[0].check_params == 1) {
        if(json_object_get_double_struct_inst.calls[0].match_obj) {
            void * val1 = (void *) &json_object_get_double_struct_inst.calls[0].obj;
            void * val2 = (void *) &obj;
            int match_result = json_object_get_double_struct_inst.calls[0].match_obj(val1, val2, "obj", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'json_object_get_double', %s",json_object_get_double_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < json_object_get_double_struct_inst.expectedCalls; opmock_i++) {
        json_object_get_double_struct_inst.calls[opmock_i - 1] = json_object_get_double_struct_inst.calls[opmock_i];
    }

    json_object_get_double_struct_inst.expectedCalls--;
    return default_res;
}

void json_object_get_double_MockReset()
{
    json_object_get_double_struct_inst.expectedCalls = 0;
    json_object_get_double_struct_inst.actualCalls = 0;
    json_object_get_double_struct_inst.callback = NULL;
}

void json_object_get_double_MockWithCallback(OPMOCK_json_object_get_double_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    json_object_get_double_struct_inst.callback = callback;
    json_object_get_double_struct_inst.expectedCalls = 0;
    json_object_get_double_struct_inst.actualCalls = 0;
}

void json_object_get_double_VerifyMock()
{
    if (json_object_get_double_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'json_object_get_double'",json_object_get_double_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void json_object_get_double_ExpectAndReturn (struct json_object * obj, double to_return, OPMOCK_MATCHER match_obj)
{
    if(json_object_get_double_struct_inst.callback != NULL)
    {
        json_object_get_double_MockReset ();
    }

    if(json_object_get_double_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting json_object_get_double_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"double json_object_get_double (struct json_object * obj)");
    json_object_get_double_struct_inst.calls[json_object_get_double_struct_inst.expectedCalls].obj = (void *)obj;
    json_object_get_double_struct_inst.calls[json_object_get_double_struct_inst.expectedCalls].match_obj = match_obj;
    json_object_get_double_struct_inst.calls[json_object_get_double_struct_inst.expectedCalls].to_return = (double) to_return;
    json_object_get_double_struct_inst.calls[json_object_get_double_struct_inst.expectedCalls].check_params = 1;
    json_object_get_double_struct_inst.expectedCalls++;
}

struct json_object * json_object_new_string(const char * s)
{
    struct json_object * default_res = (struct json_object *)json_object_new_string_struct_inst.calls[0].to_return;
    int opmock_i;
    json_object_new_string_struct_inst.actualCalls++;

    if (json_object_new_string_struct_inst.callback != NULL)
    {
        return json_object_new_string_struct_inst.callback (s, json_object_new_string_struct_inst.actualCalls);
    }
    if (json_object_new_string_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'json_object_new_string', returning random value.");
        return default_res;
    }

    if(strcmp(opmock_get_current_call(), "struct json_object * json_object_new_string (const char * s)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'struct json_object * json_object_new_string(const char * s)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (json_object_new_string_struct_inst.calls[0].check_params == 1) {
        if(json_object_new_string_struct_inst.calls[0].match_s) {
            void * val1 = (void *) &json_object_new_string_struct_inst.calls[0].s;
            void * val2 = (void *) &s;
            int match_result = json_object_new_string_struct_inst.calls[0].match_s(val1, val2, "s", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'json_object_new_string', %s",json_object_new_string_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < json_object_new_string_struct_inst.expectedCalls; opmock_i++) {
        json_object_new_string_struct_inst.calls[opmock_i - 1] = json_object_new_string_struct_inst.calls[opmock_i];
    }

    json_object_new_string_struct_inst.expectedCalls--;
    return default_res;
}

void json_object_new_string_MockReset()
{
    json_object_new_string_struct_inst.expectedCalls = 0;
    json_object_new_string_struct_inst.actualCalls = 0;
    json_object_new_string_struct_inst.callback = NULL;
}

void json_object_new_string_MockWithCallback(OPMOCK_json_object_new_string_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    json_object_new_string_struct_inst.callback = callback;
    json_object_new_string_struct_inst.expectedCalls = 0;
    json_object_new_string_struct_inst.actualCalls = 0;
}

void json_object_new_string_VerifyMock()
{
    if (json_object_new_string_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'json_object_new_string'",json_object_new_string_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void json_object_new_string_ExpectAndReturn (const char * s, struct json_object * to_return, OPMOCK_MATCHER match_s)
{
    if(json_object_new_string_struct_inst.callback != NULL)
    {
        json_object_new_string_MockReset ();
    }

    if(json_object_new_string_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting json_object_new_string_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"struct json_object * json_object_new_string (const char * s)");
    json_object_new_string_struct_inst.calls[json_object_new_string_struct_inst.expectedCalls].s = (void *)s;
    json_object_new_string_struct_inst.calls[json_object_new_string_struct_inst.expectedCalls].match_s = match_s;
    json_object_new_string_struct_inst.calls[json_object_new_string_struct_inst.expectedCalls].to_return = (struct json_object *) to_return;
    json_object_new_string_struct_inst.calls[json_object_new_string_struct_inst.expectedCalls].check_params = 1;
    json_object_new_string_struct_inst.expectedCalls++;
}

struct json_object * json_object_new_string_len(const char * s, int len)
{
    struct json_object * default_res = (struct json_object *)json_object_new_string_len_struct_inst.calls[0].to_return;
    int opmock_i;
    json_object_new_string_len_struct_inst.actualCalls++;

    if (json_object_new_string_len_struct_inst.callback != NULL)
    {
        return json_object_new_string_len_struct_inst.callback (s, len, json_object_new_string_len_struct_inst.actualCalls);
    }
    if (json_object_new_string_len_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'json_object_new_string_len', returning random value.");
        return default_res;
    }

    if(strcmp(opmock_get_current_call(), "struct json_object * json_object_new_string_len (const char * s, int len)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'struct json_object * json_object_new_string_len(const char * s, int len)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (json_object_new_string_len_struct_inst.calls[0].check_params == 1) {
        if(json_object_new_string_len_struct_inst.calls[0].match_s) {
            void * val1 = (void *) &json_object_new_string_len_struct_inst.calls[0].s;
            void * val2 = (void *) &s;
            int match_result = json_object_new_string_len_struct_inst.calls[0].match_s(val1, val2, "s", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'json_object_new_string_len', %s",json_object_new_string_len_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
        if(json_object_new_string_len_struct_inst.calls[0].match_len) {
            void * val1 = (void *) &json_object_new_string_len_struct_inst.calls[0].len;
            void * val2 = (void *) &len;
            int match_result = json_object_new_string_len_struct_inst.calls[0].match_len(val1, val2, "len", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'json_object_new_string_len', %s",json_object_new_string_len_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < json_object_new_string_len_struct_inst.expectedCalls; opmock_i++) {
        json_object_new_string_len_struct_inst.calls[opmock_i - 1] = json_object_new_string_len_struct_inst.calls[opmock_i];
    }

    json_object_new_string_len_struct_inst.expectedCalls--;
    return default_res;
}

void json_object_new_string_len_MockReset()
{
    json_object_new_string_len_struct_inst.expectedCalls = 0;
    json_object_new_string_len_struct_inst.actualCalls = 0;
    json_object_new_string_len_struct_inst.callback = NULL;
}

void json_object_new_string_len_MockWithCallback(OPMOCK_json_object_new_string_len_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    json_object_new_string_len_struct_inst.callback = callback;
    json_object_new_string_len_struct_inst.expectedCalls = 0;
    json_object_new_string_len_struct_inst.actualCalls = 0;
}

void json_object_new_string_len_VerifyMock()
{
    if (json_object_new_string_len_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'json_object_new_string_len'",json_object_new_string_len_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void json_object_new_string_len_ExpectAndReturn (const char * s, int len, struct json_object * to_return, OPMOCK_MATCHER match_s, OPMOCK_MATCHER match_len)
{
    if(json_object_new_string_len_struct_inst.callback != NULL)
    {
        json_object_new_string_len_MockReset ();
    }

    if(json_object_new_string_len_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting json_object_new_string_len_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"struct json_object * json_object_new_string_len (const char * s, int len)");
    json_object_new_string_len_struct_inst.calls[json_object_new_string_len_struct_inst.expectedCalls].s = (void *)s;
    json_object_new_string_len_struct_inst.calls[json_object_new_string_len_struct_inst.expectedCalls].len = (int)len;
    json_object_new_string_len_struct_inst.calls[json_object_new_string_len_struct_inst.expectedCalls].match_s = match_s;
    json_object_new_string_len_struct_inst.calls[json_object_new_string_len_struct_inst.expectedCalls].match_len = match_len;
    json_object_new_string_len_struct_inst.calls[json_object_new_string_len_struct_inst.expectedCalls].to_return = (struct json_object *) to_return;
    json_object_new_string_len_struct_inst.calls[json_object_new_string_len_struct_inst.expectedCalls].check_params = 1;
    json_object_new_string_len_struct_inst.expectedCalls++;
}

const char * json_object_get_string(struct json_object * obj)
{
    const char * default_res = (const char *)json_object_get_string_struct_inst.calls[0].to_return;
    int opmock_i;
    json_object_get_string_struct_inst.actualCalls++;

    if (json_object_get_string_struct_inst.callback != NULL)
    {
        return json_object_get_string_struct_inst.callback (obj, json_object_get_string_struct_inst.actualCalls);
    }
    if (json_object_get_string_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'json_object_get_string', returning random value.");
        return default_res;
    }

    if(strcmp(opmock_get_current_call(), "const char * json_object_get_string (struct json_object * obj)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'const char * json_object_get_string(struct json_object * obj)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (json_object_get_string_struct_inst.calls[0].check_params == 1) {
        if(json_object_get_string_struct_inst.calls[0].match_obj) {
            void * val1 = (void *) &json_object_get_string_struct_inst.calls[0].obj;
            void * val2 = (void *) &obj;
            int match_result = json_object_get_string_struct_inst.calls[0].match_obj(val1, val2, "obj", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'json_object_get_string', %s",json_object_get_string_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < json_object_get_string_struct_inst.expectedCalls; opmock_i++) {
        json_object_get_string_struct_inst.calls[opmock_i - 1] = json_object_get_string_struct_inst.calls[opmock_i];
    }

    json_object_get_string_struct_inst.expectedCalls--;
    return default_res;
}

void json_object_get_string_MockReset()
{
    json_object_get_string_struct_inst.expectedCalls = 0;
    json_object_get_string_struct_inst.actualCalls = 0;
    json_object_get_string_struct_inst.callback = NULL;
}

void json_object_get_string_MockWithCallback(OPMOCK_json_object_get_string_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    json_object_get_string_struct_inst.callback = callback;
    json_object_get_string_struct_inst.expectedCalls = 0;
    json_object_get_string_struct_inst.actualCalls = 0;
}

void json_object_get_string_VerifyMock()
{
    if (json_object_get_string_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'json_object_get_string'",json_object_get_string_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void json_object_get_string_ExpectAndReturn (struct json_object * obj, const char * to_return, OPMOCK_MATCHER match_obj)
{
    if(json_object_get_string_struct_inst.callback != NULL)
    {
        json_object_get_string_MockReset ();
    }

    if(json_object_get_string_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting json_object_get_string_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"const char * json_object_get_string (struct json_object * obj)");
    json_object_get_string_struct_inst.calls[json_object_get_string_struct_inst.expectedCalls].obj = (void *)obj;
    json_object_get_string_struct_inst.calls[json_object_get_string_struct_inst.expectedCalls].match_obj = match_obj;
    json_object_get_string_struct_inst.calls[json_object_get_string_struct_inst.expectedCalls].to_return = ( char *) to_return;
    json_object_get_string_struct_inst.calls[json_object_get_string_struct_inst.expectedCalls].check_params = 1;
    json_object_get_string_struct_inst.expectedCalls++;
}

int json_object_get_string_len(struct json_object * obj)
{
    int default_res = (int)json_object_get_string_len_struct_inst.calls[0].to_return;
    int opmock_i;
    json_object_get_string_len_struct_inst.actualCalls++;

    if (json_object_get_string_len_struct_inst.callback != NULL)
    {
        return json_object_get_string_len_struct_inst.callback (obj, json_object_get_string_len_struct_inst.actualCalls);
    }
    if (json_object_get_string_len_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'json_object_get_string_len', returning random value.");
        return default_res;
    }

    if(strcmp(opmock_get_current_call(), "int json_object_get_string_len (struct json_object * obj)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'int json_object_get_string_len(struct json_object * obj)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (json_object_get_string_len_struct_inst.calls[0].check_params == 1) {
        if(json_object_get_string_len_struct_inst.calls[0].match_obj) {
            void * val1 = (void *) &json_object_get_string_len_struct_inst.calls[0].obj;
            void * val2 = (void *) &obj;
            int match_result = json_object_get_string_len_struct_inst.calls[0].match_obj(val1, val2, "obj", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'json_object_get_string_len', %s",json_object_get_string_len_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < json_object_get_string_len_struct_inst.expectedCalls; opmock_i++) {
        json_object_get_string_len_struct_inst.calls[opmock_i - 1] = json_object_get_string_len_struct_inst.calls[opmock_i];
    }

    json_object_get_string_len_struct_inst.expectedCalls--;
    return default_res;
}

void json_object_get_string_len_MockReset()
{
    json_object_get_string_len_struct_inst.expectedCalls = 0;
    json_object_get_string_len_struct_inst.actualCalls = 0;
    json_object_get_string_len_struct_inst.callback = NULL;
}

void json_object_get_string_len_MockWithCallback(OPMOCK_json_object_get_string_len_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    json_object_get_string_len_struct_inst.callback = callback;
    json_object_get_string_len_struct_inst.expectedCalls = 0;
    json_object_get_string_len_struct_inst.actualCalls = 0;
}

void json_object_get_string_len_VerifyMock()
{
    if (json_object_get_string_len_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'json_object_get_string_len'",json_object_get_string_len_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void json_object_get_string_len_ExpectAndReturn (struct json_object * obj, int to_return, OPMOCK_MATCHER match_obj)
{
    if(json_object_get_string_len_struct_inst.callback != NULL)
    {
        json_object_get_string_len_MockReset ();
    }

    if(json_object_get_string_len_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting json_object_get_string_len_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"int json_object_get_string_len (struct json_object * obj)");
    json_object_get_string_len_struct_inst.calls[json_object_get_string_len_struct_inst.expectedCalls].obj = (void *)obj;
    json_object_get_string_len_struct_inst.calls[json_object_get_string_len_struct_inst.expectedCalls].match_obj = match_obj;
    json_object_get_string_len_struct_inst.calls[json_object_get_string_len_struct_inst.expectedCalls].to_return = (int) to_return;
    json_object_get_string_len_struct_inst.calls[json_object_get_string_len_struct_inst.expectedCalls].check_params = 1;
    json_object_get_string_len_struct_inst.expectedCalls++;
}

#pragma GCC diagnostic pop

