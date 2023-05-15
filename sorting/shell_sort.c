#include <stdio.h>
#include <stdlib.h>

void display(int arr[], int size){
    for(int i=0; i<size; i++)
        printf("%d ",arr[i]);
    printf("\n");
}

void sort(int arr[], int size){
    for(int gap=size/2; gap>0; gap /= 2){
        for(int i=gap; i<size; i++){
            int tmp = arr[i],j=0;
            for(j=i; j >= gap && arr[j-gap] > tmp; j -= gap){
                arr[j] = arr[j-gap];
            }
            arr[j] = tmp;
        }
    }
}

int main(){
    int arr[] = {3,12,1,3,5,9,10,11,37, 31, 1, 0};
    int size = sizeof(arr)/sizeof(arr[0]);
    display(arr,size);
    sort(arr,size);
    display(arr,size);
    return 0;
}