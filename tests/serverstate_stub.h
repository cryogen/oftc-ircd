/* OPMOCK2 GENERATED CODE - DO NOT MODIFY */
#ifndef _SERVERSTATE_STUB_H
#define _SERVERSTATE_STUB_H

#include <serverstate.h>
#include "opmock.h"

#ifdef __cplusplus
extern "C" {
#endif

void serverstate_get_config_path_ExpectAndReturn(const char * to_return);
void serverstate_get_config_path_MockReset();
typedef const char * (* OPMOCK_serverstate_get_config_path_CALLBACK)(int calls);
void serverstate_get_config_path_MockWithCallback(OPMOCK_serverstate_get_config_path_CALLBACK callback);
void serverstate_get_config_path_VerifyMock();
void serverstate_get_event_loop_ExpectAndReturn(uv_loop_t * to_return);
void serverstate_get_event_loop_MockReset();
typedef uv_loop_t * (* OPMOCK_serverstate_get_event_loop_CALLBACK)(int calls);
void serverstate_get_event_loop_MockWithCallback(OPMOCK_serverstate_get_event_loop_CALLBACK callback);
void serverstate_get_event_loop_VerifyMock();
void serverstate_set_config_path_ExpectAndReturn(const char * arg1, OPMOCK_MATCHER match_arg1);
void serverstate_set_config_path_MockReset();
typedef void (* OPMOCK_serverstate_set_config_path_CALLBACK)(const char * arg1, int calls);
void serverstate_set_config_path_MockWithCallback(OPMOCK_serverstate_set_config_path_CALLBACK callback);
void serverstate_set_config_path_VerifyMock();
void serverstate_set_event_loop_ExpectAndReturn(uv_loop_t * arg1, OPMOCK_MATCHER match_arg1);
void serverstate_set_event_loop_MockReset();
typedef void (* OPMOCK_serverstate_set_event_loop_CALLBACK)(uv_loop_t * arg1, int calls);
void serverstate_set_event_loop_MockWithCallback(OPMOCK_serverstate_set_event_loop_CALLBACK callback);
void serverstate_set_event_loop_VerifyMock();

#ifdef __cplusplus
}
#endif
#endif
