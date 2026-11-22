#include <cstddef>
#include <iostream>

struct StorageNode {
    char status;
    int nodeId;
    double capacity;
};

struct StorageNodeReordered {
    double capacity;
    int nodeId;
    char status;
};

// Here the field order really does matter.
struct FileEntryBad {
    char flags;
    double size;
    char replicas;
};

struct FileEntryGood {
    double size;
    char flags;
    char replicas;
};

#define SHOW(T) std::cout << #T << ": sizeof=" << sizeof(T) << " alignof=" << alignof(T) << '\n'
#define FIELD(T, f) std::cout << "  " #f " at offset " << offsetof(T, f) << '\n'

int main() {
    SHOW(StorageNode);
    FIELD(StorageNode, status);
    FIELD(StorageNode, nodeId);
    FIELD(StorageNode, capacity);

    SHOW(StorageNodeReordered);
    FIELD(StorageNodeReordered, capacity);
    FIELD(StorageNodeReordered, nodeId);
    FIELD(StorageNodeReordered, status);

    SHOW(FileEntryBad);
    FIELD(FileEntryBad, flags);
    FIELD(FileEntryBad, size);
    FIELD(FileEntryBad, replicas);

    SHOW(FileEntryGood);
    FIELD(FileEntryGood, size);
    FIELD(FileEntryGood, flags);
    FIELD(FileEntryGood, replicas);
}
