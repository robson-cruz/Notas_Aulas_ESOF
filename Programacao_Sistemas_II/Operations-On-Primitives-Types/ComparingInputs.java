import java.util.Scanner;

public class ComparingInputs {
    /**
     * Comparing two integer inputs
     * Write a java program that scans two integer inputs,
     * compares them and prints if the first is less than, equal to or greater than the second one.
     * For comparison use these statements 'less than', 'equal to' and 'greater than'.
     * 
     * Sample Input 1:
     * 3
     * 7
     * Sample Output 1:
     * less than
     * 
     * Sample Input 2:
     * 5
     * 5
     * equal to
     * @return 
     */
    public String ComparingTwoIntegerInputs () {
        String str;
        Scanner scanner = new Scanner(System.in);

        // Get the first integer from user input
        int num1 = scanner.nextInt();

        // Get the second integer from user input
        int num2 = scanner.nextInt();

        if (num1 == num2) {
            str = "equal to";
        } else if (num1 > num2) {
            str = "greater than";
        } else {
            str = "less than";
        }
        return str;
    }
}
