#include <stdio.h>
#include <stdlib.h>

#define N 5

// Estrutura da Fila
typedef struct QUEUE {
	int vector[N];
	int first;
	int last;
} QUEUE;

// Declaração de variáveis globais
QUEUE queue;

// Prototipação de funçoes
void enqueue();
void printQueue();
void dequeue();
void menu();
void clearScreen();

// Função principal
int main(void) {
	menu();	
	return 0;
}

/*** Implementação de funções ***/
// Inserir na Filha
void enqueue() {
	// Testa se a Filha está cheia
	if (queue.last == N) {
		printf("The queue is full!!\n\n");
  		getchar();
	} else {
		int i = 0;
		queue.first = 0;
		queue.last = 0;
		while (i < N) {
			printf("Type a number to enqueue: \n->>> ");
			scanf("%d", &queue.vector[queue.last]);
			queue.last++;
			i++;
			clearScreen();
		}
	}
}

// Imprimir a Fila
void printQueue() {
	int i;
	printf("\nFila: [ ");
	for (i = 0; i < N; i++) {
		printf("%d ", queue.vector[i]);
	}
	printf("]\n\n");
}

// Remover o primeiro da Fila
void dequeue() {
	if (queue.first == queue.last) {
		printf("\nThe queue is empty!\n\n");
		getchar();
	} else {
		int i;
		for (i = 0; i < N; i++) {
			queue.vector[i] = queue.vector[i+1];
		}
		queue.vector[queue.last-1] = 0;
		queue.last--;
	}
}

// Limpar a tela
void clearScreen () {
	#ifdef _WIN32
		system("cls");
	#else
                system("clear");
        #endif
}

// Menu
void menu() {
	int opt;
	while(1) {
		printf("\nChoose a function:\n");
		printf("1 - Enqueue\n");
		printf("2 - Dequeue\n");
		printf("0 - Exit\n\n->>> ");
		scanf("%d", &opt);
		clearScreen();
		switch(opt) {
			case 1: {
				enqueue();
				printQueue();
				break;
			}
			case 2: {
				dequeue();
				printQueue();
				break;
			}
			case 0: {
				printf("Good BY....\n");
				exit(0);
			}
			default: {
				printf("Invalid choose!\n");
			}
		}
	}
	printf("\n");
	getchar();
}
