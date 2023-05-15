#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

void display(int arr[], int size){
    for(int i=0; i<size; i++)
        printf("%d ",arr[i]);
    printf("\n");
}

void init_arr(int arr[], int size){
    for(int i=0; i<size; i++)
        arr[i] = 0;
}

void sort(int arr[], int size){
    int i=0, max = arr[0];
    for(i=0; i<size; i++){
        if(arr[i] > max)
            max = arr[i];
    }
    max += 1;
    int count[max];
    init_arr(count,max);
    for(i=0; i<size; i++){
        ++count[arr[i]];
    }
    display(count, size);
    int j=0;
    for(i=0; i<=max; i++){
        while(count[i] > 0){
            arr[j] = i;
            count[i]--;
            j++;
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