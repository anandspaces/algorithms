public class QuickSort {
    // Partition function
    static int partition(int arr[], int low, int high) {
        // Choose the pivot
        int pivot = arr[high];

        // Index of the smaller element and indicate the right position of the pivot found so far
        int i = (low - 1);

        for (int j = low; j <= high; j++) {
            // If the current element is smaller than the pivot
            if (arr[j] < pivot) {
                // Increment the index of the smaller element
                i++;
                swap(arr, i, j);
            }
        }
        swap(arr, i + 1, high);
        return (i + 1);
    }

    // Quicksort function
    static void quickSort(int arr[], int low, int high) {
        // When low is less than high
        if (low < high) {
            // pi is the partition, return index of the pivot
            int pi = partition(arr, low, high);

            // Recursion call
            // Smaller elements than the pivot go to the left and higher elements go to the right
            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }

    // Utility function to swap elements in the array
    static void swap(int arr[], int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    // Utility function to print array of size n
    static void printArray(int arr[]) {
        int n = arr.length;
        for (int i = 0; i < n; ++i)
            System.out.print(arr[i] + " ");
        System.out.println();
    }

    // Driver's code
    public static void main(String args[]) {
        int arr[] = { 10, 7, 8, 9, 1, 5 };
        int n = arr.length;
        // Function call
        quickSort(arr, 0, n - 1);

        // Print the sorted array
        System.out.println("Sorted Array:");
        printArray(arr);
    }
}
