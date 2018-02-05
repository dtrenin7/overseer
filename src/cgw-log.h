/*
 * cgw-log.h
 *
 *  Created on: 29 june 2015
 *      Author: Dmitry Trenin (dtrenin7@gmail.com)
 */

#ifndef CGW_LOG_H_
#define CGW_LOG_H_

#ifdef __pnacl__
#define	isascii(c)	(((c) & ~0x7f) == 0)	/* If C is a 7 bit value.  */
#endif

#include "cgw-types.h"
#include <stdarg.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

namespace CGW {

template<typename... Args>
str_t string_format(const i8_t* fmt, Args... args) {

    size_t size = snprintf(nullptr, 0, fmt, args...);
    str_t buf;
    buf.reserve(size + 1);
    buf.resize(size);
    snprintf(&buf[0], size + 1, fmt, args...);
    return buf;
}

};	// namespace CGW

#define STR CGW::string_format
#define VERBOSE(message) printf("%s\n", message)
#define CGW_ERROR(log_message, ...) printf(STR("[ERROR] " log_message "\n", ##__VA_ARGS__).c_str())
#define CGW_INFO(log_message, ...)  printf(STR("[INFO] " log_message "\n", ##__VA_ARGS__).c_str())
#define CGW_DEBUG(log_message, ...) printf(STR("[DEBUG] " log_message "\n", ##__VA_ARGS__).c_str())
#define CGW_PROC CGW_INFO("%s", __FUNCTION__)
#ifdef ASSERT
#undef ASSERT
#endif
#define ASSERT(x) CGW_INFO("%s : " #x " = 0x%X", __FUNCTION__, x); assert(x)

#endif /* CGW_LOG_H_ */
