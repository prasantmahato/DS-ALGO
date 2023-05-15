#include <stdio.h>
#include <stdlib.h>

void display(int arr[], int size){
    for(int i=0; i<size; i++)
        printf("%d ",arr[i]);
    printf("\n");
}

void sort(int arr[], int size){
    
}

int main(){
    int arr[] = {3,12,1,3,5,9,10,11,37, 31, 1, 0};
    int size = sizeof(arr)/sizeof(arr[0]);

    return 0;
}