#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n = 250;
    double min = 0.0;
    double max = 5.0;
    double x[n];

    // Seed the random number generator
    srand(time(NULL));

    // Generate the random numbers
    for (int i = 0; i < n; i++) {
        x[i] = min + (double)rand() / RAND_MAX * (max - min);
    }

    // Print the random numbers
    for (int i = 0; i < n; i++) {
        printf("%f\n", x[i]);
    }

    return 0;
}
