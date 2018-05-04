/*
 * @Author: Nimrod
 * @Date: 2018-05-04 17:16:23
 */
#include <fstream>
#include <iostream>
#include "12_19.h"

int main() {
    std::ifstream ifs("./books.txt");
    StrBlob sb;
    string s;
    while (getline(ifs, s)) {
        sb.push_back(s);
    }
    for (StrBlobPtr sbp = sb.begin(); sbp != sb.end(); sbp.incr()) {
        std::cout << sbp.deref() << std::endl;
    }
    return 0;
}