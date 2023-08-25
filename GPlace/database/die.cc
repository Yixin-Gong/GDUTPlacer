//
// Created by eric on 23-8-25.
//

#include "die.h"
void Die::set_size(const int32_t &xl, const int32_t &xh, const int32_t &yl, const int32_t &yh) {
  this->xl_ = xl;
  this->xh_ = xh;
  this->yl_ = yl;
  this->yh_ = yh;
}

void Die::set_row(const int32_t &start_x,
                  const int32_t &start_y,
                  const int32_t &row_l,
                  const int32_t &row_h,
                  const int32_t &repeat) {
  this->start_xy_[0] = start_x;
  this->start_xy_[1] = start_y;
  this->row_lh_[0] = row_l;
  this->row_lh_[1] = row_h;
  this->repeat_count_ = repeat;
}
void Die::set_util(const int32_t &util) {
  this->max_util_ = util;
}
void Die::set_tech(const std::string &tech) {
  this->tech_name_ = tech;
}
