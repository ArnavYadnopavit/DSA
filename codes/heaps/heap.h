#ifndef MYLIB_H
#define MYLIB_H

// Include standard libraries if needed
#include <stdio.h>
#include <stdlib.h>

typedef struct maxheap{
    int* arr;
    int capacity;
    int size;
}heap;

heap* init(int size){
    heap* ret=(heap*)malloc(sizeof(heap));
    ret->arr=(int*)malloc(sizeof(int)*size);
    ret->size=size;
    ret->capacity=0;
}

void insert(heap* hp,int x){
    if(hp->capacity>=hp->size) return;
    else{
            int temp,i=hp->capacity;
            temp=hp->arr[i/2];
            while(i>0 && temp>x){
                hp->arr[i]=temp;
                i=i/2;
                temp=hp->arr[i/2];
            }
            hp->arr[i]=x;
            hp->capacity++;
            return;
    }
}

int delete(heap* hp){
    if(hp->capacity==0)return -1;
    else{
        int ret=hp->arr[0];
        hp->arr[0]=hp->arr[hp->capacity-1];
        hp->capacity--;
        int i=0,j=2*i+1;
        while(j<hp->capacity-2){//Both 2i+1 and 2i+2 are in capacity
            if(hp->arr[j]<hp->arr[j+1]){
                j=j+1;
            }
            if(hp->arr[i]<hp->arr[j]){
                int temp=hp->arr[j];
                hp->arr[j]=hp->arr[i];
                hp->arr[i]=temp;
                i=j;
                j=2*i+1;
            }
            else break;
        } 
    }
}

void display(heap* hp){
    for(int i=0;i<hp->capacity;i++){
        printf("%d ",hp->arr[i]);
    }
    printf("\n");
}

#endif // MYLIB_H