/*
 * @Author: Nimrod
 * @Date: 2018-04-29 14:01:43
 */
#ifndef QUOTE_H
#define QUOTE_H

#include <string>

class Quote {
public:
    Quote() = default;
    Quote(const std::string& book, double sale_price)
        : bookNo(book), price(sale_price) {}
    std::string isbn() const { return bookNo; }
    virtual double net_price(std::size_t n) const { return n * price; }
    virtual Quote* clone() const& { return new Quote(*this); }
    virtual Quote* clone() && { return new Quote(std::move(*this)); }
    virtual ~Quote() = default;

private:
    std::string bookNo;

protected:
    double price = 0.0;
};

class Disc_quote : public Quote {
public:
    Disc_quote() = default;
    Disc_quote(const std::string& b, double p, std::size_t q, double d)
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
    Bulk_quote(const std::string& b, double p, std::size_t q, double disc)
        : Disc_quote(b, p, q, disc) {}
    double net_price(std::size_t cnt) const override {
        return (cnt > quantity ? (1 - discount) : 1) * price * cnt;
    }
    Bulk_quote* clone() const& { return new Bulk_quote(*this); }
    Bulk_quote* clone() && { return new Bulk_quote(std::move(*this)); }
    ~Bulk_quote() = default;
};

#endif