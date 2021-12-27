/**
 * Function responsible to execute the combine part of the merge sort algorithm.
 * A is an array and p, q, and r are indices into the array such that p <= q < r.
 *
 * This procedure assumes that the subarrays A[p..q] and A[q + 1..r] are in sorted order.
 * It merges them to form a single sorted subarray that replaces the current subarray A[p..r].
 *
 * This procedure takes time O(n), where n = r - p + 1 is the total number of elements being merged.
 */
void merge_without_sentinels(int A[], int p, int q, int r) {
    int B[r - p];
    for (int i = p; i <= q; i++) {
        B[i] = A[i];
    }

    for (int j = q + 1; j <= r; j++) {
        B[r + q + 1 - j] = A[j];
    }

    int i = p;
    int j = r;
    for (int k = p; k < r; k++) {
        if (B[i] <= B[j]) {
            A[k] = B[i];
            i++;
        } else {
            A[k] = B[j];
            j--;
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
void merge_sort_without_sentinels(int A[], int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;
        merge_sort_without_sentinels(A, p, q);
        merge_sort_without_sentinels(A, q + 1, r);
        merge_without_sentinels(A, p, q, r);
    }
}

void merge_sort_without_sentinels_tests() {
    printf("Running merge sort without sentinels tests ...\n");

    int n = 7;
    int A[] = {31, 2, 41, 59, 26, 41, 58};
    int expected[] = {2, 26, 31, 41, 41, 58, 59};
    merge_sort_without_sentinels(A, 0, n);
    assert_array_equals(expected, n, A, n);
}