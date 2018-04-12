#include <iostream>
#include <vector>

struct X {
	X() {std::cout << "X()" << std::endl;}
	X(const X&) {std::cout << "X(const X&)" << std::endl;}
	X& operator=(const X&) {std::cout << "X& operator=(const X&)" << std::endl; return *this;}
	~X() {std::cout << "~X()" << std::endl;}
};

std::vector<X> f(const X &rx, X x) {
    std::vector<X> vec;
    vec.reserve(2);
    vec.push_back(rx);
    //vec.push_back(x);
    return vec;
}

int main() {
	 X *px = new X;
	 std::vector<X> v = f(*px, *px);
	 delete px;

	 return 0;
}