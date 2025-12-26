#include <stdio.h>

#define swap(t,x,y) t temp = x; x = y, y = temp

int main() {
    int a = 1, b = 2;
    swap(int, a, b);
    printf("%d\n", a);
}