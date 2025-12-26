#include <stdio.h>
#include <limits.h>
#define MAXLINE 1000

void itob(int n, char s[], int b);
int power(int base, int n);

int main() {
    char s[MAXLINE];
    itob(11517691, s, 2);
    printf("%s\n", s);
}

void itob(int n, char s[], int b) {
    int temp, i, j, digit;
    j = 0;

    for (temp = n, i = 0; temp != 0; ++i, temp /= b)
        ;

    if (n < 0)
        s[j++] = '-';
        
    do {
        --i;
        digit = n / power(b, i);
        if (digit < 0)
            digit *= -1;
        if (digit > 9)
            s[j++] = digit - 10 + 'A';
        else
            s[j++] = digit + '0';
        n -= digit * power(b, i);
    } while (i > 0);

    s[j] = '\0';
}

int power(int base, int n) {
    int p;

    for (p = 1; n > 0; n--)
        p = p * base;
    return p;
}