#include <stdio.h>
#include <limits.h>

void zoek_extremen(const int arr [], size_t n, int * min, int * max) {
    if (n == 0 || arr == NULL) {
        return;
    }
    *min = arr[0]; *max = arr[0];
    int i;
    for (i = 0; i < n; i++) {
        if (arr[i] < *min) {
            *min = arr[i];
        }
        if (arr[i] > *max) {
            *max = arr[i];
        }
    }
}

void zoek_extremen_rec_helper(const int* arr, size_t size, size_t curr_idx, int * min_ref, int * max_ref) {
    if (curr_idx >= size) return;

    if (*min_ref > arr[curr_idx]) {
        *min_ref = arr[curr_idx];
    }

    if (*max_ref < arr[curr_idx]) {
        *max_ref = arr[curr_idx];
    }

    zoek_extremen_rec_helper(arr, size, curr_idx + 1, min_ref, max_ref);
}

void zoek_extremen_rec(const int * arr, size_t size, int *min_ref, int * max_ref) {
    if (size == 0) return;
    size_t curr_idx = 1;
    *min_ref = arr[0]; *max_ref = arr[0];
    zoek_extremen_rec_helper(arr, size, curr_idx, min_ref, max_ref);
}

int main() {
    int arr[] = {37, 20, 64, 2, 90, 80, 85};
    int max; int min;
    zoek_extremen(&arr, sizeof(arr) / sizeof(arr[0]), &min, &max);
    printf("Min: %d\n", min);
    printf("Max: %d\n", max);
}
