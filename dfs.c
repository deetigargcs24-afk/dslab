#include <stdio.h>

#define MAX 10

int n;
int adj[MAX][MAX];
int visited[MAX];

void dfs(int v) {
    visited[v] = 1;
    for (int i = 0; i < n; i++) {
        if (adj[v][i] == 1 && !visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    printf("Enter number of vertices (max %d): ", MAX);
    scanf("%d", &n);

    if (n > MAX) {
        printf("Too many vertices!\n");
        return 1;
    }

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    dfs(0);

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            printf("Graph is NOT Connected\n");
            return 0;
        }
    }

    printf("Graph is Connected\n");
    return 0;
}
