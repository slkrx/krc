#include <stdio.h>

void squeeze(char s[], char c[]);
int contains(char s[], char c);

int main() {
    char s1[] = "hi hello hi";
    char s2[] = "hello";
    squeeze(s1, s2);
    printf("%s\n", s1);
    return 0;
}

void squeeze(char s[], char c[]) {
    int i, j;
    for (i = j = 0; s[i] != '\0'; i++)
        if (!contains(c, s[i]))
            s[j++] = s[i];
    s[j] = '\0';
}

int contains(char s[], char c) {
    for (int i = 0; s[i] != '\0'; i++)
        if (s[i] == c)
            return 1;
    return 0;
}