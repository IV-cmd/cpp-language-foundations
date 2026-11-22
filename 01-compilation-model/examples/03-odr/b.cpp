#include COUNTER_HEADER

void bumpFromA();

int main() {
    bumpFromA();
    ++globalCounter;
    return globalCounter;  // 2
}
