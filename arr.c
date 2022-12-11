#include <stdio.h>

float sum(float list[], int n)
{
    float temp_sum = 0;
    int i=0;
    for(i=0; i<n; i++)
        temp_sum += list[i];
    return temp_sum;
}
float r_sum(float list[], int n)
{
    if (n)
        return r_sum(list, n-1) + list[n-1];
    return 0;
}
void print(float list[], int n)
{
    for(int i=0; i<n; i++)
        printf("%.2f ",list[i]);
}
int main()
{
    float arr[]={1,2,7,8,9};
    int size = sizeof(arr)/sizeof(float);

    print(arr,size);
    printf("\n");

    // float tot=sum(arr,size);
    float tot=r_sum(arr,size);
    printf("%.0f\n",tot);
    return 0;   
}