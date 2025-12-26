#include <stdio.h>

int rightrotn(unsigned x, unsigned n);
int rightrot(unsigned x);

int main() {
    unsigned x = 0b111001011;
    printf("%u\n", rightrotn(x, 4));
    unsigned y = rightrotn(x,4);
    while (y > 0) {
        putchar(y % 2 + '0');
        y = y / 2;
    }
    putchar('\n');
    return 0;
}

int rightrotn(unsigned x, unsigned n) {
    for (unsigned i = 0; i < n; i++)
        x = rightrot(x);
    return x;
}

int rightrot(unsigned x) {
    unsigned zero = 0;
    unsigned rightbit = ~(~zero << 1) & x;
    if (rightbit == 0)
        return x >> 1;
    else
        return x >> 1 | ~(~zero >> 1);
}