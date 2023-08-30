#ifndef VIOLET_DATABASE_PLACE_DB_H_
#define VIOLET_DATABASE_PLACE_DB_H_

#include <iostream>
#include <vector>
#include <unordered_map>
#include <torch/torch.h>
#include "database/hierarchy_db.h"
class PlaceDB : torch::nn::Module {
 public:
  PlaceDB(const HierarchyDB &db) {
    init(db);
  };
  void init(const HierarchyDB &db);
 TORCH_ARG(Die, top_die);
 TORCH_ARG(Die, bottom_die);
 TORCH_ARG(Terminal, termianl);

};

#endif //VIOLET_DATABASE_PLACE_DB_H_
