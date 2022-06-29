#include <stdio.h>
#include <locale.h>



// passagem de parâmetro por valor
void exParametroValor (int numero) {
	setlocale(LC_ALL, "Portuguese");
	printf("\nO número que veio por parâmetro é %d\n", numero);
	numero = numero * 2;
}
// passagem de parâmetro por referência
void exParametroRef (int *numero) {
	printf("\nO número que veio por parâmetro é %d\n", *numero);
	*numero = *numero * 2;
}

int main (void) {
	int num = 10;
	exParametroValor(num);
	
  	printf("\nA variável 'num' depois de executar a subrotina por valor é %d\n", num);

	exParametroRef(&num);
	printf("\nA variável 'num' depois de executar a subrotina por referência eh %d\n", num);
}