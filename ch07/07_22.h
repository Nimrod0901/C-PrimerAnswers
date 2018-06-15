#ifndef PERSON_H
#define PERSON_H

#include <istream>
#include <ostream>
#include <string>

using std::string;
using std::ostream;
using std::istream;

class Person {
    friend istream& read(istream&, Person&);
    friend ostream& print(ostream&, Person&);

private:
    string name;
    string address;

public:
    string getName const() { return name; }
    string getAddress const() { return address; }
};

istream& read(istream& is, Person& p) {
    is >> p.name >> p.address;
    return is;
}
ostream& print(ostream& os, const Person& p) {
    os << p.name << " " << p.address << std::endl;
    return os;
}

#endif
