package numerals.systems.binary;

import java.util.Scanner;

import static java.lang.Math.pow;

public class Convertion {
    public static void toBinary() {
        System.out.println("Enter integer:");
        Scanner scanner = new Scanner(System.in);
        int number = scanner.nextInt();

        StringBuilder binary = new StringBuilder();

        while (number > 0) {
            int mod = number % 2;
            binary.append(mod);  // Append the remainder (0 or 1)
            number = number / 2;   // Divide the number by 2
        }

        System.out.println(binary.reverse());
    }

    public static void toDecimal() {
        System.out.println("Enter Binary:");
        Scanner scanner = new Scanner(System.in);
        String binary = scanner.nextLine();

        int decimal = 0;
        StringBuilder steps = new StringBuilder();

        for (int i = 1; i <= binary.length(); i++) {
            int digit = Integer.parseInt(String.valueOf(binary.charAt(i - 1)));
            int exponent = binary.length() - i;
            decimal += (int) (digit * pow(2, binary.length() - i));
            if (i < binary.length()) {
                steps.append(digit);
                steps.append(".2^");
                steps.append(exponent);
                steps.append(" + ");
            } else {
                steps.append(digit);
                steps.append(".2^");
                steps.append(exponent);
            }
        }

        System.out.println(steps + " = " + decimal);
    }
}
