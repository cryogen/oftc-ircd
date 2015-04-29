/* OPMOCK2 GENERATED CODE - DO NOT MODIFY */
#include "network_stub.h"
#include <stdio.h>
#include <string.h>

typedef struct
{
    void * ip;
    void * address;
    OPMOCK_MATCHER match_ip;
    OPMOCK_MATCHER match_address;
    _Bool to_return;
    char check_params;
} network_address_from_ipstring_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_network_address_from_ipstring_CALLBACK callback;
    network_address_from_ipstring_call calls[MAX_FUNC_CALL];
} network_address_from_ipstring_struct;

static network_address_from_ipstring_struct network_address_from_ipstring_struct_inst;

typedef struct
{
    void * ip;
    unsigned short port;
    void * address;
    OPMOCK_MATCHER match_ip;
    OPMOCK_MATCHER match_port;
    OPMOCK_MATCHER match_address;
    _Bool to_return;
    char check_params;
} network_address_from_ipstring_and_port_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_network_address_from_ipstring_and_port_CALLBACK callback;
    network_address_from_ipstring_and_port_call calls[MAX_FUNC_CALL];
} network_address_from_ipstring_and_port_struct;

static network_address_from_ipstring_and_port_struct network_address_from_ipstring_and_port_struct_inst;

typedef struct
{
    void * address;
    void * ip;
    unsigned long ipLen;
    OPMOCK_MATCHER match_address;
    OPMOCK_MATCHER match_ip;
    OPMOCK_MATCHER match_ipLen;
    _Bool to_return;
    char check_params;
} network_ipstring_from_address_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_network_ipstring_from_address_CALLBACK callback;
    network_ipstring_from_address_call calls[MAX_FUNC_CALL];
} network_ipstring_from_address_struct;

static network_ipstring_from_address_struct network_ipstring_from_address_struct_inst;

typedef struct
{
    void * handle;
    void * address;
    OPMOCK_MATCHER match_handle;
    OPMOCK_MATCHER match_address;
    _Bool to_return;
    char check_params;
} network_address_from_stream_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_network_address_from_stream_CALLBACK callback;
    network_address_from_stream_call calls[MAX_FUNC_CALL];
} network_address_from_stream_struct;

static network_address_from_stream_struct network_address_from_stream_struct_inst;

static void opmock_reset_all_mocks_in_this_header()
{
    network_address_from_ipstring_MockReset();
    network_address_from_ipstring_and_port_MockReset();
    network_ipstring_from_address_MockReset();
    network_address_from_stream_MockReset();
}

static void opmock_verify_all_mocks_in_this_header()
{
    network_address_from_ipstring_VerifyMock();
    network_address_from_ipstring_and_port_VerifyMock();
    network_ipstring_from_address_VerifyMock();
    network_address_from_stream_VerifyMock();
}

