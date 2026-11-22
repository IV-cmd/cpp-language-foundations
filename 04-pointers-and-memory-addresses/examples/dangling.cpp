#include <iostream>

int* createNodeId() {
    int nodeId = 42;
    return &nodeId;               // nodeId dies when the function returns
}

int main() {
    int* p = createNodeId();
    std::cout << "p = " << p << std::endl;   // flush before the crash
    std::cout << *p << '\n';      // undefined behaviour
}
