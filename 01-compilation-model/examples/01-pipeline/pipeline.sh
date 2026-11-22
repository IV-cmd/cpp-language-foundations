#!/usr/bin/env bash
# Walks through every stage of the pipeline one at a time.
# Run it from this folder: ./pipeline.sh
set -x

g++ -E main.cpp -o main.i          # A. preprocess only
g++ -S main.cpp -o main.s          # B. compile to assembly
g++ -c main.cpp -o main.o          # C. compile + assemble to object files
g++ -c calculator.cpp -o calculator.o
file main.o calculator.o

g++ main.o calculator.o -o myapp   # D. link
./myapp; echo "exit status: $?"    # E. run

nm main.o                          # F. look at the symbols
nm calculator.o

g++ main.o -o broken               # G. linker error: add() has no definition
g++ -c no_declaration.cpp          # H. compiler error: add() was never declared

rm -f main.i main.s *.o myapp broken
