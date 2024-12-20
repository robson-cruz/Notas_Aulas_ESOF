#include <stdio.h>
#include <locale.h>

int fibonacci(int number);

int main(int argc, char *argv[]) {
	
	int n;
	
	setlocale(LC_ALL, "Portuguese");
	printf("Digite um número: ");
	scanf("%d", &n);
	
    printf("\nO número Fibonacci na posição %d é: %d\n\n", n, fibonacci(n));
	system("pause");
	
	return 0;

}

int fibonacci(int number) {
    if (number == 0 || number == 1) {
               return number;
    } else {
           return fibonacci(number - 1) + fibonacci(number - 2);
    }
}
