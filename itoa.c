#include <stdio.h>
#include <limits.h>
#define MAXLINE 1000

void itoa(int n, char s[]);
int power(int base, int n);

int main() {
    char s[MAXLINE];
    itoa(INT_MAX, s);
    printf("%s\n", s);
}

void itoa(int n, char s[]) {
    int temp, i, j, digit;
    j = 0;

    for (temp = n, i = 0; temp != 0; ++i, temp /= 10)
        ;

    if (n < 0)
        s[j++] = '-';
        
    do {
        --i;
        digit = n / power(10, i);
        s[j++] = (digit < 0 ? digit * -1 : digit) + '0';
        n -= digit * power(10, i);
    } while (i > 0);

    s[j] = '\0';
}

int power(int base, int n) {
    int p;

    for (p = 1; n > 0; n--)
        p = p * base;
    return p;
}