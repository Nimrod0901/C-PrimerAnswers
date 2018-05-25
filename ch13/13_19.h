#ifndef 13_19_H
#define 13_19_H

#include <string>
using std::string;

class Employee {
public:
    Employee() {
        id_ = unique++;
    }
    Employee(const string &name) {
        id_ = unique;
        name_ = name;
    }
    ~Employee() = delete;
    Employee& operator=(const Employee&) = delete;

    const int id() const {return id_};
private:
    string name_;
    int id_;
    static int unique = 0;
};


#endif // 13_19_H
