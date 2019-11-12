#include <stdio.h>
#include <assert.h>
#include <string.h>

const int array_bevat_dubbels_na_elkaar(const void *, const size_t, const int, const int(*)(const void *, const void *));

int int_eq(const int * a, const int * b) {
    return *a == *b;
}

int str_eq(const char ** a, const char ** b) {
    return strcmp(*a, *b) == 0;
}

int main() {
    int getallen_ja[] = {1,2,3,4,5,6,7,8,9,10,10,11};
    int getallen_neen[] = {1,2,1,2,1,2,1,2,1,2,3,4,5};
    char* woorden_ja[] = {"leentje","leerde","lotje","lopen","lopen","langs","de",
                          "lindelaan"};
    char* woorden_neen[] = {"wie","goed","doet","goed","ontmoet"};

    assert(array_bevat_dubbels_na_elkaar(getallen_ja, sizeof(getallen_ja) / sizeof(getallen_ja[0]), sizeof(int), (const int(*) (const void*, const void*)) int_eq) == 1);
    assert(array_bevat_dubbels_na_elkaar(getallen_neen, sizeof(getallen_neen) / sizeof(getallen_neen[0]), sizeof(int), (const int(*) (const void*, const void*)) int_eq) == 0);
    assert(array_bevat_dubbels_na_elkaar(woorden_ja, sizeof(woorden_ja) / sizeof(woorden_ja[0]), sizeof(char *), (const int(*) (const void*, const void*)) str_eq) == 1);
    assert(array_bevat_dubbels_na_elkaar(woorden_neen, sizeof(woorden_neen) / sizeof(woorden_neen[0]), sizeof(char *), (const int(*) (const void*, const void*)) str_eq) == 0);

    return 0;
}

const int array_bevat_dubbels_na_elkaar(const void * data, const size_t size, const int width, const int(*eq)(const void *, const void *)) {
       char * arr = (char *) data;
       size_t i = 0;
       while (i < size - 1 && !eq(arr + i * width, arr + (i + 1) * width)) {
           i++;
       }
       return i != size - 1;
}

