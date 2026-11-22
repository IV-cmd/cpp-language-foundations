#include <iostream>

int main() {
    int fileSize = 100;
    int& size = fileSize;          // size is another name for fileSize

    size = 500;
    std::cout << "fileSize = " << fileSize << '\n';
    std::cout << "&fileSize = " << &fileSize << "\n&size     = " << &size << '\n';

    // A reference can't be re-pointed. This copies otherSize's value into fileSize.
    int otherSize = 7;
    size = otherSize;
    std::cout << "after size = otherSize: fileSize = " << fileSize
              << ", &size still " << &size << '\n';

    // The same thing with a pointer, for comparison.
    int* ptr = &fileSize;
    *ptr = 900;
    ptr = &otherSize;              // a pointer can be re-pointed
    std::cout << "after *ptr = 900: fileSize = " << fileSize
              << ", ptr now points at otherSize (" << *ptr << ")\n";

#ifdef SHOW_ERRORS
    int& unbound;                  // error: a reference must be initialised
    int& toTemporary = 100;        // error: can't bind int& to a temporary
#endif
}
