/* OPMOCK2 GENERATED CODE - DO NOT MODIFY */
#include "tls_stub.h"
#include <stdio.h>
#include <string.h>

typedef struct
{
    int to_return;
    char check_params;
} tls_init_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_tls_init_CALLBACK callback;
    tls_init_call calls[MAX_FUNC_CALL];
} tls_init_struct;

static tls_init_struct tls_init_struct_inst;

typedef struct
{
    void * _ctx;
    OPMOCK_MATCHER match__ctx;
     char * to_return;
    char check_params;
} tls_error_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_tls_error_CALLBACK callback;
    tls_error_call calls[MAX_FUNC_CALL];
} tls_error_struct;

static tls_error_struct tls_error_struct_inst;

typedef struct
{
    struct tls_config * to_return;
    char check_params;
} tls_config_new_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_tls_config_new_CALLBACK callback;
    tls_config_new_call calls[MAX_FUNC_CALL];
} tls_config_new_struct;

static tls_config_new_struct tls_config_new_struct_inst;

typedef struct
{
    void * _config;
    OPMOCK_MATCHER match__config;
    char check_params;
} tls_config_free_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_tls_config_free_CALLBACK callback;
    tls_config_free_call calls[MAX_FUNC_CALL];
} tls_config_free_struct;

static tls_config_free_struct tls_config_free_struct_inst;

typedef struct
{
    void * _config;
    void * _ca_file;
    OPMOCK_MATCHER match__config;
    OPMOCK_MATCHER match__ca_file;
    int to_return;
    char check_params;
} tls_config_set_ca_file_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_tls_config_set_ca_file_CALLBACK callback;
    tls_config_set_ca_file_call calls[MAX_FUNC_CALL];
} tls_config_set_ca_file_struct;

static tls_config_set_ca_file_struct tls_config_set_ca_file_struct_inst;

typedef struct
{
    void * _config;
    void * _ca_path;
    OPMOCK_MATCHER match__config;
    OPMOCK_MATCHER match__ca_path;
    int to_return;
    char check_params;
} tls_config_set_ca_path_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_tls_config_set_ca_path_CALLBACK callback;
    tls_config_set_ca_path_call calls[MAX_FUNC_CALL];
} tls_config_set_ca_path_struct;

static tls_config_set_ca_path_struct tls_config_set_ca_path_struct_inst;

typedef struct
{
    void * _config;
    void * _ca;
    unsigned long _len;
    OPMOCK_MATCHER match__config;
    OPMOCK_MATCHER match__ca;
    OPMOCK_MATCHER match__len;
    int to_return;
    char check_params;
} tls_config_set_ca_mem_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_tls_config_set_ca_mem_CALLBACK callback;
    tls_config_set_ca_mem_call calls[MAX_FUNC_CALL];
} tls_config_set_ca_mem_struct;

static tls_config_set_ca_mem_struct tls_config_set_ca_mem_struct_inst;

typedef struct
{
    void * _config;
    void * _cert_file;
    OPMOCK_MATCHER match__config;
    OPMOCK_MATCHER match__cert_file;
    int to_return;
    char check_params;
} tls_config_set_cert_file_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_tls_config_set_cert_file_CALLBACK callback;
    tls_config_set_cert_file_call calls[MAX_FUNC_CALL];
} tls_config_set_cert_file_struct;

static tls_config_set_cert_file_struct tls_config_set_cert_file_struct_inst;

typedef struct
{
    void * _config;
    void * _cert;
    unsigned long _len;
    OPMOCK_MATCHER match__config;
    OPMOCK_MATCHER match__cert;
    OPMOCK_MATCHER match__len;
    int to_return;
    char check_params;
} tls_config_set_cert_mem_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_tls_config_set_cert_mem_CALLBACK callback;
    tls_config_set_cert_mem_call calls[MAX_FUNC_CALL];
} tls_config_set_cert_mem_struct;

static tls_config_set_cert_mem_struct tls_config_set_cert_mem_struct_inst;

typedef struct
{
    void * _config;
    void * _ciphers;
    OPMOCK_MATCHER match__config;
    OPMOCK_MATCHER match__ciphers;
    int to_return;
    char check_params;
} tls_config_set_ciphers_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_tls_config_set_ciphers_CALLBACK callback;
    tls_config_set_ciphers_call calls[MAX_FUNC_CALL];
} tls_config_set_ciphers_struct;

static tls_config_set_ciphers_struct tls_config_set_ciphers_struct_inst;

typedef struct
{
    void * _config;
    void * _params;
    OPMOCK_MATCHER match__config;
    OPMOCK_MATCHER match__params;
    int to_return;
    char check_params;
} tls_config_set_dheparams_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_tls_config_set_dheparams_CALLBACK callback;
    tls_config_set_dheparams_call calls[MAX_FUNC_CALL];
} tls_config_set_dheparams_struct;

static tls_config_set_dheparams_struct tls_config_set_dheparams_struct_inst;

typedef struct
{
    void * _config;
    void * _name;
    OPMOCK_MATCHER match__config;
    OPMOCK_MATCHER match__name;
    int to_return;
    char check_params;
} tls_config_set_ecdhecurve_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_tls_config_set_ecdhecurve_CALLBACK callback;
    tls_config_set_ecdhecurve_call calls[MAX_FUNC_CALL];
} tls_config_set_ecdhecurve_struct;

static tls_config_set_ecdhecurve_struct tls_config_set_ecdhecurve_struct_inst;

typedef struct
{
    void * _config;
    void * _key_file;
    OPMOCK_MATCHER match__config;
    OPMOCK_MATCHER match__key_file;
    int to_return;
    char check_params;
} tls_config_set_key_file_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_tls_config_set_key_file_CALLBACK callback;
    tls_config_set_key_file_call calls[MAX_FUNC_CALL];
} tls_config_set_key_file_struct;

static tls_config_set_key_file_struct tls_config_set_key_file_struct_inst;

typedef struct
{
    void * _config;
    void * _key;
    unsigned long _len;
    OPMOCK_MATCHER match__config;
    OPMOCK_MATCHER match__key;
    OPMOCK_MATCHER match__len;
    int to_return;
    char check_params;
} tls_config_set_key_mem_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_tls_config_set_key_mem_CALLBACK callback;
    tls_config_set_key_mem_call calls[MAX_FUNC_CALL];
} tls_config_set_key_mem_struct;

static tls_config_set_key_mem_struct tls_config_set_key_mem_struct_inst;

typedef struct
{
    void * _config;
    unsigned int _protocols;
    OPMOCK_MATCHER match__config;
    OPMOCK_MATCHER match__protocols;
    char check_params;
} tls_config_set_protocols_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_tls_config_set_protocols_CALLBACK callback;
    tls_config_set_protocols_call calls[MAX_FUNC_CALL];
} tls_config_set_protocols_struct;

static tls_config_set_protocols_struct tls_config_set_protocols_struct_inst;

typedef struct
{
    void * _config;
    int _verify_depth;
    OPMOCK_MATCHER match__config;
    OPMOCK_MATCHER match__verify_depth;
    char check_params;
} tls_config_set_verify_depth_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_tls_config_set_verify_depth_CALLBACK callback;
    tls_config_set_verify_depth_call calls[MAX_FUNC_CALL];
} tls_config_set_verify_depth_struct;

static tls_config_set_verify_depth_struct tls_config_set_verify_depth_struct_inst;

typedef struct
{
    void * _config;
    OPMOCK_MATCHER match__config;
    char check_params;
} tls_config_clear_keys_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_tls_config_clear_keys_CALLBACK callback;
    tls_config_clear_keys_call calls[MAX_FUNC_CALL];
} tls_config_clear_keys_struct;

static tls_config_clear_keys_struct tls_config_clear_keys_struct_inst;

typedef struct
{
    void * _protocols;
    void * _protostr;
    OPMOCK_MATCHER match__protocols;
    OPMOCK_MATCHER match__protostr;
    int to_return;
    char check_params;
} tls_config_parse_protocols_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_tls_config_parse_protocols_CALLBACK callback;
    tls_config_parse_protocols_call calls[MAX_FUNC_CALL];
} tls_config_parse_protocols_struct;

static tls_config_parse_protocols_struct tls_config_parse_protocols_struct_inst;

typedef struct
{
    void * _config;
    OPMOCK_MATCHER match__config;
    char check_params;
} tls_config_insecure_noverifycert_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_tls_config_insecure_noverifycert_CALLBACK callback;
    tls_config_insecure_noverifycert_call calls[MAX_FUNC_CALL];
} tls_config_insecure_noverifycert_struct;

static tls_config_insecure_noverifycert_struct tls_config_insecure_noverifycert_struct_inst;

typedef struct
{
    void * _config;
    OPMOCK_MATCHER match__config;
    char check_params;
} tls_config_insecure_noverifyname_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_tls_config_insecure_noverifyname_CALLBACK callback;
    tls_config_insecure_noverifyname_call calls[MAX_FUNC_CALL];
} tls_config_insecure_noverifyname_struct;

static tls_config_insecure_noverifyname_struct tls_config_insecure_noverifyname_struct_inst;

typedef struct
{
    void * _config;
    OPMOCK_MATCHER match__config;
    char check_params;
} tls_config_verify_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_tls_config_verify_CALLBACK callback;
    tls_config_verify_call calls[MAX_FUNC_CALL];
} tls_config_verify_struct;

static tls_config_verify_struct tls_config_verify_struct_inst;

typedef struct
{
    struct tls * to_return;
    char check_params;
} tls_client_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_tls_client_CALLBACK callback;
    tls_client_call calls[MAX_FUNC_CALL];
} tls_client_struct;

static tls_client_struct tls_client_struct_inst;

typedef struct
{
    struct tls * to_return;
    char check_params;
} tls_server_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_tls_server_CALLBACK callback;
    tls_server_call calls[MAX_FUNC_CALL];
} tls_server_struct;

static tls_server_struct tls_server_struct_inst;

typedef struct
{
    void * _ctx;
    void * _config;
    OPMOCK_MATCHER match__ctx;
    OPMOCK_MATCHER match__config;
    int to_return;
    char check_params;
} tls_configure_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_tls_configure_CALLBACK callback;
    tls_configure_call calls[MAX_FUNC_CALL];
} tls_configure_struct;

static tls_configure_struct tls_configure_struct_inst;

typedef struct
{
    void * _ctx;
    OPMOCK_MATCHER match__ctx;
    char check_params;
} tls_reset_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_tls_reset_CALLBACK callback;
    tls_reset_call calls[MAX_FUNC_CALL];
} tls_reset_struct;

static tls_reset_struct tls_reset_struct_inst;

typedef struct
{
    void * _ctx;
    OPMOCK_MATCHER match__ctx;
    char check_params;
} tls_free_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_tls_free_CALLBACK callback;
    tls_free_call calls[MAX_FUNC_CALL];
} tls_free_struct;

static tls_free_struct tls_free_struct_inst;

typedef struct
{
    void * _ctx;
    void * _cctx;
    int _fd_read;
    int _fd_write;
    OPMOCK_MATCHER match__ctx;
    OPMOCK_MATCHER match__cctx;
    OPMOCK_MATCHER match__fd_read;
    OPMOCK_MATCHER match__fd_write;
    int to_return;
    char check_params;
} tls_accept_fds_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_tls_accept_fds_CALLBACK callback;
    tls_accept_fds_call calls[MAX_FUNC_CALL];
} tls_accept_fds_struct;

static tls_accept_fds_struct tls_accept_fds_struct_inst;

typedef struct
{
    void * _ctx;
    void * _cctx;
    int _socket;
    OPMOCK_MATCHER match__ctx;
    OPMOCK_MATCHER match__cctx;
    OPMOCK_MATCHER match__socket;
    int to_return;
    char check_params;
} tls_accept_socket_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_tls_accept_socket_CALLBACK callback;
    tls_accept_socket_call calls[MAX_FUNC_CALL];
} tls_accept_socket_struct;

static tls_accept_socket_struct tls_accept_socket_struct_inst;

typedef struct
{
    void * _ctx;
    void * _host;
    void * _port;
    OPMOCK_MATCHER match__ctx;
    OPMOCK_MATCHER match__host;
    OPMOCK_MATCHER match__port;
    int to_return;
    char check_params;
} tls_connect_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_tls_connect_CALLBACK callback;
    tls_connect_call calls[MAX_FUNC_CALL];
} tls_connect_struct;

static tls_connect_struct tls_connect_struct_inst;

typedef struct
{
    void * _ctx;
    int _fd_read;
    int _fd_write;
    void * _servername;
    OPMOCK_MATCHER match__ctx;
    OPMOCK_MATCHER match__fd_read;
    OPMOCK_MATCHER match__fd_write;
    OPMOCK_MATCHER match__servername;
    int to_return;
    char check_params;
} tls_connect_fds_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_tls_connect_fds_CALLBACK callback;
    tls_connect_fds_call calls[MAX_FUNC_CALL];
} tls_connect_fds_struct;

static tls_connect_fds_struct tls_connect_fds_struct_inst;

typedef struct
{
    void * _ctx;
    void * _host;
    void * _port;
    void * _servername;
    OPMOCK_MATCHER match__ctx;
    OPMOCK_MATCHER match__host;
    OPMOCK_MATCHER match__port;
    OPMOCK_MATCHER match__servername;
    int to_return;
    char check_params;
} tls_connect_servername_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_tls_connect_servername_CALLBACK callback;
    tls_connect_servername_call calls[MAX_FUNC_CALL];
} tls_connect_servername_struct;

static tls_connect_servername_struct tls_connect_servername_struct_inst;

typedef struct
{
    void * _ctx;
    int _s;
    void * _servername;
    OPMOCK_MATCHER match__ctx;
    OPMOCK_MATCHER match__s;
    OPMOCK_MATCHER match__servername;
    int to_return;
    char check_params;
} tls_connect_socket_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_tls_connect_socket_CALLBACK callback;
    tls_connect_socket_call calls[MAX_FUNC_CALL];
} tls_connect_socket_struct;

static tls_connect_socket_struct tls_connect_socket_struct_inst;

typedef struct
{
    void * _ctx;
    void * _buf;
    unsigned long _buflen;
    void * _outlen;
    OPMOCK_MATCHER match__ctx;
    OPMOCK_MATCHER match__buf;
    OPMOCK_MATCHER match__buflen;
    OPMOCK_MATCHER match__outlen;
    int to_return;
    char check_params;
} tls_read_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_tls_read_CALLBACK callback;
    tls_read_call calls[MAX_FUNC_CALL];
} tls_read_struct;

static tls_read_struct tls_read_struct_inst;

typedef struct
{
    void * _ctx;
    void * _buf;
    unsigned long _buflen;
    void * _outlen;
    OPMOCK_MATCHER match__ctx;
    OPMOCK_MATCHER match__buf;
    OPMOCK_MATCHER match__buflen;
    OPMOCK_MATCHER match__outlen;
    int to_return;
    char check_params;
} tls_write_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_tls_write_CALLBACK callback;
    tls_write_call calls[MAX_FUNC_CALL];
} tls_write_struct;

static tls_write_struct tls_write_struct_inst;

typedef struct
{
    void * _ctx;
    OPMOCK_MATCHER match__ctx;
    int to_return;
    char check_params;
} tls_close_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_tls_close_CALLBACK callback;
    tls_close_call calls[MAX_FUNC_CALL];
} tls_close_struct;

static tls_close_struct tls_close_struct_inst;

typedef struct
{
    void * _file;
    void * _len;
    void * _password;
    OPMOCK_MATCHER match__file;
    OPMOCK_MATCHER match__len;
    OPMOCK_MATCHER match__password;
    unsigned char * to_return;
    char check_params;
} tls_load_file_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_tls_load_file_CALLBACK callback;
    tls_load_file_call calls[MAX_FUNC_CALL];
} tls_load_file_struct;

static tls_load_file_struct tls_load_file_struct_inst;

typedef struct
{
    void * _ctx;
    void * _buf;
    unsigned long _buflen;
    OPMOCK_MATCHER match__ctx;
    OPMOCK_MATCHER match__buf;
    OPMOCK_MATCHER match__buflen;
    int to_return;
    char check_params;
} tls_get_cert_fingerprint_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_tls_get_cert_fingerprint_CALLBACK callback;
    tls_get_cert_fingerprint_call calls[MAX_FUNC_CALL];
} tls_get_cert_fingerprint_struct;

static tls_get_cert_fingerprint_struct tls_get_cert_fingerprint_struct_inst;

static void opmock_reset_all_mocks_in_this_header()
{
    tls_init_MockReset();
    tls_error_MockReset();
    tls_config_new_MockReset();
    tls_config_free_MockReset();
    tls_config_set_ca_file_MockReset();
    tls_config_set_ca_path_MockReset();
    tls_config_set_ca_mem_MockReset();
    tls_config_set_cert_file_MockReset();
    tls_config_set_cert_mem_MockReset();
    tls_config_set_ciphers_MockReset();
    tls_config_set_dheparams_MockReset();
    tls_config_set_ecdhecurve_MockReset();
    tls_config_set_key_file_MockReset();
    tls_config_set_key_mem_MockReset();
    tls_config_set_protocols_MockReset();
    tls_config_set_verify_depth_MockReset();
    tls_config_clear_keys_MockReset();
    tls_config_parse_protocols_MockReset();
    tls_config_insecure_noverifycert_MockReset();
    tls_config_insecure_noverifyname_MockReset();
    tls_config_verify_MockReset();
    tls_client_MockReset();
    tls_server_MockReset();
    tls_configure_MockReset();
    tls_reset_MockReset();
    tls_free_MockReset();
    tls_accept_fds_MockReset();
    tls_accept_socket_MockReset();
    tls_connect_MockReset();
    tls_connect_fds_MockReset();
    tls_connect_servername_MockReset();
    tls_connect_socket_MockReset();
    tls_read_MockReset();
    tls_write_MockReset();
    tls_close_MockReset();
    tls_load_file_MockReset();
    tls_get_cert_fingerprint_MockReset();
}

static void opmock_verify_all_mocks_in_this_header()
{
    tls_init_VerifyMock();
    tls_error_VerifyMock();
    tls_config_new_VerifyMock();
    tls_config_free_VerifyMock();
    tls_config_set_ca_file_VerifyMock();
    tls_config_set_ca_path_VerifyMock();
    tls_config_set_ca_mem_VerifyMock();
    tls_config_set_cert_file_VerifyMock();
    tls_config_set_cert_mem_VerifyMock();
    tls_config_set_ciphers_VerifyMock();
    tls_config_set_dheparams_VerifyMock();
    tls_config_set_ecdhecurve_VerifyMock();
    tls_config_set_key_file_VerifyMock();
    tls_config_set_key_mem_VerifyMock();
    tls_config_set_protocols_VerifyMock();
    tls_config_set_verify_depth_VerifyMock();
    tls_config_clear_keys_VerifyMock();
    tls_config_parse_protocols_VerifyMock();
    tls_config_insecure_noverifycert_VerifyMock();
    tls_config_insecure_noverifyname_VerifyMock();
    tls_config_verify_VerifyMock();
    tls_client_VerifyMock();
    tls_server_VerifyMock();
    tls_configure_VerifyMock();
    tls_reset_VerifyMock();
    tls_free_VerifyMock();
    tls_accept_fds_VerifyMock();
    tls_accept_socket_VerifyMock();
    tls_connect_VerifyMock();
    tls_connect_fds_VerifyMock();
    tls_connect_servername_VerifyMock();
    tls_connect_socket_VerifyMock();
    tls_read_VerifyMock();
    tls_write_VerifyMock();
    tls_close_VerifyMock();
    tls_load_file_VerifyMock();
    tls_get_cert_fingerprint_VerifyMock();
}

