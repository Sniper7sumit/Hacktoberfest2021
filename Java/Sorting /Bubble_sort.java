
/**
 * @author Kritika Srivastava
 * @since October 09, 2021
 *
 * Program Description - Bubble sort Code
 */
import java.util.Scanner;

class Bubble_sort {
    public static void main(String[] args) {
        Scanner kb = new Scanner(System.in);

        // Input
        System.out.println("Enter size of array:");
        int n = kb.nextInt(); // Size of array
        int arr[] = new int[n];
        System.out.println("Enter array elements:");
        for (int i = 0; i < n; i++) {
            arr[i] = kb.nextInt();
        }

        // Bubble sort Algorithm

        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= n - i - 1; j++) {
                if (arr[j - 1] > arr[j]) {
                    int t = arr[j - 1];
                    arr[j - 1] = arr[j];
                    arr[j] = t;
                }
            }
        }
        System.out.println("The numbers arranged in ascending order (bubble sort)are:");
        for (int i = 0; i < n; i++) {
            System.out.println(arr[i]);
        }

    }
}