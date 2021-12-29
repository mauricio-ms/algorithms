#include <stdio.h>
#include <math.h>
#include "../test/assertions.h"

int find_maximum_subarray_brute_force(int A[], int n) {
    int max_sum = (int) -INFINITY;
    for (int i=0; i<n; i++) {
        int sum = 0;
        for (int j=i; j<n; j++) {
            sum += A[j];
            if (sum > max_sum) {
                max_sum = sum;
            }
        }
    }
    return max_sum;
}

void find_maximum_subarray_tests() {
    printf("Running find maximum subarray tests ...\n");
    int A[] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
    int n = sizeof(A) / sizeof(int);

    int expected = 43;

    printf("CASE: Brute-Force\n");
    int actual_brute_force = find_maximum_subarray_brute_force(A, n);
    assert_int_equals(expected, actual_brute_force);
}