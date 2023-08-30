#include "database/terminal.h"

void Terminal::set_size(const int32_t &l, const int32_t &w) {
  size_[0] = l;
  size_[1] = w;
}

void Terminal::set_spacing(const int32_t &spacing) {
  spacing_ = spacing;
}
void Terminal::set_cost(const int32_t &cost) {
  cost_ = cost;
}

std::array<double, 2> Terminal::get_center() {
  std::array<double, 2> center{};
  center[0] = size_[0] * 0.5;
  center[1] = size_[1] * 0.5;
  return center;
}
