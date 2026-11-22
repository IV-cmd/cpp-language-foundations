// This one is broken on purpose: there's no declaration of add() in sight,
// so the compiler stops before the linker even gets a chance.
int main() {
    return add(10, 20);
}
