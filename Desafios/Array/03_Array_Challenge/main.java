import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read the length of the array
        int array_length = scanner.nextInt();
        int[] array = new int[array_length];
        
        // Populate the array
        for (int i = 0; i < array.length; i++) {
            array[i] = scanner.nextInt();
        }
        // Read 'n'
        int n = scanner.nextInt();
        scanner.close();
        
        // Sum the elements greater than 'n'
        int sum = 0;
        for (int i = 0; i < array.length; i++) {
            if (array[i] > n) {
                sum += array[i];
            }
        }
        
        // Output the result
        System.out.println(sum);
    }
}