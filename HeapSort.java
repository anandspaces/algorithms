public class HeapSort {

    // To heapify a subtree rooted with node i which is an index in arr[].
    // n is the size of the heap
    static void heapify(int arr[], int N, int i) {
        // Initialize largest as root
        int largest = i;

        // left = 2*i + 1
        int l = 2 * i + 1;

        // right = 2*i + 2
        int r = 2 * i + 2;

        // If left child is larger than root
        if (l < N && arr[l] > arr[largest])
            largest = l;

        // If right child is larger than largest so far
        if (r < N && arr[r] > arr[largest])
            largest = r;

        // If the largest is not the root
        if (largest != i) {
            int temp = arr[i];
            arr[i] = arr[largest];
            arr[largest] = temp;

            // Recursively heapify the affected sub-tree
            heapify(arr, N, largest);
        }
    }

    // Main function to do heap sort
    static void heapSort(int arr[], int N) {
        // Build heap (rearrange array)
        for (int i = N / 2 - 1; i >= 0; i--)
            heapify(arr, N, i);

        // One by one extract an element from the heap
        for (int i = N - 1; i > 0; i--) {
            // Move current root to end
            int temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;

            // Call max heapify on the reduced heap
            heapify(arr, i, 0);
        }
    }

    // A utility function to print an array of size n
    static void printArray(int arr[], int N) {
        for (int i = 0; i < N; ++i)
            System.out.print(arr[i] + " ");
        System.out.println();
    }

    // Driver's code
    public static void main(String args[]) {
        int arr[] = { 12, 11, 13, 5, 6, 7 };
        int N = arr.length;

        // Function call
        heapSort(arr, N);

        System.out.println("Sorted array is:");
        printArray(arr, N);
    }
}
