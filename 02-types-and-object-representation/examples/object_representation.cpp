#include <cstddef>
#include <cstdio>

// Print every byte of an object, lowest address first.
template <typename T>
void dumpBytes(const char* label, const T& object) {
    auto bytes = reinterpret_cast<const unsigned char*>(&object);
    std::printf("%-12s", label);
    for (std::size_t i = 0; i < sizeof(T); ++i) {
        std::printf("%02x ", bytes[i]);
    }
    std::printf("\n");
}

int main() {
    int x = 42;
    int big = 0x11223344;
    int negative = -1;
    float f = 42.0f;

    dumpBytes("42", x);
    dumpBytes("0x11223344", big);
    dumpBytes("-1", negative);
    dumpBytes("42.0f", f);
}
