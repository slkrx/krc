#include <stdio.h>

int day_of_year(int year, int month, int day);
void month_day(int, int, int *, int *);
char *month_name(int n);

int main() {
    printf("%d\n", day_of_year(2025, 12, 17));
    int month, day;
    month_day(2025, 351, &month, &day);
    printf("%d/%d\n", month, day);
    printf("%s\n", month_name(12));
}

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day)
{
    int i, leap;

    if (year < 0 || month < 0 || day < 0 || month > 12 || day > 31)
        return 0;

    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    for (i = 1; i < month; i++)
        day += *(*daytab + 12 * leap + i);
    return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i, leap;

    if (yearday < 0 || yearday > 366) {
        *pmonth = 0;
        *pday = 0;
        return;
    }

    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    for (i = 1; yearday > *(*daytab + 12 * leap + i); i++)
        yearday -= *(*(daytab + leap) + i);
    *pmonth = i;
    *pday = yearday;
}

char *month_name(int n)
{
    static char *name[] = {
        "Illegal month", "January", "February",
        "March", "April", "May", "June", "July",
        "August", "September", "October",
        "November", "December"
    };

    return (n < 1 || n > 12) ? name[0] : name[n];
}