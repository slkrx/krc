#include <stdio.h>
#include "utils.h"
#define MAXLINE 1000

int main() {
    char line[MAXLINE];

    while (getLine(line, MAXLINE) > 0)
        printf("%f\n", atof(line));
}