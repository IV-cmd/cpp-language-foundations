#include <iostream>
#include <stdexcept>

struct Tracer {
    ~Tracer() { std::cout << "Tracer destructor\n"; }
};

int main() {
    Tracer t;
    std::cout << "about to throw with no handler" << std::endl;   // flush: abort() won't
    throw std::runtime_error("disk read failed");
}
