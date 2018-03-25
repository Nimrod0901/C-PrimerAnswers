#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using std::cout; using std::vector; using std::endl; using std::string;

int main() {
	vector<string> v = { "aaaaaaaaa", "aaaaaaa", "aaaaaaaaa", "aaaaaaaaa", "bbbbaa", "aa", "bbbbbbbbbbbb" };
	auto count  = count_if(v.cbegin(), v.cend(), [](const string s){ return s.size() >= 6;});
	cout << count << endl;
	return 0;
}