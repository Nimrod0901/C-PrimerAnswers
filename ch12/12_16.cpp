/*
 * @Author: Nimrod 
 * @Date: 2018-05-03 22:46:46 
 */
#include <memory>
#include <iostream>

int main() {
    std::unique_ptr<int> p(new int(10));
    std::unique_ptr<int> p2 = p;
    std::cout << *p << std::endl;
    return 0;
}