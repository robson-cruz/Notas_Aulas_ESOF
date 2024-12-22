import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        char letter = scanner.nextLine().charAt(0);
        System.out.println(isVowel(letter) ? "YES" : "NO");
    }
    
    public static boolean isVowel(char ch) {
        /*
        // Define the vowels
        char[] vowels = {'a', 'e', 'i', 'o', 'u'};

        // Convert the input character to lowercase for case-insensitive comparison
        ch = Character.toLowerCase(ch);

        // Check if the character is a vowel
        for (char vowel : vowels) {
            if (ch == vowel) {
                return true; // Return true immediately when a match is found
            }
        }
        return false; // Return false if no match is found
        */
        // A more compact and efficient approach
        return "AEIOUaeiou".indexOf(ch) != -1;
    }
}