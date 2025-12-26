#include <stdio.h>
#include <string.h>

void itoa(int n, char s[]);
void _itoa(int n, char s[], int i);
void reverse(char s[], int left, int right);
void swap(char s[], int i, int j);

int main()
{
    char s[1000];
    itoa(-12345, s);
    printf("%s\n", s);
}

void itoa(int n, char s[])
{
    _itoa(n, s, 0);
    reverse(s, 0, strlen(s) - 1);
}

void _itoa(int n, char s[], int i)
{
    if (n / 10)
        _itoa(n / 10, s, i + 1);
    else
        if (n < 0) {
            s[i+1] = '-';
            s[i+2] = '\0';
        } else
            s[i+1] = '\0';
    n = n < 0 ? n * -1 : n;
    s[i] = n % 10 + '0';
}

void reverse(char s[], int left, int right)
{
    if (left >= right)
        return;
    reverse(s, left + 1, right - 1);
    swap(s, left, right);
}

void swap(char s[], int i, int j) {
    char temp = s[i];
    s[i] = s[j];
    s[j] = temp;
}