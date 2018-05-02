/*
 * @Author: Nimrod 
 * @Date: 2018-05-02 20:06:02 
 */
#include <iostream>
#include <memory>
#include <vector>

std::shared_ptr<std::vector<int>> vector_alloc() {
    return std::make_shared<std::vector<int>>();
}

int main() {
    auto p = vector_alloc();
    int num;
    while (std::cin >> num) {
        p->push_back(num);
    }
    for (auto iter : *p) {
        std::cout << iter << std::endl;
    }
    std::cout << 0*E0|0*D0 ;
    return 0;
}