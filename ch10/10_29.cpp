#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <fstream>
using std::vector; using std::string;

int main() {
	std::ifstream in("input.txt");
	std::istream_iterator<string> in_iter(in), eof;
	vector<string> v(in_iter, eof);
	for(auto i : v)
		std::cout << i << std::endl;
	return 0;
}