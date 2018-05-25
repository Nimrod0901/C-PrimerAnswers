#include "13_30.h"

int main() {
    HasPtr h1("Nim"), h2("rod");
    swap(h1, h2);
    std::cout << "h1->string: ";
    h1.show();
    std::cout << "h2->string: ";
    h2.show();    
    return 0;
}