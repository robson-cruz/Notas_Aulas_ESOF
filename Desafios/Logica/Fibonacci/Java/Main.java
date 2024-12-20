import java.util.Scanner;

public class Main {
    /**
     * @param args
     */
    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            System.out.println("Digite um número");
            int n = scanner.nextInt();

            // Array para memoization
            int[] memo = new int[n + 1];
            for (int i = 0; i <= n; i++) {
                memo[i] = -1; // inicializar com -1 para indicar valores não calculados
            }

            System.out.println("O número Fibonacci na posição " + n + " é: " + fibonacci(n, memo));
        }
    }

    /**
     * @param number
     * @param memo
     * @return
     */
    public static int fibonacci(int number, int[] memo) {
        if (number == 0 | number == 1) {
            return number;
        }

        // Verificar se o valor já foi calculado
        if (memo[number] != -1) {
            return memo[number];
        }

        // Calcular e armanezar no memo
        memo[number] = fibonacci(number - 1, memo) + fibonacci(number -2, memo);
        return memo[number];
    }
}
