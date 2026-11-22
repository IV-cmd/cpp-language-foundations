#include <iostream>

int main() {
    int a = 10;
    int b = 20;

    const int* p1 = &a;        // pointer to const int
    p1 = &b;                   // ok: the pointer itself can move

    int* const p2 = &a;        // const pointer to int
    *p2 = 30;                  // ok: the int can change

    const int* const p3 = &a;  // const pointer to const int

#ifdef SHOW_ERRORS
    *p1 = 99;                  // error: the int is read-only through p1
    p2 = &b;                   // error: p2 can't be reseated
    p3 = &b;                   // error
    *p3 = 99;                  // error
#endif

    std::cout << "a=" << a << " *p1=" << *p1 << " *p3=" << *p3 << '\n';
}
