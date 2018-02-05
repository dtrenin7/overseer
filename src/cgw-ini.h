/*
 * cgw-ini.h
 *
 *  Created on: 23 june 2015
 *      Author: Dmitry Trenin (dtrenin7@gmail.com)
 */

#ifndef SRC_CGW_INI_H_
#define SRC_CGW_INI_H_

#include "cgw-error.h"
#include <iostream>
#include <fstream>

namespace CGW {

class ini {

    std::ifstream*  file;   ///< file stream

public:
    ini();
    virtual ~ini();

    error_t open(cstrptr_t name);
    error_t read(const str_t& section, const str_t& key, str_t& value);
};

};	// namespace CGW

#endif /* SRC_CGW_INI_H_ */
