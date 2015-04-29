/* OPMOCK2 GENERATED CODE - DO NOT MODIFY */
#ifndef _NETWORK_STUB_H
#define _NETWORK_STUB_H

#include <network.h>
#include "opmock.h"

#ifdef __cplusplus
extern "C" {
#endif

void network_address_from_ipstring_ExpectAndReturn(const char * ip, NetworkAddress * address, _Bool to_return, OPMOCK_MATCHER match_ip, OPMOCK_MATCHER match_address);
void network_address_from_ipstring_MockReset();
typedef _Bool (* OPMOCK_network_address_from_ipstring_CALLBACK)(const char * ip, NetworkAddress * address, int calls);
void network_address_from_ipstring_MockWithCallback(OPMOCK_network_address_from_ipstring_CALLBACK callback);
void network_address_from_ipstring_VerifyMock();
void network_address_from_ipstring_and_port_ExpectAndReturn(const char * ip, unsigned short port, NetworkAddress * address, _Bool to_return, OPMOCK_MATCHER match_ip, OPMOCK_MATCHER match_port, OPMOCK_MATCHER match_address);
void network_address_from_ipstring_and_port_MockReset();
typedef _Bool (* OPMOCK_network_address_from_ipstring_and_port_CALLBACK)(const char * ip, unsigned short port, NetworkAddress * address, int calls);
void network_address_from_ipstring_and_port_MockWithCallback(OPMOCK_network_address_from_ipstring_and_port_CALLBACK callback);
void network_address_from_ipstring_and_port_VerifyMock();
void network_ipstring_from_address_ExpectAndReturn(NetworkAddress * address, char * ip, size_t ipLen, _Bool to_return, OPMOCK_MATCHER match_address, OPMOCK_MATCHER match_ip, OPMOCK_MATCHER match_ipLen);
void network_ipstring_from_address_MockReset();
typedef _Bool (* OPMOCK_network_ipstring_from_address_CALLBACK)(NetworkAddress * address, char * ip, size_t ipLen, int calls);
void network_ipstring_from_address_MockWithCallback(OPMOCK_network_ipstring_from_address_CALLBACK callback);
void network_ipstring_from_address_VerifyMock();
void network_address_from_stream_ExpectAndReturn(uv_tcp_t * handle, NetworkAddress * address, _Bool to_return, OPMOCK_MATCHER match_handle, OPMOCK_MATCHER match_address);
void network_address_from_stream_MockReset();
typedef _Bool (* OPMOCK_network_address_from_stream_CALLBACK)(uv_tcp_t * handle, NetworkAddress * address, int calls);
void network_address_from_stream_MockWithCallback(OPMOCK_network_address_from_stream_CALLBACK callback);
void network_address_from_stream_VerifyMock();

#ifdef __cplusplus
}
#endif
#endif
