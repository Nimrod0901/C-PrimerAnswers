/*
 * @Author: Nimrod 
 * @Date: 2018-04-27 21:11:29 
 */
#include "15_15.h"

class Limit_quote : public Disc_quote {
public:
  Limit_quote() = default;
  Limit_quote(const std::string &b, double p, std::size_t max, double disc)
      : Disc_quote(b, p, max, disc) {}
  double net_price(std::size_t cnt) const override {
    if (cnt < quantity)
      return cnt * (1 - discount) * price;
    else
      return quantity * price * (1 - discount) + (cnt - quantity) * price;
  }
}