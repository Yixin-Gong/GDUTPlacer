#include "parser/contest_file_parser.h"
#include <chrono>
#include <iostream>
#include <sstream>
#include <vector>

void ContestParser::parse() {
  std::string tech_name, lib_cell_name, pin_name;
  std::string line;
  Technology technology;
  LibCell lib_cell;
  LibPin lib_pin;

  while (std::getline(file_, line)) {
    std::vector<std::string> tokens = split_(line, ' ');
    if (line.empty()) {
      continue;
    } else {
      if (tokens[0] == "Tech") {
        tech_name = tokens[1];
        technology.set_lib_cell_count(std::stoi(tokens[2]));
        db_.get_lib().emplace(tech_name, technology);
      } else if (tokens[0] == "LibCell") {
        if (tokens[1] == "Y")
          lib_cell.is_macro();
        lib_cell_name = tokens[2];
        lib_cell.set_size(std::stoi(tokens[3]), std::stoi(tokens[4]));
        lib_cell.set_pin_num(std::stoi(tokens[5]));
        technology = db_.get_lib().find(tech_name)->second;
        technology.add_lib_cell(lib_cell_name, lib_cell);
      } else if (tokens[0] == "Pin") {
        pin_name = tokens[1];
        lib_pin.set_offset(std::stoi(tokens[2]), std::stoi(tokens[3]));
        lib_cell = technology.lib_cell_map().find(lib_cell_name)->second;
        lib_cell.add_pin(pin_name, lib_pin);
      } else if (tokens[0] == "Die") {
        db_.top_die().set_size(std::stoi(tokens[1]), std::stoi(tokens[2]),
                               std::stoi(tokens[3]), std::stoi(tokens[4]));
        db_.bottom_die().set_size(std::stoi(tokens[1]), std::stoi(tokens[2]),
                                  std::stoi(tokens[3]), std::stoi(tokens[4]));
      } else if (tokens[0] == "TopDieMaxUtil") {
        db_.top_die().set_util(std::stoi(tokens[1]));
      } else if (tokens[0] == "BottomDieMaxUtil") {
        db_.bottom_die().set_util(std::stoi(tokens[1]));
      } else if (tokens[0] == "TopDieRows"){

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

