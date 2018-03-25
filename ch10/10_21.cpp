#include <iostream>

using std::cout; using std::endl;

int main() {
	int x = 9;
	auto f = [&x]() -> bool { return(x == 0) ? true : !(x--); };
	while(!f())
		cout << x << endl;
	return 0;
}