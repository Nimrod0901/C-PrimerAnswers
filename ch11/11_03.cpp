#include <map>
#include <string>
#include <iostream>

using std::string; using std::cout; using std::endl; using std::map; using std::cin; using std::size_t;


int main() {
	map<string, size_t> word_count;
	string w;
	for(string w; cin >> w; ++word_count[w]);
	for(const auto &w : word_count) {
		cout << w.first << " occurs " << w.second << ((w.second > 1) ? " times" : " time") << endl;
	}
	return 0;
}