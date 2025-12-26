#include <stdio.h>
#include <ctype.h>
#include "getint.h"

int getint(int *pn)
{
    int c, sign;

    while (isspace(c = getch()))
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-') {
        c = getch();
        if (!isdigit(c)) {
            ungetch(c);
            return 0;
        }
    }
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    return c;
}

int getfloat(double *px)
{
    int c, sign;
    double power;
    
    while (isspace(c = getch()))
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-') {
        c = getch();
        if (!isdigit(c)) {
            ungetch(c);
            return 0;
        }
    }
    for (*px = 0.0; isdigit(c); c = getch())
        *px = *px * 10.0 + (c - '0');
    if (c == '.') 
        c = getch();
    for (power = 1.0; isdigit(c); c = getch()) {
        *px = 10.0 * *px + (c - '0');
        power *= 10;
    }
    *px = sign * *px / power;
    if (c != EOF)
        ungetch(c);
    return c;
}