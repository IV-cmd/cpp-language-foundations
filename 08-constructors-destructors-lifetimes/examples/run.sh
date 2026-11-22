#!/usr/bin/env bash
# Builds and runs every example, then rebuilds with -DSHOW_ERRORS
# to show the compiler errors the commented-out lines produce.
for f in lifecycle default_constructor members dynamic_lifetime storage_file; do
    echo "=== $f"
    g++ -std=c++20 -Wall -Wextra $f.cpp -o $f && ./$f
    rm -f $f
done

# -O1 because at -O0 a stale copy of the pointer can stay on the stack, and the
# leak checker (which scans memory for anything that looks like a pointer) misses it.
echo "=== dynamic_lifetime with AddressSanitizer (finds the leaked node 2)"
g++ -std=c++20 -g -O1 -fsanitize=address dynamic_lifetime.cpp -o dynamic_lifetime_asan
./dynamic_lifetime_asan 2>&1 | grep -E 'constructor|destructor|end of main|ERROR|SUMMARY|Direct leak|#[01] '
rm -f dynamic_lifetime_asan

for f in default_constructor storage_file; do
    echo "=== $f with -DSHOW_ERRORS"
    g++ -std=c++20 -DSHOW_ERRORS -fsyntax-only $f.cpp 2>&1 | grep -E 'error'
done
