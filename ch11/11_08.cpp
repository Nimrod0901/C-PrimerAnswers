#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::find;

int main() {
	std::vector<string> v;
	for(string word;cin >> word ;) {
		if(find(v.begin(), v.end(), word) != v.cend())
			continue;
		v.push_back(word);
	}
	for(auto &w : v)
		cout << w << " ";
	cout << endl;
	return 0;
}