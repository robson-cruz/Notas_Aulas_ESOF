import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Main {
    /*
    * Find the greatest number in a file
    *
    * The dataset_91007.txt file containing a sequence of integers separated by spaces.
    * Find the greatest number in this file.
    * */
    public static void main(String[] args) {
        File file = new File("dataset_91007.txt");

        int maxValue = Integer.MIN_VALUE;

        try (Scanner scanner = new Scanner(file)) {
            while (scanner.hasNext()) {
                int currentNumber = scanner.nextInt();
                if (maxValue < currentNumber) {
                    maxValue = currentNumber;
                }
            }
        } catch (FileNotFoundException e) {
            System.out.println(e.getMessage());
        }

        System.out.println(maxValue);
    }
}