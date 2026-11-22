#include "MetadataManager.hpp"
#include "StorageNode.hpp"

int main() {
    StorageNode node;
    MetadataManager metadata;

    node.storeFile();
    metadata.recordFile();
}
