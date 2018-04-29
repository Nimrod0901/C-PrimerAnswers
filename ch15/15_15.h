/*
 * @Author: Nimrod
 * @Date: 2018-04-27 21:11:34
 */
#ifndef EX15_15_H
#define EX15_15_H

#include "15_03.h"

class Disc_quote : public Quote {
public:
    Disc_quote() = default;
    Disc_quote(const std::string &b, double p, std::size_t q, double d)
        : Quote(b, p), quantity(q), discount(d) {}
    virtual double net_price(std::size_t cnt) const = 0;
    ~Disc_quote() = default;

protected:
    std::size_t quantity = 0;
    double discount = 0.0;
};

class Bulk_quote : public Disc_quote {
public:
    Bulk_quote() = default;
    Bulk_quote(const std::string &b, double p, std::size_t q, double disc)
        : Disc_quote(b, p, q, disc) {}
    double net_price(std::size_t cnt) const override {
        return (cnt > quantity ? (1 - discount) : 1) * price * cnt;
    }
    ~Bulk_quote() = default;
};

#endif  // EX15_15_H
