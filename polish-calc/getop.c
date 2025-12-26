#include <ctype.h>
#include <stdio.h>
#include "calc.h"

int getop(char s[]) {
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (c == '-') {
        if (isdigit(c = getch()) || c == '.') {
            s[1] = c;
            i = 1;
        } else {
            ungetch(c);
            return s[0];
        }
    } else if (c == 's') {
        if ((s[1] = getch()) == 'i')
            if ((s[2] = getch()) == 'n')
                return SIN;
            else {
                ungetch(s[2]);
                ungetch(s[1]);
            }
        else
            ungetch(c);
        s[1] = '\0';
        return VAR;
    } else if (c == 'e') {
        if ((s[1] = getch()) == 'x')
            if ((s[2] = getch()) == 'p')
                return EXP;
            else {
                ungetch(s[2]);
                ungetch(s[1]);
            }
        else
            ungetch(c);
        s[1] = '\0';
        return VAR;
    } else if (c == 'p') {
        if ((s[1] = getch()) == 'o')
            if ((s[2] = getch()) == 'w')
                return POW;
            else {
                ungetch(s[2]);
                ungetch(s[1]);
            }
        else
            ungetch(c);
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
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}