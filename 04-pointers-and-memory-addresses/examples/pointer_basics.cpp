#include <iostream>

int main() {
    int nodeId = 42;
    int* ptr = &nodeId;           // ptr holds the address of nodeId

    std::cout << "nodeId    = " << nodeId << '\n';
    std::cout << "&nodeId   = " << &nodeId << '\n';
    std::cout << "ptr       = " << ptr << '\n';
    std::cout << "*ptr      = " << *ptr << '\n';
    std::cout << "&ptr      = " << &ptr << "   (the pointer has its own address)\n";

    int copy = *ptr;              // reads the value: copy is a separate int
    *ptr = 100;                   // writes through the pointer: changes nodeId

    std::cout << "after *ptr = 100: nodeId=" << nodeId << " copy=" << copy << '\n';
}
