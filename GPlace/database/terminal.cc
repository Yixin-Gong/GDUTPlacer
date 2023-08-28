#include "database/terminal.h"

void Terminal::set_terminal(int32_t l, int32_t w, int32_t spacing, int32_t cost)
{
  size_[0] = l;
  size_[1] = w;
  spacing_ = spacing;
  cost_ = cost;
}

std::array<double, 2> Terminal::get_center()
{
  std::array<double, 2> center{};
  center[0] = size_[0] * 0.5;
  center[1] = size_[1] * 0.5;
  return center;
}