int tls_init()
{
    int default_res = (int)tls_init_struct_inst.calls[0].to_return;
    int opmock_i;
    tls_init_struct_inst.actualCalls++;

    if (tls_init_struct_inst.callback != NULL)
    {
        return tls_init_struct_inst.callback (tls_init_struct_inst.actualCalls);
    }
    if (tls_init_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'tls_init', returning random value.");
        return default_res;
    }

    if(strcmp(opmock_get_current_call(), "int tls_init ()") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'int tls_init()',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (tls_init_struct_inst.calls[0].check_params == 1) {
    }

    for(opmock_i = 1; opmock_i < tls_init_struct_inst.expectedCalls; opmock_i++) {
        tls_init_struct_inst.calls[opmock_i - 1] = tls_init_struct_inst.calls[opmock_i];
    }

    tls_init_struct_inst.expectedCalls--;
    return default_res;
}

void tls_init_MockReset()
{
    tls_init_struct_inst.expectedCalls = 0;
    tls_init_struct_inst.actualCalls = 0;
    tls_init_struct_inst.callback = NULL;
}

void tls_init_MockWithCallback(OPMOCK_tls_init_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    tls_init_struct_inst.callback = callback;
    tls_init_struct_inst.expectedCalls = 0;
    tls_init_struct_inst.actualCalls = 0;
}

void tls_init_VerifyMock()
{
    if (tls_init_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'tls_init'",tls_init_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void tls_init_ExpectAndReturn (int to_return)
{
    if(tls_init_struct_inst.callback != NULL)
    {
        tls_init_MockReset ();
    }

    if(tls_init_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting tls_init_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"int tls_init ()");
    tls_init_struct_inst.calls[tls_init_struct_inst.expectedCalls].to_return = (int) to_return;
    tls_init_struct_inst.calls[tls_init_struct_inst.expectedCalls].check_params = 1;
    tls_init_struct_inst.expectedCalls++;
}

const char * tls_error(struct tls * _ctx)
{
    const char * default_res = (const char *)tls_error_struct_inst.calls[0].to_return;
    int opmock_i;
    tls_error_struct_inst.actualCalls++;

    if (tls_error_struct_inst.callback != NULL)
    {
        return tls_error_struct_inst.callback (_ctx, tls_error_struct_inst.actualCalls);
    }
    if (tls_error_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'tls_error', returning random value.");
        return default_res;
    }

    if(strcmp(opmock_get_current_call(), "const char * tls_error (struct tls * _ctx)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'const char * tls_error(struct tls * _ctx)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (tls_error_struct_inst.calls[0].check_params == 1) {
        if(tls_error_struct_inst.calls[0].match__ctx) {
            void * val1 = (void *) &tls_error_struct_inst.calls[0]._ctx;
            void * val2 = (void *) &_ctx;
            int match_result = tls_error_struct_inst.calls[0].match__ctx(val1, val2, "_ctx", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'tls_error', %s",tls_error_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < tls_error_struct_inst.expectedCalls; opmock_i++) {
        tls_error_struct_inst.calls[opmock_i - 1] = tls_error_struct_inst.calls[opmock_i];
    }

    tls_error_struct_inst.expectedCalls--;
    return default_res;
}

void tls_error_MockReset()
{
    tls_error_struct_inst.expectedCalls = 0;
    tls_error_struct_inst.actualCalls = 0;
    tls_error_struct_inst.callback = NULL;
}

void tls_error_MockWithCallback(OPMOCK_tls_error_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    tls_error_struct_inst.callback = callback;
    tls_error_struct_inst.expectedCalls = 0;
    tls_error_struct_inst.actualCalls = 0;
}

void tls_error_VerifyMock()
{
    if (tls_error_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'tls_error'",tls_error_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void tls_error_ExpectAndReturn (struct tls * _ctx, const char * to_return, OPMOCK_MATCHER match__ctx)
{
    if(tls_error_struct_inst.callback != NULL)
    {
        tls_error_MockReset ();
    }

    if(tls_error_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting tls_error_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"const char * tls_error (struct tls * _ctx)");
    tls_error_struct_inst.calls[tls_error_struct_inst.expectedCalls]._ctx = (void *)_ctx;
    tls_error_struct_inst.calls[tls_error_struct_inst.expectedCalls].match__ctx = match__ctx;
    tls_error_struct_inst.calls[tls_error_struct_inst.expectedCalls].to_return = ( char *) to_return;
    tls_error_struct_inst.calls[tls_error_struct_inst.expectedCalls].check_params = 1;
    tls_error_struct_inst.expectedCalls++;
}

struct tls_config * tls_config_new()
{
    struct tls_config * default_res = (struct tls_config *)tls_config_new_struct_inst.calls[0].to_return;
    int opmock_i;
    tls_config_new_struct_inst.actualCalls++;

    if (tls_config_new_struct_inst.callback != NULL)
    {
        return tls_config_new_struct_inst.callback (tls_config_new_struct_inst.actualCalls);
    }
    if (tls_config_new_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'tls_config_new', returning random value.");
        return default_res;
    }

    if(strcmp(opmock_get_current_call(), "struct tls_config * tls_config_new ()") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'struct tls_config * tls_config_new()',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (tls_config_new_struct_inst.calls[0].check_params == 1) {
    }

    for(opmock_i = 1; opmock_i < tls_config_new_struct_inst.expectedCalls; opmock_i++) {
        tls_config_new_struct_inst.calls[opmock_i - 1] = tls_config_new_struct_inst.calls[opmock_i];
    }

    tls_config_new_struct_inst.expectedCalls--;
    return default_res;
}

void tls_config_new_MockReset()
{
    tls_config_new_struct_inst.expectedCalls = 0;
    tls_config_new_struct_inst.actualCalls = 0;
    tls_config_new_struct_inst.callback = NULL;
}

void tls_config_new_MockWithCallback(OPMOCK_tls_config_new_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    tls_config_new_struct_inst.callback = callback;
    tls_config_new_struct_inst.expectedCalls = 0;
    tls_config_new_struct_inst.actualCalls = 0;
}

void tls_config_new_VerifyMock()
{
    if (tls_config_new_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'tls_config_new'",tls_config_new_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void tls_config_new_ExpectAndReturn (struct tls_config * to_return)
{
    if(tls_config_new_struct_inst.callback != NULL)
    {
        tls_config_new_MockReset ();
    }

    if(tls_config_new_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting tls_config_new_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"struct tls_config * tls_config_new ()");
    tls_config_new_struct_inst.calls[tls_config_new_struct_inst.expectedCalls].to_return = (struct tls_config *) to_return;
    tls_config_new_struct_inst.calls[tls_config_new_struct_inst.expectedCalls].check_params = 1;
    tls_config_new_struct_inst.expectedCalls++;
}

void tls_config_free(struct tls_config * _config)
{
    int opmock_i;
    tls_config_free_struct_inst.actualCalls++;

    if (tls_config_free_struct_inst.callback != NULL)
    {
        tls_config_free_struct_inst.callback (_config, tls_config_free_struct_inst.actualCalls);
        return;
    }
    if (tls_config_free_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'tls_config_free', returning random value.");
        return;
    }

    if(strcmp(opmock_get_current_call(), "void tls_config_free (struct tls_config * _config)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'void tls_config_free(struct tls_config * _config)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (tls_config_free_struct_inst.calls[0].check_params == 1) {
        if(tls_config_free_struct_inst.calls[0].match__config) {
            void * val1 = (void *) &tls_config_free_struct_inst.calls[0]._config;
            void * val2 = (void *) &_config;
            int match_result = tls_config_free_struct_inst.calls[0].match__config(val1, val2, "_config", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'tls_config_free', %s",tls_config_free_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < tls_config_free_struct_inst.expectedCalls; opmock_i++) {
        tls_config_free_struct_inst.calls[opmock_i - 1] = tls_config_free_struct_inst.calls[opmock_i];
    }

    tls_config_free_struct_inst.expectedCalls--;
}

void tls_config_free_MockReset()
{
    tls_config_free_struct_inst.expectedCalls = 0;
    tls_config_free_struct_inst.actualCalls = 0;
    tls_config_free_struct_inst.callback = NULL;
}

void tls_config_free_MockWithCallback(OPMOCK_tls_config_free_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    tls_config_free_struct_inst.callback = callback;
    tls_config_free_struct_inst.expectedCalls = 0;
    tls_config_free_struct_inst.actualCalls = 0;
}

void tls_config_free_VerifyMock()
{
    if (tls_config_free_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'tls_config_free'",tls_config_free_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void tls_config_free_ExpectAndReturn (struct tls_config * _config, OPMOCK_MATCHER match__config)
{
    if(tls_config_free_struct_inst.callback != NULL)
    {
        tls_config_free_MockReset ();
    }

    if(tls_config_free_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting tls_config_free_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"void tls_config_free (struct tls_config * _config)");
    tls_config_free_struct_inst.calls[tls_config_free_struct_inst.expectedCalls]._config = (void *)_config;
    tls_config_free_struct_inst.calls[tls_config_free_struct_inst.expectedCalls].match__config = match__config;
    tls_config_free_struct_inst.calls[tls_config_free_struct_inst.expectedCalls].check_params = 1;
    tls_config_free_struct_inst.expectedCalls++;
}

int tls_config_set_ca_file(struct tls_config * _config, const char * _ca_file)
{
    int default_res = (int)tls_config_set_ca_file_struct_inst.calls[0].to_return;
    int opmock_i;
    tls_config_set_ca_file_struct_inst.actualCalls++;

    if (tls_config_set_ca_file_struct_inst.callback != NULL)
    {
        return tls_config_set_ca_file_struct_inst.callback (_config, _ca_file, tls_config_set_ca_file_struct_inst.actualCalls);
    }
    if (tls_config_set_ca_file_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'tls_config_set_ca_file', returning random value.");
        return default_res;
    }

    if(strcmp(opmock_get_current_call(), "int tls_config_set_ca_file (struct tls_config * _config, const char * _ca_file)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'int tls_config_set_ca_file(struct tls_config * _config, const char * _ca_file)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (tls_config_set_ca_file_struct_inst.calls[0].check_params == 1) {
        if(tls_config_set_ca_file_struct_inst.calls[0].match__config) {
            void * val1 = (void *) &tls_config_set_ca_file_struct_inst.calls[0]._config;
            void * val2 = (void *) &_config;
            int match_result = tls_config_set_ca_file_struct_inst.calls[0].match__config(val1, val2, "_config", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'tls_config_set_ca_file', %s",tls_config_set_ca_file_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
        if(tls_config_set_ca_file_struct_inst.calls[0].match__ca_file) {
            void * val1 = (void *) &tls_config_set_ca_file_struct_inst.calls[0]._ca_file;
            void * val2 = (void *) &_ca_file;
            int match_result = tls_config_set_ca_file_struct_inst.calls[0].match__ca_file(val1, val2, "_ca_file", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'tls_config_set_ca_file', %s",tls_config_set_ca_file_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < tls_config_set_ca_file_struct_inst.expectedCalls; opmock_i++) {
        tls_config_set_ca_file_struct_inst.calls[opmock_i - 1] = tls_config_set_ca_file_struct_inst.calls[opmock_i];
    }

    tls_config_set_ca_file_struct_inst.expectedCalls--;
    return default_res;
}

void tls_config_set_ca_file_MockReset()
{
    tls_config_set_ca_file_struct_inst.expectedCalls = 0;
    tls_config_set_ca_file_struct_inst.actualCalls = 0;
    tls_config_set_ca_file_struct_inst.callback = NULL;
}

void tls_config_set_ca_file_MockWithCallback(OPMOCK_tls_config_set_ca_file_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    tls_config_set_ca_file_struct_inst.callback = callback;
    tls_config_set_ca_file_struct_inst.expectedCalls = 0;
    tls_config_set_ca_file_struct_inst.actualCalls = 0;
}

void tls_config_set_ca_file_VerifyMock()
{
    if (tls_config_set_ca_file_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'tls_config_set_ca_file'",tls_config_set_ca_file_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void tls_config_set_ca_file_ExpectAndReturn (struct tls_config * _config, const char * _ca_file, int to_return, OPMOCK_MATCHER match__config, OPMOCK_MATCHER match__ca_file)
{
    if(tls_config_set_ca_file_struct_inst.callback != NULL)
    {
        tls_config_set_ca_file_MockReset ();
    }

    if(tls_config_set_ca_file_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting tls_config_set_ca_file_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"int tls_config_set_ca_file (struct tls_config * _config, const char * _ca_file)");
    tls_config_set_ca_file_struct_inst.calls[tls_config_set_ca_file_struct_inst.expectedCalls]._config = (void *)_config;
    tls_config_set_ca_file_struct_inst.calls[tls_config_set_ca_file_struct_inst.expectedCalls]._ca_file = (void *)_ca_file;
    tls_config_set_ca_file_struct_inst.calls[tls_config_set_ca_file_struct_inst.expectedCalls].match__config = match__config;
    tls_config_set_ca_file_struct_inst.calls[tls_config_set_ca_file_struct_inst.expectedCalls].match__ca_file = match__ca_file;
    tls_config_set_ca_file_struct_inst.calls[tls_config_set_ca_file_struct_inst.expectedCalls].to_return = (int) to_return;
    tls_config_set_ca_file_struct_inst.calls[tls_config_set_ca_file_struct_inst.expectedCalls].check_params = 1;
    tls_config_set_ca_file_struct_inst.expectedCalls++;
}

int tls_config_set_ca_path(struct tls_config * _config, const char * _ca_path)
{
    int default_res = (int)tls_config_set_ca_path_struct_inst.calls[0].to_return;
    int opmock_i;
    tls_config_set_ca_path_struct_inst.actualCalls++;

    if (tls_config_set_ca_path_struct_inst.callback != NULL)
    {
        return tls_config_set_ca_path_struct_inst.callback (_config, _ca_path, tls_config_set_ca_path_struct_inst.actualCalls);
    }
    if (tls_config_set_ca_path_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'tls_config_set_ca_path', returning random value.");
        return default_res;
    }

    if(strcmp(opmock_get_current_call(), "int tls_config_set_ca_path (struct tls_config * _config, const char * _ca_path)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'int tls_config_set_ca_path(struct tls_config * _config, const char * _ca_path)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (tls_config_set_ca_path_struct_inst.calls[0].check_params == 1) {
        if(tls_config_set_ca_path_struct_inst.calls[0].match__config) {
            void * val1 = (void *) &tls_config_set_ca_path_struct_inst.calls[0]._config;
            void * val2 = (void *) &_config;
            int match_result = tls_config_set_ca_path_struct_inst.calls[0].match__config(val1, val2, "_config", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'tls_config_set_ca_path', %s",tls_config_set_ca_path_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
        if(tls_config_set_ca_path_struct_inst.calls[0].match__ca_path) {
            void * val1 = (void *) &tls_config_set_ca_path_struct_inst.calls[0]._ca_path;
            void * val2 = (void *) &_ca_path;
            int match_result = tls_config_set_ca_path_struct_inst.calls[0].match__ca_path(val1, val2, "_ca_path", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'tls_config_set_ca_path', %s",tls_config_set_ca_path_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < tls_config_set_ca_path_struct_inst.expectedCalls; opmock_i++) {
        tls_config_set_ca_path_struct_inst.calls[opmock_i - 1] = tls_config_set_ca_path_struct_inst.calls[opmock_i];
    }

    tls_config_set_ca_path_struct_inst.expectedCalls--;
    return default_res;
}

void tls_config_set_ca_path_MockReset()
{
    tls_config_set_ca_path_struct_inst.expectedCalls = 0;
    tls_config_set_ca_path_struct_inst.actualCalls = 0;
    tls_config_set_ca_path_struct_inst.callback = NULL;
}

void tls_config_set_ca_path_MockWithCallback(OPMOCK_tls_config_set_ca_path_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    tls_config_set_ca_path_struct_inst.callback = callback;
    tls_config_set_ca_path_struct_inst.expectedCalls = 0;
    tls_config_set_ca_path_struct_inst.actualCalls = 0;
}

void tls_config_set_ca_path_VerifyMock()
{
    if (tls_config_set_ca_path_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'tls_config_set_ca_path'",tls_config_set_ca_path_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void tls_config_set_ca_path_ExpectAndReturn (struct tls_config * _config, const char * _ca_path, int to_return, OPMOCK_MATCHER match__config, OPMOCK_MATCHER match__ca_path)
{
    if(tls_config_set_ca_path_struct_inst.callback != NULL)
    {
        tls_config_set_ca_path_MockReset ();
    }

    if(tls_config_set_ca_path_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting tls_config_set_ca_path_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"int tls_config_set_ca_path (struct tls_config * _config, const char * _ca_path)");
    tls_config_set_ca_path_struct_inst.calls[tls_config_set_ca_path_struct_inst.expectedCalls]._config = (void *)_config;
    tls_config_set_ca_path_struct_inst.calls[tls_config_set_ca_path_struct_inst.expectedCalls]._ca_path = (void *)_ca_path;
    tls_config_set_ca_path_struct_inst.calls[tls_config_set_ca_path_struct_inst.expectedCalls].match__config = match__config;
    tls_config_set_ca_path_struct_inst.calls[tls_config_set_ca_path_struct_inst.expectedCalls].match__ca_path = match__ca_path;
    tls_config_set_ca_path_struct_inst.calls[tls_config_set_ca_path_struct_inst.expectedCalls].to_return = (int) to_return;
    tls_config_set_ca_path_struct_inst.calls[tls_config_set_ca_path_struct_inst.expectedCalls].check_params = 1;
    tls_config_set_ca_path_struct_inst.expectedCalls++;
}

int tls_config_set_ca_mem(struct tls_config * _config, const uint8_t * _ca, size_t _len)
{
    int default_res = (int)tls_config_set_ca_mem_struct_inst.calls[0].to_return;
    int opmock_i;
    tls_config_set_ca_mem_struct_inst.actualCalls++;

    if (tls_config_set_ca_mem_struct_inst.callback != NULL)
    {
        return tls_config_set_ca_mem_struct_inst.callback (_config, _ca, _len, tls_config_set_ca_mem_struct_inst.actualCalls);
    }
    if (tls_config_set_ca_mem_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'tls_config_set_ca_mem', returning random value.");
        return default_res;
    }

    if(strcmp(opmock_get_current_call(), "int tls_config_set_ca_mem (struct tls_config * _config, const uint8_t * _ca, size_t _len)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'int tls_config_set_ca_mem(struct tls_config * _config, const uint8_t * _ca, size_t _len)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (tls_config_set_ca_mem_struct_inst.calls[0].check_params == 1) {
        if(tls_config_set_ca_mem_struct_inst.calls[0].match__config) {
            void * val1 = (void *) &tls_config_set_ca_mem_struct_inst.calls[0]._config;
            void * val2 = (void *) &_config;
            int match_result = tls_config_set_ca_mem_struct_inst.calls[0].match__config(val1, val2, "_config", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'tls_config_set_ca_mem', %s",tls_config_set_ca_mem_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
        if(tls_config_set_ca_mem_struct_inst.calls[0].match__ca) {
            void * val1 = (void *) &tls_config_set_ca_mem_struct_inst.calls[0]._ca;
            void * val2 = (void *) &_ca;
            int match_result = tls_config_set_ca_mem_struct_inst.calls[0].match__ca(val1, val2, "_ca", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'tls_config_set_ca_mem', %s",tls_config_set_ca_mem_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
        if(tls_config_set_ca_mem_struct_inst.calls[0].match__len) {
            void * val1 = (void *) &tls_config_set_ca_mem_struct_inst.calls[0]._len;
            void * val2 = (void *) &_len;
            int match_result = tls_config_set_ca_mem_struct_inst.calls[0].match__len(val1, val2, "_len", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'tls_config_set_ca_mem', %s",tls_config_set_ca_mem_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < tls_config_set_ca_mem_struct_inst.expectedCalls; opmock_i++) {
        tls_config_set_ca_mem_struct_inst.calls[opmock_i - 1] = tls_config_set_ca_mem_struct_inst.calls[opmock_i];
    }

    tls_config_set_ca_mem_struct_inst.expectedCalls--;
    return default_res;
}

void tls_config_set_ca_mem_MockReset()
{
    tls_config_set_ca_mem_struct_inst.expectedCalls = 0;
    tls_config_set_ca_mem_struct_inst.actualCalls = 0;
    tls_config_set_ca_mem_struct_inst.callback = NULL;
}

void tls_config_set_ca_mem_MockWithCallback(OPMOCK_tls_config_set_ca_mem_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    tls_config_set_ca_mem_struct_inst.callback = callback;
    tls_config_set_ca_mem_struct_inst.expectedCalls = 0;
    tls_config_set_ca_mem_struct_inst.actualCalls = 0;
}

void tls_config_set_ca_mem_VerifyMock()
{
    if (tls_config_set_ca_mem_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'tls_config_set_ca_mem'",tls_config_set_ca_mem_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void tls_config_set_ca_mem_ExpectAndReturn (struct tls_config * _config, const uint8_t * _ca, size_t _len, int to_return, OPMOCK_MATCHER match__config, OPMOCK_MATCHER match__ca, OPMOCK_MATCHER match__len)
{
    if(tls_config_set_ca_mem_struct_inst.callback != NULL)
    {
        tls_config_set_ca_mem_MockReset ();
    }

    if(tls_config_set_ca_mem_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting tls_config_set_ca_mem_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"int tls_config_set_ca_mem (struct tls_config * _config, const uint8_t * _ca, size_t _len)");
    tls_config_set_ca_mem_struct_inst.calls[tls_config_set_ca_mem_struct_inst.expectedCalls]._config = (void *)_config;
    tls_config_set_ca_mem_struct_inst.calls[tls_config_set_ca_mem_struct_inst.expectedCalls]._ca = (void *)_ca;
    tls_config_set_ca_mem_struct_inst.calls[tls_config_set_ca_mem_struct_inst.expectedCalls]._len = (unsigned long)_len;
    tls_config_set_ca_mem_struct_inst.calls[tls_config_set_ca_mem_struct_inst.expectedCalls].match__config = match__config;
    tls_config_set_ca_mem_struct_inst.calls[tls_config_set_ca_mem_struct_inst.expectedCalls].match__ca = match__ca;
    tls_config_set_ca_mem_struct_inst.calls[tls_config_set_ca_mem_struct_inst.expectedCalls].match__len = match__len;
    tls_config_set_ca_mem_struct_inst.calls[tls_config_set_ca_mem_struct_inst.expectedCalls].to_return = (int) to_return;
    tls_config_set_ca_mem_struct_inst.calls[tls_config_set_ca_mem_struct_inst.expectedCalls].check_params = 1;
    tls_config_set_ca_mem_struct_inst.expectedCalls++;
}

int tls_config_set_cert_file(struct tls_config * _config, const char * _cert_file)
{
    int default_res = (int)tls_config_set_cert_file_struct_inst.calls[0].to_return;
    int opmock_i;
    tls_config_set_cert_file_struct_inst.actualCalls++;

    if (tls_config_set_cert_file_struct_inst.callback != NULL)
    {
        return tls_config_set_cert_file_struct_inst.callback (_config, _cert_file, tls_config_set_cert_file_struct_inst.actualCalls);
    }
    if (tls_config_set_cert_file_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'tls_config_set_cert_file', returning random value.");
        return default_res;
    }

    if(strcmp(opmock_get_current_call(), "int tls_config_set_cert_file (struct tls_config * _config, const char * _cert_file)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'int tls_config_set_cert_file(struct tls_config * _config, const char * _cert_file)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (tls_config_set_cert_file_struct_inst.calls[0].check_params == 1) {
        if(tls_config_set_cert_file_struct_inst.calls[0].match__config) {
            void * val1 = (void *) &tls_config_set_cert_file_struct_inst.calls[0]._config;
            void * val2 = (void *) &_config;
            int match_result = tls_config_set_cert_file_struct_inst.calls[0].match__config(val1, val2, "_config", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'tls_config_set_cert_file', %s",tls_config_set_cert_file_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
        if(tls_config_set_cert_file_struct_inst.calls[0].match__cert_file) {
            void * val1 = (void *) &tls_config_set_cert_file_struct_inst.calls[0]._cert_file;
            void * val2 = (void *) &_cert_file;
            int match_result = tls_config_set_cert_file_struct_inst.calls[0].match__cert_file(val1, val2, "_cert_file", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'tls_config_set_cert_file', %s",tls_config_set_cert_file_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < tls_config_set_cert_file_struct_inst.expectedCalls; opmock_i++) {
        tls_config_set_cert_file_struct_inst.calls[opmock_i - 1] = tls_config_set_cert_file_struct_inst.calls[opmock_i];
    }

    tls_config_set_cert_file_struct_inst.expectedCalls--;
    return default_res;
}

void tls_config_set_cert_file_MockReset()
{
    tls_config_set_cert_file_struct_inst.expectedCalls = 0;
    tls_config_set_cert_file_struct_inst.actualCalls = 0;
    tls_config_set_cert_file_struct_inst.callback = NULL;
}

void tls_config_set_cert_file_MockWithCallback(OPMOCK_tls_config_set_cert_file_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    tls_config_set_cert_file_struct_inst.callback = callback;
    tls_config_set_cert_file_struct_inst.expectedCalls = 0;
    tls_config_set_cert_file_struct_inst.actualCalls = 0;
}

void tls_config_set_cert_file_VerifyMock()
{
    if (tls_config_set_cert_file_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'tls_config_set_cert_file'",tls_config_set_cert_file_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void tls_config_set_cert_file_ExpectAndReturn (struct tls_config * _config, const char * _cert_file, int to_return, OPMOCK_MATCHER match__config, OPMOCK_MATCHER match__cert_file)
{
    if(tls_config_set_cert_file_struct_inst.callback != NULL)
    {
        tls_config_set_cert_file_MockReset ();
    }

    if(tls_config_set_cert_file_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting tls_config_set_cert_file_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"int tls_config_set_cert_file (struct tls_config * _config, const char * _cert_file)");
    tls_config_set_cert_file_struct_inst.calls[tls_config_set_cert_file_struct_inst.expectedCalls]._config = (void *)_config;
    tls_config_set_cert_file_struct_inst.calls[tls_config_set_cert_file_struct_inst.expectedCalls]._cert_file = (void *)_cert_file;
    tls_config_set_cert_file_struct_inst.calls[tls_config_set_cert_file_struct_inst.expectedCalls].match__config = match__config;
    tls_config_set_cert_file_struct_inst.calls[tls_config_set_cert_file_struct_inst.expectedCalls].match__cert_file = match__cert_file;
    tls_config_set_cert_file_struct_inst.calls[tls_config_set_cert_file_struct_inst.expectedCalls].to_return = (int) to_return;
    tls_config_set_cert_file_struct_inst.calls[tls_config_set_cert_file_struct_inst.expectedCalls].check_params = 1;
    tls_config_set_cert_file_struct_inst.expectedCalls++;
}

int tls_config_set_cert_mem(struct tls_config * _config, const uint8_t * _cert, size_t _len)
{
    int default_res = (int)tls_config_set_cert_mem_struct_inst.calls[0].to_return;
    int opmock_i;
    tls_config_set_cert_mem_struct_inst.actualCalls++;

    if (tls_config_set_cert_mem_struct_inst.callback != NULL)
    {
        return tls_config_set_cert_mem_struct_inst.callback (_config, _cert, _len, tls_config_set_cert_mem_struct_inst.actualCalls);
    }
    if (tls_config_set_cert_mem_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'tls_config_set_cert_mem', returning random value.");
        return default_res;
    }

    if(strcmp(opmock_get_current_call(), "int tls_config_set_cert_mem (struct tls_config * _config, const uint8_t * _cert, size_t _len)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'int tls_config_set_cert_mem(struct tls_config * _config, const uint8_t * _cert, size_t _len)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (tls_config_set_cert_mem_struct_inst.calls[0].check_params == 1) {
        if(tls_config_set_cert_mem_struct_inst.calls[0].match__config) {
            void * val1 = (void *) &tls_config_set_cert_mem_struct_inst.calls[0]._config;
            void * val2 = (void *) &_config;
            int match_result = tls_config_set_cert_mem_struct_inst.calls[0].match__config(val1, val2, "_config", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'tls_config_set_cert_mem', %s",tls_config_set_cert_mem_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
        if(tls_config_set_cert_mem_struct_inst.calls[0].match__cert) {
            void * val1 = (void *) &tls_config_set_cert_mem_struct_inst.calls[0]._cert;
            void * val2 = (void *) &_cert;
            int match_result = tls_config_set_cert_mem_struct_inst.calls[0].match__cert(val1, val2, "_cert", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'tls_config_set_cert_mem', %s",tls_config_set_cert_mem_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
        if(tls_config_set_cert_mem_struct_inst.calls[0].match__len) {
            void * val1 = (void *) &tls_config_set_cert_mem_struct_inst.calls[0]._len;
            void * val2 = (void *) &_len;
            int match_result = tls_config_set_cert_mem_struct_inst.calls[0].match__len(val1, val2, "_len", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'tls_config_set_cert_mem', %s",tls_config_set_cert_mem_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < tls_config_set_cert_mem_struct_inst.expectedCalls; opmock_i++) {
        tls_config_set_cert_mem_struct_inst.calls[opmock_i - 1] = tls_config_set_cert_mem_struct_inst.calls[opmock_i];
    }

    tls_config_set_cert_mem_struct_inst.expectedCalls--;
    return default_res;
}

void tls_config_set_cert_mem_MockReset()
{
    tls_config_set_cert_mem_struct_inst.expectedCalls = 0;
    tls_config_set_cert_mem_struct_inst.actualCalls = 0;
    tls_config_set_cert_mem_struct_inst.callback = NULL;
}

void tls_config_set_cert_mem_MockWithCallback(OPMOCK_tls_config_set_cert_mem_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    tls_config_set_cert_mem_struct_inst.callback = callback;
    tls_config_set_cert_mem_struct_inst.expectedCalls = 0;
    tls_config_set_cert_mem_struct_inst.actualCalls = 0;
}

void tls_config_set_cert_mem_VerifyMock()
{
    if (tls_config_set_cert_mem_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'tls_config_set_cert_mem'",tls_config_set_cert_mem_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void tls_config_set_cert_mem_ExpectAndReturn (struct tls_config * _config, const uint8_t * _cert, size_t _len, int to_return, OPMOCK_MATCHER match__config, OPMOCK_MATCHER match__cert, OPMOCK_MATCHER match__len)
{
    if(tls_config_set_cert_mem_struct_inst.callback != NULL)
    {
        tls_config_set_cert_mem_MockReset ();
    }

    if(tls_config_set_cert_mem_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting tls_config_set_cert_mem_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"int tls_config_set_cert_mem (struct tls_config * _config, const uint8_t * _cert, size_t _len)");
    tls_config_set_cert_mem_struct_inst.calls[tls_config_set_cert_mem_struct_inst.expectedCalls]._config = (void *)_config;
    tls_config_set_cert_mem_struct_inst.calls[tls_config_set_cert_mem_struct_inst.expectedCalls]._cert = (void *)_cert;
    tls_config_set_cert_mem_struct_inst.calls[tls_config_set_cert_mem_struct_inst.expectedCalls]._len = (unsigned long)_len;
    tls_config_set_cert_mem_struct_inst.calls[tls_config_set_cert_mem_struct_inst.expectedCalls].match__config = match__config;
    tls_config_set_cert_mem_struct_inst.calls[tls_config_set_cert_mem_struct_inst.expectedCalls].match__cert = match__cert;
    tls_config_set_cert_mem_struct_inst.calls[tls_config_set_cert_mem_struct_inst.expectedCalls].match__len = match__len;
    tls_config_set_cert_mem_struct_inst.calls[tls_config_set_cert_mem_struct_inst.expectedCalls].to_return = (int) to_return;
    tls_config_set_cert_mem_struct_inst.calls[tls_config_set_cert_mem_struct_inst.expectedCalls].check_params = 1;
    tls_config_set_cert_mem_struct_inst.expectedCalls++;
}

int tls_config_set_ciphers(struct tls_config * _config, const char * _ciphers)
{
    int default_res = (int)tls_config_set_ciphers_struct_inst.calls[0].to_return;
    int opmock_i;
    tls_config_set_ciphers_struct_inst.actualCalls++;

    if (tls_config_set_ciphers_struct_inst.callback != NULL)
    {
        return tls_config_set_ciphers_struct_inst.callback (_config, _ciphers, tls_config_set_ciphers_struct_inst.actualCalls);
    }
    if (tls_config_set_ciphers_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'tls_config_set_ciphers', returning random value.");
        return default_res;
    }

    if(strcmp(opmock_get_current_call(), "int tls_config_set_ciphers (struct tls_config * _config, const char * _ciphers)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'int tls_config_set_ciphers(struct tls_config * _config, const char * _ciphers)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (tls_config_set_ciphers_struct_inst.calls[0].check_params == 1) {
        if(tls_config_set_ciphers_struct_inst.calls[0].match__config) {
            void * val1 = (void *) &tls_config_set_ciphers_struct_inst.calls[0]._config;
            void * val2 = (void *) &_config;
            int match_result = tls_config_set_ciphers_struct_inst.calls[0].match__config(val1, val2, "_config", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'tls_config_set_ciphers', %s",tls_config_set_ciphers_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
        if(tls_config_set_ciphers_struct_inst.calls[0].match__ciphers) {
            void * val1 = (void *) &tls_config_set_ciphers_struct_inst.calls[0]._ciphers;
            void * val2 = (void *) &_ciphers;
            int match_result = tls_config_set_ciphers_struct_inst.calls[0].match__ciphers(val1, val2, "_ciphers", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'tls_config_set_ciphers', %s",tls_config_set_ciphers_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < tls_config_set_ciphers_struct_inst.expectedCalls; opmock_i++) {
        tls_config_set_ciphers_struct_inst.calls[opmock_i - 1] = tls_config_set_ciphers_struct_inst.calls[opmock_i];
    }

    tls_config_set_ciphers_struct_inst.expectedCalls--;
    return default_res;
}

void tls_config_set_ciphers_MockReset()
{
    tls_config_set_ciphers_struct_inst.expectedCalls = 0;
    tls_config_set_ciphers_struct_inst.actualCalls = 0;
    tls_config_set_ciphers_struct_inst.callback = NULL;
}

void tls_config_set_ciphers_MockWithCallback(OPMOCK_tls_config_set_ciphers_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    tls_config_set_ciphers_struct_inst.callback = callback;
    tls_config_set_ciphers_struct_inst.expectedCalls = 0;
    tls_config_set_ciphers_struct_inst.actualCalls = 0;
}

void tls_config_set_ciphers_VerifyMock()
{
    if (tls_config_set_ciphers_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'tls_config_set_ciphers'",tls_config_set_ciphers_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void tls_config_set_ciphers_ExpectAndReturn (struct tls_config * _config, const char * _ciphers, int to_return, OPMOCK_MATCHER match__config, OPMOCK_MATCHER match__ciphers)
{
    if(tls_config_set_ciphers_struct_inst.callback != NULL)
    {
        tls_config_set_ciphers_MockReset ();
    }

    if(tls_config_set_ciphers_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting tls_config_set_ciphers_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"int tls_config_set_ciphers (struct tls_config * _config, const char * _ciphers)");
    tls_config_set_ciphers_struct_inst.calls[tls_config_set_ciphers_struct_inst.expectedCalls]._config = (void *)_config;
    tls_config_set_ciphers_struct_inst.calls[tls_config_set_ciphers_struct_inst.expectedCalls]._ciphers = (void *)_ciphers;
    tls_config_set_ciphers_struct_inst.calls[tls_config_set_ciphers_struct_inst.expectedCalls].match__config = match__config;
    tls_config_set_ciphers_struct_inst.calls[tls_config_set_ciphers_struct_inst.expectedCalls].match__ciphers = match__ciphers;
    tls_config_set_ciphers_struct_inst.calls[tls_config_set_ciphers_struct_inst.expectedCalls].to_return = (int) to_return;
    tls_config_set_ciphers_struct_inst.calls[tls_config_set_ciphers_struct_inst.expectedCalls].check_params = 1;
    tls_config_set_ciphers_struct_inst.expectedCalls++;
}

int tls_config_set_dheparams(struct tls_config * _config, const char * _params)
{
    int default_res = (int)tls_config_set_dheparams_struct_inst.calls[0].to_return;
    int opmock_i;
    tls_config_set_dheparams_struct_inst.actualCalls++;

    if (tls_config_set_dheparams_struct_inst.callback != NULL)
    {
        return tls_config_set_dheparams_struct_inst.callback (_config, _params, tls_config_set_dheparams_struct_inst.actualCalls);
    }
    if (tls_config_set_dheparams_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'tls_config_set_dheparams', returning random value.");
        return default_res;
    }

    if(strcmp(opmock_get_current_call(), "int tls_config_set_dheparams (struct tls_config * _config, const char * _params)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'int tls_config_set_dheparams(struct tls_config * _config, const char * _params)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (tls_config_set_dheparams_struct_inst.calls[0].check_params == 1) {
        if(tls_config_set_dheparams_struct_inst.calls[0].match__config) {
            void * val1 = (void *) &tls_config_set_dheparams_struct_inst.calls[0]._config;
            void * val2 = (void *) &_config;
            int match_result = tls_config_set_dheparams_struct_inst.calls[0].match__config(val1, val2, "_config", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'tls_config_set_dheparams', %s",tls_config_set_dheparams_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
        if(tls_config_set_dheparams_struct_inst.calls[0].match__params) {
            void * val1 = (void *) &tls_config_set_dheparams_struct_inst.calls[0]._params;
            void * val2 = (void *) &_params;
            int match_result = tls_config_set_dheparams_struct_inst.calls[0].match__params(val1, val2, "_params", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'tls_config_set_dheparams', %s",tls_config_set_dheparams_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < tls_config_set_dheparams_struct_inst.expectedCalls; opmock_i++) {
        tls_config_set_dheparams_struct_inst.calls[opmock_i - 1] = tls_config_set_dheparams_struct_inst.calls[opmock_i];
    }

    tls_config_set_dheparams_struct_inst.expectedCalls--;
    return default_res;
}

void tls_config_set_dheparams_MockReset()
{
    tls_config_set_dheparams_struct_inst.expectedCalls = 0;
    tls_config_set_dheparams_struct_inst.actualCalls = 0;
    tls_config_set_dheparams_struct_inst.callback = NULL;
}

void tls_config_set_dheparams_MockWithCallback(OPMOCK_tls_config_set_dheparams_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    tls_config_set_dheparams_struct_inst.callback = callback;
    tls_config_set_dheparams_struct_inst.expectedCalls = 0;
    tls_config_set_dheparams_struct_inst.actualCalls = 0;
}

void tls_config_set_dheparams_VerifyMock()
{
    if (tls_config_set_dheparams_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'tls_config_set_dheparams'",tls_config_set_dheparams_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void tls_config_set_dheparams_ExpectAndReturn (struct tls_config * _config, const char * _params, int to_return, OPMOCK_MATCHER match__config, OPMOCK_MATCHER match__params)
{
    if(tls_config_set_dheparams_struct_inst.callback != NULL)
    {
        tls_config_set_dheparams_MockReset ();
    }

    if(tls_config_set_dheparams_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting tls_config_set_dheparams_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"int tls_config_set_dheparams (struct tls_config * _config, const char * _params)");
    tls_config_set_dheparams_struct_inst.calls[tls_config_set_dheparams_struct_inst.expectedCalls]._config = (void *)_config;
    tls_config_set_dheparams_struct_inst.calls[tls_config_set_dheparams_struct_inst.expectedCalls]._params = (void *)_params;
    tls_config_set_dheparams_struct_inst.calls[tls_config_set_dheparams_struct_inst.expectedCalls].match__config = match__config;
    tls_config_set_dheparams_struct_inst.calls[tls_config_set_dheparams_struct_inst.expectedCalls].match__params = match__params;
    tls_config_set_dheparams_struct_inst.calls[tls_config_set_dheparams_struct_inst.expectedCalls].to_return = (int) to_return;
    tls_config_set_dheparams_struct_inst.calls[tls_config_set_dheparams_struct_inst.expectedCalls].check_params = 1;
    tls_config_set_dheparams_struct_inst.expectedCalls++;
}

int tls_config_set_ecdhecurve(struct tls_config * _config, const char * _name)
{
    int default_res = (int)tls_config_set_ecdhecurve_struct_inst.calls[0].to_return;
    int opmock_i;
    tls_config_set_ecdhecurve_struct_inst.actualCalls++;

    if (tls_config_set_ecdhecurve_struct_inst.callback != NULL)
    {
        return tls_config_set_ecdhecurve_struct_inst.callback (_config, _name, tls_config_set_ecdhecurve_struct_inst.actualCalls);
    }
    if (tls_config_set_ecdhecurve_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'tls_config_set_ecdhecurve', returning random value.");
        return default_res;
    }

    if(strcmp(opmock_get_current_call(), "int tls_config_set_ecdhecurve (struct tls_config * _config, const char * _name)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'int tls_config_set_ecdhecurve(struct tls_config * _config, const char * _name)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (tls_config_set_ecdhecurve_struct_inst.calls[0].check_params == 1) {
        if(tls_config_set_ecdhecurve_struct_inst.calls[0].match__config) {
            void * val1 = (void *) &tls_config_set_ecdhecurve_struct_inst.calls[0]._config;
            void * val2 = (void *) &_config;
            int match_result = tls_config_set_ecdhecurve_struct_inst.calls[0].match__config(val1, val2, "_config", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'tls_config_set_ecdhecurve', %s",tls_config_set_ecdhecurve_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
        if(tls_config_set_ecdhecurve_struct_inst.calls[0].match__name) {
            void * val1 = (void *) &tls_config_set_ecdhecurve_struct_inst.calls[0]._name;
            void * val2 = (void *) &_name;
            int match_result = tls_config_set_ecdhecurve_struct_inst.calls[0].match__name(val1, val2, "_name", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'tls_config_set_ecdhecurve', %s",tls_config_set_ecdhecurve_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < tls_config_set_ecdhecurve_struct_inst.expectedCalls; opmock_i++) {
        tls_config_set_ecdhecurve_struct_inst.calls[opmock_i - 1] = tls_config_set_ecdhecurve_struct_inst.calls[opmock_i];
    }

    tls_config_set_ecdhecurve_struct_inst.expectedCalls--;
    return default_res;
}

void tls_config_set_ecdhecurve_MockReset()
{
    tls_config_set_ecdhecurve_struct_inst.expectedCalls = 0;
    tls_config_set_ecdhecurve_struct_inst.actualCalls = 0;
    tls_config_set_ecdhecurve_struct_inst.callback = NULL;
}

void tls_config_set_ecdhecurve_MockWithCallback(OPMOCK_tls_config_set_ecdhecurve_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    tls_config_set_ecdhecurve_struct_inst.callback = callback;
    tls_config_set_ecdhecurve_struct_inst.expectedCalls = 0;
    tls_config_set_ecdhecurve_struct_inst.actualCalls = 0;
}

void tls_config_set_ecdhecurve_VerifyMock()
{
    if (tls_config_set_ecdhecurve_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'tls_config_set_ecdhecurve'",tls_config_set_ecdhecurve_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void tls_config_set_ecdhecurve_ExpectAndReturn (struct tls_config * _config, const char * _name, int to_return, OPMOCK_MATCHER match__config, OPMOCK_MATCHER match__name)
{
    if(tls_config_set_ecdhecurve_struct_inst.callback != NULL)
    {
        tls_config_set_ecdhecurve_MockReset ();
    }

    if(tls_config_set_ecdhecurve_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting tls_config_set_ecdhecurve_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"int tls_config_set_ecdhecurve (struct tls_config * _config, const char * _name)");
    tls_config_set_ecdhecurve_struct_inst.calls[tls_config_set_ecdhecurve_struct_inst.expectedCalls]._config = (void *)_config;
    tls_config_set_ecdhecurve_struct_inst.calls[tls_config_set_ecdhecurve_struct_inst.expectedCalls]._name = (void *)_name;
    tls_config_set_ecdhecurve_struct_inst.calls[tls_config_set_ecdhecurve_struct_inst.expectedCalls].match__config = match__config;
    tls_config_set_ecdhecurve_struct_inst.calls[tls_config_set_ecdhecurve_struct_inst.expectedCalls].match__name = match__name;
    tls_config_set_ecdhecurve_struct_inst.calls[tls_config_set_ecdhecurve_struct_inst.expectedCalls].to_return = (int) to_return;
    tls_config_set_ecdhecurve_struct_inst.calls[tls_config_set_ecdhecurve_struct_inst.expectedCalls].check_params = 1;
    tls_config_set_ecdhecurve_struct_inst.expectedCalls++;
}

int tls_config_set_key_file(struct tls_config * _config, const char * _key_file)
{
    int default_res = (int)tls_config_set_key_file_struct_inst.calls[0].to_return;
    int opmock_i;
    tls_config_set_key_file_struct_inst.actualCalls++;

    if (tls_config_set_key_file_struct_inst.callback != NULL)
    {
        return tls_config_set_key_file_struct_inst.callback (_config, _key_file, tls_config_set_key_file_struct_inst.actualCalls);
    }
    if (tls_config_set_key_file_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'tls_config_set_key_file', returning random value.");
        return default_res;
    }

    if(strcmp(opmock_get_current_call(), "int tls_config_set_key_file (struct tls_config * _config, const char * _key_file)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'int tls_config_set_key_file(struct tls_config * _config, const char * _key_file)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (tls_config_set_key_file_struct_inst.calls[0].check_params == 1) {
        if(tls_config_set_key_file_struct_inst.calls[0].match__config) {
            void * val1 = (void *) &tls_config_set_key_file_struct_inst.calls[0]._config;
            void * val2 = (void *) &_config;
            int match_result = tls_config_set_key_file_struct_inst.calls[0].match__config(val1, val2, "_config", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'tls_config_set_key_file', %s",tls_config_set_key_file_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
        if(tls_config_set_key_file_struct_inst.calls[0].match__key_file) {
            void * val1 = (void *) &tls_config_set_key_file_struct_inst.calls[0]._key_file;
            void * val2 = (void *) &_key_file;
            int match_result = tls_config_set_key_file_struct_inst.calls[0].match__key_file(val1, val2, "_key_file", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'tls_config_set_key_file', %s",tls_config_set_key_file_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < tls_config_set_key_file_struct_inst.expectedCalls; opmock_i++) {
        tls_config_set_key_file_struct_inst.calls[opmock_i - 1] = tls_config_set_key_file_struct_inst.calls[opmock_i];
    }

    tls_config_set_key_file_struct_inst.expectedCalls--;
    return default_res;
}

void tls_config_set_key_file_MockReset()
{
    tls_config_set_key_file_struct_inst.expectedCalls = 0;
    tls_config_set_key_file_struct_inst.actualCalls = 0;
    tls_config_set_key_file_struct_inst.callback = NULL;
}

void tls_config_set_key_file_MockWithCallback(OPMOCK_tls_config_set_key_file_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    tls_config_set_key_file_struct_inst.callback = callback;
    tls_config_set_key_file_struct_inst.expectedCalls = 0;
    tls_config_set_key_file_struct_inst.actualCalls = 0;
}

void tls_config_set_key_file_VerifyMock()
{
    if (tls_config_set_key_file_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'tls_config_set_key_file'",tls_config_set_key_file_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void tls_config_set_key_file_ExpectAndReturn (struct tls_config * _config, const char * _key_file, int to_return, OPMOCK_MATCHER match__config, OPMOCK_MATCHER match__key_file)
{
    if(tls_config_set_key_file_struct_inst.callback != NULL)
    {
        tls_config_set_key_file_MockReset ();
    }

    if(tls_config_set_key_file_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting tls_config_set_key_file_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"int tls_config_set_key_file (struct tls_config * _config, const char * _key_file)");
    tls_config_set_key_file_struct_inst.calls[tls_config_set_key_file_struct_inst.expectedCalls]._config = (void *)_config;
    tls_config_set_key_file_struct_inst.calls[tls_config_set_key_file_struct_inst.expectedCalls]._key_file = (void *)_key_file;
    tls_config_set_key_file_struct_inst.calls[tls_config_set_key_file_struct_inst.expectedCalls].match__config = match__config;
    tls_config_set_key_file_struct_inst.calls[tls_config_set_key_file_struct_inst.expectedCalls].match__key_file = match__key_file;
    tls_config_set_key_file_struct_inst.calls[tls_config_set_key_file_struct_inst.expectedCalls].to_return = (int) to_return;
    tls_config_set_key_file_struct_inst.calls[tls_config_set_key_file_struct_inst.expectedCalls].check_params = 1;
    tls_config_set_key_file_struct_inst.expectedCalls++;
}

int tls_config_set_key_mem(struct tls_config * _config, const uint8_t * _key, size_t _len)
{
    int default_res = (int)tls_config_set_key_mem_struct_inst.calls[0].to_return;
    int opmock_i;
    tls_config_set_key_mem_struct_inst.actualCalls++;

    if (tls_config_set_key_mem_struct_inst.callback != NULL)
    {
        return tls_config_set_key_mem_struct_inst.callback (_config, _key, _len, tls_config_set_key_mem_struct_inst.actualCalls);
    }
    if (tls_config_set_key_mem_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'tls_config_set_key_mem', returning random value.");
        return default_res;
    }

    if(strcmp(opmock_get_current_call(), "int tls_config_set_key_mem (struct tls_config * _config, const uint8_t * _key, size_t _len)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'int tls_config_set_key_mem(struct tls_config * _config, const uint8_t * _key, size_t _len)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (tls_config_set_key_mem_struct_inst.calls[0].check_params == 1) {
        if(tls_config_set_key_mem_struct_inst.calls[0].match__config) {
            void * val1 = (void *) &tls_config_set_key_mem_struct_inst.calls[0]._config;
            void * val2 = (void *) &_config;
            int match_result = tls_config_set_key_mem_struct_inst.calls[0].match__config(val1, val2, "_config", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'tls_config_set_key_mem', %s",tls_config_set_key_mem_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
        if(tls_config_set_key_mem_struct_inst.calls[0].match__key) {
            void * val1 = (void *) &tls_config_set_key_mem_struct_inst.calls[0]._key;
            void * val2 = (void *) &_key;
            int match_result = tls_config_set_key_mem_struct_inst.calls[0].match__key(val1, val2, "_key", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'tls_config_set_key_mem', %s",tls_config_set_key_mem_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
        if(tls_config_set_key_mem_struct_inst.calls[0].match__len) {
            void * val1 = (void *) &tls_config_set_key_mem_struct_inst.calls[0]._len;
            void * val2 = (void *) &_len;
            int match_result = tls_config_set_key_mem_struct_inst.calls[0].match__len(val1, val2, "_len", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'tls_config_set_key_mem', %s",tls_config_set_key_mem_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < tls_config_set_key_mem_struct_inst.expectedCalls; opmock_i++) {
        tls_config_set_key_mem_struct_inst.calls[opmock_i - 1] = tls_config_set_key_mem_struct_inst.calls[opmock_i];
    }

    tls_config_set_key_mem_struct_inst.expectedCalls--;
    return default_res;
}

void tls_config_set_key_mem_MockReset()
{
    tls_config_set_key_mem_struct_inst.expectedCalls = 0;
    tls_config_set_key_mem_struct_inst.actualCalls = 0;
    tls_config_set_key_mem_struct_inst.callback = NULL;
}

void tls_config_set_key_mem_MockWithCallback(OPMOCK_tls_config_set_key_mem_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    tls_config_set_key_mem_struct_inst.callback = callback;
    tls_config_set_key_mem_struct_inst.expectedCalls = 0;
    tls_config_set_key_mem_struct_inst.actualCalls = 0;
}

void tls_config_set_key_mem_VerifyMock()
{
    if (tls_config_set_key_mem_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'tls_config_set_key_mem'",tls_config_set_key_mem_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void tls_config_set_key_mem_ExpectAndReturn (struct tls_config * _config, const uint8_t * _key, size_t _len, int to_return, OPMOCK_MATCHER match__config, OPMOCK_MATCHER match__key, OPMOCK_MATCHER match__len)
{
    if(tls_config_set_key_mem_struct_inst.callback != NULL)
    {
        tls_config_set_key_mem_MockReset ();
    }

    if(tls_config_set_key_mem_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting tls_config_set_key_mem_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"int tls_config_set_key_mem (struct tls_config * _config, const uint8_t * _key, size_t _len)");
    tls_config_set_key_mem_struct_inst.calls[tls_config_set_key_mem_struct_inst.expectedCalls]._config = (void *)_config;
    tls_config_set_key_mem_struct_inst.calls[tls_config_set_key_mem_struct_inst.expectedCalls]._key = (void *)_key;
    tls_config_set_key_mem_struct_inst.calls[tls_config_set_key_mem_struct_inst.expectedCalls]._len = (unsigned long)_len;
    tls_config_set_key_mem_struct_inst.calls[tls_config_set_key_mem_struct_inst.expectedCalls].match__config = match__config;
    tls_config_set_key_mem_struct_inst.calls[tls_config_set_key_mem_struct_inst.expectedCalls].match__key = match__key;
    tls_config_set_key_mem_struct_inst.calls[tls_config_set_key_mem_struct_inst.expectedCalls].match__len = match__len;
    tls_config_set_key_mem_struct_inst.calls[tls_config_set_key_mem_struct_inst.expectedCalls].to_return = (int) to_return;
    tls_config_set_key_mem_struct_inst.calls[tls_config_set_key_mem_struct_inst.expectedCalls].check_params = 1;
    tls_config_set_key_mem_struct_inst.expectedCalls++;
}

void tls_config_set_protocols(struct tls_config * _config, uint32_t _protocols)
{
    int opmock_i;
    tls_config_set_protocols_struct_inst.actualCalls++;

    if (tls_config_set_protocols_struct_inst.callback != NULL)
    {
        tls_config_set_protocols_struct_inst.callback (_config, _protocols, tls_config_set_protocols_struct_inst.actualCalls);
        return;
    }
    if (tls_config_set_protocols_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'tls_config_set_protocols', returning random value.");
        return;
    }

    if(strcmp(opmock_get_current_call(), "void tls_config_set_protocols (struct tls_config * _config, uint32_t _protocols)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'void tls_config_set_protocols(struct tls_config * _config, uint32_t _protocols)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (tls_config_set_protocols_struct_inst.calls[0].check_params == 1) {
        if(tls_config_set_protocols_struct_inst.calls[0].match__config) {
            void * val1 = (void *) &tls_config_set_protocols_struct_inst.calls[0]._config;
            void * val2 = (void *) &_config;
            int match_result = tls_config_set_protocols_struct_inst.calls[0].match__config(val1, val2, "_config", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'tls_config_set_protocols', %s",tls_config_set_protocols_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
        if(tls_config_set_protocols_struct_inst.calls[0].match__protocols) {
            void * val1 = (void *) &tls_config_set_protocols_struct_inst.calls[0]._protocols;
            void * val2 = (void *) &_protocols;
            int match_result = tls_config_set_protocols_struct_inst.calls[0].match__protocols(val1, val2, "_protocols", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'tls_config_set_protocols', %s",tls_config_set_protocols_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < tls_config_set_protocols_struct_inst.expectedCalls; opmock_i++) {
        tls_config_set_protocols_struct_inst.calls[opmock_i - 1] = tls_config_set_protocols_struct_inst.calls[opmock_i];
    }

    tls_config_set_protocols_struct_inst.expectedCalls--;
}

void tls_config_set_protocols_MockReset()
{
    tls_config_set_protocols_struct_inst.expectedCalls = 0;
    tls_config_set_protocols_struct_inst.actualCalls = 0;
    tls_config_set_protocols_struct_inst.callback = NULL;
}

void tls_config_set_protocols_MockWithCallback(OPMOCK_tls_config_set_protocols_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    tls_config_set_protocols_struct_inst.callback = callback;
    tls_config_set_protocols_struct_inst.expectedCalls = 0;
    tls_config_set_protocols_struct_inst.actualCalls = 0;
}

void tls_config_set_protocols_VerifyMock()
{
    if (tls_config_set_protocols_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'tls_config_set_protocols'",tls_config_set_protocols_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void tls_config_set_protocols_ExpectAndReturn (struct tls_config * _config, uint32_t _protocols, OPMOCK_MATCHER match__config, OPMOCK_MATCHER match__protocols)
{
    if(tls_config_set_protocols_struct_inst.callback != NULL)
    {
        tls_config_set_protocols_MockReset ();
    }

    if(tls_config_set_protocols_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting tls_config_set_protocols_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"void tls_config_set_protocols (struct tls_config * _config, uint32_t _protocols)");
    tls_config_set_protocols_struct_inst.calls[tls_config_set_protocols_struct_inst.expectedCalls]._config = (void *)_config;
    tls_config_set_protocols_struct_inst.calls[tls_config_set_protocols_struct_inst.expectedCalls]._protocols = (unsigned int)_protocols;
    tls_config_set_protocols_struct_inst.calls[tls_config_set_protocols_struct_inst.expectedCalls].match__config = match__config;
    tls_config_set_protocols_struct_inst.calls[tls_config_set_protocols_struct_inst.expectedCalls].match__protocols = match__protocols;
    tls_config_set_protocols_struct_inst.calls[tls_config_set_protocols_struct_inst.expectedCalls].check_params = 1;
    tls_config_set_protocols_struct_inst.expectedCalls++;
}

void tls_config_set_verify_depth(struct tls_config * _config, int _verify_depth)
{
    int opmock_i;
    tls_config_set_verify_depth_struct_inst.actualCalls++;

    if (tls_config_set_verify_depth_struct_inst.callback != NULL)
    {
        tls_config_set_verify_depth_struct_inst.callback (_config, _verify_depth, tls_config_set_verify_depth_struct_inst.actualCalls);
        return;
    }
    if (tls_config_set_verify_depth_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'tls_config_set_verify_depth', returning random value.");
        return;
    }

    if(strcmp(opmock_get_current_call(), "void tls_config_set_verify_depth (struct tls_config * _config, int _verify_depth)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'void tls_config_set_verify_depth(struct tls_config * _config, int _verify_depth)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (tls_config_set_verify_depth_struct_inst.calls[0].check_params == 1) {
        if(tls_config_set_verify_depth_struct_inst.calls[0].match__config) {
            void * val1 = (void *) &tls_config_set_verify_depth_struct_inst.calls[0]._config;
            void * val2 = (void *) &_config;
            int match_result = tls_config_set_verify_depth_struct_inst.calls[0].match__config(val1, val2, "_config", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'tls_config_set_verify_depth', %s",tls_config_set_verify_depth_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
        if(tls_config_set_verify_depth_struct_inst.calls[0].match__verify_depth) {
            void * val1 = (void *) &tls_config_set_verify_depth_struct_inst.calls[0]._verify_depth;
            void * val2 = (void *) &_verify_depth;
            int match_result = tls_config_set_verify_depth_struct_inst.calls[0].match__verify_depth(val1, val2, "_verify_depth", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'tls_config_set_verify_depth', %s",tls_config_set_verify_depth_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < tls_config_set_verify_depth_struct_inst.expectedCalls; opmock_i++) {
        tls_config_set_verify_depth_struct_inst.calls[opmock_i - 1] = tls_config_set_verify_depth_struct_inst.calls[opmock_i];
    }

    tls_config_set_verify_depth_struct_inst.expectedCalls--;
}

void tls_config_set_verify_depth_MockReset()
{
    tls_config_set_verify_depth_struct_inst.expectedCalls = 0;
    tls_config_set_verify_depth_struct_inst.actualCalls = 0;
    tls_config_set_verify_depth_struct_inst.callback = NULL;
}

void tls_config_set_verify_depth_MockWithCallback(OPMOCK_tls_config_set_verify_depth_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    tls_config_set_verify_depth_struct_inst.callback = callback;
    tls_config_set_verify_depth_struct_inst.expectedCalls = 0;
    tls_config_set_verify_depth_struct_inst.actualCalls = 0;
}

void tls_config_set_verify_depth_VerifyMock()
{
    if (tls_config_set_verify_depth_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'tls_config_set_verify_depth'",tls_config_set_verify_depth_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void tls_config_set_verify_depth_ExpectAndReturn (struct tls_config * _config, int _verify_depth, OPMOCK_MATCHER match__config, OPMOCK_MATCHER match__verify_depth)
{
    if(tls_config_set_verify_depth_struct_inst.callback != NULL)
    {
        tls_config_set_verify_depth_MockReset ();
    }

    if(tls_config_set_verify_depth_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting tls_config_set_verify_depth_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"void tls_config_set_verify_depth (struct tls_config * _config, int _verify_depth)");
    tls_config_set_verify_depth_struct_inst.calls[tls_config_set_verify_depth_struct_inst.expectedCalls]._config = (void *)_config;
    tls_config_set_verify_depth_struct_inst.calls[tls_config_set_verify_depth_struct_inst.expectedCalls]._verify_depth = (int)_verify_depth;
    tls_config_set_verify_depth_struct_inst.calls[tls_config_set_verify_depth_struct_inst.expectedCalls].match__config = match__config;
    tls_config_set_verify_depth_struct_inst.calls[tls_config_set_verify_depth_struct_inst.expectedCalls].match__verify_depth = match__verify_depth;
    tls_config_set_verify_depth_struct_inst.calls[tls_config_set_verify_depth_struct_inst.expectedCalls].check_params = 1;
    tls_config_set_verify_depth_struct_inst.expectedCalls++;
}

void tls_config_clear_keys(struct tls_config * _config)
{
    int opmock_i;
    tls_config_clear_keys_struct_inst.actualCalls++;

    if (tls_config_clear_keys_struct_inst.callback != NULL)
    {
        tls_config_clear_keys_struct_inst.callback (_config, tls_config_clear_keys_struct_inst.actualCalls);
        return;
    }
    if (tls_config_clear_keys_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'tls_config_clear_keys', returning random value.");
        return;
    }

    if(strcmp(opmock_get_current_call(), "void tls_config_clear_keys (struct tls_config * _config)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'void tls_config_clear_keys(struct tls_config * _config)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (tls_config_clear_keys_struct_inst.calls[0].check_params == 1) {
        if(tls_config_clear_keys_struct_inst.calls[0].match__config) {
            void * val1 = (void *) &tls_config_clear_keys_struct_inst.calls[0]._config;
            void * val2 = (void *) &_config;
            int match_result = tls_config_clear_keys_struct_inst.calls[0].match__config(val1, val2, "_config", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'tls_config_clear_keys', %s",tls_config_clear_keys_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < tls_config_clear_keys_struct_inst.expectedCalls; opmock_i++) {
        tls_config_clear_keys_struct_inst.calls[opmock_i - 1] = tls_config_clear_keys_struct_inst.calls[opmock_i];
    }

    tls_config_clear_keys_struct_inst.expectedCalls--;
}

void tls_config_clear_keys_MockReset()
{
    tls_config_clear_keys_struct_inst.expectedCalls = 0;
    tls_config_clear_keys_struct_inst.actualCalls = 0;
    tls_config_clear_keys_struct_inst.callback = NULL;
}

void tls_config_clear_keys_MockWithCallback(OPMOCK_tls_config_clear_keys_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    tls_config_clear_keys_struct_inst.callback = callback;
    tls_config_clear_keys_struct_inst.expectedCalls = 0;
    tls_config_clear_keys_struct_inst.actualCalls = 0;
}

void tls_config_clear_keys_VerifyMock()
{
    if (tls_config_clear_keys_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'tls_config_clear_keys'",tls_config_clear_keys_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void tls_config_clear_keys_ExpectAndReturn (struct tls_config * _config, OPMOCK_MATCHER match__config)
{
    if(tls_config_clear_keys_struct_inst.callback != NULL)
    {
        tls_config_clear_keys_MockReset ();
    }

    if(tls_config_clear_keys_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting tls_config_clear_keys_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"void tls_config_clear_keys (struct tls_config * _config)");
    tls_config_clear_keys_struct_inst.calls[tls_config_clear_keys_struct_inst.expectedCalls]._config = (void *)_config;
    tls_config_clear_keys_struct_inst.calls[tls_config_clear_keys_struct_inst.expectedCalls].match__config = match__config;
    tls_config_clear_keys_struct_inst.calls[tls_config_clear_keys_struct_inst.expectedCalls].check_params = 1;
    tls_config_clear_keys_struct_inst.expectedCalls++;
}

int tls_config_parse_protocols(uint32_t * _protocols, const char * _protostr)
{
    int default_res = (int)tls_config_parse_protocols_struct_inst.calls[0].to_return;
    int opmock_i;
    tls_config_parse_protocols_struct_inst.actualCalls++;

    if (tls_config_parse_protocols_struct_inst.callback != NULL)
    {
        return tls_config_parse_protocols_struct_inst.callback (_protocols, _protostr, tls_config_parse_protocols_struct_inst.actualCalls);
    }
    if (tls_config_parse_protocols_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'tls_config_parse_protocols', returning random value.");
        return default_res;
    }

    if(strcmp(opmock_get_current_call(), "int tls_config_parse_protocols (uint32_t * _protocols, const char * _protostr)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'int tls_config_parse_protocols(uint32_t * _protocols, const char * _protostr)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (tls_config_parse_protocols_struct_inst.calls[0].check_params == 1) {
        if(tls_config_parse_protocols_struct_inst.calls[0].match__protocols) {
            void * val1 = (void *) &tls_config_parse_protocols_struct_inst.calls[0]._protocols;
            void * val2 = (void *) &_protocols;
            int match_result = tls_config_parse_protocols_struct_inst.calls[0].match__protocols(val1, val2, "_protocols", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'tls_config_parse_protocols', %s",tls_config_parse_protocols_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
        if(tls_config_parse_protocols_struct_inst.calls[0].match__protostr) {
            void * val1 = (void *) &tls_config_parse_protocols_struct_inst.calls[0]._protostr;
            void * val2 = (void *) &_protostr;
            int match_result = tls_config_parse_protocols_struct_inst.calls[0].match__protostr(val1, val2, "_protostr", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'tls_config_parse_protocols', %s",tls_config_parse_protocols_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < tls_config_parse_protocols_struct_inst.expectedCalls; opmock_i++) {
        tls_config_parse_protocols_struct_inst.calls[opmock_i - 1] = tls_config_parse_protocols_struct_inst.calls[opmock_i];
    }

    tls_config_parse_protocols_struct_inst.expectedCalls--;
    return default_res;
}

void tls_config_parse_protocols_MockReset()
{
    tls_config_parse_protocols_struct_inst.expectedCalls = 0;
    tls_config_parse_protocols_struct_inst.actualCalls = 0;
    tls_config_parse_protocols_struct_inst.callback = NULL;
}

void tls_config_parse_protocols_MockWithCallback(OPMOCK_tls_config_parse_protocols_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    tls_config_parse_protocols_struct_inst.callback = callback;
    tls_config_parse_protocols_struct_inst.expectedCalls = 0;
    tls_config_parse_protocols_struct_inst.actualCalls = 0;
}

void tls_config_parse_protocols_VerifyMock()
{
    if (tls_config_parse_protocols_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'tls_config_parse_protocols'",tls_config_parse_protocols_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void tls_config_parse_protocols_ExpectAndReturn (uint32_t * _protocols, const char * _protostr, int to_return, OPMOCK_MATCHER match__protocols, OPMOCK_MATCHER match__protostr)
{
    if(tls_config_parse_protocols_struct_inst.callback != NULL)
    {
        tls_config_parse_protocols_MockReset ();
    }

    if(tls_config_parse_protocols_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting tls_config_parse_protocols_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"int tls_config_parse_protocols (uint32_t * _protocols, const char * _protostr)");
    tls_config_parse_protocols_struct_inst.calls[tls_config_parse_protocols_struct_inst.expectedCalls]._protocols = (void *)_protocols;
    tls_config_parse_protocols_struct_inst.calls[tls_config_parse_protocols_struct_inst.expectedCalls]._protostr = (void *)_protostr;
    tls_config_parse_protocols_struct_inst.calls[tls_config_parse_protocols_struct_inst.expectedCalls].match__protocols = match__protocols;
    tls_config_parse_protocols_struct_inst.calls[tls_config_parse_protocols_struct_inst.expectedCalls].match__protostr = match__protostr;
    tls_config_parse_protocols_struct_inst.calls[tls_config_parse_protocols_struct_inst.expectedCalls].to_return = (int) to_return;
    tls_config_parse_protocols_struct_inst.calls[tls_config_parse_protocols_struct_inst.expectedCalls].check_params = 1;
    tls_config_parse_protocols_struct_inst.expectedCalls++;
}

void tls_config_insecure_noverifycert(struct tls_config * _config)
{
    int opmock_i;
    tls_config_insecure_noverifycert_struct_inst.actualCalls++;

    if (tls_config_insecure_noverifycert_struct_inst.callback != NULL)
    {
        tls_config_insecure_noverifycert_struct_inst.callback (_config, tls_config_insecure_noverifycert_struct_inst.actualCalls);
        return;
    }
    if (tls_config_insecure_noverifycert_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'tls_config_insecure_noverifycert', returning random value.");
        return;
    }

    if(strcmp(opmock_get_current_call(), "void tls_config_insecure_noverifycert (struct tls_config * _config)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'void tls_config_insecure_noverifycert(struct tls_config * _config)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (tls_config_insecure_noverifycert_struct_inst.calls[0].check_params == 1) {
        if(tls_config_insecure_noverifycert_struct_inst.calls[0].match__config) {
            void * val1 = (void *) &tls_config_insecure_noverifycert_struct_inst.calls[0]._config;
            void * val2 = (void *) &_config;
            int match_result = tls_config_insecure_noverifycert_struct_inst.calls[0].match__config(val1, val2, "_config", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'tls_config_insecure_noverifycert', %s",tls_config_insecure_noverifycert_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < tls_config_insecure_noverifycert_struct_inst.expectedCalls; opmock_i++) {
        tls_config_insecure_noverifycert_struct_inst.calls[opmock_i - 1] = tls_config_insecure_noverifycert_struct_inst.calls[opmock_i];
    }

    tls_config_insecure_noverifycert_struct_inst.expectedCalls--;
}

void tls_config_insecure_noverifycert_MockReset()
{
    tls_config_insecure_noverifycert_struct_inst.expectedCalls = 0;
    tls_config_insecure_noverifycert_struct_inst.actualCalls = 0;
    tls_config_insecure_noverifycert_struct_inst.callback = NULL;
}

void tls_config_insecure_noverifycert_MockWithCallback(OPMOCK_tls_config_insecure_noverifycert_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    tls_config_insecure_noverifycert_struct_inst.callback = callback;
    tls_config_insecure_noverifycert_struct_inst.expectedCalls = 0;
    tls_config_insecure_noverifycert_struct_inst.actualCalls = 0;
}

void tls_config_insecure_noverifycert_VerifyMock()
{
    if (tls_config_insecure_noverifycert_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'tls_config_insecure_noverifycert'",tls_config_insecure_noverifycert_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void tls_config_insecure_noverifycert_ExpectAndReturn (struct tls_config * _config, OPMOCK_MATCHER match__config)
{
    if(tls_config_insecure_noverifycert_struct_inst.callback != NULL)
    {
        tls_config_insecure_noverifycert_MockReset ();
    }

    if(tls_config_insecure_noverifycert_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting tls_config_insecure_noverifycert_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"void tls_config_insecure_noverifycert (struct tls_config * _config)");
    tls_config_insecure_noverifycert_struct_inst.calls[tls_config_insecure_noverifycert_struct_inst.expectedCalls]._config = (void *)_config;
    tls_config_insecure_noverifycert_struct_inst.calls[tls_config_insecure_noverifycert_struct_inst.expectedCalls].match__config = match__config;
    tls_config_insecure_noverifycert_struct_inst.calls[tls_config_insecure_noverifycert_struct_inst.expectedCalls].check_params = 1;
    tls_config_insecure_noverifycert_struct_inst.expectedCalls++;
}

void tls_config_insecure_noverifyname(struct tls_config * _config)
{
    int opmock_i;
    tls_config_insecure_noverifyname_struct_inst.actualCalls++;

    if (tls_config_insecure_noverifyname_struct_inst.callback != NULL)
    {
        tls_config_insecure_noverifyname_struct_inst.callback (_config, tls_config_insecure_noverifyname_struct_inst.actualCalls);
        return;
    }
    if (tls_config_insecure_noverifyname_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'tls_config_insecure_noverifyname', returning random value.");
        return;
    }

    if(strcmp(opmock_get_current_call(), "void tls_config_insecure_noverifyname (struct tls_config * _config)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'void tls_config_insecure_noverifyname(struct tls_config * _config)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (tls_config_insecure_noverifyname_struct_inst.calls[0].check_params == 1) {
        if(tls_config_insecure_noverifyname_struct_inst.calls[0].match__config) {
            void * val1 = (void *) &tls_config_insecure_noverifyname_struct_inst.calls[0]._config;
            void * val2 = (void *) &_config;
            int match_result = tls_config_insecure_noverifyname_struct_inst.calls[0].match__config(val1, val2, "_config", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'tls_config_insecure_noverifyname', %s",tls_config_insecure_noverifyname_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < tls_config_insecure_noverifyname_struct_inst.expectedCalls; opmock_i++) {
        tls_config_insecure_noverifyname_struct_inst.calls[opmock_i - 1] = tls_config_insecure_noverifyname_struct_inst.calls[opmock_i];
    }

    tls_config_insecure_noverifyname_struct_inst.expectedCalls--;
}

void tls_config_insecure_noverifyname_MockReset()
{
    tls_config_insecure_noverifyname_struct_inst.expectedCalls = 0;
    tls_config_insecure_noverifyname_struct_inst.actualCalls = 0;
    tls_config_insecure_noverifyname_struct_inst.callback = NULL;
}

void tls_config_insecure_noverifyname_MockWithCallback(OPMOCK_tls_config_insecure_noverifyname_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    tls_config_insecure_noverifyname_struct_inst.callback = callback;
    tls_config_insecure_noverifyname_struct_inst.expectedCalls = 0;
    tls_config_insecure_noverifyname_struct_inst.actualCalls = 0;
}

void tls_config_insecure_noverifyname_VerifyMock()
{
    if (tls_config_insecure_noverifyname_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'tls_config_insecure_noverifyname'",tls_config_insecure_noverifyname_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void tls_config_insecure_noverifyname_ExpectAndReturn (struct tls_config * _config, OPMOCK_MATCHER match__config)
{
    if(tls_config_insecure_noverifyname_struct_inst.callback != NULL)
    {
        tls_config_insecure_noverifyname_MockReset ();
    }

    if(tls_config_insecure_noverifyname_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting tls_config_insecure_noverifyname_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"void tls_config_insecure_noverifyname (struct tls_config * _config)");
    tls_config_insecure_noverifyname_struct_inst.calls[tls_config_insecure_noverifyname_struct_inst.expectedCalls]._config = (void *)_config;
    tls_config_insecure_noverifyname_struct_inst.calls[tls_config_insecure_noverifyname_struct_inst.expectedCalls].match__config = match__config;
    tls_config_insecure_noverifyname_struct_inst.calls[tls_config_insecure_noverifyname_struct_inst.expectedCalls].check_params = 1;
    tls_config_insecure_noverifyname_struct_inst.expectedCalls++;
}

void tls_config_verify(struct tls_config * _config)
{
    int opmock_i;
    tls_config_verify_struct_inst.actualCalls++;

    if (tls_config_verify_struct_inst.callback != NULL)
    {
        tls_config_verify_struct_inst.callback (_config, tls_config_verify_struct_inst.actualCalls);
        return;
    }
    if (tls_config_verify_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'tls_config_verify', returning random value.");
        return;
    }

    if(strcmp(opmock_get_current_call(), "void tls_config_verify (struct tls_config * _config)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'void tls_config_verify(struct tls_config * _config)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (tls_config_verify_struct_inst.calls[0].check_params == 1) {
        if(tls_config_verify_struct_inst.calls[0].match__config) {
            void * val1 = (void *) &tls_config_verify_struct_inst.calls[0]._config;
            void * val2 = (void *) &_config;
            int match_result = tls_config_verify_struct_inst.calls[0].match__config(val1, val2, "_config", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'tls_config_verify', %s",tls_config_verify_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < tls_config_verify_struct_inst.expectedCalls; opmock_i++) {
        tls_config_verify_struct_inst.calls[opmock_i - 1] = tls_config_verify_struct_inst.calls[opmock_i];
    }

    tls_config_verify_struct_inst.expectedCalls--;
}

void tls_config_verify_MockReset()
{
    tls_config_verify_struct_inst.expectedCalls = 0;
    tls_config_verify_struct_inst.actualCalls = 0;
    tls_config_verify_struct_inst.callback = NULL;
}

void tls_config_verify_MockWithCallback(OPMOCK_tls_config_verify_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    tls_config_verify_struct_inst.callback = callback;
    tls_config_verify_struct_inst.expectedCalls = 0;
    tls_config_verify_struct_inst.actualCalls = 0;
}

void tls_config_verify_VerifyMock()
{
    if (tls_config_verify_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'tls_config_verify'",tls_config_verify_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void tls_config_verify_ExpectAndReturn (struct tls_config * _config, OPMOCK_MATCHER match__config)
{
    if(tls_config_verify_struct_inst.callback != NULL)
    {
        tls_config_verify_MockReset ();
    }

    if(tls_config_verify_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting tls_config_verify_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"void tls_config_verify (struct tls_config * _config)");
    tls_config_verify_struct_inst.calls[tls_config_verify_struct_inst.expectedCalls]._config = (void *)_config;
    tls_config_verify_struct_inst.calls[tls_config_verify_struct_inst.expectedCalls].match__config = match__config;
    tls_config_verify_struct_inst.calls[tls_config_verify_struct_inst.expectedCalls].check_params = 1;
    tls_config_verify_struct_inst.expectedCalls++;
}

struct tls * tls_client()
{
    struct tls * default_res = (struct tls *)tls_client_struct_inst.calls[0].to_return;
    int opmock_i;
    tls_client_struct_inst.actualCalls++;

    if (tls_client_struct_inst.callback != NULL)
    {
        return tls_client_struct_inst.callback (tls_client_struct_inst.actualCalls);
    }
    if (tls_client_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'tls_client', returning random value.");
        return default_res;
    }

    if(strcmp(opmock_get_current_call(), "struct tls * tls_client ()") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'struct tls * tls_client()',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (tls_client_struct_inst.calls[0].check_params == 1) {
    }

    for(opmock_i = 1; opmock_i < tls_client_struct_inst.expectedCalls; opmock_i++) {
        tls_client_struct_inst.calls[opmock_i - 1] = tls_client_struct_inst.calls[opmock_i];
    }

    tls_client_struct_inst.expectedCalls--;
    return default_res;
}

void tls_client_MockReset()
{
    tls_client_struct_inst.expectedCalls = 0;
    tls_client_struct_inst.actualCalls = 0;
    tls_client_struct_inst.callback = NULL;
}

void tls_client_MockWithCallback(OPMOCK_tls_client_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    tls_client_struct_inst.callback = callback;
    tls_client_struct_inst.expectedCalls = 0;
    tls_client_struct_inst.actualCalls = 0;
}

void tls_client_VerifyMock()
{
    if (tls_client_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'tls_client'",tls_client_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void tls_client_ExpectAndReturn (struct tls * to_return)
{
    if(tls_client_struct_inst.callback != NULL)
    {
        tls_client_MockReset ();
    }

    if(tls_client_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting tls_client_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"struct tls * tls_client ()");
    tls_client_struct_inst.calls[tls_client_struct_inst.expectedCalls].to_return = (struct tls *) to_return;
    tls_client_struct_inst.calls[tls_client_struct_inst.expectedCalls].check_params = 1;
    tls_client_struct_inst.expectedCalls++;
}

struct tls * tls_server()
{
    struct tls * default_res = (struct tls *)tls_server_struct_inst.calls[0].to_return;
    int opmock_i;
    tls_server_struct_inst.actualCalls++;

    if (tls_server_struct_inst.callback != NULL)
    {
        return tls_server_struct_inst.callback (tls_server_struct_inst.actualCalls);
    }
    if (tls_server_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'tls_server', returning random value.");
        return default_res;
    }

    if(strcmp(opmock_get_current_call(), "struct tls * tls_server ()") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'struct tls * tls_server()',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (tls_server_struct_inst.calls[0].check_params == 1) {
    }

    for(opmock_i = 1; opmock_i < tls_server_struct_inst.expectedCalls; opmock_i++) {
        tls_server_struct_inst.calls[opmock_i - 1] = tls_server_struct_inst.calls[opmock_i];
    }

    tls_server_struct_inst.expectedCalls--;
    return default_res;
}

void tls_server_MockReset()
{
    tls_server_struct_inst.expectedCalls = 0;
    tls_server_struct_inst.actualCalls = 0;
    tls_server_struct_inst.callback = NULL;
}

void tls_server_MockWithCallback(OPMOCK_tls_server_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    tls_server_struct_inst.callback = callback;
    tls_server_struct_inst.expectedCalls = 0;
    tls_server_struct_inst.actualCalls = 0;
}

void tls_server_VerifyMock()
{
    if (tls_server_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'tls_server'",tls_server_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void tls_server_ExpectAndReturn (struct tls * to_return)
{
    if(tls_server_struct_inst.callback != NULL)
    {
        tls_server_MockReset ();
    }

    if(tls_server_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting tls_server_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"struct tls * tls_server ()");
    tls_server_struct_inst.calls[tls_server_struct_inst.expectedCalls].to_return = (struct tls *) to_return;
    tls_server_struct_inst.calls[tls_server_struct_inst.expectedCalls].check_params = 1;
    tls_server_struct_inst.expectedCalls++;
}

int tls_configure(struct tls * _ctx, struct tls_config * _config)
{
    int default_res = (int)tls_configure_struct_inst.calls[0].to_return;
    int opmock_i;
    tls_configure_struct_inst.actualCalls++;

    if (tls_configure_struct_inst.callback != NULL)
    {
        return tls_configure_struct_inst.callback (_ctx, _config, tls_configure_struct_inst.actualCalls);
    }
    if (tls_configure_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'tls_configure', returning random value.");
        return default_res;
    }

    if(strcmp(opmock_get_current_call(), "int tls_configure (struct tls * _ctx, struct tls_config * _config)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'int tls_configure(struct tls * _ctx, struct tls_config * _config)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (tls_configure_struct_inst.calls[0].check_params == 1) {
        if(tls_configure_struct_inst.calls[0].match__ctx) {
            void * val1 = (void *) &tls_configure_struct_inst.calls[0]._ctx;
            void * val2 = (void *) &_ctx;
            int match_result = tls_configure_struct_inst.calls[0].match__ctx(val1, val2, "_ctx", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'tls_configure', %s",tls_configure_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
        if(tls_configure_struct_inst.calls[0].match__config) {
            void * val1 = (void *) &tls_configure_struct_inst.calls[0]._config;
            void * val2 = (void *) &_config;
            int match_result = tls_configure_struct_inst.calls[0].match__config(val1, val2, "_config", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'tls_configure', %s",tls_configure_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < tls_configure_struct_inst.expectedCalls; opmock_i++) {
        tls_configure_struct_inst.calls[opmock_i - 1] = tls_configure_struct_inst.calls[opmock_i];
    }

    tls_configure_struct_inst.expectedCalls--;
    return default_res;
}

void tls_configure_MockReset()
{
    tls_configure_struct_inst.expectedCalls = 0;
    tls_configure_struct_inst.actualCalls = 0;
    tls_configure_struct_inst.callback = NULL;
}

void tls_configure_MockWithCallback(OPMOCK_tls_configure_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    tls_configure_struct_inst.callback = callback;
    tls_configure_struct_inst.expectedCalls = 0;
    tls_configure_struct_inst.actualCalls = 0;
}

void tls_configure_VerifyMock()
{
    if (tls_configure_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'tls_configure'",tls_configure_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void tls_configure_ExpectAndReturn (struct tls * _ctx, struct tls_config * _config, int to_return, OPMOCK_MATCHER match__ctx, OPMOCK_MATCHER match__config)
{
    if(tls_configure_struct_inst.callback != NULL)
    {
        tls_configure_MockReset ();
    }

    if(tls_configure_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting tls_configure_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"int tls_configure (struct tls * _ctx, struct tls_config * _config)");
    tls_configure_struct_inst.calls[tls_configure_struct_inst.expectedCalls]._ctx = (void *)_ctx;
    tls_configure_struct_inst.calls[tls_configure_struct_inst.expectedCalls]._config = (void *)_config;
    tls_configure_struct_inst.calls[tls_configure_struct_inst.expectedCalls].match__ctx = match__ctx;
    tls_configure_struct_inst.calls[tls_configure_struct_inst.expectedCalls].match__config = match__config;
    tls_configure_struct_inst.calls[tls_configure_struct_inst.expectedCalls].to_return = (int) to_return;
    tls_configure_struct_inst.calls[tls_configure_struct_inst.expectedCalls].check_params = 1;
    tls_configure_struct_inst.expectedCalls++;
}

void tls_reset(struct tls * _ctx)
{
    int opmock_i;
    tls_reset_struct_inst.actualCalls++;

    if (tls_reset_struct_inst.callback != NULL)
    {
        tls_reset_struct_inst.callback (_ctx, tls_reset_struct_inst.actualCalls);
        return;
    }
    if (tls_reset_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'tls_reset', returning random value.");
        return;
    }

    if(strcmp(opmock_get_current_call(), "void tls_reset (struct tls * _ctx)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'void tls_reset(struct tls * _ctx)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (tls_reset_struct_inst.calls[0].check_params == 1) {
        if(tls_reset_struct_inst.calls[0].match__ctx) {
            void * val1 = (void *) &tls_reset_struct_inst.calls[0]._ctx;
            void * val2 = (void *) &_ctx;
            int match_result = tls_reset_struct_inst.calls[0].match__ctx(val1, val2, "_ctx", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'tls_reset', %s",tls_reset_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < tls_reset_struct_inst.expectedCalls; opmock_i++) {
        tls_reset_struct_inst.calls[opmock_i - 1] = tls_reset_struct_inst.calls[opmock_i];
    }

    tls_reset_struct_inst.expectedCalls--;
}

void tls_reset_MockReset()
{
    tls_reset_struct_inst.expectedCalls = 0;
    tls_reset_struct_inst.actualCalls = 0;
    tls_reset_struct_inst.callback = NULL;
}

void tls_reset_MockWithCallback(OPMOCK_tls_reset_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    tls_reset_struct_inst.callback = callback;
    tls_reset_struct_inst.expectedCalls = 0;
    tls_reset_struct_inst.actualCalls = 0;
}

void tls_reset_VerifyMock()
{
    if (tls_reset_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'tls_reset'",tls_reset_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void tls_reset_ExpectAndReturn (struct tls * _ctx, OPMOCK_MATCHER match__ctx)
{
    if(tls_reset_struct_inst.callback != NULL)
    {
        tls_reset_MockReset ();
    }

    if(tls_reset_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting tls_reset_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"void tls_reset (struct tls * _ctx)");
    tls_reset_struct_inst.calls[tls_reset_struct_inst.expectedCalls]._ctx = (void *)_ctx;
    tls_reset_struct_inst.calls[tls_reset_struct_inst.expectedCalls].match__ctx = match__ctx;
    tls_reset_struct_inst.calls[tls_reset_struct_inst.expectedCalls].check_params = 1;
    tls_reset_struct_inst.expectedCalls++;
}

void tls_free(struct tls * _ctx)
{
    int opmock_i;
    tls_free_struct_inst.actualCalls++;

    if (tls_free_struct_inst.callback != NULL)
    {
        tls_free_struct_inst.callback (_ctx, tls_free_struct_inst.actualCalls);
        return;
    }
    if (tls_free_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'tls_free', returning random value.");
        return;
    }

    if(strcmp(opmock_get_current_call(), "void tls_free (struct tls * _ctx)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'void tls_free(struct tls * _ctx)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (tls_free_struct_inst.calls[0].check_params == 1) {
        if(tls_free_struct_inst.calls[0].match__ctx) {
            void * val1 = (void *) &tls_free_struct_inst.calls[0]._ctx;
            void * val2 = (void *) &_ctx;
            int match_result = tls_free_struct_inst.calls[0].match__ctx(val1, val2, "_ctx", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'tls_free', %s",tls_free_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < tls_free_struct_inst.expectedCalls; opmock_i++) {
        tls_free_struct_inst.calls[opmock_i - 1] = tls_free_struct_inst.calls[opmock_i];
    }

    tls_free_struct_inst.expectedCalls--;
}

void tls_free_MockReset()
{
    tls_free_struct_inst.expectedCalls = 0;
    tls_free_struct_inst.actualCalls = 0;
    tls_free_struct_inst.callback = NULL;
}

void tls_free_MockWithCallback(OPMOCK_tls_free_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    tls_free_struct_inst.callback = callback;
    tls_free_struct_inst.expectedCalls = 0;
    tls_free_struct_inst.actualCalls = 0;
}

void tls_free_VerifyMock()
{
    if (tls_free_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'tls_free'",tls_free_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void tls_free_ExpectAndReturn (struct tls * _ctx, OPMOCK_MATCHER match__ctx)
{
    if(tls_free_struct_inst.callback != NULL)
    {
        tls_free_MockReset ();
    }

    if(tls_free_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting tls_free_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"void tls_free (struct tls * _ctx)");
    tls_free_struct_inst.calls[tls_free_struct_inst.expectedCalls]._ctx = (void *)_ctx;
    tls_free_struct_inst.calls[tls_free_struct_inst.expectedCalls].match__ctx = match__ctx;
    tls_free_struct_inst.calls[tls_free_struct_inst.expectedCalls].check_params = 1;
    tls_free_struct_inst.expectedCalls++;
}

int tls_accept_fds(struct tls * _ctx, struct tls ** _cctx, int _fd_read, int _fd_write)
{
    int default_res = (int)tls_accept_fds_struct_inst.calls[0].to_return;
    int opmock_i;
    tls_accept_fds_struct_inst.actualCalls++;

    if (tls_accept_fds_struct_inst.callback != NULL)
    {
        return tls_accept_fds_struct_inst.callback (_ctx, _cctx, _fd_read, _fd_write, tls_accept_fds_struct_inst.actualCalls);
    }
    if (tls_accept_fds_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'tls_accept_fds', returning random value.");
        return default_res;
    }

    if(strcmp(opmock_get_current_call(), "int tls_accept_fds (struct tls * _ctx, struct tls ** _cctx, int _fd_read, int _fd_write)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'int tls_accept_fds(struct tls * _ctx, struct tls ** _cctx, int _fd_read, int _fd_write)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (tls_accept_fds_struct_inst.calls[0].check_params == 1) {
        if(tls_accept_fds_struct_inst.calls[0].match__ctx) {
            void * val1 = (void *) &tls_accept_fds_struct_inst.calls[0]._ctx;
            void * val2 = (void *) &_ctx;
            int match_result = tls_accept_fds_struct_inst.calls[0].match__ctx(val1, val2, "_ctx", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'tls_accept_fds', %s",tls_accept_fds_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
        if(tls_accept_fds_struct_inst.calls[0].match__cctx) {
            void * val1 = (void *) &tls_accept_fds_struct_inst.calls[0]._cctx;
            void * val2 = (void *) &_cctx;
            int match_result = tls_accept_fds_struct_inst.calls[0].match__cctx(val1, val2, "_cctx", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'tls_accept_fds', %s",tls_accept_fds_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
        if(tls_accept_fds_struct_inst.calls[0].match__fd_read) {
            void * val1 = (void *) &tls_accept_fds_struct_inst.calls[0]._fd_read;
            void * val2 = (void *) &_fd_read;
            int match_result = tls_accept_fds_struct_inst.calls[0].match__fd_read(val1, val2, "_fd_read", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'tls_accept_fds', %s",tls_accept_fds_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
        if(tls_accept_fds_struct_inst.calls[0].match__fd_write) {
            void * val1 = (void *) &tls_accept_fds_struct_inst.calls[0]._fd_write;
            void * val2 = (void *) &_fd_write;
            int match_result = tls_accept_fds_struct_inst.calls[0].match__fd_write(val1, val2, "_fd_write", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'tls_accept_fds', %s",tls_accept_fds_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < tls_accept_fds_struct_inst.expectedCalls; opmock_i++) {
        tls_accept_fds_struct_inst.calls[opmock_i - 1] = tls_accept_fds_struct_inst.calls[opmock_i];
    }

    tls_accept_fds_struct_inst.expectedCalls--;
    return default_res;
}

void tls_accept_fds_MockReset()
{
    tls_accept_fds_struct_inst.expectedCalls = 0;
    tls_accept_fds_struct_inst.actualCalls = 0;
    tls_accept_fds_struct_inst.callback = NULL;
}

void tls_accept_fds_MockWithCallback(OPMOCK_tls_accept_fds_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    tls_accept_fds_struct_inst.callback = callback;
    tls_accept_fds_struct_inst.expectedCalls = 0;
    tls_accept_fds_struct_inst.actualCalls = 0;
}

void tls_accept_fds_VerifyMock()
{
    if (tls_accept_fds_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'tls_accept_fds'",tls_accept_fds_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void tls_accept_fds_ExpectAndReturn (struct tls * _ctx, struct tls ** _cctx, int _fd_read, int _fd_write, int to_return, OPMOCK_MATCHER match__ctx, OPMOCK_MATCHER match__cctx, OPMOCK_MATCHER match__fd_read, OPMOCK_MATCHER match__fd_write)
{
    if(tls_accept_fds_struct_inst.callback != NULL)
    {
        tls_accept_fds_MockReset ();
    }

    if(tls_accept_fds_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting tls_accept_fds_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"int tls_accept_fds (struct tls * _ctx, struct tls ** _cctx, int _fd_read, int _fd_write)");
    tls_accept_fds_struct_inst.calls[tls_accept_fds_struct_inst.expectedCalls]._ctx = (void *)_ctx;
    tls_accept_fds_struct_inst.calls[tls_accept_fds_struct_inst.expectedCalls]._cctx = (void *)_cctx;
    tls_accept_fds_struct_inst.calls[tls_accept_fds_struct_inst.expectedCalls]._fd_read = (int)_fd_read;
    tls_accept_fds_struct_inst.calls[tls_accept_fds_struct_inst.expectedCalls]._fd_write = (int)_fd_write;
    tls_accept_fds_struct_inst.calls[tls_accept_fds_struct_inst.expectedCalls].match__ctx = match__ctx;
    tls_accept_fds_struct_inst.calls[tls_accept_fds_struct_inst.expectedCalls].match__cctx = match__cctx;
    tls_accept_fds_struct_inst.calls[tls_accept_fds_struct_inst.expectedCalls].match__fd_read = match__fd_read;
    tls_accept_fds_struct_inst.calls[tls_accept_fds_struct_inst.expectedCalls].match__fd_write = match__fd_write;
    tls_accept_fds_struct_inst.calls[tls_accept_fds_struct_inst.expectedCalls].to_return = (int) to_return;
    tls_accept_fds_struct_inst.calls[tls_accept_fds_struct_inst.expectedCalls].check_params = 1;
    tls_accept_fds_struct_inst.expectedCalls++;
}

int tls_accept_socket(struct tls * _ctx, struct tls ** _cctx, int _socket)
{
    int default_res = (int)tls_accept_socket_struct_inst.calls[0].to_return;
    int opmock_i;
    tls_accept_socket_struct_inst.actualCalls++;

    if (tls_accept_socket_struct_inst.callback != NULL)
    {
        return tls_accept_socket_struct_inst.callback (_ctx, _cctx, _socket, tls_accept_socket_struct_inst.actualCalls);
    }
    if (tls_accept_socket_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'tls_accept_socket', returning random value.");
        return default_res;
    }

    if(strcmp(opmock_get_current_call(), "int tls_accept_socket (struct tls * _ctx, struct tls ** _cctx, int _socket)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'int tls_accept_socket(struct tls * _ctx, struct tls ** _cctx, int _socket)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (tls_accept_socket_struct_inst.calls[0].check_params == 1) {
        if(tls_accept_socket_struct_inst.calls[0].match__ctx) {
            void * val1 = (void *) &tls_accept_socket_struct_inst.calls[0]._ctx;
            void * val2 = (void *) &_ctx;
            int match_result = tls_accept_socket_struct_inst.calls[0].match__ctx(val1, val2, "_ctx", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'tls_accept_socket', %s",tls_accept_socket_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
        if(tls_accept_socket_struct_inst.calls[0].match__cctx) {
            void * val1 = (void *) &tls_accept_socket_struct_inst.calls[0]._cctx;
            void * val2 = (void *) &_cctx;
            int match_result = tls_accept_socket_struct_inst.calls[0].match__cctx(val1, val2, "_cctx", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'tls_accept_socket', %s",tls_accept_socket_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
        if(tls_accept_socket_struct_inst.calls[0].match__socket) {
            void * val1 = (void *) &tls_accept_socket_struct_inst.calls[0]._socket;
            void * val2 = (void *) &_socket;
            int match_result = tls_accept_socket_struct_inst.calls[0].match__socket(val1, val2, "_socket", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'tls_accept_socket', %s",tls_accept_socket_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < tls_accept_socket_struct_inst.expectedCalls; opmock_i++) {
        tls_accept_socket_struct_inst.calls[opmock_i - 1] = tls_accept_socket_struct_inst.calls[opmock_i];
    }

    tls_accept_socket_struct_inst.expectedCalls--;
    return default_res;
}

void tls_accept_socket_MockReset()
{
    tls_accept_socket_struct_inst.expectedCalls = 0;
    tls_accept_socket_struct_inst.actualCalls = 0;
    tls_accept_socket_struct_inst.callback = NULL;
}

void tls_accept_socket_MockWithCallback(OPMOCK_tls_accept_socket_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    tls_accept_socket_struct_inst.callback = callback;
    tls_accept_socket_struct_inst.expectedCalls = 0;
    tls_accept_socket_struct_inst.actualCalls = 0;
}

void tls_accept_socket_VerifyMock()
{
    if (tls_accept_socket_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'tls_accept_socket'",tls_accept_socket_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void tls_accept_socket_ExpectAndReturn (struct tls * _ctx, struct tls ** _cctx, int _socket, int to_return, OPMOCK_MATCHER match__ctx, OPMOCK_MATCHER match__cctx, OPMOCK_MATCHER match__socket)
{
    if(tls_accept_socket_struct_inst.callback != NULL)
    {
        tls_accept_socket_MockReset ();
    }

    if(tls_accept_socket_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting tls_accept_socket_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"int tls_accept_socket (struct tls * _ctx, struct tls ** _cctx, int _socket)");
    tls_accept_socket_struct_inst.calls[tls_accept_socket_struct_inst.expectedCalls]._ctx = (void *)_ctx;
    tls_accept_socket_struct_inst.calls[tls_accept_socket_struct_inst.expectedCalls]._cctx = (void *)_cctx;
    tls_accept_socket_struct_inst.calls[tls_accept_socket_struct_inst.expectedCalls]._socket = (int)_socket;
    tls_accept_socket_struct_inst.calls[tls_accept_socket_struct_inst.expectedCalls].match__ctx = match__ctx;
    tls_accept_socket_struct_inst.calls[tls_accept_socket_struct_inst.expectedCalls].match__cctx = match__cctx;
    tls_accept_socket_struct_inst.calls[tls_accept_socket_struct_inst.expectedCalls].match__socket = match__socket;
    tls_accept_socket_struct_inst.calls[tls_accept_socket_struct_inst.expectedCalls].to_return = (int) to_return;
    tls_accept_socket_struct_inst.calls[tls_accept_socket_struct_inst.expectedCalls].check_params = 1;
    tls_accept_socket_struct_inst.expectedCalls++;
}

int tls_connect(struct tls * _ctx, const char * _host, const char * _port)
{
    int default_res = (int)tls_connect_struct_inst.calls[0].to_return;
    int opmock_i;
    tls_connect_struct_inst.actualCalls++;

    if (tls_connect_struct_inst.callback != NULL)
    {
        return tls_connect_struct_inst.callback (_ctx, _host, _port, tls_connect_struct_inst.actualCalls);
    }
    if (tls_connect_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'tls_connect', returning random value.");
        return default_res;
    }

    if(strcmp(opmock_get_current_call(), "int tls_connect (struct tls * _ctx, const char * _host, const char * _port)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'int tls_connect(struct tls * _ctx, const char * _host, const char * _port)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (tls_connect_struct_inst.calls[0].check_params == 1) {
        if(tls_connect_struct_inst.calls[0].match__ctx) {
            void * val1 = (void *) &tls_connect_struct_inst.calls[0]._ctx;
            void * val2 = (void *) &_ctx;
            int match_result = tls_connect_struct_inst.calls[0].match__ctx(val1, val2, "_ctx", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'tls_connect', %s",tls_connect_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
        if(tls_connect_struct_inst.calls[0].match__host) {
            void * val1 = (void *) &tls_connect_struct_inst.calls[0]._host;
            void * val2 = (void *) &_host;
            int match_result = tls_connect_struct_inst.calls[0].match__host(val1, val2, "_host", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'tls_connect', %s",tls_connect_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
        if(tls_connect_struct_inst.calls[0].match__port) {
            void * val1 = (void *) &tls_connect_struct_inst.calls[0]._port;
            void * val2 = (void *) &_port;
            int match_result = tls_connect_struct_inst.calls[0].match__port(val1, val2, "_port", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'tls_connect', %s",tls_connect_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < tls_connect_struct_inst.expectedCalls; opmock_i++) {
        tls_connect_struct_inst.calls[opmock_i - 1] = tls_connect_struct_inst.calls[opmock_i];
    }

    tls_connect_struct_inst.expectedCalls--;
    return default_res;
}

void tls_connect_MockReset()
{
    tls_connect_struct_inst.expectedCalls = 0;
    tls_connect_struct_inst.actualCalls = 0;
    tls_connect_struct_inst.callback = NULL;
}

void tls_connect_MockWithCallback(OPMOCK_tls_connect_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    tls_connect_struct_inst.callback = callback;
    tls_connect_struct_inst.expectedCalls = 0;
    tls_connect_struct_inst.actualCalls = 0;
}

void tls_connect_VerifyMock()
{
    if (tls_connect_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'tls_connect'",tls_connect_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void tls_connect_ExpectAndReturn (struct tls * _ctx, const char * _host, const char * _port, int to_return, OPMOCK_MATCHER match__ctx, OPMOCK_MATCHER match__host, OPMOCK_MATCHER match__port)
{
    if(tls_connect_struct_inst.callback != NULL)
    {
        tls_connect_MockReset ();
    }

    if(tls_connect_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting tls_connect_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"int tls_connect (struct tls * _ctx, const char * _host, const char * _port)");
    tls_connect_struct_inst.calls[tls_connect_struct_inst.expectedCalls]._ctx = (void *)_ctx;
    tls_connect_struct_inst.calls[tls_connect_struct_inst.expectedCalls]._host = (void *)_host;
    tls_connect_struct_inst.calls[tls_connect_struct_inst.expectedCalls]._port = (void *)_port;
    tls_connect_struct_inst.calls[tls_connect_struct_inst.expectedCalls].match__ctx = match__ctx;
    tls_connect_struct_inst.calls[tls_connect_struct_inst.expectedCalls].match__host = match__host;
    tls_connect_struct_inst.calls[tls_connect_struct_inst.expectedCalls].match__port = match__port;
    tls_connect_struct_inst.calls[tls_connect_struct_inst.expectedCalls].to_return = (int) to_return;
    tls_connect_struct_inst.calls[tls_connect_struct_inst.expectedCalls].check_params = 1;
    tls_connect_struct_inst.expectedCalls++;
}

int tls_connect_fds(struct tls * _ctx, int _fd_read, int _fd_write, const char * _servername)
{
    int default_res = (int)tls_connect_fds_struct_inst.calls[0].to_return;
    int opmock_i;
    tls_connect_fds_struct_inst.actualCalls++;

    if (tls_connect_fds_struct_inst.callback != NULL)
    {
        return tls_connect_fds_struct_inst.callback (_ctx, _fd_read, _fd_write, _servername, tls_connect_fds_struct_inst.actualCalls);
    }
    if (tls_connect_fds_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'tls_connect_fds', returning random value.");
        return default_res;
    }

    if(strcmp(opmock_get_current_call(), "int tls_connect_fds (struct tls * _ctx, int _fd_read, int _fd_write, const char * _servername)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'int tls_connect_fds(struct tls * _ctx, int _fd_read, int _fd_write, const char * _servername)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (tls_connect_fds_struct_inst.calls[0].check_params == 1) {
        if(tls_connect_fds_struct_inst.calls[0].match__ctx) {
            void * val1 = (void *) &tls_connect_fds_struct_inst.calls[0]._ctx;
            void * val2 = (void *) &_ctx;
            int match_result = tls_connect_fds_struct_inst.calls[0].match__ctx(val1, val2, "_ctx", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'tls_connect_fds', %s",tls_connect_fds_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
        if(tls_connect_fds_struct_inst.calls[0].match__fd_read) {
            void * val1 = (void *) &tls_connect_fds_struct_inst.calls[0]._fd_read;
            void * val2 = (void *) &_fd_read;
            int match_result = tls_connect_fds_struct_inst.calls[0].match__fd_read(val1, val2, "_fd_read", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'tls_connect_fds', %s",tls_connect_fds_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
        if(tls_connect_fds_struct_inst.calls[0].match__fd_write) {
            void * val1 = (void *) &tls_connect_fds_struct_inst.calls[0]._fd_write;
            void * val2 = (void *) &_fd_write;
            int match_result = tls_connect_fds_struct_inst.calls[0].match__fd_write(val1, val2, "_fd_write", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'tls_connect_fds', %s",tls_connect_fds_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
        if(tls_connect_fds_struct_inst.calls[0].match__servername) {
            void * val1 = (void *) &tls_connect_fds_struct_inst.calls[0]._servername;
            void * val2 = (void *) &_servername;
            int match_result = tls_connect_fds_struct_inst.calls[0].match__servername(val1, val2, "_servername", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'tls_connect_fds', %s",tls_connect_fds_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < tls_connect_fds_struct_inst.expectedCalls; opmock_i++) {
        tls_connect_fds_struct_inst.calls[opmock_i - 1] = tls_connect_fds_struct_inst.calls[opmock_i];
    }

    tls_connect_fds_struct_inst.expectedCalls--;
    return default_res;
}

void tls_connect_fds_MockReset()
{
    tls_connect_fds_struct_inst.expectedCalls = 0;
    tls_connect_fds_struct_inst.actualCalls = 0;
    tls_connect_fds_struct_inst.callback = NULL;
}

void tls_connect_fds_MockWithCallback(OPMOCK_tls_connect_fds_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    tls_connect_fds_struct_inst.callback = callback;
    tls_connect_fds_struct_inst.expectedCalls = 0;
    tls_connect_fds_struct_inst.actualCalls = 0;
}

void tls_connect_fds_VerifyMock()
{
    if (tls_connect_fds_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'tls_connect_fds'",tls_connect_fds_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void tls_connect_fds_ExpectAndReturn (struct tls * _ctx, int _fd_read, int _fd_write, const char * _servername, int to_return, OPMOCK_MATCHER match__ctx, OPMOCK_MATCHER match__fd_read, OPMOCK_MATCHER match__fd_write, OPMOCK_MATCHER match__servername)
{
    if(tls_connect_fds_struct_inst.callback != NULL)
    {
        tls_connect_fds_MockReset ();
    }

    if(tls_connect_fds_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting tls_connect_fds_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"int tls_connect_fds (struct tls * _ctx, int _fd_read, int _fd_write, const char * _servername)");
    tls_connect_fds_struct_inst.calls[tls_connect_fds_struct_inst.expectedCalls]._ctx = (void *)_ctx;
    tls_connect_fds_struct_inst.calls[tls_connect_fds_struct_inst.expectedCalls]._fd_read = (int)_fd_read;
    tls_connect_fds_struct_inst.calls[tls_connect_fds_struct_inst.expectedCalls]._fd_write = (int)_fd_write;
    tls_connect_fds_struct_inst.calls[tls_connect_fds_struct_inst.expectedCalls]._servername = (void *)_servername;
    tls_connect_fds_struct_inst.calls[tls_connect_fds_struct_inst.expectedCalls].match__ctx = match__ctx;
    tls_connect_fds_struct_inst.calls[tls_connect_fds_struct_inst.expectedCalls].match__fd_read = match__fd_read;
    tls_connect_fds_struct_inst.calls[tls_connect_fds_struct_inst.expectedCalls].match__fd_write = match__fd_write;
    tls_connect_fds_struct_inst.calls[tls_connect_fds_struct_inst.expectedCalls].match__servername = match__servername;
    tls_connect_fds_struct_inst.calls[tls_connect_fds_struct_inst.expectedCalls].to_return = (int) to_return;
    tls_connect_fds_struct_inst.calls[tls_connect_fds_struct_inst.expectedCalls].check_params = 1;
    tls_connect_fds_struct_inst.expectedCalls++;
}

int tls_connect_servername(struct tls * _ctx, const char * _host, const char * _port, const char * _servername)
{
    int default_res = (int)tls_connect_servername_struct_inst.calls[0].to_return;
    int opmock_i;
    tls_connect_servername_struct_inst.actualCalls++;

    if (tls_connect_servername_struct_inst.callback != NULL)
    {
        return tls_connect_servername_struct_inst.callback (_ctx, _host, _port, _servername, tls_connect_servername_struct_inst.actualCalls);
    }
    if (tls_connect_servername_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'tls_connect_servername', returning random value.");
        return default_res;
    }

    if(strcmp(opmock_get_current_call(), "int tls_connect_servername (struct tls * _ctx, const char * _host, const char * _port, const char * _servername)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'int tls_connect_servername(struct tls * _ctx, const char * _host, const char * _port, const char * _servername)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (tls_connect_servername_struct_inst.calls[0].check_params == 1) {
        if(tls_connect_servername_struct_inst.calls[0].match__ctx) {
            void * val1 = (void *) &tls_connect_servername_struct_inst.calls[0]._ctx;
            void * val2 = (void *) &_ctx;
            int match_result = tls_connect_servername_struct_inst.calls[0].match__ctx(val1, val2, "_ctx", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'tls_connect_servername', %s",tls_connect_servername_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
        if(tls_connect_servername_struct_inst.calls[0].match__host) {
            void * val1 = (void *) &tls_connect_servername_struct_inst.calls[0]._host;
            void * val2 = (void *) &_host;
            int match_result = tls_connect_servername_struct_inst.calls[0].match__host(val1, val2, "_host", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'tls_connect_servername', %s",tls_connect_servername_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
        if(tls_connect_servername_struct_inst.calls[0].match__port) {
            void * val1 = (void *) &tls_connect_servername_struct_inst.calls[0]._port;
            void * val2 = (void *) &_port;
            int match_result = tls_connect_servername_struct_inst.calls[0].match__port(val1, val2, "_port", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'tls_connect_servername', %s",tls_connect_servername_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
        if(tls_connect_servername_struct_inst.calls[0].match__servername) {
            void * val1 = (void *) &tls_connect_servername_struct_inst.calls[0]._servername;
            void * val2 = (void *) &_servername;
            int match_result = tls_connect_servername_struct_inst.calls[0].match__servername(val1, val2, "_servername", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'tls_connect_servername', %s",tls_connect_servername_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < tls_connect_servername_struct_inst.expectedCalls; opmock_i++) {
        tls_connect_servername_struct_inst.calls[opmock_i - 1] = tls_connect_servername_struct_inst.calls[opmock_i];
    }

    tls_connect_servername_struct_inst.expectedCalls--;
    return default_res;
}

void tls_connect_servername_MockReset()
{
    tls_connect_servername_struct_inst.expectedCalls = 0;
    tls_connect_servername_struct_inst.actualCalls = 0;
    tls_connect_servername_struct_inst.callback = NULL;
}

void tls_connect_servername_MockWithCallback(OPMOCK_tls_connect_servername_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    tls_connect_servername_struct_inst.callback = callback;
    tls_connect_servername_struct_inst.expectedCalls = 0;
    tls_connect_servername_struct_inst.actualCalls = 0;
}

void tls_connect_servername_VerifyMock()
{
    if (tls_connect_servername_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'tls_connect_servername'",tls_connect_servername_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void tls_connect_servername_ExpectAndReturn (struct tls * _ctx, const char * _host, const char * _port, const char * _servername, int to_return, OPMOCK_MATCHER match__ctx, OPMOCK_MATCHER match__host, OPMOCK_MATCHER match__port, OPMOCK_MATCHER match__servername)
{
    if(tls_connect_servername_struct_inst.callback != NULL)
    {
        tls_connect_servername_MockReset ();
    }

    if(tls_connect_servername_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting tls_connect_servername_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"int tls_connect_servername (struct tls * _ctx, const char * _host, const char * _port, const char * _servername)");
    tls_connect_servername_struct_inst.calls[tls_connect_servername_struct_inst.expectedCalls]._ctx = (void *)_ctx;
    tls_connect_servername_struct_inst.calls[tls_connect_servername_struct_inst.expectedCalls]._host = (void *)_host;
    tls_connect_servername_struct_inst.calls[tls_connect_servername_struct_inst.expectedCalls]._port = (void *)_port;
    tls_connect_servername_struct_inst.calls[tls_connect_servername_struct_inst.expectedCalls]._servername = (void *)_servername;
    tls_connect_servername_struct_inst.calls[tls_connect_servername_struct_inst.expectedCalls].match__ctx = match__ctx;
    tls_connect_servername_struct_inst.calls[tls_connect_servername_struct_inst.expectedCalls].match__host = match__host;
    tls_connect_servername_struct_inst.calls[tls_connect_servername_struct_inst.expectedCalls].match__port = match__port;
    tls_connect_servername_struct_inst.calls[tls_connect_servername_struct_inst.expectedCalls].match__servername = match__servername;
    tls_connect_servername_struct_inst.calls[tls_connect_servername_struct_inst.expectedCalls].to_return = (int) to_return;
    tls_connect_servername_struct_inst.calls[tls_connect_servername_struct_inst.expectedCalls].check_params = 1;
    tls_connect_servername_struct_inst.expectedCalls++;
}

int tls_connect_socket(struct tls * _ctx, int _s, const char * _servername)
{
    int default_res = (int)tls_connect_socket_struct_inst.calls[0].to_return;
    int opmock_i;
    tls_connect_socket_struct_inst.actualCalls++;

    if (tls_connect_socket_struct_inst.callback != NULL)
    {
        return tls_connect_socket_struct_inst.callback (_ctx, _s, _servername, tls_connect_socket_struct_inst.actualCalls);
    }
    if (tls_connect_socket_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'tls_connect_socket', returning random value.");
        return default_res;
    }

    if(strcmp(opmock_get_current_call(), "int tls_connect_socket (struct tls * _ctx, int _s, const char * _servername)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'int tls_connect_socket(struct tls * _ctx, int _s, const char * _servername)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (tls_connect_socket_struct_inst.calls[0].check_params == 1) {
        if(tls_connect_socket_struct_inst.calls[0].match__ctx) {
            void * val1 = (void *) &tls_connect_socket_struct_inst.calls[0]._ctx;
            void * val2 = (void *) &_ctx;
            int match_result = tls_connect_socket_struct_inst.calls[0].match__ctx(val1, val2, "_ctx", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'tls_connect_socket', %s",tls_connect_socket_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
        if(tls_connect_socket_struct_inst.calls[0].match__s) {
            void * val1 = (void *) &tls_connect_socket_struct_inst.calls[0]._s;
            void * val2 = (void *) &_s;
            int match_result = tls_connect_socket_struct_inst.calls[0].match__s(val1, val2, "_s", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'tls_connect_socket', %s",tls_connect_socket_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
        if(tls_connect_socket_struct_inst.calls[0].match__servername) {
            void * val1 = (void *) &tls_connect_socket_struct_inst.calls[0]._servername;
            void * val2 = (void *) &_servername;
            int match_result = tls_connect_socket_struct_inst.calls[0].match__servername(val1, val2, "_servername", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'tls_connect_socket', %s",tls_connect_socket_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < tls_connect_socket_struct_inst.expectedCalls; opmock_i++) {
        tls_connect_socket_struct_inst.calls[opmock_i - 1] = tls_connect_socket_struct_inst.calls[opmock_i];
    }

    tls_connect_socket_struct_inst.expectedCalls--;
    return default_res;
}

void tls_connect_socket_MockReset()
{
    tls_connect_socket_struct_inst.expectedCalls = 0;
    tls_connect_socket_struct_inst.actualCalls = 0;
    tls_connect_socket_struct_inst.callback = NULL;
}

void tls_connect_socket_MockWithCallback(OPMOCK_tls_connect_socket_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    tls_connect_socket_struct_inst.callback = callback;
    tls_connect_socket_struct_inst.expectedCalls = 0;
    tls_connect_socket_struct_inst.actualCalls = 0;
}

void tls_connect_socket_VerifyMock()
{
    if (tls_connect_socket_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'tls_connect_socket'",tls_connect_socket_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void tls_connect_socket_ExpectAndReturn (struct tls * _ctx, int _s, const char * _servername, int to_return, OPMOCK_MATCHER match__ctx, OPMOCK_MATCHER match__s, OPMOCK_MATCHER match__servername)
{
    if(tls_connect_socket_struct_inst.callback != NULL)
    {
        tls_connect_socket_MockReset ();
    }

    if(tls_connect_socket_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting tls_connect_socket_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"int tls_connect_socket (struct tls * _ctx, int _s, const char * _servername)");
    tls_connect_socket_struct_inst.calls[tls_connect_socket_struct_inst.expectedCalls]._ctx = (void *)_ctx;
    tls_connect_socket_struct_inst.calls[tls_connect_socket_struct_inst.expectedCalls]._s = (int)_s;
    tls_connect_socket_struct_inst.calls[tls_connect_socket_struct_inst.expectedCalls]._servername = (void *)_servername;
    tls_connect_socket_struct_inst.calls[tls_connect_socket_struct_inst.expectedCalls].match__ctx = match__ctx;
    tls_connect_socket_struct_inst.calls[tls_connect_socket_struct_inst.expectedCalls].match__s = match__s;
    tls_connect_socket_struct_inst.calls[tls_connect_socket_struct_inst.expectedCalls].match__servername = match__servername;
    tls_connect_socket_struct_inst.calls[tls_connect_socket_struct_inst.expectedCalls].to_return = (int) to_return;
    tls_connect_socket_struct_inst.calls[tls_connect_socket_struct_inst.expectedCalls].check_params = 1;
    tls_connect_socket_struct_inst.expectedCalls++;
}

int tls_read(struct tls * _ctx, void * _buf, size_t _buflen, size_t * _outlen)
{
    int default_res = (int)tls_read_struct_inst.calls[0].to_return;
    int opmock_i;
    tls_read_struct_inst.actualCalls++;

    if (tls_read_struct_inst.callback != NULL)
    {
        return tls_read_struct_inst.callback (_ctx, _buf, _buflen, _outlen, tls_read_struct_inst.actualCalls);
    }
    if (tls_read_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'tls_read', returning random value.");
        return default_res;
    }

    if(strcmp(opmock_get_current_call(), "int tls_read (struct tls * _ctx, void * _buf, size_t _buflen, size_t * _outlen)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'int tls_read(struct tls * _ctx, void * _buf, size_t _buflen, size_t * _outlen)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (tls_read_struct_inst.calls[0].check_params == 1) {
        if(tls_read_struct_inst.calls[0].match__ctx) {
            void * val1 = (void *) &tls_read_struct_inst.calls[0]._ctx;
            void * val2 = (void *) &_ctx;
            int match_result = tls_read_struct_inst.calls[0].match__ctx(val1, val2, "_ctx", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'tls_read', %s",tls_read_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
        if(tls_read_struct_inst.calls[0].match__buf) {
            void * val1 = (void *) &tls_read_struct_inst.calls[0]._buf;
            void * val2 = (void *) &_buf;
            int match_result = tls_read_struct_inst.calls[0].match__buf(val1, val2, "_buf", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'tls_read', %s",tls_read_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
        if(tls_read_struct_inst.calls[0].match__buflen) {
            void * val1 = (void *) &tls_read_struct_inst.calls[0]._buflen;
            void * val2 = (void *) &_buflen;
            int match_result = tls_read_struct_inst.calls[0].match__buflen(val1, val2, "_buflen", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'tls_read', %s",tls_read_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
        if(tls_read_struct_inst.calls[0].match__outlen) {
            void * val1 = (void *) &tls_read_struct_inst.calls[0]._outlen;
            void * val2 = (void *) &_outlen;
            int match_result = tls_read_struct_inst.calls[0].match__outlen(val1, val2, "_outlen", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'tls_read', %s",tls_read_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < tls_read_struct_inst.expectedCalls; opmock_i++) {
        tls_read_struct_inst.calls[opmock_i - 1] = tls_read_struct_inst.calls[opmock_i];
    }

    tls_read_struct_inst.expectedCalls--;
    return default_res;
}

void tls_read_MockReset()
{
    tls_read_struct_inst.expectedCalls = 0;
    tls_read_struct_inst.actualCalls = 0;
    tls_read_struct_inst.callback = NULL;
}

void tls_read_MockWithCallback(OPMOCK_tls_read_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    tls_read_struct_inst.callback = callback;
    tls_read_struct_inst.expectedCalls = 0;
    tls_read_struct_inst.actualCalls = 0;
}

void tls_read_VerifyMock()
{
    if (tls_read_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'tls_read'",tls_read_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void tls_read_ExpectAndReturn (struct tls * _ctx, void * _buf, size_t _buflen, size_t * _outlen, int to_return, OPMOCK_MATCHER match__ctx, OPMOCK_MATCHER match__buf, OPMOCK_MATCHER match__buflen, OPMOCK_MATCHER match__outlen)
{
    if(tls_read_struct_inst.callback != NULL)
    {
        tls_read_MockReset ();
    }

    if(tls_read_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting tls_read_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"int tls_read (struct tls * _ctx, void * _buf, size_t _buflen, size_t * _outlen)");
    tls_read_struct_inst.calls[tls_read_struct_inst.expectedCalls]._ctx = (void *)_ctx;
    tls_read_struct_inst.calls[tls_read_struct_inst.expectedCalls]._buf = (void *)_buf;
    tls_read_struct_inst.calls[tls_read_struct_inst.expectedCalls]._buflen = (unsigned long)_buflen;
    tls_read_struct_inst.calls[tls_read_struct_inst.expectedCalls]._outlen = (void *)_outlen;
    tls_read_struct_inst.calls[tls_read_struct_inst.expectedCalls].match__ctx = match__ctx;
    tls_read_struct_inst.calls[tls_read_struct_inst.expectedCalls].match__buf = match__buf;
    tls_read_struct_inst.calls[tls_read_struct_inst.expectedCalls].match__buflen = match__buflen;
    tls_read_struct_inst.calls[tls_read_struct_inst.expectedCalls].match__outlen = match__outlen;
    tls_read_struct_inst.calls[tls_read_struct_inst.expectedCalls].to_return = (int) to_return;
    tls_read_struct_inst.calls[tls_read_struct_inst.expectedCalls].check_params = 1;
    tls_read_struct_inst.expectedCalls++;
}

int tls_write(struct tls * _ctx, const void * _buf, size_t _buflen, size_t * _outlen)
{
    int default_res = (int)tls_write_struct_inst.calls[0].to_return;
    int opmock_i;
    tls_write_struct_inst.actualCalls++;

    if (tls_write_struct_inst.callback != NULL)
    {
        return tls_write_struct_inst.callback (_ctx, _buf, _buflen, _outlen, tls_write_struct_inst.actualCalls);
    }
    if (tls_write_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'tls_write', returning random value.");
        return default_res;
    }

    if(strcmp(opmock_get_current_call(), "int tls_write (struct tls * _ctx, const void * _buf, size_t _buflen, size_t * _outlen)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'int tls_write(struct tls * _ctx, const void * _buf, size_t _buflen, size_t * _outlen)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (tls_write_struct_inst.calls[0].check_params == 1) {
        if(tls_write_struct_inst.calls[0].match__ctx) {
            void * val1 = (void *) &tls_write_struct_inst.calls[0]._ctx;
            void * val2 = (void *) &_ctx;
            int match_result = tls_write_struct_inst.calls[0].match__ctx(val1, val2, "_ctx", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'tls_write', %s",tls_write_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
        if(tls_write_struct_inst.calls[0].match__buf) {
            void * val1 = (void *) &tls_write_struct_inst.calls[0]._buf;
            void * val2 = (void *) &_buf;
            int match_result = tls_write_struct_inst.calls[0].match__buf(val1, val2, "_buf", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'tls_write', %s",tls_write_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
        if(tls_write_struct_inst.calls[0].match__buflen) {
            void * val1 = (void *) &tls_write_struct_inst.calls[0]._buflen;
            void * val2 = (void *) &_buflen;
            int match_result = tls_write_struct_inst.calls[0].match__buflen(val1, val2, "_buflen", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'tls_write', %s",tls_write_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
        if(tls_write_struct_inst.calls[0].match__outlen) {
            void * val1 = (void *) &tls_write_struct_inst.calls[0]._outlen;
            void * val2 = (void *) &_outlen;
            int match_result = tls_write_struct_inst.calls[0].match__outlen(val1, val2, "_outlen", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'tls_write', %s",tls_write_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < tls_write_struct_inst.expectedCalls; opmock_i++) {
        tls_write_struct_inst.calls[opmock_i - 1] = tls_write_struct_inst.calls[opmock_i];
    }

    tls_write_struct_inst.expectedCalls--;
    return default_res;
}

void tls_write_MockReset()
{
    tls_write_struct_inst.expectedCalls = 0;
    tls_write_struct_inst.actualCalls = 0;
    tls_write_struct_inst.callback = NULL;
}

void tls_write_MockWithCallback(OPMOCK_tls_write_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    tls_write_struct_inst.callback = callback;
    tls_write_struct_inst.expectedCalls = 0;
    tls_write_struct_inst.actualCalls = 0;
}

void tls_write_VerifyMock()
{
    if (tls_write_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'tls_write'",tls_write_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void tls_write_ExpectAndReturn (struct tls * _ctx, const void * _buf, size_t _buflen, size_t * _outlen, int to_return, OPMOCK_MATCHER match__ctx, OPMOCK_MATCHER match__buf, OPMOCK_MATCHER match__buflen, OPMOCK_MATCHER match__outlen)
{
    if(tls_write_struct_inst.callback != NULL)
    {
        tls_write_MockReset ();
    }

    if(tls_write_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting tls_write_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"int tls_write (struct tls * _ctx, const void * _buf, size_t _buflen, size_t * _outlen)");
    tls_write_struct_inst.calls[tls_write_struct_inst.expectedCalls]._ctx = (void *)_ctx;
    tls_write_struct_inst.calls[tls_write_struct_inst.expectedCalls]._buf = (void *)_buf;
    tls_write_struct_inst.calls[tls_write_struct_inst.expectedCalls]._buflen = (unsigned long)_buflen;
    tls_write_struct_inst.calls[tls_write_struct_inst.expectedCalls]._outlen = (void *)_outlen;
    tls_write_struct_inst.calls[tls_write_struct_inst.expectedCalls].match__ctx = match__ctx;
    tls_write_struct_inst.calls[tls_write_struct_inst.expectedCalls].match__buf = match__buf;
    tls_write_struct_inst.calls[tls_write_struct_inst.expectedCalls].match__buflen = match__buflen;
    tls_write_struct_inst.calls[tls_write_struct_inst.expectedCalls].match__outlen = match__outlen;
    tls_write_struct_inst.calls[tls_write_struct_inst.expectedCalls].to_return = (int) to_return;
    tls_write_struct_inst.calls[tls_write_struct_inst.expectedCalls].check_params = 1;
    tls_write_struct_inst.expectedCalls++;
}

int tls_close(struct tls * _ctx)
{
    int default_res = (int)tls_close_struct_inst.calls[0].to_return;
    int opmock_i;
    tls_close_struct_inst.actualCalls++;

    if (tls_close_struct_inst.callback != NULL)
    {
        return tls_close_struct_inst.callback (_ctx, tls_close_struct_inst.actualCalls);
    }
    if (tls_close_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'tls_close', returning random value.");
        return default_res;
    }

    if(strcmp(opmock_get_current_call(), "int tls_close (struct tls * _ctx)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'int tls_close(struct tls * _ctx)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (tls_close_struct_inst.calls[0].check_params == 1) {
        if(tls_close_struct_inst.calls[0].match__ctx) {
            void * val1 = (void *) &tls_close_struct_inst.calls[0]._ctx;
            void * val2 = (void *) &_ctx;
            int match_result = tls_close_struct_inst.calls[0].match__ctx(val1, val2, "_ctx", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'tls_close', %s",tls_close_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < tls_close_struct_inst.expectedCalls; opmock_i++) {
        tls_close_struct_inst.calls[opmock_i - 1] = tls_close_struct_inst.calls[opmock_i];
    }

    tls_close_struct_inst.expectedCalls--;
    return default_res;
}

void tls_close_MockReset()
{
    tls_close_struct_inst.expectedCalls = 0;
    tls_close_struct_inst.actualCalls = 0;
    tls_close_struct_inst.callback = NULL;
}

void tls_close_MockWithCallback(OPMOCK_tls_close_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    tls_close_struct_inst.callback = callback;
    tls_close_struct_inst.expectedCalls = 0;
    tls_close_struct_inst.actualCalls = 0;
}

void tls_close_VerifyMock()
{
    if (tls_close_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'tls_close'",tls_close_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void tls_close_ExpectAndReturn (struct tls * _ctx, int to_return, OPMOCK_MATCHER match__ctx)
{
    if(tls_close_struct_inst.callback != NULL)
    {
        tls_close_MockReset ();
    }

    if(tls_close_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting tls_close_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"int tls_close (struct tls * _ctx)");
    tls_close_struct_inst.calls[tls_close_struct_inst.expectedCalls]._ctx = (void *)_ctx;
    tls_close_struct_inst.calls[tls_close_struct_inst.expectedCalls].match__ctx = match__ctx;
    tls_close_struct_inst.calls[tls_close_struct_inst.expectedCalls].to_return = (int) to_return;
    tls_close_struct_inst.calls[tls_close_struct_inst.expectedCalls].check_params = 1;
    tls_close_struct_inst.expectedCalls++;
}

uint8_t * tls_load_file(const char * _file, size_t * _len, char * _password)
{
    uint8_t * default_res = (uint8_t *)tls_load_file_struct_inst.calls[0].to_return;
    int opmock_i;
    tls_load_file_struct_inst.actualCalls++;

    if (tls_load_file_struct_inst.callback != NULL)
    {
        return tls_load_file_struct_inst.callback (_file, _len, _password, tls_load_file_struct_inst.actualCalls);
    }
    if (tls_load_file_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'tls_load_file', returning random value.");
        return default_res;
    }

    if(strcmp(opmock_get_current_call(), "uint8_t * tls_load_file (const char * _file, size_t * _len, char * _password)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'uint8_t * tls_load_file(const char * _file, size_t * _len, char * _password)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (tls_load_file_struct_inst.calls[0].check_params == 1) {
        if(tls_load_file_struct_inst.calls[0].match__file) {
            void * val1 = (void *) &tls_load_file_struct_inst.calls[0]._file;
            void * val2 = (void *) &_file;
            int match_result = tls_load_file_struct_inst.calls[0].match__file(val1, val2, "_file", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'tls_load_file', %s",tls_load_file_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
        if(tls_load_file_struct_inst.calls[0].match__len) {
            void * val1 = (void *) &tls_load_file_struct_inst.calls[0]._len;
            void * val2 = (void *) &_len;
            int match_result = tls_load_file_struct_inst.calls[0].match__len(val1, val2, "_len", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'tls_load_file', %s",tls_load_file_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
        if(tls_load_file_struct_inst.calls[0].match__password) {
            void * val1 = (void *) &tls_load_file_struct_inst.calls[0]._password;
            void * val2 = (void *) &_password;
            int match_result = tls_load_file_struct_inst.calls[0].match__password(val1, val2, "_password", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'tls_load_file', %s",tls_load_file_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < tls_load_file_struct_inst.expectedCalls; opmock_i++) {
        tls_load_file_struct_inst.calls[opmock_i - 1] = tls_load_file_struct_inst.calls[opmock_i];
    }

    tls_load_file_struct_inst.expectedCalls--;
    return default_res;
}

void tls_load_file_MockReset()
{
    tls_load_file_struct_inst.expectedCalls = 0;
    tls_load_file_struct_inst.actualCalls = 0;
    tls_load_file_struct_inst.callback = NULL;
}

void tls_load_file_MockWithCallback(OPMOCK_tls_load_file_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    tls_load_file_struct_inst.callback = callback;
    tls_load_file_struct_inst.expectedCalls = 0;
    tls_load_file_struct_inst.actualCalls = 0;
}

void tls_load_file_VerifyMock()
{
    if (tls_load_file_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'tls_load_file'",tls_load_file_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void tls_load_file_ExpectAndReturn (const char * _file, size_t * _len, char * _password, uint8_t * to_return, OPMOCK_MATCHER match__file, OPMOCK_MATCHER match__len, OPMOCK_MATCHER match__password)
{
    if(tls_load_file_struct_inst.callback != NULL)
    {
        tls_load_file_MockReset ();
    }

    if(tls_load_file_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting tls_load_file_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"uint8_t * tls_load_file (const char * _file, size_t * _len, char * _password)");
    tls_load_file_struct_inst.calls[tls_load_file_struct_inst.expectedCalls]._file = (void *)_file;
    tls_load_file_struct_inst.calls[tls_load_file_struct_inst.expectedCalls]._len = (void *)_len;
    tls_load_file_struct_inst.calls[tls_load_file_struct_inst.expectedCalls]._password = (void *)_password;
    tls_load_file_struct_inst.calls[tls_load_file_struct_inst.expectedCalls].match__file = match__file;
    tls_load_file_struct_inst.calls[tls_load_file_struct_inst.expectedCalls].match__len = match__len;
    tls_load_file_struct_inst.calls[tls_load_file_struct_inst.expectedCalls].match__password = match__password;
    tls_load_file_struct_inst.calls[tls_load_file_struct_inst.expectedCalls].to_return = (unsigned char *) to_return;
    tls_load_file_struct_inst.calls[tls_load_file_struct_inst.expectedCalls].check_params = 1;
    tls_load_file_struct_inst.expectedCalls++;
}

int tls_get_cert_fingerprint(struct tls * _ctx, char * _buf, size_t _buflen)
{
    int default_res = (int)tls_get_cert_fingerprint_struct_inst.calls[0].to_return;
    int opmock_i;
    tls_get_cert_fingerprint_struct_inst.actualCalls++;

    if (tls_get_cert_fingerprint_struct_inst.callback != NULL)
    {
        return tls_get_cert_fingerprint_struct_inst.callback (_ctx, _buf, _buflen, tls_get_cert_fingerprint_struct_inst.actualCalls);
    }
    if (tls_get_cert_fingerprint_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'tls_get_cert_fingerprint', returning random value.");
        return default_res;
    }

    if(strcmp(opmock_get_current_call(), "int tls_get_cert_fingerprint (struct tls * _ctx, char * _buf, size_t _buflen)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'int tls_get_cert_fingerprint(struct tls * _ctx, char * _buf, size_t _buflen)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (tls_get_cert_fingerprint_struct_inst.calls[0].check_params == 1) {
        if(tls_get_cert_fingerprint_struct_inst.calls[0].match__ctx) {
            void * val1 = (void *) &tls_get_cert_fingerprint_struct_inst.calls[0]._ctx;
            void * val2 = (void *) &_ctx;
            int match_result = tls_get_cert_fingerprint_struct_inst.calls[0].match__ctx(val1, val2, "_ctx", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'tls_get_cert_fingerprint', %s",tls_get_cert_fingerprint_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
        if(tls_get_cert_fingerprint_struct_inst.calls[0].match__buf) {
            void * val1 = (void *) &tls_get_cert_fingerprint_struct_inst.calls[0]._buf;
            void * val2 = (void *) &_buf;
            int match_result = tls_get_cert_fingerprint_struct_inst.calls[0].match__buf(val1, val2, "_buf", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'tls_get_cert_fingerprint', %s",tls_get_cert_fingerprint_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
        if(tls_get_cert_fingerprint_struct_inst.calls[0].match__buflen) {
            void * val1 = (void *) &tls_get_cert_fingerprint_struct_inst.calls[0]._buflen;
            void * val2 = (void *) &_buflen;
            int match_result = tls_get_cert_fingerprint_struct_inst.calls[0].match__buflen(val1, val2, "_buflen", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'tls_get_cert_fingerprint', %s",tls_get_cert_fingerprint_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < tls_get_cert_fingerprint_struct_inst.expectedCalls; opmock_i++) {
        tls_get_cert_fingerprint_struct_inst.calls[opmock_i - 1] = tls_get_cert_fingerprint_struct_inst.calls[opmock_i];
    }

    tls_get_cert_fingerprint_struct_inst.expectedCalls--;
    return default_res;
}

void tls_get_cert_fingerprint_MockReset()
{
    tls_get_cert_fingerprint_struct_inst.expectedCalls = 0;
    tls_get_cert_fingerprint_struct_inst.actualCalls = 0;
    tls_get_cert_fingerprint_struct_inst.callback = NULL;
}

void tls_get_cert_fingerprint_MockWithCallback(OPMOCK_tls_get_cert_fingerprint_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    tls_get_cert_fingerprint_struct_inst.callback = callback;
    tls_get_cert_fingerprint_struct_inst.expectedCalls = 0;
    tls_get_cert_fingerprint_struct_inst.actualCalls = 0;
}

void tls_get_cert_fingerprint_VerifyMock()
{
    if (tls_get_cert_fingerprint_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'tls_get_cert_fingerprint'",tls_get_cert_fingerprint_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void tls_get_cert_fingerprint_ExpectAndReturn (struct tls * _ctx, char * _buf, size_t _buflen, int to_return, OPMOCK_MATCHER match__ctx, OPMOCK_MATCHER match__buf, OPMOCK_MATCHER match__buflen)
{
    if(tls_get_cert_fingerprint_struct_inst.callback != NULL)
    {
        tls_get_cert_fingerprint_MockReset ();
    }

    if(tls_get_cert_fingerprint_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting tls_get_cert_fingerprint_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"int tls_get_cert_fingerprint (struct tls * _ctx, char * _buf, size_t _buflen)");
    tls_get_cert_fingerprint_struct_inst.calls[tls_get_cert_fingerprint_struct_inst.expectedCalls]._ctx = (void *)_ctx;
    tls_get_cert_fingerprint_struct_inst.calls[tls_get_cert_fingerprint_struct_inst.expectedCalls]._buf = (void *)_buf;
    tls_get_cert_fingerprint_struct_inst.calls[tls_get_cert_fingerprint_struct_inst.expectedCalls]._buflen = (unsigned long)_buflen;
    tls_get_cert_fingerprint_struct_inst.calls[tls_get_cert_fingerprint_struct_inst.expectedCalls].match__ctx = match__ctx;
    tls_get_cert_fingerprint_struct_inst.calls[tls_get_cert_fingerprint_struct_inst.expectedCalls].match__buf = match__buf;
    tls_get_cert_fingerprint_struct_inst.calls[tls_get_cert_fingerprint_struct_inst.expectedCalls].match__buflen = match__buflen;
    tls_get_cert_fingerprint_struct_inst.calls[tls_get_cert_fingerprint_struct_inst.expectedCalls].to_return = (int) to_return;
    tls_get_cert_fingerprint_struct_inst.calls[tls_get_cert_fingerprint_struct_inst.expectedCalls].check_params = 1;
    tls_get_cert_fingerprint_struct_inst.expectedCalls++;
}

