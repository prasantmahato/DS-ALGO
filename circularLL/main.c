#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int val;
    struct node *next;
}node;

node *create_node(int data){
    node *newptr = (node *)malloc((unsigned)sizeof(node));
    newptr->val = data;
    newptr->next = NULL;   
    return newptr;
}
/*
void insert(node **last, int val){
    node *newnode = create_node(val);
    if(*last == NULL){
        *last->next = *last;
        last->val = val;
        return;
    }
    newnode->next = *last->next;
    *last->next = newnode;

}
*/
void before(node **last,int key_val,int val){
    if(last == NULL){
        printf("\nCLL empty()");
        return;
    }
    node *newnode = (node *)malloc(sizeof(node));
    newnode->val = val;
    node *curr = *last, *prev = NULL;
    while(curr->val != key_val && curr->next != *last){
        prev = curr;
        curr = curr->next;
    }
    if(curr == *last){
        printf("\n%d not found in CLL",key_val);
        return;
    }
    newnode->next = curr;
    prev->next = newnode;
}
void display(node *last){
    node *curr = last->next;
    while(curr != last){
        printf("%d -> ", curr->val);
        curr = curr->next;
    }
    printf(" %d \n",curr->val);
}
int main(){
    node *last = NULL;
    node *a,*b,*c;
    a = create_node(10);
    b = create_node(20);
    //c = create_node(30);
    a->next = b;
    //b->next = c;
    b->next = a;
    //c->next = a;
    last=b;
    display(last);

    before(&last, 20, 44);
    display(last);
    printf("\nLast Value:- %d", last->next->val);
    return 0;
}
