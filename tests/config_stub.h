/* OPMOCK2 GENERATED CODE - DO NOT MODIFY */
#ifndef _CONFIG_STUB_H
#define _CONFIG_STUB_H

#include <json-c/json.h>
#include <config.h>
#include "opmock.h"

#ifdef __cplusplus
extern "C" {
#endif

void config_init_ExpectAndReturn();
void config_init_MockReset();
typedef void (* OPMOCK_config_init_CALLBACK)(int calls);
void config_init_MockWithCallback(OPMOCK_config_init_CALLBACK callback);
void config_init_VerifyMock();
void config_load_ExpectAndReturn(_Bool to_return);
void config_load_MockReset();
typedef _Bool (* OPMOCK_config_load_CALLBACK)(int calls);
void config_load_MockWithCallback(OPMOCK_config_load_CALLBACK callback);
void config_load_VerifyMock();
void config_register_section_ExpectAndReturn(const char * sectionName, bool isArray, ConfigSection * to_return, OPMOCK_MATCHER match_sectionName, OPMOCK_MATCHER match_isArray);
void config_register_section_MockReset();
typedef ConfigSection * (* OPMOCK_config_register_section_CALLBACK)(const char * sectionName, bool isArray, int calls);
void config_register_section_MockWithCallback(OPMOCK_config_register_section_CALLBACK callback);
void config_register_section_VerifyMock();
void config_register_field_ExpectAndReturn(ConfigSection * arg1, const char * arg2, json_type arg3, ConfigFieldHandler arg4, OPMOCK_MATCHER match_arg1, OPMOCK_MATCHER match_arg2, OPMOCK_MATCHER match_arg3, OPMOCK_MATCHER match_arg4);
void config_register_field_MockReset();
typedef void (* OPMOCK_config_register_field_CALLBACK)(ConfigSection * arg1, const char * arg2, json_type arg3, ConfigFieldHandler arg4, int calls);
void config_register_field_MockWithCallback(OPMOCK_config_register_field_CALLBACK callback);
void config_register_field_VerifyMock();

#ifdef __cplusplus
}
#endif
#endif
