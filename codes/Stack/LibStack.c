#include <stdio.h>
#include <stdlib.h>
#include "hstack.h"

stack* CreateStack(int* A,int n,int size){
    stack* st=(stack*)malloc(sizeof(stack));
    st->size=size;
    st->s=(int*)malloc(st->size*(sizeof(int)));
    for(int i=0;i<n;i++){
        st->s[i]=A[i];
    }   
    st->top=n-1;
}

void Display(stack* st){
    for(int i=st->top;i>-1;i--){
        printf("%d ",st->s[i]);
    }
    printf("\n");
}

int pop(stack* st){
    if(st->top<0){
        printf("Stack Underflow\n");
        return -1;
    }
    else if(st->top>-1)    return st->s[st->top--];
}

void push(stack* st,int x){
    if(st->top>=st->size-1){
        printf("Stack Overlow! :)\n");
    }
    else if(st->top<st->size-1){
        st->s[++(st->top)]=x;
    }
}

int peek(stack* st,int index){
    if(st->top-index<0){
        printf("Invalid Index");
    return -1;
    }
    else{
        return st->s[st->top-index];
    }
}

int isEmpty(stack* st){
return st->top==-1;
}


int isFull(stack* st){
return st->top==st->size-1;
}



