#include <cstddef>
#include <iostream>

int main() {
    double size = 10.9;
    int truncated = static_cast<int>(size);   // fractional part is dropped, not rounded
    std::cout << "static_cast<int>(10.9) = " << truncated << '\n';

    int largeNumber = 1000000;
    short smallNumber = static_cast<short>(largeNumber);
    std::cout << "1000000 as short = " << smallNumber << '\n';

    int count = -1;
    std::size_t asSize = count;               // -1 becomes the largest size_t
    std::cout << "-1 as size_t = " << asSize << '\n';

    std::size_t bufferSize = 4096;
    if (count < bufferSize) {                 // count is converted to size_t first
        std::cout << "-1 < 4096\n";
    } else {
        std::cout << "-1 is NOT less than 4096 (compared as unsigned)\n";
    }

#ifdef SHOW_ERRORS
    int x{10.9};                              // error: narrowing inside braces
    short s{largeNumber};                     // error: narrowing inside braces
#endif
}
