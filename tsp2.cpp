#include <iostream>

const int INF = 1e9;
const int MAX_VERTICES = 10;

class TSP {
private:
    int graph[MAX_VERTICES][MAX_VERTICES];
    int numVertices;
    int memo[1 << MAX_VERTICES][MAX_VERTICES];

public:
    TSP(int g[MAX_VERTICES][MAX_VERTICES], int n) : numVertices(n) {
        // Initialize memoization table
        for (int i = 0; i < (1 << MAX_VERTICES); ++i) {
            for (int j = 0; j < MAX_VERTICES; ++j) {
                memo[i][j] = -1;
            }
        }

        // Copy the graph
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                graph[i][j] = g[i][j];
            }
        }
    }

    int tsp(int mask, int pos) {
        // Base case: all cities visited
        if (mask == (1 << numVertices) - 1) {
            return (graph[pos][0] != 0) ? graph[pos][0] : INF; // Return to the starting city
        }

        // Check if the result is already memoized
        if (memo[mask][pos] != -1) {
            return memo[mask][pos];
        }

        int ans = INF;

        // Try visiting unvisited cities
        for (int next = 0; next < numVertices; ++next) {
            if ((mask & (1 << next)) == 0 && graph[pos][next] != 0) {
                int newMask = mask | (1 << next);
                ans = std::min(ans, graph[pos][next] + tsp(newMask, next));
            }
        }

        // Memoize the result
        memo[mask][pos] = ans;
        return ans;
    }

    int solveTSP() {
        // Start the TSP from the first city (0)
        return tsp(1, 0); // Start with the first city visited
    }
};

int main() {
    // Example graph represented as an adjacency matrix
    int graph[MAX_VERTICES][MAX_VERTICES] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    TSP tsp(graph, 4);
    int minCost = tsp.solveTSP();

    std::cout << "Minimum Cost of TSP: " << minCost << std::endl;

    return 0;
}
