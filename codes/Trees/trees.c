#include <stdio.h>
#include <stdlib.h>
#include "htrees.h" 

int main(){
    int arr[7]={    1,
                    2,3,
                -1,5, 7,10,};
    int n=7;
    tree* root=CreateTree(arr,n);
    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
}




