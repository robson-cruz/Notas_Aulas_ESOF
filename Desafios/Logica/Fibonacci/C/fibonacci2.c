#include <stdio.h>
#include <locale.h>

int fibonacci(int number, int memo[]);

int main(int argc, char *argv[]) {
    int n;

    setlocale(LC_ALL, "Portuguese");
    printf("Digite um n�mero: ");
    scanf("%d", &n);

    // Array para armazenar resultados j� calculados
    int memo[n + 1];
    int i;
    for (i = 0; i <= n; i++) {
        memo[i] = -1; // Inicializar com -1 indicando que n�o foi calculado
    }

    printf("\nO n�mero Fibonacci na posi��o %d �: %d\n\n", n, fibonacci(n, memo));
    system("pause");

    return 0;
}

int fibonacci(int number, int memo[]) {
    if (number == 0 || number == 1) {
        return number;
    }

    // Verificar se j� foi calculado
    if (memo[number] != -1) {
        return memo[number];
    }

    // Calcular e armazenar no array de memoization
    memo[number] = fibonacci(number - 1, memo) + fibonacci(number - 2, memo);
    return memo[number];
}
