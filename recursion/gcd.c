#include <stdio.h>

int gcd(int x, int y)
{;
    if(x > y)
        return gcd(x-y, y);
    else if(x < y)
        return gcd(x,y-x);
    else
        return x;
}

int _gcd_(int x, int y)
{
    if(x == 0)
        return y;
    return _gcd_(y%x, x);
}

int main()
{
    printf("GCD Difference Method: %d\n",gcd(90,25));
    printf("GCD Euclid Method: %d\n",_gcd_(36,6));
    return 0;
}