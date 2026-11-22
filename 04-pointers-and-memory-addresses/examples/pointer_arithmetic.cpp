#include <iostream>

int main() {
    int values[] = {10, 20, 30};
    int* p = values;              // an array name decays to a pointer to its first element

    for (int i = 0; i < 3; ++i) {
        std::cout << "p = " << p << "  *p = " << *p << '\n';
        ++p;                      // moves by sizeof(int), not by 1 byte
    }

    char text[] = "abc";
    char* c = text;
    std::cout << "\nc = " << static_cast<void*>(c) << "  c + 1 = " << static_cast<void*>(c + 1) << '\n';

    // p now points one past the end. Comparing or subtracting is fine; dereferencing isn't.
    std::cout << "\nelements between values and p: " << (p - values) << '\n';
}
