#include <stdio.h>

#define MAX_SIZE 100

int adj[MAX_SIZE][MAX_SIZE]; // Adjacency matrix
int visited[MAX_SIZE]; // Visited array
int n; // Number of nodes

// Depth-first search function
void dfs(int v) {
    int i;
    visited[v] = 1;
    printf("%d ", v);
    for(i = 0; i < n; i++) {
        if(adj[v][i] && !visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    int i, j, start;
    printf("Enter the number of nodes: ");
    
scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }
    printf("Enter the starting node: ");
    scanf("%d", &start);
    printf("Depth-first traversal starting from node %d: ", start);
    dfs(start);
    printf("\n");
    return 0;
}