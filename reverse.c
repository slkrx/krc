#include <stdio.h>
#define MAXLINE 1000

void reverse(char result[], char s[], int len);
int getLine(char line[], int maxline);

int main() {
    int len;
    char line[MAXLINE], reversed[MAXLINE];

    while ((len = getLine(line, MAXLINE)) > 0) {
        reverse(reversed,line,len);
        printf("%s\n", reversed);
    }
}

int getLine(char s[], int lim) {
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    s[i] = '\0';
    return i;
}

void reverse(char result[], char s[], int len) {
    int i;

    for (i = 0; i < len; ++i)
        result[i] = s[len - 1 - i];
    result[i] = '\0';
}