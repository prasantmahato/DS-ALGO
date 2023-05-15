#include <stdio.h>

void reverse(int num)
{
    int rem=0,rev = 0;
    while(num > 0)
    {
        rem = num%10;
        rev = rev*10 + rem;
        num /= 10;
    }
    printf("Rev: %d\n ",rev);
}

int rev = 0;
int _rev_(int num)
{
    if(num <= 0)
        return rev;
    rev = rev*10 + num%10;
    return _rev_(num/10);
}
int main()
{
    reverse(123);
    int rev_ = _rev_(123);
    printf("Reverse: %d\n",rev_);
    return 0;
}