#include <iostream>
using namespace std;

// Function to print subsets with the given sum
void printSubsets(bool** dp, int set[], int n, int sum) {
    if (n == 0 || sum == 0) {
        return;
    }

    if (dp[n][sum]) {
        printSubsets(dp, set, n - 1, sum);
        cout << set[n - 1] << " ";
    } else {
        printSubsets(dp, set, n - 1, sum);
    }
}

// Function to solve the Sum of Subsets problem using dynamic programming
bool isSubsetSum(int set[], int n, int sum) {
    // dp[i][j] is true if there is a subset of set[0..i-1] with the sum equal to j
    bool** dp = new bool*[n + 1];
    for (int i = 0; i <= n; ++i) {
        dp[i] = new bool[sum + 1];
    }

    // Sum 0 is always possible with an empty subset
    for (int i = 0; i <= n; ++i) {
        dp[i][0] = true;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= sum; ++j) {
            // If the current element is greater than the sum, it cannot be included
            if (set[i - 1] > j) {
                dp[i][j] = dp[i - 1][j];
            } else {
                // Check if either the current element is included or excluded
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - set[i - 1]];
            }
        }
    }

    // Print the subset with the given sum
    if (dp[n][sum]) {
        cout << "Subset with the given sum: ";
        printSubsets(dp, set, n, sum);
        cout << endl;

        // Free allocated memory
        for (int i = 0; i <= n; ++i) {
            delete[] dp[i];
        }
        delete[] dp;

        return true;
    } else {
        cout << "No subset with the given sum exists." << endl;

        // Free allocated memory
        for (int i = 0; i <= n; ++i) {
            delete[] dp[i];
        }
        delete[] dp;

        return false;
    }
}

int main() {
    int set[] = {3, 34, 4, 12, 5, 2};
    int sum = 9;
    int n = sizeof(set) / sizeof(set[0]);

    isSubsetSum(set, n, sum);

    return 0;
}
