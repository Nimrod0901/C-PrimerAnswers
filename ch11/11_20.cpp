#include <map>
#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;
using std::map;
using std::cin;
using std::size_t;

int main() {
	map<string, size_t> word_count;
	string w;
	for(string w; cin >> w; ){
		auto ret = word_count.insert({w, 1});//ret is std::pair<std::map<std::string, size_t>::iterator, bool>
		if(!ret.second)
			++ret.first->second;
	}
	for(const auto &w : word_count) {
		cout << w.first << " occurs " << w.second << ((w.second > 1) ? " times" : " time") << endl;
	}
	return 0;
}