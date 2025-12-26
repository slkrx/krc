#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

int getLine(char s[], int lim);

void expand(char s1[], char s2[], int lim);

int main() {
    int len;
    char s1[MAXLINE], s2[MAXLINE];

    while (getLine(s1, MAXLINE)) {
        expand(s1, s2, MAXLINE);
        printf("%s\n", s2);
    }
}

void expand(char s1[], char s2[], int lim) {
    int i, j, k;

    for (i = 0, j = 0; i < strlen(s1); ++i) {
        if (s1[i] == 'a' && i < strlen(s1) - 2 && s1[i + 1] == '-' && s1[i + 2] == 'z') {
            i += 2;
            for (k = 0; k < 26 && j < lim; ++k, ++j)
                s2[j] = 'a' + k;
        }
        else if (s1[i] == 'A' && i < strlen(s1) - 2 && s1[i + 1] == '-' && s1[i + 2] == 'Z') {
            i += 2;
            for (k = 0; k < 26 && j < lim; ++k, ++j)
                s2[j] = 'A' + k;
        }
        else if (s1[i] == '0' && i < strlen(s1) - 2 && s1[i + 1] == '-' && s1[i + 2] == '9') {
            i += 2;
            for (k = 0; k < 10 && j < lim; ++k, ++j)
                s2[j] = '0' + k;
        }
        else
            s2[j++] = s1[i];
    }
    s2[j] = '\0';
}

int getLine(char s[], int lim) {
    int i, c;

    for (i = 0; (c = getchar()) != EOF && c != '\n' && i < lim - 1; ++i)
        s[i] = c;

    if (c == '\n')
        s[i++] = '\n';
    
    s[i] = '\0';

    return i;
}