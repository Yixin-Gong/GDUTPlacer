//
// Created by eric on 4/18/23.
//

#ifndef ICCAD_CONTEST_2023_PROBLEMB_CONTESTFILEDATABASE_H
#define ICCAD_CONTEST_2023_PROBLEMB_CONTESTFILEDATABASE_H


#include <string>
#include <utility>
#include <unordered_map>
#include <vector>

namespace file_parser {
    class ContestFileDataBase {
    public:
        struct Pin {
            std::string name;
            int32_t location[2]{};
            int32_t offset[2]{};
        };
        struct LibCell {
            int32_t is_macro{};
            std::string name;
            int32_t size[2]{};
            int32_t count{};
            std::unordered_map<std::string, Pin> lib_pin{};
        };
        struct Tech {
            int32_t cell_count{};
            std::string name;
            std::unordered_map<std::string, LibCell> lib_cell{};
        };

        struct Lib{
            int32_t tech_count;
            std::unordered_map<std::string, Tech> lib_tech{};
        };
        struct DieRow {
            int32_t start_xy[2]{};   ///< x, y
            int32_t length{};      ///< row length
            int32_t height{};      ///< row height
            int32_t repeat_count{}; ///< repeat count
        };
        struct Constraint {
            int32_t size[4]{};
            double top_util{};
            double bottom_util{};
            DieRow top_row{};
            DieRow bottom_row{};
            std::string top_tech;
            std::string bottom_tech;
            int32_t t_size[2]{};
            int32_t t_spacing{};
            int32_t t_cost{};
        };
        struct InstCell {
            std::string name;
            std::string lib_name;
        };
        struct InstPin {
            std::string lib_cell_name;
            std::string pin_name;
        };
        struct Net {
            std::string name;
            int32_t num{};
            std::vector<InstPin> v_inst_pin{};
        };
        struct Instance {
            int32_t inst_count{};
            int32_t net_count{};
            std::vector<InstCell> v_inst{};
            std::vector<Net> v_net{};
        };

    public:
        void get_pin_offset();
    };
}


#endif //ICCAD_CONTEST_2023_PROBLEMB_CONTESTFILEDATABASE_H
