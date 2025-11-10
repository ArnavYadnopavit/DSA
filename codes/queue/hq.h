#ifndef MYLIB_H
#define MYLIB_H

#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int x;
    struct node* next;
}node;

typedef struct queue{
    node* head;
    int size;
}queue;

node* CreateNode(int x){
    node* new=(node*)malloc(sizeof(node));
    new->x=x;
    new->next;
    return new;
}
queue* CreateQueue(){
    queue* q = (queue*)malloc(sizeof(queue));
    q->head = NULL;
    q->size = 0;
    return q;
}


void enq(queue* q,int x){
    if(q->head==NULL){
        q->head=CreateNode(x);
    }
    else{
        node* temp=q->head;
        while(temp->next){
            temp=temp->next;
        }
        temp->next=CreateNode(x);
    }
    q->size++;
}

int deq(queue* q){
    node* ret=q->head;
    if(q->size>0){
        q->head=q->head->next;
        q->size--;
    }
    return ret->x;
}   
#endif // MYLIB_H