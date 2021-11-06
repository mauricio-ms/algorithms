#include <stdio.h>
#include "../test/assertions.h"

void selection_sort(int A[], int n) {
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
}

void selection_sort_tests() {
    printf("Running selection sort tests ...\n");
    int n = 6;
    int A[] = {31, 41, 59, 26, 41, 58};

    int expected[] = {26, 31, 41, 41, 58, 59};
    selection_sort(A, n);
    assert_array_equals(expected, n, A, n);
}