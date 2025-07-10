#include <stdio.h>
#include <stdlib.h>
#include "hstack.h"

int main(void){
    int A[6]={10,5,7,8,9,11};
    stack* s=CreateStack(A,6,10);
    Display(s);
    push(s,1);
    Display(s);
    printf("%d \n",pop(s));
    Display(s);
    printf("%d \n",pop(s));
    push(s,1);
    push(s,1);
    push(s,1);
    push(s,1);
    push(s,1);
    push(s,1);
    push(s,1);
    Display(s);

}