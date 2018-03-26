#include <vector>
#include <list>
#include <iostream>

int main() {
	std::vector<int> v = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	std::list<int> lst(v.rbegin() + 2, v.rend() - 3);
	//      0, 1, 2, [3, 4, 5, 6, 7], 8, 9
	//     ^          ^           ^      ^ 
	//     rend       ^           ^      rbegin
	//                rend - 3    rebgin + 2
	for( auto i : lst)
		std::cout << i << " ";
	std::cout << std::endl;
	return 0;
}