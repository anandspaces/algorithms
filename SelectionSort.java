public class SelectionSort {
    // Function for Selection sort
    static void selectionSort(int arr[], int n) {
        int i, j, minIdx;

        // One by one move the boundary of the unsorted subarray
        for (i = 0; i < n - 1; i++) {

            // Find the minimum element in the unsorted array
            minIdx = i;
            for (j = i + 1; j < n; j++) {
                if (arr[j] < arr[minIdx])
                    minIdx = j;
            }

            // Swap the found minimum element with the first element
            if (minIdx != i)
                swap(arr, minIdx, i);
        }
    }

    // Function to print an array
    static void printArray(int arr[], int size) {
        for (int i = 0; i < size; i++) {
            System.out.print(arr[i] + " ");
        }
    }

    // Utility function to swap elements in the array
    static void swap(int arr[], int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    // Driver program
    public static void main(String args[]) {
        int arr[] = { 64, 25, 12, 22, 11 };
        int n = arr.length;

        // Function Call
        selectionSort(arr, n);
        System.out.println("Sorted array: ");
        printArray(arr, n);
    }
}
