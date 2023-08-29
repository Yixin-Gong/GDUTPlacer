#ifndef VIOLET_GPLACE_DATABASE_STD_CELL_H_
#define VIOLET_GPLACE_DATABASE_STD_CELL_H_

#include <iostream>
#include <array>
#include "database/lib_cell.h"
class StdCell : LibCell
{
public:
  StdCell()
  {
    loc_xy_[0] = 0;
    loc_xy_[1] = 0;
    fixed_ = false;
  }
  const std::array<int32_t, 2> &loc_xy() const { return loc_xy_; }
  std::array<int32_t, 2> &loc_xy() { return loc_xy_; }
//  const std::unordered_map<std::string, Pin> &pins() const { return pins_; }
//  std::unordered_map<std::string, Pin> &pins() { return pins_; }
  void set_lib(const std::string &lib_name);
  void fix_cell();

private:
  std::array<int32_t, 2> loc_xy_{};
  std::string lib_name_;
  bool fixed_{};
};

#endif // VIOLET_GPLACE_DATABASE_STD_CELL_H_