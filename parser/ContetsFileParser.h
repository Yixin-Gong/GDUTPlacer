//
// Created by eric on 4/18/23.
//

#include "ContestFileDataBase.h"

namespace ContestFileParser {
    class Parser {
    public:
        explicit Parser(string &filename) {
            static char file_buffer[1024 * 1024 * 128] = {0};
            fp_ = fopen(filename.c_str(), "r");
            std::cout << "\nOpen file: " << filename << std::endl;
            setbuffer(fp_, file_buffer, sizeof(file_buffer));
        }

        ~Parser() {
            fclose(fp_);
            lib_.clear();
        }

        void getTechInfo();

        void getLibCellInfo();

        void getPinInfo();

        void getDieInfo();

        void getTerminalInfo();

        void getInstInfo();

        void getInstCellInfo();

        void getInstNetInfo();

        void getNetPinInfo();

    private:
        FILE *fp_;
        ContestFileDataBase::Pin lib_pin_;
        ContestFileDataBase::LibCell lib_cell_;
        ContestFileDataBase::Tech tech_info_;
        std::unordered_map<string, ContestFileDataBase::Tech> lib_;

        ContestFileDataBase::DieRow die_row_;
        ContestFileDataBase::Die die_;
        ContestFileDataBase::Terminal terminal_;

        ContestFileDataBase::InstCell inst_cell_;
        ContestFileDataBase::InstPin inst_pin_;
        ContestFileDataBase::Net net_;
        ContestFileDataBase::Instance instance_;
    };
}