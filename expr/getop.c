#include <ctype.h>
#include <stdio.h>
#include "calc.h"

int getop(char t[], char s[]) {
    int i, c;

    c = *s = *t;
    s[1] = '\0';
    if (c == '-') {
        if (isdigit(c = *++t) || c == '.') {
            s[1] = c;
            i = 1;
        } else
            return s[0];
    } else if (c == 's') {
        if ((s[1] = *++t) == 'i')
            if ((s[2] = *++t) == 'n')
                return SIN;
            else {
                --t;
                --t;
            }
        else
            --t;
        s[1] = '\0';
        return VAR;
    } else if (c == 'e') {
        if ((s[1] = *++t) == 'x')
            if ((s[2] = *++t) == 'p')
                return EXP;
            else {
                t--;
                t--;
            }
        else
            t--;
        s[1] = '\0';
        return VAR;
    } else if (c == 'p') {
        if ((s[1] = *++t) == 'o')
            if ((s[2] = *++t) == 'w')
                return POW;
            else {
                t--;
                t--;
            }
        else
            t--;
        s[1] = '\0';
        return VAR;
    } else if (isalpha(c)) {
        return VAR;
    } else if (c == '^') {
        s[0] = 'z' + 1;
        return VAR;
    } else if (!isdigit(c) && c != '.')
        return c;
    else
        i = 0;
    if (isdigit(c))
        while (isdigit(s[++i] = c = *++t))
            ;
    if (c == '.')
        while (isdigit(s[++i] = c = *++t))
            ;
    s[i] = '\0';
    return NUMBER;
}