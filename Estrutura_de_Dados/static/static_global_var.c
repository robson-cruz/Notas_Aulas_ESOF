#include <stdio.h>

/*
Aqui, variavelGlobalEstatica é uma variável global estática.
Ela está acessível apenas neste arquivo de origem e não pode ser acessada em outros arquivos.
*/

static int variavelGlobalEstatica = 42;

int main() {
    printf("Variável global estática: %d\n", variavelGlobalEstatica);
    return 0;
}
