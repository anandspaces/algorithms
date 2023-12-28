#include <iostream>
using namespace std;

const int MAX_INT = 1e9;  // A large constant value to represent infinity
const int MAX_VERTICES = 5;

// Function to find the vertex with the minimum distance value, from the set of vertices not yet included in the shortest path tree
int minDistance(int dist[], bool sptSet[], int numVertices) {
    int minDist = MAX_INT, minIndex = -1;

    for (int v = 0; v < numVertices; v++) {
        if (!sptSet[v] && dist[v] < minDist) {
            minDist = dist[v];
            minIndex = v;
        }
    }

    return minIndex;
}

// Function to print the constructed distance array
void printSolution(int dist[], int numVertices) {
    cout << "Vertex \t Distance from Source\n";
    for (int i = 0; i < numVertices; i++) {
        cout << i << "\t\t" << dist[i] << endl;
    }
}

// Function to implement Dijkstra's algorithm for a given graph
void dijkstra(int graph[MAX_VERTICES][MAX_VERTICES], int src, int numVertices) {
    int dist[MAX_VERTICES];  // The output array dist[i] holds the shortest distance from src to i

    bool sptSet[MAX_VERTICES];  // sptSet[i] is true if vertex i is included in the shortest path tree or the shortest distance from src to i is finalized

    // Initialize all distances as INFINITE and sptSet[] as false
    for (int i = 0; i < numVertices; i++) {
        dist[i] = MAX_INT;
        sptSet[i] = false;
    }

    // Distance of source vertex from itself is always 0
    dist[src] = 0;

    // Find the shortest path for all vertices
    for (int count = 0; count < numVertices - 1; count++) {
        // Pick the minimum distance vertex from the set of vertices not yet processed
        int u = minDistance(dist, sptSet, numVertices);

        // Mark the picked vertex as processed
        sptSet[u] = true;

        // Update dist value of the adjacent vertices of the picked vertex
        for (int v = 0; v < numVertices; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != MAX_INT && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print the constructed distance array
    printSolution(dist, numVertices);
}

int main() {
    // Example graph represented as an adjacency matrix
    int graph[MAX_VERTICES][MAX_VERTICES] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    int src = 0;  // Source vertex

    dijkstra(graph, src, MAX_VERTICES);

    return 0;
}
