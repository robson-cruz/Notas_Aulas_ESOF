package bullscows;

import java.util.HashSet;
import java.util.Random;
import java.util.Scanner;

public class Main {
    // Boolean variable to control when the secre code is reveals
    public static boolean isSecretRevealed = false;

    public static void main(String[] args) {
        // Game greeting
        try (Scanner scanner = new Scanner(System.in)) {
            // Game greeting
            System.out.println("The secret code is prepared: ****.");
            
            // Define variables to control the number of attempts
            int attempt = 1;
            
            // Generates the secrete code
            String secret = generateSecret();
            
            // Prompt the user to guess the secret code
            while (!isSecretRevealed) {  // Ensure at least 2 turns
                System.out.println("\nTurn " + attempt + ". Answer:");
                String userGuess = scanner.next();
                checkBullsAndCows(secret, userGuess);
                attempt ++;
            }
        }
    }

    /**
     * Generates a 4-digit secret code consisting of unique digits.
     * 
     * The method uses a HashSet to ensure that each digit in the secret code is unique.
     * Random digits between 0 and 9 are generated until the secret code contains exactly
     * 4 unique digits. The result is returned as a string.
     * 
     * @return A String representing the 4-digit secret code with unique digits.
     */
    private static String generateSecret() {
        Random random_number = new Random();
        HashSet<Integer> uniqueDigits = new HashSet<>();
        StringBuilder secret = new StringBuilder();

        while (uniqueDigits.size() < 4) {
            int digit = random_number.nextInt(10);
            if (uniqueDigits.add(digit)) {  // Adds the digit to the HashSet if it's unique
                secret.append(digit);  // If unique, append it to the secret code
            }
        }

        return secret.toString();
    }

    /**
    * Checks the user's guess against the secret code and calculates the number of bulls and cows.
    *
    * Bulls: Digits in the guess that match both the value and position in the secret code.
    * Cows: Digits in the guess that exist in the secret code but are in the wrong position.
    *
    * The method prints the grade (number of bulls and cows) for the current guess. If the number
    * of bulls equals the length of the secret code (4), the game ends, and the secret code is revealed.
    *
    * @param secret    The 4-digit secret code as a String with unique digits.
    * @param userGuess The user's 4-digit guess as a String.
    *
    * Example:
    * If the secret code is "4931" and the user's guess is "1234":
    * - Bulls: 1 (digit '3' is in the correct position).
    * - Cows: 2 (digits '1' and '4' are present but in the wrong positions).
    * The method prints: "Grade: 1 bull and 2 cows."
    */
    private static void checkBullsAndCows(String secret, String userGuess) {
        int bulls = 0;
        int cows = 0;

        // Count bulls
        for (int i = 0 ; i < secret.length(); i++) {
            if (userGuess.charAt(i) == secret.charAt(i)) {
                bulls += 1;
            }
        }

        // Count cows
        for (int i = 0; i < secret.length(); i++) {
            if (userGuess.charAt(i) != secret.charAt(i) && secret.contains(String.valueOf(userGuess.charAt(i)))) {
                cows++;
            }
        }

        // Print the grade
        if (bulls == 4) {
            System.out.println("Grade: " + bulls + " bulls.\nCongrats! The secret code is " + secret + ".");
            isSecretRevealed = true;
        } else if (bulls == 1 && cows == 0) {
            System.out.println("Grade: " + bulls + " bull.");
        } else if(cows == 1 && bulls == 0) {
            System.out.println("Grade: " + cows + " cow.");
        } else if(bulls == 0 && cows == 0) {
            System.out.println("Grade: None.");
        } else if(bulls > cows) {
            System.out.println("Grade: " + bulls + " bulls.");
        } else if (bulls == cows) {
            System.out.println("Grade: " + bulls + " bull and " + cows + " cow.");
        } else {
            System.out.println("Grade: " + cows + " cows.");
        }
    }
}
