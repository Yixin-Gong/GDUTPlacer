#include "database/lib_cell.h"

void LibCell::set_size(const int32_t &l, const int32_t &w)
{
  this->size_[0] = l;
  this->size_[1] = w;
}
void LibCell::add_pin(const std::string &name, LibPin &lib_pin)
{
  this->pins_.emplace(name, lib_pin);
}
std::array<double, 2> LibCell::get_center()
{
  std::array<double, 2> center{};
  center[0] = this->size_[0] * 0.5;
  center[1] = this->size_[1] * 0.5;
  return center;
}

