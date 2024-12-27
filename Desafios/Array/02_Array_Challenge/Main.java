import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read the length of the array
        int array_length = scanner.nextInt();
        int[] array = new int[array_length];

        // Populate the array
        for (int i = 0; i < array.length; i++) {
            array[i] = scanner.nextInt();
        }
        scanner.close();

        // Check if the array is sorted
        boolean isSorted = true;
        for (int i = 1; i < array.length; i++) {
            if (array[i] < array[i - 1]) {
                isSorted = false;
                break;
            }
        }

        // Output the result
        System.out.println(isSorted);
    }
}
