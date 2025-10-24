#include <stdio.h>
#include <stdlib.h>
#include "myhash.h"

#define MOD 5

int main(){
    /* CHAINING
    node* HT[MOD];
    for (int i=0;i<MOD;i++){
        HT[i]=NULL;
    }  
    InsertHash(HT,42,MOD);
    InsertHash(HT,37,MOD);
    InsertHash(HT,48,MOD);
    InsertHash(HT,47,MOD);
    InsertHash(HT,102,MOD);
    node* temp=Search(HT,47,MOD);
    */

    //LINEAR PROBING
    int *HT=CreateProbeHash(MOD);
    PROBINGinsert(HT,4,MOD);
    PROBINGinsert(HT,2,MOD);
    PROBINGinsert(HT,3,MOD);
    PROBINGinsert(HT,1,MOD);
    PROBINGinsert(HT,6,MOD);
    printHT(HT,MOD);
    printf("%d\n",HT[PROBINGsearch(HT,0,MOD)]);
        int i=-1;
    //while(1){
        //printf("%d %d\n",HT[i],i);
        //i=i-1;
    //}
    i=0;
    while(1){
        printf("%d %d\n",HT[i],i);
        i=i+1;
    }

}