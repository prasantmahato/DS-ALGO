#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TOTAL_STUDENTS 100

typedef struct{
    char srn[30];   // 13 char max, PES1202202967
    char name[30];  
    int sem;
    char sec[3];   // 'A' or 'B'
    char sub[30];
}student;

typedef struct{
    student stu[TOTAL_STUDENTS];
    int top;
}stack;

void print(stack *,int);
int isEmpty(stack *);
int isFull(stack *);
void push(stack *,char [], char [], int, char[], char []);
int pop(stack *);
void display(stack *);



int isEmpty(stack *s)
{
    if(s->top == -1)
        return 1;       // stack empty
    
    return 0;       
}

int isFull(stack *s)
{
    if(s->top == TOTAL_STUDENTS-1)
        return 1;   // stack full
    return 0;
}

void push(stack *s, char srn[], char name[], int sem, char sec[],char sub[])
{
    if(isFull(s))
    {
        printf("\nStack Full..!!\n");
        return;
    }
    ++(s->top);
    
    strcpy(s->stu[s->top].name,name);
    strcpy(s->stu[s->top].srn,srn);
    strcpy(s->stu[s->top].sub, sub);
    strcpy(s->stu[s->top].sec, sec);
    s->stu[s->top].sem = sem;
}

int pop(stack *s)
{
    if(isEmpty(s))
        return -1;
    
    // s->top--;
    // return (s->top);
    printf("\n\t\t\tPopped element: \n");
    print(s,s->top--);
    return 0;
}

int top(stack *s)
{
    if(isEmpty(s))
        return -1;
    
    printf("\n\t\tTop element: \n");
    print(s,s->top);
    return 0;
}

void print(stack *s,int i)
{
        printf("\nStudent Name: %s",s->stu[i].name);
        printf("\nStudent SRN: %s",s->stu[i].srn);
        printf("\nStudent Sec: %s",s->stu[i].sec);
        printf("\nStudent Sem: %d",s->stu[i].sem);
        printf("\nStudent Subject: %s",s->stu[i].sub);
        printf("\n");
}

void display(stack *s)
{
    for(int i=s->top; i>=0; i--)
    {
        printf("\nStudent Name: %s",s->stu[i].name);
        printf("\nStudent SRN: %s",s->stu[i].srn);
        printf("\nStudent Sec: %s",s->stu[i].sec);
        printf("\nStudent Sem: %d",s->stu[i].sem);
        printf("\nStudent Subject: %s",s->stu[i].sub);
        printf("\n\n");
    }
}

int main()
{
    stack s1,*s=&s1;
    s->top =-1;
    student *stu;
    int choice =0;
    
    char srn[13];   // 13 char max, PES1202202967
    char name[25];  
    int sem;
    char sec[3];   // 'A' or 'B'
    char sub[10];
    
    do
    {
        printf("\n");
        printf("0. Exit\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Top\n");
        printf("4. Display\n");
        printf("\nChoose an option: ");
        scanf("%d",&choice);
        
        switch(choice)
        {
            case 1:
                printf("\nEnter Student data to push in stack: \n");
                printf("SECTION: ");  
                scanf("%s",sec);
                printf("SRN: ");  scanf("%s",srn);
                printf("NAME: "); scanf("%s",name);
                printf("SEMESTER: ");  scanf("%d",&sem);
                printf("SUBJECT: ");  scanf("%s",sub);
                // sec = 'A';
                
                push(s,srn,name,sem,sec,sub);
                
                break;
            
            case 2:
                if(pop(s) != -1)
                    printf("\n");
                else
                    printf("\n\t\tSTACK EMPTY\n");
                break;
                
            case 3:
                if(top(s) != -1)
                    printf("\n");
                else
                    printf("\n\t\tSTACK EMPTY\n");
                break;
            
            case 4:
                printf("\n\t\tStack Elements: \n");
                display(s);
                printf("\n");
                break;
                
            default:
                break;
        }
        
    }while(choice != 0);
    return 0;
}


