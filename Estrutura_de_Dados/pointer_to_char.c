#include <stdio.h>
#include <stdlib.h>

int main(void) {
	
	char c;
	char *ptr;
	
	c = 'a';
	ptr =  &c;
	
	printf("%p\n%p\n%p\n%p\n", ptr, ptr+1, ptr+2, ptr+3);
	printf("\n%c\n%c\n%c\n%c\n", *ptr, *ptr+1, *ptr+2, *ptr+3);
	
	
	return 0;
}
