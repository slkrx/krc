#define NUMBER '0'
#define SIN '1'
#define EXP '2'
#define POW '3'
#define VAR '4'

void push(double);
double pop(void);
int getop(char[], char []);
int getch(void);
void ungetch(int);