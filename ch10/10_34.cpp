#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>

int main() {
	std::vector<int> v = { 1, 2, 3, 4, 5, 6, 7};
	for(auto it = v.rbegin(); it != v.rend(); it++) {
		std::cout << *it << std::endl;
	}
	return 0;
}