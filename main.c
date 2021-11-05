#include <stdio.h>

void insertion_sort_increasing_order() {
    printf("insertion_sort_increasing_order\n");

    int n = 6;
    int A[6] = {31, 41, 59, 26, 41, 58};

    for (int j = 1; j < n; j++) {
        int key = A[j];
        // Insert A[j] into the sorted sequence A[0..j - 1]
        int i = j - 1;
        while (i >= 0 && A[i] > key) {
            A[i + 1] = A[i];
            i--;
        }
        A[i + 1] = key;
    }

    for (int k = 0; k < n; k++) {
        printf("%d ", A[k]);
    }
    printf("\n");
}

void insertion_sort_decreasing_order() {
    printf("insertion_sort_decreasing_order\n");

    int n = 6;
    int A[6] = {31, 41, 59, 26, 41, 58};

    for (int j = 1; j < n; j++) {
        int key = A[j];
        // Insert A[j] into the sorted sequence A[0..j - 1]
        int i = j - 1;
        while (i >= 0 && A[i] < key) {
            A[i + 1] = A[i];
            i--;
        }
        A[i + 1] = key;
    }

    for (int k = 0; k < n; k++) {
        printf("%d ", A[k]);
    }
    printf("\n");
}

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

    for (int k = 0; k < n + 1; k++) {
        printf("%d ", C[k]);
    }
    printf("\n");
}

void selection_sort() {
    printf("selection_sort\n");

    int n = 6;
    int A[6] = {31, 41, 59, 26, 41, 58};

    for (int i=0; i<n-1; i++) {
        int lower = A[i];
        int lowerIndex = i;
        for (int j=i+1; j<n; j++) {
            if (A[j] < lower) {
                lower = A[j];
                lowerIndex = j;
            }
        }

        if (lowerIndex != i) {
            int current = A[i];
            A[i] = lower;
            A[lowerIndex] = current;
        }
    }

    for (int k = 0; k < n; k++) {
        printf("%d ", A[k]);
    }
    printf("\n");
}

int main() {
    insertion_sort_increasing_order();
    insertion_sort_decreasing_order();
    sum_binary_integers();
    selection_sort();
    return 0;
}
