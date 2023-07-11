#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define maximo 10

// Vari�veis globais
int tamanho = 0;
int grafo [maximo]; // Tamanho do grafo
int matriz[maximo][maximo]; // Matriz de adjac�ncias
int i, j, op=1;

// Prototipa��o de fun��es
int grafo_tamanho();
void limpa_tela();
void inserir_aresta();
void remover_aresta();
void desenhar_grafo();
void grafo_desenhar_matriz();
void menu();

// Fin��o Principal
int main(void) {
	setlocale(LC_ALL, "");
	
	while (tamanho <= 0 || tamanho > maximo) {
		tamanho = grafo_tamanho();
		if (tamanho <= 0 || tamanho > maximo) {
			limpa_tela();
			printf("Escolha um valor entre 1 e %d!\n\n", maximo);
		} else {
			for (i = 0; i < tamanho; i++) {
				grafo[i] = i;
			}
		}
	}
	
	while (op != 0) {
		limpa_tela();
		desenhar_grafo();
		grafo_desenhar_matriz();
		menu();
		scanf("%d", &op);
		switch (op) {
			case 1: {
				inserir_aresta();
				break;
			}
			case 2: {
				remover_aresta();
				break;
			}
			case 0: {
				exit(0);
			}
			default: {
				printf("Op��o Inv�lida!");
			}
		}
	}
	printf("\n");
	getchar();
	
	return 0;
}

// Define o n�mero de v�rtices do grafo
int grafo_tamanho() {
	int tamanho;
	printf("Escolha a quantidade de v�rtices do grafo: ");
	scanf("%d", &tamanho);
	return tamanho;
}

// Limpa a tela
void limpa_tela() {
	#ifdef _WIN32
	       system("cls");
	#else
	       system("clear");
	#endif
}

// Inserir aresta
void inserir_aresta() {
     int num1, num2;
     limpa_tela();
     printf("Escolha o v�rtice de origem entre 0 a %d: ", tamanho-1);
     scanf("%d",&num1);
     printf("Escolha o v�rtice de destino entre 0 a %d: ",tamanho-1);
     scanf("%d",&num2);
     if (num1 > tamanho-1 || num2 > tamanho-1 || num1 <0 || num2 <0) {
     	printf("\nOs valores precisam estar entre 0 e %d\n\n", tamanho);
     	getchar();
     } else {
     	matriz[num1][num2] = 1;
     	matriz[num2][num1] = 1;
     }
}

// Remover aresta
void remover_aresta() {
	int num1, num2;
	limpa_tela();
	printf("Escolha o v�rtice de origem entre 0 a %d: ", tamanho);
	scanf("%d", &num1);
	printf("Escolha o v�rtice de destino entre 0 a %d: ", tamanho);
	scanf("%d", &num2);
	if (num1 > tamanho-1 || num2 > tamanho-1 || num1 <0 || num2 <0) {
		printf("\nOs valores precisam estar entre 0 e %d\n\n",tamanho);
		getchar();
	} else {
		matriz[num1][num2] = 0;
		matriz[num2][num1] = 0;
	}
}

// Fun��o para desenhar o vetor de v�rtices
void desenhar_grafo() {
	printf("Listas de v�rtices\n[ ");
	for (i = 0; i < tamanho; i++) {
		printf("%d ", grafo[i]);
	}
	printf("]\n\n");
}

// Fun��o para desenhar a matriz de arestas
void grafo_desenhar_matriz() {
	// Desenhando matriz de adjac�ncias
	printf("Matriz de adjacencias\n[\n");
	for (i = 0; i < tamanho; i++) {
		for (j = 0; j < tamanho; j++) {
			printf(" %d", matriz[i][j]);
		}
		printf("\n");
	}
	printf("]\n\n");
}

// Menu
void menu() {
     printf("\nEscolha uma op��o:\n");
     printf("1 - Inserir aresta\n");
     printf("2 - Remover aresta\n");
     printf("0 - Sair\n\n");	
}
