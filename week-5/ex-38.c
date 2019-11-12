#include <stdio.h>

const int NUM_WORDS = 3;
const int AVG_LEN_WORD = 2;
const int TOTAL_LEN_ARR = NUM_WORDS * (AVG_LEN_WORD + 1);

void read_naive(char ** pt) {
    if (pt == NULL) {
        printf("Null pointer given");
        return;
    }
    int i; int num_scanned;
    for (i = 0; i < NUM_WORDS; i++) {
        printf("Start addr: %p\n", pt[i]);
        scanf("%s%n", pt[i], &num_scanned);
        fflush(stdin);
        pt[i + 1] = &(pt[i][0 + num_scanned + 1]);
    }
    pt[NUM_WORDS] = NULL;
}

void write(char ** pt) {
    if (pt == NULL) {
        printf("Null pointer given");
        return;
    }
    int i = 0;
    while (pt[i] != NULL) {
        printf("%s ", pt[i]);
        i++;
    }
}

int main() {
    char* pt[NUM_WORDS + 1];
    char t[TOTAL_LEN_ARR];
    pt[0] = t;
    read_naive(pt);
    write(pt);
    return 0;
}
