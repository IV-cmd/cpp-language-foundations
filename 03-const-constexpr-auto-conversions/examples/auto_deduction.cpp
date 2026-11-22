#include <iostream>
#include <string>
#include <type_traits>
#include <vector>

int main() {
    auto nodeId = 42;
    auto capacity = 100.5;
    auto available = true;
    static_assert(std::is_same_v<decltype(nodeId), int>);
    static_assert(std::is_same_v<decltype(capacity), double>);
    static_assert(std::is_same_v<decltype(available), bool>);

    int original = 42;
    auto copy = original;       // a new int
    auto& ref = original;       // another name for original
    copy = 100;
    std::cout << "after copy = 100: original=" << original << " copy=" << copy << '\n';
    ref = 100;
    std::cout << "after ref = 100:  original=" << original << '\n';

    const int fixed = 42;
    auto a = fixed;             // top-level const is dropped: plain int
    const auto& b = fixed;      // const int&
    static_assert(std::is_same_v<decltype(a), int>);
    static_assert(std::is_same_v<decltype(b), const int&>);
    a = 7;                      // fine, a is just a copy

    std::vector<std::string> nodes{"node-a", "node-b", "node-c"};
    for (const auto& node : nodes) {    // no copies, read-only
        std::cout << node << ' ';
    }
    std::cout << '\n';
}
