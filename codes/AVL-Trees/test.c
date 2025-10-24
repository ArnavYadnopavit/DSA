#include <stdio.h>
#include <stdlib.h>

typedef struct avl
{
    struct avl* r;
    struct avl* l;
    int h;
    int x;
}avl;

typedef struct root{
    avl* root;
}root;

root* CreateRoot(){
    root* ret=(root*)malloc(sizeof(root));
    ret->root=NULL;
    return ret;
}

avl* CreateAvl(int x){
    avl* ret=(avl*)malloc(sizeof(avl));
    ret->l=NULL;
    ret->r=NULL;
    ret->h=1;
    ret->x=x;
    return ret;
}

int AvlHeight(avl* p){
    if(p==NULL){
        return 0;
    }
    avl* pl=p->l;
    avl* pr=p->r;
    return AvlHeight(pl)>AvlHeight(pr)?AvlHeight(pl)+1:AvlHeight(pr)+1;
}

int Balance(avl* p){
    return AvlHeight(p->l)-AvlHeight(p->r);
}

avl* LLRotation(avl* p,root* b){
    avl* pl=p->l;
    avl* plr=pl->r;

    p->l=pl->r;
    pl->r=p;
    p->h=AvlHeight(p);
    pl->h=AvlHeight(pl);

    if(b->root==p) b->root=pl;

    return pl;
    
}

avl* LRRotation(avl* p,root* b){
    avl* pl=p->l;
    avl* plr=pl->r;

    p->l=plr->r;
    pl->r=plr->l;
    plr->l=pl;
    plr->r=p;
    p->h=AvlHeight(p);
    pl->h=AvlHeight(pl);
    plr->h=AvlHeight(plr);

    if(b->root==p) b->root=plr;

    return plr;
    
}

avl* RLRotation(avl* p,root* b){
    avl* pr=p->r;
    avl* prl=pr->l;

    p->r=prl->l;
    pr->l=prl->r;
    prl->l=p;
    prl->r=pr;
    p->h=AvlHeight(p);
    pr->h=AvlHeight(pr);
    prl->h=AvlHeight(prl);

    if(b->root==p) b->root=prl;

    return prl;
    
}

avl* RRRotation(avl* p,root* b){
    avl* pr=p->r;
    avl* prl=pr->l;

    p->r=pr->l;
    pr->l=p;
    p->h=AvlHeight(p);
    pr->h=AvlHeight(pr);

    if(b->root==p) b->root=pr;

    return pr;
    
}

avl* Rinsert(avl* p,int x,root* b){
    if(p == NULL)
        return CreateAvl(x);

    if (x < p->x)
        p->l = Rinsert(p->l, x, b);
    else
        p->r = Rinsert(p->r, x, b);
    p->h=AvlHeight(p);

    if(Balance(p)==2 && Balance(p->l)==1){
        return LLRotation(p,b);
    }
    else if(Balance(p)==2 && Balance(p->l)==-1){
        return LRRotation(p,b);
    }
    else if(Balance(p)==-2 && Balance(p->r)==1){
        return RLRotation(p,b);
    }
    else if(Balance(p)==-2 && Balance(p->r)==-1){
        return RRRotation(p,b);
    }

    return p;
}

void InsertAvl(root* b,int x){
    b->root = Rinsert(b->root, x, b);
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

int main(){
    root* b=CreateRoot();
    InsertAvl(b,50);
    InsertAvl(b,20);
    InsertAvl(b,10);
    inorder(b->root);
    printf("\n");
    preorder(b->root);
    printf("\n");
}
