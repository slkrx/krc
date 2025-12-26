#include <stdio.h>
#define MAXLEN 1000

int getArray(int a[]);

int main() {
    int len;
    int a[MAXLEN];

    while ((len = getArray(a)) > 0) {
        int j;
        for (j = 1; j < len; ++j) {
            int key,i;
            for(key = a[j], i = j - 1; i >= 0 && a[i] > key; --i)
                a[i + 1] = a[i];
            a[i + 1] = key;
        }
        int i = 0;
        while (i < len - 1)
            printf("%d, ", a[i++]);
        printf("%d\n", a[i]);
    }
}

int getArray(int a[]) {
    int c;
    int i = 0;
    a[0] = 0;

    while ((c = getchar()) != EOF && c != '\n') {
        if (c == ',')
            a[++i] = 0;
        else
            a[i] = 10 * a[i] + (c - '0');
    }

    if (c == '\n' && a[i] > 0)
        ++i;

    return i;
}