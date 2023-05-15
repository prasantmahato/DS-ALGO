#include <stdio.h>

#define max 15

int max_size;
int max_pr;

int queue[max][max];
int front[max];
int rear[max];

void init(int arr[], int size, int val){
    for(int i=0; i<size; i++)
        arr[i] = val;
}

void insert(int q[][max_pr], int rear[], int pr, int item){
    if(rear[pr] == max_size -1){
        printf("\nQueue Overflow.\n");
        return;
    }
    rear[pr] = rear[pr] + 1;
    q[pr][rear[pr]] = item;
    
}


void display(int q[][max_pr], int rear[], int front[]){
    for(int i=0; i<max_pr; i++){
        if(rear[i] == front[i] - 1)
            printf("\nQueue %d is empty.!!\n", i);
        else{
            printf("Queue %d\n",i);
            for(int j=front[i]; j<rear[i]; j++){
                printf("%d",q[i][j]);
            }
        }
        printf("\n");
    }
}

int main(){
    
    printf("\nEnter Max Size of Queue: ");
    scanf("%d", &max_size);
    printf("\nEnter Max Priority: ");
    scanf("%d", &max_pr);
    
    int queue[max_pr][max_size];
    
    int front[max_pr];
    int rear[max_pr];
    
    init(front,max_pr,0);
    init(rear,max_pr,-1);
    
    insert(queue, rear, 1, 10);
    insert(queue, rear, 1, 40);
    // insert(queue, rear, 2, 20);
    // insert(queue, rear, 0, 30);
    display(queue, rear, front);
        
    
    return 0;
}