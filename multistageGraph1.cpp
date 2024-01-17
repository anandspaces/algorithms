#include <iostream>
using namespace std;

const int MAX_STAGES = 6;  // Maximum number of stages
const int MAX_VERTICES = 10;  // Maximum number of vertices
const int INF = 1e9;  // Infinity value

// Function to find the minimum cost in a multistage graph
int findMinCost(int graph[MAX_STAGES][MAX_VERTICES], int numStages) {
    int cost[MAX_VERTICES];

    // Initialize the cost array with large values
    fill(cost, cost + MAX_VERTICES, INF);

    // The cost of the last stage is 0 for the last vertex
    cost[numStages - 1] = 0;

    // Traverse the graph in reverse order to find the minimum cost
    for (int stage = numStages - 2; stage >= 0; --stage) {
        for (int vertex = 0; vertex < MAX_VERTICES; ++vertex) {
            // Traverse the vertices in the current stage
            if (graph[stage][vertex] != INF) {
                // Update the minimum cost for each vertex in the current stage
                cost[vertex] = min(cost[vertex], graph[stage][vertex] + cost[vertex + 1]);
            }
        }
    }

    // The final result is the minimum cost for the starting vertex in the first stage
    return cost[0];
}

int main() {
    // Example multistage graph represented as an adjacency matrix
    int graph[MAX_STAGES][MAX_VERTICES] = {
        {INF},        // Dummy entry for 0th stage (1-based index)
        {INF, INF, 2, 1, INF, INF},   // 1st stage
        {INF, INF, INF, INF, 4, INF},   // 2nd stage
        {INF, INF, INF, INF, INF, 1},      // 3rd stage
        {INF, INF, INF, INF, INF, 3},      // 4th stage
        {INF}        // 5th stage
    };

    int numStages = MAX_STAGES - 1; // Number of stages excluding the dummy entry

    int minCost = findMinCost(graph, numStages);

    cout << "Minimum cost: " << minCost << endl;

    return 0;
}
