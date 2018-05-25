/*
 * @Author: Nimrod
 * @Date: 2018-05-25 20:29:12
 */

#ifndef SCREEN_H
#define SCREEN_H

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
    Screen(char c)
        : contents(H * W, c) {}
    char get() const { return contents[cursor] }
    inline char get(pos ht, pos wd) const;
    Screen &move(pos r, pos c)
};

template <unsigned H, unsigned W>
inline Screen<H, W> &Screen<H, W>::move(pos r, pos c) {
    pos row = r * width;
    cursor = row + c;
    return *this;
}
#endif  // SCREEN_H