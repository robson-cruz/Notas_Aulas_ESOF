import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Main {
    /*
    * Count even numbers
    *
    * The dataset_91065.txt file contain a sequence of integers. Each number begins a new line.
    * Write a Java program that counts the number of even numbers in this file.
    * You should stop counting either if you get 0 or the last number is reached.
     * */
    public static void main(String[] args) {
        File file = new File("dataset_91065.txt");
        int evenNumbers = 0;

        try (Scanner scanner = new Scanner(file)) {
            while (scanner.hasNext()) {
                int number = scanner.nextInt();
                if (number == 0) {
                    break; // Stop counting if o is encountered
                }
                if (number % 2 == 0) {
                    evenNumbers ++;
                }
            }
        } catch (FileNotFoundException e) {
            System.out.println(e.getMessage());
        }

        System.out.println(evenNumbers);
    }
}