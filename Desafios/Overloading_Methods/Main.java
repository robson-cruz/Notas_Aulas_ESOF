import java.util.Scanner;

public class Main {
	/**
     * calculate method
     * Multiplies two integers (n1 * n2) and returns the result.
	 * @param n1
	 * @param n2
	 * @return
	 */
	public static long calculate(int n1, int n2) {
		long result = n1 * n2;
		return result;
	}
	/**
     * calculate method
     * Adds the first two integers (n1 + n2) and then multiplies the sum by the
     * third integer ((n1 + n2) * n3), and returns the result.
	 * @param n1
	 * @param n2
	 * @param n3
	 * @return
	 */

	public static long calculate(int n1, int n2, int n3) {
		long result = (n1 + n2) * n3;
		return result;
	}
	
	/**
	 * Method to read input from user and separate the integers 
	 */
	public static void processInputAndCallFunctions() {
        Scanner scanner = new Scanner(System.in);

		// Loop until the user provides valid input (2 or 3 integers)
        while (true) {
            try {
                System.out.println("Please enter 2 or 3 integers separated by spaces:");
                String inputString = scanner.nextLine();
                String[] strArr = inputString.split(" ");
                
                if (strArr.length == 2 || strArr.length == 3) {
                    int[] intArr = new int[strArr.length];
                    for (int i = 0; i < strArr.length; i++) {
                        intArr[i] = Integer.parseInt(strArr[i]);
                    }

                    // Call the appropriate function depending on the number of integers in the input
                    if (intArr.length == 2) {
                        // Call calculate(int, int) 
                        System.out.println(calculate(intArr[0], intArr[1]));
                    } else if (intArr.length == 3) {
                        // Call calculate(int, int, int)
                        System.out.println(calculate(intArr[0], intArr[1], intArr[2]));
                    }
                    break;  // Exit the loop when valid input is received
                } else {
                    System.out.println("Invalid input. Please enter exactly 2 or 3 integers.");
                }
            } catch (NumberFormatException e) {
                System.out.println("Invalid input. Please enter only integers.");
            }
        }
        // Close the scanner after usage
        scanner.close();
	}

	public static void main(String[] args) {
		processInputAndCallFunctions();
	}
}