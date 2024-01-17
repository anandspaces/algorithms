#include <iostream>
using namespace std;

const int MAX_VERTICES = 10;

class TravelingSalesmanProblem {
private:
    int graph[MAX_VERTICES][MAX_VERTICES];
    int numVertices;

public:
    TravelingSalesmanProblem(int n) : numVertices(n) {
        // Initialize the graph with adjacency matrix representation
        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                graph[i][j] = -1; // Initialize with a large value (use -1 as infinity)
            }
        }
    }

    void addEdge(int u, int v, int weight) {
        graph[u][v] = weight;
        graph[v][u] = weight; // Undirected graph
    }

    void generatePermutation(int permutation[], int n) {
        for (int i = 0; i < n; ++i) {
            permutation[i] = i;
        }
    }

    int calculateTourCost(const int tour[], int n) {
        int cost = 0;
        for (int i = 0; i < n - 1; ++i) {
            int u = tour[i];
            int v = tour[i + 1];
            cost += (graph[u][v] == -1) ? 0 : graph[u][v];
        }
        // Add the cost of returning to the starting city
        cost += (graph[tour[n - 1]][tour[0]] == -1) ? 0 : graph[tour[n - 1]][tour[0]];
        return cost;
    }

    void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }

    void permute(int currentTour[], int start, int end, int& minTourCost, int optimalTour[]) {
        if (start == end) {
            int currentTourCost = calculateTourCost(currentTour, numVertices);
            if (currentTourCost < minTourCost) {
                minTourCost = currentTourCost;
                for (int i = 0; i < numVertices; ++i) {
                    optimalTour[i] = currentTour[i];
                }
            }
        } else {
            for (int i = start; i <= end; ++i) {
                swap(currentTour[start], currentTour[i]);
                permute(currentTour, start + 1, end, minTourCost, optimalTour);
                swap(currentTour[start], currentTour[i]); // Backtrack
            }
        }
    }

    void findOptimalTour() {
        int currentTour[MAX_VERTICES];
        generatePermutation(currentTour, numVertices);

        int optimalTour[MAX_VERTICES];
        int minTourCost = calculateTourCost(currentTour, numVertices);

        permute(currentTour, 1, numVertices - 1, minTourCost, optimalTour);

        cout << "Optimal Tour: ";
        for (int i = 0; i < numVertices; ++i) {
            cout << optimalTour[i] << " ";
        }
        cout << optimalTour[0]; // Return to the starting city
        cout << "\nOptimal Tour Cost: " << minTourCost << endl;
    }
};

int main() {
    int numVertices = 4;
    TravelingSalesmanProblem tsp(numVertices);

    tsp.addEdge(0, 1, 10);
    tsp.addEdge(0, 2, 15);
    tsp.addEdge(0, 3, 20);
    tsp.addEdge(1, 2, 35);
    tsp.addEdge(1, 3, 25);
    tsp.addEdge(2, 3, 30);

    tsp.findOptimalTour();

    return 0;
}
