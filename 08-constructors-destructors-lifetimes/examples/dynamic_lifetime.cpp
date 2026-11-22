#include <iostream>

class StorageNode {
public:
    StorageNode(int id) : nodeId(id) { std::cout << "  constructor: node " << nodeId << '\n'; }
    ~StorageNode() { std::cout << "  destructor:  node " << nodeId << '\n'; }

private:
    int nodeId;
};

void withDelete() {
    StorageNode* node = new StorageNode(1);
    delete node;                        // runs the destructor, then frees the memory
}

void withoutDelete() {
    StorageNode* node = new StorageNode(2);
    (void)node;
}   // the pointer dies here. The object doesn't.

int main() {
    std::cout << "withDelete()\n";
    withDelete();
    std::cout << "withoutDelete()\n";
    withoutDelete();
    std::cout << "end of main\n";
}
