//
// Created by eric on 4/18/23.
//
#include <iostream>
#include "parser/ContestFileDataBase.h"
#include "parser/ContetsFileParser.h"
int main(){
    file_parser::Parser parser("/home/eric/Desktop/ICCAD-contest-2023-problemB/case1.txt");
    parser.get_lib_info();
    parser.get_constraint_info();
    parser.get_inst_info();
    parser.display();
}
