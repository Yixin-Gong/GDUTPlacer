#ifndef VIOLET_GPLACE_DATABASE_TECHNOLOGY_H_
#define VIOLET_GPLACE_DATABASE_TECHNOLOGY_H_

#include <iostream>
#include <unordered_map>
#include "database/lib_cell.h"
class Technology {
 public:
  Technology() {
    lib_cell_count_ = 0;
  }

  void add_lib_cell(const std::string &name, LibCell &lib_cell);
  void set_lib_cell_count(const uint32_t &num);
  uint32_t &get_lib_cell_count() { return lib_cell_count_; }
  void set_tech_name(const std::string &name);
 private:
  std::unordered_map<std::string, LibCell> lib_cell_map_{};
  uint32_t lib_cell_count_{};
};

#endif //VIOLET_GPLACE_DATABASE_TECHNOLOGY_H_
