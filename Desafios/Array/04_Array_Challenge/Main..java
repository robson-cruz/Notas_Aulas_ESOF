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
        scanner.close();
        
        // Get the index of the maximum value
        int max_value = Integer.MIN_VALUE;
        int index_max = 0;
        for (int i = 0; i < array.length; i++) {
            if (array[i] > max_value) {
                max_value = array[i];
                index_max = i;
            }
        }
        System.out.println(index_max);
    }
}