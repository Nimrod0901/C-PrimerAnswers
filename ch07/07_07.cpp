#include <iostream>
#include "07_06.h"

using std::cin;
using std::cout;
using std::endl;

int main() {
    Sales_data total;
    if (read(cin, total)) {
        Sales_data trans;
        while (read(cin, trans)) {
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
