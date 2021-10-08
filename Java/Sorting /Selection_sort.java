
/**
 * @author Kritika Srivastava
 * @since October 09, 2021
 *
 * Program Description - Selection sort Code
 */
import java.util.Scanner;

public class Selection_sort {
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

        // Selection sort Algorithm

        for (int i = 0; i < n; i++) {
            int min = i;
            for (int j = i + 1; j < n; j++) {
                if (arr[j] < arr[min])
                    min = j;
            }
            int t = arr[i];
            arr[i] = arr[min];
            arr[min] = t;
        }
        System.out.println("The numbers arranged in ascending order(selection sort) are:");
        for (int i = 0; i < n; i++) {
            System.out.println(arr[i]);
        }

    }
}