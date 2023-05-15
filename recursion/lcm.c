#include <stdio.h>

int lcm(int a,int b, int max)
{
    if(max % a == 0 && max % b == 0)
        return max;
    ++max;
    return lcm(a,b,max);
}

int gcd(a,b)
{
    if(a==0)
        return b;
    return gcd(b%a, a);
}

int hcf(int a,int b)
{
    while(a!=b)
    {
        if(a>b)
            return hcf(a-b,b);
        else
            return hcf(a,b-a);
    }
    return a;
}

int main()
{
    int a,b;
    a=10, b =8;
    printf("Enter two numbers: ");
    scanf("%d %d",&a,&b);
    int max = a > b ? a : b;
    // int res = lcm(a,b,max);
    int lcm = (a*b)/gcd(a,b);
    printf("LCM: %d\n",lcm);
    return 0;
}