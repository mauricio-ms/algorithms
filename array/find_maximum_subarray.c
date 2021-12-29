#include <stdio.h>
#include <math.h>
#include "../test/assertions.h"

typedef struct {
    int start;
    int end;
    int sum;
} max_subarray;

max_subarray find_maximum_subarray_brute_force(int A[], int n) {
    max_subarray maximum;
    maximum.start = -1;
    maximum.end = -1;
    maximum.sum = (int) -INFINITY;

    for (int i=0; i<n; i++) {
        int sum = 0;
        for (int j=i; j<n; j++) {
            sum += A[j];
            if (sum > maximum.sum) {
                maximum.start = i;
                maximum.end = j;
                maximum.sum = sum;
            }
        }
    }
    return maximum;
}

max_subarray find_max_crossing_subarray(int A[], int low, int mid, int high) {
    max_subarray maximum;
    maximum.start = -1;
    maximum.end = -1;

    int left_sum = (int) -INFINITY;
    int sum = 0;
    for (int i=mid; i>=low; i--) {
        sum += A[i];
        if (sum > left_sum) {
            left_sum = sum;
            maximum.start = i;
        }
    }

    int right_sum = (int) -INFINITY;
    sum = 0;
    for (int j=mid+1; j<=high; j++) {
        sum += A[j];
        if (sum > right_sum) {
            right_sum = sum;
            maximum.end = j;
        }
    }

    maximum.sum = left_sum + right_sum;
    return maximum;
}

max_subarray find_maximum_subarray_divide_and_conquer(int A[], int low, int high) {
    if (high == low) {
        max_subarray maximum;
        maximum.start = low;
        maximum.end = high;
        maximum.sum = A[low];

        return maximum;
    } else {
        int mid = (low + high) / 2;
        max_subarray maximum_left = find_maximum_subarray_divide_and_conquer(A, low, mid);
        max_subarray maximum_right = find_maximum_subarray_divide_and_conquer(A, mid+1, high);
        max_subarray maximum_cross = find_max_crossing_subarray(A, low, mid, high);
        if (maximum_left.sum >= maximum_right.sum && maximum_left.sum >= maximum_cross.sum) {
            return maximum_left;
        } else if (maximum_right.sum >= maximum_left.sum && maximum_right.sum >= maximum_cross.sum) {
            return maximum_right;
        } else {
            return maximum_cross;
        }
    }
}

void find_maximum_subarray_tests() {
    printf("Running find maximum subarray tests ...\n");
    int A[] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
    int n = sizeof(A) / sizeof(int);

    int expected_start = 7;
    int expected_end = 10;
    int expected_sum = 43;

    printf("CASE: Brute-Force\n");
    max_subarray actual_brute_force = find_maximum_subarray_brute_force(A, n);
    assert_int_equals(expected_start, actual_brute_force.start);
    assert_int_equals(expected_end, actual_brute_force.end);
    assert_int_equals(expected_sum, actual_brute_force.sum);

    printf("CASE: Divide-and-Conquer\n");
    max_subarray actual_divide_and_conquer = find_maximum_subarray_divide_and_conquer(A, 0, n-1);
    assert_int_equals(expected_start, actual_divide_and_conquer.start);
    assert_int_equals(expected_end, actual_divide_and_conquer.end);
    assert_int_equals(expected_sum, actual_divide_and_conquer.sum);
}