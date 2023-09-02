#ifndef VIOLET_GPLACE_DATABASE_NET_H_
#define VIOLET_GPLACE_DATABASE_NET_H_

#include <iostream>
#include <vector>
#include "database/lib_cell.h"

class Net {
 public:
  Net() = default;
  std::unordered_map<std::string, std::string> &net() { return net_; }

  uint32_t pin_num() { return net_.size(); }
 private:
  std::unordered_map<std::string, std::string> net_{};
};
#endif // VIOLET_GPLACE_DATABASE_NET_H_