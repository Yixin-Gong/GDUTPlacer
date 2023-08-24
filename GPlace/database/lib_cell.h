#ifndef  VIOLET_GPLACE_DATABASE_LIB_CELL_H_
#define  VIOLET_GPLACE_DATABASE_LIB_CELL_H_

#include <iostream>
#include <array>
#include <unordered_map>
#include "database/lib_pin.h"

class LibCell {
 public:
  LibCell() {
    size_[0] = 0;
    size_[1] = 0;
  }
  const std::unordered_map<std::string, LibPin> &pins() { return pins_; }
  uint32_t pin_num() { return pins_.size(); }

  void set_size(int32_t l, int32_t w);
  void add_pin(const std::string &name, LibPin lib_pin);
  std::array<double, 2> get_center();
 protected:
  std::unordered_map<std::string, LibPin> pins_{};
  int32_t size_[2]{};
};

#endif //VIOLET_GPLACE_DATABASE_LIB_CELL_H_