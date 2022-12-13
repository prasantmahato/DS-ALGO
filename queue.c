#include <stdio.h>

#define MAX_SIZE 100

typedef struct{
    int data[MAX_SIZE];
    int size;
}QUEUE;

// Initialize queue
void init(QUEUE *q)
{
    q->size = 0;
}

// Check if queue is empty
int isEmpty(QUEUE *q)
{
    return (q->size == 0);
}

// Check if queue is full
int isFull(QUEUE *q)
{
    return (q->size == MAX_SIZE);
}

// Returns first element
int peekFront(QUEUE *q, int *element)
{
    if(isEmpty(q))
        return 0;
    *element = q->data[q->size-1];
    return 1;
}

// Insert element on the queue
void queueInsert(QUEUE *q, int element)
{
    if(isFull(q))
        return;
    for(int i=q->size; i>0; i--)
        q->data[i] = q->data[i-1];
    
    q->data[0] = element;
    q->size++;
}

int queueFront(QUEUE *q,int *element)
{
    if(isEmpty(q))
        return 0;
    q->size--;
    *element = q->data[q->size];
    return 1;
}
void display(QUEUE *q)
{
    printf("\n\t\tQUEUE Elements:\n");
    if(isEmpty(q))
    {
        printf("\n\t\tQueue Empty.!!\n");
        return;
    }
    for(int i=q->size-1; i>=0; i--)
        printf("%d <- ",q->data[i]);
    printf("\n");
}
int main()
{
    QUEUE q1, *q = &q1;
    int element=0;
    init(q);
    
    int choice = 0;
    do
    {
        printf("\n");
        printf("0. Exit\n");
        printf("1. Insert\n");
        printf("2. Remove\n");
        printf("3. Peek Front\n");
        printf("4. Size\n");
        printf("5. Display\n");
        printf("Choose any of the options: ");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter element to insert: ");
            scanf("%d",&element);
            queueInsert(q,element);
            break;
        case 2:
            if(queueFront(q,&element))
                printf("\nElement removed: %d\n",element);
            else
                printf("\n\t\tQueue Empty, Insert First.!!");
            break;
        case 3:
            if(peekFront(q,&element))
                printf("\nFront element: %d\n",element);
            else
                printf("\n\t\tQueue Empty, Insert First.!!");
            break;
        case 4:
            printf("\nSize: %d\n",q->size);
            break;
        case 5:
            display(q);
            break;
        default:
            break;
        }
    } while (choice != 0);
    

    return 0;
}