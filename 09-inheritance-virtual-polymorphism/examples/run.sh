#!/usr/bin/env bash
# Builds and runs every example, then rebuilds with -DSHOW_ERRORS
# to show the compiler errors the commented-out lines produce.
for f in inheritance virtual_dispatch abstract; do
    echo "=== $f"
    g++ -std=c++20 -Wall -Wextra $f.cpp -o $f && ./$f
    rm -f $f
done

echo "=== vtables in virtual_dispatch.o"
g++ -std=c++20 -c virtual_dispatch.cpp -o virtual_dispatch.o
nm -C virtual_dispatch.o | grep -E 'vtable for (StorageNode|SSDNode|HDDNode)'
rm -f virtual_dispatch.o

echo "=== virtual_destructor (non-virtual destructor, broken)"
g++ -std=c++20 -Wall -Wextra virtual_destructor.cpp -o virtual_destructor && ./virtual_destructor
echo "=== virtual_destructor with AddressSanitizer"
g++ -std=c++20 -g -fsanitize=address virtual_destructor.cpp -o virtual_destructor && ./virtual_destructor 2>&1 | grep -E 'delete|~|ERROR|object passed|size of|SUMMARY'
echo "=== virtual_destructor -DFIXED"
g++ -std=c++20 -Wall -Wextra -DFIXED virtual_destructor.cpp -o virtual_destructor && ./virtual_destructor
rm -f virtual_destructor

for f in inheritance abstract; do
    echo "=== $f with -DSHOW_ERRORS"
    g++ -std=c++20 -DSHOW_ERRORS -fsyntax-only $f.cpp 2>&1 | grep -E 'error|note:.*(pure|because)'
done
