#include <iostream>
using namespace std;

const int MAX_VERTICES = 10;

// Function to check if a vertex can be added to the Hamiltonian Cycle
bool isSafe(int v, int path[], int pos, int graph[MAX_VERTICES][MAX_VERTICES], int numVertices) {
    // Check if this vertex is an adjacent vertex of the previously added vertex
    if (graph[path[pos - 1]][v] == 0) {
        return false;
    }

    // Check if the vertex has already been included
    for (int i = 0; i < pos; i++) {
        if (path[i] == v) {
            return false;
        }
    }

    return true;
}

// Recursive function to find Hamiltonian Cycle
bool hamiltonianCycleUtil(int graph[MAX_VERTICES][MAX_VERTICES], int path[], int pos, int numVertices) {
    if (pos == numVertices) {
        // All vertices are included in the Hamiltonian Cycle
        // Check if there is an edge from the last added vertex to the first vertex
        if (graph[path[pos - 1]][path[0]] == 1) {
            return true;
        } else {
            return false;
        }
    }

    for (int v = 1; v < numVertices; v++) {
        if (isSafe(v, path, pos, graph, numVertices)) {
            path[pos] = v;

            // Recur to construct the rest of the path
            if (hamiltonianCycleUtil(graph, path, pos + 1, numVertices)) {
                return true;
            }

            // If adding vertex v doesn't lead to a solution, remove it (backtrack)
            path[pos] = -1;
        }
    }

    return false;
}

// Function to find Hamiltonian Cycle in a graph
void hamiltonianCycle(int graph[MAX_VERTICES][MAX_VERTICES], int numVertices) {
    int path[MAX_VERTICES];

    // Initialize path with -1
    fill(path, path + numVertices, -1);

    // Start from the first vertex (0)
    path[0] = 0;

    if (!hamiltonianCycleUtil(graph, path, 1, numVertices)) {
        cout << "Solution does not exist!" << endl;
    } else {
        cout << "Hamiltonian Cycle: ";
        for (int i = 0; i < numVertices; i++) {
            cout << path[i] << " ";
        }
        cout << path[0] << endl;
    }
}

int main() {
    // Example graph represented as an adjacency matrix
    int graph[MAX_VERTICES][MAX_VERTICES] = {
        {0, 1, 0, 1, 0},
        {1, 0, 1, 1, 1},
        {0, 1, 0, 0, 1},
        {1, 1, 0, 0, 1},
        {0, 1, 1, 1, 0}
    };

    int numVertices = 5;

    hamiltonianCycle(graph, numVertices);

    return 0;
}
