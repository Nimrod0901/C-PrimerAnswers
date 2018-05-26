/*
 * @Author: Nimrod
 * @Date: 2018-05-26 20:05:47
 */
#ifndef DEBUGDELETE_H
#define DEBUGDELETE_H

#include <iostream>
// #define printfunc std::cout << __FUNCTION__ << std::endl
class DebugDelete {
public:
    DebugDelete(std::ostream &s = std::cerr) : os(s) {}
    template <typename T>
    void operator()(T *p) const {
        os << "deleting unique_ptr" << std::endl;
        delete p;
        // printfunc;
    }

private:
    std::ostream &os;
};

#endif  // DEBUGDELETE_H