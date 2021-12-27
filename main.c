#include "sort/insertion_sort.c"
#include "bits-manipulation/sum_binary_integers.c"
#include "sort/selection_sort.c"
#include "sort/merge_sort.c"
#include "sort/merge_sort_without_sentinels.c"
#include "sort/insertion_sort_recursive.c"

int main() {
    insertion_sort_tests();
    sum_binary_integers_tests();
    selection_sort_tests();
    merge_sort_tests();
//    merge_sort_without_sentinels_tests(); TODO FIX SEGMENTATION FAULT
    insertion_sort_recursive_tests();
    return 0;
}
