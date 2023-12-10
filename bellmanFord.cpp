#include <iostream>

using namespace std;

const int INF = 1e9;  // A large constant value to represent infinity

struct Edge {
    int src, dest, weight;
};

void bellmanFord(int graph[][3], int numVertices, int numEdges, int source) {
    // Initialize distances from the source to all vertices as infinite
    int distance[numVertices];
    for (int i = 0; i < numVertices; ++i) {
        distance[i] = INF;
    }
    distance[source] = 0;

    // Relax edges repeatedly
    for (int i = 1; i <= numVertices - 1; ++i) {
        for (int j = 0; j < numEdges; ++j) {
            int u = graph[j][0];
            int v = graph[j][1];
            int w = graph[j][2];
            if (distance[u] != INF && distance[u] + w < distance[v]) {
                distance[v] = distance[u] + w;
            }
        }
    }

    // Check for negative cycles
    for (int i = 0; i < numEdges; ++i) {
        int u = graph[i][0];
        int v = graph[i][1];
        int w = graph[i][2];
        if (distance[u] != INF && distance[u] + w < distance[v]) {
            cout << "Graph contains negative cycle!" << endl;
            return;
        }
    }

    // Print the shortest distances
    cout << "Shortest distances from source " << source << " to all other vertices:\n";
    for (int i = 0; i < numVertices; ++i) {
        cout << "Vertex " << i << ": ";
        if (distance[i] == INF) {
            cout << "INFINITY" << endl;
        } else {
            cout << distance[i] << endl;
        }
    }
}

int main() {
    // Example graph represented by an array of edges {source, destination, weight}
    int graph[][3] = {
        {0, 1, 6}, {0, 2, 5}, {0, 3, 5},
        {1, 4, 3},
        {2, 1, -2}, {2, 4, 1},
        {3, 2, 2},
        {4, 3, -1}, {4, 5, 3},
    };

    int numVertices = 6; // Number of vertices in the graph
    int numEdges = sizeof(graph) / sizeof(graph[0]); // Number of edges in the graph
    int source = 0; // Source vertex

    bellmanFord(graph, numVertices, numEdges, source);

    return 0;
}
