#include <iostream>
using namespace std;

const int MAX_VERTICES = 100;  // Adjust the maximum number of vertices as needed
const int INF = 1e9;  // A large constant value to represent infinity

void floydWarshall(int graph[MAX_VERTICES][MAX_VERTICES], int numVertices) {
    // Initialize the distance matrix with the given graph
    int dist[MAX_VERTICES][MAX_VERTICES];
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            dist[i][j] = graph[i][j];
        }
    }

    // Iterate through all vertices as intermediate vertices
    for (int k = 0; k < numVertices; ++k) {
        // Pick all vertices as source one by one
        for (int i = 0; i < numVertices; ++i) {
            // Pick all vertices as destination for the above source
            for (int j = 0; j < numVertices; ++j) {
                // If vertex k is on the shortest path from i to j, then update the value
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Print the shortest distances between every pair of vertices
    cout << "All Pairs Shortest Path Matrix:\n";
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            if (dist[i][j] == INF) {
                cout << "INF\t";
            } else {
                cout << dist[i][j] << "\t";
            }
        }
        cout << endl;
    }
}

int main() {
    // Example graph represented as an adjacency matrix
    int graph[MAX_VERTICES][MAX_VERTICES] = {
        {0, 5, INF, 10},
        {INF, 0, 3, INF},
        {INF, INF, 0, 1},
        {INF, INF, INF, 0}
    };

    int numVertices = 4;  // Number of vertices in the graph

    floydWarshall(graph, numVertices);

    return 0;
}
