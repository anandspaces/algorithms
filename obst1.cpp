#include <iostream>

using namespace std;

const int MAX_INT = 1e9;  // A large constant value to represent infinity

const int MAX_KEYS = 5;

// Function to find the optimal binary search tree cost
int optimalBSTCost(int keys[], int freq[], int n) {
    int cost[MAX_KEYS][MAX_KEYS];

    // Initialize cost for a single key
    for (int i = 0; i < n; i++) {
        cost[i][i] = freq[i];
    }

    // Calculate cost for chains of increasing length
    for (int chainLen = 2; chainLen <= n; chainLen++) {
        for (int i = 0; i <= n - chainLen + 1; i++) {
            int j = i + chainLen - 1;
            cost[i][j] = MAX_INT;

            // Try making all keys in the current range the root
            for (int k = i; k <= j; k++) {
                int leftCost = (k > i) ? cost[i][k - 1] : 0;
                int rightCost = (k < j) ? cost[k + 1][j] : 0;
                cost[i][j] = min(cost[i][j], leftCost + rightCost + freq[k]);
            }
        }
    }

    return cost[0][n - 1];
}

int main() {
    int keys[] = {10, 12, 20, 35, 46};
    int freq[] = {34, 8, 50, 21, 16};
    int n = sizeof(keys) / sizeof(keys[0]);

    int minCost = optimalBSTCost(keys, freq, n);

    cout << "Minimum cost of optimal BST: " << minCost << endl;

    return 0;
}
