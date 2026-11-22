#include <cstdint>
#include <iostream>

int main() {
    // 10 GiB doesn't fit in a 32-bit int. The conversion keeps only the low 32 bits.
    long long tenGiB = 10LL * 1024 * 1024 * 1024;
    std::int32_t truncated = static_cast<std::int32_t>(tenGiB);
    std::uint64_t fileSize = tenGiB;
    std::cout << "10 GiB as int64:  " << tenGiB << '\n';
    std::cout << "10 GiB as int32:  " << truncated << '\n';
    std::cout << "10 GiB as uint64: " << fileSize << '\n';

    // Unsigned arithmetic wraps around modulo 2^N.
    std::uint32_t size = 0;
    size--;
    std::cout << "0u - 1 (uint32):  " << size << '\n';

    // A "remaining bytes" calculation that goes wrong.
    std::uint64_t bufferSize = 4096;
    std::uint64_t used = 5000;
    std::uint64_t remaining = bufferSize - used;
    std::cout << "4096 - 5000:      " << remaining << '\n';
}
