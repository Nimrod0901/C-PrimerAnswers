#ifndef PERSON
#define PERSON
#include <string>

using std::string;

class Person {
private:
    string name;
    string address;

public:
    string getName const() { return name; }
    string getAddress const() { return address; }
};

#endif
