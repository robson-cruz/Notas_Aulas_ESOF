#include <stdio.h>
#include <locale.h>

int main(int argc, char *argv[]) {
	float p1, p2, p3, media = 0.0;
	
	printf("Digite a nota 1\n");
 	scanf("%f", &p1);
 	printf("Digite a nota 2\n");
 	scanf("%f", &p2);
 	printf("Digite a nota 3\n");
 	scanf("%f", &p3);
 	
 	media = (p1+p2+p3)/3;
 	
 	setlocale(LC_ALL, "Portuguese");
 	
	printf("Média calculada %f\n", media);
 	
 	if (media <= 5) {
 		printf("Reprovado\n");
	}
	if (media <= 7) {
		printf("Recuperação\n");
	} 
	if (media <= 10) {
		printf("Aprovado\n");
	}
	return 0;
}

/***
O problema está nas linhas 18 e 21. Na linha 18 deveria usar um "else if", e na 
linha 21 um "else". Ao usar if nas duas primeiras condições a serem testadas, 
sempre que a média for emnor ou iguar a 7, o programa imprimirá "Reprovado" e 
"Recuperação", pois 7 é menor ou igual a 7 e menor ou igual a 5.
***/
