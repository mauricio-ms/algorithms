#include <math.h>

/**
 * Function responsible to execute the combine part of the merge sort algorithm.
 * A is an array and p, q, and r are indices into the array such that p <= q < r.
 *
 * This procedure assumes that the subarrays A[p..q] and A[q + 1..r] are in sorted order.
 * It merges them to form a single sorted subarray that replaces the current subarray A[p..r].
 *
 * This procedure takes time O(n), where n = r - p + 1 is the total number of elements being merged.
 */
void merge(int A[], int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++) {
        L[i] = A[p + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = A[q + j + 1];
    }
    // This is called as sentinels in Cormen book, it is used to stop updating the values when a stack (L or R) ends
    L[n1] = INFINITY;
    R[n2] = INFINITY;

    int i = 0;
    int j = 0;
    for (int k = p; k <= r; k++) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
    }
}

/**
 * Merge sort algorithm closely follows the divide-and-conquer paradigm. Intuitively, it operates as follow:
 *
 * Divide: Divide the n-element sequence to be stored into two subsequences of n/2 elements each.
 * Conquer: Sort the two subsequences recursively using merge sort.
 * Combine: Merge the two sorted subsequences to produce the sorted answer.
 */
void merge_sort(int A[], int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;
        merge_sort(A, p, q);
        merge_sort(A, q + 1, r);
        merge(A, p, q, r);
    }
}

void merge_sort_tests() {
    printf("Running merge sort tests ...\n");
    int n = 6;
    int A[] = {31, 41, 59, 26, 41, 58};

    int expected[] = {26, 31, 41, 41, 58, 59};
    merge_sort(A, 0, n - 1);
    assert_array_equals(expected, n, A, n);
}