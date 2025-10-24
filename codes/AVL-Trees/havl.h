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
    new->h=1;
    new->r=NULL;
}

root* CreateRoot(){
    root* ret=(root*)malloc(sizeof(root));
    ret->root=NULL;
    return ret;
}

int NodeHeight(avl *p){
    int hl,hr;
    hl=p && p->l?p->l->h:0;
    hr=p && p->r?p->r->h:0;
    return hl>hr?hl+1:hr+1;
}

int BalanceFactor(avl *p){
    int hl,hr;
    hl=p && p->l?p->l->h:0;
    hr=p && p->r?p->r->h:0;
    return hl-hr;
}

avl* LLRotation(avl* p,root* b){
    avl* pl=p->l;
    avl* plr=p->r;

    pl->r=p;
    p->l=plr;
    p->h=NodeHeight(p);
    pl->h=NodeHeight(pl);

    if(b->root=p) b->root=pl;

    return pl;
}

avl* LRRotation(avl* p,root* b){
    avl* pl=p->l;
    avl* plr=p->r;

    pl->r=p;
    p->l=plr;
    p->h=NodeHeight(p);
    pl->h=NodeHeight(pl);

    if(b->root=p) b->root=pl;

    return pl;
}

avl* RRRotation(avl* p,root* b){
    avl* pl=p->l;
    avl* plr=p->r;

    pl->r=p;
    p->l=plr;
    p->h=NodeHeight(p);
    pl->h=NodeHeight(pl);

    if(b->root=p) b->root=pl;

    return pl;

}

avl* RLRotation(avl* p,root* b){
    avl* pl=p->l;
    avl* plr=p->r;

    pl->r=p;
    p->l=plr;
    p->h=NodeHeight(p);
    pl->h=NodeHeight(pl);

    if(b->root=p) b->root=pl;

    return pl;

}

avl* RecursiveInsert(avl* n,int x,root* b){
    if(x<n->x){
        if(n->l) RecursiveInsert(n->l,x,b);
        else {
            n->l=CreateAVL(x);
        }
    }
    else{
        if(n->r) RecursiveInsert(n->r,x,b);
        else {
            n->r=CreateAVL(x);
        }
    }
    n->h=NodeHeight(n);
    if(BalanceFactor(n)==2 && BalanceFactor(n->l)==1){
        return LLRotation(n,b);
    }
    else if(BalanceFactor(n)==2 && BalanceFactor(n->l)==-1){
        return LRRotation(n,b);
    }
    else if(BalanceFactor(n)==-2 && BalanceFactor(n->r)==-1){
        return RRRotation(n,b);
    }
    else if(BalanceFactor(n)==-2 && BalanceFactor(n->l)==1){
        return RLRotation(n,b);
    }
    return n;
}

avl* Insert(root *b,int x){
    if(b->root) return RecursiveInsert(b->root,x,b);
    else{ b->root=CreateAVL(x);
        return b->root;
    }
}

#endif // MYLIB_H