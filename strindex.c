#include <string.h>

int strindex(char s[], char t[]) {
    int i, j, k;

    for (i = 0; s[i] != '\0'; i++) {
        for (j=i, k=0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0')
            return i;
    }
    return -1;
}

int rstrindex(char s[], char t[]) {
    int i, j, k;

    for (i = strlen(s) - 1; i >= 0; i--) {
        for (j = i, k = strlen(t) - 1; k >= 0 && s[j] == t[k]; j--, k--)
            ;
        if (k < 0)
            return j + 1;
    }
    return -1;
}