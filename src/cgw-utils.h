/*
 * cgw-utils.h
 *
 *  Created on: 30 june 2015
 *      Author: Dmitry Trenin (dtrenin7@gmail.com)
 */

#ifndef SRC_CGW_UTILS_H_
#define SRC_CGW_UTILS_H_

#include "cgw-error.h"

//#define B2STR(buffer) str_t(buffer.begin(), buffer.end()).c_str()
#define B2STR(buffer) CGW::str_t(reinterpret_cast<CGW::cstrptr_t>(&buffer[0]), buffer.size())
#define STR2B(str) CGW::buffer_t(str.begin(), str.end())
#define BUF2STR(buffer) buff2hex(buffer).c_str()
// convert buffer to C string

#define RANDOM_DATA(x) res.x.resize( strlen(#x)+ (rand()%30));\
                        memcpy(&res.x[0], #x, strlen(#x));
// generate response random data

namespace CGW {

str_t buff2hex( buffer_t& buffer );
str_t buff2hex( u8_t* buffer, u32_t size );
void hex2buff( cstrptr_t str, buffer_t& buffer );
str_t buff2hex2( buffer_t& buffer );
// converts binary array into readable hex string

str_t get_module_path();
// get path to executing module

u32_t switch_endian(u32_t var);
// switch dword between little endian/big endian

u64_t get_tick_count();
// get time in milliseconds

error_t base64encode(buffer_t& out, const buffer_t& in);
error_t b64encode(buffer_t& out, const buffer_t& in);
// encode to Base64

error_t base64decode(buffer_t& out, const buffer_t& in);
error_t b64decode(buffer_t& out, const buffer_t& in);
str_t b64decode(const str_t& in);
// decode from Base64
// ***BEWARE*** BUGGY on random data!!! (use urlencode before or don't use)

constexpr u32_t str2int(cstrptr_t str, i32_t h = 0) {
    return !str[h] ? 5381 : (str2int(str, h+1)*33) ^ str[h]; };
// for string switching

str_t random_str(u32_t size = 32);
// generates random hex string

i32_t getdir(str_t dir, std::vector<str_t>& files);
// get list of directory content

void replace_substring(str_t& src, cstrptr_t macro, const str_t& value);
// replace substring

i32_t get_file_size(cstrptr_t filename);
// get file size

error_t file2buff(cstrptr_t filename, buffer_t& buffer);
// read file into buffer

error_t file2string(cstrptr_t filename, str_t& buffer);
// read file into string

void gen_random(buffer_t& data, size_t size);
// fill 'data' with 'size' random values.

error_t write_file(str_t name, const buffer_t& data);
// write 'data' to file 'name'. Creates file, if it doesn't exists and overwrites if it is exists.

error_t write_file(str_t name, const str_t& data);
// write 'data' to file 'name'. Creates file, if it doesn't exists and overwrites if it is exists.

//str_t sha1(buffer_t& buffer);
// compute SHA1 hash

};	// namespace CGW

#endif /* SRC_CGW_UTILS_H_ */
