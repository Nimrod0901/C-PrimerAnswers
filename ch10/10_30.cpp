#include <iostream>
#include <vector>
#include <iterator>
#include <vector>
#include <algorithm>

int main() {
	std::istream_iterator<int> in(std::cin), eof;
	std::vector<int> v(in, eof);
	sort(v.begin(), v.end());
	for(auto i : v)
		std::cout << i << " ";
	std::cout << std::endl;
	return 0;
}