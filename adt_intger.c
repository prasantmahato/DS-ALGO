#include <stdio.h>

/*
    Abstract Data Type for INTEGER
*/
typedef struct INTEGER{
    int N;
    int incr(int);
};

int incr(int N){
    return N++;
}

void create_integer()
{
    N = (int *)malloc(1*sizeof(int));
}



int main()
{
    printf("It's working.\n");
    return 0;
}