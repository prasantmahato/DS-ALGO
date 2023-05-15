#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

node *create_node(int data){
    node *new_node = (node *)malloc(sizeof(node));
    if(!new_node){
        printf("\nMemory Full, Cannot Allocate.\n");
        exit(0);
    }

    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

int empty(node *start){
    return (start == NULL);
}


void insert(node **start,int data){
    node *new_ptr = (node *)malloc(sizeof(node));
    new_ptr->data = data;
    if(start == NULL){
        new_ptr = *start;
        new_ptr->next = NULL;
    }
    new_ptr->next = *start;
    *start = new_ptr;
}

void delete(node *start){
    if(start == NULL){
        printf("List Empty.!!\n");
        return;
    }
    if(start->next == NULL){
        free(start);
        start = NULL;
        return;
    }
    node *tmp = start;
    node *curr = NULL;
    while(tmp->next != NULL){
        curr = tmp;
        tmp = tmp->next;
    }
    curr->next = NULL;
    free(tmp);
}

int length(node *start){
    if(start == NULL)
        return 0;
    node *tmp = start;
    int cnt = 0;
    while(tmp){
        cnt++;
        tmp=tmp->next;
    }
    return cnt;
}

void nthNodeFromBeg(node *start, int n){
    if(empty(start)){
        printf("\nList Empty.\n");
        return;
    }
    int cnt = 0;
    node *tmp = start;
    while(tmp){
        cnt++;
        if(cnt == n){
            printf("\nNode %d Value from Beg: %d\n",n,tmp->data);
            return;
        }
        tmp = tmp->next;
    }
    printf("\n%d is out of bounds of list.\n",n);    
}

void nthNodeFromEnd(node *start, int n){
    if(empty(start)){
        printf("\nList Empty.\n");
        return;
    }
    int len = length(start);
    
    if(n > len) printf("\n%d index out of bounds\n", n);

    int cnt = 0;
    node *tmp = start;
    while(len-cnt != n){
        cnt++;
        tmp = tmp->next;
    }
    printf("\nNode %d Value from End: %d \n",n, tmp->data);
}

void sortList(node **start){
    if(*start == NULL){
        return;
    }
    for(node *i = *start; i; i=i->next){
        for(node *j=i; j; j=j->next){
            if( i->data > j->data){
                int tmp = i->data;
                i->data = j->data;
                j->data = tmp;
            }
        }
    }
}


void reverse(node **start){
    if(*start == NULL)
        return;
    node *prev, *curr=*start, *forward;
    prev = forward = NULL;
    while(curr != NULL){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    *start = prev;
}


void display(node *start){
    // node *tmp = start;
    // while(tmp != NULL){
    //     printf("%d -> ",tmp->data);
    //     tmp = tmp->next;
    // }
    for(node *tmp = start; tmp; tmp = tmp->next)
        printf("%d -> ",tmp->data);
    printf(" :: NULL\n");
}

node *find_middle(node *start){
    if(start == NULL)
        return NULL;
    node *slow, *fast;
    slow = fast = start;
    while(slow && fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int main(){
    printf("Linked List Program\n");
    // node *start = (node *)malloc(sizeof(node));
    node *start = NULL;
    start = create_node(10);
    insert(&start,10);
    insert(&start,20);
    display(start);
    
    insert(&start,40);
    insert(&start,50);
    insert(&start,60);
    display(start);
    insert(&start,70);
//    insert(&start,80);
    
    delete(start);
    display(start);
    
    delete(start);
    display(start);

    printf("\nLength: %d",length(start));
    nthNodeFromBeg(start,3);
    nthNodeFromEnd(start,4);
    display(start);
    sortList(&start);
    display(start);


    node *mid = find_middle(start);
    printf("\nMiddle Element: %d\n",mid->data);

    reverse(&start);
    display(start);

    return 0;
}
