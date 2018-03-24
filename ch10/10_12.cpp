#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using std::string; using std::cout; using std::endl;

class Sales_data  
{  
public:  
    Sales_data();  
    Sales_data(string s):_isbn(s) {

    }  

    string isbn() {  
        return _isbn;  
    }  
    string _isbn;  
};  

bool compareIsbn(Sales_data s1, Sales_data s2) {
	return s1.isbn().size() < s2.isbn().size();
}

int main() {
	Sales_data a("This");
	Sales_data b("is");
	Sales_data c("Just");
	Sales_data d("A");
	Sales_data e("Test");
	std::vector<Sales_data> v = { a, b, c, d, e };
	std::sort(v.begin(), v.end(), compareIsbn);
	for(auto &i : v)
		cout << i._isbn << endl;
	return 0;
}