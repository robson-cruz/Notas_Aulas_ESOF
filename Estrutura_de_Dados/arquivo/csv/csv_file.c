#include <stdio.h>
#include <locale.h>
#include <unistd.h>
#include <string.h>


#define MAX_DATA 100


typedef struct {
	char name[55];
	int old;
	float weight;
	char sex;
} Data;

Data data[MAX_DATA];
int dataCount = 0; // Tracks the number of data entries

void add_data() {
	if (dataCount >= MAX_DATA) {
		setlocale(LC_ALL, "Portuguese");
		printf("Limite máximo de dados atingido!\n");
		return;
	}
	
	printf("Digite o nome: ");
    	getchar();  // Consume the newline character
    	fgets(data[dataCount].name, 55, stdin);

    	printf("Digite a idade: ");
    	scanf("%d", &data[dataCount].old);

    	printf("Digite o peso: ");
    	scanf("%f", &data[dataCount].weight);

    	printf("Digite o sexo [M/F]: ");
    	getchar();  // Consume the newline character
    	scanf("%c", &data[dataCount].sex);

    	dataCount++;
}

void print_data() {
	setlocale(LC_ALL, "Portuguese");
	printf("\nDados Digitados\n");
	// Print table header
	printf("| %-4s | %-20s | %-6s | %-10s | %-4s |\n", "No.", "Nome", "Idade", "Peso", "Sexo");
    	printf("+------+----------------------+--------+------------+------+\n");
	int i;
	for (i = 0; i < dataCount; i++) {
		printf("| %-4d | %-20s | %-6d | %-3.2f | %-4c |\n", i + 1,
		 data[i].name, data[i].old, data[i].weight, data[i].sex);
	}
	system("Pause");
}

int isFileEmpty(FILE *file) {
	long currentPosition;
    
    	// Salva a posição atual do arquivo
    	currentPosition = ftell(file);
    
    	// Move para o fim do arquivo
    	fseek(file, 0, SEEK_END);
    
    	// Obtém a posição atual (tamanho do arquivo em bytes)
    	long fileSize = ftell(file);
    
    	// Retorna para a posição anterior
    	fseek(file, currentPosition, SEEK_SET);
    
    	// Se o tamanho do arquivo for 0, está vazio
    	if (fileSize == 0) {
        	return 1; // Verdadeiro
    	} else {
        	return 0; // Falso
    	}
}

void save_data() {
	FILE *file = fopen("text_file0.csv", "a");
	
	if (isFileEmpty(file)) {
		fprintf(file, "Nome;Idade;Peso;Sexo\n");	
	}
	
	if (file) {
		
		int i;
		for (i = 0; i < dataCount; i++) {
			// Remove the newline character from the name string
			size_t len = strlen(data[i].name);
			if (len > 0 && data[i].name[len - 1] == '\n') {
				data[i].name[len -1] = '\0';
			}
			
			fprintf(file, "\"%s\";%d;%.2f;%c\n", data[i].name, data[i].old, data[i].weight, data[i].sex);
		}
		fclose(file);
	} else {
		printf("Erro ao abrir arquivo!!\n\n");
	}
}

int main(void) {
	int opt;
	
	setlocale(LC_ALL, "Portuguese");
	
	do {
		printf("\n\nEscolha uma opção\n\n");
		printf("1 - Cadastrar dados\n2 - Imprimir Dados\n3 - Salvar Dados\n0 - Sair\n\n>>");
		scanf("%d", &opt);
		
		switch (opt) {
			case 1:
				add_data();
				break;
			case 2:
				print_data();
				break;
			case 3:
				save_data();
				break;
			case 0:
				printf("\n\nSaindo do programa!\n");
			default:
				printf("\nOpção inválida\n");
				// consume the newline character left in the buffer.
				// This ensures that the newline character doesn't
				// interfere with the subsequent input operations.
				break;
				
		}
	} while (opt != 0);
	
	return 0;
}
