#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define MAX_N 20 // Maximum number of cities

int n; // Number of cities
int dist[MAX_N][MAX_N]; // Distance matrix
int memo[MAX_N][1 << MAX_N]; // Memoization table

int tsp(int current, int visited) {
    if (visited == (1 << n) - 1) {
        // All cities visited, return to the starting city
        return dist[current][0];
    }

    if (memo[current][visited] != -1) {
        // Already computed
        return memo[current][visited];
    }

    int min_cost = INT_MAX;
    for (int next = 0; next < n; next++) {
        if ((visited & (1 << next)) == 0) {
            int new_cost = dist[current][next] + tsp(next, visited | (1 << next));
            if (new_cost < min_cost) {
                min_cost = new_cost;
            }
        }
    }

    return memo[current][visited] = min_cost;
}

int main() {
    printf("Enter the number of cities (<= %d): ", MAX_N);
    scanf("%d", &n);

    printf("Enter the distance matrix (%dx%d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &dist[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (1 << n); j++) {
            memo[i][j] = -1;
        }
    }

    clock_t start_time = clock();
    int min_cost = tsp(0, 1);
    clock_t end_time = clock();

    double execution_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Minimum cost for the TSP tour: %d\n", min_cost);
    printf("Execution time: %f seconds\n", execution_time);

    return 0;
}
