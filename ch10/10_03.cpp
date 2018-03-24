#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

int main() {
	std::vector<int> v = { 1, 2, 3, 4, 5, 6, 6, 6, 2 };
	auto sum = accumulate(v.cbegin(), v.cend(), 0);
	std::cout << "sum:" << sum << std::endl;
	return 0;
}	