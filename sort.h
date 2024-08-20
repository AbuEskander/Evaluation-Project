#ifndef SORT_H
#define SORT_H


#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
//Firt Algorithm is Bubble Sort
void bubbleSort(int *arr, int n)
{
    int cmp = 0 ;
    int move_count = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            cmp++;
            if (arr[j] > arr[j + 1])
            {
                //swap
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                move_count += 3;
            }
        }
    }
    printf("Number of moves in Bubble Sort: %d", move_count);
    printf("\nNumber of comparisons in Bubble Sort: %d\n", cmp);
}
//Second Algorithm is Merge Sort
int merge_cmp = 0;
int merge_mv = 0;
void merge(int *arr, int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[l + i];
    }

    for (int i = 0; i < n2; i++)
    {
        R[i] = arr[m + 1 + i];
    }

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2)
    {
        merge_cmp++;
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        merge_mv++;
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
        merge_mv++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
        merge_mv++;
    }
}

void mergeSort(int *arr, int l, int r)
{
    if (l >= r)
    {
        return;
    }

    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    merge(arr, l, m, r);
}

void printMergeSort()
{
    printf("Number of moves in Merge Sort: %d", merge_mv);
    printf("\nNumber of comparisons in Merge Sort: %d\n", merge_cmp);
}
//Third algorithm is Counting Sort
int sort_move = 0;
int comp_sort = 0;
void findMinMax(int arr[], int n, int *min, int *max) {
    *min = arr[0];
    *max = arr[0];
    for (int i = 1; i < n; i++) {
        comp_sort++;
        if (arr[i] > *max) {
            *max = arr[i];
        }
        comp_sort++;
        if (arr[i] < *min) {
            *min = arr[i];
        }
    }
}
void countingSort(int arr[], int n) {
    int min, max;
    findMinMax(arr, n, &min, &max);
    
    int range = max - min + 1;
    int *count = (int *)calloc(range, sizeof(int));
    sort_move += range;
    // Store the count of each element
    for (int i = 0; i < n; i++) {
        comp_sort++;
        sort_move++;
        count[arr[i] - min]++;
    }

    // Reconstruct the array from the count array
    int index = 0;
    for (int i = 0; i < range; i++) {
        while (count[i] > 0) {
            arr[index++] = i + min;
            count[i]--;
            sort_move++;
        }
    }

    // Free the dynamically allocated memory
    free(count);
    sort_move++;
    printf("number of moves in Counting Sort: %d\n", sort_move);
    printf("number of comparisons in Counting Sort: %d\n", comp_sort);
    printf("In Counting Sort, there is no comparison, it's an Operation to be more prescise\n");
}


#endif 