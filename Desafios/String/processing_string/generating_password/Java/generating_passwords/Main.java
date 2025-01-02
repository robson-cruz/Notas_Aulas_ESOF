import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = sc.nextInt();
        int n = sc.nextInt();

        System.out.println(generatePassword(a, b, c, n));
    }

    public static String generatePassword(int A, int B, int C, int N) {
        if (A + B + C > N) {
            throw new IllegalArgumentException("A + B + C cannot be greater than N");
        }

        Random random = new Random();
        List<Character> password = new ArrayList<>();

        // Add A uppercase letters
        for (int i = 0; i < A; i++) {
            password.add((char) ('A' + random.nextInt(26)));
        }

        // Add B lowercase letters
        for (int i = 0; i < B; i++) {
            password.add((char) ('a' + random.nextInt(26)));
        }

        // Add C digits
        for (int i = 0; i < C; i++) {
            password.add((char) ('0' + random.nextInt(10)));
        }

        // Add remaining characters to make up the exact length N
        int remaining = N - (A + B + C);
        for (int i = 0; i < remaining; i++) {
            int type = random.nextInt(3);
            if (type == 0) {
                password.add((char) ('A' + random.nextInt(26)));
            } else if (type == 1) {
                password.add((char) ('a' + random.nextInt(26)));
            } else {
                password.add((char) ('0' + random.nextInt(10)));
            }
        }

        // Shuffle the password to randomize the order
        Collections.shuffle(password);

        // Build the result while ensuring no consecutive characters are the same
        StringBuilder result = new StringBuilder();
        result.append(password.remove(0)); // Add the first character

        while (!password.isEmpty() && result.length() < N) {
            char nextChar = password.remove(0);
            if (nextChar != result.charAt(result.length() - 1)) {
                result.append(nextChar);
            } else {
                // If the character is the same as the last, move it to the end of the list
                password.add(nextChar);
            }
        }

        // If still shorter than N, fill with random characters
        while (result.length() < N) {
            int type = random.nextInt(3);
            char filler;
            if (type == 0) {
                filler = (char) ('A' + random.nextInt(26));
            } else if (type == 1) {
                filler = (char) ('a' + random.nextInt(26));
            } else {
                filler = (char) ('0' + random.nextInt(10));
            }

            // Ensure no consecutive characters are added
            if (filler != result.charAt(result.length() - 1)) {
                result.append(filler);
            }
        }

        return result.toString();
    }
}
