#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <fstream> 

using std::string;
using std::map;
using std::cin;
using std::cout;
using std::endl;
using std::istringstream;
using std::ifstream;

map<string, string> buildMap(ifstream &map_file) {
	map<string, string> trans_map;
	string key;
	string value;
	while(map_file >> key && getline(map_file, value)) {
		if(value.size() > 1)
			trans_map[key] = value.substr(1);
		else
			cout << "No Rule For" << key << endl;
	}
	return trans_map;
}

const string &
transform(const string &s, const map<string, string> &m) {
	auto map_it = m.find(s);
	return map_it == m.cend() ? s : map_it->second;
}

void word_transform(ifstream &map, ifstream &input)
{
    auto trans_map = buildMap(map);
    for (string text; getline(input, text); ) {
        istringstream iss(text);
        for (string word; iss >> word; )
            cout << transform(word, trans_map) << " ";
        cout << endl;
    }
}

int main()
{
    ifstream ifs_map("..tran.txt"), ifs_content("..given_to_transform.txt");
    if (ifs_map && ifs_content) {
    	word_transform(ifs_map, ifs_content);
    } else
    std::cerr << "can't find the documents." << std::endl;
    return 0; 
}