#include <stdio.h>

int product(int a, int b)
{
    if(b == 1)
        return a;
    return product(a,b-1) + a;
}

int main()
{
    int a=5,b=1;
    printf("Enter a,b : ");
    scanf("%d %d",&a,&b);
    printf("Product of (%d x %d) : %d\n",a,b,product(a,b));
    return 0;
}