#include <stdio.h>

int any(char s1[], char s2[]);
int contains(char s[], char c);

int main() {
    char s1[] = "the quick brown fox";
    char s2[] = "xfq";
    printf("%d\n", any(s1,s2));
    return 0;
}

int any(char s1[], char s2[]) {
    char c;
    for (int i = 0; (c = s1[i]) != '\0'; i++)
        if (contains(s2, c))
            return i;
    return -1;
}

int contains(char s[], char c) {
    for (int i = 0; s[i] != '\0'; i++)
        if (s[i] == c)
            return 1;
    return 0;
}