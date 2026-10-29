#include <stdio.h>

#define MAX_CITIES 100

int graph[MAX_CITIES][MAX_CITIES];
int visited[MAX_CITIES];
int queue[MAX_CITIES];
int cityCount;

void bfs(int start) {
    int front = 0;
    int rear = 0;
    int i;
    int current;

    for (i = 0; i < cityCount; i++)
        visited[i] = 0;

    visited[start] = 1;
    queue[rear++] = start;

    printf("BFS reachable cities: ");

    while (front < rear) {
        current = queue[front++];
        printf("%d ", current);

        for (i = 0; i < cityCount; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }

    printf("\n");
}

void dfsVisit(int current) {
    int i;

    visited[current] = 1;
    printf("%d ", current);

    for (i = 0; i < cityCount; i++) {
        if (graph[current][i] == 1 && !visited[i])
            dfsVisit(i);
    }
}

void dfs(int start) {
    int i;

    for (i = 0; i < cityCount; i++)
        visited[i] = 0;

    printf("DFS reachable cities: ");
    dfsVisit(start);
    printf("\n");
}

int main(void) {
    int i, j;
    int start;

    printf("Enter the number of cities (1-%d): ", MAX_CITIES);
    if (scanf("%d", &cityCount) != 1 ||
        cityCount < 1 || cityCount > MAX_CITIES) {
        printf("Invalid number of cities.\n");
        return 1;
    }

    printf("Enter the adjacency matrix (0 or 1):\n");
    for (i = 0; i < cityCount; i++) {
        for (j = 0; j < cityCount; j++) {
            if (scanf("%d", &graph[i][j]) != 1 ||
                (graph[i][j] != 0 && graph[i][j] != 1)) {
                printf("Invalid matrix value. Enter only 0 or 1.\n");
                return 1;
            }
        }
    }

    printf("Enter the starting city (0-%d): ", cityCount - 1);
    if (scanf("%d", &start) != 1 || start < 0 || start >= cityCount) {
        printf("Invalid starting city.\n");
        return 1;
    }

    bfs(start);
    dfs(start);

    return 0;
}
