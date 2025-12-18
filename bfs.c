#include <stdio.h>

int n; // number of vertices
int adj[10][10]; // adjacency matrix
int visited[10]; // visited array
int queue[10]; // queue for BFS
int front = -1, rear = -1;

/* Function to insert into queue */
void enqueue(int v) {
    queue[++rear] = v;
}

/* Function to delete from queue */
int dequeue() {
    return queue[++front];
}

/* BFS Traversal */
void bfs(int start) {
    int i, v;

    enqueue(start);
    visited[start] = 1;

    printf("BFS Traversal: ");

    while (front != rear) {
        v = dequeue();
        printf("%d ", v);

        for (i = 0; i < n; i++) {
            if (adj[v][i] == 1 && visited[i] == 0) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int i, j, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
        visited[i] = 0;
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    bfs(start);

    return 0;
}
