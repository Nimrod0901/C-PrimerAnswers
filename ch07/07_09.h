#ifndef PERSON
#define PERSON
#include <string>
#include <ostream>
#include <istream>

using std::string;
using std::ostream;
using std::istream;

class Person {
private:
    string name;
    string address;

public:
    string getName const() { return name; }
    string getAddress const() { return address; }
};

istream& read(istream& is, Person &p) {
	is >> p.name >> p.address;
	return is;
}
ostream& print(ostream& os, const Person &p) {
	os << p.name << " " << p.address << std::endl;
	return os;
}

#endif
