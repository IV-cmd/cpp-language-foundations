#include <iostream>

class StorageNode {
public:
    int nodeId;
    int totalCapacity;
    int usedCapacity;

    void printInfo() {
        std::cout << "node " << nodeId << ": " << usedCapacity << "/" << totalCapacity
                  << " used (this = " << this << ")\n";
    }
};

int main() {
    StorageNode node1{1, 1000, 400};
    StorageNode node2{2, 2000, 1500};

    std::cout << "&node1 = " << &node1 << ", &node2 = " << &node2 << '\n';
    node1.printInfo();
    node2.printInfo();

    // Objects hold data only. printInfo() is compiled once and shared by every object.
    std::cout << "sizeof(StorageNode) = " << sizeof(StorageNode) << '\n';
}
