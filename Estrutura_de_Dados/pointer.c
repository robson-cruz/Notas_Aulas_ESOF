#include <stdio.h>
#include <stdlib.h>


void change_value(int *nb);


int main(void) {
	int nb;
	nb = 42;
	change_value(&nb);
	printf("%d\n", nb);
	
	return 0;
}


void change_value(int *nb) {
	*nb = *nb * 2;
}
