#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 10
#define ll long long

int count = 0;

typedef struct Node{
    int data;
    struct Node *next;
}Node;

typedef struct queue{
    Node *front, *rear;
}queue;


Node *create_node(int data){
    Node *node = (struct Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

queue *create_q(){
    queue *q = (struct queue *)malloc(sizeof(queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(queue *q, int data){
    Node *tmp = create_node(data);

    if(q->rear == NULL){
        q->front = q->rear = tmp;
    }

    q->rear->next = tmp;
    q->rear = tmp;
    count++;
}

void dequeue(queue *q){
    if(q->front == NULL){
        printf("\nQueue Empty\n");
        return;
    }
    Node *tmp = q->front;
    q->front = q->front->next;

    if(q->front == NULL){
        q->rear = NULL;
    }
    free(tmp);
    count--;
}

void display(queue *q){
    if(q->front == NULL && q->rear == NULL){
        printf("\nQueue Empty\n");
        return;
    }
    Node *tmp = q->front;
    while(tmp != NULL){
        printf("%d ",tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
}

int main(void){

    queue *q = create_q();

    for(int i=0; i<MAX_SIZE; i++){
        enqueue(q,i*12 - 3);

    }
    // enqueue(q,20);
    // enqueue(q,30);
    // enqueue(q,40);
    display(q);
    printf("\nTotal Elements: %d\n",count);

    return 0;
}
