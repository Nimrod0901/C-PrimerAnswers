#include "13_31.h"
#include <vector>
#include <algorithm>

int main() {
	HasPtr h1("c"), h2("b"), h3("a");
	std::vector<HasPtr> v = { h1, h2, h3 };
	std::sort(v.begin(), v.end());
	for(auto &elem : v)
		elem.show();
	return 0;
}