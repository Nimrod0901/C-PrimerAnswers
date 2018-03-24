#include <vector>
#include <algorithm>
#include <iostream>

int main() {
	std::vector<int> v = { 1, 2, 3, 4, 5 };
	std::fill_n(v.begin(), v.size(), 0);

	for(auto i : v) 
		std::cout << i << ", ";
	std::cout << std::endl;
	return 0;
}