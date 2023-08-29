#ifndef VIOLET_GPLACE_DATABASE_DIE_H_
#define VIOLET_GPLACE_DATABASE_DIE_H_

#include <iostream>
#include <array>

class Die {
 public:
  Die() = default;
  void set_size(const int32_t &xl, const int32_t &yl, const int32_t &xh, const int32_t &yh);
  void set_row(const int32_t &start_x,
               const int32_t &start_y,
               const int32_t &row_l,
               const int32_t &row_h,
               const int32_t &repeat);
  void set_util(const int32_t &util);
  void set_tech(const std::string &tech);

  int32_t &get_util() { return this->max_util_; }
  std::array<int32_t, 2> &start_xy() { return start_xy_; }
  std::array<int32_t, 2> &row_lh() { return row_lh_; }
  int32_t &repeat() { return this->repeat_count_; }
  const std::string &get_tech() { return this->tech_name_; }

 private:
  std::array<int32_t, 4> size_{};
  int32_t max_util_{};
  std::array<int32_t, 2> start_xy_{};
  std::array<int32_t, 2> row_lh_{};
  int32_t repeat_count_{};
  std::string tech_name_{};
};

#endif // VIOLET_GPLACE_DATABASE_DIE_H_

