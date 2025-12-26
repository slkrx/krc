#include <stdio.h>
#include "../_getline.c"

#define MAXLINE 1000

int _getline(char [], int);
char *detab(char *, int);
char *entab(char *, int);

int main(int argc, char *argv[])
{
    char s[MAXLINE];

    while(_getline(s, MAXLINE))
        printf("%s", entab(s, 8));
}

char *detab(char *s, int n)
{
    static char t[MAXLINE];
    int i, j;

    for (i = 0, j = 0; s[i] != '\0'; i++)
        if (s[i] == '\t') {
            t[j++] = ' ';
            while(j % n != 0)
                t[j++] = ' ';
        }
        else
            t[j++] = s[i];
    t[j] = '\0';

    return t;
}

char *entab(char *s, int n)
{
    static char t[MAXLINE];
    int i, j, k;

    for (i = 0, j = 0; s[i] != '\0'; )
        if (s[i] == ' ' && i % (n - 1) != 0) {
            k = i;
            while (s[++k] == ' ' && k % n != 0)
                ;
            if (k % n == 0) {
                t[j++] = '\t';
                i = k;
            }
            else
                while (i < k)
                    t[j++] = s[i++];
        }
        else
            t[j++] = s[i++];
    t[j] = '\0';

    return t;
}