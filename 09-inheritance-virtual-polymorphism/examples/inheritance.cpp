#include <iostream>

class StorageNode {
public:
    int nodeId = 0;
    void printInfo() const { std::cout << "node " << nodeId << ", " << capacity << " GB\n"; }

protected:
    int capacity = 0;          // derived classes can use this

private:
    int internalSecret = 42;   // only StorageNode's own functions can
};

class SSDNode : public StorageNode {
public:
    SSDNode(int id, int gb) { nodeId = id; capacity = gb; }
    void optimiseForRandomIO() const { std::cout << "SSD " << nodeId << ": optimising for random I/O\n"; }

private:
    int eraseCycles = 0;
};

class HDDNode : public StorageNode {
public:
    HDDNode(int id, int gb) { nodeId = id; capacity = gb; }
    void optimiseForSequentialIO() const { std::cout << "HDD " << nodeId << ": optimising for sequential I/O\n"; }

#ifdef SHOW_ERRORS
    void peek() { std::cout << internalSecret; }   // error: private in StorageNode
#endif
};

int main() {
    SSDNode ssd(1, 1000);
    HDDNode hdd(2, 8000);

    ssd.printInfo();              // inherited from StorageNode
    ssd.optimiseForRandomIO();    // SSDNode's own
    hdd.printInfo();
    hdd.optimiseForSequentialIO();

    std::cout << "sizeof(StorageNode) = " << sizeof(StorageNode) << '\n';
    std::cout << "sizeof(SSDNode)     = " << sizeof(SSDNode) << '\n';

    StorageNode* base = &ssd;     // an SSDNode is a StorageNode
    std::cout << "&ssd = " << &ssd << ", base = " << base << '\n';

#ifdef SHOW_ERRORS
    ssd.capacity = 5;             // error: protected, and main isn't a derived class
#endif
}
