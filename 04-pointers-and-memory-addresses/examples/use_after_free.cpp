#include <iostream>

int main() {
    int* ptr = new int(42);
    delete ptr;
    std::cout << *ptr << '\n';    // the object is gone, the address isn't
}
