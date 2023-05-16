#include <stdio.h>

long long int i=1;

void tower_of_hanoi(int n,char A, char B, char C)
{
    if(n==1)
    {
        printf("%ld. %c %c\n",n,A,C);
        return;
        //i++;
    }
    tower_of_hanoi(n-1,A,C,B);
    printf("%ld. %c %c \n",n,A,C);
    //i++;
    tower_of_hanoi(n-1,B,A,C);
}

int main()
{
    int n;
    printf("\nEnter no of disks: ");
    scanf("%d",&n);
    printf("\nThe Tower of Hanoi:\n");
    tower_of_hanoi(n,'A','B','C');
    return 0;
}