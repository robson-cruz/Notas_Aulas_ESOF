#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <stdbool.h>


// Constant
#define SIZE 10

// Stack structure
typedef struct {
	int top;
	int data[SIZE];
} Stack;


// Function prototypes
void initializeStack(Stack* stack);
bool isFull(Stack* stack);
bool isEmpty(Stack* stack);
void push(Stack* stack, int value);
int pop(Stack* stack);
void printStack(Stack* stack);
void clearScreen();


// Main function
int main(void) {
	Stack dataStack;
	int option;
	initializeStack(&dataStack);
	
	while (true) {
		// set the locale to "Portuguese" 
		setlocale(LC_ALL, "Portuguese");
		
		clearScreen();
		printf("Escolha uma opção:\n");
		printf("1 - Empilhar\n");
		printf("2 - Desempilhar\n");
		printf("3 - Mostrar pilha\n");
		printf("0 - Sair\n");
		printf("Opção: ");
		scanf("%d", &option);
		
		switch (option) {
			case 1: {
				int value;
				printf("Digite um número inteiro para inserir na pilha: ");
				scanf("%d", &value);
				if (!isFull(&dataStack)) {
					push(&dataStack, value);
					printf("Valor empilhado com sucesso!\n");
				} else {
					printf("A pilha está cheia!\n");
				}
				break;
			}
			case 2: {
				if (!isEmpty(&dataStack)) {
					int value = pop(&dataStack);
					printf("Valor desempilhado: %d\n", value);
				} else {
					printf("A pilha está vazia!\n");
				}
				break;
			}
			case 3: {
				printf("Conteúdo da pilha:\n");
				printStack(&dataStack);
				break;
			}
			case 0: {
				printf("Encerrando o programa...\n");
				exit(0);
			}
			default:
				printf("Opção inválida!!!\n");
		}
		printf("\n");
		system("pause");
	}
	return 0;
}

// Initialize stack
void initializeStack(Stack *stack) {
	stack->top = -1;
}

// Check if stack is full
bool isFull(Stack *stack) {
	return stack->top == SIZE - 1;
}

// Check if stack is empty
bool isEmpty(Stack *stack) {
	return stack->top == -1;
}

// Push an element onto the stack
void push(Stack *stack, int value) {
	stack->data[++stack->top] = value;
}

// Pop an element from the stack
int pop(Stack *stack) {
	return stack->data[stack->top--];
}

// Print stack elements
void printStack(Stack *stack) {
	if (isEmpty(stack)) {
		printf("A pilha está vazia!\n");
	}
	int i;
	for (i = stack->top; i >= 0; i--) {
		printf("%d\n", stack->data[i]);
	}
}

// Clear the screen
void clearScreen() {
	#ifdef _WIN32
		system("cls");
	#else
		system("clear");
	#endif
}
