#include <stdio.h>

const int NUM_WORDS = 10;
const int AVG_LEN_WORD = 7;
const int TOTAL_LEN_ARR = NUM_WORDS * (AVG_LEN_WORD + 1);

void read_naive(char ** pt) {
    if (pt == NULL) {
        printf("Null pointer given");
        return;
    }

    char scanned_word [AVG_LEN_WORD + 1];
    int i; int num_scanned; int j;
    for (i = 0; i < NUM_WORDS; i++) {
        scanf("%s%n", scanned_word, &num_scanned);
        fflush(stdin);
        for (j = 0; j < num_scanned + 1; j++) {
            printf("Copying %c into %p\n",scanned_word[j], &(pt[i][j]));
            pt[i][j] = scanned_word[j];
        }
        pt[i + 1] = &(pt[i][j]);
    }
    pt[NUM_WORDS] = NULL;
}

void write(char ** pt) {
    if (pt == NULL) {
        printf("Null pointer given");
        return;
    }

    int i = 0; int j;
    while (pt[i] != NULL) {
        j = 0;
        while (pt[i][j] != '\0') {
            printf("%c", pt[i][j]);
            j++;
        }
        printf(" ");
        i++;
    }
}

int main(){
    char* pt[NUM_WORDS + 1];
    char t[TOTAL_LEN_ARR];
    pt[0] = t;
    read_naive(pt);
    write(pt);
    return 0;
}
