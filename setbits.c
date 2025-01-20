#include <stdio.h>

int setbits(int x, int p, int n, int y);

int main() {
    int x = 0b100111000;
    int y = 0b101010111;
    printf("%d\n", setbits(x, 6, 3, y));
    return 0;
}

int setbits(int x, int p, int n, int y) {
    return x & (~0 >> (p - n) | ~0 << (p + 1)) | (y << (p - n + 1)) & ~(~0 << (p + 1));
}