#include <stdio.h>

int i=1;

void tower_of_hanoi(int n,char A, char B, char C)
{
    if(n==1)
    {
        printf("%d.\t %d \t %c \t %c\n",i,n,A,C);
        i++;
        return;
    }
    tower_of_hanoi(n-1,A,C,B);
    printf("%d.\t %d \t %c \t %c \n",i,n,A,C);
    i++;
    tower_of_hanoi(n-1,B,A,C);
}

int main()
{
    int n;
    printf("\nEnter no of disks: ");
    scanf("%d",&n);
    printf("\nThe Tower of Hanoi:\n");
    printf("Call.\tDisk No\t Src\t Dest\n");
    tower_of_hanoi(n,'A','B','C');
    return 0;
}