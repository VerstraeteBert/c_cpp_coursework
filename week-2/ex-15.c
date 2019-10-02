#include <time.h>
#include <stdio.h>
#include <stdlib.h>

const int ARRAY_SIZE = 20;
const int MIN_NUMBER = 100;
const int MAX_NUMBER = 120;
const int AMOUNT_POSSIBLE_NUMBERS = MAX_NUMBER - MIN_NUMBER + 1;

/**
 * M = size of random num array
 * N = size of bitmap
 * O(M+N) runtime implementation
 * O(M+N) Memory
 */
void fill_and_check_occurrence(int * array, int * occurrence_map, int size, int min, int max) {
    srand(time(NULL));
    int i; int ran_num;
    for (i = 0; i < size; i++) {
        ran_num = min + (rand() % (max + 1 - min));
        array[i] = ran_num;
        occurrence_map[ran_num - min] = 1;
    }
}

int main() {
    int occurrence_map [AMOUNT_POSSIBLE_NUMBERS] = { 0 };
    int random_numbers [ARRAY_SIZE] = { 0 };

    fill_and_check_occurrence(random_numbers, occurrence_map, ARRAY_SIZE, MIN_NUMBER, MAX_NUMBER);

    printf("All random numbers: ");
    int i;
    for (i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", random_numbers[i]);
    }

    printf("\nAll missing numbers: ");
    for (i = 0; i < AMOUNT_POSSIBLE_NUMBERS; i++) {
        if (occurrence_map[i] == 0) {
            printf("%d ", i + MIN_NUMBER);
        }
    }
}
