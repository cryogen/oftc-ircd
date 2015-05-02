/* OPMOCK2 GENERATED CODE - DO NOT MODIFY */
#ifndef _TLS_STUB_H
#define _TLS_STUB_H

#include <stdint.h>
#include <stddef.h>

#include <tls.h>
#include "opmock.h"

#ifdef __cplusplus
extern "C" {
#endif

void tls_init_ExpectAndReturn(int to_return);
void tls_init_MockReset();
typedef int (* OPMOCK_tls_init_CALLBACK)(int calls);
void tls_init_MockWithCallback(OPMOCK_tls_init_CALLBACK callback);
void tls_init_VerifyMock();
void tls_error_ExpectAndReturn(struct tls * _ctx, const char * to_return, OPMOCK_MATCHER match__ctx);
void tls_error_MockReset();
typedef const char * (* OPMOCK_tls_error_CALLBACK)(struct tls * _ctx, int calls);
void tls_error_MockWithCallback(OPMOCK_tls_error_CALLBACK callback);
void tls_error_VerifyMock();
void tls_config_new_ExpectAndReturn(struct tls_config * to_return);
void tls_config_new_MockReset();
typedef struct tls_config * (* OPMOCK_tls_config_new_CALLBACK)(int calls);
void tls_config_new_MockWithCallback(OPMOCK_tls_config_new_CALLBACK callback);
void tls_config_new_VerifyMock();
void tls_config_free_ExpectAndReturn(struct tls_config * _config, OPMOCK_MATCHER match__config);
void tls_config_free_MockReset();
typedef void (* OPMOCK_tls_config_free_CALLBACK)(struct tls_config * _config, int calls);
void tls_config_free_MockWithCallback(OPMOCK_tls_config_free_CALLBACK callback);
void tls_config_free_VerifyMock();
void tls_config_set_ca_file_ExpectAndReturn(struct tls_config * _config, const char * _ca_file, int to_return, OPMOCK_MATCHER match__config, OPMOCK_MATCHER match__ca_file);
void tls_config_set_ca_file_MockReset();
typedef int (* OPMOCK_tls_config_set_ca_file_CALLBACK)(struct tls_config * _config, const char * _ca_file, int calls);
void tls_config_set_ca_file_MockWithCallback(OPMOCK_tls_config_set_ca_file_CALLBACK callback);
void tls_config_set_ca_file_VerifyMock();
void tls_config_set_ca_path_ExpectAndReturn(struct tls_config * _config, const char * _ca_path, int to_return, OPMOCK_MATCHER match__config, OPMOCK_MATCHER match__ca_path);
void tls_config_set_ca_path_MockReset();
typedef int (* OPMOCK_tls_config_set_ca_path_CALLBACK)(struct tls_config * _config, const char * _ca_path, int calls);
void tls_config_set_ca_path_MockWithCallback(OPMOCK_tls_config_set_ca_path_CALLBACK callback);
void tls_config_set_ca_path_VerifyMock();
void tls_config_set_ca_mem_ExpectAndReturn(struct tls_config * _config, const uint8_t * _ca, size_t _len, int to_return, OPMOCK_MATCHER match__config, OPMOCK_MATCHER match__ca, OPMOCK_MATCHER match__len);
void tls_config_set_ca_mem_MockReset();
typedef int (* OPMOCK_tls_config_set_ca_mem_CALLBACK)(struct tls_config * _config, const uint8_t * _ca, size_t _len, int calls);
void tls_config_set_ca_mem_MockWithCallback(OPMOCK_tls_config_set_ca_mem_CALLBACK callback);
void tls_config_set_ca_mem_VerifyMock();
void tls_config_set_cert_file_ExpectAndReturn(struct tls_config * _config, const char * _cert_file, int to_return, OPMOCK_MATCHER match__config, OPMOCK_MATCHER match__cert_file);
void tls_config_set_cert_file_MockReset();
typedef int (* OPMOCK_tls_config_set_cert_file_CALLBACK)(struct tls_config * _config, const char * _cert_file, int calls);
void tls_config_set_cert_file_MockWithCallback(OPMOCK_tls_config_set_cert_file_CALLBACK callback);
void tls_config_set_cert_file_VerifyMock();
void tls_config_set_cert_mem_ExpectAndReturn(struct tls_config * _config, const uint8_t * _cert, size_t _len, int to_return, OPMOCK_MATCHER match__config, OPMOCK_MATCHER match__cert, OPMOCK_MATCHER match__len);
void tls_config_set_cert_mem_MockReset();
typedef int (* OPMOCK_tls_config_set_cert_mem_CALLBACK)(struct tls_config * _config, const uint8_t * _cert, size_t _len, int calls);
void tls_config_set_cert_mem_MockWithCallback(OPMOCK_tls_config_set_cert_mem_CALLBACK callback);
void tls_config_set_cert_mem_VerifyMock();
void tls_config_set_ciphers_ExpectAndReturn(struct tls_config * _config, const char * _ciphers, int to_return, OPMOCK_MATCHER match__config, OPMOCK_MATCHER match__ciphers);
void tls_config_set_ciphers_MockReset();
typedef int (* OPMOCK_tls_config_set_ciphers_CALLBACK)(struct tls_config * _config, const char * _ciphers, int calls);
void tls_config_set_ciphers_MockWithCallback(OPMOCK_tls_config_set_ciphers_CALLBACK callback);
void tls_config_set_ciphers_VerifyMock();
void tls_config_set_dheparams_ExpectAndReturn(struct tls_config * _config, const char * _params, int to_return, OPMOCK_MATCHER match__config, OPMOCK_MATCHER match__params);
void tls_config_set_dheparams_MockReset();
typedef int (* OPMOCK_tls_config_set_dheparams_CALLBACK)(struct tls_config * _config, const char * _params, int calls);
void tls_config_set_dheparams_MockWithCallback(OPMOCK_tls_config_set_dheparams_CALLBACK callback);
void tls_config_set_dheparams_VerifyMock();
void tls_config_set_ecdhecurve_ExpectAndReturn(struct tls_config * _config, const char * _name, int to_return, OPMOCK_MATCHER match__config, OPMOCK_MATCHER match__name);
void tls_config_set_ecdhecurve_MockReset();
typedef int (* OPMOCK_tls_config_set_ecdhecurve_CALLBACK)(struct tls_config * _config, const char * _name, int calls);
void tls_config_set_ecdhecurve_MockWithCallback(OPMOCK_tls_config_set_ecdhecurve_CALLBACK callback);
void tls_config_set_ecdhecurve_VerifyMock();
void tls_config_set_key_file_ExpectAndReturn(struct tls_config * _config, const char * _key_file, int to_return, OPMOCK_MATCHER match__config, OPMOCK_MATCHER match__key_file);
void tls_config_set_key_file_MockReset();
typedef int (* OPMOCK_tls_config_set_key_file_CALLBACK)(struct tls_config * _config, const char * _key_file, int calls);
void tls_config_set_key_file_MockWithCallback(OPMOCK_tls_config_set_key_file_CALLBACK callback);
void tls_config_set_key_file_VerifyMock();
void tls_config_set_key_mem_ExpectAndReturn(struct tls_config * _config, const uint8_t * _key, size_t _len, int to_return, OPMOCK_MATCHER match__config, OPMOCK_MATCHER match__key, OPMOCK_MATCHER match__len);
void tls_config_set_key_mem_MockReset();
typedef int (* OPMOCK_tls_config_set_key_mem_CALLBACK)(struct tls_config * _config, const uint8_t * _key, size_t _len, int calls);
void tls_config_set_key_mem_MockWithCallback(OPMOCK_tls_config_set_key_mem_CALLBACK callback);
void tls_config_set_key_mem_VerifyMock();
void tls_config_set_protocols_ExpectAndReturn(struct tls_config * _config, uint32_t _protocols, OPMOCK_MATCHER match__config, OPMOCK_MATCHER match__protocols);
void tls_config_set_protocols_MockReset();
typedef void (* OPMOCK_tls_config_set_protocols_CALLBACK)(struct tls_config * _config, uint32_t _protocols, int calls);
void tls_config_set_protocols_MockWithCallback(OPMOCK_tls_config_set_protocols_CALLBACK callback);
void tls_config_set_protocols_VerifyMock();
void tls_config_set_verify_depth_ExpectAndReturn(struct tls_config * _config, int _verify_depth, OPMOCK_MATCHER match__config, OPMOCK_MATCHER match__verify_depth);
void tls_config_set_verify_depth_MockReset();
typedef void (* OPMOCK_tls_config_set_verify_depth_CALLBACK)(struct tls_config * _config, int _verify_depth, int calls);
void tls_config_set_verify_depth_MockWithCallback(OPMOCK_tls_config_set_verify_depth_CALLBACK callback);
void tls_config_set_verify_depth_VerifyMock();
void tls_config_clear_keys_ExpectAndReturn(struct tls_config * _config, OPMOCK_MATCHER match__config);
void tls_config_clear_keys_MockReset();
typedef void (* OPMOCK_tls_config_clear_keys_CALLBACK)(struct tls_config * _config, int calls);
void tls_config_clear_keys_MockWithCallback(OPMOCK_tls_config_clear_keys_CALLBACK callback);
void tls_config_clear_keys_VerifyMock();
void tls_config_parse_protocols_ExpectAndReturn(uint32_t * _protocols, const char * _protostr, int to_return, OPMOCK_MATCHER match__protocols, OPMOCK_MATCHER match__protostr);
void tls_config_parse_protocols_MockReset();
typedef int (* OPMOCK_tls_config_parse_protocols_CALLBACK)(uint32_t * _protocols, const char * _protostr, int calls);
void tls_config_parse_protocols_MockWithCallback(OPMOCK_tls_config_parse_protocols_CALLBACK callback);
void tls_config_parse_protocols_VerifyMock();
void tls_config_insecure_noverifycert_ExpectAndReturn(struct tls_config * _config, OPMOCK_MATCHER match__config);
void tls_config_insecure_noverifycert_MockReset();
typedef void (* OPMOCK_tls_config_insecure_noverifycert_CALLBACK)(struct tls_config * _config, int calls);
void tls_config_insecure_noverifycert_MockWithCallback(OPMOCK_tls_config_insecure_noverifycert_CALLBACK callback);
void tls_config_insecure_noverifycert_VerifyMock();
void tls_config_insecure_noverifyname_ExpectAndReturn(struct tls_config * _config, OPMOCK_MATCHER match__config);
void tls_config_insecure_noverifyname_MockReset();
typedef void (* OPMOCK_tls_config_insecure_noverifyname_CALLBACK)(struct tls_config * _config, int calls);
void tls_config_insecure_noverifyname_MockWithCallback(OPMOCK_tls_config_insecure_noverifyname_CALLBACK callback);
void tls_config_insecure_noverifyname_VerifyMock();
void tls_config_verify_ExpectAndReturn(struct tls_config * _config, OPMOCK_MATCHER match__config);
void tls_config_verify_MockReset();
typedef void (* OPMOCK_tls_config_verify_CALLBACK)(struct tls_config * _config, int calls);
void tls_config_verify_MockWithCallback(OPMOCK_tls_config_verify_CALLBACK callback);
void tls_config_verify_VerifyMock();
void tls_client_ExpectAndReturn(struct tls * to_return);
void tls_client_MockReset();
typedef struct tls * (* OPMOCK_tls_client_CALLBACK)(int calls);
void tls_client_MockWithCallback(OPMOCK_tls_client_CALLBACK callback);
void tls_client_VerifyMock();
void tls_server_ExpectAndReturn(struct tls * to_return);
void tls_server_MockReset();
typedef struct tls * (* OPMOCK_tls_server_CALLBACK)(int calls);
void tls_server_MockWithCallback(OPMOCK_tls_server_CALLBACK callback);
void tls_server_VerifyMock();
void tls_configure_ExpectAndReturn(struct tls * _ctx, struct tls_config * _config, int to_return, OPMOCK_MATCHER match__ctx, OPMOCK_MATCHER match__config);
void tls_configure_MockReset();
typedef int (* OPMOCK_tls_configure_CALLBACK)(struct tls * _ctx, struct tls_config * _config, int calls);
void tls_configure_MockWithCallback(OPMOCK_tls_configure_CALLBACK callback);
void tls_configure_VerifyMock();
void tls_reset_ExpectAndReturn(struct tls * _ctx, OPMOCK_MATCHER match__ctx);
void tls_reset_MockReset();
typedef void (* OPMOCK_tls_reset_CALLBACK)(struct tls * _ctx, int calls);
void tls_reset_MockWithCallback(OPMOCK_tls_reset_CALLBACK callback);
void tls_reset_VerifyMock();
void tls_free_ExpectAndReturn(struct tls * _ctx, OPMOCK_MATCHER match__ctx);
void tls_free_MockReset();
typedef void (* OPMOCK_tls_free_CALLBACK)(struct tls * _ctx, int calls);
void tls_free_MockWithCallback(OPMOCK_tls_free_CALLBACK callback);
void tls_free_VerifyMock();
void tls_accept_fds_ExpectAndReturn(struct tls * _ctx, struct tls ** _cctx, int _fd_read, int _fd_write, int to_return, OPMOCK_MATCHER match__ctx, OPMOCK_MATCHER match__cctx, OPMOCK_MATCHER match__fd_read, OPMOCK_MATCHER match__fd_write);
void tls_accept_fds_MockReset();
typedef int (* OPMOCK_tls_accept_fds_CALLBACK)(struct tls * _ctx, struct tls ** _cctx, int _fd_read, int _fd_write, int calls);
void tls_accept_fds_MockWithCallback(OPMOCK_tls_accept_fds_CALLBACK callback);
void tls_accept_fds_VerifyMock();
void tls_accept_socket_ExpectAndReturn(struct tls * _ctx, struct tls ** _cctx, int _socket, int to_return, OPMOCK_MATCHER match__ctx, OPMOCK_MATCHER match__cctx, OPMOCK_MATCHER match__socket);
void tls_accept_socket_MockReset();
typedef int (* OPMOCK_tls_accept_socket_CALLBACK)(struct tls * _ctx, struct tls ** _cctx, int _socket, int calls);
void tls_accept_socket_MockWithCallback(OPMOCK_tls_accept_socket_CALLBACK callback);
void tls_accept_socket_VerifyMock();
void tls_connect_ExpectAndReturn(struct tls * _ctx, const char * _host, const char * _port, int to_return, OPMOCK_MATCHER match__ctx, OPMOCK_MATCHER match__host, OPMOCK_MATCHER match__port);
void tls_connect_MockReset();
typedef int (* OPMOCK_tls_connect_CALLBACK)(struct tls * _ctx, const char * _host, const char * _port, int calls);
void tls_connect_MockWithCallback(OPMOCK_tls_connect_CALLBACK callback);
void tls_connect_VerifyMock();
void tls_connect_fds_ExpectAndReturn(struct tls * _ctx, int _fd_read, int _fd_write, const char * _servername, int to_return, OPMOCK_MATCHER match__ctx, OPMOCK_MATCHER match__fd_read, OPMOCK_MATCHER match__fd_write, OPMOCK_MATCHER match__servername);
void tls_connect_fds_MockReset();
typedef int (* OPMOCK_tls_connect_fds_CALLBACK)(struct tls * _ctx, int _fd_read, int _fd_write, const char * _servername, int calls);
void tls_connect_fds_MockWithCallback(OPMOCK_tls_connect_fds_CALLBACK callback);
void tls_connect_fds_VerifyMock();
void tls_connect_servername_ExpectAndReturn(struct tls * _ctx, const char * _host, const char * _port, const char * _servername, int to_return, OPMOCK_MATCHER match__ctx, OPMOCK_MATCHER match__host, OPMOCK_MATCHER match__port, OPMOCK_MATCHER match__servername);
void tls_connect_servername_MockReset();
typedef int (* OPMOCK_tls_connect_servername_CALLBACK)(struct tls * _ctx, const char * _host, const char * _port, const char * _servername, int calls);
void tls_connect_servername_MockWithCallback(OPMOCK_tls_connect_servername_CALLBACK callback);
void tls_connect_servername_VerifyMock();
void tls_connect_socket_ExpectAndReturn(struct tls * _ctx, int _s, const char * _servername, int to_return, OPMOCK_MATCHER match__ctx, OPMOCK_MATCHER match__s, OPMOCK_MATCHER match__servername);
void tls_connect_socket_MockReset();
typedef int (* OPMOCK_tls_connect_socket_CALLBACK)(struct tls * _ctx, int _s, const char * _servername, int calls);
void tls_connect_socket_MockWithCallback(OPMOCK_tls_connect_socket_CALLBACK callback);
void tls_connect_socket_VerifyMock();
void tls_read_ExpectAndReturn(struct tls * _ctx, void * _buf, size_t _buflen, size_t * _outlen, int to_return, OPMOCK_MATCHER match__ctx, OPMOCK_MATCHER match__buf, OPMOCK_MATCHER match__buflen, OPMOCK_MATCHER match__outlen);
void tls_read_MockReset();
typedef int (* OPMOCK_tls_read_CALLBACK)(struct tls * _ctx, void * _buf, size_t _buflen, size_t * _outlen, int calls);
void tls_read_MockWithCallback(OPMOCK_tls_read_CALLBACK callback);
void tls_read_VerifyMock();
void tls_write_ExpectAndReturn(struct tls * _ctx, const void * _buf, size_t _buflen, size_t * _outlen, int to_return, OPMOCK_MATCHER match__ctx, OPMOCK_MATCHER match__buf, OPMOCK_MATCHER match__buflen, OPMOCK_MATCHER match__outlen);
void tls_write_MockReset();
typedef int (* OPMOCK_tls_write_CALLBACK)(struct tls * _ctx, const void * _buf, size_t _buflen, size_t * _outlen, int calls);
void tls_write_MockWithCallback(OPMOCK_tls_write_CALLBACK callback);
void tls_write_VerifyMock();
void tls_close_ExpectAndReturn(struct tls * _ctx, int to_return, OPMOCK_MATCHER match__ctx);
void tls_close_MockReset();
typedef int (* OPMOCK_tls_close_CALLBACK)(struct tls * _ctx, int calls);
void tls_close_MockWithCallback(OPMOCK_tls_close_CALLBACK callback);
void tls_close_VerifyMock();
void tls_load_file_ExpectAndReturn(const char * _file, size_t * _len, char * _password, uint8_t * to_return, OPMOCK_MATCHER match__file, OPMOCK_MATCHER match__len, OPMOCK_MATCHER match__password);
void tls_load_file_MockReset();
typedef uint8_t * (* OPMOCK_tls_load_file_CALLBACK)(const char * _file, size_t * _len, char * _password, int calls);
void tls_load_file_MockWithCallback(OPMOCK_tls_load_file_CALLBACK callback);
void tls_load_file_VerifyMock();

#ifdef __cplusplus
}
#endif
#endif
