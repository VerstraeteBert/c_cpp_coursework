#include <stdio.h>

int * idx_of(int haystack [], size_t size, int needle) {
    size_t i;
    while (i < size && haystack[i] != needle) {
        i++;
    }
    return (i == size) ? NULL : &haystack[i];
}

void print_arr(const int * arr, size_t size) {
    size_t i;
    printf("Array: ");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void move_ptr_to_num(int ** ptr, size_t len, int needle) {
    size_t i = 0;
    while (i < len && **ptr != needle) {
        (*ptr)++;
    }
    if (i == len) *ptr = NULL;
}

int main() {
    int arr[] = {1, 2, 3, 7, 3, 3, 5};
    size_t size = sizeof(arr) / sizeof(arr[0]);

    int * idx = idx_of(arr, size, 3);
    if (!idx) {
        printf("Attempting to dereference a null pointer");
        return -1;
    }
    printf("idx at: %ld\n",  idx - arr);
    *idx *= 2;

// test 23.1
//    idx = idx_of(arr, size, 5);
//    if (!idx) return -1;
//    *idx *= 2;
//    printf("idx at: %ld\n",  idx - arr);
//
//    idx = idx_of(arr, size, 5);
//    if (!idx) return -1;
//    *idx *= 2;
//    printf("idx at: %ld\n",  idx - arr);
//
//    idx = idx_of(arr, size, 6);
//    if (!idx) return -1;
//    *idx *= 2;
//    printf("idx at: %ld",  idx - arr);
    print_arr(arr, size);

    int * array_ptr = arr;
    move_ptr_to_num(&array_ptr, size, 7);
    if (!array_ptr) {
        printf("Needle not found, null pointer");
        return -1;
    }
    print_arr(array_ptr, (arr + size) - array_ptr);
}
