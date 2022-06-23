#include <stdio.h>
#include <stdlib.h>

/*** Arquivo
     --> Programa para ler um arquivo .txt e o imprimir na tela
***/

int main () {
	// variavel para receber as linhas do arquivo a ser lido
	char linha[100];
	// variavel para receber o endereço de memória do  arquivo a ser lido
	FILE *arquivo;
	
	// abrir o arquivo
	arquivo = fopen("ROC_curves.txt", "r");
	// testa se o arquvo foi lido com sucesso
	if (arquivo == NULL) {  // fopen retorna NULL se não ler o arquivo
		printf("Erro ao ler arquivo!\n");
		system("pause");
		exit(-1);  // stdlib.h
	}
	else {
		// Posiciona o cursor no início do arquivo
		rewind (arquivo);
		// lê cada linha enquanto não chegar ao fim do arquivo
		while (!feof (arquivo)) {
			// lê um linha do arquivo de até 100 caracteres
			fgets(linha, 100, arquivo);
			printf("%s", linha);
		}
	}
	// fecha o arquivo
	fclose(arquivo);
	return 0;
}
