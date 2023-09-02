#include "parser/contest_file_parser.h"
#include <iostream>
#include <sstream>
#include <vector>

void ContestParser::parse() {
  std::string tech_name, lib_cell_name, pin_name, net_name;

  Technology technology;
  LibCell lib_cell;
  LibPin lib_pin;
  StdCell cell;
  Net net;

  std::string line;
  while (std::getline(file_, line)) {
    std::vector<std::string> tokens = split_(line, ' ');
    if (line.empty()) {
      continue;
    } else {
      if (tokens[0] == "Tech") {
        tech_name = tokens[1];
        technology.set_lib_cell_count(std::stoi(tokens[2]));
        db().get_lib().emplace(tech_name, technology);
      } else if (tokens[0] == "LibCell") {
        if (tokens[1] == "Y")
          lib_cell.is_macro();
        lib_cell_name = tokens[2];
        lib_cell.set_size(std::stoi(tokens[3]), std::stoi(tokens[4]));
        lib_cell.set_pin_num(std::stoi(tokens[5]));
        technology = db().get_lib().find(tech_name)->second;
        technology.add_lib_cell(lib_cell_name, lib_cell);
      } else if (tokens[0] == "Pin" && !tokens[1].find('/')) {
        pin_name = tokens[1];
        lib_pin.set_offset(std::stoi(tokens[2]), std::stoi(tokens[3]));
        lib_cell = technology.lib_cell_map().find(lib_cell_name)->second;
        lib_cell.add_pin(pin_name, lib_pin);
      } else if (tokens[0] == "Die") {
        db().top_die().set_size(std::stoi(tokens[1]), std::stoi(tokens[2]),
                                std::stoi(tokens[3]), std::stoi(tokens[4]));
        db().bottom_die().set_size(std::stoi(tokens[1]), std::stoi(tokens[2]),
                                   std::stoi(tokens[3]), std::stoi(tokens[4]));
      } else if (tokens[0] == "TopDieMaxUtil") {
        db().top_die().set_util(std::stoi(tokens[1]));
      } else if (tokens[0] == "BottomDieMaxUtil") {
        db().bottom_die().set_util(std::stoi(tokens[1]));
      } else if (tokens[0] == "TopDieRows") {
        db().top_die().start_xy()[0] = std::stoi(tokens[1]);
        db().top_die().start_xy()[1] = std::stoi(tokens[2]);
        db().top_die().row_lh()[0] = std::stoi(tokens[3]);
        db().top_die().row_lh()[1] = std::stoi(tokens[4]);
        db().top_die().repeat() = std::stoi(tokens[5]);
      } else if (tokens[0] == "BottomDieRows") {
        db().bottom_die().start_xy()[0] = std::stoi(tokens[1]);
        db().bottom_die().start_xy()[1] = std::stoi(tokens[2]);
        db().bottom_die().row_lh()[0] = std::stoi(tokens[3]);
        db().bottom_die().row_lh()[1] = std::stoi(tokens[4]);
        db().bottom_die().repeat() = std::stoi(tokens[5]);
      } else if (tokens[0] == "TopDieTech") {
        db().top_die().set_tech(tokens[1]);
      } else if (tokens[0] == "BottomDieTech") {
        db().bottom_die().set_tech(tokens[1]);
      } else if (tokens[0] == "TerminalSize") {
        db().terminal().set_size(std::stoi(tokens[1]), std::stoi(tokens[2]));
      } else if (tokens[0] == "TerminalSpacing") {
        db().terminal().set_spacing(std::stoi(tokens[1]));
      } else if (tokens[0] == "TerminalCost") {
        db().terminal().set_cost(std::stoi(tokens[1]));
      } else if (tokens[0] == "Inst") {
        db().cell2lib().emplace(tokens[1], tokens[2]);
      } else if (tokens[0] == "Net") {
        net_name = tokens[1];
        db().get_nets().emplace(net_name, net);
      } else if (tokens[0] == "Pin" && tokens[1].find('/')) {
        std::vector<std::string> token_slash = split_(tokens[1], '/');
        db().get_nets().find(net_name)->second.net().emplace(token_slash[0], token_slash[1]);
      }
    }
  }
}
std::vector<std::string> ContestParser::split_(const std::string &str, char delimiter) {
  std::vector<std::string> tokens;
  std::string token;
  std::istringstream tokenStream(str);
  while (getline(tokenStream, token, delimiter)) {
    tokens.push_back(token);
  }
  return tokens;
}

