#!/usr/bin/env bash
# Same a.cpp and b.cpp, built twice with a different header swapped in.
set -x

# Broken: both translation units define globalCounter -> multiple definition.
g++ -DCOUNTER_HEADER='"counter_bad.hpp"' a.cpp b.cpp -o odr_bad

# Fixed: header only declares it, counter.cpp defines it once.
g++ -std=c++17 -DCOUNTER_HEADER='"counter_good.hpp"' a.cpp b.cpp counter.cpp -o odr_good
./odr_good; echo "exit status: $?"

rm -f odr_bad odr_good
