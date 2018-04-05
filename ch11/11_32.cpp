#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>

using std::pair;
using Author = std::string;
using Work = std::string;
using Record = std::multimap<Author, Work>;
using Other_Record = std::vector<std::pair<Author, Work>>;

bool cmp_author(const pair<Author, Work> a, const pair<Author, Work> b) {
	return a.first.size() < b.first.size();
}

int main() {
		Record record = {
		{ "Apple", "A Happy Day" },
		{ "Pear", "A Not Happy Day" },
		{ "Nimrod", "A Half-happy Day" },
		{ "Banana", "How to Eat Myself"}
	};
	Other_Record other;
	for(auto & w : record)
		other.push_back(w);
	std::sort(other.begin(), other.end(), cmp_author);
	for(auto & w: record)
		std::cout << w.first << " " << w.second << std::endl;
	return 0;
}