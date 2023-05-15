#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct nodetree{
    int value;
    struct nodetree *left;
    struct nodetree *right;
}nodetree;

nodetree *create_tree(int value){
    nodetree *node = (nodetree *)malloc(sizeof(nodetree));
    if(node != NULL){
        node->left = NULL;
        node->right = NULL;
        node->value = value;
    }
    return node;
}

void printtabs(int level){
    for(int i=0; i<level; i++)
        printf("\t");
}

void display_rec(nodetree *root, int level){
    if(root == NULL){
        printtabs(level);
        printf("----<empty>----\n");
        return;
    }
    printtabs(level);
    printf("VALUE  %d\n",root->value);

    printtabs(level);
    printf("LEFT \n");
    display_rec(root->left, level+1);

    printtabs(level);
    printf("RIGHT \n");
    display_rec(root->right, level+1);
    
        printtabs(level);
    printf("done\n");
}

void display(nodetree *tree){
    // initial level of tree = 0
    display_rec(tree, 0);
}

bool insert_value(nodetree **rootptr, int value){
    nodetree *root = *rootptr;
    
    if(root == NULL){
        *rootptr = create_tree(value);
        return true;
    }
    if(value == root->value){
        // Do nothing with duplicate elements
        return false;
    }else if(value < root->value){
        insert_value(&(root->left), value);
    }else{
        insert_value(&(root->right), value);
    }
    return false;
}

bool search(nodetree *root, int value){
    if(root == NULL)    
        return false;
    
    if(root->value == value)
        return true;
    else if(value < root->value)
        return search(root->left,value);
    else
        return search(root->right, value);
}

int find_height(nodetree *root,int height){
    nodetree *tmp = root;
    if(root == NULL){
        return height;
    }
    return find_height(tmp->left, height+1);
    return find_height(tmp->right, height+1);
}

int CNT=0;
void find_leaf_count(nodetree *root){
    nodetree *tmp = root;
     if(root == NULL){
        return;
    }
    if(root->left == NULL && root->right == NULL){
        ++CNT;
    }
    find_leaf_count(tmp->left);
    find_leaf_count(tmp->right);
}

int max_val(nodetree *root){
    if(root->right == NULL){
        return root->value;
    }
    return max_val(root->right);
}

int min_val(nodetree *root){
    if(root->left == NULL)
        return root->value;
    return min_val(root->left);
}

int path_sum[1000];
int n = 0;
void find_path_sum(nodetree *root, int sum){
    static int i = 0;
    if(root == NULL){
        return;
    }
    if(root->left == NULL && root->right == NULL){
        path_sum[i++] = sum;
        sum = 0;
        n = i;
    }
    sum += root->value;
    find_path_sum(root->left, sum);
    find_path_sum(root->right, sum);
}

int max_sum(){
    for(int i=0; i<n; i++)
        printf("%d ",path_sum[i]);
}

nodetree *get_min_node(nodetree *root){
    while(root){
        root = root->left;
    }
    return root;
}

nodetree *delete_node(nodetree *root, int val){
    if(root == NULL){
        printf("\nKey not found.!\n");
        return NULL;
    }
    if(val < root->value){
        root->left = delete_node(root->left, val);
    }else if(val > root->value){
        root->right = delete_node(root->right, val);
    }else{
        nodetree *tmp = NULL;
        if(root->left == NULL){
            tmp = root->right;
            free(root);
            return tmp;
        }else if(root->right == NULL){
            tmp = root->left;
            free(root);
            return tmp;
        }else{
            tmp = get_min_node(root);
            root->value = tmp->value;
            root->right = delete_node(root->right, tmp->value);
        }
    }
    return root;
}

int generate_random(int lower, int upper){
    int num = (rand() % (upper - lower + 1) + lower);
    return num;
}

void inorder(nodetree *root){
    if(root != NULL){
        inorder(root->left);
        printf("%d ",root->value);
        inorder(root->right);
    }
}

void preorder(nodetree *root){
    if(root != NULL){
        printf("%d ",root->value);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(nodetree *root){
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->value);
    }
}

void destroy(nodetree *root){
    if(root == NULL)
        return;
    destroy(root->left);
    destroy(root->right);
    free(root);
    printf("Memory deallocated.\n");
}

int main(void){
    nodetree *root = NULL;
    int arr[]= {10, 11, 5, 7, 12, 9, 2, 11,131,-3,13,40};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    for(int i=0; i<arr_size; i++){
        int index = generate_random(0,arr_size-1);
        insert_value(&root, arr[index]);
    }


    display(root);
    printf("\nHeight: \t (%d)\n", find_height(root,0));
    find_leaf_count(root);
    printf("LEAF Nodes: \t (%d)\n",CNT);
    
    printf("%d \t (%d)\n", 7,search(root,7));
    printf("%d \t (%d)\n", -3,search(root,-3));
    printf("%d \t (%d)\n", 10,search(root,10));
    printf("%d \t (%d)\n", 122,search(root,122));

    // free(root);

    printf("Inorder: ");
    inorder(root);
    printf("\n");

    printf("Preorder: ");
    preorder(root);
    printf("\n");

    printf("Post-order: ");
    postorder(root);
    printf("\n");
    
    printf("\nMAXIMUM VALUE IN TREE:- %d\n",max_val(root));
    printf("\nMINIMUN VALUE IN TREE:- %d\n",min_val(root));

    find_path_sum(root,0);
    max_sum();

    int key = 0;
    printf("\nEnter a key to delete: ");
    scanf("%d",&key);
    root = delete_node(root, key);
    printf("Inorder: ");
    inorder(root);
    printf("\n");
    
    destroy(root);
    return 0;
}
