#include <stdio.h>
#include <ctype.h>
#define MAXLINE 1000

int getLine(char line[], int maxline);

int main() {
    int len;
    char line[MAXLINE];

    while ((len = getLine(line, MAXLINE - MAXLINE / 10)) > 0) {
        printf("%s", line);
    }

    return 0;
}

int getLine(char s[], int lim) {
    int c, i, j;

    for (i = 0, j = 0; i < lim - 1 && (c = getchar()) != EOF &&
        c != '\n'; ++i, ++j) {
        if (i > 0 && i % 10 == 0 && !isspace(c))
            s[j++] = '\n';
        s[j] = c;
    }
    if (c == '\n') {
        s[j] = c;
        ++j;
    }
    s[j] = '\0';
    return j;
}