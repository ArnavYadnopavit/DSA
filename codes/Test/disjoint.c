#include <stdio.h>

#define MAXN 100000

/* ===== DISJOINT SET ARRAYS ===== */
int sets[MAXN];   // or size — your choice


/* ===== INITIALIZE DSU ===== */
/* Makes n separate sets: 0,1,2,...,n-1 */
void dsu_init(int n) {
    for (int i = 0; i < n; i++) {
        sets[i] = -1;      // or 1 if using size
    }
}


/* ===== FIND FUNCTION (YOU MUST COMPLETE THIS) ===== */
/* return representative of x */
int dsu_find(int x) {

    /* WRITE YOUR CODE HERE */
    int ret=x;
    while(sets[ret]>=0){
        ret=sets[ret];
    }
    return ret;

}



/* ===== UNION FUNCTION (YOU MUST COMPLETE THIS) ===== */
/* merge sets containing a and b */
void dsu_union(int a, int b) {

    /* WRITE YOUR CODE HERE */
    int arep=dsu_find(a),brep=dsu_find(b);
    if(arep==brep) return;
    if(sets[arep]<sets[brep]){//add smaller set to bigger set
        sets[arep]=sets[arep]+sets[brep];
        sets[brep]=arep;
    }
    else{
        sets[brep]=sets[arep]+sets[brep];
        sets[arep]=brep;
    }
    

}



/* ===== DEMO MAIN (YOU CAN IGNORE THIS PART) ===== */
int main() {
    int n = 7;
    dsu_init(n);

    dsu_union(1, 2);
    dsu_union(2, 3);
    dsu_union(4, 5);

    printf("find(3) = %d\n", dsu_find(3));
    printf("find(5) = %d\n", dsu_find(5));
    printf("find(6) = %d\n", dsu_find(6));

    return 0;
}
