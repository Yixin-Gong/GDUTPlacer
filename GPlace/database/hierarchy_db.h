#ifndef VIOLET_GPLACE_DATABASE_HIERARCHY_DB_H_
#define VIOLET_GPLACE_DATABASE_HIERARCHY_DB_H_

#include <iostream>
#include <vector>
#include <unordered_map>
#include "database/terminal.h"
#include "database/technology.h"
#include "database/die.h"
#include "database/net.h"
#include "database/std_cell.h"
#include "database/macro.h"

class HierarchyDB {
 public:
  HierarchyDB() = default;
  void init_db();
  void write_db();

  Die &top_die() { return top_die_; }
  const Die &top_die() const { return top_die_; }
  Die &bottom_die() { return bottom_die_; }
  const Die &bottom_die() const { return bottom_die_; }

  Terminal &terminal() { return terminal_; }
  const Terminal &terminal() const { return terminal_; }

  std::unordered_map<std::string, Net> &get_nets() { return net_list_; }
  const std::unordered_map<std::string, Net> &get_nets() const { return net_list_; }
  std::unordered_map<std::string, Technology> &get_lib() { return tech_lib_; }
  const std::unordered_map<std::string, Technology> &get_lib() const { return tech_lib_; }
  std::unordered_map<std::string, std::string> &cell2lib() { return cell2lib_; }
  const std::unordered_map<std::string, std::string> &cell2lib() const { return cell2lib_; }
  uint32_t net_num() { return net_list_.size(); }
  uint32_t lib_num() { return tech_lib_.size(); }

 private:
  Die top_die_{};
  Die bottom_die_{};
  Terminal terminal_{};
  std::unordered_map<std::string, Net> net_list_{};
  std::unordered_map<std::string, Technology> tech_lib_{};
  std::unordered_map<std::string, std::string> cell2lib_{};
};

#endif // VIOLET_GPLACE_DATABASE_HIERARCHY_DB_H_