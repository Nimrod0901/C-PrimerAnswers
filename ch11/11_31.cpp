#include <iostream>
#include <map>
#include <string>

using Author = std::string;
using Work = std::string;
using Record = std::multimap<Author, Work>;

int main() {
	Record record = {
		{ "Nimrod", "Ch1" },
		{ "Nimrod", "Ch2" },
		{ "Nimrod", "Ch3" },
		{ "Hoooo", "hooo1"}
	};
	for(std::string search_author; std::cin >> search_author; )
		record.erase(search_author);
	for(auto &w : record)
		std::cout << w.first << " " << w.second << std::endl;
	std::cout << std::endl;
	return 0;
}