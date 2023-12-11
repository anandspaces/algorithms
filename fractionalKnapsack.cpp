#include <iostream>

using namespace std;

const int MAX_ITEMS = 100;

struct Item {
    char id;
    int weight;
    int value;
};

class FractionalKnapsack {
private:
    Item items[MAX_ITEMS];
    int numItems;

public:
    FractionalKnapsack(int n) : numItems(n) {}

    void addItem(char id, int weight, int value) {
        items[numItems].id = id;
        items[numItems].weight = weight;
        items[numItems].value = value;
        ++numItems;
    }

    void knapsackFractional(int capacity) {
        // Sort items based on value per unit weight in descending order
        sortItems();

        int currentWeight = 0;
        double totalValue = 0.0;

        for (int i = 0; i < numItems; ++i) {
            if (currentWeight + items[i].weight <= capacity) {
                currentWeight += items[i].weight;
                totalValue += items[i].value;
            } else {
                int remainingCapacity = capacity - currentWeight;
                totalValue += items[i].value * (static_cast<double>(remainingCapacity) / items[i].weight);
                break;
            }
        }

        printKnapsack(totalValue);
    }

    void sortItems() {
        for (int i = 0; i < numItems - 1; ++i) {
            for (int j = 0; j < numItems - i - 1; ++j) {
                double valuePerUnit1 = static_cast<double>(items[j].value) / items[j].weight;
                double valuePerUnit2 = static_cast<double>(items[j + 1].value) / items[j + 1].weight;

                if (valuePerUnit1 < valuePerUnit2) {
                    swap(items[j], items[j + 1]);
                }
            }
        }
    }

    void printKnapsack(double totalValue) {
        cout << "Selected items in the knapsack:" << endl;

        for (int i = 0; i < numItems; ++i) {
            cout << items[i].id << " ";
        }

        cout << "\nTotal value in the knapsack: " << totalValue << endl;
    }
};

int main() {
    int numItems = 4;
    int knapsackCapacity = 25;

    FractionalKnapsack knapsack(numItems);

    knapsack.addItem('a', 12, 4);
    knapsack.addItem('b', 2, 2);
    knapsack.addItem('c', 1, 10);
    knapsack.addItem('d', 4, 1);

    knapsack.knapsackFractional(knapsackCapacity);

    return 0;
}
