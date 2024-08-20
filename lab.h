#ifndef LAB_H
#define LAB_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10000
#define MIN -500
#define MAX 500

int *genArray() {
    int *array;
    array = malloc(sizeof(int) * SIZE);
    // Set the seed for random number generation
    srand(458);

    // Generate and store random integers in the array
    for (int i = 0; i < SIZE; i++) {
        array[i] = (rand() % (MAX - MIN + 1)) + MIN;
    }

    // Print the first 10 numbers as a sample output
    for (int i = 0; i < 10; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    return array;
}
void printSample(int *array) {
    // Print the first 10 numbers as a sample output
    printf("Sample of Sorted array : ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    }
#endif
