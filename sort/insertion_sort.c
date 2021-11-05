#include <stdio.h>
#include "../helper/array.h"

void insertion_sort_increasing_order(int A[], int n) {
    printf("insertion_sort_increasing_order\n");

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

//    int n = sizeof(A)/sizeof(A[0]);
    print_array(A, n);
}

void insertion_sort_decreasing_order(int A[], int n) {
    printf("insertion_sort_decreasing_order\n");

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

    print_array(A, n);
}

void insertion_sort_tests() {
    int n = 6;
    int A[] = {31, 41, 59, 26, 41, 58};
    insertion_sort_increasing_order(A, n);
    insertion_sort_decreasing_order(A, n);
}