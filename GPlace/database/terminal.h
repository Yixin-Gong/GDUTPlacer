#ifndef VIOLET_GPLACE_DATABASE_TERMINAL_H_
#define VIOLET_GPLACE_DATABASE_TERMINAL_H_

#include <iostream>
#include <array>

class Terminal
{
public:
  Terminal()
  {
    size_[0] = 0;
    size_[1] = 0;
    spacing_ = 0;
    cost_ = 0;
  }

  std::array<int32_t, 2> &get_size() { return size_; }
  int32_t &get_spacing() { return spacing_; }
  int32_t &get_cost() { return cost_; }

  void set_size(const int32_t &l,const int32_t &w);
  void set_spacing(const int32_t &spacing);
  void set_cost(const int32_t &cost);
  std::array<double, 2> get_center();

private:
  std::array<int32_t, 2> size_{};
  int32_t spacing_{};
  int32_t cost_{};
};

#endif // VIOLET_GPLACE_DATABASE_TERMINAL_H_