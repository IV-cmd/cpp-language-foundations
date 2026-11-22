#include <cstdint>
#include <iostream>
#include <stdexcept>
#include <string>
#include <utility>

class StorageNode {
public:
    StorageNode(int id, std::string host, std::uint64_t total, std::uint64_t used)
        : nodeId(id), hostname(std::move(host)), totalCapacity(total), usedCapacity(used) {
        if (used > total) {
            throw std::invalid_argument("used capacity exceeds total");   // Module 10
        }
    }

    std::uint64_t getAvailableCapacity() const { return totalCapacity - usedCapacity; }
    bool isHealthy() const { return healthy; }
    void markUnhealthy() { healthy = false; }

    void printInfo() const {
        std::cout << "node " << nodeId << " (" << hostname << "): "
                  << getAvailableCapacity() << " free, healthy=" << healthy << '\n';
    }

private:
    int nodeId;
    std::string hostname;
    std::uint64_t totalCapacity;
    std::uint64_t usedCapacity;
    bool healthy = true;
};

int main() {
    std::cout << std::boolalpha;

    StorageNode node(1, "fst-01", 100000, 40000);
    node.printInfo();
    node.markUnhealthy();
    node.printInfo();

    const StorageNode backup(2, "fst-02", 50000, 10000);
    std::cout << "backup free: " << backup.getAvailableCapacity() << '\n';   // const: fine

    try {
        StorageNode broken(3, "fst-03", 1000, 2000);
    } catch (const std::invalid_argument& e) {
        std::cout << "rejected fst-03: " << e.what() << '\n';
    }

#ifdef SHOW_ERRORS
    backup.markUnhealthy();     // error: markUnhealthy() isn't const
#endif
}
