#include <stdio.h>

void tower_of_hanoi(int n,char A,char B, char C)
{
    if(n == 1){
        printf("%d. %c %c\n",n,A,C);
        return;
    }
    tower_of_hanoi(n-1, A, C, B);
    printf("%d. %c %c\n",n,A,C);
    tower_of_hanoi(n-1,B,A,C);
}


int fact(int n)
{
    if(n == 1)
        return 1;
    return n*fact(n-1);
}

int fib_sum(int n)
{
    if(n == 1 || n == 2)
        return 1;
    return fib_sum(n-1) + fib_sum(n-2);
}

int gcd(int a, int b)
{
    if(a == 0)
        return b;
    return gcd(b%a, a);
}

int reverse(int n, int rev)
{
    if (n <= 0)
        return rev;
    rev = rev*10 + n%10;
    return reverse(n/10,rev);
}

int digit_cnt(int n,int cnt)
{
    if(n<=0)
        return cnt;
    cnt++;
    return digit_cnt(n/10, cnt);
}

int digit_sum(int n, int sum)
{
    if(n<= 0)
        return sum;
    sum += n%10;
    return digit_sum(n/10,sum);
}

int dec_to_bin(int n)
{
    if(n == 0)
        return 0;
    return (n%2 + 10 * dec_to_bin(n/2));
}

int main()
{
    // tower_of_hanoi(3,'A','B','C');
    // printf("\nFact of 5: %d",fact(5));
    // printf("\nFib of 5: %d",fib_sum(8));
    // printf("\nGCD: %d",gcd(90,25));
    // printf("\nRev of 501: %d",reverse(501,0));
    // printf("\nDigits Count: %d",digit_cnt(9025,0));
    // printf("\nDigits sum: %d",digit_sum(9025,0));
    // printf("\nBinary num of %d: %d",12,dec_to_bin(12));
    
    int ch = 0,n=0;
    int a,b;
    do{
        printf("\n0. Exit\n");
        printf("1.  Tower of Hanoi.\n");
        printf("2.  Factorial.\n");
        printf("3.  Fibonacci Sum.\n");
        printf("4.  GCD.\n");
        printf("5.  Revese a num.\n");
        printf("6.  Sum of Digits.\n");
        printf("7.  Total Num of Digits.\n");
        printf("8.  Decimal To Binary.\n");
        printf("Choose a option: ");
        scanf("%d",&ch);
        
        switch(ch)
        {
            case 1: 
                printf("\nEnter number of disk: ");
                scanf("%d",&n);
                tower_of_hanoi(n,'A','B','C');
                printf("\n");
                break;
            case 2:
                printf("\nEnter the number: ");
                scanf("%d",&n);
                printf("\nFactorial: %d\n",fact(n));
                break;
            case 3:
                printf("\nEnter the number: ");
                scanf("%d",&n);
                printf("\nFibonacci Sum: %d\n",fib_sum(n));
                break;
            case 4:
                printf("\nEnter 2 numbers: ");
                scanf("%d %d",&a,&b);
                printf("\nGCD(%d,%d): %d\n",a,b,fib_sum(n));
                break;
            case 5:
                printf("\nEnter the number: ");
                scanf("%d",&n);
                printf("\nReverse: %d\n",reverse(n,0));
                break;
            case 6:
                printf("\nEnter the number: ");
                scanf("%d",&n);
                printf("\nSum of Digits: %d\n",digit_sum(n,0));
                break;
            case 7:
                printf("\nEnter the number: ");
                scanf("%d",&n);
                printf("\nTotl no. of Digits: %d\n",digit_cnt(n,0));
                break;
            case 8:
                printf("\nEnter the number: ");
                scanf("%d",&n);
                printf("\nBinary Equivalent: %d\n",dec_to_bin(n));
                break;
            default:
                break;
        }
    }while(ch != 0);
    
    
    return 0;
}