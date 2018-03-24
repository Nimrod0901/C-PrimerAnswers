#include <iostream>
#include <algorithm>
#include <string>
#include <list>

int main() {
	std::list<std::string> l = { "1" , "11", "222" , "1", "1", "1" };
	std::cout << std::count(l.cbegin(), l.cend(), "1") << std::endl;
	return 0;
}