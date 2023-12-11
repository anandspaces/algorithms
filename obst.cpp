#include <iostream>

using namespace std;

const int MY_INT_MAX = 2147483647;  // A large constant value

const int MAX_KEYS = 100;

class OptimalBST {
private:
    int keys[MAX_KEYS];
    int freq[MAX_KEYS];
    int numKeys;

public:
    OptimalBST(int n) : numKeys(n) {}

    void setKeys(int keyArray[], int freqArray[]) {
        for (int i = 0; i < numKeys; ++i) {
            keys[i] = keyArray[i];
            freq[i] = freqArray[i];
        }
    }

    int optimalBSTCost() {
        int cost[MAX_KEYS][MAX_KEYS];

        // Initialize the cost table
        for (int i = 0; i < numKeys; ++i) {
            cost[i][i] = freq[i];
        }

        // Build the cost table
        for (int len = 2; len <= numKeys; ++len) {
            for (int i = 0; i <= numKeys - len + 1; ++i) {
                int j = i + len - 1;
                cost[i][j] = MY_INT_MAX;  // Use your own constant

                int sum = 0;
                for (int k = i; k <= j; ++k) {
                    sum += freq[k];
                }

                for (int k = i; k <= j; ++k) {
                    int val = ((k > i) ? cost[i][k - 1] : 0) +
                              ((k < j) ? cost[k + 1][j] : 0) + sum;

                    if (val < cost[i][j]) {
                        cost[i][j] = val;
                    }
                }
            }
        }

        return cost[0][numKeys - 1];
    }
};

int main() {
    int numKeys = 5;
    int keys[] = {10, 12, 16, 21, 25};
    int freq[] = {4, 2, 6, 3, 1};

    OptimalBST obst(numKeys);
    obst.setKeys(keys, freq);

    int cost = obst.optimalBSTCost();

    cout << "Optimal BST cost: " << cost << endl;

    return 0;
}
