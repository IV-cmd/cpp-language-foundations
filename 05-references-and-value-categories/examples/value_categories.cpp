#include <iostream>
#include <utility>

int getSize() { return 4096; }

void process(int& x)  { std::cout << "int&  (lvalue) got " << x << '\n'; }
void process(int&& x) { std::cout << "int&& (rvalue) got " << x << '\n'; }

int main() {
    int a = 10;

    process(a);              // a has a name and an address: lvalue
    process(100);            // a literal: rvalue
    process(a + 1);          // the result of a + 1 is a temporary: rvalue
    process(getSize());      // returned by value: rvalue
    process(std::move(a));   // "treat a as an rvalue" (Phase 2)

    const int& limit = 4096; // const T& can bind to a temporary and keeps it alive
    std::cout << "limit = " << limit << '\n';

#ifdef SHOW_ERRORS
    int* p = &100;           // error: a literal has no address
    int&& r = a;             // error: int&& won't bind to an lvalue
#endif
}
