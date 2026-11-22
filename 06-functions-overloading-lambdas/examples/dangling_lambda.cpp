#include <functional>
#include <iostream>

// Tells AddressSanitizer to check stack lifetimes (it doesn't by default).
// Ignored in a normal build.
extern "C" const char* __asan_default_options() { return "detect_stack_use_after_return=1"; }

// Broken on purpose: the lambda keeps a reference to a local that dies on return.
std::function<bool(int)> makeChecker() {
    int threshold = 3;
    return [&threshold](int nodeId) { return nodeId > threshold; };
}

int main() {
    auto isHealthy = makeChecker();
    std::cout << std::boolalpha << "isHealthy(5) = " << isHealthy(5) << '\n';
}
