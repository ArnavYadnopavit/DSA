#include<stdio.h>
#include<stdlib.h>
#include "hbst.h"
#define SIZE 10

int main(){
    BST* bst=CreateBST();
    int arr[]={2,6,4,7,3,9,10,8,19,0};
    for(int i=0;i<SIZE;i++){
        Insert(bst,arr[i]);
    }
    preorder(bst->root);
    printf("\n");
    inorder(bst->root);
    printf("\n");
    postorder(bst->root);
    printf("\n");
}