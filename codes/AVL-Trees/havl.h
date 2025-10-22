#ifndef MYLIB_H
#define MYLIB_H

// Include standard libraries if needed
#include <stdio.h>
#include <stdlib.h>

typedef struct avl{
    int x;
    int h;
    struct avl* l;
    struct avl* r;
}avl;

typedef struct root{
    avl *root;
}root;

avl* CreateAVL(int val){
    avl* new=(avl*)malloc(sizeof(avl));
    new->l=NULL;
    new->x=val;
    new->h=0;
    new->r=NULL;
}

root* CreateRoot(){
    root* ret=(root*)malloc(sizeof(root));
    ret->root=NULL;
    return ret;
}

void RecursiveInsert(avl* n,int x){
    if(x<n->x){
        if(n->l) RecursiveInsert(n->l,x);
        else {
            n->l=CreateAVL(x);
            return;
        }
    }
    else{
        if(n->r) RecursiveInsert(n->r,x);
        else {
            n->r=CreateAVL(x);
            return;
        }
    }
}

void Insert(root *b,int x){
    if(b->root) RecursiveInsert(b->root,x);
    else b->root=CreateAVL(x);
}

#endif // MYLIB_H