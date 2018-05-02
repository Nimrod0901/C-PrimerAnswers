/*
 * @Author: Nimrod
 * @Date: 2018-05-02 19:49:41
 */
#include <iostream>
#include <vector>

std::vector<int>* vector_alloc() { return new std::vector<int>(); }

int main() {
    auto p = vector_alloc();
    int num;
    while (std::cin >> num) {
        p->push_back(num);
    }
    for (auto iter : *p) {
        std::cout << iter << std::endl;
    }
    delete p;
    return 0;
}