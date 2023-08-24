#ifndef VIOLET_GPLACE_DATABASE_PIN_H_
#define VIOLET_GPLACE_DATABASE_PIN_H_

#include <iostream>
#include <array>
#include <unordered_map>
#include"lib_pin.h"

class Pin {
 public:
  Pin() {
    offset_[0] = 0;
    offset_[1] = 0;
    pin_pos_[0] = 0;
    pin_pos_[1] = 0;
  }

  void set_offset(const std::string &lib_pin_name, const std::string &tech);
 private:
  std::array<int32_t, 2> offset_{};
  std::array<int32_t, 2> pin_pos_{};
};

#endif //#ifndef VIOLET_GPLACE_DATABASE_PIN_H_