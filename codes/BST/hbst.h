#ifndef MYLIB_H
#define MYLIB_H

// Include standard libraries if needed
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    struct node* l;
    int x;
    struct node* r;
}node;

typedef struct BST{
    node* root;
}BST;

node* CreateNode(int val);
BST* CreateBST();
void RecursiveInsert(node* n,int x);
void Insert(BST *b,int x);
void preorder(node* root);
void inorder(node* root);
void postorder(node* root);
#endif // MYLIB_H