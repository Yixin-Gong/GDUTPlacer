#ifndef VIOLET_GPLACE_DATABASE_MACRO_H_
#define VIOLET_GPLACE_DATABASE_MACRO_H_

#include <iostream>
#include <array>
#include "database/lib_cell.h"

class Macro : LibCell {
 public:
  Macro() {
    loc_[0] = 0;
    loc_[1] = 0;
    angle_ = 0;
    fixed_ = false;
  }

  const std::array<int32_t, 2> &loc() const { return loc_; }
  std::array<int32_t, 2> &loc() { return loc_; }
  const double &angle() const { return angle_; }
  double &angel() { return angle_; }
  bool &is_fix() { return fixed_; }
  void set_lib(const std::string &lib_name);
  void fix_macro();

 private:
  std::array<int32_t, 2> loc_{};
  std::string macro_name_;
  std::string lib_name_;
  double angle_;
  bool fixed_;
};

#endif // VIOLET_GPLACE_DATABASE_MACRO_H_