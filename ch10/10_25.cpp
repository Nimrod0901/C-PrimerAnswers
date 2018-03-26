#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <functional>

using std::cout; using std::endl; using std::string; using std::vector;
using namespace std::placeholders;

void elimDups(vector<string> &v) {
	sort(v.begin(), v.end());
	auto end_unique = unique(v.begin(), v.end());
	v.erase(end_unique, v.end());
}

bool check_size(const string &s, string::size_type sz) {
	return s.size() >= sz;
}

void biggies(vector<string> &v, string::size_type sz) {
	elimDups(v);
	auto result = std::stable_partition(v.begin(), v.end(), bind(check_size, _1, sz));
	for_each(v.begin(), result, [](const string s){cout << s << " ";});
	cout << endl;
}

int main() {
	vector<string> v = { "aaaaaaaaa", "aaaaaaa", "aaaaaaaaa", "aaaaaaaaa", "bbbbaa", "aa", "bbbbbbbbbbbb" };
	biggies(v, 4);
	return 0;
}