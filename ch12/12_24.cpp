/*
 * @Author: Nimrod 
 * @Date: 2018-05-10 22:44:46 
 */
#include <iostream>

int main() {
    unsigned int size(10);
    char* c = new char[size]();
    std::cin.get(c, size);
    std::cout << c << std::endl;
    return 0;
}