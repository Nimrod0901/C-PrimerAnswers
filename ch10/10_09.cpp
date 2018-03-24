#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using std::cout; using std::endl; using std::vector; using std::string;



void elimDups(vector<string> &v) {
	sort(v.begin(), v.end());
	auto end_unique = unique(v.begin(), v.end());
	v.erase(end_unique, v.end());
}

int main() {
	vector<string> words = { "c", "cd", "aaa", "b", "aaa", "hhp" };
	elimDups(words);
	for(auto &i : words) 
		cout << i << " ";
	cout << endl;
	return 0;
}