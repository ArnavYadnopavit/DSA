#include <stdio.h>
#include <stdlib.h>
#include "htrees.h" 

node* CreateNode(tree* addr){
    node* new=(node*)malloc(sizeof(node));
    new->addr=addr;
    new->next;
    return new;
}
queue* CreateQueue(){
    queue* q = (queue*)malloc(sizeof(queue));
    q->head = NULL;
    q->size = 0;
    return q;
}

void enq(queue* q,tree* addr){
    if(q->head==NULL){
        q->head=CreateNode(addr);
    }
    else{
        node* temp=q->head;
        while(temp->next){
            temp=temp->next;
        }
        temp->next=CreateNode(addr);
    }
    q->size++;
}

node* deq(queue* q){
    node* ret=q->head;
    if(q->size>0){
        q->head=q->head->next;
        q->size--;
    }
    return ret;
}   

tree* CreateTreeNode(int val){
    tree* t=(tree*)malloc(sizeof(tree));
    t->x=val;
    t->l=NULL;
    t->r=NULL;
    return t;
}

tree* CreateTree(int* arr,int arrsize){
    //Level by level
    tree * p=CreateTreeNode(arr[0]);
    tree* tempp=p;
    queue* q=CreateQueue();
    enq(q,p);
    int i=1;
    while(i<arrsize && q->size>0){
        
        tempp=deq(q)->addr;
        //Left
        if(arr[i]!=-1){
            tree* t=CreateTreeNode(arr[i]);
            tempp->l=t;
            enq(q,t);
        }
        i++;
        if(arr[i]!=-1){
            tree* t=CreateTreeNode(arr[i]);
            tempp->r=t;
            enq(q,t);
        }
        i++;
    }
    return p; 

}

void preorder(tree* root){
    if(root){
        printf("%d ",root->x);
        preorder(root->l);
        preorder(root->r);
    }
}

void inorder(tree* root){
    if(root){
        inorder(root->l);
        printf("%d ",root->x);
        inorder(root->r);
    }
}

void postorder(tree* root){
    if(root){
        postorder(root->l);
        postorder(root->r);
        printf("%d ",root->x);
    }
}