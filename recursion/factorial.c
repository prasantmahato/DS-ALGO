#include <stdio.h>

int factorial(int x)
{
    if(x == 0)
        return 1;
    return x*factorial(x-1);
}

int main()
{
    int x = 0;
    printf("Enter N : ");
    scanf("%d",&x);
    printf("N! = %d\n",factorial(x));
}