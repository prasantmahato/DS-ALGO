#include <stdio.h>

#define max_size 5

int queue[max_size];
int front;
int rear;

// enum init = {zeroZero, zeroMinusOne, minusOneZero, minusOneminusOne};
int curr;

void create_queue(int fr, int rr){
    if(fr == 0 && rr == 0)
        curr = 0;
    else if(fr == 0 && rr == -1)
        curr = 1;
    else if(fr == -1 && rr == 0)
        curr = 2;
    else
        curr = 3;
    
    front = fr;
    rear = rr;
}

int isEmpty(){
    if(curr == 0 || curr == 3)
        return (front == rear);
    else if(curr == 1)
        return (front > rear);
    else
        return (front < rear);
}

int isFull(){
    if(curr == 0 || curr == 2)
        return(rear == max_size);
    else 
        return(rear == max_size-1);
}

void insert(int item){
    if(!isFull()){
        if(curr == 0 || curr == 2){  
            queue[rear++] = item; 
        }else if(curr == 1 || curr == 3){ 
            queue[++rear] = item; 
        }
    }else{
        printf("\nQUEUE OVERFLOW\n");
        return;
    }
}

void delete_q(){
    if(isEmpty()){
        
    if(curr == 2 || curr == 3)
        queue[++front];
    else
        queue[front++];
    }else{
        printf("\nQUEUE UNDERFLOW\n");
        return;
    }
}

int dequeue(){
    if(curr == 2 || curr == 3)
        return queue[++front];
    else
        return queue[front++];
}

void display(){
    
    if(!isEmpty()){
        int i=0;
        if(curr == 0){
            for(i=front; i<rear; i++)
                printf("| %d ",queue[i]);
        }
        else if(curr == 1){
            for(i=front; i<=rear; i++)
                printf("| %d ",queue[i]);
        }
        else if(curr == 2){
            for(i=front+1; i<rear; i++)
                printf("| %d ",queue[i]);
        }
        else{
            for(i=front+1; i<=rear; i++)
                printf("| %d ",queue[i]);
        }
        printf("| \n");
    }else{
        printf("Queue Empty\n");
    }
}

void requeue()
{
    insert(dequeue());
}

int main(){
    int fr,rr;
    printf("\nEnter Front and Rear value: ");
    scanf("%d %d",&fr, &rr);
    create_queue(fr,rr);
    int ch, item=0;
    do{
        printf("\n0. Exit\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Requeue \n");
        printf("4. Dequeue\n");
        printf("5. Display\n");
        printf("Choose an option: ");
        scanf("%d",&ch);
        
        switch(ch){
            case 1: 
                printf("\nEnter item to insert: ");
                scanf("%d",&item);
                insert(item);
                break;
            case 2:
                delete_q();
                break;
            case 3:
                requeue();
                break;
            case 4:
                printf("\nThe item removed: %d\n",dequeue());
                break;
            case 5:
                printf("\n\t\t\tQueue Elements: \n");
                display();
                break;
            default:
                break;
        }
    }while(ch != 0);
    
    return 0;
}
