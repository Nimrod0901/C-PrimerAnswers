#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <iostream>
#include <istream>
#include <ostream>
#include <string>

using std::istream;
using std::ostream;

class Sales_data {
    friend istream &read(istream &is, Sales_data &item);
    friend ostream &print(ostream &os, const Sales_data &item);
    friend Sales_data add(const Sales_data &lhs, const Sales_data &rhs);

public:
    Sales_data(const std::string &s, unsigned n, double p)
        : bookNo(s), units_sold(n), revenue(n * p) {
        std::cout << "Non-delegating Constructor" << std::endl;
    }
    Sales_data() : Sales_data("", 0, 0) {
        std::cout << "Delegating Constructor" << std::endl;
    }
    Sales_data(std::string s) : Sales_data(s, 0, 0) {
        std::cout << "Delegating Constructor" << std::endl;
    }
    Sales_data(istream &is) : Sales_data() {
        read(is, *this);
        std::cout << "Delegating Constructor" << std::endl;
    }

    std::string isbn() const { return bookNo; };
    Sales_data &combine(const Sales_data &);

private:
    std::string bookNo;
    unsigned units_sold;
    double revenue;
};

Sales_data &Sales_data::combine(const Sales_data &rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

istream &read(istream &is, Sales_data &item) {
    is >> item.bookNo >> item.units_sold >> item.revenue;
    return is;
}

ostream &print(ostream &os, const Sales_data &item) {
    os << item.bookNo << " " << item.units_sold << " " << item.revenue
       << std::endl;
    return os;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs) {
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}
#endif
