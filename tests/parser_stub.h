/* OPMOCK2 GENERATED CODE - DO NOT MODIFY */
#ifndef _PARSER_STUB_H
#define _PARSER_STUB_H

#include <parser.h>
#include "opmock.h"

#ifdef __cplusplus
extern "C" {
#endif

void parser_get_line_ExpectAndReturn(Buffer * srcBuffer, char * destBuffer, size_t length, _Bool to_return, OPMOCK_MATCHER match_srcBuffer, OPMOCK_MATCHER match_destBuffer, OPMOCK_MATCHER match_length);
void parser_get_line_MockReset();
typedef _Bool (* OPMOCK_parser_get_line_CALLBACK)(Buffer * srcBuffer, char * destBuffer, size_t length, int calls);
void parser_get_line_MockWithCallback(OPMOCK_parser_get_line_CALLBACK callback);
void parser_get_line_VerifyMock();
void parser_process_line_ExpectAndReturn(const char * arg1, size_t arg2, ParserResult * to_return, OPMOCK_MATCHER match_arg1, OPMOCK_MATCHER match_arg2);
void parser_process_line_MockReset();
typedef ParserResult * (* OPMOCK_parser_process_line_CALLBACK)(const char * arg1, size_t arg2, int calls);
void parser_process_line_MockWithCallback(OPMOCK_parser_process_line_CALLBACK callback);
void parser_process_line_VerifyMock();
void parser_result_new_ExpectAndReturn(ParserResult * to_return);
void parser_result_new_MockReset();
typedef ParserResult * (* OPMOCK_parser_result_new_CALLBACK)(int calls);
void parser_result_new_MockWithCallback(OPMOCK_parser_result_new_CALLBACK callback);
void parser_result_new_VerifyMock();
void parser_result_free_ExpectAndReturn(ParserResult * result, OPMOCK_MATCHER match_result);
void parser_result_free_MockReset();
typedef void (* OPMOCK_parser_result_free_CALLBACK)(ParserResult * result, int calls);
void parser_result_free_MockWithCallback(OPMOCK_parser_result_free_CALLBACK callback);
void parser_result_free_VerifyMock();

#ifdef __cplusplus
}
#endif
#endif
