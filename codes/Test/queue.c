#include <stdio.h>
#include <stdlib.h>

typedef struct qu{
    int start;
    int end;
    int size;
    int n; //size
    int* arr;
}qu;

qu* init(int size){
    qu* ret=(qu*)malloc(sizeof(qu));
    ret->arr = (int*)malloc(size*sizeof(int));
    ret->n=0;
    ret->size=size;
    ret->start=0;
    ret->end=0;
    return ret;
}

void enq(qu* q,int x){
    if(q->n==q->size){
        printf("FAIL! QUEUE FULL!\n");
        return;
    }
    else{
        q->arr[q->end++]=x;
        q->end%=q->size;
        q->n++;
        return;
    }
}

int deq(qu* q){
    if(q->n==0){
        printf("FAIL! QUEUE EMPTY!\n");
        return -1;
    }
    else{
        int p=q->arr[q->start];
        q->start++;
        q->start%=q->size;
        q->n-=1;
        printf("%d\n",p);
        return p;
    }
}

void displayqu(qu* q){
    for (int i=q->start;i%q->size!=q->end;i++){
        printf("%d ",q->arr[i%q->size]);
    }
    printf("\n");
}

/*
Input

n,op (size of q and no. of op) (code 1 enq,code 2 deq, code 3 print)
1 2
3
2 3



*/
int main(){
    int n,op,code,x;
    scanf("%d %d",&n,&op);
    qu* q=init(n);
    
    for (int i=0;i<op;i++){
        scanf("%d",&code);
        if(code==1){
            scanf("%d",&x);
            enq(q,x);
        }
        else if(code ==2){
            deq(q,x);
        }
        else displayqu(q);
    }
}