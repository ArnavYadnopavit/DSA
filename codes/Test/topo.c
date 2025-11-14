#include <stdio.h>

#define MAXN 1000
#define MAXDEG 1000

int adj[MAXN][MAXDEG];
int deg[MAXN];

int visited[MAXN];       // 0 = unvisited, 1 = in stack, 2 = finished
int next_child[MAXN];    // next child index to process in adjacency list

int topo[MAXN];
int topo_idx;

/* ===== Iterative DFS using stack ===== */
void dfs_iterative(int start) {
    int stack[MAXN];
    int top = -1;

    stack[++top] = start;
    visited[start] = 1;
    next_child[start] = 0;

    while (top >= 0) {
        int u = stack[top];

        // If unprocessed neighbors remain
        if (next_child[u] < deg[u]) {
            int v = adj[u][next_child[u]];
            next_child[u]++;

            if (visited[v] == 0) {
                visited[v] = 1;
                next_child[v] = 0;
                stack[++top] = v;
            }
        }
        else {
            // all neighbors processed → post-order action
            topo[topo_idx++] = u;
            visited[u] = 2;
            top--;
        }
    }
}

/* ===== Topological Sort ===== */
void topo_sort(int n) {
    topo_idx = 0;

    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        next_child[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        if (visited[i] == 0) {
            dfs_iterative(i);
        }
    }

    // Print reverse post-order
    printf("Topological Order:\n");
    for (int i = topo_idx - 1; i >= 0; i--)
        printf("%d ", topo[i]);
    printf("\n");
}

/* ===== MAIN ===== */
int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++)
        deg[i] = 0;

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v); // directed edge u -> v
        adj[u][deg[u]++] = v;
    }

    topo_sort(n);

    return 0;
}
