#include <iostream>

class StorageNode {               // abstract: has a pure virtual function
public:
    virtual void performIO() const = 0;
    virtual ~StorageNode() = default;
};

class NVMeNode : public StorageNode {
public:
    void performIO() const override { std::cout << "NVMe parallel queues I/O\n"; }
};

#ifdef SHOW_ERRORS
class TypoNode : public StorageNode {
public:
    void performIo() const override {}   // error: typo, so it overrides nothing
};
#endif

int main() {
    NVMeNode nvme;
    const StorageNode& node = nvme;
    node.performIO();

#ifdef SHOW_ERRORS
    StorageNode generic;          // error: can't create an abstract class
#endif
}
