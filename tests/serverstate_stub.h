/* OPMOCK2 GENERATED CODE - DO NOT MODIFY */
#ifndef _SERVERSTATE_STUB_H
#define _SERVERSTATE_STUB_H

#include <serverstate.h>
#include "opmock.h"

#ifdef __cplusplus
extern "C" {
#endif

void serverstate_set_config_path_ExpectAndReturn(const char * arg1, OPMOCK_MATCHER match_arg1);
void serverstate_set_config_path_MockReset();
typedef void (* OPMOCK_serverstate_set_config_path_CALLBACK)(const char * arg1, int calls);
void serverstate_set_config_path_MockWithCallback(OPMOCK_serverstate_set_config_path_CALLBACK callback);
void serverstate_set_config_path_VerifyMock();
void serverstate_get_config_path_ExpectAndReturn(const char * to_return);
void serverstate_get_config_path_MockReset();
typedef const char * (* OPMOCK_serverstate_get_config_path_CALLBACK)(int calls);
void serverstate_get_config_path_MockWithCallback(OPMOCK_serverstate_get_config_path_CALLBACK callback);
void serverstate_get_config_path_VerifyMock();

#ifdef __cplusplus
}
#endif
#endif
