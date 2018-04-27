/*
 * @Author: Nimrod 
 * @Date: 2018-04-27 21:11:21 
 */
#include "15_05.h"
#include <iostream>

using std::cout;

void print_double(std::ostream &os, const Quote &item, size_t n) {
  double ret = item.net_price(n);
  os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret
     << std::endl;
}

int main() {
  Quote q("i am Alice", 100);
  Bulk_quote b("i am Bob", 100, 50, 0.6);
  print_double(std::cout, q, 1);
  print_double(std::cout, b, 1);
  return 0;
}