#include <stdio.h>
#include <ctype.h>
#define MAXLINE 1000

int getLine(char line[], int maxline);

int main() {
    int len;
    char s[MAXLINE];

    while ((len = getLine(s, MAXLINE)) > 0) {
        int i, x = 0;
        char c;
        for (i = 0; i < len - 1; i++) {
            if (len > 1 && i == 0 && s[0] == '0' &&
                (s[1] == 'x' || s[1] == 'X'))
                ++i;
            else {
                c = s[i];
                int n;
                if (c >= '0' && c <= '9')
                    n = c - '0';
                else if (c >= 'a' && c <= 'f')
                    n = c - 'a' + 10;
                else if (c >= 'A' && c <= 'F')
                    n = c - 'A' + 10;
                x = x * 16 + n;
            }
        }
        printf("%d\n", x);
    }

    return 0;
}

int getLine(char s[], int lim) {
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF &&
        c != '\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}