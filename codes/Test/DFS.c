/* ONLY FILL IN THE DFS PROCEDURE.
 * STACK IMPLEMENTATION IS TO BE USED AS-IS.
 */

#include <stdio.h>
#include <stdlib.h>

#define MAXN 1000
#define MAXDEG MAXN

/* ---------------- Graph Representation ---------------- */
int adj[MAXN][MAXDEG];
int deg[MAXN];

/* ---------------- DFS Output Data ---------------- */
int visited[MAXN];
int parent[MAXN];
int TOPO[MAXN];

/* ---------------- Stack Implementation (DO NOT MODIFY) ---------------- */

typedef struct {
    int *data;
    int top;
    int cap;
} Stack;

/* === Stack Implementation (PROVIDED) === */
void stack_init(Stack *s, int init_cap) {
    if (init_cap < 2) init_cap = 2;
    s->data = malloc(init_cap * sizeof(int));
    if (!s->data) { perror("malloc"); exit(EXIT_FAILURE); }
    s->cap = init_cap;
    s->top = 0;
}

int stack_empty(const Stack *s) {
    return s->top == 0;
}

void stack_push(Stack *s, int x) {
    if (s->top == s->cap) {
        /* Resize if full */
        int newcap = s->cap * 2;
        int *newdata = malloc(newcap * sizeof(int));
        if (!newdata) { perror("malloc"); exit(EXIT_FAILURE); }
        for (int i = 0; i < s->top; i++)
            newdata[i] = s->data[i];
        free(s->data);
        s->data = newdata;
        s->cap = newcap;
    }
    s->data[s->top++] = x;
}

int stack_pop(Stack *s) {
    if (stack_empty(s)) { fprintf(stderr, "Stack underflow!\n"); exit(EXIT_FAILURE); }
    return s->data[--s->top];
}

void stack_free(Stack *s) {
    free(s->data);
    s->data = NULL;
    s->cap = 0;
    s->top = 0;
}

/* === DFS FUNCTION (TO BE FILLED IN BY YOU) === */
void dfs(int n, int s) {
    int arr[n];
    for(int i=0;i<n;i++) arr[i]=0;
    Stack *st=(Stack*)malloc(sizeof(Stack));
    stack_init(st,n);
    parent[s]=-1;
    stack_push(st,s);
    int temp;
    int index=0;
    arr[s]=1;
    while(!stack_empty(st)){
        temp=stack_pop(st);
        visited[index++]=temp;
        for(int i=0;i<deg[temp];i++){
            if(arr[adj[temp][i]]==0){
                parent[adj[temp][i]]=temp;
                arr[adj[temp][i]]=1;
                stack_push(st,adj[temp][i]);
            }
        }
    }
    for(int i=0;i<n;i++){
        TOPO[i]=visited[i];
    }
    
    

}



/* ---------------- MAIN PROGRAM DO NOT MODIFY ---------------- */
int main(void) {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) {
        fprintf(stderr, "Invalid input\n");
        return 1;
    }

    for (int i = 0; i < n; i++) deg[i] = 0;

    /* Read edges (0-based vertex input) */
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        if (u < 0 || u >= n || v < 0 || v >= n) continue;
        adj[u][deg[u]++] = v;
        if (u != v) adj[v][deg[v]++] = u;  /* undirected graph */
    }

    int s;
    scanf("%d", &s);

    dfs(n, s);

    printf("visited:");
    for (int i = 0; i < n; i++) printf(" %d", visited[i]);
    printf("\nparents:");
    for (int i = 0; i < n; i++) printf(" %d", parent[i]);
    printf("\n");

    return 0;
}
