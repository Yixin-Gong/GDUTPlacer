#ifndef VIOLET_GPLACE_DATABASE_PIN_H_
#define VIOLET_GPLACE_DATABASE_PIN_H_

#include <iostream>
#include <array>
#include <unordered_map>
#include"database/lib_pin.h"

class Pin : LibPin {
 public:
  Pin() {
    pin_pos_[0] = 0;
    pin_pos_[1] = 0;
  }
 private:
  std::array<int32_t, 2> offset_{};
  std::array<int32_t, 2> pin_pos_{};
};

#endif //#ifndef VIOLET_GPLACE_DATABASE_PIN_H_