_Bool network_address_from_ipstring(const char * ip, NetworkAddress * address)
{
    _Bool default_res = (_Bool)network_address_from_ipstring_struct_inst.calls[0].to_return;
    int opmock_i;
    network_address_from_ipstring_struct_inst.actualCalls++;

    if (network_address_from_ipstring_struct_inst.callback != NULL)
    {
        return network_address_from_ipstring_struct_inst.callback (ip, address, network_address_from_ipstring_struct_inst.actualCalls);
    }
    if (network_address_from_ipstring_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'network_address_from_ipstring', returning random value.");
        return default_res;
    }

    if(strcmp(opmock_get_current_call(), "_Bool network_address_from_ipstring (const char * ip, NetworkAddress * address)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to '_Bool network_address_from_ipstring(const char * ip, NetworkAddress * address)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (network_address_from_ipstring_struct_inst.calls[0].check_params == 1) {
        if(network_address_from_ipstring_struct_inst.calls[0].match_ip) {
            void * val1 = (void *) &network_address_from_ipstring_struct_inst.calls[0].ip;
            void * val2 = (void *) &ip;
            int match_result = network_address_from_ipstring_struct_inst.calls[0].match_ip(val1, val2, "ip", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'network_address_from_ipstring', %s",network_address_from_ipstring_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
        if(network_address_from_ipstring_struct_inst.calls[0].match_address) {
            void * val1 = (void *) &network_address_from_ipstring_struct_inst.calls[0].address;
            void * val2 = (void *) &address;
            int match_result = network_address_from_ipstring_struct_inst.calls[0].match_address(val1, val2, "address", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'network_address_from_ipstring', %s",network_address_from_ipstring_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < network_address_from_ipstring_struct_inst.expectedCalls; opmock_i++) {
        network_address_from_ipstring_struct_inst.calls[opmock_i - 1] = network_address_from_ipstring_struct_inst.calls[opmock_i];
    }

    network_address_from_ipstring_struct_inst.expectedCalls--;
    return default_res;
}

void network_address_from_ipstring_MockReset()
{
    network_address_from_ipstring_struct_inst.expectedCalls = 0;
    network_address_from_ipstring_struct_inst.actualCalls = 0;
    network_address_from_ipstring_struct_inst.callback = NULL;
}

void network_address_from_ipstring_MockWithCallback(OPMOCK_network_address_from_ipstring_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    network_address_from_ipstring_struct_inst.callback = callback;
    network_address_from_ipstring_struct_inst.expectedCalls = 0;
    network_address_from_ipstring_struct_inst.actualCalls = 0;
}

void network_address_from_ipstring_VerifyMock()
{
    if (network_address_from_ipstring_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'network_address_from_ipstring'",network_address_from_ipstring_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void network_address_from_ipstring_ExpectAndReturn (const char * ip, NetworkAddress * address, _Bool to_return, OPMOCK_MATCHER match_ip, OPMOCK_MATCHER match_address)
{
    if(network_address_from_ipstring_struct_inst.callback != NULL)
    {
        network_address_from_ipstring_MockReset ();
    }

    if(network_address_from_ipstring_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting network_address_from_ipstring_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"_Bool network_address_from_ipstring (const char * ip, NetworkAddress * address)");
    network_address_from_ipstring_struct_inst.calls[network_address_from_ipstring_struct_inst.expectedCalls].ip = (void *)ip;
    network_address_from_ipstring_struct_inst.calls[network_address_from_ipstring_struct_inst.expectedCalls].address = (void *)address;
    network_address_from_ipstring_struct_inst.calls[network_address_from_ipstring_struct_inst.expectedCalls].match_ip = match_ip;
    network_address_from_ipstring_struct_inst.calls[network_address_from_ipstring_struct_inst.expectedCalls].match_address = match_address;
    network_address_from_ipstring_struct_inst.calls[network_address_from_ipstring_struct_inst.expectedCalls].to_return = (_Bool) to_return;
    network_address_from_ipstring_struct_inst.calls[network_address_from_ipstring_struct_inst.expectedCalls].check_params = 1;
    network_address_from_ipstring_struct_inst.expectedCalls++;
}

_Bool network_address_from_ipstring_and_port(const char * ip, unsigned short port, NetworkAddress * address)
{
    _Bool default_res = (_Bool)network_address_from_ipstring_and_port_struct_inst.calls[0].to_return;
    int opmock_i;
    network_address_from_ipstring_and_port_struct_inst.actualCalls++;

    if (network_address_from_ipstring_and_port_struct_inst.callback != NULL)
    {
        return network_address_from_ipstring_and_port_struct_inst.callback (ip, port, address, network_address_from_ipstring_and_port_struct_inst.actualCalls);
    }
    if (network_address_from_ipstring_and_port_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'network_address_from_ipstring_and_port', returning random value.");
        return default_res;
    }

    if(strcmp(opmock_get_current_call(), "_Bool network_address_from_ipstring_and_port (const char * ip, unsigned short port, NetworkAddress * address)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to '_Bool network_address_from_ipstring_and_port(const char * ip, unsigned short port, NetworkAddress * address)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (network_address_from_ipstring_and_port_struct_inst.calls[0].check_params == 1) {
        if(network_address_from_ipstring_and_port_struct_inst.calls[0].match_ip) {
            void * val1 = (void *) &network_address_from_ipstring_and_port_struct_inst.calls[0].ip;
            void * val2 = (void *) &ip;
            int match_result = network_address_from_ipstring_and_port_struct_inst.calls[0].match_ip(val1, val2, "ip", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'network_address_from_ipstring_and_port', %s",network_address_from_ipstring_and_port_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
        if(network_address_from_ipstring_and_port_struct_inst.calls[0].match_port) {
            void * val1 = (void *) &network_address_from_ipstring_and_port_struct_inst.calls[0].port;
            void * val2 = (void *) &port;
            int match_result = network_address_from_ipstring_and_port_struct_inst.calls[0].match_port(val1, val2, "port", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'network_address_from_ipstring_and_port', %s",network_address_from_ipstring_and_port_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
        if(network_address_from_ipstring_and_port_struct_inst.calls[0].match_address) {
            void * val1 = (void *) &network_address_from_ipstring_and_port_struct_inst.calls[0].address;
            void * val2 = (void *) &address;
            int match_result = network_address_from_ipstring_and_port_struct_inst.calls[0].match_address(val1, val2, "address", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'network_address_from_ipstring_and_port', %s",network_address_from_ipstring_and_port_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < network_address_from_ipstring_and_port_struct_inst.expectedCalls; opmock_i++) {
        network_address_from_ipstring_and_port_struct_inst.calls[opmock_i - 1] = network_address_from_ipstring_and_port_struct_inst.calls[opmock_i];
    }

    network_address_from_ipstring_and_port_struct_inst.expectedCalls--;
    return default_res;
}

void network_address_from_ipstring_and_port_MockReset()
{
    network_address_from_ipstring_and_port_struct_inst.expectedCalls = 0;
    network_address_from_ipstring_and_port_struct_inst.actualCalls = 0;
    network_address_from_ipstring_and_port_struct_inst.callback = NULL;
}

void network_address_from_ipstring_and_port_MockWithCallback(OPMOCK_network_address_from_ipstring_and_port_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    network_address_from_ipstring_and_port_struct_inst.callback = callback;
    network_address_from_ipstring_and_port_struct_inst.expectedCalls = 0;
    network_address_from_ipstring_and_port_struct_inst.actualCalls = 0;
}

void network_address_from_ipstring_and_port_VerifyMock()
{
    if (network_address_from_ipstring_and_port_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'network_address_from_ipstring_and_port'",network_address_from_ipstring_and_port_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void network_address_from_ipstring_and_port_ExpectAndReturn (const char * ip, unsigned short port, NetworkAddress * address, _Bool to_return, OPMOCK_MATCHER match_ip, OPMOCK_MATCHER match_port, OPMOCK_MATCHER match_address)
{
    if(network_address_from_ipstring_and_port_struct_inst.callback != NULL)
    {
        network_address_from_ipstring_and_port_MockReset ();
    }

    if(network_address_from_ipstring_and_port_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting network_address_from_ipstring_and_port_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"_Bool network_address_from_ipstring_and_port (const char * ip, unsigned short port, NetworkAddress * address)");
    network_address_from_ipstring_and_port_struct_inst.calls[network_address_from_ipstring_and_port_struct_inst.expectedCalls].ip = (void *)ip;
    network_address_from_ipstring_and_port_struct_inst.calls[network_address_from_ipstring_and_port_struct_inst.expectedCalls].port = (unsigned short)port;
    network_address_from_ipstring_and_port_struct_inst.calls[network_address_from_ipstring_and_port_struct_inst.expectedCalls].address = (void *)address;
    network_address_from_ipstring_and_port_struct_inst.calls[network_address_from_ipstring_and_port_struct_inst.expectedCalls].match_ip = match_ip;
    network_address_from_ipstring_and_port_struct_inst.calls[network_address_from_ipstring_and_port_struct_inst.expectedCalls].match_port = match_port;
    network_address_from_ipstring_and_port_struct_inst.calls[network_address_from_ipstring_and_port_struct_inst.expectedCalls].match_address = match_address;
    network_address_from_ipstring_and_port_struct_inst.calls[network_address_from_ipstring_and_port_struct_inst.expectedCalls].to_return = (_Bool) to_return;
    network_address_from_ipstring_and_port_struct_inst.calls[network_address_from_ipstring_and_port_struct_inst.expectedCalls].check_params = 1;
    network_address_from_ipstring_and_port_struct_inst.expectedCalls++;
}

_Bool network_ipstring_from_address(NetworkAddress * address, char * ip, size_t ipLen)
{
    _Bool default_res = (_Bool)network_ipstring_from_address_struct_inst.calls[0].to_return;
    int opmock_i;
    network_ipstring_from_address_struct_inst.actualCalls++;

    if (network_ipstring_from_address_struct_inst.callback != NULL)
    {
        return network_ipstring_from_address_struct_inst.callback (address, ip, ipLen, network_ipstring_from_address_struct_inst.actualCalls);
    }
    if (network_ipstring_from_address_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'network_ipstring_from_address', returning random value.");
        return default_res;
    }

    if(strcmp(opmock_get_current_call(), "_Bool network_ipstring_from_address (NetworkAddress * address, char * ip, size_t ipLen)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to '_Bool network_ipstring_from_address(NetworkAddress * address, char * ip, size_t ipLen)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (network_ipstring_from_address_struct_inst.calls[0].check_params == 1) {
        if(network_ipstring_from_address_struct_inst.calls[0].match_address) {
            void * val1 = (void *) &network_ipstring_from_address_struct_inst.calls[0].address;
            void * val2 = (void *) &address;
            int match_result = network_ipstring_from_address_struct_inst.calls[0].match_address(val1, val2, "address", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'network_ipstring_from_address', %s",network_ipstring_from_address_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
        if(network_ipstring_from_address_struct_inst.calls[0].match_ip) {
            void * val1 = (void *) &network_ipstring_from_address_struct_inst.calls[0].ip;
            void * val2 = (void *) &ip;
            int match_result = network_ipstring_from_address_struct_inst.calls[0].match_ip(val1, val2, "ip", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'network_ipstring_from_address', %s",network_ipstring_from_address_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
        if(network_ipstring_from_address_struct_inst.calls[0].match_ipLen) {
            void * val1 = (void *) &network_ipstring_from_address_struct_inst.calls[0].ipLen;
            void * val2 = (void *) &ipLen;
            int match_result = network_ipstring_from_address_struct_inst.calls[0].match_ipLen(val1, val2, "ipLen", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'network_ipstring_from_address', %s",network_ipstring_from_address_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < network_ipstring_from_address_struct_inst.expectedCalls; opmock_i++) {
        network_ipstring_from_address_struct_inst.calls[opmock_i - 1] = network_ipstring_from_address_struct_inst.calls[opmock_i];
    }

    network_ipstring_from_address_struct_inst.expectedCalls--;
    return default_res;
}

void network_ipstring_from_address_MockReset()
{
    network_ipstring_from_address_struct_inst.expectedCalls = 0;
    network_ipstring_from_address_struct_inst.actualCalls = 0;
    network_ipstring_from_address_struct_inst.callback = NULL;
}

void network_ipstring_from_address_MockWithCallback(OPMOCK_network_ipstring_from_address_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    network_ipstring_from_address_struct_inst.callback = callback;
    network_ipstring_from_address_struct_inst.expectedCalls = 0;
    network_ipstring_from_address_struct_inst.actualCalls = 0;
}

void network_ipstring_from_address_VerifyMock()
{
    if (network_ipstring_from_address_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'network_ipstring_from_address'",network_ipstring_from_address_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void network_ipstring_from_address_ExpectAndReturn (NetworkAddress * address, char * ip, size_t ipLen, _Bool to_return, OPMOCK_MATCHER match_address, OPMOCK_MATCHER match_ip, OPMOCK_MATCHER match_ipLen)
{
    if(network_ipstring_from_address_struct_inst.callback != NULL)
    {
        network_ipstring_from_address_MockReset ();
    }

    if(network_ipstring_from_address_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting network_ipstring_from_address_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"_Bool network_ipstring_from_address (NetworkAddress * address, char * ip, size_t ipLen)");
    network_ipstring_from_address_struct_inst.calls[network_ipstring_from_address_struct_inst.expectedCalls].address = (void *)address;
    network_ipstring_from_address_struct_inst.calls[network_ipstring_from_address_struct_inst.expectedCalls].ip = (void *)ip;
    network_ipstring_from_address_struct_inst.calls[network_ipstring_from_address_struct_inst.expectedCalls].ipLen = (unsigned long)ipLen;
    network_ipstring_from_address_struct_inst.calls[network_ipstring_from_address_struct_inst.expectedCalls].match_address = match_address;
    network_ipstring_from_address_struct_inst.calls[network_ipstring_from_address_struct_inst.expectedCalls].match_ip = match_ip;
    network_ipstring_from_address_struct_inst.calls[network_ipstring_from_address_struct_inst.expectedCalls].match_ipLen = match_ipLen;
    network_ipstring_from_address_struct_inst.calls[network_ipstring_from_address_struct_inst.expectedCalls].to_return = (_Bool) to_return;
    network_ipstring_from_address_struct_inst.calls[network_ipstring_from_address_struct_inst.expectedCalls].check_params = 1;
    network_ipstring_from_address_struct_inst.expectedCalls++;
}

_Bool network_address_from_stream(uv_tcp_t * handle, NetworkAddress * address)
{
    _Bool default_res = (_Bool)network_address_from_stream_struct_inst.calls[0].to_return;
    int opmock_i;
    network_address_from_stream_struct_inst.actualCalls++;

    if (network_address_from_stream_struct_inst.callback != NULL)
    {
        return network_address_from_stream_struct_inst.callback (handle, address, network_address_from_stream_struct_inst.actualCalls);
    }
    if (network_address_from_stream_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'network_address_from_stream', returning random value.");
        return default_res;
    }

    if(strcmp(opmock_get_current_call(), "_Bool network_address_from_stream (uv_tcp_t * handle, NetworkAddress * address)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to '_Bool network_address_from_stream(uv_tcp_t * handle, NetworkAddress * address)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (network_address_from_stream_struct_inst.calls[0].check_params == 1) {
        if(network_address_from_stream_struct_inst.calls[0].match_handle) {
            void * val1 = (void *) &network_address_from_stream_struct_inst.calls[0].handle;
            void * val2 = (void *) &handle;
            int match_result = network_address_from_stream_struct_inst.calls[0].match_handle(val1, val2, "handle", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'network_address_from_stream', %s",network_address_from_stream_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
        if(network_address_from_stream_struct_inst.calls[0].match_address) {
            void * val1 = (void *) &network_address_from_stream_struct_inst.calls[0].address;
            void * val2 = (void *) &address;
            int match_result = network_address_from_stream_struct_inst.calls[0].match_address(val1, val2, "address", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'network_address_from_stream', %s",network_address_from_stream_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < network_address_from_stream_struct_inst.expectedCalls; opmock_i++) {
        network_address_from_stream_struct_inst.calls[opmock_i - 1] = network_address_from_stream_struct_inst.calls[opmock_i];
    }

    network_address_from_stream_struct_inst.expectedCalls--;
    return default_res;
}

void network_address_from_stream_MockReset()
{
    network_address_from_stream_struct_inst.expectedCalls = 0;
    network_address_from_stream_struct_inst.actualCalls = 0;
    network_address_from_stream_struct_inst.callback = NULL;
}

void network_address_from_stream_MockWithCallback(OPMOCK_network_address_from_stream_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    network_address_from_stream_struct_inst.callback = callback;
    network_address_from_stream_struct_inst.expectedCalls = 0;
    network_address_from_stream_struct_inst.actualCalls = 0;
}

void network_address_from_stream_VerifyMock()
{
    if (network_address_from_stream_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'network_address_from_stream'",network_address_from_stream_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void network_address_from_stream_ExpectAndReturn (uv_tcp_t * handle, NetworkAddress * address, _Bool to_return, OPMOCK_MATCHER match_handle, OPMOCK_MATCHER match_address)
{
    if(network_address_from_stream_struct_inst.callback != NULL)
    {
        network_address_from_stream_MockReset ();
    }

    if(network_address_from_stream_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting network_address_from_stream_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"_Bool network_address_from_stream (uv_tcp_t * handle, NetworkAddress * address)");
    network_address_from_stream_struct_inst.calls[network_address_from_stream_struct_inst.expectedCalls].handle = (void *)handle;
    network_address_from_stream_struct_inst.calls[network_address_from_stream_struct_inst.expectedCalls].address = (void *)address;
    network_address_from_stream_struct_inst.calls[network_address_from_stream_struct_inst.expectedCalls].match_handle = match_handle;
    network_address_from_stream_struct_inst.calls[network_address_from_stream_struct_inst.expectedCalls].match_address = match_address;
    network_address_from_stream_struct_inst.calls[network_address_from_stream_struct_inst.expectedCalls].to_return = (_Bool) to_return;
    network_address_from_stream_struct_inst.calls[network_address_from_stream_struct_inst.expectedCalls].check_params = 1;
    network_address_from_stream_struct_inst.expectedCalls++;
}

