/*
Build a BST from a preorder sequence (given as command-line input),
print its level-order traversal (linear) and a simple ASCII "pictorial" view.

Compile:
    gcc -std=c99 -O2 -o bst_level bst_level.c

Run (examples):
    ./bst_level 8,3,1,4,6,7,10,14,13
    ./bst_level 8 3 1 4 6 7 10 14 13

Notes:
 - The program accepts either a single comma-separated argument or multiple numeric arguments.
 - Works best for small trees (the pictorial output is ASCII-art and simple).
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Node {
    int val;
    struct Node *left, *right;
    int depth;
    int xindex;
} Node;

Node* new_node(int v) {
    Node* n = malloc(sizeof(Node));
    n->val = v;
    n->left = n->right = NULL;
    n->depth = 0;
    n->xindex = 0;
    return n;
}

Node* insert_bst(Node* root, int v) {
    if (!root) return new_node(v);
    if (v < root->val) root->left = insert_bst(root->left, v);
    else root->right = insert_bst(root->right, v);
    return root;
}

int max(int a, int b) { return a > b ? a : b; }

int compute_depth(Node* root) {
    if (!root) return 0;
    int dl = compute_depth(root->left);
    int dr = compute_depth(root->right);
    root->depth = 1 + max(dl, dr);
    return root->depth;
}

/* inorder traversal to give x-index positions (1..n) */
void inorder_assign(Node* root, int *counter, int depth, int *maxdepth) {
    if (!root) return;
    inorder_assign(root->left, counter, depth+1, maxdepth);
    root->xindex = (*counter)++;
    root->depth = depth;
    if (depth > *maxdepth) *maxdepth = depth;
    inorder_assign(root->right, counter, depth+1, maxdepth);
}

/* BFS level-order printing (linear) */
void print_level_order(Node* root) {
    if (!root) {
        printf("The level order traversal is\n\n");
        return;
    }
    /* simple queue using array pointers */
    Node** q = malloc(10000 * sizeof(Node*));
    int head = 0, tail = 0;
    q[tail++] = root;
    int first = 1;
    printf("The level order traversal is\n");
    while (head < tail) {
        Node* cur = q[head++];
        if (!first) printf(",");
        first = 0;
        printf("%d", cur->val);
        if (cur->left) q[tail++] = cur->left;
        if (cur->right) q[tail++] = cur->right;
    }
    printf("\n\n");
    free(q);
}

