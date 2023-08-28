#include "database/technology.h"

void Technology::add_lib_cell(const std::string &name, LibCell &lib_cell)
{
  this->lib_cell_map_.emplace(name, lib_cell);
}
void Technology::set_lib_cell_count(const uint32_t &num)
{
  this->lib_cell_count_ = num;
}

