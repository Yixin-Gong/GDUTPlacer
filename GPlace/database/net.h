#ifndef VIOLET_GPLACE_DATABASE_NET_H_
#define VIOLET_GPLACE_DATABASE_NET_H_

#include <iostream>
#include <vector>
#include "database/lib_cell.h"

class Net
{
public:
  Net() = default;

  const std::vector<std::pair<std::string, std::string>> &net() const { return net_; }
  std::vector<std::pair<std::string, std::string>> &net() { return net_; }

  void set_net(const std::string &std_cell, const std::string &pin);
  uint32_t pin_num() { return net_.size(); }

private:
  std::vector<std::pair<std::string, std::string>> net_{};
};
#endif // VIOLET_GPLACE_DATABASE_NET_H_