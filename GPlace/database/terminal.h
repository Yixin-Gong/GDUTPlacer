#ifndef VIOLET_GPLACE_DATABASE_TERMINAL_H_
#define VIOLET_GPLACE_DATABASE_TERMINAL_H_

#include <iostream>
#include <array>

class Terminal {
 public:
  Terminal() {
    size_[0] = 0;
    size_[1] = 0;
    spacing_ = 0;
    cost_ = 0;
  }

  int32_t &get_spacing() { return this->spacing_; }
  int32_t &get_cost() { return this->cost_; }

  void set_terminal(int32_t l, int32_t w, int32_t spacing, int32_t cost);

  std::array<double, 2> get_center();
 private:
  std::array<int32_t, 2> size_{};
  int32_t spacing_{};
  int32_t cost_{};
};

#endif //VIOLET_GPLACE_DATABASE_TERMINAL_H_