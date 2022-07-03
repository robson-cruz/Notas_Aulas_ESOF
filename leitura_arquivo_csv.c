#include <stdio.h>

int main (void) {
	
	// Cria uma variável para leitura de dados
	char linha[200];
	// Cria o ponteiro 'arq' do tipo FILE para receber o endereço de
	// memória de um arquivo
	FILE *arq;
	// Atribui o endereço de um arquivo em disco ao ponteriro 'arq' e
	// e abre o arquivo no modo leitura
	arq = fopen("baseball.csv", "r");
	// Testa se o arquivo foi lido com sucesso
	// A função fopen() retorna NULL se não consegue ler o arquivo
	if (arq == NULL) {
		printf("Erro ao ler arquivo!\n");
		system("pause");
		exit(-1);
	}
	else {
		// Posiciona o cursor no início do arquivo
		rewind (arq);
		// lê cada linha enquanto não chegar ao fim do arquivo
		while (!feof (arq)) { // retorna 0 se o fim do arquivo não foi alcançado
			fgets (linha, sizeof(linha), arq);
			printf("%s", linha);
		}
	}
	// Fecha o arquivo
	fclose(arq);
	return 0;
}
