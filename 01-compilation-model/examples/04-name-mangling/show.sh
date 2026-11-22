#!/usr/bin/env bash
set -x
g++ -c overloads.cpp -o overloads.o
nm overloads.o          # mangled names
nm -C overloads.o       # demangled (-C runs them through c++filt)
rm -f overloads.o
