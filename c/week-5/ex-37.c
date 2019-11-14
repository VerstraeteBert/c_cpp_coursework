#include <stdlib.h>
#include <stdio.h>

typedef struct Numerator {
    int value;
    int num_divisors;
    int * divisors;
} Numerator;

void write_ints(int * arr, size_t size) {
    size_t i;
    for (i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i + 1 < size) {
            printf("-");
        }
    }
    printf("\n");
}

void write_numerator(const Numerator * pNumerator) {
    if (pNumerator == NULL) {
        return;
    }
    printf("%d\t", pNumerator->value);
    write_ints(pNumerator->divisors, pNumerator->num_divisors);
}

int num_divisors_of(int x) {
    int i;
    int upper_bound = x % 2 == 0 ? x / 2 : (x / 2) + 1;
    int num_demons = 0;
    for (i = 1; i <= upper_bound; i++) {
        if (x % i == 0) num_demons++;
    }
    return num_demons;
}

int * divisors_of(int x, int num_divs) {
    int * divs = malloc(num_divs * sizeof(int));
    int curr_div = 0; int i;
    int upper_bound = x % 2 == 0 ? x / 2 : (x / 2) + 1;
    for (i = 1; i <= upper_bound; i++) {
        if (x % i == 0) {
            divs[curr_div] = i;
            curr_div++;
        }
    }
    return divs;
}

Numerator * read_numerator() {
    Numerator * pNumerator = malloc(sizeof(Numerator));
    printf("ptr = %p\n", (void *) pNumerator);
    printf("Geef een geheel getal in: \n");
    scanf("%d", &pNumerator->value);
    fflush(stdin);
    pNumerator->num_divisors=num_divisors_of(pNumerator->value);
    pNumerator->divisors=divisors_of(pNumerator->value, pNumerator->num_divisors);
    return pNumerator;
}

Numerator ** read_numerators(Numerator ** pNumerators, int size) {
    int i = 0;
    for(i = 0; i < size; i++) {
        pNumerators[i] = read_numerator();
    }
    return pNumerators;
}

void write_numerators(Numerator ** pNumerators, int size) {
    int i;
    for (i = 0; i < size; i++) {
        write_numerator(pNumerators[i]);
    }
}

void free_numerator(Numerator * pNumerator) {
    printf("Now that she had nothing to lose, she was free. %d\n", pNumerator->value);
    printf("ptr = %p\n", (void *) pNumerator);
    free(pNumerator->divisors);
    free(pNumerator);
}

void free_numerators(Numerator ** pNumerators, int size) {
    int i;
    for (i = 0; i < size; i++) {
        free_numerator(pNumerators[i]);
    }
    free(pNumerators);
}

Numerator * search(int value, Numerator ** pNumerators, int size) {
    int i;
    for (i = 0; i < size; i++) {
        if (pNumerators[i]->value == value) {
            return pNumerators[i];
        }
    }
    return NULL;
}

int main () {
    Numerator * pNumerator = read_numerator();
    write_numerator(pNumerator);
    printf("Alé tis goed, hoeveel moeje en?\n");
    int num_nums;
    scanf("%d", &num_nums);
    fflush(stdin);
    Numerator ** pNumerators = malloc(num_nums * sizeof(Numerator *));
    read_numerators(pNumerators, num_nums);
    write_numerators(pNumerators, num_nums);
    Numerator * pSearchNum = search(5, pNumerators, num_nums);
    if (pSearchNum) {
        printf("We got em bwois: %d\n", pSearchNum->value);
    }
    free_numerator(pNumerator);
    free_numerators(pNumerators, num_nums);
    return 0;
}