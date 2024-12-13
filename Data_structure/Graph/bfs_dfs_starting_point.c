#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

// Graph structure
int adj[MAX][MAX]; // Adjacency matrix
int visited[MAX];
int queue[MAX];
int front = -1, rear = -1;

// Stack for DFS
int stack[MAX];
int top = -1;

// Function to add an edge
void addEdge(int u, int v)
{
    adj[u][v] = 1;
    adj[v][u] = 1; // Since the graph is undirected
}

// DFS function using stack
void DFS_Stack(int start, int n)
{
    top = -1; // Initialize stack
    stack[++top] = start;

    for (int i = 0; i < n; i++)
        visited[i] = 0; // Reset visited array

    while (top != -1)
    {
        int vertex = stack[top--];

        if (!visited[vertex])
        {
            printf("%d ", vertex);
            visited[vertex] = 1;
        }

        for (int i = n - 1; i >= 0; i--)
        { // Reverse order to match desired traversal
            if (adj[vertex][i] == 1 && !visited[i])
            {
                stack[++top] = i;
            }
        }
    }
}

// BFS function
void BFS(int start, int n)
{
    front = rear = 0;
    queue[rear] = start;
    visited[start] = 1;

    while (front <= rear)
    {
        int vertex = queue[front++];
        printf("%d ", vertex);

        for (int i = 0; i < n; i++)
        {
            if (adj[vertex][i] == 1 && !visited[i])
            {
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }
}

int main()
{
    int n, e, start;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the number of edges: ");
    scanf("%d", &e);

    // Initialize adjacency matrix to 0
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            adj[i][j] = 0;
        }
    }

    // Read edges
    printf("Enter edges (u v):\n");
    for (int i = 0; i < e; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    printf("Enter the starting vertex: ");
    scanf("%d", &start);

    // DFS Traversal
    printf("\nDFS Traversal: ");
    DFS_Stack(start, n); // Start from the input node

    // BFS Traversal
    printf("\nBFS Traversal: ");
    for (int i = 0; i < n; i++)
        visited[i] = 0; // Reset visited array
    BFS(start, n);      // Start from the input node

    return 0;
}
