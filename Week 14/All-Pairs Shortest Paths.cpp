#include <stdio.h>

#define MAX_VERTICES 100
#define INF 10000000

int main(void) {
    int distance[MAX_VERTICES][MAX_VERTICES];
    int vertices;
    int i, j, k;

    printf("Enter the number of vertices (1-%d): ", MAX_VERTICES);
    if (scanf("%d", &vertices) != 1 ||
        vertices < 1 || vertices > MAX_VERTICES) {
        printf("Invalid number of vertices.\n");
        return 1;
    }

    printf("Enter the adjacency matrix (%d for a missing edge):\n", INF);
    printf("Use 0 on the diagonal and INF where no edge exists.\n");

    for (i = 0; i < vertices; i++) {
        for (j = 0; j < vertices; j++) {
            if (scanf("%d", &distance[i][j]) != 1) {
                printf("Invalid matrix input.\n");
                return 1;
            }
        }
    }

    
    for (k = 0; k < vertices; k++) {
        for (i = 0; i < vertices; i++) {
            for (j = 0; j < vertices; j++) {
                if (distance[i][k] != INF && distance[k][j] != INF &&
                    distance[i][k] + distance[k][j] < distance[i][j]) {
                    distance[i][j] = distance[i][k] + distance[k][j];
                }
            }
        }
    }

    printf("\nShortest-distance matrix:\n");
    for (i = 0; i < vertices; i++) {
        for (j = 0; j < vertices; j++) {
            if (distance[i][j] == INF)
                printf("INF\t");
            else
                printf("%d\t", distance[i][j]);
        }
        printf("\n");
    }

    return 0;
}