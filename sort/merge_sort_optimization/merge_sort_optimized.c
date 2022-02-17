#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../../helper/array.h"

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
    int L[n1+1], R[n2+1];
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

void insertion_sort(int A[], int p, int r) {
    for (int j = p; j <= r; j++) {
        int key = A[j];
        // Insert A[j] into the sorted sequence A[0..j - 1]
        int i = j - 1;
        while (i >= p && A[i] > key) {
            A[i + 1] = A[i];
            i--;
        }
        A[i + 1] = key;
    }
}

/**
 * Merge sort algorithm closely follows the divide-and-conquer paradigm. Intuitively, it operates as follow:
 *
 * Divide: Divide the n-element sequence to be stored into two subsequences of n/2 elements each.
 * Conquer: Sort the two subsequences recursively using merge sort.
 * Combine: Merge the two sorted subsequences to produce the sorted answer.
 */
void merge_sort(int A[], int p, int r, int k) {
    if (p < r) {
        int q = (p + r) / 2;
        if ((q-p) <= k) {
            insertion_sort(A, p, q);
            insertion_sort(A, q + 1, r);
        } else {
            merge_sort(A, p, q, k);
            merge_sort(A, q + 1, r, k);
        }
        merge(A, p, q, r);
    }
}

int main(int argc, char **argv) {
    int n = atoi(argv[1]);
    int k = atoi(argv[2]);
    int A[n];
    fill_random_array(A, n);

    merge_sort(A, 0, n - 1, k);
}
