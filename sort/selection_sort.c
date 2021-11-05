#include <stdio.h>
#include "../helper/array.h"

void selection_sort(int A[], int n) {
    printf("selection_sort\n");

    for (int i=0; i<n-1; i++) {
        int lower = A[i];
        int lowerIndex = i;
        for (int j=i+1; j<n; j++) {
            if (A[j] < lower) {
                lower = A[j];
                lowerIndex = j;
            }
        }

        if (lowerIndex != i) {
            int current = A[i];
            A[i] = lower;
            A[lowerIndex] = current;
        }
    }

    print_array(A, n);
}

void selection_sort_tests() {
    int n = 6;
    int A[] = {31, 41, 59, 26, 41, 58};
    selection_sort(A, n);
}