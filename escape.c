#include <stdio.h>

#define MAXLINE 1000

int getLine(char s[], int lim);
void escape(char s[], char t[], int lim);

int main() {
    char s[MAXLINE], t[MAXLINE];

    getLine(s, MAXLINE);
    escape(s, t, MAXLINE);
    printf("%s\n", t);
}

void escape(char s[], char t[], int lim) {
    int i, j;
    for (i = 0, j = 0; s[i] != '\0' && j < lim - 2; ++i, ++j)
        switch (s[i]) {
            case '\t':
                t[j++] = '\\';
                t[j] = 't';
                break;
            case '\n':
                t[j++] = '\\';
                t[j] = 'n';
                break;
            case '\\':
            case '\?':
            case '\'':
            case '\"':
                t[j++] = '\\';
            default:
                t[j] = s[i];
                break;
        }
    t[j] = '\0';
}

int getLine(char s[], int lim) {
    int i, c;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF; i++)
        s[i] = c;
    
    s[i] = '\0';

    return i;
}