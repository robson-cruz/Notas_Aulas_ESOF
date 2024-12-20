import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            System.out.println("Digite um número");
            int n = scanner.nextInt();

            System.out.println("O número Fibonacci na posição " + n + " é: " + fibonacci(n));
        }
    }

    public static int fibonacci(int number) {
        if (number == 0) return 0;
        if (number == 1) return 1;

        int prev1 = 0, prev2 = 1, current = 0;
        for (int i = 2; i <= number; i++) {
            current = prev1 + prev2;
            prev1 = prev2;
            prev2 = current;
        }

        return current;
    }
}
