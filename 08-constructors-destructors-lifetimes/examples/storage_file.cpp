#include <cstdio>
#include <iostream>
#include <stdexcept>
#include <string>

class StorageFile {
public:
    explicit StorageFile(const char* path) : file(std::fopen(path, "rb")) {
        if (file == nullptr) {
            throw std::runtime_error(std::string("can't open ") + path);
        }
        std::cout << "  opened " << path << '\n';
    }

    ~StorageFile() {
        std::fclose(file);
        std::cout << "  closed\n";
    }

    // Two objects owning one FILE* would both fclose it. Forbid copies.
    StorageFile(const StorageFile&) = delete;
    StorageFile& operator=(const StorageFile&) = delete;

    long size() const {
        std::fseek(file, 0, SEEK_END);
        return std::ftell(file);
    }

private:
    std::FILE* file;
};

int main() {
    std::FILE* out = std::fopen("node.dat", "wb");
    std::fputs("block data for fst-01", out);
    std::fclose(out);

    {
        StorageFile f("node.dat");
        std::cout << "  size: " << f.size() << " bytes\n";
    }   // no fclose here: the destructor does it
    std::cout << "after the block\n";

    try {
        StorageFile missing("missing.dat");
    } catch (const std::exception& e) {
        std::cout << "  error: " << e.what() << '\n';
    }

#ifdef SHOW_ERRORS
    StorageFile a("node.dat");
    StorageFile b = a;                  // error: copy constructor is deleted
#endif
    std::remove("node.dat");
}
