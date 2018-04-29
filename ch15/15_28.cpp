/*
 * @Author: Nimrod
 * @Date: 2018-04-28 23:21:22
 */
#include <iostream>
#include <memory>
#include <vector>
#include "15_15.h"

int main() {
    std::vector<std::shared_ptr<Quote>> basket;
    basket.push_back(std::make_shared<Bulk_quote>("i am Bob", 100, 50, 0.6));
    basket.push_back(std::make_shared<Bulk_quote>("i am Bob", 60, 15, 0.8));
    double sum = 0;
    for (auto v : basket) {
        sum += v->net_price(30);
    }
    std::cout << sum << std::endl;
    return 0;
}