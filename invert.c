#include <stdio.h>

int invert (int x, int p, int n);

int main() {
    int x = 0b10110111;
    printf("%d\n", invert(x, 5, 3));
    return 0;
}

int invert (int x, int p, int n) {
    return ~x & (~0 << (p - n + 1) & ~(~0 << (p + 1)))
        | x & ~(~0 << (p - n + 1) & ~(~0 << (p + 1)));
}