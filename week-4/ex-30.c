#include <stdio.h>
#include <assert.h>
#include <string.h>

int int_eq(const int * a, const int * b) {
    return *a == *b;
}

int string_eq(const char ** a, const char ** b) {
    return !strcmp(*a, *b);
}

int array_bevat_dubbels_na_elkaar(const void * arr, size_t size, int grootte, int (*eq) (const void *, const void *)) {
    size_t i;
    const char * s = (char *) arr;
    for (i = 0; i < size - 1; i++) {
        if (eq(s + i * grootte, s + (i + 1) * grootte)) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int getallen_ja[] = {1,2,3,4,5,6,7,8,9,10,10,11};
    int getallen_neen[] = {1,2,1,2,1,2,1,2,1,2,3,4,5};
    char* woorden_ja[] = {"leentje","leerde","lotje","lopen","lopen","langs","de",
                          "lindelaan"};
    char* woorden_neen[] = {"wie","goed","doet","goed","ontmoet"};

    assert(array_bevat_dubbels_na_elkaar(getallen_ja, sizeof(getallen_ja) / sizeof(getallen_ja[0]), sizeof(int), (int(*) (const void*, const void*)) &int_eq) == 1);
    assert(array_bevat_dubbels_na_elkaar(getallen_neen, sizeof(getallen_neen) / sizeof(getallen_neen[0]), sizeof(int), (int(*) (const void*, const void*)) &int_eq) == 0);
    assert(array_bevat_dubbels_na_elkaar(woorden_ja, sizeof(woorden_ja) / sizeof(woorden_ja[0]), sizeof(char *), (int(*) (const void*, const void*)) &string_eq) == 1);
    assert(array_bevat_dubbels_na_elkaar(woorden_neen, sizeof(woorden_neen) / sizeof(woorden_neen[0]), sizeof(char *), (int(*) (const void*, const void*)) &string_eq) == 0);

    return 0;
}
