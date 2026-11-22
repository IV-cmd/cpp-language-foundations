#include <iostream>

class StorageNode {
public:
    virtual void performIO() const { std::cout << "generic storage I/O\n"; }
    void describe() const { std::cout << "plain StorageNode::describe\n"; }   // not virtual
    virtual ~StorageNode() = default;
};

class SSDNode : public StorageNode {
public:
    void performIO() const override { std::cout << "SSD random I/O\n"; }
    void describe() const { std::cout << "SSDNode::describe\n"; }
};

class HDDNode : public StorageNode {
public:
    void performIO() const override { std::cout << "HDD sequential I/O\n"; }
};

void runThroughPointer(const StorageNode* node) { node->performIO(); }
void runThroughReference(const StorageNode& node) { node.performIO(); }
void runByValue(StorageNode node) { node.performIO(); }    // copies only the StorageNode part

struct Plain   { int id; void f() {} };
struct Virtual { int id; virtual void f() {} };

int main() {
    SSDNode ssd;
    HDDNode hdd;

    std::cout << "-- virtual, through StorageNode*\n";
    const StorageNode* nodes[] = {&ssd, &hdd};
    for (const StorageNode* node : nodes) {
        node->performIO();
    }

    std::cout << "-- non-virtual, through StorageNode*\n";
    const StorageNode* base = &ssd;
    base->describe();
    ssd.describe();

    std::cout << "-- passing an SSDNode three ways\n";
    runThroughPointer(&ssd);
    runThroughReference(ssd);
    runByValue(ssd);

    std::cout << "-- the cost of virtual\n";
    std::cout << "sizeof(Plain) = " << sizeof(Plain) << ", sizeof(Virtual) = " << sizeof(Virtual) << '\n';
}
