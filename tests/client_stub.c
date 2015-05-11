/* OPMOCK2 GENERATED CODE - DO NOT MODIFY */
#include "client_stub.h"
#include <stdio.h>
#include <string.h>


typedef struct
{
  char check_params;
} client_send_call;

typedef struct
{
  int expectedCalls;
  int actualCalls;
  OPMOCK_client_send_CALLBACK callback;
  client_send_call calls[MAX_FUNC_CALL];
} client_send_struct;

static client_send_struct client_send_struct_inst;

typedef struct
{
    char check_params;
} client_init_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_client_init_CALLBACK callback;
    client_init_call calls[MAX_FUNC_CALL];
} client_init_struct;

static client_init_struct client_init_struct_inst;

typedef struct
{
    struct _Client * to_return;
    char check_params;
} client_new_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_client_new_CALLBACK callback;
    client_new_call calls[MAX_FUNC_CALL];
} client_new_struct;

static client_new_struct client_new_struct_inst;

typedef struct
{
    void * client;
    OPMOCK_MATCHER match_client;
    char check_params;
} client_free_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_client_free_CALLBACK callback;
    client_free_call calls[MAX_FUNC_CALL];
} client_free_struct;

static client_free_struct client_free_struct_inst;

typedef struct
{
    void * client;
    OPMOCK_MATCHER match_client;
    char check_params;
} client_lookup_dns_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_client_lookup_dns_CALLBACK callback;
    client_lookup_dns_call calls[MAX_FUNC_CALL];
} client_lookup_dns_struct;

static client_lookup_dns_struct client_lookup_dns_struct_inst;

typedef struct
{
    void * client;
    OPMOCK_MATCHER match_client;
    char check_params;
} client_process_read_buffer_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_client_process_read_buffer_CALLBACK callback;
    client_process_read_buffer_call calls[MAX_FUNC_CALL];
} client_process_read_buffer_struct;

static client_process_read_buffer_struct client_process_read_buffer_struct_inst;

typedef struct
{
    void * name;
    OPMOCK_MATCHER match_name;
    struct _Client * to_return;
    char check_params;
} client_find_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_client_find_CALLBACK callback;
    client_find_call calls[MAX_FUNC_CALL];
} client_find_struct;

static client_find_struct client_find_struct_inst;

typedef struct
{
    void * client;
    OPMOCK_MATCHER match_client;
    char check_params;
} client_register_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_client_register_CALLBACK callback;
    client_register_call calls[MAX_FUNC_CALL];
} client_register_struct;

static client_register_struct client_register_struct_inst;

typedef struct
{
    void * client;
    OPMOCK_MATCHER match_client;
    _Bool to_return;
    char check_params;
} client_can_register_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_client_can_register_CALLBACK callback;
    client_can_register_call calls[MAX_FUNC_CALL];
} client_can_register_struct;

static client_can_register_struct client_can_register_struct_inst;

typedef struct
{
    void * client;
    void * username;
    OPMOCK_MATCHER match_client;
    OPMOCK_MATCHER match_username;
    _Bool to_return;
    char check_params;
} client_set_username_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_client_set_username_CALLBACK callback;
    client_set_username_call calls[MAX_FUNC_CALL];
} client_set_username_struct;

static client_set_username_struct client_set_username_struct_inst;

typedef struct
{
    void * client;
    void * nickname;
    OPMOCK_MATCHER match_client;
    OPMOCK_MATCHER match_nickname;
    _Bool to_return;
    char check_params;
} client_set_nickname_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_client_set_nickname_CALLBACK callback;
    client_set_nickname_call calls[MAX_FUNC_CALL];
} client_set_nickname_struct;

static client_set_nickname_struct client_set_nickname_struct_inst;

typedef struct
{
    void * client;
    void * realname;
    OPMOCK_MATCHER match_client;
    OPMOCK_MATCHER match_realname;
    _Bool to_return;
    char check_params;
} client_set_realname_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_client_set_realname_CALLBACK callback;
    client_set_realname_call calls[MAX_FUNC_CALL];
} client_set_realname_struct;

static client_set_realname_struct client_set_realname_struct_inst;

typedef struct
{
    void * client;
    OPMOCK_MATCHER match_client;
     char * to_return;
    char check_params;
} client_get_nickname_call;

typedef struct
{
    int expectedCalls;
    int actualCalls;
    OPMOCK_client_get_nickname_CALLBACK callback;
    client_get_nickname_call calls[MAX_FUNC_CALL];
} client_get_nickname_struct;

static client_get_nickname_struct client_get_nickname_struct_inst;

static void opmock_reset_all_mocks_in_this_header()
{
    client_init_MockReset();
    client_new_MockReset();
    client_free_MockReset();
    client_lookup_dns_MockReset();
    client_process_read_buffer_MockReset();
    client_find_MockReset();
    client_register_MockReset();
    client_can_register_MockReset();
    client_set_username_MockReset();
    client_set_nickname_MockReset();
    client_set_realname_MockReset();
    client_get_nickname_MockReset();
}

