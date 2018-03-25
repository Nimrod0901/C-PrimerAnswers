#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using std::string;using std::cout; using std::endl; using std::vector;
using namespace std::placeholders;

bool isLongerThanOrEqualTo6(const string &s, string::size_type sz) {
    return s.size() >= sz;
}

int main() {
	vector<string> v = { "aaaaaaaaa", "aaaaaaa", "aaaaaaaaa", "aaaaaaaaa", "bbbbaa", "aa", "bbbbbbbbbbbb" };
    auto count = count_if(v.cbegin(), v.cend(), bind(isLongerThanOrEqualTo6, _1, 6));
    cout << count << endl;
    return 0;
}