#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <utility>

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::map;
using std::cin;
using std::pair;
using Birthdate = pair<string, string>;
using Family = map<string, vector<Birthdate>>                  ;

Family input_family() {
	Family family;
	for(string first_name; cout << "First name" <<  endl, cin >> first_name && first_name != "#q"; )
		for(string child_name, child_birthdate; 
			cout << "Children name" << endl, 
			cin >> child_name, 
			cout << "Children birthday" << endl, 
			cin >> child_birthdate ;)
			family[first_name].push_back(make_pair(child_name, child_birthdate));
	return family;
}

void print_family(Family const& family) { 
	for(auto &p : family) {
		cout << p.first << endl;
		for(auto &ch : p.second)
			cout << ch.first << " " << ch.second << endl;
		cout << endl;
	}
}


int main() {
	print_family(input_family());
	return 0;

}