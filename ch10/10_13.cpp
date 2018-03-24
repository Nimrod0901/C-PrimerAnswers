#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


bool isLonger(std::string &s) {
	return s.size() >= 5;
}

int main() {
	std::vector<std::string> v = { "aaaaaa", "aaa", "aa", "aaaaaaa", "a" };
	auto end_part = std::partition(v.begin(), v.end(), isLonger);
	for(auto it = v.begin(); it < end_part; it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	return 0;
}