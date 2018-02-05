/*
 * cgw-ini.cpp
 *
 *  Created on: 23 june 2015
 *      Author: Dmitry Trenin (dtrenin7@gmail.com)
 */

#include "cgw-ini.h"
#include <string>
#include <algorithm>
#include "cgw-log.h"

namespace CGW {

static str_t trim(const str_t& s) {

    size_t l = s.length();
    if (l == 0)
        return s;
    size_t b = s.find_first_not_of(" \t\r\n\0");
    if (b == str_t::npos)
        b = 0;
    size_t e = s.find_last_not_of(" \t\r\n\0");
    if (e == str_t::npos)
        return s.substr(b);
    return s.substr(b, e-b+1);
}

static str_t makelower(const str_t& s) {

    str_t str = s;
    for( str_t::iterator i = str.begin(); i != str.end(); ++i)
        if (tolower(*i) != (int)*i)
            *i = (char)tolower(*i);
    return str;
}

static str_t value_for_key(const str_t& s, const str_t& k) {

    size_t p = s.find('=');
    if (p == str_t::npos || trim(makelower(s.substr(0,p))) != k)
        return "";
    p = s.find_first_not_of(" \t\n\r\0", p+1);
    return s.substr(p);
}

ini::ini() : file(0) {

}

ini::~ini() {

    if(file) {
        file->close();
        delete file;
        file = 0;
    }
}

error_t ini::open(cstrptr_t name) {

    try {
        file = new std::ifstream(name);
    }
    catch(const std::bad_alloc& exception) {
        return STATUS(E_INSUFFICIENT_MEMORY);
    };
    if( !file->good() ) {
        delete file, file = NULL;
        return STATUS("Can't open file " + str_t(name));
    }
    return STATUS(E_OK);
}

error_t ini::read(const str_t& section, const str_t& key, str_t& value)
{
    if (!file)
       return STATUS("file could not be opened");

    str_t s, k;
    str_t sec = str_t("[") + makelower(section) + "]";
    k = trim(makelower(key));
    bool found_section  = false;
    file->seekg(0);
    while( std::getline(*file, s) ) {
       if( *s.c_str() == '#' )
            continue;
       if( !found_section ) {
          if( trim(makelower(s)) == sec )
              found_section = true;
          continue;
       }
       value = value_for_key(trim(s), k);
       if( value.length() )
           return STATUS(E_OK);
    }
    return found_section ? STATUS("key" + key + " not found") :
        STATUS("section " + section + " not found");
}

};	// namespace CGW
