#include "database/macro.h"

//TODO:Implement set_macro method for macro instance
void Macro::set_macro() {

}
std::array<double, 2> Macro::get_center() {
  std::array<double, 2> center{};
  center[0] = this->size_[0] * 0.5;
  center[1] = this->size_[1] * 0.5;
  return center;
}
