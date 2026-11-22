#include <iostream>

class Configured {
public:
    Configured(int id) : nodeId(id) {}    // only a parameterised constructor
    int nodeId;
};

class Defaulted {
public:
    Defaulted() = default;                // ask the compiler for the no-argument one too
    Defaulted(int id) : nodeId(id) {}
    int nodeId = 0;                       // used when a constructor doesn't set it
};

int main() {
    Configured a(10);
    Defaulted b;
    Defaulted c(20);
    std::cout << "a.nodeId = " << a.nodeId << '\n';
    std::cout << "b.nodeId = " << b.nodeId << '\n';
    std::cout << "c.nodeId = " << c.nodeId << '\n';

#ifdef SHOW_ERRORS
    Configured d;                         // error: no default constructor
#endif
}
