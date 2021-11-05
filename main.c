#include <stdio.h>

void print_array(int A[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void insertion_sort_increasing_order(int A[], int n) {
    printf("insertion_sort_increasing_order\n");

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

//    int n = sizeof(A)/sizeof(A[0]);
    print_array(A, n);
}

void insertion_sort_decreasing_order(int A[], int n) {
    printf("insertion_sort_decreasing_order\n");

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

    print_array(A, n);
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

    print_array(C, n+1);
}

void selection_sort(int A[], int n) {
    printf("selection_sort\n");

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

    print_array(A, n);
}

int main() {
    int n = 6;
    int A[] = {31, 41, 59, 26, 41, 58};
    insertion_sort_increasing_order(A, n);
    insertion_sort_decreasing_order(A, n);
    sum_binary_integers();
    selection_sort(A, n);
    return 0;
}
