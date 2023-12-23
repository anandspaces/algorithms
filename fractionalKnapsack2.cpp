#include <iostream>
#include <algorithm>
using namespace std;

// Class for an item which stores weight and corresponding value of Item
class Item {
public:
    int profit, weight;

    // Constructor
    Item(int profit, int weight) {
        this->profit = profit;
        this->weight = weight;
    }
};

// Class representing the fractional knapsack problem
class FractionalKnapsack {
public:
    // Comparison function to sort Item according to profit/weight ratio
    static bool cmp(Item a, Item b) {
        double r1 = (double)a.profit / (double)a.weight;
        double r2 = (double)b.profit / (double)b.weight;
        return r1 > r2;
    }

    // Main greedy function to solve the problem
    double solve(int W, Item arr[], int N) {
        // Sorting Item on basis of ratio
        sort(arr, arr + N, cmp);

        double finalValue = 0.0;

        // Looping through all items
        for (int i = 0; i < N; i++) {
            // If adding Item won't overflow, add it completely
            if (arr[i].weight <= W) {
                W -= arr[i].weight;
                finalValue += arr[i].profit;
            }
            // If we can't add the current Item, add fractional part of it
            else {
                finalValue += arr[i].profit * ((double)W / (double)arr[i].weight);
                break;
            }
        }

        // Returning final value
        return finalValue;
    }
};

// Driver code
int main() {
    int W = 50;
    Item arr[] = { {60, 10}, {100, 20}, {120, 30} };
    int N = sizeof(arr) / sizeof(arr[0]);

    // Creating an instance of FractionalKnapsack
    FractionalKnapsack knapsackSolver;

    // Function call
    cout << knapsackSolver.solve(W, arr, N);

    return 0;
}
