#include <stdio.h>
#include <stdlib.h>


#define N 5

// Estrutura da Pilha
typedef struct STACK {
	int vector[N];
	int start;
	int top;
} STACK;

// Declara��o de vari�veis globais
STACK stack;

// Prototipa��o de fun�oes
void push();
void printStack();
void pop();
void menu();
void clearScreen();

// Fun��o principal
int main(void) {
	menu();
	
	stack.start = 0;
	stack.top = 0;
	
	return 0;
}

/*** Implementa��o de fun��es ***/
// Inserir na pilha
void push() {
	// Testa se a pilha est� cheia
	if (stack.top == N) {
		printf("The stack is full!!\n\n");
  		getchar();
	} else {
		printf("Type a number to insert in the stack: \n->>> ");
		scanf("%d", &stack.vector[stack.top]);
		stack.top++;
		clearScreen();
	}
}

// Imprimir a pilha
void printStack() {
	int i;
	printf("\nPilha: [ ");
	for (i = 0; i < N; i++) {
		printf("%d ", stack.vector[i]);
	}
	printf("]\n\n");
}

// Remover da pilha
void pop() {
	if (stack.top == 0) {
		printf("\nThe stack is empty!\n\n");
		getchar();
	} else {
		stack.vector[stack.top-1] = 0;
		stack.top--;
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
		printf("1 - Insert in the stack\n");
		printf("2 - Pop from the stack\n");
		printf("0 - Exit\n\n->>> ");
		scanf("%d", &opt);
		clearScreen();
		switch(opt) {
			case 1: {
				push();
				printStack();
				break;
			}
			case 2: {
				pop();
				printStack();
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
