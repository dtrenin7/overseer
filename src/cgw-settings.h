/*
 * cgw-settings.h
 *
 *  Created on: 26 august 2015
 *      Author: Dmitry Trenin (dtrenin7@gmail.com)
 */

#ifndef SRC_CGW_SETTINGS_H_
#define SRC_CGW_SETTINGS_H_

#include "cgw-error.h"
#include <map>

#define CONFIG_FILE "./config.ini"

namespace CGW {

class settings {
public:
  settings();

  i32_t threads;    ///< кол-во рабочих потоков
};

extern settings* Settings;
};	// namespace CGW

#endif /* SRC_CGW_SETTINGS_H_ */
