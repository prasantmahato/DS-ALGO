#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 50

typedef struct{
    char item[MAX_SIZE];
    int top;
}stack;

// Funtion declarations
int isEmpty(stack *);
int isFull(stack *);
void push(stack *, char);
void display(stack *);
char pop(stack *);
char peek(stack *);


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

char peek(stack *s)
{
    if(s->top >= 0 && s->top < MAX_SIZE)
        return s->item[s->top];
    return -1;
}

void push(stack *s, char data)
{
    if(isFull(s) == 1)
    {
        printf("\nStack Full, Cannot push element.!");
        return;
    }
    s->item[++s->top] = data;
}

char pop(stack *s)
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
    // printf("Stack Elements: \n");
    for(int i = s->top; i>=0; i--)
    {
        printf("%c\t",s->item[i]);
    }
    printf("\n");
}

int main()
{
    stack s1,s2;
    stack *s = &s1, *s_tmp =  &s2;
    s->top = -1;    // No elements in stack
    s_tmp->top = -1;

    const char *expr="(()))((())))))";
    char ch;
    int flag = 0;

    // printf("\nEnter the brackets expression: ");
    // scanf("%s",expr);

    for(int i=0; expr[i]!='\0'; i++)
    {
        display(s);
        if(expr[i] == '(')
            push(s,expr[i]);
        else
        {
            ch = pop(s);
            if(ch == -1)
            {
                flag = 1;
                break;
            }
        }
    }

    printf("\n");

    if(s->top == -1 && flag == 1)
        printf("Unbalaced.!!\n");
    else
        printf("Balanced.!!\n");

    return 0;
}