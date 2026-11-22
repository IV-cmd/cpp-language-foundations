#include <climits>
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <limits>

int main() {
    std::cout << "CHAR_BIT      " << CHAR_BIT << '\n';
    std::cout << "char          " << sizeof(char) << '\n';
    std::cout << "bool          " << sizeof(bool) << '\n';
    std::cout << "short         " << sizeof(short) << '\n';
    std::cout << "int           " << sizeof(int) << '\n';
    std::cout << "long          " << sizeof(long) << '\n';
    std::cout << "long long     " << sizeof(long long) << '\n';
    std::cout << "double        " << sizeof(double) << '\n';
    std::cout << "std::size_t   " << sizeof(std::size_t) << '\n';
    std::cout << "int*          " << sizeof(int*) << '\n';
    std::cout << '\n';
    std::cout << "int max       " << std::numeric_limits<int>::max() << '\n';
    std::cout << "int64_t max   " << std::numeric_limits<std::int64_t>::max() << '\n';
    std::cout << "uint64_t max  " << std::numeric_limits<std::uint64_t>::max() << '\n';
}
