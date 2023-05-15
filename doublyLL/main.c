#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int val;
    struct node *next, *prev;
}node;

node *create_node(int val){
    node *newnode = (node *)malloc((unsigned)(sizeof(node)));
    newnode->val = val;
    newnode->next = NULL;
    newnode->prev = NULL;
    return newnode;
}

void display(node *start){
    node *tmp = start;
    printf("NULL ");
    while(tmp){
        printf(" <- %d ->",tmp->val);
        tmp = tmp->next;
    }
    printf(" NULL\n\n");
}

// Inserts data in front of the list
void insert(node **start, int val){
    node *new_node = create_node(val);
    new_node->next = (*start);
    new_node->prev = NULL;
 
    if ((*start) != NULL)
        (*start)->prev = new_node;
 
    (*start) = new_node;
}

// Inserts data at end of the list
void push(node **start, int val){
    node *new_node = (node *)malloc((unsigned)(sizeof(node)));
    new_node->val = val;
    new_node->next = NULL;

    if(start == NULL){
        new_node->prev = NULL;
        *start = new_node;
        return;
    }
    node *curr = *start;
    while(curr->next){
        curr=curr->next;
    }
    curr->next = new_node;
    new_node->prev = curr;
}

void insert_middle(node **start, int val){
    if(*start == NULL){
        printf("\nList Empty.!");
        return;
    }
    node *curr, *fast;
    curr = fast = *start;
    while(fast!=NULL && fast->next!=NULL){
        curr = curr->next;
        fast = fast->next->next;
    }
    printf("\nMiddle Element: %d\n", curr->val);
    node *newnode = create_node(val);
    newnode->prev = curr->prev;
    newnode->next = curr;
    curr->prev->next = newnode;
    curr->prev = newnode;
}

void delete(node **start, int val){
    if(*start == NULL){
        printf("\nList Empty");
        return;
    }
    node *prev = NULL,*curr=*start;
    while(curr!=NULL && curr->val != val ){
        prev = curr;
        curr=curr->next;
    }
    if(curr == NULL){
        printf("\nElement not found.!\n");
        return;
    }
    prev->next = curr->next;
    curr->next->next->prev = prev;
    printf("\nItem deleted is: %d\n",curr->val);
    free(curr);
}

void sort(node **start){
    if(*start == NULL)
        return;
    int tmp = 0;
    for(node *i = *start; i; i = i->next){
        for(node *j = i; j; j = j->next){
            if(i->val > j->val){
                tmp = i->val;
                i->val = j->val;
                j->val = tmp;
            }
        }
    }
}

void reverse(node **start){
    if(*start == NULL)
        return;
    node *tmp, *curr = *start;
    while(curr){
        tmp = curr->prev;
        curr->prev = curr->next;
        curr->next = tmp;
        curr = curr->prev;
    }
    if(tmp != NULL)
        *start = tmp->prev;
}

int main(){
    node *start = NULL;
    insert(&start, 10);
    insert(&start, 20);
    insert(&start, 30);
    insert(&start, 40);
    insert(&start, 50);
    insert(&start, 60);
    display(start);

    push(&start, 33);
    push(&start, 36);
    
    display(start);
    // delete(&start, 30);
    display(start);
    // delete(&start, 220);
    insert_middle(&start, 22);
    display(start);
    reverse(&start);
    display(start);
    sort(&start);
    display(start);


    return 0;
}