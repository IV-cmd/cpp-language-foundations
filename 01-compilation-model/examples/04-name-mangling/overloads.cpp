// Two functions named add. The linker needs two different symbol names.
int add(int a, int b) { return a + b; }
double add(double a, double b) { return a + b; }

// C linkage: no mangling, so C code (or dlsym) can find it as plain "c_add".
// The catch: you can't overload an extern "C" function.
extern "C" int c_add(int a, int b) { return a + b; }
