#ifndef VIOLET_GPLACE_DATABASE_DIE_H_
#define VIOLET_GPLACE_DATABASE_DIE_H_

#include <iostream>
#include <array>

class Die
{
public:
  Die()
  {
    xl_ = 0;
    xh_ = 0;
    yl_ = 0;
    yh_ = 0;
    start_xy_[0] = 0;
    start_xy_[1] = 0;
    row_lh_[0] = 0;
    row_lh_[1] = 0;
    repeat_count_ = 0;
    tech_name_ = "";
  }

  void set_size(const int32_t &xl, const int32_t &xh, const int32_t &yl, const int32_t &yh);
  void set_row(const int32_t &start_x,
               const int32_t &start_y,
               const int32_t &row_l,
               const int32_t &row_h,
               const int32_t &repeat);
  void set_util(const int32_t &util);
  void set_tech(const std::string &tech);

  const int32_t xl() const { return xl_; }
  int32_t xl() { return xl_; }
  const int32_t xh() const { return xh_; }
  int32_t xh() { return xh_; }
  const int32_t yl() const { return yl_; }
  int32_t yl() { return yl_; }
  const int32_t yh() const { return yh_; }
  int32_t yh() { return yh_; }
  const int32_t get_util() const { return this->max_util_; }
  int32_t get_util() { return this->max_util_; }
  const std::array<int32_t, 2> &start_xy() const { return start_xy_; }
  std::array<int32_t, 2> &start_xy() { return start_xy_; }
  const std::array<int32_t, 2> &row_lh() const { return row_lh_; }
  std::array<int32_t, 2> &row_lh() { return row_lh_; }
  const int32_t get_repeat() const { return this->repeat_count_; }
  int32_t get_repeat() { return this->repeat_count_; }
  const std::string &get_tech() const { return this->tech_name_; }
  std::string &get_tech() { return this->tech_name_; }

private:
  int32_t xl_{};
  int32_t xh_{};
  int32_t yl_{};
  int32_t yh_{};
  int32_t max_util_{};
  std::array<int32_t, 2> start_xy_{};
  std::array<int32_t, 2> row_lh_{};
  int32_t repeat_count_{};
  std::string tech_name_{};
};

#endif // VIOLET_GPLACE_DATABASE_DIE_H_
