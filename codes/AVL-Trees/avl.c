#include <stdio.h>
#include <stdlib.h>
#include "havl.h"

int main(){
    root* r=CreateRoot();
    Insert(r,50);
    Insert(r,100);
    Insert(r,60);
    inorder(r->root);
    printf("\n");
    //preorder(r->root);
    //printf("\n");
}