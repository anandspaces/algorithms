// Class for an item which stores weight and corresponding value of Item
class Item {
  late int profit;
  late int weight;

  // Constructor
  Item(int profit, int weight) {
    this.profit = profit;
    this.weight = weight;
  }
}

// Comparison function to sort Item according to profit/weight ratio
// Comparison function to sort Item according to profit/weight ratio
int cmp(Item a, Item b) {
  double r1 = a.profit / a.weight;
  double r2 = b.profit / b.weight;

  if (r1 > r2) {
    return -1; // Return a negative value for descending order
  } else if (r1 < r2) {
    return 1;  // Return a positive value for descending order
  } else {
    return 0;  // Return 0 for equal values
  }
}

// Main greedy function to solve the problem
double fractionalKnapsack(int W, List<Item> arr) {
  // Sorting Item on basis of ratio
  arr.sort(cmp);

  double finalValue = 0.0;

  // Looping through all items
  for (int i = 0; i < arr.length; i++) {
    // If adding Item won't overflow, add it completely
    if (arr[i].weight <= W) {
      W -= arr[i].weight;
      finalValue += arr[i].profit;
    }
    // If we can't add the current Item, add the fractional part of it
    else {
      finalValue += arr[i].profit * (W / arr[i].weight);
      break;
    }
  }

  // Returning the final value
  return finalValue;
}

// Driver code
void main() {
  int W = 50;
  List<Item> arr = [Item(60, 10), Item(100, 20), Item(120, 30)];

  // Function call
  print(fractionalKnapsack(W, arr));
}
