/*
 * @Author: Nimrod
 * @Date: 2018-04-27 20:48:57
 */
#ifndef BULK_H
#define BULK_H

#include <string>
#include "15_03.h"

class Bulk_quote : public Quote {
public:
    Bulk_quote() = default;
    Bulk_quote(const std::string &book, double p, std::size_t qty, double disc)
        : Quote(book, p), min_qty(qty), discount(disc) {}
    double net_price(std::size_t) const override;
    ~Bulk_quote() = default;

private:
    std::size_t min_qty = 0;
    double discount = 0.0;
};

double Bulk_quote::net_price(std::size_t cnt) const {
    if (cnt >= min_qty)
        return cnt * (1 - discount) * price;
    else
        return cnt * price;
}
#endif // BULK_H