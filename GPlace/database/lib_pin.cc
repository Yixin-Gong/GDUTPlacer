#include "database/lib_pin.h"

void LibPin::set_offset(int32_t x, int32_t y) {
  this->offset_[0] = x;
  this->offset_[1] = y;
}
