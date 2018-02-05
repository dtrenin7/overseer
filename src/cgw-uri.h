#include "cgw-error.h"


namespace CGW {

str_t UriDecode(const str_t& sSrc);
str_t UriEncode(const str_t& sSrc);
error_t UriDecodeBuffer(const buffer_t& sSrc, buffer_t& dst);

};  // namespace CGW
