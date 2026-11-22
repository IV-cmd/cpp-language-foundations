#!/usr/bin/env bash
# Builds and runs every example, then rebuilds each one with -DSHOW_ERRORS
# to show the compiler errors the commented-out lines produce.
for f in reference_basics pass_by_reference value_categories; do
    echo "=== $f"
    g++ -std=c++20 -Wall -Wextra $f.cpp -o $f && ./$f
    rm -f $f
done
for f in reference_basics pass_by_reference value_categories; do
    echo "=== $f with -DSHOW_ERRORS"
    g++ -std=c++20 -DSHOW_ERRORS -fsyntax-only $f.cpp 2>&1 | grep -E 'error|warning'
done
