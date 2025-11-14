#include <stdio.h>

#define MAXN 100000
#define MAXE 200000

/* ===== DISJOINT SET ARRAYS ===== */
int sets[MAXN];

/* ===== EDGE STRUCTURE ===== */
typedef struct {
    int u, v, w;
} Edge;

Edge edges[MAXE];

/* ========== DSU FUNCTIONS ========== */
void dsu_init(int n) {
    for (int i = 0; i < n; i++) {
        sets[i] = -1;    // each node is a separate set
    }
}

int dsu_find(int x) {
    int ret = x;
    while (sets[ret] >= 0) {
        ret = sets[ret];
    }
    return ret;
}

void dsu_union(int a, int b) {
    int ra = dsu_find(a);
    int rb = dsu_find(b);
    if (ra == rb) ;

    if (sets[ra] < sets[rb]) {         // ra’s tree is bigger
        sets[ra] += sets[rb];          // update size
        sets[rb] = ra;                 // attach rb under ra
    } else {
        sets[rb] += sets[ra];
        sets[ra] = rb;
    }
}

/* ===== COMPARATOR FOR SORTING EDGES BY WEIGHT ===== */
int cmp_edges(const void *a, const void *b) {
    Edge *x = (Edge*)a;
    Edge *y = (Edge*)b;
    return x->w - y->w;
}

/* ========== KRUSKAL’S MST FUNCTION ========== */
int kruskal(int n, int m) {
    int mst_weight = 0;

    // 1. Sort edges by weight
    qsort(edges, m, sizeof(Edge), cmp_edges);

    // 2. Initialize DSU
    dsu_init(n);
    int count=0;
    // 3. Iterate through sorted edges
    for (int i = 0; i < m; i++) {
        
        /* 
           TODO: YOU COMPLETE THIS PART

           PSEUDOCODE:
           u = edges[i].u
           v = edges[i].v
           w = edges[i].w

           if find(u) != find(v):
               union(u, v)
               add w to MST weight
               print the edge (optional)
        */
        int u = edges[i].u,v = edges[i].v,w = edges[i].w;
        if(count<n-1){
            if(dsu_find(u)!=dsu_find(v)){
                mst_weight+=w;
                dsu_union(u,v);
                count++;
            }
        }
        else break;
    }

    return mst_weight;
}

/* ========== MAIN ========== */
int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    int mst = kruskal(n, m);

    printf("MST Weight = %d\n", mst);

    return 0;
}
