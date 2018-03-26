//The code is copied from https://github.com/Mooophy/Cpp-Primer/edit/master/ch10/ex10_33.cpp

#include <fstream>
#include <iterator>
#include <algorithm>

int main() {
    std::ifstream ifs("input.txt");
    std::ofstream ofs_odd("odd.txt"), ofs_even("even.txt");

    std::istream_iterator<int> in(ifs), in_eof;
    std::ostream_iterator<int> out_odd(ofs_odd, " "), out_even(ofs_even, "\n");

    std::for_each(in, in_eof, [&out_odd, &out_even](const int i){
        *(i & 0x1 ? out_odd : out_even)++ = i;
    });

    return 0;
}
