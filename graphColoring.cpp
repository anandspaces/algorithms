#include <iostream>

using namespace std;

const int MAX_VERTICES = 10;

// Function to check if it's safe to color a vertex with the given color
bool isSafe(int vertex, int graph[MAX_VERTICES][MAX_VERTICES], int color[], int c, int numVertices) {
    for (int i = 0; i < numVertices; ++i) {
        if (graph[vertex][i] && color[i] == c) {
            return false;
        }
    }
    return true;
}

// Recursive function to color the graph using backtracking
bool graphColoringUtil(int graph[MAX_VERTICES][MAX_VERTICES], int m, int color[], int vertex, int numVertices) {
    if (vertex == numVertices) {
        // All vertices are colored, print the solution
        cout << "Vertex Colors: ";
        for (int i = 0; i < numVertices; ++i) {
            cout << color[i] << " ";
        }
        cout << endl;
        return true;
    }

    for (int c = 1; c <= m; ++c) {
        if (isSafe(vertex, graph, color, c, numVertices)) {
            color[vertex] = c; // Assign color

            // Recur to color the rest of the vertices
            if (graphColoringUtil(graph, m, color, vertex + 1, numVertices)) {
                return true;
            }

            // If assigning color c doesn't lead to a solution, backtrack
            color[vertex] = 0;
        }
    }

    return false;
}

// Function to color the graph with at most m colors
void graphColoring(int graph[MAX_VERTICES][MAX_VERTICES], int m, int numVertices) {
    int color[MAX_VERTICES] = {0}; // Initialize colors with 0

    if (!graphColoringUtil(graph, m, color, 0, numVertices)) {
        cout << "Solution does not exist!" << endl;
    }
}

int main() {
    // Example graph represented as an adjacency matrix
    int graph[MAX_VERTICES][MAX_VERTICES] = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}
    };

    int m = 3; // Number of colors

    int numVertices = sizeof(graph) / sizeof(graph[0]);

    graphColoring(graph, m, numVertices);

    return 0;
}
