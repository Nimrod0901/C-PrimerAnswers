#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using std::cout; using std::endl; using std::vector; using std::string;

bool isShorter(const string &s1, const string &s2) {
	return s1.size() < s2.size();
}

void elimDups(vector<string> &v) {
	sort(v.begin(), v.end());
	auto end_unique = unique(v.begin(), v.end());
	v.erase(end_unique, v.end());
}

int main() {
	vector<string> words = { "c", "cd", "aaa", "b", "aaa", "hhp" };
	elimDups(words);
	stable_sort(words.begin(), words.end(), isShorter);
	for(auto &i : words) 
		cout << i << " ";
	cout << endl;
	return 0;
}