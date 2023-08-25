#ifndef VIOLET_GPLACE_DATABASE_LIB_PIN_H_
#define VIOLET_GPLACE_DATABASE_LIB_PIN_H_

#include <iostream>
#include <array>

class LibPin {
 public:
  LibPin() {
    offset_[0] = 0;
    offset_[1] = 0;
  }

  void set_offset(const int32_t &x,const int32_t &y);

 protected:
  std::array<int32_t, 2> offset_{};
};

#endif //VIOLET_GPLACE_DATABASE_LIB_PIN_H_