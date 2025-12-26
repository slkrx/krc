#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXOP 100
#define NUMBER '0'
#define SIN '1'
#define EXP '2'
#define POW '3'
#define VAR '4'

int getop(char []);
void push(double);
double pop(void);
void resetvars(void);

double vars[27];

int main() {
    int type;
    double op2;
    char s[MAXOP];
    resetvars();

    while ((type = getop(s)) != EOF) {
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
            case '\n':
                op2 = pop();
                printf("\t%.8g\n", op2);
                resetvars();
                vars[26] = op2;
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}

void resetvars(void) {
    int i;
    for (i = 0; i < 26; i++)
        vars[i] = i;
}

#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

void push(double f) {
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

double pop(void) {
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

double peek(void) {
    if (sp > 0)
        return val[sp - 1];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

void dup(void) {
    if (sp > 0)
        val[sp++] = peek();
    else 
        printf("error: stack empty\n");
}

void swap(void) {
    double temp;
    if (sp > 1)
        temp = val[sp-2], val[sp-2] = val[sp-1], val[sp-1] = temp;
    else 
        printf("error: not enough elements\n");
}

void clear(void) {
    sp = 0;
}

#include <ctype.h>

int getch(void);
void ungetch(int);

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

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}