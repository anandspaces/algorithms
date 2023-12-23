#include <iostream>

using namespace std;

const int MAX_VERTICES = 100;
const int MAX_EDGES = 100;

struct Edge {
    int src, dest, weight;
};

class Kruskal {
private:
    Edge edges[MAX_EDGES];
    int parent[MAX_VERTICES];
    int rank[MAX_VERTICES];
    int vertices, edgesCount;

public:
    Kruskal(int v) : vertices(v), edgesCount(0) {
        for (int i = 0; i < vertices; ++i) {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    void addEdge(int src, int dest, int weight) {
        edges[edgesCount].src = src;
        edges[edgesCount].dest = dest;
        edges[edgesCount].weight = weight;
        edgesCount++;
    }

    int find(int v) {
        if (v != parent[v]) {
            parent[v] = find(parent[v]);
        }
        return parent[v];
    }

    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else {
            parent[rootX] = rootY;
            rank[rootY]++;
        }
    }

    // Basic bubble sort
    void sortEdges() {
        for (int i = 0; i < edgesCount - 1; ++i) {
            for (int j = 0; j < edgesCount - i - 1; ++j) {
                if (edges[j].weight > edges[j + 1].weight) {
                    Edge temp = edges[j];
                    edges[j] = edges[j + 1];
                    edges[j + 1] = temp;
                }
            }
        }
    }

    void kruskalMST() {
        sortEdges();

        cout << "Minimum Spanning Tree:" << endl;
        for (int i = 0; i < edgesCount; ++i) {
            int rootSrc = find(edges[i].src);
            int rootDest = find(edges[i].dest);

            if (rootSrc != rootDest) {
                cout << edges[i].src << " - " << edges[i].dest << " : " << edges[i].weight << endl;
                unionSets(rootSrc, rootDest);
            }
        }
    }
};

int main() {
    Kruskal kruskal(4);

    kruskal.addEdge(0, 1, 10);
    kruskal.addEdge(0, 2, 6);
    kruskal.addEdge(0, 3, 5);
    kruskal.addEdge(1, 3, 15);
    kruskal.addEdge(2, 3, 4);

    kruskal.kruskalMST();

    return 0;
}
