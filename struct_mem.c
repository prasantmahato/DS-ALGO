#include <stdio.h>

typedef struct memory
{
    int a;
    char b;
    char c;
    double d;
    // int x;
}memory;

int main()
{
    memory m1;

    printf("%d\n",sizeof(m1));
    printf("%lu\n",&(m1.a));
    printf("%lu\n",&(m1.b));
    printf("%lu\n",&(m1.c));
    printf("%lu\n",&(m1.d));
    // printf("%lu\n",&(m1.x));
    return 0;
}