static void opmock_verify_all_mocks_in_this_header()
{
    client_init_VerifyMock();
    client_new_VerifyMock();
    client_free_VerifyMock();
    client_lookup_dns_VerifyMock();
    client_process_read_buffer_VerifyMock();
    client_find_VerifyMock();
    client_register_VerifyMock();
    client_can_register_VerifyMock();
    client_set_username_VerifyMock();
    client_set_nickname_VerifyMock();
    client_set_realname_VerifyMock();
    client_get_nickname_VerifyMock();
    client_send_VerifyMock();
}

void client_send(Client *source, Client *client, const char *command, const char *args, ...)
{
  int opmock_i;
  client_send_struct_inst.actualCalls++;

  if(client_send_struct_inst.expectedCalls == 0)
  {
    opmock_add_error_message((char *) "WARNING : unexpected call of 'client_send', returning random value.");
    return;
  }

  if(strcmp(opmock_get_current_call(), "void client_send ()") != 0) {
    char buffer[OP_ERROR_MESSAGE_LENGTH];
    snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'void client_send ()',  but was expecting call to '%s'", opmock_get_current_call());
    opmock_add_error_message(buffer);
  }
  opmock_pop_call();

  if (client_send_struct_inst.calls[0].check_params == 1) {
  }

  for(opmock_i = 1; opmock_i < client_send_struct_inst.expectedCalls; opmock_i++) {
    client_send_struct_inst.calls[opmock_i - 1] = client_send_struct_inst.calls[opmock_i];
  }

  client_send_struct_inst.expectedCalls--;
}

void client_send_MockReset()
{
    client_send_struct_inst.expectedCalls = 0;
    client_send_struct_inst.actualCalls = 0;
    client_send_struct_inst.callback = NULL;
}

void client_send_MockWithCallback(OPMOCK_client_send_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    client_send_struct_inst.callback = callback;
    client_send_struct_inst.expectedCalls = 0;
    client_send_struct_inst.actualCalls = 0;
}

