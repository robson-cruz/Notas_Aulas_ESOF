#include <stdio.h>
#include <stdlib.h>  //srand() and rand()
#include <time.h>
#include <locale.h>
#include <stdbool.h> //bool type and true/false constants
#include <setjmp.h> //setjmp() and longjmp()


void main () {
	//Intialize the seed to random number generator
	srand(time(NULL));
	
	//Number of unique random numbers to generate
	int n[6];
	
	int i, j;
	for (i = 0; i < 6; i++) {
		do {
			n[i] = rand() % 60+1;
			// Chek if the number is in the array
			for (j = 0; j < i; j++) {
				if (n[i] == n[j]) {
					break;
				}
			}
		// Repeat until find a unique number
		}while (j < i);
	}
	//Sort the array in ascending order using Bubble Sort algorithm
	for (i = 0; i < 6; i++) {
		for (j = 0; j < 6-i-1; j++) {
			if (n[j] > n[j+1]) {
				int temp = n[j];
				n[j] = n[j+1];
				n[j+1] = temp;
			}
		}
	}
	
	// Print the sorted array
	setlocale(LC_ALL, "Portuguese");
	for (i = 0; i < 6; i++) {
		printf(" %d", n[i]);
	}
	
	printf("\n\n");
	system("pause");
}
