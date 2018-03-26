#include <list>
#include <algorithm>
#include <iostream>

int main() {
	std::list<int> lst = { 1, 2, 0, 4, 5, 6, 0, 9};
	auto pos = std::find(lst.crbegin(), lst.crend(), 0);
	std::cout << "The position is: " << std::distance(pos, lst.crend()) << std::endl;
	return 0; 
}