// Time Complexity of Exponential Search is O(1) for the best case. O(log2 i) for average or worst case. Where i is the location where search key is present.

class Searching {
    boolean exponentialSearch(int arr[], int key) {
        int lengthOfArray = arr.length;
        if (arr[0] == key) {        // Checking whether first element is the key
            return true;
        }
        // Finding the range in which the element might be present
        int i = 1;
        while (i < lengthOfArray && arr[i] <= key) {
            i = i * 2; // Exponentially increasing value of i.
        }
        return binarySearch(arr, i / 2, Math.min(i, lengthOfArray - 1), key); // calling binary search method on the sub-array
    }

    boolean binarySearch(int arr[], int low, int high, int key) {  // Binary Search Method
        int mid; // to store middle element
        while (low <= high) {
            mid = (low + high) / 2; // Can also do mid = low+(high-low)/2 

            if (arr[mid] == key) {
                return true;
            }
            else if (arr[mid] < key) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return false;
    }
}

public class ExponentialSearch {
    public static void main(String[] args) {
        Searching search = new Searching();

        int arr[] = {1, 3, 6, 7, 10, 12, 15, 19 };  //Sorted Array (Exponential Search does not work in unsorted array)

        if (search.exponentialSearch(arr, 15)) {
            System.out.println("Element found !");
        } else {
            System.out.println("Element not found :( ");
        }
    }
}
