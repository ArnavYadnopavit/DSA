#include <stdio.h>
#define CONST 6
void heap_insert(int hp[],int x,int top){
    if(top==0) hp[0]=x;
    else{
        int i=top;
        int parent=hp[(i-1)/2];
        while(i>0 && parent<x){
            hp[i]=parent;
            i=(i-1)/2;
            if(i>0) parent=hp[(i-1)/2];
        }
        hp[i]=x;
    }
    return;
}

int heap_pop(int hp[],int top){
    if(top==0) return -1;
    else{
        int ret=hp[0];
        hp[0]=hp[top-1];
        hp[top]=ret;
        int i=0;
        int j=i*2+1;
        while(j<top-1){
            if(j+1<top && hp[j]<hp[j+1]){
                j++;
            }
            if(hp[i]<hp[j]){
                int temp=hp[i];
                hp[i]=hp[j];
                hp[j]=temp;
                i=j;
                j=i*2+1;
            }
            else break;
        }
        return ret;
    }
}

void printarr(int arr[],int size){
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main(){
    int hp[CONST]={0};
    int top=0;
    heap_insert(hp,3,top++);
    printarr(hp,top);
    heap_insert(hp,1,top++);
    printarr(hp,top);
    heap_insert(hp,2,top++);
    printarr(hp,top);
    heap_insert(hp,5,top++);
    printarr(hp,top);
    heap_insert(hp,6,top++);
    printarr(hp,top);
    heap_pop(hp,top--);
    printarr(hp,CONST);
    heap_pop(hp,top--);
    printarr(hp,CONST);
    heap_pop(hp,top--);
    printarr(hp,CONST);
    heap_pop(hp,top--);
    printarr(hp,CONST);
    heap_pop(hp,top--);
    printarr(hp,CONST);
}