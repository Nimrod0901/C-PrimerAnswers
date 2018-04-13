#ifndef 13_18_H
#define 13_18_H

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

	const int id() const {return id_};
private:
	string name_;
	int id_;
	static int unique = 0;
}

#endif // 13_18_H
