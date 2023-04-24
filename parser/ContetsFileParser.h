//
// Created by eric on 4/18/23.
//

#include "ContestFileDataBase.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>

namespace file_parser {
    class Parser {
    public:
        explicit Parser(const std::string &filename): file_(filename) {
            std::cout << "\nOpen file: " << filename << std::endl;
        }

        void get_lib_info();

        void get_constraint_info();

        void get_inst_info();

        static std::vector <std::string> split(const std::string &str, char delimiter) {
            std::vector <std::string> tokens;
            std::string token;
            std::istringstream tokenStream(str);
            while (getline(tokenStream, token, delimiter)) {
                tokens.push_back(token);
            }
            return tokens;
        }

        void display();


    private:
        std::ifstream file_;
        ContestFileDataBase::Lib lib_{};
        ContestFileDataBase::Constraint constraint_{};
        ContestFileDataBase::Instance instance_{};
    };
}
