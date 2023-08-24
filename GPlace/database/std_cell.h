#ifndef VIOLET_GPLACE_DATABASE_STD_CELL_H_
#define VIOLET_GPLACE_DATABASE_STD_CELL_H_

#include <iostream>
#include <array>
#include "pin.h"

class StdCell {
 public:
  StdCell() {
    loc_xy_[0] = 0;
    loc_xy_[1] = 0;
    size_[0] = 0;
    size_[1] = 0;
    fixed = false;
  }
  void set_cell();
 private:
  std::array<int32_t, 2> loc_xy_{};
  std::array<int32_t, 2> size_{};
  std::unordered_map<std::string, Pin> pins_{};
  bool fixed{};
};

#endif //VIOLET_GPLACE_DATABASE_STD_CELL_H_