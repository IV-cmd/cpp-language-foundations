#include <iostream>
#include <vector>

// Broken on purpose: without -DFIXED, ~StorageNode() isn't virtual.
class StorageNode {
public:
    virtual void performIO() const = 0;
#ifdef FIXED
    virtual
#endif
    ~StorageNode() { std::cout << "  ~StorageNode\n"; }
};

class SSDNode : public StorageNode {
public:
    SSDNode() : writeCache(1024 * 1024) {}
    ~SSDNode() { std::cout << "  ~SSDNode (frees the 1 MiB write cache)\n"; }
    void performIO() const override {}

private:
    std::vector<char> writeCache;
};

int main() {
    StorageNode* node = new SSDNode();
    std::cout << "delete through StorageNode*\n";
    delete node;
}
