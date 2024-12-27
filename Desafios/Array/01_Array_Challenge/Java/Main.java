import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int min_value = Integer.MAX_VALUE;
        
        int len = scanner.nextInt();
        int[] array = new int[len];
        
        for (int i = 0; i < array.length; i++) {
            array[i] = scanner.nextInt();
        }
        scanner.close();
        
        for (int i = 0; i < array.length; i++) {
            if (array[i] < min_value) {
                min_value = array[i];
            }
        }
        
        System.out.println(min_value);
        
    }
}