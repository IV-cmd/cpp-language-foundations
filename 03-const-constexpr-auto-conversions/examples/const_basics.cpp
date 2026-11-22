#include <iostream>

class StorageNode {
public:
    int getNodeId() const { return nodeId; }   // promises not to modify *this
    void setNodeId(int id) { nodeId = id; }

private:
    int nodeId = 42;
};

int main() {
    const int blockSize = 4096;
    const StorageNode node;

    std::cout << "node id: " << node.getNodeId() << '\n';  // fine, getNodeId() is const

#ifdef SHOW_ERRORS
    blockSize = 8192;       // error: assignment of read-only variable
    node.setNodeId(7);      // error: setNodeId() isn't const
#endif
    (void)blockSize;
}
