#ifndef VIOLET_GPLACE_DATABASE_NET_H_
#define VIOLET_GPLACE_DATABASE_NET_H_

#include <iostream>
#include <vector>
#include "database/lib_cell.h"

class Net {
 public:
  Net() = default;
  std::vector<LibCell> &net() { return v_net_; }

  uint32_t pin_num() { return v_net_.size(); }
 private:
  std::vector<LibCell> v_net_{};
};
#endif // VIOLET_GPLACE_DATABASE_NET_H_