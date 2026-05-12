#include <stdio.h>
#define MAX 10

int adj[MAX][MAX], vis[MAX], stack[MAX];
int top = -1;
int n;

void dfs(int v) {
    vis[v] = 1;
    for (int i = 0; i < n; i++) {
        if (adj[v][i] == 1 && vis[i] == 0) {
            dfs(i);
        }
    }
    stack[++top] = v;
}

void topologicalSort() {
    for (int i = 0; i < n; i++) {
        if (vis[i] == 0) {
            dfs(i);
        }
    }

    printf("Topological Order: ");
    while (top != -1) {
        printf("%d ", stack[top--]);
    }
}

void main() {
    int i, j;
    printf("Enter No. of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
        vis[i] = 0;
    }

    topologicalSort();
    printf("\n");
}
