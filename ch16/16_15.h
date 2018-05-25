/*
 * @Author: Nimrod
 * @Date: 2018-05-25 20:44:24
 */
#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>
#include <string>

template <unsigned H, unsigned W>
class Screen {
    typedef std::string::size_type pos;

private:
    pos cursor = 0;
    pos height = H, width = W;
    std::string contents;

public:
    Screen() = default;
    Screen(char c) : contents(H * W, c) {}
    char get() const { return contents[cursor]; }
    inline char get(pos ht, pos wd) const;
    Screen &move(pos r, pos c);

    friend std::ostream& operator<<(std::ostream &os, const Screen<H, W> &s) {
        for (unsigned int i = 0; i < s.height; i++) {
            os << s.contents.substr(0, W) << std::endl;
        }
        return os;
    }

    friend std::istream& operator>>(std::istream &is, Screen<H, W> &s) {
        char a;
        is >> a;
        s.contents = std::string(H * W, a);
        return is;
    }
};

template <unsigned H, unsigned W>
inline Screen<H, W> &Screen<H, W>::move(pos r, pos c) {
    pos row = r * width;
    cursor = row + c;
    return *this;
}

#endif  // SCREEN_H