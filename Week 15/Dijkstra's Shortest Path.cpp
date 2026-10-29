#include <stdio.h>

#define MAX_VERTICES 100
#define INF 10000000

int main(void) {
    int graph[MAX_VERTICES][MAX_VERTICES];
    int distance[MAX_VERTICES];
    int visited[MAX_VERTICES];
    int previous[MAX_VERTICES];
    int vertices;
    int start, end;
    int i, j, count, current, next;
    int minDistance;

    printf("Enter the number of vertices (1-%d): ", MAX_VERTICES);
    if (scanf("%d", &vertices) != 1 ||
        vertices < 1 || vertices > MAX_VERTICES) {
        printf("Invalid number of vertices.\n");
        return 1;
    }

    printf("Enter the adjacency matrix (0 means no edge):\n");
    for (i = 0; i < vertices; i++) {
        for (j = 0; j < vertices; j++) {
            if (scanf("%d", &graph[i][j]) != 1 || graph[i][j] < 0) {
                printf("Invalid input. Use nonnegative edge weights.\n");
                return 1;
            }
        }
    }

    printf("Enter the start node (0-%d): ", vertices - 1);
    if (scanf("%d", &start) != 1 || start < 0 || start >= vertices) {
        printf("Invalid start node.\n");
        return 1;
    }

    printf("Enter the end node (0-%d): ", vertices - 1);
    if (scanf("%d", &end) != 1 || end < 0 || end >= vertices) {
        printf("Invalid end node.\n");
        return 1;
    }

    for (i = 0; i < vertices; i++) {
        distance[i] = INF;
        visited[i] = 0;
        previous[i] = -1;
    }

    distance[start] = 0;

    for (count = 0; count < vertices; count++) {
        minDistance = INF;
        current = -1;

        for (i = 0; i < vertices; i++) {
            if (!visited[i] && distance[i] < minDistance) {
                minDistance = distance[i];
                current = i;
            }
        }

        if (current == -1)
            break;

        visited[current] = 1;

        if (current == end)
            break;

        for (next = 0; next < vertices; next++) {
            if (!visited[next] && graph[current][next] > 0 &&
                distance[current] != INF &&
                distance[current] + graph[current][next] < distance[next]) {
                distance[next] = distance[current] + graph[current][next];
                previous[next] = current;
            }
        }
    }

    if (distance[end] == INF) {
        printf("No path exists from node %d to node %d.\n", start, end);
    } else {
        int path[MAX_VERTICES];
        int pathLength = 0;
        int node = end;

        while (node != -1) {
            path[pathLength++] = node;
            node = previous[node];
        }

        printf("Shortest distance: %d\n", distance[end]);
        printf("Path: ");

        for (i = pathLength - 1; i >= 0; i--) {
            printf("%d", path[i]);
            if (i > 0)
                printf(" -> ");
        }
        printf("\n");
    }

    return 0;
}