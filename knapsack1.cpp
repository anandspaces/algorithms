#include <iostream>
using namespace std;

const int MAX_ITEMS = 100;

struct Item {
    char id;
    int weight;
    int value;
};

class Knapsack01 {
private:
    Item items[MAX_ITEMS];
    int numItems;

public:
    Knapsack01(int n) : numItems(n) {}

    void addItem(char id, int weight, int value) {
        items[numItems].id = id;
        items[numItems].weight = weight;
        items[numItems].value = value;
        ++numItems;
    }

    void knapsack01(int capacity) {
        int dp[MAX_ITEMS + 1][capacity + 1];

        // Initialize the dynamic programming table
        for (int i = 0; i <= numItems; ++i) {
            for (int w = 0; w <= capacity; ++w) {
                if (i == 0 || w == 0) {
                    dp[i][w] = 0;
                } else if (items[i - 1].weight <= w) {
                    dp[i][w] = max(dp[i - 1][w], items[i - 1].value + dp[i - 1][w - items[i - 1].weight]);
                } else {
                    dp[i][w] = dp[i - 1][w];
                }
            }
        }

        printSelectedItems(dp, capacity);
    }

    void printSelectedItems(const int dp[][100], int capacity) {
        int w = capacity;
        cout << "Selected items in the knapsack:" << endl;

        for (int i = numItems; i > 0 && w > 0; --i) {
            if (dp[i][w] != dp[i - 1][w]) {
                cout << items[i - 1].id << " ";
                w -= items[i - 1].weight;
            }
        }

        cout << endl;
    }
};

int main() {
    int numItems = 4;
    int knapsackCapacity = 5;

    Knapsack01 knapsack(numItems);

    knapsack.addItem('a', 2, 3);
    knapsack.addItem('b', 1, 2);
    knapsack.addItem('c', 3, 4);
    knapsack.addItem('d', 2, 1);

    knapsack.knapsack01(knapsackCapacity);

    return 0;
}
