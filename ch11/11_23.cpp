#include <iostream>
#include <map>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::multimap;
using std::cin;
using Firstname = string;
using Lastname = string;
using Family = multimap<Firstname, Lastname>;

Family input_family() {
	Family family;
	for(string first_name, last_name; cin >> first_name >> last_name; family.emplace(first_name, last_name));
	return family;
}

void print_family(Family const& family) { 
	for(auto &p : family) {
		cout << p.first << endl;
		for(auto &ch : p.second)
			cout << ch << " ";
		cout << endl;
	}
}

int main() {
	print_family(input_family());
	return 0;
}