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

//  void set_macro(std::string name);
 private:
  std::array<int32_t, 2> loc_{};
  double angle_;
  bool fixed_;
};

#endif //VIOLET_GPLACE_DATABASE_MACRO_H_