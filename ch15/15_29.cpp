/*
 * @Author: Nimrod 
 * @Date: 2018-04-28 23:59:02 
 */
#include <iostream>
#include <memory>
#include <vector>
#include "15_15.h"

int main() {
    std::vector<std::shared_ptr<Quote>> basket;
    basket.push_back(std::make_shared<Quote>("i am Bob", 100));
    basket.push_back(std::make_shared<Quote>("i am Bob", 60));
    double sum = 0;
    for (auto v : basket) {
        sum += v->net_price(30);
    }
    std::cout << sum << std::endl;
    return 0;
}