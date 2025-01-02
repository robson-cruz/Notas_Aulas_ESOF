import java.util.Locale;
import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String input = scanner.nextLine().toLowerCase(Locale.ROOT).trim();

        String[] arrayInput = input.split("");

        int count = 0;
        for (int i = 0; i < arrayInput.length; i++) {
            if (arrayInput[i].equals("g") || arrayInput[i].equals("c")) {
                count ++;
            }
        }

        double gcPercentage = (double) count / input.length() * 100;
        System.out.println(gcPercentage);
    }
}