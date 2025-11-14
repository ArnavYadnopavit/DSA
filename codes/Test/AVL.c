#include <stdio.h>
#include <stdlib.h>

typedef struct avl{
    int x;
    struct avl* l;
    struct avl* r;
    int h;
}avl;

typedef struct root{
    avl* root;
}root;

avl* CreateAvl(int x){
    avl* p=(avl*)malloc(sizeof(avl));
    p->l=NULL;
    p->r=NULL;
    p->h=1;
    p->x=x;
    return p;
}

root* CreateRoot(){
    root* b=(root*)malloc(sizeof(root));
    b->root=NULL;
    return b;
}

int AvlHeight(avl* p){
    if(p==NULL) return 0;
    int hl=AvlHeight(p->l);
    int hr=AvlHeight(p->r);
    return hl>hr?hl+1:hr+1;
}

int Bal(avl* p){
    return AvlHeight(p->l)-AvlHeight(p->r);
}

avl* LLRot(avl* p,root* b){
    avl* pl=p->l;
    avl* plr=pl->r;
    
    p->l=plr;
    pl->r=p;
    p->h=AvlHeight(p);
    pl->h=AvlHeight(pl);
    
    if(b->root==p) b->root=pl;
    
    return pl;
}

avl* LRRot(avl* p,root* b){
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

avl* RLRot(avl* p,root* b){
    avl* pr=p->r;
    avl* prl=pr->l;
    
    p->r=prl->l;
    pr->l=prl->r;
    prl->l=p;
    prl->r=pr;
    
    if(b->root==p) b->root=prl;
    
    return prl;
}

avl* RRRot(avl* p,root* b){
    avl* pr=p->r;
    avl* prl=pr->l;
    
    p->r=prl;
    pr->l=p;
    p->h=AvlHeight(p);
    pr->h=AvlHeight(pr);
    if(b->root==p) b->root=pr;
    return pr;
}

avl* Rinsert(avl* p,int x,root* b){
    if(p==NULL){
        return CreateAvl(x);
    }
    else if(p->x<x){
        p->r=Rinsert(p->r,x,b);
    }
    else if(p->x>x){
        p->l=Rinsert(p->l,x,b);
    }
    
    p->h=AvlHeight(p);
    printf("%d\n",p->x);
    if (Bal(p)==2 && Bal(p->l)==1){
        printf("hi\n");
        return LLRot(p,b);
    }
    else if(Bal(p)==2 && Bal(p->l)==-1){
        return LRRot(p,b);
    }
    else if(Bal(p)==-2 && Bal(p->r)==1){
        return RLRot(p,b);
    }
    else if(Bal(p)==-2 && Bal(p->r)==-1){
        return RRRot(p,b);
    }
    
    return p;
}

root* AvlInsert(root* b, int x){
    if (b->root==NULL){
        b->root=CreateAvl(x);
        return b;
    }
    else{
        b->root=Rinsert(b->root,x,b);
        return b;
    }
}

void preorder(avl* p){
    if (p==NULL) return;
    printf("%d ",p->x);
    preorder(p->l);
    preorder(p->r);
}

void inorder(avl* p){
    if(p==NULL)return;
    inorder(p->l);
    printf("%d ",p->x);
    inorder(p->r);
}

avl* Search(int x,avl* p){
    if(p==NULL) return NULL;
    else if(p->x<x) return Search(x,p->l);
    else if(p->x>x) return Search(x,p->r);
    else return p;
    
}

int main(){
    root* b=CreateRoot();
    AvlInsert(b,50);
    
    //printf("123");
    AvlInsert(b,80);
    AvlInsert(b,70);
    inorder(b->root);
    printf("\n");
    preorder(b->root);
    printf("\n");
}
