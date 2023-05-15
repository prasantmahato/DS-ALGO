#include <stdio.h>

int find_largest(int arr[], int n,int max)
{
    if(n==0)
        return max;
    if(arr[n] > max)
        max = arr[n];
    return find_largest(arr,--n,max);

}

int main()
{
    int n=10;
    int arr[]= {1,2,3,4,45,6,7,8,8,9};

    int max=find_largest(arr,n,arr[0]);
    printf("MAx: %d\n",max);
    return 0;
}