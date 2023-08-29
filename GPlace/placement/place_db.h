#ifndef VIOLET_DATABASE_PLACE_DB_H_
#define VIOLET_DATABASE_PLACE_DB_H_

#include <iostream>
#include <vector>
#include <unordered_map>
#include "database/terminal.h"
#include "database/technology.h"
#include "database/die.h"
#include "database/net.h"
#include <torch/torch.h>

class PlaceDB : torch::nn::Module{
 public:
  PlaceDB() = default;
  void init();
  void write_db();

};

#endif //VIOLET_DATABASE_PLACE_DB_H_
