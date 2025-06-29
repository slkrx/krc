#include <stdio.h>

int bitcount (unsigned x);

int main() {
    printf("%d\n", bitcount(0b1011010101011111));
    return 1;
}

int bitcount (unsigned x) {
    int b;

    for (b = 0; x != 0; x &= x - 1)
        ++b;

    return b;
}