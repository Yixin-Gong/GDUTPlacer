#include "database/terminal.h"

void Terminal::set_terminal(int32_t l, int32_t w, int32_t spacing, int32_t cost) {
  this->size_[0] = l;
  this->size_[1] = w;
  this->spacing_ = spacing;
  this->cost_ = cost;
}

std::array<double, 2> Terminal::get_center() {
  std::array<double, 2> center{};
  center[0] = this->size_[0] * 0.5;
  center[1] = this->size_[1] * 0.5;
  return center;
}
