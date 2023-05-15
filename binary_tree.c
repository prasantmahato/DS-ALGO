#include <stdio.h>
#include <stdlib.h>

#define max_size 20

typedef struct node{
    int val;
    struct node *left, *right;
}node;

int front = 0;
int rear = 0;
node *queue[max_size];

void queue_init(){
    front = rear = 0;
}

int empty(){
    return rear == front;
}

int full(){
    return rear == max_size-1;
}

void enqueue(node *root){
    if(full())
        return;
    queue[rear++]=root;
}

/*
node *create_node(){
    node *ptr;
    int val;
    printf("Enter the data (-1 for no node creation)\t: ");
    scanf("%d", &val);
    if(val == -1)
        return NULL;
    ptr = (node *)malloc(sizeof(node));
    ptr->val = val;
    printf("Enter the left child of %d\n",val);
    ptr->left = create_node();

    printf("Enter the right child of %d\n",val);
    ptr->right = create_node();
    
    return ptr;
}
*/

node *create_node(int val){
    node *new_node = (node *)malloc(sizeof(node));
    new_node->val = val;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

void insert(node **root, int val){
    if(*root == NULL){
        *root = create_node(val);
        return;
    }
    if(val < (*root)->val)
        insert(&((*root)->left), val);
    if(val > (*root)->val)
        insert(&((*root)->right), val);
}

void inorder(node *root){
    if(root == NULL)
        return;
    inorder(root->left);
    printf("%d ",root->val);
    inorder(root->right);
}

void preorder(node *root){
    if(root == NULL)
        return;
    printf("%d ",root->val);
    preorder(root->left);
    preorder(root->right);
}

void postorder(node *root){
    if(root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->val);
}

void bfs(node *root){
    if(root == NULL)
        return;
    queue_init();
    enqueue(root);
    while(1){
        root = queue[front++];
        if(root){
            printf("%d ",root->val);
            if(root->left)
                enqueue(root->left);
            if(root->right)
                enqueue(root->right);
        }else break;
    }
}

int max(int x, int y){
    return x > y ? x : y;
}

int find_height(node *root){
    if(root == NULL)
        return 0;
    return max(find_height(root->left), find_height(root->right)) + 1;
}


int find_diameter(node *root,int *res){
    if(root == NULL)     
        return 0;

    int lh = find_diameter(root->left, res);
    int rh = find_diameter(root->right, res);
    *res = max(*res, lh+rh);
    return 1 + max(lh, rh);
}

int max_path_sum(node *root, int *max_sum){
    if(root == NULL)   return 0;

    int leftSum = max(0,max_path_sum(root->left, max_sum));
    int rightSum = max(0,max_path_sum(root->right, max_sum));

    *max_sum = max(*max_sum, leftSum+rightSum+root->val);

    return root->val + max(leftSum, rightSum);
}

node *find_min(node *root){
    if(root == NULL)
        return NULL;
    if(root->left == NULL)
        return root;
    return find_min(root->left);
}

node *delete_node(node **root, int val){
    if(*root == NULL){
        printf("Item not found.");
        return NULL;
    }
    node *curr = *root;
    if(val < curr->val)
        curr->left = delete_node(&(curr->left), val);
    else if(val > curr->val)
        curr->right = delete_node(&(curr->right), val);
    else{
        if(curr->left == NULL){
            node *tmp = curr->right;
            free(curr);
            return tmp;
        }else if(curr->right == NULL){
            node *tmp = curr->left;
            free(curr);
            return tmp;
        }else{
            node *tmp = find_min(curr->right);
            curr->val = tmp->val;
            curr->right = delete_node(&(curr->right), tmp->val);
        }
    }
    return curr;
}




int main(){
    node *root = NULL;
    // root = create_node();

    insert(&root, 10);
    insert(&root, 8);
    insert(&root, 15);
    insert(&root, 9);
    insert(&root, 12);
    insert(&root, 7);
    insert(&root, 17);
    
    printf("\nInorder: ");
    inorder(root);
    printf("\nPreorder: ");
    preorder(root);
    printf("\nPostorder: ");
    postorder(root);
    printf("\nLevelorder: ");
    bfs(root);
    printf("\n\n");

    printf("\nHeight: %d\n", find_height(root));
    int dia=0;
    int height = find_diameter(root, &dia);
    printf("\nDIAMETER : %d\n", dia);
    int maxPathSum = 0;
    height = max_path_sum(root, &maxPathSum);
    printf("\nMax Path Sum : %d\n", maxPathSum);


    node *tmp = delete_node(&root, 7);
    printf("\nDeleted node: %d\n", tmp->val);
    printf("\nInorder: ");
    inorder(root);


    return 0;
}

