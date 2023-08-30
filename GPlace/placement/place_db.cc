#include "place_db.h"

void PlaceDB::init(const HierarchyDB &db) {
  this->top_die() = db.top_die();
  this->bottom_die() = db.bottom_die();
}

