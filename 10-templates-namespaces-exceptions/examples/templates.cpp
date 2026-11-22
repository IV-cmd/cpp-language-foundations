#include <iostream>
#include <string>
#include <vector>

template <typename T>
T getFirst(const std::vector<T>& values) {
    return values[0];
}

template <typename T>
T findMaximum(T a, T b) {
    if (a > b) {
        return a;
    }
    return b;
}

struct StorageNode {
    int nodeId;
};

int main() {
    std::vector<int> ids{7, 3, 9};
    std::vector<double> loads{0.75, 0.20};
    std::vector<std::string> hosts{"fst-01", "fst-02"};

    std::cout << "getFirst(ids)   = " << getFirst(ids) << '\n';
    std::cout << "getFirst(loads) = " << getFirst(loads) << '\n';
    std::cout << "getFirst(hosts) = " << getFirst(hosts) << '\n';

    std::cout << "findMaximum(10, 20)     = " << findMaximum(10, 20) << '\n';
    std::cout << "findMaximum(10.5, 20.5) = " << findMaximum(10.5, 20.5) << '\n';
    std::cout << "findMaximum(string fst-01, string fst-09) = "
              << findMaximum(std::string("fst-01"), std::string("fst-09")) << '\n';
    std::cout << "findMaximum<double>(10, 20.5) = " << findMaximum<double>(10, 20.5) << '\n';

#ifdef SHOW_ERRORS
    findMaximum(10, 20.5);                          // error: is T int or double?
    findMaximum(StorageNode{1}, StorageNode{2});    // error: StorageNode has no >
#endif
}
