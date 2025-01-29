import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Main {
    /*
    * The sum of numbers in a file
    *
    * The fdataset_91033.txtile contain a sequence of integers. Each number starts with a new line.
    * The  file contain a sequence of integers. Each number starts with a new line.
    * Write a Java program that calculates the sum of these numbers.
    * */
    public static void main(String[] args) {

        String filePath = "dataset_91033.txt";
        File file = new File(filePath);

        int sum = 0;

        try (Scanner scanner = new Scanner(file)) {
            while (scanner.hasNext()) {
                sum += scanner.nextInt();
            }
        } catch (FileNotFoundException e) {
            System.out.println(e.getMessage());
        }
        System.out.println(sum);
    }
}