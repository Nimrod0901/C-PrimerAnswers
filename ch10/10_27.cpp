#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <list>

int main() {
	std::vector<int> v = { 1, 2, 4, 4, 9, 6, 9, 1 };
	std::list<int> lst;
	std::sort(v.begin(), v.end());//must be sorted before using unique_copy
	std::unique_copy(v.cbegin(), v.cend(), back_inserter(lst));
	for(auto i : lst)
		std::cout << i << std::endl;
	return 0;
}