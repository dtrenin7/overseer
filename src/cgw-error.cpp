/*
 * cgw-error.cpp
 *
 *  Created on: 23 june 2015
 *      Author: Dmitry Trenin  (dtrenin7@gmail.com)
 */

#include "cgw-error.h"
#include "cgw-log.h"

namespace CGW {

error_t::error_t() : code(E_OK) {

}

error_t::error_t(error_code_t error, cstrptr_t src) :
		code(error), location(src) {

//    if( code != E_OK ) {
        //CGW_DEBUG( "ERROR: %s", get_text().c_str() );
    //}
}

error_t::error_t(cstrptr_t text_, cstrptr_t src) :
		code(E_TEXT_BASED), text(text_),location(src) {

    //CGW_DEBUG( "ERROR: %s", get_text().c_str() );
}

error_t::error_t(str_t text_, cstrptr_t src) :
		code(E_TEXT_BASED), text(text_),location(src) {

    //CGW_DEBUG( "ERROR: %s", get_text().c_str() );
}

error_t& error_t::operator = (const error_t& rhs) {

	code = rhs.code;
	text = rhs.text;
	location = rhs.location;
	return *this;
}

bool error_t::operator == (error_code_t error) {

	return code == error;
}

str_t error_t::get_text() {

	switch(code) {
	case E_OK:
		return "OK";
	case E_TEXT_BASED:
		return text + location;
	case E_PACKET_TOO_SMALL:
		return "Packet size is too small" + location;
	case E_INSUFFICIENT_MEMORY:
		return "FATAL: Insufficient memory" + location;
    case E_NOT_CONNECTED:
        return "Not connected" + location;
    case E_EMPTY_INCOMING_PACKET:
        return "Empty incoming packet" + location;
	};
	return "";
}

};	// namespace CGW
