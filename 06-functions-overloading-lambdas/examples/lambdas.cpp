#include <algorithm>
#include <iostream>
#include <vector>

void print(const char* label, const std::vector<int>& values) {
    std::cout << label;
    for (int v : values) {
        std::cout << ' ' << v;
    }
    std::cout << '\n';
}

int main() {
    auto isHealthy = [](int nodeId) { return nodeId > 2; };
    std::cout << std::boolalpha << "isHealthy(3) = " << isHealthy(3) << '\n';

    // Capture by value copies threshold now. Capture by reference reads it later.
    int threshold = 3;
    auto byValue = [threshold](int nodeId) { return nodeId > threshold; };
    auto byRef   = [&threshold](int nodeId) { return nodeId > threshold; };
    threshold = 10;
    std::cout << "threshold changed to 10. Is node 5 healthy?\n"
              << "  [threshold]  says " << byValue(5) << '\n'
              << "  [&threshold] says " << byRef(5) << '\n';

    // A lambda is an object. Its size is the size of what it captures.
    auto none = [] {};
    std::cout << "sizeof: [] " << sizeof none << ", [threshold] " << sizeof byValue
              << ", [&threshold] " << sizeof byRef << '\n';

    std::vector<int> freeGb = {500, 200, 800, 100, 400};
    print("before sort:", freeGb);
    std::sort(freeGb.begin(), freeGb.end(), [](int a, int b) { return a > b; });
    print("most free first:", freeGb);

    int minFree = 300;
    auto usable = std::count_if(freeGb.begin(), freeGb.end(),
                                [minFree](int gb) { return gb >= minFree; });
    std::cout << usable << " nodes have at least " << minFree << " GB free\n";
}
