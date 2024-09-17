public class sot {
    // Function to perform the Quicksort algorithm
    public static void quickSort(int[] arr, int low, int high) {
        if (low < high) {
            // Partition the array, arr[pivotIndex] is now at its sorted position
            int pivotIndex = partition(arr, low, high);

            // Recursively sort the sub-arrays on both sides of the pivot
            quickSort(arr, low, pivotIndex - 1);
            quickSort(arr, pivotIndex + 1, high);
        }
    }

    // Function to partition the array and return the pivot index
    private static int partition(int[] arr, int low, int high) {
        int pivot = arr[high];  // Choose the last element as the pivot
        int i = low - 1;

        // Move elements smaller than the pivot to the left
        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(arr, i, j);
            }
        }

        // Move the pivot to its sorted position
        swap(arr, i + 1, high);

        return i + 1;  // Return the index of the pivot
    }

    // Function to swap two elements in an array
    private static void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    public static void main(String[] args) {
        int[] arr = {12, 4, 5, 6, 7, 3, 1, 15};

        System.out.println("Original Array: " + java.util.Arrays.toString(arr));

        quickSort(arr, 0, arr.length - 1);

        System.out.println("Sorted Array: " + java.util.Arrays.toString(arr));
    }
}

