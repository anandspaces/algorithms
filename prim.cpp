#include <iostream>

using namespace std;

const int MAX_VERTICES = 100;
const int INF = 1e9;

class Prim {
private:
    int graph[MAX_VERTICES][MAX_VERTICES];
    int numVertices;

public:
    Prim(int n) : numVertices(n) {
        // Initialize the graph with INF (representing absence of edge)
        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                graph[i][j] = INF;
            }
        }
    }

    void addEdge(int u, int v, int weight) {
        graph[u][v] = weight;
        graph[v][u] = weight; // Assuming the graph is undirected
    }

    void primMST() {
        int parent[MAX_VERTICES];
        int key[MAX_VERTICES];
        bool inMST[MAX_VERTICES];

        // Initialize keys and MST set
        for (int i = 0; i < numVertices; ++i) {
            key[i] = INF;
            inMST[i] = false;
        }

        // Start with the first vertex
        key[0] = 0;
        parent[0] = -1;

        for (int count = 0; count < numVertices - 1; ++count) {
            int u = minKey(key, inMST);
            inMST[u] = true;

            for (int v = 0; v < numVertices; ++v) {
                if (graph[u][v] != INF && !inMST[v] && graph[u][v] < key[v]) {
                    parent[v] = u;
                    key[v] = graph[u][v];
                }
            }
        }

        printMST(parent);
    }

    int minKey(const int key[], const bool inMST[]) {
        int minIndex, minValue;
        minIndex = minValue = INF;

        for (int v = 0; v < numVertices; ++v) {
            if (!inMST[v] && key[v] < minValue) {
                minValue = key[v];
                minIndex = v;
            }
        }

        return minIndex;
    }

    void printMST(const int parent[]) {
        cout << "Edges in the Minimum Spanning Tree:" << endl;
        for (int i = 1; i < numVertices; ++i) {
            cout << parent[i] << " - " << i << " : " << graph[i][parent[i]] << endl;
        }
    }
};

int main() {
    int numVertices = 5;

    Prim prim(numVertices);

    prim.addEdge(0, 1, 2);
    prim.addEdge(0, 3, 6);
    prim.addEdge(1, 2, 3);
    prim.addEdge(1, 3, 8);
    prim.addEdge(1, 4, 5);
    prim.addEdge(2, 4, 7);
    prim.addEdge(3, 4, 9);

    prim.primMST();

    return 0;
}
