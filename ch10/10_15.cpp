#include <iostream>



int main() {
	int b = 1;
	auto Sum = [b](int a) {
	return a + b;
};
	std::cout << Sum(2) << std::endl;
}