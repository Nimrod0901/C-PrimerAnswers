#include <map>
#include <string>
#include <iostream>
#include <algorithm>
#include <cctype>

using std::string; using std::cout; using std::endl; using std::map; using std::cin; using std::size_t;
using std::remove_if;

int main() {
	map<string, size_t> word_count;
	string word;
	for(string word; cin >> word; ++word_count[word]){
		for (auto &ch : word)
			ch = tolower(ch);
		word.erase(remove_if(word.begin(), word.end(), ispunct), word.end());
	}

	for(const auto &word : word_count) {
		cout << word.first << " occurs " << word.second << ((word.second > 1) ? " times" : " time") << endl;
	}
	return 0;
}