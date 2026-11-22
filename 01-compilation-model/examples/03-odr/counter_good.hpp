#pragma once

// Fix 1: declare here, define in exactly one .cpp (counter.cpp).
extern int globalCounter;

// Fix 2 (C++17): an inline variable may appear in many TUs; the linker keeps one.
inline int inlineCounter = 0;
