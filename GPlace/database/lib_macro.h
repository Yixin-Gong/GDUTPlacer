#ifndef VIOLET_GPLACE_DATABASE_LIB_MACRO_H_
#define VIOLET_GPLACE_DATABASE_LIB_MACRO_H_

#include <iostream>
#include <unordered_map>
#include "lib_pin.h"

class LibMacro {
 public:
  LibMacro() {
    size_[0] = 0;
    size_[1] = 0;
    pin_num_ = 0;
  }

  const std::unordered_map<std::string, LibPin> &pins() { return pins_; }
  uint32_t pin_num() { return pins_.size(); }

  void set_size(int32_t l, int32_t w);
  void add_pin(const std::string &name, LibPin lib_pin);
  std::array<double, 2> get_center();

 private:
  int32_t size_[2]{};
  uint32_t pin_num_{};
  std::unordered_map<std::string, LibPin> pins_{};
};

#endif //VIOLET_GPLACE_DATABASE_LIB_MACRO_H_