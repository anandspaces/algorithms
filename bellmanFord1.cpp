#include <iostream>

using namespace std;

const int MAX_VERTICES = 10;
const int MAX_EDGES = 20;
const int INF = 1e9; // A large constant value to represent infinity

class Edge {
public:
    int src, dest, weight;
};

class Graph {
private:
    Edge edges[MAX_EDGES];
    int numVertices, numEdges;

public:
    Graph(int vertices, int edges) : numVertices(vertices), numEdges(edges) {}

    void addEdge(int src, int dest, int weight) {
        edges[src * numVertices + dest].src = src;
        edges[src * numVertices + dest].dest = dest;
        edges[src * numVertices + dest].weight = weight;
    }

    void bellmanFord(int source) {
        int distance[MAX_VERTICES];

        // Initialize distances from the source to all vertices as infinite
        for (int i = 0; i < numVertices; ++i) {
            distance[i] = INF;
        }
        distance[source] = 0;

        // Relax edges repeatedly
        for (int i = 1; i <= numVertices - 1; ++i) {
            for (int j = 0; j < numEdges; ++j) {
                int u = edges[j].src;
                int v = edges[j].dest;
                int w = edges[j].weight;
                if (distance[u] != INF && distance[u] + w < distance[v]) {
                    distance[v] = distance[u] + w;
                }
            }
        }

        // Check for negative cycles
        for (int i = 0; i < numEdges; ++i) {
            int u = edges[i].src;
            int v = edges[i].dest;
            int w = edges[i].weight;
            if (distance[u] != INF && distance[u] + w < distance[v]) {
                cout << "Graph contains negative cycle!" << endl;
                return;
            }
        }

        // Print the shortest distances
        cout << "Shortest distances from source " << source << " to all other vertices:" << endl;
        for (int i = 0; i < numVertices; ++i) {
            cout << "Vertex " << i << ": ";
            if (distance[i] == INF) {
                cout << "INFINITY" << endl;
            } else {
                cout << distance[i] << endl;
            }
        }
    }
};

int main() {
    int numVertices = 5;
    int numEdges = 8;

    Graph graph(numVertices, numEdges);

    // Add edges (src, dest, weight)
    graph.addEdge(0, 1, -1);
    graph.addEdge(0, 2, 4);
    graph.addEdge(1, 2, 3);
    graph.addEdge(1, 3, 2);
    graph.addEdge(1, 4, 2);
    graph.addEdge(3, 2, 5);
    graph.addEdge(3, 1, 1);
    graph.addEdge(4, 3, -3);

    int source = 0;
    graph.bellmanFord(source);

    return 0;
}
