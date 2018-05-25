#ifndef 13_05_H
#define 13_05_H

#include <string>

class HasPtr {
public:
    HasPtr(const std::string &s = std::string()): ps(new std::string(s)), i(0) {}
    HasPtr(const HasPtr &arg) : ps(new std::string(*arg.ps)), i(arg.i) {}

private:
    std::string *ps;
    int i;
};


#endif // 13_05_H