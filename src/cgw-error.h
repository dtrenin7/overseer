/*
 * cgw-error.h
 *
 *  Created on: 23 june 2015
 *      Author: Dmitry Trenin (dtrenin7@gmail.com)
 */

#ifndef CGW_ERROR_H_
#define CGW_ERROR_H_

#include <string>
#include "cgw-types.h"

#define S(x) #x
#define S_(x) S(x)
#define S__LINE__ S_(__LINE__)
#define __FILELINE__ (" -> " __FILE__ " (" S__LINE__ ")")

#define STATUS(code_or_text) CGW::error_t(code_or_text, __FILELINE__)

#define CHECK(expr) error = expr; if(error.code != CGW::E_OK) return error
#define THROW(expr) error = expr; if(error.code != CGW::E_OK) throw error

namespace CGW {

typedef enum {
	E_OK = 0,
	E_TEXT_BASED,
	E_PACKET_TOO_SMALL,
	E_INSUFFICIENT_MEMORY,
	E_UNABLE_ACQUIRE_CSP,
	E_UNABLE_GENERATE_CONTAINER_NAME,
	E_UNABLE_HASH_DATA,
	E_UNABLE_SET_PIN,
	E_UNABLE_GENERATE_MK,
	E_UNABLE_GENERATE_EXCHANGE_KEY,
	E_UNABLE_ACQUIRE_SMK,
	E_UNABLE_DECODE_SESSION_KEY,
	E_UNABLE_ENCODE_SESSION_KEY,
	E_NOT_CONNECTED,
	E_EMPTY_INCOMING_PACKET

} error_code_t;

struct error_t {

	error_code_t	code;	///< error code

	error_t();
	error_t(error_code_t error, cstrptr_t src);
	error_t(cstrptr_t text_, cstrptr_t src);
	error_t(str_t text_, cstrptr_t src);
	error_t& operator = (const error_t& rhs);
	bool operator == (error_code_t error);

	virtual str_t get_text();

private:
	str_t		text;		///< text (only for E_TEXT_BASED)
	str_t		location;	///< source file & line
};

};	// namespace CGW

#endif /* CGW_ERROR_H_ */
