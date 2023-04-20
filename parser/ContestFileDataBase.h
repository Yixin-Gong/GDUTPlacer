//
// Created by eric on 4/18/23.
//

#ifndef ICCAD_CONTEST_2023_PROBLEMB_CONTESTFILEDATABASE_H
#define ICCAD_CONTEST_2023_PROBLEMB_CONTESTFILEDATABASE_H


#include <string>
#include <utility>
#include <unordered_map>
#include <vector>

namespace ContestFileParser {
    using std::string;
    using std::vector;

    class ContestFileDataBase {
    public:
        struct Pin {
            string name;
            int32_t location[2]{};
            int32_t offset[2]{};
        };
        struct LibCell {
            bool is_macro{};
            string name;
            int32_t size[2]{};
            int32_t count{};
            std::unordered_map<string, Pin> lib_pin{};
        };
        struct Tech {
            int32_t tech_count{};
            string name;
            int32_t cell_count{};
            std::unordered_map<string, LibCell> lib_cell{};
        };
        struct DieRow {
            int32_t start_xy[2]{};   ///< x, y
            int32_t length{};      ///< row length
            int32_t height{};      ///< row height
            int32_t repeat_count{}; ///< repeat count
        };
        struct Die {
            int32_t size[4]{};
            double util{};
            DieRow row{};
            string tech;
        };
        struct Terminal {
            int32_t size[2]{};
            int32_t spacing{};
            int32_t cost{};
        };
        struct InstCell {
            string name;
            string lib_name;
        };
        struct InstPin {
            string lib_cell_name;
            string pin_name;
        };
        struct Net {
            string name;
            int32_t num{};
            vector<InstPin> v_inst_pin{};
        };
        struct Instance {
            int32_t inst_count{};
            int32_t net_count{};
            vector<InstCell> v_inst{};
            vector<Net> v_net{};
        };

    public:
        void get_pin_offset();
    };
}


#endif //ICCAD_CONTEST_2023_PROBLEMB_CONTESTFILEDATABASE_H
