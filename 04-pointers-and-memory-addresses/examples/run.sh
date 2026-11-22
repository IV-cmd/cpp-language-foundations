#!/usr/bin/env bash
# The first four examples are correct programs.
for f in pointer_basics pass_by_pointer find_node pointer_arithmetic; do
    echo "=== $f"
    g++ -std=c++20 -Wall -Wextra $f.cpp -o $f && ./$f
    rm -f $f
done

# The last three are broken on purpose. AddressSanitizer (-fsanitize=address)
# catches what a normal build would silently get away with.
for f in dangling use_after_free leak; do
    echo "=== $f (plain build)"
    g++ -std=c++20 -Wall -Wextra $f.cpp -o $f && ./$f
    echo "=== $f (with AddressSanitizer)"
    g++ -std=c++20 -g -fsanitize=address $f.cpp -o $f && ./$f
    rm -f $f
done