/* Build ASCII grid and print pictorial tree */
void print_pictorial(Node* root) {
    if (!root) {
        printf("(empty tree)\n");
        return;
    }
    /* Assign inorder x-index and depth (root depth=0) */
    int counter = 1;
    int maxdepth = 0;
    inorder_assign(root, &counter, 0, &maxdepth);
    int n = counter - 1;

    /* find max width of node string */
    int maxw = 0;
    /* traverse to compute max width */
    Node** stack = malloc((n+5) * sizeof(Node*));
    int sp = 0;
    stack[sp++] = root;
    while (sp) {
        Node* t = stack[--sp];
        char buf[64];
        sprintf(buf, "%d", t->val);
        int len = strlen(buf);
        if (len > maxw) maxw = len;
        if (t->right) stack[sp++] = t->right;
        if (t->left) stack[sp++] = t->left;
    }
    free(stack);

    int spacing = maxw + 2; /* column width per inorder position */
    int cols = (n + 2) * spacing + 4;
    int rows = (maxdepth + 1) * 2 - 1; /* nodes on even rows, connectors on odd rows */
    if (rows < 1) rows = 1;

    /* allocate grid filled with spaces */
    char **grid = malloc(rows * sizeof(char*));
    for (int r = 0; r < rows; ++r) {
        grid[r] = malloc(cols + 1);
        for (int c = 0; c < cols; ++c) grid[r][c] = ' ';
        grid[r][cols] = '\0';
    }

    /* place nodes */
    /* traverse tree and place each node */
    stack = malloc((n+5) * sizeof(Node*));
    sp = 0;
    stack[sp++] = root;
    while (sp) {
        Node* t = stack[--sp];
        int r = t->depth * 2; /* even row */
        int center_col = t->xindex * spacing;
        char buf[64];
        sprintf(buf, "%d", t->val);
        int len = strlen(buf);
        int startc = center_col - len/2;
        if (startc < 0) startc = 0;
        if (startc + len >= cols) startc = cols - len - 1;
        for (int i = 0; i < len; ++i) grid[r][startc + i] = buf[i];

        if (t->right) stack[sp++] = t->right;
        if (t->left) stack[sp++] = t->left;
    }
    free(stack);

    /* draw single-character connectors '/' or '\' on connector rows */
    /* for each node, if left/right child exists, put a slash on the connector row between their columns */
    /* We'll place connector at row = parent_row + 1, col = midpoint between cols or near child */
    stack = malloc((n+5) * sizeof(Node*));
    sp = 0;
    stack[sp++] = root;
    while (sp) {
        Node* t = stack[--sp];
        int pr = t->depth * 2;
        int pc = t->xindex * spacing;
        if (t->left) {
            int cc = t->left->xindex * spacing;
            int crow = pr + 1;
            if (crow < rows) {
                int con_col = (pc + cc) / 2;
                if (con_col < 0) con_col = 0;
                if (con_col >= cols) con_col = cols - 1;
                grid[crow][con_col] = '/';
            }
            stack[sp++] = t->left;
        }
        if (t->right) {
            int cc = t->right->xindex * spacing;
            int crow = pr + 1;
            if (crow < rows) {
                int con_col = (pc + cc) / 2;
                if (con_col < 0) con_col = 0;
                if (con_col >= cols) con_col = cols - 1;
                grid[crow][con_col] = '\\';
            }
            stack[sp++] = t->right;
        }
    }
    free(stack);

    /* Trim trailing spaces on each printed line for neatness and print */
    for (int r = 0; r < rows; ++r) {
        int last = cols - 1;
        while (last >= 0 && grid[r][last] == ' ') last--;
        if (last < 0) printf("\n");
        else {
            for (int c = 0; c <= last; ++c) putchar(grid[r][c]);
            putchar('\n');
        }
    }

    /* free grid */
    for (int r = 0; r < rows; ++r) free(grid[r]);
    free(grid);
}

/* Parse input arguments into integer array.
   Accept either single comma-separated arg or multiple args.
*/
int parse_input(int argc, char **argv, int **out_arr) {
    if (argc < 2) return 0;
    int *arr = malloc(argc * sizeof(int));
    int n = 0;
    if (argc == 2) {
        /* one argument: may be comma-separated or space-separated */
        char *s = argv[1];
        int len = strlen(s);
        char *tmp = malloc(len+1);
        strcpy(tmp, s);
        char *p = tmp;
        char *tok;
        while ((tok = strsep(&p, ",")) != NULL) {
            /* trim spaces */
            while (*tok && isspace((unsigned char)*tok)) tok++;
            if (*tok == '\0') continue;
            char *end = tok + strlen(tok) - 1;
            while (end > tok && isspace((unsigned char)*end)) { *end = '\0'; end--; }
            if (*tok == '\0') continue;
            arr[n++] = atoi(tok);
        }
        free(tmp);
    } else {
        for (int i = 1; i < argc; ++i) {
            char *s = argv[i];
            /* allow commas inside args like "8,3" */
            char *tmp = strdup(s);
            char *p = tmp;
            char *tok;
            while ((tok = strsep(&p, ",")) != NULL) {
                while (*tok && isspace((unsigned char)*tok)) tok++;
                if (*tok == '\0') continue;
                arr[n++] = atoi(tok);
            }
            free(tmp);
        }
    }
    *out_arr = arr;
    return n;
}

/* free tree */
void free_tree(Node* root) {
    if (!root) return;
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

int main(int argc, char **argv) {
    int *arr = NULL;
    int n = parse_input(argc, argv, &arr);
    if (n <= 0) {
        fprintf(stderr, "Usage: %s 8,3,1,4,6,7,10,14,13\n(or) %s 8 3 1 4 6 7 10 14 13\n", argv[0], argv[0]);
        return 1;
    }

    Node *root = NULL;
    for (int i = 0; i < n; ++i) root = insert_bst(root, arr[i]);

    print_level_order(root);
    print_pictorial(root);

    free_tree(root);
    free(arr);
    return 0;
}
