#include <iostream>

struct Disk {
    Disk()  { std::cout << "  Disk constructed\n"; }
    ~Disk() { std::cout << "  Disk destroyed\n"; }
};

struct NetworkLink {
    NetworkLink()  { std::cout << "  NetworkLink constructed\n"; }
    ~NetworkLink() { std::cout << "  NetworkLink destroyed\n"; }
};

class StorageNode {
public:
    StorageNode()  { std::cout << "  StorageNode constructor body\n"; }
    ~StorageNode() { std::cout << "  StorageNode destructor body\n"; }

private:
    Disk disk;           // declared first: built first, destroyed last
    NetworkLink link;
};

int main() {
    std::cout << "creating node\n";
    {
        StorageNode node;
        std::cout << "using node\n";
    }
    std::cout << "node is gone\n";
}
