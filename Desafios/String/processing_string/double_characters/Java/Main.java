import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String input = scanner.nextLine().trim();

        StringBuilder newString = new StringBuilder();
        String[] arrayFromInput = input.split("");

        for (int i = 0; i < arrayFromInput.length; i++) {
            newString.append(arrayFromInput[i]);
            newString.append(arrayFromInput[i]);
        }

        System.out.println(newString);
    }
}