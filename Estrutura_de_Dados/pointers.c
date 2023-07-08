#include <stdio.h>
#include <stdlib.h>


int main(void) {
	// Declaration
	int n;
	int *pn;
	int **ppn;
	int ***pppn;
	
	n = 42;
	pn = &n;
	ppn = &pn;
	pppn = &ppn;
	
	printf("%p == %p\n", (void*)&n,(void*)pn);
	printf("%p == %p\n", (void*)ppn, (void*)pn);
	printf("%p == %p\n", (void*)*pppn, (void*)ppn);
	
	printf("\nconteudo de n: %d\n", n);
	printf("conteudo de pn: %d\n", *pn);
	printf("conteudo de ppn: %d\n", **ppn);
	printf("conteudo de pppn: %d\n", ***pppn);
	
	return 0;
}
