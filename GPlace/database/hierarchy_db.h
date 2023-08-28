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
class HierarchyDB
{
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

  std::unordered_map<std::string, Net> &get_nets() { return nets_; }
  const std::unordered_map<std::string, Net> &get_nets() const { return nets_; }
  std::unordered_map<std::string, Technology> &get_lib() { return tech_lib_; }
  const std::unordered_map<std::string, Technology> &get_lib() const { return tech_lib_; }

  std::unordered_map<std::string, StdCell> &net2cell() { return net2cell_; }
  const std::unordered_map<std::string, StdCell> &net2cell() const { return net2cell_; }
  std::unordered_map<std::string, Pin> &net2pin() { return net2pin_; }
  const std::unordered_map<std::string, Pin> &net2pin() const { return net2pin_; }
  std::unordered_map<std::string, Pin> &cell2pin() { return cell2pin_; }
  const std::unordered_map<std::string, Pin> &cell2pin() const { return cell2pin_; }
  std::unordered_map<std::string, Net> &cell2net() { return cell2net_; }
  const std::unordered_map<std::string, Net> &cell2net() const { return cell2net_; }

  uint32_t nets_size() { return nets_.size(); }
  uint32_t lib_num() { return tech_lib_.size(); }

private:
  Die top_die_{};
  Die bottom_die_{};
  Terminal terminal_{};
  std::unordered_map<std::string, Net> nets_{};
  std::unordered_map<std::string, Technology> tech_lib_{};
  std::unordered_map<std::string, StdCell> net2cell_{};
  std::unordered_map<std::string, Pin> net2pin_{};
  std::unordered_map<std::string, Pin> cell2pin_{};
  std::unordered_map<std::string, Net> cell2net_{};
  std::unordered_map<std::string, StdCell> pin2cell_{};
  std::unordered_map<std::string, Net> pin2net_{};
};

#endif // VIOLET_GPLACE_DATABASE_HIERARCHY_DB_H_