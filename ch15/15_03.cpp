#include "15_03.h"
#include <iostream>

using std::cout;

double print_double(std::ostream &os, const Quote &item, size_t n) {
	double ret = item.net_price(n);
	os << "ISBN: " << item.isbn()
	   << " # sold: " <<  n << " total due: " << ret << std::endl;
	return ret;
}

int main() {
	Quote q("i am Alice", 100);
	double ret = print_double(std::cout, q, 1);
	return 0;
}