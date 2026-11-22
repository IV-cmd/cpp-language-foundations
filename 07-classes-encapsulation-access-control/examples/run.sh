#!/usr/bin/env bash
# Builds and runs every example, then rebuilds with -DSHOW_ERRORS
# to show the compiler errors the commented-out lines produce.
for f in class_basics encapsulation storage_node init_order; do
    echo "=== $f"
    g++ -std=c++20 -Wall -Wextra $f.cpp -o $f && ./$f
    rm -f $f
done
for f in encapsulation storage_node; do
    echo "=== $f with -DSHOW_ERRORS"
    g++ -std=c++20 -DSHOW_ERRORS -fsyntax-only $f.cpp 2>&1 | grep -E 'error'
done
