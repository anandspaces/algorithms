public class MergeSort {

    // Merges two subarrays of array[]
    // First subarray is arr[begin..mid]
    // Second subarray is arr[mid+1..end]
    static void merge(int array[], int left, int mid, int right) {
        int subArrayOne = mid - left + 1;
        int subArrayTwo = right - mid;

        // Create temp arrays
        int[] leftArray = new int[subArrayOne];
        int[] rightArray = new int[subArrayTwo];

        // Copy data to temp arrays leftArray[] and rightArray[]
        for (int i = 0; i < subArrayOne; i++)
            leftArray[i] = array[left + i];
        for (int j = 0; j < subArrayTwo; j++)
            rightArray[j] = array[mid + 1 + j];

        int indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
        int indexOfMergedArray = left;

        // Merge the temp arrays back into array[left..right]
        while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
            if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
                array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
                indexOfSubArrayOne++;
            } else {
                array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
                indexOfSubArrayTwo++;
            }
            indexOfMergedArray++;
        }

        // Copy the remaining elements of left[], if there are any
        while (indexOfSubArrayOne < subArrayOne) {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
            indexOfMergedArray++;
        }

        // Copy the remaining elements of right[], if there are any
        while (indexOfSubArrayTwo < subArrayTwo) {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
            indexOfMergedArray++;
        }
    }

    // begin is for the left index and end is the right index of the sub-array of arr to be sorted
    static void mergeSort(int array[], int begin, int end) {
        if (begin < end) {
            int mid = begin + (end - begin) / 2;
            mergeSort(array, begin, mid);
            mergeSort(array, mid + 1, end);
            merge(array, begin, mid, end);
        }
    }

    // Utility function to print an array
    static void printArray(int A[], int size) {
        for (int i = 0; i < size; i++)
            System.out.print(A[i] + " ");
        System.out.println();
    }

    // Driver code
    public static void main(String args[]) {
        int arr[] = { 12, 11, 13, 5, 6, 7 };
        int arrSize = arr.length;

        System.out.println("Given array is:");
        printArray(arr, arrSize);

        mergeSort(arr, 0, arrSize - 1);

        System.out.println("\nSorted array is:");
        printArray(arr, arrSize);
    }
}
