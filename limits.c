#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
    printf("char bits:\t%d\n", CHAR_BIT);
    printf("char min:\t%d\n", CHAR_MIN);
    printf("char max:\t%d\n", CHAR_MAX);

    printf("schar min:\t%d\n", SCHAR_MIN);
    printf("schar max:\t%d\n", SCHAR_MAX);

    printf("uchar max:\t%d\n", UCHAR_MAX);

    printf("int min:\t%d\n", INT_MIN);
    printf("int max:\t%d\n", INT_MAX);
    printf("uint max:\t%u\n", UINT_MAX);
    
    printf("long min:\t%ld\n", LONG_MIN);
    printf("long max:\t%ld\n", LONG_MAX);
    printf("ulong max:\t%lu\n", ULONG_MAX);
    
    printf("short min:\t%d\n", SHRT_MIN);
    printf("short max:\t%d\n", SHRT_MAX);
    printf("ushort max:\t%d\n", USHRT_MAX);

    printf("float min:\t%f\n", FLT_MIN);
    printf("float max:\t%f\n", FLT_MAX);

    printf("double min:\t%f\n", DBL_MIN);
    printf("double max:\t%f\n", DBL_MAX);
}