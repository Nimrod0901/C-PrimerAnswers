#include <vector>
#include <algorithm>
#include <iostream>
#include <list>

int main() {
	std::vector<int> v = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	std::list<int> lst1, lst2, lst3;
	std::copy(v.begin(), v.end(), inserter(lst1, lst1.begin()));
	std::cout << "lst1: ";
	for(auto i : lst1)
		std::cout << i << " ";//123456789
	std::cout << std::endl;
	std::copy(v.begin(), v.end(), back_inserter(lst2));
	std::cout << "lst2: ";
	for(auto i : lst2)
		std::cout << i << " ";//123456789
	std::cout << std::endl;
	std::copy(v.begin(), v.end(), front_inserter(lst3));
	std::cout << "lst3: ";
	for(auto i : lst3)
		std::cout << i << " ";//987654321
	std::cout << std::endl;
	return 0;
}