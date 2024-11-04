#include <stdint.h>

void some_function(void) {
    uint32_t x, y, z;
    x = 100;
    y = 200;
    z = x + y;
    (void)z;

}

int main(void) {
    uint32_t a, b, c;
    a = 15;
    b = 3;
    c = a * b;
    (void)c;  // Suppress unused variable warning

    // Call a function to see the effect on the stack pointer (SP) and link register (LR)
    some_function();

    return 0;
}
