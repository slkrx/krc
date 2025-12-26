#include <stdio.h>
#include "getint.h"

#define SIZE 100

int main() {
    int n, ret;
    double array[SIZE];

    for (n = 0; n < SIZE && (ret = getfloat(&array[n])) != EOF; n++)
        if (ret == 0)
            n--;
    while (n >= 0)
        printf("%.8g\n", array[n--]);
}