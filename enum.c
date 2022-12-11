#include <stdio.h>

enum datatype { CHAR=1, INT=2, FLOAT=4, DOUBLE=8};

int main()
{
    // char *type="INT";
    // scanf("%s",type);
    enum datatype dt=FLOAT;
    printf("%d\n",dt);
    return 0;
}