#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <iostream>
#include <istream>
#include <ostream>
#include <string>

using std::istream;
using std::ostream;

class Sales_data {
    friend ostream &operator<<(ostream &os, Sales_data item);
	friend Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs);

public:
    Sales_data(const std::string &s, unsigned n, double p)
        : bookNo(s), units_sold(n), revenue(n * p) {}
    Sales_data() : Sales_data("", 0, 0) {}
    Sales_data(std::string s) : Sales_data(s, 0, 0) {}

    std::string isbn() const { return bookNo; };

	Sales_data operator+=(const Sales_data &rhs) {
		units_sold += rhs.units_sold;
		revenue +=rhs.revenue;
		return *this;
	}



private:
    std::string bookNo;
    unsigned units_sold;
    double revenue;
};

ostream &operator<<(ostream &os, Sales_data item) {
    os << item.revenue;
    return os;
}

Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs) {
	Sales_data sum = lhs;
	sum += rhs;
	return sum;
}

bool compareIsbn(Sales_data s1, Sales_data s2) {
    return s1.isbn().size() < s2.isbn().size();
}

#endif
