#ifndef CH13_31_H
#define CH13_31_H

#include <string>
#include <iostream>

using std::string;

class HasPtr {
    friend bool operator<(const HasPtr& hasl, const HasPtr& hasr);
    friend void swap(HasPtr&, HasPtr&);
public:
    HasPtr(const std::string &s = std::string()): ps(new std::string(s)), i(0) {}
    HasPtr(const HasPtr &arg) : ps(new std::string(*arg.ps)), i(arg.i) {}
    HasPtr& operator=(const HasPtr& arg) { 
        std::string *new_ps = new std::string(*arg.ps);
        delete ps;//necessary
        ps = new_ps;
        i = arg.i;
        return *this;
    }
    ~HasPtr() {
            delete ps;
    }
    void show() {std::cout << *ps << std::endl;}

private:
    std::string *ps;
    int i;
};

inline
void swap(HasPtr& hasl, HasPtr& hasr) {
    using std::swap;
    swap(hasl.ps, hasr.ps);
    swap(hasl.i, hasr.i);
}

bool operator<(const HasPtr &hasl, const HasPtr &hasr) {
    return *hasl.ps < *hasr.ps;
}

#endif // CH13_31_H
