#include <stdio.h>

int index_of(const int haystack[], double needle, size_t size) {
    size_t i;
    for (i = 0; i < size; i++) {
        if (haystack[i] == needle) {
            return i;
        }
    }
    return -1;
}

int main() {
    int haystack[] = {1, 2, 3, 4, 8, 12, 3, 17, 5, 19};
    int size = sizeof(haystack) / sizeof(haystack[0]);
    double needle;
    while (scanf("%lf", &needle)==0) {
        fflush(stdin);
        printf("Please enter a real number !\n");
    }
    printf("%d", index_of(haystack, needle, size));
}
