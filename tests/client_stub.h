/* OPMOCK2 GENERATED CODE - DO NOT MODIFY */
#ifndef _CLIENT_STUB_H
#define _CLIENT_STUB_H

#include <client.h>
#include "opmock.h"

#ifdef __cplusplus
extern "C" {
#endif

void client_send_ExpectAndReturn();
void client_send_MockReset();
typedef void (* OPMOCK_client_send_CALLBACK)(int calls);
void client_send_MockWithCallback(OPMOCK_client_send_CALLBACK callback);
void client_send_VerifyMock();
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
void client_lookup_dns_ExpectAndReturn(Client * client, OPMOCK_MATCHER match_client);
void client_lookup_dns_MockReset();
typedef void (* OPMOCK_client_lookup_dns_CALLBACK)(Client * client, int calls);
void client_lookup_dns_MockWithCallback(OPMOCK_client_lookup_dns_CALLBACK callback);
void client_lookup_dns_VerifyMock();
void client_process_read_buffer_ExpectAndReturn(Client * client, OPMOCK_MATCHER match_client);
void client_process_read_buffer_MockReset();
typedef void (* OPMOCK_client_process_read_buffer_CALLBACK)(Client * client, int calls);
void client_process_read_buffer_MockWithCallback(OPMOCK_client_process_read_buffer_CALLBACK callback);
void client_process_read_buffer_VerifyMock();
void client_set_username_ExpectAndReturn(Client * client, const char * username, _Bool to_return, OPMOCK_MATCHER match_client, OPMOCK_MATCHER match_username);
void client_set_username_MockReset();
typedef _Bool (* OPMOCK_client_set_username_CALLBACK)(Client * client, const char * username, int calls);
void client_set_username_MockWithCallback(OPMOCK_client_set_username_CALLBACK callback);
void client_set_username_VerifyMock();
void client_set_nickname_ExpectAndReturn(Client * client, const char * nickname, _Bool to_return, OPMOCK_MATCHER match_client, OPMOCK_MATCHER match_nickname);
void client_set_nickname_MockReset();
typedef _Bool (* OPMOCK_client_set_nickname_CALLBACK)(Client * client, const char * nickname, int calls);
void client_set_nickname_MockWithCallback(OPMOCK_client_set_nickname_CALLBACK callback);
void client_set_nickname_VerifyMock();
void client_set_realname_ExpectAndReturn(Client * client, const char * realname, _Bool to_return, OPMOCK_MATCHER match_client, OPMOCK_MATCHER match_realname);
void client_set_realname_MockReset();
typedef _Bool (* OPMOCK_client_set_realname_CALLBACK)(Client * client, const char * realname, int calls);
void client_set_realname_MockWithCallback(OPMOCK_client_set_realname_CALLBACK callback);
void client_set_realname_VerifyMock();

#ifdef __cplusplus
}
#endif
#endif
