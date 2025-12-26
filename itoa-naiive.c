#include <string.h>
#include <stdio.h>
#include <limits.h>
#define MAXLINE 1000

void itoa(int n, char s[]);
void reverse(char s[]);

int main() {
    char s[MAXLINE];
    itoa(INT_MIN, s);
    printf("%s\n", s);
}

void itoa(int n, char s[]) {
    int i, sign;

    if ((sign = n) < 0)
        n = -n;
    i = 0;
    do {
        s[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

void reverse(char s[]) {
    int i, c, temp, len;
    len = strlen(s);
    for (i = 0; i < len / 2; ++i)
        temp = s[i], s[i] = s[len - 1 - i], s[len - 1 - i] = temp;
}