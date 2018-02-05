/*
 * cgw-types.h
 *
 *  Created on: 23 june 2015
 *      Author: Dmitry Trenin (dtrenin7@gmail.com)
 */

#ifndef CGW_TYPES_H_
#define CGW_TYPES_H_

#include <vector>
#include <string>
#include <memory>
#include <array>
#include <functional>

#define DISALLOW_COPY_AND_ASSIGN(TypeName) \
    TypeName(const TypeName&);               \
    void operator=(const TypeName&)

#define BUFLEN(buffer) (buffer.size() + 4)
// we must store buffer size (dword) in raw data

namespace CGW {

typedef char                i8_t;
typedef unsigned char       u8_t;
typedef short int           i16_t;
typedef unsigned short int  u16_t;
typedef int                 i32_t;
typedef unsigned int        u32_t;
typedef long long           i64_t;
typedef unsigned long long  u64_t;
typedef char*               strptr_t;
typedef const char*         cstrptr_t;
typedef std::string         str_t;
typedef std::vector<u8_t>   buffer_t;
typedef std::hash<str_t>    strhash_t;

typedef std::array<u8_t,32>     div_data_t; // Size of GOST R 34.11 hash
typedef std::array<u8_t,32>     serial_t;
typedef std::array<u8_t,36>     encoded_sk_t; // 32 bytes of GOST 2147-89 key + 4 bytes of imito
typedef std::array<u8_t,100>    public_key_blob_t; //May be longer if not dafault crypto OIDs used
typedef std::array<u8_t,8>      iv_t;
typedef u8_t                    smk_set_num_t;

enum MK_TYPE {
    MKT_ENCRYPT = 0,
    MKT_DECRYPT
};

typedef std::shared_ptr<buffer_t> buffer_ptr;

};	// namespace CGW

#endif /* CGW_TYPES_H_ */
