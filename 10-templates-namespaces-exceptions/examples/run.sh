#!/usr/bin/env bash
# Builds and runs every example, then rebuilds with -DSHOW_ERRORS
# to show the compiler errors the commented-out lines produce.
for f in templates class_template namespaces exceptions; do
    echo "=== $f"
    g++ -std=c++20 -Wall -Wextra $f.cpp -o $f && ./$f
    rm -f $f
done

echo "=== template instantiations in templates.o"
g++ -std=c++20 -c templates.cpp -o templates.o
nm -C templates.o | grep -E 'getFirst<|findMaximum<' | sed 's/std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >/std::string/g; s/, std::allocator<[^>]*> >/>/g; s/<std::string >/<std::string>/g'
rm -f templates.o

echo "=== namespaced symbols in namespaces.o"
g++ -std=c++20 -c namespaces.cpp -o namespaces.o
nm namespaces.o | grep connect
rm -f namespaces.o

echo "=== uncaught (broken on purpose)"
g++ -std=c++20 -Wall -Wextra uncaught.cpp -o uncaught && ./uncaught
echo "exit status: $?"
rm -f uncaught

for f in templates namespaces; do
    echo "=== $f with -DSHOW_ERRORS"
    g++ -std=c++20 -DSHOW_ERRORS -fsyntax-only $f.cpp 2>&1 | grep -E 'error|deduced conflicting|candidate:'
done
