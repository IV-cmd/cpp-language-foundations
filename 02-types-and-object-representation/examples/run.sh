#!/usr/bin/env bash
# Builds and runs every example in this folder.
set -e
for f in sizes integer_traps object_representation struct_layout; do
    echo "=== $f"
    g++ -std=c++20 -Wall -Wextra $f.cpp -o $f && ./$f
    rm -f $f
done
