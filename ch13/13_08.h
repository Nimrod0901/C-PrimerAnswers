#ifndef 13_08_H
#define 13_08_H

#include <string>

class HasPtr {
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

private:
	std::string *ps;
	int i;
};


#endif // 13_08_H
