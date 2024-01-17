#include <iostream>
#include <string>
using namespace std;

// Function to find the length of the Longest Common Subsequence
int lcsLength(const string& X, const string& Y, int m, int n, int dp[100][100]) {
    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (X[i - 1] == Y[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[m][n];
}

// Function to find the Longest Common Subsequence
void printLCS(const string& X, const string& Y, int m, int n, const int dp[100][100]) {
    int index = dp[m][n];
    string lcs(index, ' ');

    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcs[--index] = X[i - 1];
            --i;
            --j;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            --i;
        } else {
            --j;
        }
    }

    cout << "Longest Common Subsequence: " << lcs << endl;
}

int main() {
    const string X = "ABCBDAB";
    const string Y = "BDCAB";
    int m = X.length();
    int n = Y.length();

    int dp[100][100];

    int length = lcsLength(X, Y, m, n, dp);

    cout << "Length of Longest Common Subsequence: " << length << endl;

    printLCS(X, Y, m, n, dp);

    return 0;
}
