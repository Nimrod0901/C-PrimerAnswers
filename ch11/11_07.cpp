#include <iostream>
#include <map>
#include <vector>
#include <string>

using std::cout; using std::endl; using std::vector; using std::string; using std::map; using std::cin;
using Family = map<string, vector<string>>;

Family input_family() {
	Family family;
	for(string first_name; cout << "First name" <<  endl, cin >> first_name && first_name != "#q"; )
		for(string child_name; cout << "Children name" << endl, cin >> child_name && child_name != "#q";)
			family[first_name].push_back(child_name);
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