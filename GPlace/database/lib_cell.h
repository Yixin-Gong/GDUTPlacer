#ifndef VIOLET_GPLACE_DATABASE_LIB_CELL_H_
#define VIOLET_GPLACE_DATABASE_LIB_CELL_H_

#include <iostream>
#include <memory>
#include <array>
#include <unordered_map>
#include "database/lib_pin.h"
class LibCell
{
public:
  LibCell()
  {
    size_[0] = 0;
    size_[1] = 0;
    is_macro_ = 0;
  }
  const std::unordered_map<std::string, LibPin> &pins() const { return pins_; }
  std::unordered_map<std::string, LibPin> &pins() { return pins_; }
  const std::array<int32_t, 2> &size() const { return size_; }
  std::array<int32_t, 2> &size() { return size_; }
  void set_size(const int32_t &l, const int32_t &w);
  void set_pin_num(const uint32_t &num) { this->pin_num_ = num; };
  void add_pin(const std::string &name, LibPin &lib_pin);
  void is_macro() { this->is_macro_ = 1; }
  
  std::array<double, 2> get_center();
  uint32_t pin_num() { return pin_num_; }

protected:
  std::unordered_map<std::string, LibPin> pins_{};
  std::array<int32_t, 2> size_{};
  uint32_t pin_num_{};
  uint32_t is_macro_{};
};

#endif // VIOLET_GPLACE_DATABASE_LIB_CELL_H_