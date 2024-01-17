#include <iostream>
using namespace std;

// Function to check if there is a subset with the given sum
bool isSubsetSum(int set[], int n, int sum) {
    // If the sum is 0, an empty subset is always possible
    if (sum == 0) {
        return true;
    }

    // If there are no elements left and the sum is not 0, no subset is possible
    if (n == 0 && sum != 0) {
        return false;
    }

    // If the last element is greater than the sum, then ignore it
    if (set[n - 1] > sum) {
        return isSubsetSum(set, n - 1, sum);
    }

    // Check if the sum can be obtained by either including or excluding the last element
    return isSubsetSum(set, n - 1, sum) || isSubsetSum(set, n - 1, sum - set[n - 1]);
}

int main() {
    int set[] = {3, 34, 4, 12, 5, 2};
    int sum = 9;
    int n = sizeof(set) / sizeof(set[0]);

    if (isSubsetSum(set, n, sum)) {
        cout << "Subset with the given sum exists." << endl;
    } else {
        cout << "Subset with the given sum does not exist." << endl;
    }

    return 0;
}
