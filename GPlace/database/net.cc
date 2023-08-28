#include "database/net.h"

void Net::set_net(const std::string &std_cell, const std::string &pin)
{
  this->net_.emplace_back(std_cell, pin);
}
