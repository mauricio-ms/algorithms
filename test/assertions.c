#include <stdio.h>
#include "assertions.h"
#include "../helper/array.h"

#define ANSI_COLOR_FAIL "\x1b[31m"
#define ANSI_COLOR_RESET "\x1b[0m"

void start_fail_report() {
    printf(ANSI_COLOR_FAIL);
}

void end_fail_report() {
    printf(ANSI_COLOR_RESET);
}

int assert_array_equals(int expected[], int expected_n, int actual[], int actual_n) {
    int assertion_error = 0;
    if (expected_n != actual_n) {
        assertion_error = 1;
    } else {
        for (int i=0; i<expected_n; i++) {
            if (expected[i] != actual[i]) {
                assertion_error = 1;
                break;
            }
        }
    }

    if (assertion_error) {
        start_fail_report();
        printf("ERROR: The actual array is different from the expected:\n");
        printf("  ACTUAL=");
        print_array(actual, actual_n);
        printf("EXPECTED=");
        print_array(expected, expected_n);
        end_fail_report();
    }
    return assertion_error;
}