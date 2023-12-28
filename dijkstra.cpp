#include <iostream>
using namespace std;

const int MAX_VERTICES = 100;
const int INF = 1e9;

class Dijkstra {
private:
    int graph[MAX_VERTICES][MAX_VERTICES];
    int numVertices;

public:
    Dijkstra(int n) : numVertices(n) {
        // Initialize the graph with INF (representing absence of edge)
        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                graph[i][j] = INF;
            }
        }
    }

    void addEdge(int u, int v, int weight) {
        graph[u][v] = weight;
    }

    void dijkstraShortestPath(int source) {
        int distance[MAX_VERTICES];
        bool visited[MAX_VERTICES];

        // Initialize distances and visited array
        for (int i = 0; i < numVertices; ++i) {
            distance[i] = INF;
            visited[i] = false;
        }

        // Distance from the source to itself is 0
        distance[source] = 0;

        // Find shortest path for all vertices
        for (int count = 0; count < numVertices - 1; ++count) {
            int u = minDistance(distance, visited);
            visited[u] = true;

            for (int v = 0; v < numVertices; ++v) {
                if (!visited[v] && graph[u][v] != INF && distance[u] != INF &&
                    distance[u] + graph[u][v] < distance[v]) {
                    distance[v] = distance[u] + graph[u][v];
                }
            }
        }

        printShortestPaths(source, distance);
    }

    int minDistance(const int distance[], const bool visited[]) {
        int minIndex, minValue;
        minIndex = minValue = INF;

        for (int v = 0; v < numVertices; ++v) {
            if (!visited[v] && distance[v] < minValue) {
                minValue = distance[v];
                minIndex = v;
            }
        }

        return minIndex;
    }

    void printShortestPaths(int source, const int distance[]) {
        cout << "Shortest paths from source " << source << " to all other vertices:" << endl;
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
    int numVertices = 6;

    Dijkstra dijkstra(numVertices);

    dijkstra.addEdge(0, 1, 5);
    dijkstra.addEdge(0, 2, 2);
    dijkstra.addEdge(1, 3, 4);
    dijkstra.addEdge(2, 1, 1);
    dijkstra.addEdge(2, 3, 7);
    dijkstra.addEdge(3, 4, 3);
    dijkstra.addEdge(4, 0, 2);
    dijkstra.addEdge(4, 5, 1);
    dijkstra.addEdge(5, 3, 6);

    int source = 0;

    dijkstra.dijkstraShortestPath(source);

    return 0;
}
