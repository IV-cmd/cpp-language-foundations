#include <iostream>
#include <string>
#include <utility>

class StorageNode {
public:
    explicit StorageNode(std::string name) : name(std::move(name)) {
        std::cout << "  constructor: " << this->name << '\n';
    }
    ~StorageNode() {
        std::cout << "  destructor:  " << name << '\n';
    }

private:
    std::string name;
};

int main() {
    std::cout << "1. one object\n";
    {
        std::cout << "  before object\n";
        StorageNode node("fst-01");
        std::cout << "  after object, doing work\n";
    }   // node's lifetime ends here

    std::cout << "2. three objects\n";
    {
        StorageNode node1("node1");
        StorageNode node2("node2");
        StorageNode node3("node3");
    }   // destroyed in reverse order

    std::cout << "3. nested scope\n";
    StorageNode outer("outer");
    {
        StorageNode inner("inner");
        std::cout << "  leaving inner block\n";
    }
    std::cout << "  back in main\n";
    std::cout << "end of main\n";
}
