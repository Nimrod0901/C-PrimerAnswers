/*
 * @Author: Nimrod
 * @Date: 2018-04-29 13:55:23
 */
#include "15_30.h"

int main() {
    Basket bsk;
    bsk.add_item(Bulk_quote("i am Bob", 100, 50, 0.6));
    bsk.add_item(Bulk_quote("i am Alice  ", 60, 15, 0.8));
    bsk.total_receipt(std::cout);
    return 0;
}