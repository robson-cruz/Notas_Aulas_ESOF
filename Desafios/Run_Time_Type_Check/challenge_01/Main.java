import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner scanner = new Scanner(System.in);

        Object obj = scanner.nextLine();

        if (obj instanceof String) {
            String str = (String) obj;

            if (str.isBlank()) {
                System.out.println("The string is empty or contains only whitespace.");
            } else {
                System.out.println(str);
            }
        } else {
            System.out.println("The input is not a string!");
        }
    }
}