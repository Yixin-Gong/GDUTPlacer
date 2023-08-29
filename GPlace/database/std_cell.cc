#include "database/std_cell.h"

void StdCell::set_lib(const std::string &lib_name) {
  lib_name_ = lib_name;
}
void StdCell::fix_cell() {
  fixed_ = true;
}
