#ifndef VIOLET_GPLACE_PARSER_CONTEST_FILE_PARSER_H_
#define VIOLET_GPLACE_PARSER_CONTEST_FILE_PARSER_H_

#include <fstream>
#include <iostream>
#include <vector>
#include "database/hierarchy_db.h"
class ContestParser {
 public:
  ContestParser(const std::string &filename, HierarchyDB &db)
      : db_(db), file_(filename), filename_(filename) {}

  void parse();

  const HierarchyDB &db() const { return db_; }
  HierarchyDB &db() { return db_; }
 private:
  std::ifstream file_;
  std::string filename_;
  HierarchyDB &db_;
  static std::vector<std::string> split_(const std::string &str, char delimiter);
};

#endif // VIOLET_GPLACE_PARSER_CONTEST_FILE_PARSER_H_