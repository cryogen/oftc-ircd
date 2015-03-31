/* OPMOCK2 GENERATED CODE - DO NOT MODIFY */
#ifndef _SERVER_STUB_H
#define _SERVER_STUB_H

#include <server.h>
#include "opmock.h"

#ifdef __cplusplus
extern "C" {
#endif

void server_init_ExpectAndReturn();
void server_init_MockReset();
typedef void (* OPMOCK_server_init_CALLBACK)(int calls);
void server_init_MockWithCallback(OPMOCK_server_init_CALLBACK callback);
void server_init_VerifyMock();
void server_get_this_server_ExpectAndReturn(Client * to_return);
void server_get_this_server_MockReset();
typedef Client * (* OPMOCK_server_get_this_server_CALLBACK)(int calls);
void server_get_this_server_MockWithCallback(OPMOCK_server_get_this_server_CALLBACK callback);
void server_get_this_server_VerifyMock();

#ifdef __cplusplus
}
#endif
#endif
