#include <stdio.h>

void _strcat(char *s, char *t);
int _strend(char *s, char *t);

int main()
{
    char s[] = "hello you? how you? are you?";
    char t[] = "you?";
    printf("%d\n", _strend(s, t));
}

void _strcat(char *s, char *t)
{
    while (*s++)
        ;
    s--;
    while(*s++ = *t++)
        ;
}

int _strend(char *s, char *t)
{
    if (*t == '\0')
        return 1;

    char *u = t;
    while (*s != '\0') {
        while (*s && *u && *s++ == *u++)
            ;
        if (*s == *u && *u == '\0')
            return 1;
        else
            u = t;
    }
    return 0;
}