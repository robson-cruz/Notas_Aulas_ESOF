package numbers;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter a natural number:");
        int number = scanner.nextInt();

        String lastDigit = "";

        // Check if the number is natural
        if (number <= 0) {
            System.out.println("This number is not natural!");
            return;
        }

        String digits = String.valueOf(number);
        String[] arrayDigits = new String[digits.length()];

        for (int i = 0; i < digits.length(); i++) {
            arrayDigits[i] = String.valueOf(digits.charAt(i));
        }

        lastDigit = arrayDigits[digits.length() - 1];

        if (number % 2 == 0 && number % 7 == 0) {
            System.out.println("This number is Even.");
            System.out.println("It is a Buzz number.");
            System.out.println("Explanation:\n" + number + " is divisible by 7.");
        } else if (number % 2 == 0) {
            System.out.println("This number is Even.");
            System.out.println("It is not a Buzz number.");
            System.out.println("Explanation:\n" + number + " is neither divisible by 7 nor does it end with 7.");
        } else {
            if (number % 7 == 0 && lastDigit.equals("7")) {
                System.out.println("This number is Odd.");
                System.out.println("It is a Buzz number.");
                System.out.println("Explanation:\n" + number + " is divisible by 7 and ends with 7.");
            } else if (lastDigit.equals("7")) {
                System.out.println("This number is Odd.");
                System.out.println("It is a Buzz number.");
                System.out.println("Explanation:\n" + number + " ends with 7.");
            } else if (number % 7 == 0) {
                System.out.println("This number is Odd.");
                System.out.println("It is a Buzz number.");
                System.out.println("Explanation:\n" + number + " is divisible by 7.");
            } else {
                System.out.println("This number is Odd.");
                System.out.println("It is not a Buzz number.");
                System.out.println("Explanation:\n" + number + " is neither divisible by 7 nor does it end with 7.");
            }
        }
    }
}