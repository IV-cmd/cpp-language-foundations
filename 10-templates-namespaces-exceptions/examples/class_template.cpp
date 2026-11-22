#include <iostream>
#include <string>
#include <utility>

template <typename T>
class StorageContainer {
public:
    explicit StorageContainer(T value) : data(std::move(value)) {}
    const T& getData() const { return data; }

private:
    T data;
};

int main() {
    StorageContainer<int> intContainer(100);
    StorageContainer<std::string> stringContainer("EOS");

    std::cout << intContainer.getData() << ' ' << stringContainer.getData() << '\n';
    std::cout << "sizeof(StorageContainer<int>)         = " << sizeof(intContainer) << '\n';
    std::cout << "sizeof(StorageContainer<std::string>) = " << sizeof(stringContainer) << '\n';
}
