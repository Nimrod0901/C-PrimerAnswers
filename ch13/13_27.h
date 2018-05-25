#ifndef 13_27_H
#define 13_27_H

class HasPtr {
public:
    HasPtr(const std::string &s = std::string()): ps(new std::string(s)), i(0) {}
    HasPtr(const HasPtr &arg) : ps(new std::string(*arg.ps)), i(arg.i) {}
    HasPtr& operator=(const HasPtr& arg) { 
        std::string *new_ps = new std::string(*arg.ps);
        delete ps;//necessary
        ps = new_ps;
        i = arg.i;
        ++*use;
        return *this;
    }

    ~HasPtr() {
        if(*use-- == 0){
            delete ps;
            delete use;
        }
    }

private:
    std::string *ps;
    int i;
    std::size_t *use;
};

#endif // 13_27_H
