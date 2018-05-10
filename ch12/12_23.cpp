/*
 * @Author: Nimrod 
 * @Date: 2018-05-10 22:08:26 
 */

#include <iostream>
#include <string>
#include <cstring>
#include <memory>
#include <sstream>

using std::string;

int main() {
    const char* c1 = "Hello";
    const char* c2 = "World!";
    auto len = strlen(c1) + strlen(c2) - 1;
    char *c = new char[len]();
    strcpy(c, c1);
    strcat(c, c2);
    std::cout << c << std::endl;

    string s1 = "Fuck";
    string s2 = "it!";
    strcpy(c, (s1 + s2).c_str());    
    std::cout << c << std::endl;
    delete[] c;
    return 0;
}