#include <stdio.h>

int binsearch(int x, int v[], int n);

int main() {
    int v[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
    int x = 10;
    int n = 13;
    printf("%d\n", binsearch(x, v, n));
    return 0;
}

int binsearch(int x, int v[], int n) {
    int low, high, mid;

    low = 0;
    high = n - 1;
    mid = (low + high) / 2;
    while (low <= high && v[mid] != x) {
        mid = (low + high) / 2;
        if (x < v[mid])
            high = mid + 1;
        else
            low = mid + 1;
    }
    if (v[mid] == x)
        return mid;
    else
        return -1;
}