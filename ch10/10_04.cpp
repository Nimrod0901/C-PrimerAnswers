#include <iostream>
#include <numeric>
#include <vector>

int main() {
	std::vector<double> v = { 3.1, 9.2, 2.3 };
	double sum = accumulate(v.cbegin(), v.cend(), 0.0);
	//std::accumulate is a template function
	//When the third parametor is initialized, the template is specified.
	std::cout << "sum:" 
			  << sum 
			  << std::endl;
	return 0;
}