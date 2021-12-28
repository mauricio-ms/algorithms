#include <stdio.h>
#include "../test/assertions.h"

void insertion_sort_increasing_order(int A[], int n) {
    for (int j = 1; j < n; j++) {
        int key = A[j];
        // Insert A[j] into the sorted sequence A[0..j - 1]
        int i = j - 1;
        while (i >= 0 && A[i] > key) {
            A[i + 1] = A[i];
            i--;
        }
        A[i + 1] = key;
    }
}

void insertion_sort_decreasing_order(int A[], int n) {
    for (int j = 1; j < n; j++) {
        int key = A[j];
        // Insert A[j] into the sorted sequence A[0..j - 1]
        int i = j - 1;
        while (i >= 0 && A[i] < key) {
            A[i + 1] = A[i];
            i--;
        }
        A[i + 1] = key;
    }
}

void insertion_sort_tests() {
    printf("Running insertion sort tests ...\n");
    int n = 6;
    int A[] = {31, 41, 59, 26, 41, 58};

    int expected_increasing_order[] = {26, 31, 41, 41, 58, 59};
    insertion_sort_increasing_order(A, n);
    assert_array_equals(expected_increasing_order, n, A, n);

    int expected_decreasing_order[] = {59, 58, 41, 41, 31, 26};
    insertion_sort_decreasing_order(A, n);
    assert_array_equals(expected_decreasing_order, n, A, n);
}