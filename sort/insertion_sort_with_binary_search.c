#include <stdio.h>
#include "../test/assertions.h"

int get_index_to_insert(int A[], int v, int start, int end) {
    if (end - start <= 1) {
        if (v <= A[start]) {
            return start;
        } else {
            return end;
        }
    }

    int middle = start + (end - start) / 2;
    if (v > A[middle]) {
        return get_index_to_insert(A, v, middle, end);
    } else if (v < A[middle]) {
        return get_index_to_insert(A, v, start, middle);
    } else {
        return middle;
    }
}

void insertion_sort_with_binary_search(int A[], int n) {
    for (int j = 1; j < n; j++) {
        int key = A[j];
        // Insert A[j] into the sorted sequence A[0..j - 1]
        int i = j - 1;
        int k = get_index_to_insert(A, key, 0, j);
        while (i >= k) {
            A[i + 1] = A[i];
            i--;
        }
        A[i + 1] = key;
    }
}

void insertion_sort_with_binary_search_tests() {
    printf("Running insertion sort with binary search tests ...\n");
    int n = 6;
    int A[] = {31, 41, 59, 26, 41, 58};

    int expected[] = {26, 31, 41, 41, 58, 59};
    insertion_sort_with_binary_search(A, n);
    assert_array_equals(expected, n, A, n);
}