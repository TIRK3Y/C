#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int adj_matrix[MAX_SIZE][MAX_SIZE];
int visited[MAX_SIZE];
int queue[MAX_SIZE];
int front = -1;
int rear = -1;

void BFS(int start, int n) {
    int v, i;
    visited[start] = 1;
    queue[++rear] = start;
    while (front != rear) {
        v = queue[++front];
        printf("%d ", v);
        for (i = 0; i < n; i++) {
            if (adj_matrix[v][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                queue[++rear] = i;
            }
        }
    }
}

int main() {
    int n, i, j, start;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adj_matrix[i][j]);
        }
    }
    printf("Enter the starting vertex: ");
    scanf("%d", &start);
    printf("BFS traversal: ");
    BFS(start, n);
    printf("\n");
    return 0;
}