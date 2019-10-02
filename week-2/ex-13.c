#include <stdio.h>

int index_of(int haystack[], double needle) {
    int i;
    for (i = 0; haystack[i] != '\0'; i++) {
        if (haystack[i] == needle) {
            return i;
        }
    }
    return -1;
}

int main() {
    int haystack[] = {1, 2, 3, 4, 8, 12, 3, 17, 5, 19};
    double needle;
    while (scanf("%lf", &needle)==0) {
        while (getchar () != '\n');
        printf("Please enter a real number !\n");
    }
    printf("%d", index_of(haystack, needle));
}
