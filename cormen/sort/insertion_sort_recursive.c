#include <stdio.h>
#include "../test/assertions.h"

void insertion_sort_recursive(int A[], int n) {
    if (n > 1) {
        insertion_sort_recursive(A, n-1);
    }

    int key = A[n];
    // Insert A[n] into the sorted sequence A[0..n - 1]
    int i = n - 1;
    while (i >= 0 && A[i] > key) {
        A[i + 1] = A[i];
        i--;
    }
    A[i + 1] = key;
}

void insertion_sort_recursive_tests() {
    printf("Running insertion sort recursive tests ...\n");
    int n = 6;
    int A[] = {31, 41, 59, 26, 41, 58};

    int expected[] = {26, 31, 41, 41, 58, 59};
    insertion_sort_recursive(A, n-1);
    assert_array_equals(expected, n, A, n);
}