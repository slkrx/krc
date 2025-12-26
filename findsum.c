#include <stdio.h>
#include <math.h>

int findsum(int A[], int x, int n);

int main() {
    int A[] = {23, 45, 68, 73, 89, 93, 102, 113};
    int x = 113;
    printf("%d\n",findsum(A,x,8));
}

int findsum(int S[], int x, int n) {
    int i = 0, j = n - 1;

    while (i < j)
        if (S[i] + S[j] == x)
            return 1;
        else if (S[i] + S[j] < x)
            ++i;
        else
            --j;
    return 0;
}