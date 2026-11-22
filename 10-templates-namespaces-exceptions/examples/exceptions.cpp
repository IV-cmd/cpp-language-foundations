#include <iostream>
#include <stdexcept>
#include <string>
#include <utility>

int divide(int a, int b) {
    if (b == 0) {
        throw std::runtime_error("division by zero");
    }
    return a / b;
}

// Prints when it's created and destroyed, so we can watch stack unwinding.
struct Tracer {
    std::string name;
    explicit Tracer(std::string n) : name(std::move(n)) { std::cout << "  enter " << name << '\n'; }
    ~Tracer() { std::cout << "  leave " << name << " (destructor)\n"; }
};

void readFile() {
    Tracer t("readFile");
    throw std::runtime_error("disk read failed");
    std::cout << "  never printed\n";
}

void processFile() {
    Tracer t("processFile");
    readFile();
    std::cout << "  never printed\n";
}

int main() {
    std::cout << "1. try / throw / catch\n";
    try {
        int result = divide(10, 0);
        std::cout << "  result: " << result << '\n';
    } catch (const std::exception& e) {
        std::cout << "  error: " << e.what() << '\n';
    }

    std::cout << "2. propagation and unwinding\n";
    try {
        processFile();
    } catch (const std::exception& e) {
        std::cout << "  caught in main: " << e.what() << '\n';
    }

    std::cout << "3. the first matching catch wins\n";
    try {
        throw std::out_of_range("node id 99 doesn't exist");
    } catch (const std::out_of_range& e) {
        std::cout << "  out_of_range: " << e.what() << '\n';
    } catch (const std::exception& e) {
        std::cout << "  exception: " << e.what() << '\n';
    }
}
