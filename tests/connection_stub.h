/* OPMOCK2 GENERATED CODE - DO NOT MODIFY */
#ifndef _CONNECTION_STUB_H
#define _CONNECTION_STUB_H

#include <connection.h>
#include "opmock.h"

#ifdef __cplusplus
extern "C" {
#endif

void connection_accept_ExpectAndReturn(uv_stream_t * handle, OPMOCK_MATCHER match_handle);
void connection_accept_MockReset();
typedef void (* OPMOCK_connection_accept_CALLBACK)(uv_stream_t * handle, int calls);
void connection_accept_MockWithCallback(OPMOCK_connection_accept_CALLBACK callback);
void connection_accept_VerifyMock();
void connection_send_ExpectAndReturn(Client * client, char * buffer, OPMOCK_MATCHER match_client, OPMOCK_MATCHER match_buffer);
void connection_send_MockReset();
typedef void (* OPMOCK_connection_send_CALLBACK)(Client * client, char * buffer, int calls);
void connection_send_MockWithCallback(OPMOCK_connection_send_CALLBACK callback);
void connection_send_VerifyMock();

#ifdef __cplusplus
}
#endif
#endif
