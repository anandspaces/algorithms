#include <iostream>
using namespace std;

const int MAX_VERTICES = 100;
const int MAX_EDGES = 100;

struct Edge {
    int src, dest, weight;
};

bool compareEdges(const Edge& a, const Edge& b) {
    return a.weight < b.weight;
}

class Kruskal {
private:
    int parent[MAX_VERTICES];
    Edge edges[MAX_EDGES];
    int numVertices, numEdges;

public:
    Kruskal(int n, int m) : numVertices(n), numEdges(m) {}

    void addEdge(int src, int dest, int weight) {
        edges[numEdges].src = src;
        edges[numEdges].dest = dest;
        edges[numEdges].weight = weight;
        ++numEdges;
    }

    int find(int v) {
        if (parent[v] == -1)
            return v;
        return find(parent[v]);
    }

    void unionSets(int x, int y) {
        int xRoot = find(x);
        int yRoot = find(y);
        parent[xRoot] = yRoot;
    }

    void kruskalMST() {
        sortEdges();

        int mstWeight = 0;
        fill(parent, parent + numVertices, -1);

        cout << "Edges in the Minimum Spanning Tree:" << endl;
        for (int i = 0; i < numEdges; ++i) {
            int srcRoot = find(edges[i].src);
            int destRoot = find(edges[i].dest);

            if (srcRoot != destRoot) {
                cout << edges[i].src << " - " << edges[i].dest << " : " << edges[i].weight << endl;
                mstWeight += edges[i].weight;
                unionSets(srcRoot, destRoot);
            }
        }

        cout << "Total weight of the Minimum Spanning Tree: " << mstWeight << endl;
    }

    void sortEdges() {
        for (int i = 0; i < numEdges - 1; ++i) {
            for (int j = 0; j < numEdges - i - 1; ++j) {
                if (edges[j].weight > edges[j + 1].weight) {
                    swap(edges[j], edges[j + 1]);
                }
            }
        }
    }
};

int main() {
    int numVertices = 4;
    int numEdges = 5;

    Kruskal kruskal(numVertices, numEdges);

    kruskal.addEdge(0, 1, 10);
    kruskal.addEdge(0, 2, 6);
    kruskal.addEdge(0, 3, 5);
    kruskal.addEdge(1, 3, 15);
    kruskal.addEdge(2, 3, 4);

    kruskal.kruskalMST();

    return 0;
}
