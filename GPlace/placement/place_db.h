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

};


#endif //GDUTPLACER_DATABASE_PLACE_DB_H_
