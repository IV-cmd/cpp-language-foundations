#include <cstdint>
#include <iostream>
#include <string>

struct FileMetadata {
    std::string filename;
    std::uint64_t fileSize;
    std::uint64_t checksum;
};

void updateByValue(int size) { size = 500; }
void updateByReference(int& size) { size = 500; }

void inspectCopy(FileMetadata metadata) {
    std::cout << "by value:     " << &metadata << " (a new " << sizeof metadata << "-byte object)\n";
}

void inspect(const FileMetadata& metadata) {
    std::cout << "by const ref: " << &metadata << " (the caller's object)\n";
#ifdef SHOW_ERRORS
    metadata.fileSize = 0;         // error: metadata is read-only here
#endif
}

int main() {
    int fileSize = 100;
    updateByValue(fileSize);
    std::cout << "after updateByValue:     " << fileSize << '\n';
    updateByReference(fileSize);
    std::cout << "after updateByReference: " << fileSize << '\n';

    FileMetadata meta{"/eos/data/run42.root", 4096, 0xbeef};
    std::cout << "\ncaller:       " << &meta << '\n';
    inspectCopy(meta);
    inspect(meta);
}
