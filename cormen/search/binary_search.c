#include <stdio.h>
#include "../test/assertions.h"

int binary_search(int A[], int n, int v, int start, int end) {
    if (start < 0 || end >= n) {
        return -1;
    } else if (end-start <=1) {
        if (A[start] != v) {
            return -1;
        } else {
            return start;
        }
    }

    int middle = start + (end - start) / 2;
    if (v > A[middle]) {
        return binary_search(A, n, v, middle, end);
    } else if (v < A[middle]) {
        return binary_search(A, n, v, start, middle);
    } else {
        return middle;
    }
}

void binary_search_tests() {
    printf("Running binary search tests ...\n");

    int n = 17;
    int A[] = {2, 4, 8, 20, 22, 34, 44, 48, 51, 59, 120, 190, 200, 201, 221, 240, 270};

    int index_of_59 = binary_search(A, n, 59, 0, n-1);
    assert_int_equals(9, index_of_59);

    int index_of_121 = binary_search(A, n, 121, 0, n-1);
    assert_int_equals(-1, index_of_121);
}