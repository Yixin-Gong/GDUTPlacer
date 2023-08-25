#include "database/pin.h"
void Pin::set_pin_pos(const std::array<int32_t, 2> &offset, const std::array<int32_t, 2> &loc) {
  this->pin_pos_[0] = loc[0] + offset[0];
  this->pin_pos_[1] = loc[1] + offset[1];
}
