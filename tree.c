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
        printf("LEVEL:: %d\n",level);
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

int main(void){

    nodetree *n1 = create_tree(10);
    nodetree *n2 = create_tree(20);
    nodetree *n3 = create_tree(30);
    nodetree *n4 = create_tree(40);
    nodetree *n5 = create_tree(50);
    nodetree *n6 = create_tree(60);

    n1->left = n2;
    n1->right = n3;
    n2->left = n6;
    n3->left = n4;
    n3->right = n5;

    /*
            10
          /   \    
        20      30
      /       /   \
    60      40      50    
    
    */

   display(n1);
   free(n1);
   free(n2);
   free(n3);
   free(n4);
   free(n5);
   free(n6);
    return 0;
}