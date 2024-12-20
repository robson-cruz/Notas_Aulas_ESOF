#include <stdio.h>
#include <stdlib.h>


/***
argc: an integer representing the number of command-line arguments passed to
the program.
**argv: an array of strings containing the actual arguments. 
***/

int main(int argc, char **argv[]) {
	
	int j, k;

	// Iterate over the command-line arguments
	while (argv[j]) {
		k = 0;
		while (argv[j][k]) {
			printf("%c", argv[j][k]);
			k++;
		}
		puts("");
		++j;
	}
	
	return 0;
}
