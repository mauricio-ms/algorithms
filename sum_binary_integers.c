#include <stdio.h>
#include "array.h"

void sum_binary_integers() {
    printf("sum_binary_integers\n");

    int n = 3;
    int A[] = {1, 0, 1};
    int B[] = {1, 0, 1};

    int remainder = 0;
    int C[n + 1];

    int i = n-1;
    for (; i > 0; i--) {
        C[i + 1] = A[i] ^ B[i] ^ remainder;
        remainder = A[i] & B[i];
    }

    C[i + 1] = A[i] ^ B[i] ^ remainder;
    remainder ^= A[i] & B[i];

    C[0] = remainder;

    print_array(C, n+1);
}

void sum_binary_integers_tests() {
    sum_binary_integers();
}