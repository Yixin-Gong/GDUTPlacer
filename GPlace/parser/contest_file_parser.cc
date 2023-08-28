#include "parser/contest_file_parser.h"
#include <chrono>
#include <iostream>
#include <sstream>
#include <vector>

void ContestParser::parse()
{
}

std::vector<std::string> ContestParser::split_(const std::string &str, char delimiter)
{
  std::vector<std::string> tokens;
  std::string token;
  std::istringstream tokenStream(str);
  while (getline(tokenStream, token, delimiter))
  {
    tokens.push_back(token);
  }
  return tokens;
}
