// bfs.c
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int queue[MAX], front = -1, rear = -1;
int visited[MAX];

void enqueue(int vertex) {
    if (rear == MAX - 1)
        return;
    if (front == -1)
        front = 0;
    queue[++rear] = vertex;
}

int dequeue() {
    if (front == -1 || front > rear)
        return -1;
    return queue[front++];
}

void bfs(int graph[MAX][MAX], int n, int start) {
    int i, vertex;
    enqueue(start);
    visited[start] = 1;

    while ((vertex = dequeue()) != -1) {
        printf("%d ", vertex);
        for (i = 0; i < n; i++) {
            if (graph[vertex][i] && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int graph[MAX][MAX], n, i, j, start;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\n");

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    printf("Enter start vertex: ");
    scanf("%d", &start);

    printf("BFS traversal: ");
    bfs(graph, n, start);

    return 0;
}
