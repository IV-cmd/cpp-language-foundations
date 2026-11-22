#include <iostream>

constexpr int BLOCK_SIZE = 4096;

constexpr int calculateBlocks(int fileSize) {
    return (fileSize + BLOCK_SIZE - 1) / BLOCK_SIZE;   // round up
}

int blockSizeFromConfig() { return 4096; }             // pretend this reads a file

int main() {
    constexpr int blocks = calculateBlocks(10000);
    static_assert(blocks == 3);                        // checked by the compiler

    const int runtimeBlockSize = blockSizeFromConfig();   // const, but only known at runtime
    int sizeFromUser = 10000;
    int runtimeBlocks = calculateBlocks(sizeFromUser);    // same function, called at runtime

    std::cout << "blocks=" << blocks << " runtimeBlocks=" << runtimeBlocks
              << " runtimeBlockSize=" << runtimeBlockSize << '\n';

#ifdef SHOW_ERRORS
    constexpr int bad = blockSizeFromConfig();         // error: not a constant expression
    static_assert(runtimeBlockSize == 4096);           // error: not known at compile time
#endif
}
