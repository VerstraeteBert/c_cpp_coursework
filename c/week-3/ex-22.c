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

void zoek_extremen_rec(const int arr [], size_t n, int * min, int * max) {
    if (lengte == 1) {
        *min = rij[0];
        *max = rij[0];
    } else {
        zoek_extremen_rec(arr, n - 1, min, max);
        if (rij[lengte - 1] < *min) {
            *min = rij[lengte - 1];
        }
        if (rij[lengte - 1] > *max) {
            *max = rij[lengte - 1];
        }
    }
}

int main() {
    int arr[] = {37, 20, 64, 2, 90, 80, 85};
    int max; int min;
    zoek_extremen(&arr, sizeof(arr) / sizeof(arr[0]), &min, &max);
    printf("Min: %d\n", min);
    printf("Max: %d\n", max);
}
