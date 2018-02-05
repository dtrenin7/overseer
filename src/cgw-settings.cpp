/*
 * cgw-settings.cpp
 *
 *  Created on: 01 july 2015
 *      Author: Dmitry Trenin (dtrenin7@gmail.com)
 */

#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include "cgw-settings.h"
#include "cgw-ini.h"
#include "cgw-log.h"
#include "cgw-utils.h"

namespace CGW {
  settings* Settings;

#define READ_STRING(key, ini_section, ini_key) { conf_value.clear();\
    if( config.read(str_t(ini_section), str_t(ini_key), conf_value) == E_OK )\
        key = conf_value;\
    CGW_INFO("SETTINGS(%s) = %s", #key, key.c_str()); }

#define READ_BASE64(key, ini_section, ini_key) { conf_value.clear();\
    if( config.read(str_t(ini_section), str_t(ini_key), conf_value) == E_OK )\
        THROW(CGW::base64decode(key, STR2B(conf_value)));\
    CGW_INFO("SETTINGS(%s) = %s", #key, buff2hex2(key).c_str()); }

#define READ_INTEGER(key, ini_section, ini_key) { conf_value.clear();\
    if( config.read(str_t(ini_section), str_t(ini_key), conf_value) == E_OK )\
        key = atoi(conf_value.c_str());\
    CGW_INFO("SETTINGS(%s) = %d", #key, key); }

#define READ_STRING_ENV(key, ini_section, ini_key, env_var)\
  env = getenv(env_var);\
  if(env && strcmp(env, "")) {key = env;\
    CGW_INFO("SETTINGS(%s) = ENV(%s) = %s", #key, env_var, env);}\
    else {READ_STRING(key, ini_section, ini_key)};

#define READ_INTEGER_ENV(key, ini_section, ini_key, env_var)\
  env = getenv(env_var);\
  if(env && strcmp(env, "")) {key = atoi(env);\
    CGW_INFO("SETTINGS(%s) = ENV(%s) = %s", #key, env_var, env);}\
    else {READ_INTEGER(key, ini_section, ini_key)};


settings::settings() {
    error_t error;
    str_t conf_value;

    ini config;
    THROW(config.open(CONFIG_FILE));
    // try to open config file

    cstrptr_t server = "server";
    READ_INTEGER(threads, server, "threads");
     //*/

    CGW_INFO("Reading settings done...");
    // read settings from config and/or environment */
}

#undef READ_STRING
#undef READ_INTEGER
#undef READ_BASE64
};	// namespace CGW
