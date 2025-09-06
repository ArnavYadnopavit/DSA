#include<stdio.h>
#include<stdlib.h>
#include "hbst.h"

node* CreateNode(int val){
    node* new=(node*)malloc(sizeof(node));
    new->l=NULL;
    new->x=val;
    new->r=NULL;
}

BST* CreateBST(){
    BST* ret=(BST*)malloc(sizeof(BST));
    ret->root=NULL;
    return ret;
}

void RecursiveInsert(node* n,int x){
    if(x<n->x){
        if(n->l) RecursiveInsert(n->l,x);
        else {
            n->l=CreateNode(x);
            return;
        }
    }
    else{
        if(n->r) RecursiveInsert(n->r,x);
        else {
            n->r=CreateNode(x);
            return;
        }
    }
}

void Insert(BST *b,int x){
    if(b->root) RecursiveInsert(b->root,x);
    else b->root=CreateNode(x);
}


void preorder(node* root){
    if(root){
        printf("%d ",root->x);
        preorder(root->l);
        preorder(root->r);
    }
}

void inorder(node* root){
    if(root){
        inorder(root->l);
        printf("%d ",root->x);
        inorder(root->r);
    }
}

void postorder(node* root){
    if(root){
        postorder(root->l);
        postorder(root->r);
        printf("%d ",root->x);
    }
}