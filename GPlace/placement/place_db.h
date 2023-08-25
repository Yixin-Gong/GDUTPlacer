#ifndef GDUTPLACER_DATABASE_PLACE_DB_H_
#define GDUTPLACER_DATABASE_PLACE_DB_H_

#include <iostream>
#include <vector>
#include <unordered_map>
#include "database/terminal.h"
#include "database/technology.h"
#include "database/die.h"
#include "database/net.h"
class PlaceDB {
 public:
  PlaceDB()=default;
  void init();
  void write_db();
 private:
  Die top_die_{};
  Die bottom_die_{};
  Terminal terminal_{};
  std::unordered_map<std::string, Net> nets_{};
  std::unordered_map<std::string, Technology> tech_lib_{};
};


#endif //GDUTPLACER_DATABASE_PLACE_DB_H_
