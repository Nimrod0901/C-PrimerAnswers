#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>
#include "salesdata.h"

using std::vector;

typedef std::tuple<vector<Sales_data>::size_type,
                   vector<Sales_data>::const_iterator,
                   vector<Sales_data>::const_iterator>
    matches;

vector<matches> findBook(const vector<vector<Sales_data>> &files,
                         const std::string &book) {
    vector<matches> ret;  // 初始化为空
    for (auto it = files.cbegin(); it != files.cend(); ++it) {
        auto found =
            std::equal_range(it->cbegin(), it->cend(), book, compareIsbn);
        if (found.first != found.second)
            ret.push_back(std::make_tuple(it - files.cbegin(), found.first,
                                          found.second));
    }
    return ret;
}

void reportResults(istream &is, ostream &os,
                   const vector<vector<Sales_data>> &files) {
    std::string s;
    while (is >> s) {
        auto trans = findBook(files, s);
        if (trans.empty()) {
            std::cout << s << " not found in any stores" << std::endl;
            continue;    auto found =
            std::equal_range(it->cbegin(), it->cend(), book, compareIsbn);
        }
        for (const auto &store : trans)
            os << "store " << std::get<0>(store) << " sales:"
               << std::accumulate(std::get<1>(store), std::get<2>(store),
                                  Sales_data(s))
               << std::endl;
    }
}
int main() {
    Sales_data s1("aaa", 1, 1), s2("2", 2, 2), s3("3", 3, 3);
    vector<Sales_data> v1{s1, s2, s3};  // file from one bookstore
    Sales_data s4("bbb", 1, 1), s5("5", 2, 2), s6("6", 3, 3);
    vector<Sales_data> v2{s4, s5, s6, s1};  // file from another bookstore
    vector<vector<Sales_data>> files{v1, v2};
	reportResults(std::cin, std::cout, files);
	return 0;    auto found =
            std::equal_range(it->cbegin(), it->cend(), book, compareIsbn);
}
