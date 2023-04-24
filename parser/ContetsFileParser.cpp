//
// Created by eric on 4/18/23.
//

#include "ContetsFileParser.h"
#include <cstring>
#include <cstdio>

void file_parser::Parser::get_lib_info() {
    std::string tech_name, lib_cell_name, pin_name;
    std::string line;
    while (std::getline(file_, line)) {
        std::vector<std::string> tokens = split(line, ' ');
        if (line.empty()) {
            break;
        } else {
            if (tokens[0] == "NumTechnologies") {
                lib_.tech_count = std::stoi(tokens[1]);
            } else if (tokens[0] == "Tech") {
                auto *tech = new ContestFileDataBase::Tech;
                tech_name = tokens[1];
                tech->name.swap(tokens[1]);
                tech->cell_count = std::stoi(tokens[2]);
                lib_.lib_tech.insert(std::pair<std::string, struct ContestFileDataBase::Tech>(tech_name, *tech));
                delete tech;
            } else if (tokens[0] == "LibCell") {
                auto *lib_cell = new ContestFileDataBase::LibCell;
                if (tokens[1] == "N")
                    lib_cell->is_macro = 0;
                else if (tokens[1] == "Y")
                    lib_cell->is_macro = 1;
                lib_cell_name = tokens[2];
                lib_cell->name.swap(tokens[2]);
                lib_cell->size[0] = std::stoi(tokens[3]);
                lib_cell->size[1] = std::stoi(tokens[4]);
                lib_cell->count = std::stoi(tokens[5]);
                auto it = lib_.lib_tech.find(tech_name);
                it->second.lib_cell.insert(
                        std::pair<std::string, struct ContestFileDataBase::LibCell>(lib_cell_name, *lib_cell));
                delete lib_cell;
            } else if (tokens[0] == "Pin") {
                auto *pin = new ContestFileDataBase::Pin;
                pin_name = tokens[1];
                pin->name.swap(tokens[1]);
                pin->location[0] = std::stoi(tokens[2]);
                pin->location[1] = std::stoi(tokens[3]);
                auto it = lib_.lib_tech.find(tech_name)->second.lib_cell.find(lib_cell_name);
                it->second.lib_pin.insert(
                        std::pair<std::string, struct ContestFileDataBase::Pin>(pin_name, *pin));
                delete pin;
            }
        }
    }
}

void file_parser::Parser::get_constraint_info() {
    std::string line;
    while (getline(file_, line)) {
        std::vector<std::string> tokens = split(line, ' ');
        if (line.empty()) {
            continue;
        } else {
            if (tokens[0] == "DieSize") {
                constraint_.size[0] = std::stoi(tokens[1]);
                constraint_.size[1] = std::stoi(tokens[2]);
                constraint_.size[2] = std::stoi(tokens[3]);
                constraint_.size[3] = std::stoi(tokens[4]);
            } else if (tokens[0] == "TopDieMaxUtil") {
                constraint_.top_util = std::stod(tokens[1]);
            } else if (tokens[0] == "BottomDieMaxUtil") {
                constraint_.bottom_util = std::stod(tokens[1]);
            } else if (tokens[0] == "TopDieRows") {
                constraint_.top_row.start_xy[0] = std::stoi(tokens[1]);
                constraint_.top_row.start_xy[1] = std::stoi(tokens[2]);
                constraint_.top_row.length = std::stoi(tokens[3]);
                constraint_.top_row.height = std::stoi(tokens[4]);
                constraint_.top_row.repeat_count = std::stoi(tokens[5]);
            } else if (tokens[0] == "BottomDieRows") {
                constraint_.bottom_row.start_xy[0] = std::stoi(tokens[1]);
                constraint_.bottom_row.start_xy[1] = std::stoi(tokens[2]);
                constraint_.bottom_row.length = std::stoi(tokens[3]);
                constraint_.bottom_row.height = std::stoi(tokens[4]);
                constraint_.bottom_row.repeat_count = std::stoi(tokens[5]);
            } else if (tokens[0] == "TopDieTech") {
                constraint_.top_tech.swap(tokens[1]);
            } else if (tokens[0] == "BottomDieTech") {
                constraint_.bottom_tech.swap(tokens[1]);
            } else if (tokens[0] == "TerminalSize") {
                constraint_.t_size[0] = std::stoi(tokens[1]);
                constraint_.t_size[1] = std::stoi(tokens[2]);
            } else if (tokens[0] == "TerminalSpacing") {
                constraint_.t_spacing = std::stoi(tokens[1]);
            } else if (tokens[0] == "TerminalCost") {
                constraint_.t_cost = std::stoi(tokens[1]);
                break;
            }
        }
    }
}

