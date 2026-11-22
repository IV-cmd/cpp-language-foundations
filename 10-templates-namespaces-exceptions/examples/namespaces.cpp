#include <iostream>

namespace Storage {
    void connect() { std::cout << "connecting to storage\n"; }
}

namespace Metadata {
    void connect() { std::cout << "connecting to metadata\n"; }
}

namespace eos::fst {               // nested namespace, C++17 shorthand
    void connect() { std::cout << "connecting to an FST node\n"; }
}

#ifdef SHOW_ERRORS
void tooMuchUsing() {
    using namespace Storage;
    using namespace Metadata;      // now two connect()s are visible
    connect();                     // error: ambiguous
}
#endif

int main() {
    Storage::connect();
    Metadata::connect();
    eos::fst::connect();

    using Storage::connect;        // brings in just this one name
    connect();
}
