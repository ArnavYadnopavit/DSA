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

node* Search(BST* b, int key){
    node* temp=b->root;
    while(temp){
        if(key==temp->x){
            return temp;
        }
        else if(key<temp->x){
            temp=temp->l;
        }
        else temp=temp->r;
    }
    return temp;
}

int rcount(node* p){
    int x,y;
    if(p){
        x=rcount(p->l);
        y=rcount(p->r);
        return x+y+1; 
    }
    else return 0;
}

int count(BST* b){
    return rcount(b->root);
}

int rheight(node* p){
    int x,y;
    if(p){
        x=rheight(p->l);
        y=rheight(p->r);
        if(x>y) return x+1;
        else return y+1;
    }
    else return 0;
}

int height(BST* b){
    return rheight(b->root);
}

node* inPre(node* t){ //Give t->l into this
    if(t==NULL){
        return NULL;
    }
    else if (t->r==NULL){
        return t;
    }
    else inPre(t->r);
}

node* inSuc(node* t){ //Give t->r into this
    if(t==NULL){
        return NULL;
    }
    else if (t->l==NULL){
        return t;
    }
    else inPre(t->r);
}

node* rDelete(node* t,int key){
    if(t==NULL){
        return NULL;
    }
    else if(t->l==NULL && t->l==NULL && t->x==key){
        free(t);
        return NULL;

    }
    else{
        if(key<t->x){
            rDelete(t->l,key);
        }
        else if(key>t->x) rDelete(t->r,key);
        else{
            if(rheight(t->l)>rheight(t->l)){
                node* rep=inPre(t->l);
                int temp=rep->x;
                rep->x=t->x;
                t->x=temp;
                rDelete(rep,key);
            }
            else{
                node* rep=inSuc(t->r);
                int temp=rep->x;
                rep->x=t->x;
                t->x=temp;
                rDelete(rep,key);
            }
        }

    }
    return NULL;
}

node* DeleteNode(BST* b, int key){
    rDelete(b->root,key);
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