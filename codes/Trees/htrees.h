#ifndef MYLIB_H
#define MYLIB_H

#include <stdio.h>
#include <stdlib.h>

typedef struct tree{
    int x;
    struct tree* l;
    struct tree* r;
}tree;

typedef struct node{
    tree* addr;
    struct node* next;
}node;

typedef struct queue{
    node* head;
    int size;
}queue;


node* CreateNode(tree* addr);
queue* CreateQueue();
void enq(queue* q,tree* addr);
node* deq(queue* q);
tree* CreateTreeNode(int val);
tree* CreateTree(int* arr,int arrsize);
void preorder(tree* root);
void inorder(tree* root);
void postorder(tree* root);
#endif // MYLIB_H