#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;

Node *create_stack()
{
    return NULL;
}

int empty(Node *stack)
{
    return(stack==NULL);
}

void push(Node **stack, int data)
{
    Node *new_node = (Node *)malloc(sizeof(Node));

    new_node->data = data;
    new_node->next = *stack;
    *stack=new_node;
}

int pop(Node **stack)
{
    if(empty(*stack))
        return -1;
    
    int data = (*stack)->data;
    
    Node *current = *stack;
    *stack = (*stack)->next;
    free(current);

    return data;
}

int top(Node *stack)
{
    if(empty(stack))
        return -1;
    
    return stack->data;
}

int size(Node *stack)
{
    if(empty(stack))
        return -1;

    int len=0;
    while(stack)
    {
        len++;
        stack = stack->next;
    }
    return len;
}

void display(Node *stack)
{
    while(stack)
    {
        printf("\n%d",stack->data);
        stack = stack->next;
    }
    printf("\n");
}

int main()
{
    Node *stack=create_stack();
    int choice = 0,data;
    do
    {
        printf("\n");
        printf("0. Exit\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Top\n");
        printf("4. Size\n");
        printf("5. Display\n");
        printf("Choose any of the options: ");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter data to push(): ");
            scanf("%d",&data);
            push(&stack,data);
            break;
        case 2:
            data = pop(&stack);
            if(data != -1)
            {
                printf("\nPopped Element: %d\n",data);
            }
            else
            {
                printf("\nStack Empty.!!\n");
            }
            break;
        case 3:
            printf("\nTop element: %d\n",top(stack));
            break;
        case 4:
            printf("\nStack size: %d\n",size(stack));
        case 5:
            printf("\nStack Elements: ");
            display(stack);
        default:
            break;
        }

    } while (choice != 0);

    printf("\n");
    return 0;
}