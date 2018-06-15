#include <iostream>
#include "07_12.h"

using std::cin;
using std::cout;
using std::endl;

int main() {
    Sales_data total(cin);
    istream &is = cin;
    if (!total.isbn().empty()) {
        while (is) {
            Sales_data trans(is);
            if (total.bookNo == trans.bookNo) {
                total.combine(trans);
            } else {
                print(cout, total);
                total = trans;
            }
        }
        print(cout, total);
    } else {
        std::cerr << "No data?!" << std::endl;
        return -1;
    }
    return 0;
}