void client_send_VerifyMock()
{
    if (client_send_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'client_send'",client_send_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void client_send_ExpectAndReturn ()
{
    if(client_send_struct_inst.callback != NULL)
    {
        client_send_MockReset ();
    }

    if(client_send_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting client_send_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"void client_send ()");
    client_send_struct_inst.calls[client_send_struct_inst.expectedCalls].check_params = 1;
    client_send_struct_inst.expectedCalls++;
}

void client_init()
{
    int opmock_i;
    client_init_struct_inst.actualCalls++;

    if (client_init_struct_inst.callback != NULL)
    {
        client_init_struct_inst.callback (client_init_struct_inst.actualCalls);
        return;
    }
    if (client_init_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'client_init', returning random value.");
        return;
    }

    if(strcmp(opmock_get_current_call(), "void client_init ()") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'void client_init()',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (client_init_struct_inst.calls[0].check_params == 1) {
    }

    for(opmock_i = 1; opmock_i < client_init_struct_inst.expectedCalls; opmock_i++) {
        client_init_struct_inst.calls[opmock_i - 1] = client_init_struct_inst.calls[opmock_i];
    }

    client_init_struct_inst.expectedCalls--;
}

void client_init_MockReset()
{
    client_init_struct_inst.expectedCalls = 0;
    client_init_struct_inst.actualCalls = 0;
    client_init_struct_inst.callback = NULL;
}

void client_init_MockWithCallback(OPMOCK_client_init_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    client_init_struct_inst.callback = callback;
    client_init_struct_inst.expectedCalls = 0;
    client_init_struct_inst.actualCalls = 0;
}

void client_init_VerifyMock()
{
    if (client_init_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'client_init'",client_init_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void client_init_ExpectAndReturn ()
{
    if(client_init_struct_inst.callback != NULL)
    {
        client_init_MockReset ();
    }

    if(client_init_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting client_init_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"void client_init ()");
    client_init_struct_inst.calls[client_init_struct_inst.expectedCalls].check_params = 1;
    client_init_struct_inst.expectedCalls++;
}

Client * client_new()
{
    Client * default_res = (Client *)client_new_struct_inst.calls[0].to_return;
    int opmock_i;
    client_new_struct_inst.actualCalls++;

    if (client_new_struct_inst.callback != NULL)
    {
        return client_new_struct_inst.callback (client_new_struct_inst.actualCalls);
    }
    if (client_new_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'client_new', returning random value.");
        return default_res;
    }

    if(strcmp(opmock_get_current_call(), "Client * client_new ()") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'Client * client_new()',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (client_new_struct_inst.calls[0].check_params == 1) {
    }

    for(opmock_i = 1; opmock_i < client_new_struct_inst.expectedCalls; opmock_i++) {
        client_new_struct_inst.calls[opmock_i - 1] = client_new_struct_inst.calls[opmock_i];
    }

    client_new_struct_inst.expectedCalls--;
    return default_res;
}

void client_new_MockReset()
{
    client_new_struct_inst.expectedCalls = 0;
    client_new_struct_inst.actualCalls = 0;
    client_new_struct_inst.callback = NULL;
}

void client_new_MockWithCallback(OPMOCK_client_new_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    client_new_struct_inst.callback = callback;
    client_new_struct_inst.expectedCalls = 0;
    client_new_struct_inst.actualCalls = 0;
}

void client_new_VerifyMock()
{
    if (client_new_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'client_new'",client_new_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void client_new_ExpectAndReturn (Client * to_return)
{
    if(client_new_struct_inst.callback != NULL)
    {
        client_new_MockReset ();
    }

    if(client_new_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting client_new_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"Client * client_new ()");
    client_new_struct_inst.calls[client_new_struct_inst.expectedCalls].to_return = (struct _Client *) to_return;
    client_new_struct_inst.calls[client_new_struct_inst.expectedCalls].check_params = 1;
    client_new_struct_inst.expectedCalls++;
}

void client_free(Client * client)
{
    int opmock_i;
    client_free_struct_inst.actualCalls++;

    if (client_free_struct_inst.callback != NULL)
    {
        client_free_struct_inst.callback (client, client_free_struct_inst.actualCalls);
        return;
    }
    if (client_free_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'client_free', returning random value.");
        return;
    }

    if(strcmp(opmock_get_current_call(), "void client_free (Client * client)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'void client_free(Client * client)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (client_free_struct_inst.calls[0].check_params == 1) {
        if(client_free_struct_inst.calls[0].match_client) {
            void * val1 = (void *) &client_free_struct_inst.calls[0].client;
            void * val2 = (void *) &client;
            int match_result = client_free_struct_inst.calls[0].match_client(val1, val2, "client", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'client_free', %s",client_free_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < client_free_struct_inst.expectedCalls; opmock_i++) {
        client_free_struct_inst.calls[opmock_i - 1] = client_free_struct_inst.calls[opmock_i];
    }

    client_free_struct_inst.expectedCalls--;
}

void client_free_MockReset()
{
    client_free_struct_inst.expectedCalls = 0;
    client_free_struct_inst.actualCalls = 0;
    client_free_struct_inst.callback = NULL;
}

void client_free_MockWithCallback(OPMOCK_client_free_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    client_free_struct_inst.callback = callback;
    client_free_struct_inst.expectedCalls = 0;
    client_free_struct_inst.actualCalls = 0;
}

void client_free_VerifyMock()
{
    if (client_free_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'client_free'",client_free_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void client_free_ExpectAndReturn (Client * client, OPMOCK_MATCHER match_client)
{
    if(client_free_struct_inst.callback != NULL)
    {
        client_free_MockReset ();
    }

    if(client_free_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting client_free_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"void client_free (Client * client)");
    client_free_struct_inst.calls[client_free_struct_inst.expectedCalls].client = (void *)client;
    client_free_struct_inst.calls[client_free_struct_inst.expectedCalls].match_client = match_client;
    client_free_struct_inst.calls[client_free_struct_inst.expectedCalls].check_params = 1;
    client_free_struct_inst.expectedCalls++;
}

void client_lookup_dns(Client * client)
{
    int opmock_i;
    client_lookup_dns_struct_inst.actualCalls++;

    if (client_lookup_dns_struct_inst.callback != NULL)
    {
        client_lookup_dns_struct_inst.callback (client, client_lookup_dns_struct_inst.actualCalls);
        return;
    }
    if (client_lookup_dns_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'client_lookup_dns', returning random value.");
        return;
    }

    if(strcmp(opmock_get_current_call(), "void client_lookup_dns (Client * client)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'void client_lookup_dns(Client * client)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (client_lookup_dns_struct_inst.calls[0].check_params == 1) {
        if(client_lookup_dns_struct_inst.calls[0].match_client) {
            void * val1 = (void *) &client_lookup_dns_struct_inst.calls[0].client;
            void * val2 = (void *) &client;
            int match_result = client_lookup_dns_struct_inst.calls[0].match_client(val1, val2, "client", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'client_lookup_dns', %s",client_lookup_dns_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < client_lookup_dns_struct_inst.expectedCalls; opmock_i++) {
        client_lookup_dns_struct_inst.calls[opmock_i - 1] = client_lookup_dns_struct_inst.calls[opmock_i];
    }

    client_lookup_dns_struct_inst.expectedCalls--;
}

void client_lookup_dns_MockReset()
{
    client_lookup_dns_struct_inst.expectedCalls = 0;
    client_lookup_dns_struct_inst.actualCalls = 0;
    client_lookup_dns_struct_inst.callback = NULL;
}

void client_lookup_dns_MockWithCallback(OPMOCK_client_lookup_dns_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    client_lookup_dns_struct_inst.callback = callback;
    client_lookup_dns_struct_inst.expectedCalls = 0;
    client_lookup_dns_struct_inst.actualCalls = 0;
}

void client_lookup_dns_VerifyMock()
{
    if (client_lookup_dns_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'client_lookup_dns'",client_lookup_dns_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void client_lookup_dns_ExpectAndReturn (Client * client, OPMOCK_MATCHER match_client)
{
    if(client_lookup_dns_struct_inst.callback != NULL)
    {
        client_lookup_dns_MockReset ();
    }

    if(client_lookup_dns_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting client_lookup_dns_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"void client_lookup_dns (Client * client)");
    client_lookup_dns_struct_inst.calls[client_lookup_dns_struct_inst.expectedCalls].client = (void *)client;
    client_lookup_dns_struct_inst.calls[client_lookup_dns_struct_inst.expectedCalls].match_client = match_client;
    client_lookup_dns_struct_inst.calls[client_lookup_dns_struct_inst.expectedCalls].check_params = 1;
    client_lookup_dns_struct_inst.expectedCalls++;
}

void client_process_read_buffer(Client * client)
{
    int opmock_i;
    client_process_read_buffer_struct_inst.actualCalls++;

    if (client_process_read_buffer_struct_inst.callback != NULL)
    {
        client_process_read_buffer_struct_inst.callback (client, client_process_read_buffer_struct_inst.actualCalls);
        return;
    }
    if (client_process_read_buffer_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'client_process_read_buffer', returning random value.");
        return;
    }

    if(strcmp(opmock_get_current_call(), "void client_process_read_buffer (Client * client)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'void client_process_read_buffer(Client * client)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (client_process_read_buffer_struct_inst.calls[0].check_params == 1) {
        if(client_process_read_buffer_struct_inst.calls[0].match_client) {
            void * val1 = (void *) &client_process_read_buffer_struct_inst.calls[0].client;
            void * val2 = (void *) &client;
            int match_result = client_process_read_buffer_struct_inst.calls[0].match_client(val1, val2, "client", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'client_process_read_buffer', %s",client_process_read_buffer_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < client_process_read_buffer_struct_inst.expectedCalls; opmock_i++) {
        client_process_read_buffer_struct_inst.calls[opmock_i - 1] = client_process_read_buffer_struct_inst.calls[opmock_i];
    }

    client_process_read_buffer_struct_inst.expectedCalls--;
}

void client_process_read_buffer_MockReset()
{
    client_process_read_buffer_struct_inst.expectedCalls = 0;
    client_process_read_buffer_struct_inst.actualCalls = 0;
    client_process_read_buffer_struct_inst.callback = NULL;
}

void client_process_read_buffer_MockWithCallback(OPMOCK_client_process_read_buffer_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    client_process_read_buffer_struct_inst.callback = callback;
    client_process_read_buffer_struct_inst.expectedCalls = 0;
    client_process_read_buffer_struct_inst.actualCalls = 0;
}

void client_process_read_buffer_VerifyMock()
{
    if (client_process_read_buffer_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'client_process_read_buffer'",client_process_read_buffer_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void client_process_read_buffer_ExpectAndReturn (Client * client, OPMOCK_MATCHER match_client)
{
    if(client_process_read_buffer_struct_inst.callback != NULL)
    {
        client_process_read_buffer_MockReset ();
    }

    if(client_process_read_buffer_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting client_process_read_buffer_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"void client_process_read_buffer (Client * client)");
    client_process_read_buffer_struct_inst.calls[client_process_read_buffer_struct_inst.expectedCalls].client = (void *)client;
    client_process_read_buffer_struct_inst.calls[client_process_read_buffer_struct_inst.expectedCalls].match_client = match_client;
    client_process_read_buffer_struct_inst.calls[client_process_read_buffer_struct_inst.expectedCalls].check_params = 1;
    client_process_read_buffer_struct_inst.expectedCalls++;
}

Client * client_find(const char * name)
{
    Client * default_res = (Client *)client_find_struct_inst.calls[0].to_return;
    int opmock_i;
    client_find_struct_inst.actualCalls++;

    if (client_find_struct_inst.callback != NULL)
    {
        return client_find_struct_inst.callback (name, client_find_struct_inst.actualCalls);
    }
    if (client_find_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'client_find', returning random value.");
        return default_res;
    }

    if(strcmp(opmock_get_current_call(), "Client * client_find (const char * name)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'Client * client_find(const char * name)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (client_find_struct_inst.calls[0].check_params == 1) {
        if(client_find_struct_inst.calls[0].match_name) {
            void * val1 = (void *) &client_find_struct_inst.calls[0].name;
            void * val2 = (void *) &name;
            int match_result = client_find_struct_inst.calls[0].match_name(val1, val2, "name", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'client_find', %s",client_find_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < client_find_struct_inst.expectedCalls; opmock_i++) {
        client_find_struct_inst.calls[opmock_i - 1] = client_find_struct_inst.calls[opmock_i];
    }

    client_find_struct_inst.expectedCalls--;
    return default_res;
}

void client_find_MockReset()
{
    client_find_struct_inst.expectedCalls = 0;
    client_find_struct_inst.actualCalls = 0;
    client_find_struct_inst.callback = NULL;
}

void client_find_MockWithCallback(OPMOCK_client_find_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    client_find_struct_inst.callback = callback;
    client_find_struct_inst.expectedCalls = 0;
    client_find_struct_inst.actualCalls = 0;
}

void client_find_VerifyMock()
{
    if (client_find_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'client_find'",client_find_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void client_find_ExpectAndReturn (const char * name, Client * to_return, OPMOCK_MATCHER match_name)
{
    if(client_find_struct_inst.callback != NULL)
    {
        client_find_MockReset ();
    }

    if(client_find_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting client_find_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"Client * client_find (const char * name)");
    client_find_struct_inst.calls[client_find_struct_inst.expectedCalls].name = (void *)name;
    client_find_struct_inst.calls[client_find_struct_inst.expectedCalls].match_name = match_name;
    client_find_struct_inst.calls[client_find_struct_inst.expectedCalls].to_return = (struct _Client *) to_return;
    client_find_struct_inst.calls[client_find_struct_inst.expectedCalls].check_params = 1;
    client_find_struct_inst.expectedCalls++;
}

void client_register(Client * client)
{
    int opmock_i;
    client_register_struct_inst.actualCalls++;

    if (client_register_struct_inst.callback != NULL)
    {
        client_register_struct_inst.callback (client, client_register_struct_inst.actualCalls);
        return;
    }
    if (client_register_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'client_register', returning random value.");
        return;
    }

    if(strcmp(opmock_get_current_call(), "void client_register (Client * client)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'void client_register(Client * client)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (client_register_struct_inst.calls[0].check_params == 1) {
        if(client_register_struct_inst.calls[0].match_client) {
            void * val1 = (void *) &client_register_struct_inst.calls[0].client;
            void * val2 = (void *) &client;
            int match_result = client_register_struct_inst.calls[0].match_client(val1, val2, "client", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'client_register', %s",client_register_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < client_register_struct_inst.expectedCalls; opmock_i++) {
        client_register_struct_inst.calls[opmock_i - 1] = client_register_struct_inst.calls[opmock_i];
    }

    client_register_struct_inst.expectedCalls--;
}

void client_register_MockReset()
{
    client_register_struct_inst.expectedCalls = 0;
    client_register_struct_inst.actualCalls = 0;
    client_register_struct_inst.callback = NULL;
}

void client_register_MockWithCallback(OPMOCK_client_register_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    client_register_struct_inst.callback = callback;
    client_register_struct_inst.expectedCalls = 0;
    client_register_struct_inst.actualCalls = 0;
}

void client_register_VerifyMock()
{
    if (client_register_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'client_register'",client_register_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void client_register_ExpectAndReturn (Client * client, OPMOCK_MATCHER match_client)
{
    if(client_register_struct_inst.callback != NULL)
    {
        client_register_MockReset ();
    }

    if(client_register_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting client_register_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"void client_register (Client * client)");
    client_register_struct_inst.calls[client_register_struct_inst.expectedCalls].client = (void *)client;
    client_register_struct_inst.calls[client_register_struct_inst.expectedCalls].match_client = match_client;
    client_register_struct_inst.calls[client_register_struct_inst.expectedCalls].check_params = 1;
    client_register_struct_inst.expectedCalls++;
}

_Bool client_can_register(Client * client)
{
    _Bool default_res = (_Bool)client_can_register_struct_inst.calls[0].to_return;
    int opmock_i;
    client_can_register_struct_inst.actualCalls++;

    if (client_can_register_struct_inst.callback != NULL)
    {
        return client_can_register_struct_inst.callback (client, client_can_register_struct_inst.actualCalls);
    }
    if (client_can_register_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'client_can_register', returning random value.");
        return default_res;
    }

    if(strcmp(opmock_get_current_call(), "_Bool client_can_register (Client * client)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to '_Bool client_can_register(Client * client)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (client_can_register_struct_inst.calls[0].check_params == 1) {
        if(client_can_register_struct_inst.calls[0].match_client) {
            void * val1 = (void *) &client_can_register_struct_inst.calls[0].client;
            void * val2 = (void *) &client;
            int match_result = client_can_register_struct_inst.calls[0].match_client(val1, val2, "client", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'client_can_register', %s",client_can_register_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < client_can_register_struct_inst.expectedCalls; opmock_i++) {
        client_can_register_struct_inst.calls[opmock_i - 1] = client_can_register_struct_inst.calls[opmock_i];
    }

    client_can_register_struct_inst.expectedCalls--;
    return default_res;
}

void client_can_register_MockReset()
{
    client_can_register_struct_inst.expectedCalls = 0;
    client_can_register_struct_inst.actualCalls = 0;
    client_can_register_struct_inst.callback = NULL;
}

void client_can_register_MockWithCallback(OPMOCK_client_can_register_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    client_can_register_struct_inst.callback = callback;
    client_can_register_struct_inst.expectedCalls = 0;
    client_can_register_struct_inst.actualCalls = 0;
}

void client_can_register_VerifyMock()
{
    if (client_can_register_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'client_can_register'",client_can_register_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void client_can_register_ExpectAndReturn (Client * client, _Bool to_return, OPMOCK_MATCHER match_client)
{
    if(client_can_register_struct_inst.callback != NULL)
    {
        client_can_register_MockReset ();
    }

    if(client_can_register_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting client_can_register_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"_Bool client_can_register (Client * client)");
    client_can_register_struct_inst.calls[client_can_register_struct_inst.expectedCalls].client = (void *)client;
    client_can_register_struct_inst.calls[client_can_register_struct_inst.expectedCalls].match_client = match_client;
    client_can_register_struct_inst.calls[client_can_register_struct_inst.expectedCalls].to_return = (_Bool) to_return;
    client_can_register_struct_inst.calls[client_can_register_struct_inst.expectedCalls].check_params = 1;
    client_can_register_struct_inst.expectedCalls++;
}

_Bool client_set_username(Client * client, const char * username)
{
    _Bool default_res = (_Bool)client_set_username_struct_inst.calls[0].to_return;
    int opmock_i;
    client_set_username_struct_inst.actualCalls++;

    if (client_set_username_struct_inst.callback != NULL)
    {
        return client_set_username_struct_inst.callback (client, username, client_set_username_struct_inst.actualCalls);
    }
    if (client_set_username_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'client_set_username', returning random value.");
        return default_res;
    }

    if(strcmp(opmock_get_current_call(), "_Bool client_set_username (Client * client, const char * username)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to '_Bool client_set_username(Client * client, const char * username)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (client_set_username_struct_inst.calls[0].check_params == 1) {
        if(client_set_username_struct_inst.calls[0].match_client) {
            void * val1 = (void *) &client_set_username_struct_inst.calls[0].client;
            void * val2 = (void *) &client;
            int match_result = client_set_username_struct_inst.calls[0].match_client(val1, val2, "client", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'client_set_username', %s",client_set_username_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
        if(client_set_username_struct_inst.calls[0].match_username) {
            void * val1 = (void *) &client_set_username_struct_inst.calls[0].username;
            void * val2 = (void *) &username;
            int match_result = client_set_username_struct_inst.calls[0].match_username(val1, val2, "username", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'client_set_username', %s",client_set_username_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < client_set_username_struct_inst.expectedCalls; opmock_i++) {
        client_set_username_struct_inst.calls[opmock_i - 1] = client_set_username_struct_inst.calls[opmock_i];
    }

    client_set_username_struct_inst.expectedCalls--;
    return default_res;
}

void client_set_username_MockReset()
{
    client_set_username_struct_inst.expectedCalls = 0;
    client_set_username_struct_inst.actualCalls = 0;
    client_set_username_struct_inst.callback = NULL;
}

void client_set_username_MockWithCallback(OPMOCK_client_set_username_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    client_set_username_struct_inst.callback = callback;
    client_set_username_struct_inst.expectedCalls = 0;
    client_set_username_struct_inst.actualCalls = 0;
}

void client_set_username_VerifyMock()
{
    if (client_set_username_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'client_set_username'",client_set_username_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void client_set_username_ExpectAndReturn (Client * client, const char * username, _Bool to_return, OPMOCK_MATCHER match_client, OPMOCK_MATCHER match_username)
{
    if(client_set_username_struct_inst.callback != NULL)
    {
        client_set_username_MockReset ();
    }

    if(client_set_username_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting client_set_username_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"_Bool client_set_username (Client * client, const char * username)");
    client_set_username_struct_inst.calls[client_set_username_struct_inst.expectedCalls].client = (void *)client;
    client_set_username_struct_inst.calls[client_set_username_struct_inst.expectedCalls].username = (void *)username;
    client_set_username_struct_inst.calls[client_set_username_struct_inst.expectedCalls].match_client = match_client;
    client_set_username_struct_inst.calls[client_set_username_struct_inst.expectedCalls].match_username = match_username;
    client_set_username_struct_inst.calls[client_set_username_struct_inst.expectedCalls].to_return = (_Bool) to_return;
    client_set_username_struct_inst.calls[client_set_username_struct_inst.expectedCalls].check_params = 1;
    client_set_username_struct_inst.expectedCalls++;
}

_Bool client_set_nickname(Client * client, const char * nickname)
{
    _Bool default_res = (_Bool)client_set_nickname_struct_inst.calls[0].to_return;
    int opmock_i;
    client_set_nickname_struct_inst.actualCalls++;

    if (client_set_nickname_struct_inst.callback != NULL)
    {
        return client_set_nickname_struct_inst.callback (client, nickname, client_set_nickname_struct_inst.actualCalls);
    }
    if (client_set_nickname_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'client_set_nickname', returning random value.");
        return default_res;
    }

    if(strcmp(opmock_get_current_call(), "_Bool client_set_nickname (Client * client, const char * nickname)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to '_Bool client_set_nickname(Client * client, const char * nickname)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (client_set_nickname_struct_inst.calls[0].check_params == 1) {
        if(client_set_nickname_struct_inst.calls[0].match_client) {
            void * val1 = (void *) &client_set_nickname_struct_inst.calls[0].client;
            void * val2 = (void *) &client;
            int match_result = client_set_nickname_struct_inst.calls[0].match_client(val1, val2, "client", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'client_set_nickname', %s",client_set_nickname_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
        if(client_set_nickname_struct_inst.calls[0].match_nickname) {
            void * val1 = (void *) &client_set_nickname_struct_inst.calls[0].nickname;
            void * val2 = (void *) &nickname;
            int match_result = client_set_nickname_struct_inst.calls[0].match_nickname(val1, val2, "nickname", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'client_set_nickname', %s",client_set_nickname_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < client_set_nickname_struct_inst.expectedCalls; opmock_i++) {
        client_set_nickname_struct_inst.calls[opmock_i - 1] = client_set_nickname_struct_inst.calls[opmock_i];
    }

    client_set_nickname_struct_inst.expectedCalls--;
    return default_res;
}

void client_set_nickname_MockReset()
{
    client_set_nickname_struct_inst.expectedCalls = 0;
    client_set_nickname_struct_inst.actualCalls = 0;
    client_set_nickname_struct_inst.callback = NULL;
}

void client_set_nickname_MockWithCallback(OPMOCK_client_set_nickname_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    client_set_nickname_struct_inst.callback = callback;
    client_set_nickname_struct_inst.expectedCalls = 0;
    client_set_nickname_struct_inst.actualCalls = 0;
}

void client_set_nickname_VerifyMock()
{
    if (client_set_nickname_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'client_set_nickname'",client_set_nickname_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void client_set_nickname_ExpectAndReturn (Client * client, const char * nickname, _Bool to_return, OPMOCK_MATCHER match_client, OPMOCK_MATCHER match_nickname)
{
    if(client_set_nickname_struct_inst.callback != NULL)
    {
        client_set_nickname_MockReset ();
    }

    if(client_set_nickname_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting client_set_nickname_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"_Bool client_set_nickname (Client * client, const char * nickname)");
    client_set_nickname_struct_inst.calls[client_set_nickname_struct_inst.expectedCalls].client = (void *)client;
    client_set_nickname_struct_inst.calls[client_set_nickname_struct_inst.expectedCalls].nickname = (void *)nickname;
    client_set_nickname_struct_inst.calls[client_set_nickname_struct_inst.expectedCalls].match_client = match_client;
    client_set_nickname_struct_inst.calls[client_set_nickname_struct_inst.expectedCalls].match_nickname = match_nickname;
    client_set_nickname_struct_inst.calls[client_set_nickname_struct_inst.expectedCalls].to_return = (_Bool) to_return;
    client_set_nickname_struct_inst.calls[client_set_nickname_struct_inst.expectedCalls].check_params = 1;
    client_set_nickname_struct_inst.expectedCalls++;
}

_Bool client_set_realname(Client * client, const char * realname)
{
    _Bool default_res = (_Bool)client_set_realname_struct_inst.calls[0].to_return;
    int opmock_i;
    client_set_realname_struct_inst.actualCalls++;

    if (client_set_realname_struct_inst.callback != NULL)
    {
        return client_set_realname_struct_inst.callback (client, realname, client_set_realname_struct_inst.actualCalls);
    }
    if (client_set_realname_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'client_set_realname', returning random value.");
        return default_res;
    }

    if(strcmp(opmock_get_current_call(), "_Bool client_set_realname (Client * client, const char * realname)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to '_Bool client_set_realname(Client * client, const char * realname)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (client_set_realname_struct_inst.calls[0].check_params == 1) {
        if(client_set_realname_struct_inst.calls[0].match_client) {
            void * val1 = (void *) &client_set_realname_struct_inst.calls[0].client;
            void * val2 = (void *) &client;
            int match_result = client_set_realname_struct_inst.calls[0].match_client(val1, val2, "client", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'client_set_realname', %s",client_set_realname_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
        if(client_set_realname_struct_inst.calls[0].match_realname) {
            void * val1 = (void *) &client_set_realname_struct_inst.calls[0].realname;
            void * val2 = (void *) &realname;
            int match_result = client_set_realname_struct_inst.calls[0].match_realname(val1, val2, "realname", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'client_set_realname', %s",client_set_realname_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < client_set_realname_struct_inst.expectedCalls; opmock_i++) {
        client_set_realname_struct_inst.calls[opmock_i - 1] = client_set_realname_struct_inst.calls[opmock_i];
    }

    client_set_realname_struct_inst.expectedCalls--;
    return default_res;
}

void client_set_realname_MockReset()
{
    client_set_realname_struct_inst.expectedCalls = 0;
    client_set_realname_struct_inst.actualCalls = 0;
    client_set_realname_struct_inst.callback = NULL;
}

void client_set_realname_MockWithCallback(OPMOCK_client_set_realname_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    client_set_realname_struct_inst.callback = callback;
    client_set_realname_struct_inst.expectedCalls = 0;
    client_set_realname_struct_inst.actualCalls = 0;
}

void client_set_realname_VerifyMock()
{
    if (client_set_realname_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'client_set_realname'",client_set_realname_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void client_set_realname_ExpectAndReturn (Client * client, const char * realname, _Bool to_return, OPMOCK_MATCHER match_client, OPMOCK_MATCHER match_realname)
{
    if(client_set_realname_struct_inst.callback != NULL)
    {
        client_set_realname_MockReset ();
    }

    if(client_set_realname_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting client_set_realname_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"_Bool client_set_realname (Client * client, const char * realname)");
    client_set_realname_struct_inst.calls[client_set_realname_struct_inst.expectedCalls].client = (void *)client;
    client_set_realname_struct_inst.calls[client_set_realname_struct_inst.expectedCalls].realname = (void *)realname;
    client_set_realname_struct_inst.calls[client_set_realname_struct_inst.expectedCalls].match_client = match_client;
    client_set_realname_struct_inst.calls[client_set_realname_struct_inst.expectedCalls].match_realname = match_realname;
    client_set_realname_struct_inst.calls[client_set_realname_struct_inst.expectedCalls].to_return = (_Bool) to_return;
    client_set_realname_struct_inst.calls[client_set_realname_struct_inst.expectedCalls].check_params = 1;
    client_set_realname_struct_inst.expectedCalls++;
}

const char * client_get_nickname(Client * client)
{
    const char * default_res = (const char *)client_get_nickname_struct_inst.calls[0].to_return;
    int opmock_i;
    client_get_nickname_struct_inst.actualCalls++;

    if (client_get_nickname_struct_inst.callback != NULL)
    {
        return client_get_nickname_struct_inst.callback (client, client_get_nickname_struct_inst.actualCalls);
    }
    if (client_get_nickname_struct_inst.expectedCalls == 0)
    {
        opmock_add_error_message((char *) "WARNING : unexpected call of 'client_get_nickname', returning random value.");
        return default_res;
    }

    if(strcmp(opmock_get_current_call(), "const char * client_get_nickname (Client * client)") != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : got call to 'const char * client_get_nickname(Client * client)',  but was expecting call to '%s'", opmock_get_current_call());
        opmock_add_error_message(buffer);
    }
    opmock_pop_call();

    if (client_get_nickname_struct_inst.calls[0].check_params == 1) {
        if(client_get_nickname_struct_inst.calls[0].match_client) {
            void * val1 = (void *) &client_get_nickname_struct_inst.calls[0].client;
            void * val2 = (void *) &client;
            int match_result = client_get_nickname_struct_inst.calls[0].match_client(val1, val2, "client", get_matcher_message());
            if(match_result){
                char buffer[OP_ERROR_MESSAGE_LENGTH];
                snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : on call number %d of 'client_get_nickname', %s",client_get_nickname_struct_inst.actualCalls, get_matcher_message());
                opmock_add_error_message((char *) buffer);
            }
        }
    }

    for(opmock_i = 1; opmock_i < client_get_nickname_struct_inst.expectedCalls; opmock_i++) {
        client_get_nickname_struct_inst.calls[opmock_i - 1] = client_get_nickname_struct_inst.calls[opmock_i];
    }

    client_get_nickname_struct_inst.expectedCalls--;
    return default_res;
}

void client_get_nickname_MockReset()
{
    client_get_nickname_struct_inst.expectedCalls = 0;
    client_get_nickname_struct_inst.actualCalls = 0;
    client_get_nickname_struct_inst.callback = NULL;
}

void client_get_nickname_MockWithCallback(OPMOCK_client_get_nickname_CALLBACK callback)
{
    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    client_get_nickname_struct_inst.callback = callback;
    client_get_nickname_struct_inst.expectedCalls = 0;
    client_get_nickname_struct_inst.actualCalls = 0;
}

void client_get_nickname_VerifyMock()
{
    if (client_get_nickname_struct_inst.expectedCalls != 0) {
        char buffer[OP_ERROR_MESSAGE_LENGTH];
        snprintf(buffer, OP_ERROR_MESSAGE_LENGTH, "WARNING : Bad number of calls (%d) for 'client_get_nickname'",client_get_nickname_struct_inst.actualCalls);
        opmock_add_error_message((char *) buffer);
    }
}

void client_get_nickname_ExpectAndReturn (Client * client, const char * to_return, OPMOCK_MATCHER match_client)
{
    if(client_get_nickname_struct_inst.callback != NULL)
    {
        client_get_nickname_MockReset ();
    }

    if(client_get_nickname_struct_inst.expectedCalls >= MAX_FUNC_CALL)
    {
        printf("WARNING : aborting client_get_nickname_ExpectAndReturn, call stack overload.");
        return;
    }

    opmock_add_reset_callback(opmock_reset_all_mocks_in_this_header);
    opmock_add_verify_callback(opmock_verify_all_mocks_in_this_header);
    opmock_add_call((char *)"const char * client_get_nickname (Client * client)");
    client_get_nickname_struct_inst.calls[client_get_nickname_struct_inst.expectedCalls].client = (void *)client;
    client_get_nickname_struct_inst.calls[client_get_nickname_struct_inst.expectedCalls].match_client = match_client;
    client_get_nickname_struct_inst.calls[client_get_nickname_struct_inst.expectedCalls].to_return = ( char *) to_return;
    client_get_nickname_struct_inst.calls[client_get_nickname_struct_inst.expectedCalls].check_params = 1;
    client_get_nickname_struct_inst.expectedCalls++;
}

