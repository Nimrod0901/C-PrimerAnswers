/*
 * @Author: Nimrod
 * @Date: 2018-05-02 19:11:12
 */
#include "12_02.h"
#include <iostream>

int main() {
    StrBlob b = {"a", "an", "the"};
    std::cout << b.front() << std::endl;
    std::cout << b.back() << std::endl;
    b.push_back("aaa");
    b.pop_back();
    b.pop_back();    
    std::cout << b.size() << std::endl;
    return 0;
}