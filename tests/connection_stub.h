/* OPMOCK2 GENERATED CODE - DO NOT MODIFY */
#ifndef _CONNECTION_STUB_H
#define _CONNECTION_STUB_H

#include <connection.h>
#include "opmock.h"

#ifdef __cplusplus
extern "C" {
#endif

void connection_init_ExpectAndReturn();
void connection_init_MockReset();
typedef void (* OPMOCK_connection_init_CALLBACK)(int calls);
void connection_init_MockWithCallback(OPMOCK_connection_init_CALLBACK callback);
void connection_init_VerifyMock();
void connection_init_tls_ExpectAndReturn();
void connection_init_tls_MockReset();
typedef void (* OPMOCK_connection_init_tls_CALLBACK)(int calls);
void connection_init_tls_MockWithCallback(OPMOCK_connection_init_tls_CALLBACK callback);
void connection_init_tls_VerifyMock();
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
void connection_start_read_ExpectAndReturn(Client * client, OPMOCK_MATCHER match_client);
void connection_start_read_MockReset();
typedef void (* OPMOCK_connection_start_read_CALLBACK)(Client * client, int calls);
void connection_start_read_MockWithCallback(OPMOCK_connection_start_read_CALLBACK callback);
void connection_start_read_VerifyMock();

#ifdef __cplusplus
}
#endif
#endif
