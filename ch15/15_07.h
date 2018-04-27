/*
 * @Author: Nimrod
 * @Date: 2018-04-27 20:49:01
 */
#ifndef LIMIT_QUOTE_H
#define LIMIT_QUOTE_H

#include "15_03.h"

class Limit_quote : public Quote {
   public:
    Limit_quote();
    Limit_quote(const std::string &book, double p, std::size_t qty, double disc)
        : Quote(book, p), min_qty(qty), discount(disc) {}
    double net_price(std::size_t) const override;
    ~Limit_quote();

   private:
    std::size_t min_qty = 0;
    double discount = 0.0;
};

double Limit_quote::net_price(std::size_t cnt) const {
    if (cnt < min_qty)
        return cnt * (1 - discount) * price;
    else
        return min_qty * price * (1 - discount) + (cnt - min_qty) * price;
}

#endif // LIMIT_QUOTE_H