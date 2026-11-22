void handleRequest() {
    char* buffer = new char[1024 * 1024];
    buffer[0] = 'x';
    // forgot delete[] buffer;
}

int main() {
    for (int i = 0; i < 3; ++i) {
        handleRequest();
    }
}
