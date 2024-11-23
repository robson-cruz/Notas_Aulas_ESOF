
import java.util.Scanner;

public class CheckTheSum {
    Scanner scanner = new Scanner(System.in);

    /**
     * check20 method
     * 
     * Write a program that reads the numbers a, b, c and checks if there's a pair of them that adds up to exactly 20.* The program must output true or false.
     * 
     * Sample Input 1:
     * 1 2 3
     * Sample Output 1:
     * false
     * 
     * Sample Input 2:
     * 4 16 7
     * Sample Output 2:
     * true
     */
    public boolean check20 () {
        boolean checkSum20;
        int a, b, c;

        System.out.print("\nInput the first integer number: ");
        a = scanner.nextInt();
        System.out.print("\nInput the second integer number: ");
        b = scanner.nextInt();
        System.out.print("\nInput the third integer number: ");
        c = scanner.nextInt();

        checkSum20 = a + b == 20 || a + c == 20 || b + c == 20;
        
        return checkSum20;
    }
}