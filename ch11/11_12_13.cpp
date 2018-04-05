#include <iostream>
#include <vector>
#include <string>
#include <utility>

using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::pair;

int main() {
	vector<pair<string, int>>v;
	string str;
	int count;
	while(cin >> str >> count)
		v.push_back(make_pair(str, count));
		//v.push_back(pair<string, int>(str, count));
		//v.push_back((str, count));
		//v.emplace_back(str, count);
	for(auto & w : v)
		cout << w.first << " " << w.second << endl;
	return 0;
}
