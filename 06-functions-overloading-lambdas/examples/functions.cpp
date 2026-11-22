#include <iostream>
#include <string>

int calculateChecksum(int data) {
    return data * 31;
}

void deleteFile(const std::string& filename) {
    std::cout << "deleted " << filename << '\n';
}

// The default goes in the declaration (normally the header), not the definition.
void readFile(const std::string& filename, int bufferSize = 4096);

int main() {
    int checksum = calculateChecksum(10);
    std::cout << "checksum = " << checksum << '\n';

    deleteFile("old.log");          // void: nothing to store

    readFile("data.bin");           // compiler rewrites this to readFile("data.bin", 4096)
    readFile("data.bin", 8192);
}

void readFile(const std::string& filename, int bufferSize) {
    std::cout << "reading " << filename << " with a " << bufferSize << "-byte buffer\n";
}
