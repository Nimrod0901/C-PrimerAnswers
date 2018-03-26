#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

int main() {
	std::istream_iterator<int> in(std::cin), eof;
	std::vector<int> v(in, eof);
	sort(v.begin(), v.end());
	std::unique_copy(v.cbegin(), v.cend(), std::ostream_iterator<int>(std::cout, " "));
	return 0;
}

