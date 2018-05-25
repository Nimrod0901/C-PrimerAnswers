/*
 * @Author: Nimrod
 * @Date: 2018-05-25 20:51:30
 */
#include "16_15.h"

int main() {
    Screen<3, 4> s('!');
    std::cout << s;
    std::cin >> s;
    std::cout << s;
    return 0;
}