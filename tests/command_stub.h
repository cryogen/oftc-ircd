/* OPMOCK2 GENERATED CODE - DO NOT MODIFY */
#ifndef _COMMAND_STUB_H
#define _COMMAND_STUB_H

#include <command.h>
#include "opmock.h"

#ifdef __cplusplus
extern "C" {
#endif

void command_init_ExpectAndReturn();
void command_init_MockReset();
typedef void (* OPMOCK_command_init_CALLBACK)(int calls);
void command_init_MockWithCallback(OPMOCK_command_init_CALLBACK callback);
void command_init_VerifyMock();
void command_new_ExpectAndReturn(Command * to_return);
void command_new_MockReset();
typedef Command * (* OPMOCK_command_new_CALLBACK)(int calls);
void command_new_MockWithCallback(OPMOCK_command_new_CALLBACK callback);
void command_new_VerifyMock();
void command_free_ExpectAndReturn(Command * arg1, OPMOCK_MATCHER match_arg1);
void command_free_MockReset();
typedef void (* OPMOCK_command_free_CALLBACK)(Command * arg1, int calls);
void command_free_MockWithCallback(OPMOCK_command_free_CALLBACK callback);
void command_free_VerifyMock();
void command_register_ExpectAndReturn(const char * arg1, CommandAccess arg2, CommandHandler arg3, int arg4, OPMOCK_MATCHER match_arg1, OPMOCK_MATCHER match_arg2, OPMOCK_MATCHER match_arg3, OPMOCK_MATCHER match_arg4);
void command_register_MockReset();
typedef void (* OPMOCK_command_register_CALLBACK)(const char * arg1, CommandAccess arg2, CommandHandler arg3, int arg4, int calls);
void command_register_MockWithCallback(OPMOCK_command_register_CALLBACK callback);
void command_register_VerifyMock();
void command_find_ExpectAndReturn(const char * arg1, Command * to_return, OPMOCK_MATCHER match_arg1);
void command_find_MockReset();
typedef Command * (* OPMOCK_command_find_CALLBACK)(const char * arg1, int calls);
void command_find_MockWithCallback(OPMOCK_command_find_CALLBACK callback);
void command_find_VerifyMock();

#ifdef __cplusplus
}
#endif
#endif
