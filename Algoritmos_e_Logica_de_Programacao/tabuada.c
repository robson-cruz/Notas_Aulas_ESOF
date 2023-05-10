#include <stdio.h>
#include <locale.h>


int main(void) {

	int opt, num, s;

	setlocale(LC_ALL, "Portuguese");
	
	printf("\t>>>  Tabuada  <<<\n\n");
	printf("\t1 - Soma\n\t2 - Subtração\n\t3 - Multiplicação\n\t4 - Divisão\n");
	printf("\nInforme a operação: \n>> ");
	scanf("%d", &opt);

	switch (opt) {
		case 1:
		printf("Digite um número para adição: \n>> ");
		scanf("%d", &num);
		printf("\tTabuada da Adição\n\n");
		for (int i = 0; i <= 10; i++) {
			printf("\t%2d + %2d = %2d\n", num, i, num+i);
		}
		break;

		case 2:
		printf("Digite um número para Subtração: \n>> ");
		scanf("%d", &num);
		printf("\tTabuada da Subtração\n\n");
		for (int i = 1; i <= 10+num; i++) {
			printf("\t%2d - %2d = %2d\n", i, num, i-num);
		}
		break;

		case 3:
		printf("Digite um número para multiplicar\n >> ");
		scanf("%d", &num);
		printf("\tTabuada da Multiplicação\n\n");
		for (int i = 0; i <= 10; i++) {
			printf("\t%2d x %2d = %2d\n", num, i, num*i);
		}
		break;

		case 4:
		printf("Digite um número para divisão\n >> ");
		scanf("%d", &num);
		printf("\tTabuada da Divisão\n\n");
		for (int i = 0; i <= num*9; i+=num) {
			printf(" %2d ÷ %2d = %2d\n", i, num, i/num);
		}
		break;

		default:
		printf("\n\tOpção inválida!\n");
	}
	
  	return 0;
}