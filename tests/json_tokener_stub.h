/* OPMOCK2 GENERATED CODE - DO NOT MODIFY */
#ifndef _JSON_TOKENER_STUB_H
#define _JSON_TOKENER_STUB_H

#include <json_tokener.h>
#include "opmock.h"

#ifdef __cplusplus
extern "C" {
#endif

void json_tokener_error_desc_ExpectAndReturn(enum json_tokener_error jerr, const char * to_return, OPMOCK_MATCHER match_jerr);
void json_tokener_error_desc_MockReset();
typedef const char * (* OPMOCK_json_tokener_error_desc_CALLBACK)(enum json_tokener_error jerr, int calls);
void json_tokener_error_desc_MockWithCallback(OPMOCK_json_tokener_error_desc_CALLBACK callback);
void json_tokener_error_desc_VerifyMock();
void json_tokener_get_error_ExpectAndReturn(struct json_tokener * tok, enum json_tokener_error to_return, OPMOCK_MATCHER match_tok);
void json_tokener_get_error_MockReset();
typedef enum json_tokener_error (* OPMOCK_json_tokener_get_error_CALLBACK)(struct json_tokener * tok, int calls);
void json_tokener_get_error_MockWithCallback(OPMOCK_json_tokener_get_error_CALLBACK callback);
void json_tokener_get_error_VerifyMock();
void json_tokener_new_ExpectAndReturn(struct json_tokener * to_return);
void json_tokener_new_MockReset();
typedef struct json_tokener * (* OPMOCK_json_tokener_new_CALLBACK)(int calls);
void json_tokener_new_MockWithCallback(OPMOCK_json_tokener_new_CALLBACK callback);
void json_tokener_new_VerifyMock();
void json_tokener_new_ex_ExpectAndReturn(int depth, struct json_tokener * to_return, OPMOCK_MATCHER match_depth);
void json_tokener_new_ex_MockReset();
typedef struct json_tokener * (* OPMOCK_json_tokener_new_ex_CALLBACK)(int depth, int calls);
void json_tokener_new_ex_MockWithCallback(OPMOCK_json_tokener_new_ex_CALLBACK callback);
void json_tokener_new_ex_VerifyMock();
void json_tokener_free_ExpectAndReturn(struct json_tokener * tok, OPMOCK_MATCHER match_tok);
void json_tokener_free_MockReset();
typedef void (* OPMOCK_json_tokener_free_CALLBACK)(struct json_tokener * tok, int calls);
void json_tokener_free_MockWithCallback(OPMOCK_json_tokener_free_CALLBACK callback);
void json_tokener_free_VerifyMock();
void json_tokener_reset_ExpectAndReturn(struct json_tokener * tok, OPMOCK_MATCHER match_tok);
void json_tokener_reset_MockReset();
typedef void (* OPMOCK_json_tokener_reset_CALLBACK)(struct json_tokener * tok, int calls);
void json_tokener_reset_MockWithCallback(OPMOCK_json_tokener_reset_CALLBACK callback);
void json_tokener_reset_VerifyMock();
void json_tokener_parse_ExpectAndReturn(const char * str, struct json_object * to_return, OPMOCK_MATCHER match_str);
void json_tokener_parse_MockReset();
typedef struct json_object * (* OPMOCK_json_tokener_parse_CALLBACK)(const char * str, int calls);
void json_tokener_parse_MockWithCallback(OPMOCK_json_tokener_parse_CALLBACK callback);
void json_tokener_parse_VerifyMock();
void json_tokener_parse_verbose_ExpectAndReturn(const char * str, enum json_tokener_error * error, struct json_object * to_return, OPMOCK_MATCHER match_str, OPMOCK_MATCHER match_error);
void json_tokener_parse_verbose_MockReset();
typedef struct json_object * (* OPMOCK_json_tokener_parse_verbose_CALLBACK)(const char * str, enum json_tokener_error * error, int calls);
void json_tokener_parse_verbose_MockWithCallback(OPMOCK_json_tokener_parse_verbose_CALLBACK callback);
void json_tokener_parse_verbose_VerifyMock();
void json_tokener_set_flags_ExpectAndReturn(struct json_tokener * tok, int flags, OPMOCK_MATCHER match_tok, OPMOCK_MATCHER match_flags);
void json_tokener_set_flags_MockReset();
typedef void (* OPMOCK_json_tokener_set_flags_CALLBACK)(struct json_tokener * tok, int flags, int calls);
void json_tokener_set_flags_MockWithCallback(OPMOCK_json_tokener_set_flags_CALLBACK callback);
void json_tokener_set_flags_VerifyMock();
void json_tokener_parse_ex_ExpectAndReturn(struct json_tokener * tok, const char * str, int len, struct json_object * to_return, OPMOCK_MATCHER match_tok, OPMOCK_MATCHER match_str, OPMOCK_MATCHER match_len);
void json_tokener_parse_ex_MockReset();
typedef struct json_object * (* OPMOCK_json_tokener_parse_ex_CALLBACK)(struct json_tokener * tok, const char * str, int len, int calls);
void json_tokener_parse_ex_MockWithCallback(OPMOCK_json_tokener_parse_ex_CALLBACK callback);
void json_tokener_parse_ex_VerifyMock();

#ifdef __cplusplus
}
#endif
#endif
