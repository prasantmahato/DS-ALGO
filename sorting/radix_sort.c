#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int val;
    struct node *next;
}node;

// Function declarations
node *create_node(int val);
void init(node *start[], int size);
void insert(node **start, int val);
void display(int arr[], int size);
void display_list(node *start[],int size);
int find_cnt_digits(int num);
int find_max(int arr[], int size);
void sort(int arr[], int size, int max);



void init(node *start[], int size){
    for(int i=0; i<size; i++){
        start[i] = NULL;
    }
}

node *create_node(int val){
    node *newnode = (node *)malloc((unsigned)(sizeof(node)));
    newnode->val = val;
    newnode->next = NULL;
    return newnode;
}

void insert(node **start, int val){
    node *newnode = create_node(val);
    if(*start == NULL){
        *start = newnode;
        return;
    }
    node *curr = *start;
    while(curr){
        curr = curr->next;
    }
    curr->next = newnode;
    newnode->next = NULL;
}

void display(int arr[], int size){
    for(int i=0; i<size; i++)
        printf("%d ",arr[i]);
    printf("\n");
}

int find_cnt_digits(int num){
    int cnt = 1;
    while(num > 0){
        num/=10;
        cnt++;
    }
    return cnt;
}

int find_max(int arr[], int size){
    int max = arr[0];
    for(int i=0; i<size; i++){
        if(arr[i] > max)
            max = arr[i];
    }
    return max;
}

void sort(int arr[], int size, int max){
    node *map[max];
    init(map, max);

    int i=0;
    int digit_cnt = find_cnt_digits(max);
    for(i=0; i<size; i++){
        int j = 0;
        while(i == arr[j] % 10){
            insert(&map[i],arr[j]);
            j++;
        }
    }
    display_list(map,max);
}

void display_list(node *start[],int size){
    for(int i=0; i<size; i++){
        node *curr = start[i];
        printf("%d | ",i);
        while(curr){
            printf("%d -> ", curr->val);
            curr = curr->next;
        }
        printf(":: NULL\n");
    }
}

int main(){
    int arr[] = {3,12,1,3,5,9,10,11,37, 31, 1, 0};
    int size = sizeof(arr)/sizeof(arr[0]);

    display(arr,size);
    int max = find_max(arr, size);
    sort(arr,size, max);
    display(arr,size);

    return 0;
}