#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <functional>

using std::cout; using std::endl; using std::vector; using std::string;
using std::bind; using std::size_t; using namespace std::placeholders;

bool check_size(const string &s, size_t sz) {
	return s.size() <= sz;
}

int main() {
	vector<int> v = { 0, 1, 2, 3, 4, 5 };
	string str("12345");
	auto result = find_if(v.cbegin(), v.cend(), bind(check_size, str , _1));
	if(result != v.end()) {
		cout << *result << endl;		
	} else {
		cout << "Not Found!" << endl;
	}
	return 0;
}