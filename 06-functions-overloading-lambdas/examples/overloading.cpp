#include <iostream>
#include <string>

int calculateChecksum(int data) {
    return data * 31;
}

int calculateChecksum(const std::string& data) {
    int sum = 0;
    for (char c : data) {
        sum = sum * 31 + c;
    }
    return sum;
}

#ifdef SHOW_ERRORS
int getSize() { return 100; }
double getSize() { return 100.0; }   // error: differs only in return type
#endif

int main() {
    std::cout << "calculateChecksum(10)    = " << calculateChecksum(10) << '\n';
    std::cout << "calculateChecksum(\"EOS\") = " << calculateChecksum("EOS") << '\n';
}
