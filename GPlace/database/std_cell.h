#ifndef VIOLET_GPLACE_DATABASE_STD_CELL_H_
#define VIOLET_GPLACE_DATABASE_STD_CELL_H_

#include <iostream>
#include <array>
#include "database/pin.h"
#include "database/lib_cell.h"
class StdCell :LibCell {
 public:
  StdCell() {
    loc_xy_[0] = 0;
    loc_xy_[1] = 0;
    fixed = false;
  }
  void set_cell();
 private:
  std::array<int32_t, 2> loc_xy_{};
  std::unordered_map<std::string, Pin> pins_{};
  bool fixed{};
};

#endif //VIOLET_GPLACE_DATABASE_STD_CELL_H_