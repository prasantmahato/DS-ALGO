#include <stdio.h>
#include <math.h>

int digit_sum(int n)
{
    if(n!=0)
    {
        return (n%10)+digit_sum(n/10);
    }
    return n;
}

int natural_sum(int n)
{
    if(n==1)
        return 1;
    return n+natural_sum(n-1);
}

int check_even_odd(int l_bound,int r_bound)
{
    if(r_bound % 2 == 0)
        printf("%d -> EVEN\n",r_bound);
    else
        printf("%d -> ODD\n",r_bound);

    if(r_bound == l_bound)
        return l_bound;
    return check_even_odd(l_bound,--r_bound);
}

int decimal_to_binary(int n)
{
    if(n == 0)
        return 0;
    return (n%2 + 10 * decimal_to_binary(n/2));
}

int isPrime(int n, int i)
{
    if(n <= 2)
        return (n==2) ? 1 : 0;
    if(n % i == 0)
        return 0;
    if(i*i > n)
        return 1;
    
    return isPrime(n,i+1);
}

void count_digits(int num, int cnt)
{
    if(num != 0)
    {
        cnt++;
    }
    else
    {
        printf("\nCount of digits: %d\n",cnt);
        return;
    }
    return count_digits(num/10,cnt);
}

int main()
{
    int tmp=0;
    // Question 1
    int n=0;
    printf("\nEnter a number: ");
    scanf("%d",&n);
    printf("\nSum of digits: %d\n",digit_sum(n));

    // Question 2
    printf("\nSum(1, %d): %d\n",n,natural_sum(n));
    
    // Question 3
    int l,r;
    printf("\nEnter a lower and upper bound: ");
    scanf("%d %d",&l,&r);
    printf("\nEven Odd in range(%d, %d):\n",l,r);
    tmp = check_even_odd(l,r);

    // Question 4 Decimal to binary 
    printf("\nEnter number to get it's binary: ");
    scanf("%d",&n);
    tmp=decimal_to_binary(n);
    printf("\n(%d) in binary: %d", n, tmp);
    printf("\n");

    printf("\nEnter a number to check prime: ");
    scanf("%d",&n);
    if(isPrime(n,2) == 1)
        printf("\nIts an prime number..\n");
    else
        printf("\nIt's not an prime number.\n");
    
    printf("\nEnter a number to count digits: ");
    scanf("%d",&n);
    count_digits(n,0);


    int ch = 0,n=0;
    do{
        printf("0. Exit\n");
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
        
        switch (ch)
        {
        case 1:
            printf("\nEnter number of disk: ");
            scanf("%d",n);
            tower_of_hanoi(n,'A','B','C');
            break;
        
        
        default:
            break;
        }
    }while(ch != 0);
    return 0;
}
