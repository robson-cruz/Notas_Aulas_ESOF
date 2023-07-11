#include <stdio.h>

// Function Prototypes
int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
int divide(int a, int b);

// Function to perfome arithmetic operation using function pointer
int performArithmetic(int a, int b, int (*operation)(int, int)) {
	return operation(a, b);
}

// Main Function
int main(void) {
	int a = 10, b = 5;
	
	int sum = performArithmetic(a, b, add);
	int sub = subtract(a, b);
	int mult = multiply(a, b);
	int div = divide(a, b);
	
	printf("Sum of %d and %d: %d\t\tSum address \t\t%p\n", a, b, sum, add);
	printf("Difference of %d and %d: %d\tSubtraction address \t%p\n", a, b, sub, subtract);
	printf("Product of %d and %d: %d\t\tMultiply address \t%p\n", a, b, mult, multiply);
	printf("Quotient of %d and %d: %d\t\tDivide address \t\t%p\n", a, b, div, divide);
	
	return 0;
}

// Function to add two numbers
int add(int a, int b) {
	return a + b;
}

// Function to subtract two numbers
int subtract(int a, int b) {
	return a - b;
}

// Function to multiply two numbers
int multiply(int a, int b) {
	return a * b;
}

// Function to divide two numbers
int divide(int a, int b) {
	return a / b;
}
