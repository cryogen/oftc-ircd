/* OPMOCK2 GENERATED CODE - DO NOT MODIFY */
#ifndef _CLIENT_STUB_H
#define _CLIENT_STUB_H

#include <client.h>
#include "opmock.h"

#ifdef __cplusplus
extern "C" {
#endif

void client_init_ExpectAndReturn();
void client_init_MockReset();
typedef void (* OPMOCK_client_init_CALLBACK)(int calls);
void client_init_MockWithCallback(OPMOCK_client_init_CALLBACK callback);
void client_init_VerifyMock();
void client_new_ExpectAndReturn(Client * to_return);
void client_new_MockReset();
typedef Client * (* OPMOCK_client_new_CALLBACK)(int calls);
void client_new_MockWithCallback(OPMOCK_client_new_CALLBACK callback);
void client_new_VerifyMock();
void client_free_ExpectAndReturn(Client * client, OPMOCK_MATCHER match_client);
void client_free_MockReset();
typedef void (* OPMOCK_client_free_CALLBACK)(Client * client, int calls);
void client_free_MockWithCallback(OPMOCK_client_free_CALLBACK callback);
void client_free_VerifyMock();
void client_accept_ExpectAndReturn(Client * client, uv_stream_t * handle, _Bool to_return, OPMOCK_MATCHER match_client, OPMOCK_MATCHER match_handle);
void client_accept_MockReset();
typedef _Bool (* OPMOCK_client_accept_CALLBACK)(Client * client, uv_stream_t * handle, int calls);
void client_accept_MockWithCallback(OPMOCK_client_accept_CALLBACK callback);
void client_accept_VerifyMock();

#ifdef __cplusplus
}
#endif
#endif
