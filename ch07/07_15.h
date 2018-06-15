#ifndef PERSON_H
#define PERSON_H
#include <istream>
#include <ostream>
#include <string>

using std::string;
using std::ostream;
using std::istream;

struct Person;
istream& read(istream& is, Person& p);

struct Person {
    string name;
    string address;

    Person() = default;
    Person(const string& name, const string& address)
        : name(name), address(address) {}
    Person(istream& is) { read(is, *this); }
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
