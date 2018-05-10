/*
 * @Author: Nimrod
 * @Date: 2018-05-10 22:57:44
 */

#include <iostream>
#include <memory>
#include <string>

using std::allocator;
using std::string;
using std::cin;

int main() {
    int n = 5;
    allocator<string> alloc;
    auto p = alloc.allocate(n);
    string s;
    auto q = p;
    while (cin >> s && q != p + n) {
        alloc.construct(q++, s);
    }
    while (q != p) {
        std::cout << *--q << " ";
        alloc.destroy(q);
    }
    alloc.deallocate(p, n);

    return 0; 
}