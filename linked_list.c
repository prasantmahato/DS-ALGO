#include <stdio.h>
#include <stdlib.h>

typedef struct list{
    int data;
    struct list *next;
}list;

void print(struct list *head_ref)
{
    printf("\n[");
    list *tmp = head_ref;
    while(tmp != NULL)
    {
        printf("%d, ",tmp->data);
        tmp = tmp->next;
    }
    printf("]\n");
}

// Insert values from end of the list
void append(list **head, int data)
{
    struct list *new_list = (struct list *)malloc(sizeof(struct list));
    struct list *last = *head;

    new_list->data=data;
    new_list->next=NULL;

    if(*head == NULL)
    {
        *head = new_list;
        return;
    }
    while(last->next != NULL)
        last = last->next;
    
    last->next = new_list;
    return;
}

// Insert elements from front of the list 
void push(struct list **head, int data)
{

    struct list *new_list = (struct list *)malloc(sizeof(struct list));
    new_list->data = data;
    new_list->next = *head;
    *head = new_list;
}

// Function to insert element after a giver position
void insertPos(struct list **head, int data, int pos)
{
    if(*head == NULL)
    {
        printf("List cannot be empty.!!");
        return;
    }
    struct list *tmp = *head;
    struct list *new_num = (struct list *)malloc(sizeof(struct list));
    int i=0;
    while(tmp != NULL)
    {
        if(i+1 == pos)
        {
            new_num->data = data;
            new_num->next = tmp->next;
            tmp->next = new_num;
            break;
        }
        i++;
        tmp = tmp->next;
    }
    
}

void remove_element(struct list **head, int data)
{
    if(*head == NULL)
    {
        printf("\nList cannot be empty.!!");
        return;
    }
    struct list *prev_ele,*curr = *head;
    
    while(curr != NULL && curr->data != data)
    {   
        prev_ele = curr;
        curr = curr->next;
    }
    prev_ele->next = curr->next;
    free(curr);
}

int find_pos(struct list *head, int data)
{
    if(head == NULL)
    {
        printf("\nList cannot be NULL");
        return -1;
    }
    struct list *tmp = head;
    int i=0;
    while(tmp != NULL)
    {
        if(tmp->data == data)
        {
            return i+1;     // Return the position of the element
        }
        i++;
        tmp = tmp->next;
    }

    return -1;      // Return -1 when element is not found

}

int main()
{
    list *head = (struct list *)malloc(sizeof(struct list));
    head = NULL;

    int choice = 0;
    int element,pos;
    element=pos=0;
    do
    {
        printf("\n0. Exit ");
        printf("\n1. Create list(push). ");
        printf("\n2. Append element.");
        printf("\n3. Insert after a position.");
        printf("\n4. Search element.");
        printf("\n5. Remove element.");
        printf("\n6. Print list.");
        printf("\nChoose an option: ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter element: ");
            scanf("%d",&element);
            push(&head,element);
            break;
        case 2:
            printf("\nEnter element to append: ");
            scanf("%d",&element);
            append(&head,element);
            break;
        case 3:
            printf("\nEnter (Data, Pos) to insert: ");
            scanf("%d %d",&element,&pos);
            insertPos(&head,element,pos);
            break;
        case 4:
            printf("\nEnter element to search: ");
            scanf("%d",&element);
            int pos = find_pos(head, element);
            if(pos != -1)
                printf("Element Found at position: %d\n",pos);
            else
                printf("Element Not Found.\n");
            break;
        case 5:
            printf("\nEnter element to remove: ");
            scanf("%d",&element);
            remove_element(&head, element);
            printf("\nUpdated List: ");
            print(head);
            break;
        case 6:
            print(head);
            break;
        default:
            break;
        }
    } while (choice != 0);

    return 0;
}