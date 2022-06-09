#include <stdio.h>
#include <locale.h>

int main () {
	
	int gado, par , impar, Qgado, Qantigo, vetorA[10];

    	par = 0;
    	gado = 0; //contador
    	impar = 0;
    	
	setlocale(LC_ALL, "Portuguese");
	
	printf("Informe a Quantidade de Gados a Cadastrar: \n");
	scanf("%d", &Qgado);
	
    	while (gado != Qgado) {
        	for (gado = 0; gado < Qgado; gado++) {
        		printf("Digite o código do gado: \n");
			scanf("%d", &vetorA[gado]);
            		if (vetorA[gado] == gado) {
        			printf("Código repetido, digite novamente: \n");
				scanf("%d", &vetorA[gado]);
       			}
		}
	}
	
	for (gado = 0; gado < Qgado; gado++) {
		if (vetorA[gado] % 2 == 0) {
			par++;
		}
		else {
			impar++;
		}
	}
     	
        printf("\nTotal de gados no Pasto 1: %d\n", par);
        printf("Total de gados no Pasto 2: %d\n", impar);
	
	getch();
        return 0;
}
