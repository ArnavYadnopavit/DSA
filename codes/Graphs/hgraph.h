#ifndef MYLIB_H
#define MYLIB_H

// Include standard libraries if needed
#include <stdio.h>
#include <stdlib.h>

//Queue Import Start
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
    new->next=NULL;
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

int deq(queue* q) {
    if (q->size == 0 || q->head == NULL) {
        printf("Queue is empty!\n");
        return -1;
    }
    node* ret = q->head;
    q->head = q->head->next;
    q->size--;
    int val = ret->x;
    free(ret);
    return val;
} 
//Queue Import End



void BFS (int* G,int start,int n){
    int s=start;
    queue* q=CreateQueue();
    int visited[n];
    for (int i=0;i<n;i++) visited[i]=0;
    printf("%d ",s);
    visited[s]=1;
    enq(q,s);
    while(q->size!=0){
        s=deq(q);
        for(int i=0;i<n;i++){
            if(G[s*n+i]==1 && visited[i]==0){
                printf("%d ",i);
                visited[i]=1;
                enq(q,i);
            }
        }
    }
}
#endif // MYLIB_H