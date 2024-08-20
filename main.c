#include "lab.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "sort.h"
int main (){
    int *randArray;
    randArray = genArray();
    
    clock_t start, end;
    //Bubble sort
    start = clock();
    bubbleSort(randArray, SIZE);
    end = clock();
    printSample(randArray);
    printf("Time taken to sort the array using BUBBLE: %f\n\n", (double)(end - start) / CLOCKS_PER_SEC);
   
    //Merge sort
    free(randArray);
    randArray = genArray();
    start = clock();
    mergeSort(randArray, 0, SIZE - 1);
    end = clock();
    printMergeSort();
    printSample(randArray);
    printf("Time taken to sort the array using MERGE: %f\n\n", (double)(end - start) / CLOCKS_PER_SEC);
    
    //Counting sort
    free(randArray);
    randArray = genArray();
    start = clock();
    countingSort(randArray, SIZE);
    end = clock();
    printSample(randArray);
    printf("Time taken to sort the array using COUNT: %f\n\n", (double)(end - start) / CLOCKS_PER_SEC);
    free(randArray);
    return 0;
}