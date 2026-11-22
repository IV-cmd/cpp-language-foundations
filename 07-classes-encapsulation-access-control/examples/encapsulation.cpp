#include <iostream>

struct OpenNode {            // struct: members are public by default
    int totalCapacity;
    int usedCapacity;
};

class StorageNode {          // class: members are private by default
    int totalCapacity = 0;
    int usedCapacity = 0;

public:
    bool setCapacity(int total, int used) {
        if (used < 0 || used > total) {
            return false;
        }
        totalCapacity = total;
        usedCapacity = used;
        return true;
    }

    int getAvailableCapacity() const { return totalCapacity - usedCapacity; }
};

int main() {
    OpenNode open{1000, 400};
    open.usedCapacity = 2000;                       // nothing stops this
    std::cout << "open node available: " << open.totalCapacity - open.usedCapacity << '\n';

    StorageNode node;
    std::cout << std::boolalpha;
    std::cout << "setCapacity(1000, 400):  " << node.setCapacity(1000, 400) << '\n';
    std::cout << "setCapacity(1000, 2000): " << node.setCapacity(1000, 2000) << '\n';
    std::cout << "available: " << node.getAvailableCapacity() << '\n';

#ifdef SHOW_ERRORS
    node.usedCapacity = 2000;                       // error: private
#endif
}
