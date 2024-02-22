#include <stdio.h>
#include "../test/assertions.h"

void sum_binary_integers(int A[], int B[], int R[], int n) {
    int remainder = 0;
    int i = n - 1;
    for (; i > 0; i--) {
        R[i + 1] = A[i] ^ B[i] ^ remainder;
        remainder = A[i] & B[i];
    }

    R[i + 1] = A[i] ^ B[i] ^ remainder;
    remainder ^= A[i] & B[i];

    R[0] = remainder;
}

void sum_binary_integers_tests() {
    printf("Running sum binary integers tests ...\n");
    int n = 3;
    int A[] = {1, 0, 1};
    int B[] = {1, 0, 1};
    int R[n + 1];

    int expected[] = {1, 0, 1, 0};
    sum_binary_integers(A, B, R, n);

    assert_array_equals(expected, n + 1, R, n + 1);
}