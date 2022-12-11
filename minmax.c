#include <stdio.h>
void min_max(int arr[], int n, int val[])
{
    int min=arr[0],max=arr[0];

    for(int i = 0; i<n; i++)
    {
        if(arr[i] < min)
            min = arr[i];
        else
            max = arr[i];
    }
    val[0] = min;
    val[1] = max;
}
int main()
{
    int size;
    printf("\nEnter array size: ");
    scanf("%d",&size);

    int arr[size];
    printf("\nEnter array elements: ");
    for(int i=0; i<size; i++)
        scanf("%d",&arr[i]);

    int res[2];
    min_max(arr,size, res);
    printf("\nMin: %d\nMax: %d\n",res[0],res[1]);
    return 0;
}