void file_parser::Parser::get_inst_info() {
    std::string line;
    while (std::getline(file_, line)) {
        std::vector<std::string> tokens = split(line, ' ');
        if (line.empty()) {
            continue;
        } else {
            if (tokens[0] == "NumInstances") {
                instance_.inst_count = std::stoi(tokens[1]);
            } else if (tokens[0] == "Inst") {
                ContestFileDataBase::InstCell inst;
                inst.name.swap(tokens[1]);
                inst.lib_name.swap(tokens[2]);
                instance_.v_inst.push_back(inst);
            } else if (tokens[0] == "NumNets") {
                instance_.net_count = std::stoi(tokens[1]);
            } else if (tokens[0] == "Net") {
                ContestFileDataBase::Net net;
                net.name.swap(tokens[1]);
                net.num = std::stoi(tokens[2]);
                instance_.v_net.push_back(net);
            } else if (tokens[0] == "Pin") {
                std::vector<std::string> token_slash = split(tokens[1], '/');
                ContestFileDataBase::InstPin pin;
                pin.lib_cell_name = token_slash[0];
                pin.pin_name = token_slash[1];
                instance_.v_net.back().v_inst_pin.push_back(pin);
            }
        }
    }
}

void file_parser::Parser::display() {
    std::cout << "NumTechnologies: " << lib_.tech_count << "\n";
    for (auto &tech: lib_.lib_tech) {
        std::cout <<"Tech "<< tech.second.name <<' '<<tech.second.cell_count<< "\n";
        for (auto &lib_cell: tech.second.lib_cell) {
            std::cout << "LibCell: " << lib_cell.second.is_macro << ' ' << lib_cell.second.name <<
                      ' ' << lib_cell.second.size[0] << ' ' << lib_cell.second.size[1] << ' ' << lib_cell.second.count
                      << "\n";
            for (auto &pin: lib_cell.second.lib_pin) {
                std::cout << "Pin: " << pin.second.name << ' ' << pin.second.location[0] << ' '
                          << pin.second.location[1] << "\n";
            }
        }
    }
    std::cout << "\n" << "DieSize: " << constraint_.size[0] << ' ' << constraint_.size[1] << ' '
              << constraint_.size[2] << ' ' << constraint_.size[3] << "\n";
    std::cout << "\n" << "TopDieMaxUtil: " << constraint_.top_util << "\n";
    std::cout << "BottomDieMaxUtil: " << constraint_.bottom_util << "\n";
    std::cout << "\n" << "TopDieRows: " << constraint_.top_row.start_xy[0] << ' ' << constraint_.top_row.start_xy[1]
              << ' ' <<
              ' ' << constraint_.top_row.length << ' ' << constraint_.top_row.height << ' '
              << constraint_.top_row.repeat_count << "\n";
    std::cout << "BottomDieRows: " << constraint_.bottom_row.start_xy[0] << ' ' << constraint_.bottom_row.start_xy[1]
              << ' ' <<
              ' ' << constraint_.bottom_row.length << ' ' << constraint_.bottom_row.height << ' '
              << constraint_.bottom_row.repeat_count << "\n";
    std::cout << "\n" << "TopDieTech: " << constraint_.top_tech << "\n";
    std::cout << "BottomDieTech: " << constraint_.bottom_tech << "\n";
    std::cout << "\n" << "TerminalSize: " << constraint_.t_size[0] << ' ' << constraint_.t_size[1] << "\n";
    std::cout << "TerminalSpacing: " << constraint_.t_spacing << "\n";
    std::cout << "TerminalCost: " << constraint_.t_cost << "\n";

    std::cout << "\n" << "NumInstances: " << instance_.inst_count << "\n";
    for (auto &inst: instance_.v_inst) {
        std::cout << "Inst: " << inst.name << ' ' << inst.lib_name << "\n";
    }

    std::cout << "\n" << "NumNets: " << instance_.net_count << "\n";
    for (auto &net: instance_.v_net) {
        std::cout << "Net: " << net.name << ' ' << net.num << "\n";
        for (auto &pin: net.v_inst_pin) {
            std::cout << "Pin " << pin.lib_cell_name << '/' << pin.pin_name << "\n";
        }
    }

}

