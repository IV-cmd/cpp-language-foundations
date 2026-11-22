#!/usr/bin/env bash
for f in functions overloading lambdas; do
    echo "=== $f"
    g++ -std=c++20 -Wall -Wextra $f.cpp -o $f && ./$f
    rm -f $f
done

echo "=== overloading with -DSHOW_ERRORS"
g++ -std=c++20 -DSHOW_ERRORS -fsyntax-only overloading.cpp 2>&1 | grep -E 'error'

# Overloads get different symbol names (name mangling, Module 1).
echo "=== overloaded symbols in overloading.o"
g++ -std=c++20 -c overloading.cpp -o overloading.o
nm overloading.o | grep calculateChecksum
nm -C overloading.o | grep calculateChecksum
rm -f overloading.o

# Broken on purpose.
echo "=== dangling_lambda (plain build)"
g++ -std=c++20 -Wall -Wextra dangling_lambda.cpp -o dangling_lambda && ./dangling_lambda
echo "=== dangling_lambda (with AddressSanitizer)"
g++ -std=c++20 -g -fsanitize=address dangling_lambda.cpp -o dangling_lambda
./dangling_lambda
rm -f dangling_lambda
