// kruskal.c
#include <stdio.h>

#define MAX 100
#define INF 9999

int parent[MAX];

int find(int i) {
    while (parent[i])
        i = parent[i];
    return i;
}

int uni(int i, int j) {
    if (i != j) {
        parent[j] = i;
        return 1;
    }
    return 0;
}

void kruskal(int graph[MAX][MAX], int n) {
    int i, j, u, v, a, b, min, edge_count = 0, cost = 0;

    while (edge_count < n - 1) {
        min = INF;
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (graph[i][j] < min) {
                    min = graph[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        u = find(u);
        v = find(v);

        if (uni(u, v)) {
            printf("Edge %d: (%d, %d) cost: %d\n", edge_count++, a, b, min);
            cost += min;
        }

        graph[a][b] = graph[b][a] = INF;
    }

    printf("Total cost of MST: %d\n", cost);
}

int main() {
    int graph[MAX][MAX], i, j, n;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (9999 for no edge):\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    kruskal(graph, n);

    return 0;
}
