import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String input = scanner.nextLine();

        StringBuilder outputString = new StringBuilder();

        int count = 1; // Initialize count for the first character

        for (int i = 1; i < input.length(); i++) {
            if (input.charAt(i) == input.charAt(i - 1)) {
                count++; // Increment count if the current character matches the previous
            } else {
                // Append the previous character and its count to the output
                outputString.append(input.charAt(i - 1)).append(count);
                count = 1; // Reset count for the new character
            }
        }

        // Append the last character and its count
        outputString.append(input.charAt(input.length() - 1)).append(count);

        System.out.println(outputString);
    }
}
