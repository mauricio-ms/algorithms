#include <stdio.h>
#include "../test/assertions.h"

int linear_search(int A[], int n, int v) {
    for (int i = 0; i < n; ++i) {
        if (A[i] == v) {
            return i;
        }
    }
    return -1;
}

void linear_search_tests() {
    printf("Running linear search tests ...\n");
    int n = 6;
    int A[] = {31, 41, 59, 26, 41, 58};

    int index_of_59 = linear_search(A, n, 59);
    assert_int_equals(2, index_of_59);

    int index_of_120 = linear_search(A, n, 120);
    assert_int_equals(-1, index_of_120);
}