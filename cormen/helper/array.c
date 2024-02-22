#include <stdio.h>
#include <stdlib.h>
#include "array.h"

void print_array(int A[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void fill_random_array(int A[], int n) {
    for (int i = 0; i < n; ++i) {
        A[i] = rand() % 100000;
    }
}