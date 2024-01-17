public class BubbleSort {
    // An optimized version of Bubble Sort
    static void bubbleSort(int arr[], int n) {
        boolean swapped;
        for (int i = 0; i < n - 1; i++) {
            swapped = false;
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    // Swap elements
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                    swapped = true;
                }
            }

            // If no two elements were swapped by inner loop, then break
            if (!swapped)
                break;
        }
    }

    // Function to print an array
    static void printArray(int arr[], int size) {
        for (int i = 0; i < size; i++)
            System.out.print(arr[i] + " ");
    }

    // Driver program to test above functions
    public static void main(String args[]) {
        int arr[] = { 64, 34, 25, 12, 22, 11, 90 };
        int N = arr.length;

        bubbleSort(arr, N);
        System.out.println("Sorted array:");
        printArray(arr, N);
    }
}
