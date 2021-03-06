#include <stdio.h>

void process_input(int alpha_occurrences []) {
    char arr [4096];
    fgets(arr, 4096, stdin);
    int size = sizeof(arr) / sizeof(arr[0]);
    int i;
    for (i = 0; i < size && arr[i] != '\0'; i++) {
        int char_ascii = arr[i];
        if (char_ascii >= 97 && char_ascii <= 122) {
            alpha_occurrences[char_ascii % 97]++;
        }
        if (char_ascii >= 65 && char_ascii <= 90) {
            alpha_occurrences[char_ascii % 65]++;
        }
    }
}

void print_first_histo (const int alpha_occurrences [], size_t size) {
    size_t i;
    for (i = 0; i < size; i++) {
        printf("%c:\t", (char) (i + 97));
        int num_occurrences = (int) alpha_occurrences[i];
        while (num_occurrences != 0) {
            printf("*");
            num_occurrences--;
        }
        printf("\n");
    }
}

void print_second_histo(int alpha_occurrences [], size_t size) {
    size_t i;
    int largest_occurrence = 0;
    for(i = 0; i < size; i++) {
        if (alpha_occurrences[i] > largest_occurrence) {
            largest_occurrence = alpha_occurrences[i];
        }
    }

    while (largest_occurrence != 0) {
        for (i = 0; i < size; i++) {
            if (alpha_occurrences[i] == largest_occurrence) {
                printf("%c", (char) (i + 97));
                alpha_occurrences[i]--;
            } else {
                printf(" ");
            }
        }
        largest_occurrence--;
        printf("\n");
    }

}

int main() {
    int alpha_occurrences [26] = { 0 };
    size_t size = sizeof(alpha_occurrences) / sizeof(alpha_occurrences[0]);
    process_input(alpha_occurrences);
    print_first_histo(alpha_occurrences, size);
    printf("\n");
    print_second_histo(alpha_occurrences, size);
    return 0;
}
