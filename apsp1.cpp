#include <iostream>

using namespace std;

const int MAX_VERTICES = 100;

class AllPairsShortestPath {
private:
    int graph[MAX_VERTICES][MAX_VERTICES];
    int numVertices;

public:
    AllPairsShortestPath(int n) : numVertices(n) {
        // Initialize the graph with adjacency matrix representation
        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                if (i == j) {
                    graph[i][j] = 0; // Distance to itself is 0
                } else {
                    graph[i][j] = -1; // Initialize with a large value (use -1 as infinity)
                }
            }
        }
    }

    void addEdge(int u, int v, int weight) {
        graph[u][v] = weight;
    }

    void floydWarshall() {
        for (int k = 0; k < numVertices; ++k) {
            for (int i = 0; i < numVertices; ++i) {
                for (int j = 0; j < numVertices; ++j) {
                    if (graph[i][k] != -1 && graph[k][j] != -1) {
                        // Avoid integer overflow by checking for -1 (infinity)
                        if (graph[i][j] == -1 || graph[i][k] + graph[k][j] < graph[i][j]) {
                            graph[i][j] = graph[i][k] + graph[k][j];
                        }
                    }
                }
            }
        }
    }

    void printShortestPaths() {
        cout << "Shortest paths between vertices:\n";
        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                cout << "Vertex " << i << " to " << j << ": ";
                if (graph[i][j] == -1) {
                    cout << "INF";
                } else {
                    cout << graph[i][j];
                }
                cout << endl;
            }
        }
    }
};

int main() {
    int numVertices = 4;
    AllPairsShortestPath apsp(numVertices);

    apsp.addEdge(0, 1, 5);
    apsp.addEdge(0, 3, 10);
    apsp.addEdge(1, 2, 3);
    apsp.addEdge(2, 3, 1);

    apsp.floydWarshall();
    apsp.printShortestPaths();

    return 0;
}
