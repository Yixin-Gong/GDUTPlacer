#include "database/macro.h"

void Macro::set_lib(const std::string &lib_name) {
  lib_name_ = lib_name;
}

void Macro::fix_macro() {
  fixed_ = true;
}
