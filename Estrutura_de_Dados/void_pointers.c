#include <stdio.h>
#include <stdlib.h>

// Function to print different data types using void pointers
void print_data(void* data, char data_type);

// Main functrion
int main(void) {
	
	int num = 41;
	
	print_data(&num, 'i');
	print_data(&num, 'f');
	print_data(&num, 'c');
	
	return 0;
}

// Function to print different data types using void pointers
void print_data(void* data, char data_type) {
	if (data_type == 'i') {
		printf("Integer: %d\n", *((int*)data));
	}
	else if (data_type == 'f') {
		printf("Float: %f\n", *((float*)data));
	}
	else if (data_type == 'c') {
		printf("Character: %c\n", *((char*)data));
	} else {
		printf("Unknown data type!\n");
	}
}
