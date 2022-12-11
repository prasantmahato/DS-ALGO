#include <stdio.h>

void insertData(int arr[], int size, int data)
{
    int tmp_arr[size+1],i=0;
    for(i=0; i<size; i++)
        tmp_arr[i] = arr[i];
        
    tmp_arr[i] = data;
    size += 1;
    for(int i=0; i<size; i++)
        arr[i] = tmp_arr[i];
    arr = tmp_arr;
}

void removeEle(int arr[], int size, int data)
{
    int tmp_arr[size];
    for(int i=0, j=0; i<size; i++)
    {
        
        if(arr[i] == data)
            i++;
        tmp_arr[j] = arr[i];
        j++;
        // if(arr[i] != data)
        // {
        //     tmp_arr[j] = arr[i];
        //     j++;
        // }
        // else
        // {
        //     i++;
        // }
    }
    for(int i=0; i<size; i++)
        arr[i] = tmp_arr[i];

    // arr = tmp_arr;
}

void printSet(int arr[], int size)
{
    for(int i=0; i<size; i++)
        printf("%d ",arr[i]);
}


int main()
{
    int arr[500];
    int size;
    
    
    printf("Enter the size of set: ");
    scanf("%d", &size);
    
    printf("Enter %d elements: \n",size);
    for(int i=0; i<size; i++)
        scanf("%d",&arr[i]);
        
    
    printSet(arr,size);
    
    int ele = 0;
    printf("\nEnter element to remove: ");
    scanf("%d",&ele);
    
    removeEle(arr, size,ele);
    // size -= 1;
    
    printf("\nEnter element to add: ");
    scanf("%d",&ele);
    insertData(arr,size,ele);
    
    printSet(arr,size);
    
    
    return 0;
}