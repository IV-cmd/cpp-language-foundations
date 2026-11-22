#include <iostream>

// Broken on purpose. Members are initialised in the order they're declared,
// not the order they're written in the initialiser list.
class Volume {
public:
    Volume(int total, int used)
        : totalCapacity(total), usedCapacity(used),
          availableCapacity(totalCapacity - usedCapacity) {}

    void print() const {
        std::cout << "total=" << totalCapacity << " used=" << usedCapacity
                  << " available=" << availableCapacity << '\n';
    }

private:
    int availableCapacity;      // declared first, so initialised first
    int totalCapacity;
    int usedCapacity;
};

int main() {
    Volume v(1000, 400);
    v.print();
}
