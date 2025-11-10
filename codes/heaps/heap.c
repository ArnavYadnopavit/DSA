#include <stdio.h>
#include <stdlib.h>
#include "heap.h"
#define SIZE 5
int main(){
    int arr[SIZE]={12,7,18,20,15};
    heap* HP=init(20);
    for (int i=0;i<SIZE;i++){
        insert(HP,arr[i]);
    }
    display(HP);
}