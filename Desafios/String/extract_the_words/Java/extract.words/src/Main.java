import java.util.HashMap;
import java.util.regex.Pattern;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter a string:");
        String inputString = scanner.nextLine();

        // Define a pattern to match non-alphabetical characters
        Pattern pattern = Pattern.compile("[^A-Za-z]+");

        // Split the input string using the non-alphabetical pattern
        String[] partialResult = inputString.split(pattern.pattern());

        // Build the final string, count total words, and track word frequencies
        StringBuilder finalString = new StringBuilder();
        HashMap<String, Integer> wordCount = new HashMap<>();

        for (String str : partialResult) {
            if (!str.isEmpty()) {  // Avoid adding empty strings
                finalString.append(str).append(" ");
                // How many times each word appears
                wordCount.put(str, wordCount.getOrDefault(str, 0) + 1);  // Update word frequency
            }
        }

        System.out.println("Extracted Words: " + finalString.toString().trim());
        System.out.println("Number of Words: " + wordCount.values().stream().mapToInt(Integer::intValue).sum());
        System.out.println("Word Frequencies:");
        wordCount.forEach((key, value) -> System.out.printf("%s: %d\n", key, value));

    }
}