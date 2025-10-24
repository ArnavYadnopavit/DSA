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
    avl* plr=pl->r;

    pl->r=p;
    p->l=plr;
    p->h=NodeHeight(p);
    pl->h=NodeHeight(pl);

    if(b->root=p) b->root=pl;

    return pl;
}

avl* LRRotation(avl* p,root* b){
    avl* pl=p->l;
    avl* plr=pl->r;

    pl->r=plr->l;
    p->l=plr->r;
    plr->l=pl;
    plr->r=p;
    p->h=NodeHeight(p);
    pl->h=NodeHeight(pl);
    plr->h=NodeHeight(plr);

    if(b->root=p) b->root=plr;

    return plr;
}

avl* RRRotation(avl* p,root* b){
    avl* pr=p->r;
    avl* prl=p->l;

    pr->l=p;
    p->r=prl;
    p->h=NodeHeight(p);
    pr->h=NodeHeight(p);

    if(b->root==p) b->root=pr;
    return pr;

}

avl* RLRotation(avl* p,root* b){
    avl* pr=p->r;
    avl* prl=pr->l;

    prl->l=p;
    prl->r=pr;
    pr->l=prl->r;
    p->r=prl->l;
    prl->h=NodeHeight(prl);
    pr->h=NodeHeight(pr);
    p->h=NodeHeight(p);

    if(b->root==p) b->root=prl;

    return prl;

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
    else if(BalanceFactor(n)==-2 && BalanceFactor(n->r)==1){
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
void inorder(avl* p){
    if(p==NULL) return;
    inorder(p->l);
    printf("%d ", p->x);
    inorder(p->r);
}
void preorder(avl* p){
    if(p==NULL) return;
    printf("%d ", p->x);
    preorder(p->l);
    preorder(p->r);
}

#endif // MYLIB_H