#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "calc.h"

#define MAXOP 100

double vars[27];
void resetvars(void);

int main(int argc, char *argv[]) {
    int type;
    double op2;
    char s[MAXOP];
    resetvars();

    while (--argc) {
        type = getop(*++argv, s);
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case VAR:
                push(vars[s[0]-'a']);
                break;
            case '=':
                op2 = pop();
                vars[(int) pop()] = op2;
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");
                break;
            case '%':
                op2 = pop();
                push((int) pop() % (int) op2);
                break;
            case SIN:
                push(sin(pop()));
                break;
            case EXP:
                push(exp(pop()));
                break;
            case POW:
                op2 = pop();
                push(pow(pop(), op2));
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    op2 = pop();
    printf("\t%.8g\n", op2);
    return 0;
}

void resetvars(void) {
    int i;
    for (i = 0; i < 26; i++)
        vars[i] = i;
}