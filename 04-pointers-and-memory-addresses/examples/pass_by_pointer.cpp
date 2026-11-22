#include <iostream>

void updateCapacityByValue(int capacity) {
    capacity = 100;               // changes the local copy only
}

void updateCapacityByPointer(int* capacity) {
    *capacity = 100;              // changes the caller's variable
}

int main() {
    int capacity = 50;
    updateCapacityByValue(capacity);
    std::cout << "after by-value:   " << capacity << '\n';
    updateCapacityByPointer(&capacity);
    std::cout << "after by-pointer: " << capacity << '\n';
}
