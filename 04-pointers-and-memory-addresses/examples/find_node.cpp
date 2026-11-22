#include <iostream>

struct StorageNode {
    int id;
    int freeGb;
};

StorageNode nodes[] = {{7, 120}, {42, 800}, {99, 15}};

// Returns a pointer to the node, or nullptr if there isn't one.
StorageNode* findNode(int id) {
    for (auto& node : nodes) {
        if (node.id == id) {
            return &node;
        }
    }
    return nullptr;
}

int main() {
    for (int id : {42, 5}) {
        StorageNode* node = findNode(id);
        if (node) {
            std::cout << "node " << id << ": " << node->freeGb << " GB free\n";
        } else {
            std::cout << "node " << id << ": not found\n";
        }
    }
}
