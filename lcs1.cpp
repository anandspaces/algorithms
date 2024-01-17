#include <iostream>
using namespace std;

const int MAX_LENGTH = 100;

class LongestCommonSubsequence {
private:
    char X[MAX_LENGTH];
    char Y[MAX_LENGTH];
    int m, n;

public:
    LongestCommonSubsequence(const char* strX, const char* strY) {
        m = customStrLen(strX);
        n = customStrLen(strY);

        if (m > MAX_LENGTH || n > MAX_LENGTH) {
            cerr << "Input strings are too long." << endl;
            exit(1);
        }

        customStrCopy(X, strX);
        customStrCopy(Y, strY);
    }

    int findLCSLength() {
        int dp[MAX_LENGTH + 1][MAX_LENGTH + 1];

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

    void printLCS() {
        int lcsLength = findLCSLength();
        char lcs[MAX_LENGTH + 1];
        lcs[lcsLength] = '\0';

        int i = m, j = n;
        while (i > 0 && j > 0) {
            if (X[i - 1] == Y[j - 1]) {
                lcs[--lcsLength] = X[i - 1];
                --i;
                --j;
            } else if (findLCSLength() == findLCSLength() - 1) {
                --i;
            } else {
                --j;
            }
        }

        cout << "Longest Common Subsequence: " << lcs << endl;
    }

private:
    int customStrLen(const char* str) {
        int len = 0;
        while (str[len] != '\0') {
            ++len;
        }
        return len;
    }

    void customStrCopy(char* dest, const char* src) {
        int i = 0;
        while ((dest[i] = src[i]) != '\0') {
            ++i;
        }
    }
};

int main() {
    const char X[] = "ABCBDAB";
    const char Y[] = "BDCAB";

    LongestCommonSubsequence lcs(X, Y);

    int length = lcs.findLCSLength();
    cout << "Length of Longest Common Subsequence: " << length << endl;

    lcs.printLCS();

    return 0;
}
