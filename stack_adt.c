#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct{
    int item[MAX_SIZE];
    int top;
}stack;

// Funtion declarations
int isEmpty(stack *);
int isFull(stack *);
void push(stack *,int);
void display(stack *);
int pop(stack *);


// 1 = True & 0 = False
int isEmpty(stack *s)
{
    if(s->top == -1)
        return 1;   // stack empty
    else
        return 0;
}

int isFull(stack *s)
{
    if(s->top >= MAX_SIZE-1)
        return 1;   // stack full
    else
        return 0;
}

void push(stack *s, int data)
{
    if(isFull(s) == 1)
    {
        printf("\nStack Full, Cannot push element.!");
        return;
    }
    s->item[++s->top] = data;
}

int pop(stack *s)
{
    if(isEmpty(s) == 1)
    {
        printf("\nStack Empty.!!");
        return -1;
    }
    return s->item[s->top--];
}

void display(stack *s)
{
    printf("Stack Elements: \n");
    for(int i = s->top; i>=0; i--)
    {
        printf("%d\t",s->item[i]);
    }
    printf("\n");
}

int main()
{
    stack *s1,s;

    s1 = &s;
    s1->top = -1;     // Stack top = -1, stack is empty

    for(int i=1; i<MAX_SIZE+1; i++)
    {
        push(s1, i*3);
    }
    display(s1);

    printf("\nPopped element: %d\n",pop(s1));
    display(s1);
    printf("\nPopped element: %d\n",pop(s1));
    display(s1);
    printf("\nPopped element: %d\n",pop(s1));
    display(s1);

    return 0;
}

