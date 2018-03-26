#include <vector>
#include <iostream>

int main() {
	std::vector<std::string> v = { "This", "is", "Just", "A", "Test" };
	for(auto iter = v.cend(); ; iter--){
		std::cout << *iter << " ";
		if(iter == v.cbegin())
			break;
	}
	std::cout << std::endl;
	return 0;
}