#include <stdio.h>
#include <math.h>
int bsearch(int A[], int p, int q, int v);

int main() {
    int A[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27};
    int v = 0;
    printf("%d\n",bsearch(A,0,26,v));
}

int bsearch(int A[], int p, int q, int v) {
    if (p > q || q < p) return -1;

    int m = p + ceil((q - p)/2.0);

    if (A[m] == v)
        return m;
    else if (A[m] > v)
        return bsearch(A, p, m - 1, v);
    else
        return bsearch(A, m + 1, q, v);
}